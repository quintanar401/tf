## Tensorflow Q wrapper

You need to have `tensorflow.so` in your library path.

A thin wrapper for TF. Expects that `.tf.ops.inp`, `.tf.ops.att` and `.tf.ops.ops` tables are initialized (load `c/ops.q`). Call `.tf.init[path_to_tf.so]` to initialize:
```
\l c/ops.q
\l tf.q
.tf.init `:c / assuming tf.so is in c/
.tf.init `   / if it is in the lib path
```

Wrappers are in `.tf.i.lib`.

TF object pointers are returned as longs and you must ensure that you pass in the correct pointer values and delete objects after they are not needed.

For examples check test directory.

### Misc functions

Status related:
```
status:.tf.newStatus[];            / new status
code:.tf.getStatus[s];             / status code
msg:.tf.getStatusMsg[s];           / status msg
.tf.setStatus[s;`code;"msg"];      / set status
.tf.delStatus[s];                  / delete status
.tf.checkAndDelStatus["prefix";s]; / check status, delete it and throw an exception if it is not TF_OK
```
Status codes can be found in `.tf.i.st`.

Version:
```
v:.tf.version[]; / returns a string
```

TF data type size:
```
sz:.tf.getDataTypeSize[`TF_TYPE]; / long
```
Data types are defined as keys of `.tf.i.dt`.

Load a graph from a save:
```
/ @dir symbol export directory
/ @tags (symbol list) tags
/ @opts long session options
/ @runOpts long a buffer with run options, can be 0
/ @gmeta long a buffer with meta graph, can be 0
/ @returns (long list) A pair (session;graph)
p:.tf.loadSavedModel[`:model.pb;enlist `tag;0;0;0];
```

### Predefined operations.

All ops will accept `deps` (operation dependencies) and `opName` (operation name) in scope argument. All operations return a table with oper and index columns (usually it has only 1 row).
This table or any of its rows can be passed to other operations. It is ok to have additional columns, they are ignored (session.run expects additional tensor col for its input).
Table not dict must be used when multiple input/ouput is required.
```
c:.tf.const[scope;10]; / for atoms and vectors with INT/FLOAT/DOUBLE/STRING types (including strings)
c:.tf.const[scope;til 100;10 10]; / with explicit shape
c:.tf.const[scope;til 100;`TF_UINT64]; / explicit type
c:.tf.const[scope;til 100;10 10;`TF_UINT64]; / explicit type and shape (order doesn't matter)

v:.tf.variable[scope;`TF_INT64;10 10]; / define a variable (RESOURCE, not by ref like in python)
p:.tf.placeholder[scope;`TF_INT64]; / placeholder(input)
p:.tf.placeholder[scope,enlist[`shape]!enlist 10 10;`TF_INT64]; / placeholder(input)
t:.tf.tensorDataset[scope;enlist val;enlist 10 10]; /

r:.tf.assign[scope;var;val]; / assign
r:.tf.assignAdd[scope;var;val]; / +: assign
r:.tf.assignSub[scope;var;val]; / -: assign
r:.tf.readVar[scope;var]; / create a read node, pass r into session.run output list

r:.tf.add[scope;v1;v2]; / add
r:.tf.sub[scope;v1;v2]; / sub
r:.tf.mul[scope;v1;v2]; / mul
r:.tf.div[scope;v1;v2]; / div
r:.tf.matMul[scope;v1;v2]; / matrix mult
r:.tf.matMul[scope,`transpose_a`transpose_b!0 1b;v1;v2]; / optional attributes

i:.tf.iter[scope;name;container;outputTypes;outputShapes] aka .tf.iter[scope;`;`;`TF_FLOAT;enlist 10]
i:.tf.makeIter[scope;data;iter]
```

### Tensors

There are two ways to create a tensor - either to copy data from Q (`alloc`) or use Q vectors (`new`). For Q vectors the ref count will be decremented by TF. This may not work well with several threads, in this case use `alloc`. Also `alloc` will always be used for scalars and TF_STRING type.

To create a new tensor:
```
/ @x symbol TF data type
/ @y (long|long list) dimensions
/ @z (atom|list) Q data
/ @returns long tensor
t:.tf.tensor.alloc[`TF_FLOAT;10 10;100#1.1e]

/ @x symbol TF data type
/ @y (long|long list) dimensions
/ @z (atom|list) Q data
/ @returns long tensor
t:.tf.tensor.new[`TF_FLOAT;10 10;100#1.1e]
```

To delete a tensor:
```
.tf.tensor.del tensor
```

Tensor properties:
```
t:.tf.tensor.type tensor;    / symbol, tensor type like `TF_FLOAT
sh:.tf.tensor.shape tensor;  / tensor dimensions, list: () - undefined, `long$() - scalar, long list otherwise
sz:.tf.tensor.size tensor;   / long, tensor size
val:.tf.tensor.value tensor; / tensor data, copy is created. If the tensor was created via new then its Q vector can be used instead
```

### Graphs

```
g:.tf.graph.new[]; / long, new graph
.tf.graph.del g;   / delete a graph

/ @x long graph
/ @y (byte list|string) definition
/ @z symbol prefix
.tf.graph.import[graph;0x00...;`myGraph]; / imports a graph from a buffer

buf:.tf.graph.serialize graph; / byte list, serializes a graph into a buffer

/ Get output ops shape in a graph.
/ @x long graph
/ @y dict oper + index
/ @returns (long list) () for unknown, `long$() for scalar, a list otherwise
l:.tf.graph.opGetShape[graph;`oper`index!(op;0i)];

/ Set output ops shape in a graph.
/ @x long graph
/ @y dict oper + index
/ @z (long list) shape
.tf.graph.opSetShape[graph;`oper`index!(op;0i);10 10];
```

### Operations

Operations are defined in `.tf.ops.ops`. Help is not provided, use TF website (https://github.com/tensorflow/tensorflow/blob/r1.6/tensorflow/core/api_def/base_api/).

Add an operation to a graph:
```
/ @scope dict graph, namespace, dependencies
/ @t string operation type as in ops.q (`FloorMod and etc).
/ @i (dict|table|list) Inputs. For the single input should be a table/dict. Otherwise 0 type list.
/ @a dict Optional attributes. Attribute values are string/str list/(), long/long list, float/double atom/list, bool/bool list, datatype(as a symbol)/symbol list, (`tensor;long/long list)
/ @returns table Operation outputs.
out:.tf.addOp[sc:.tf.newScope .tf.graph.new[];`ShapeN;([] oper:(op1;op2); index: 0 1i);()]
out:.tf.addOp[scope;`Placeholder;();`dtype`shape!(`TF_FLOAT;10)]
```
TF unrelated attributes:
* deps - control dependecies, a list of longs (operations).
* opName - symbol, optional operation name.

You can pass `deps` and `opName` either in attributes or scope args.

Query operations:
```
l:.tf.ops.getOperations scopeOrGraph;        / long list, all operations
op:.tf.ops.getOpByName[scopeOrGraph;`name];  / long, get the operation by name
```

Operation properties:
```
s:.tf.ops.name op;                           / symbol, op's name
s:.tf.ops.type op;                           / symbol, op's type
s:.tf.ops.device op;                         / symbol, op's device
opTbl:.tf.ops.outputs op;                    / table(oper,index,dtype), op's outputs
opTbl:.tf.ops.inputs op;                     / table(oper,index,dtype), op's inputs
opDct:.tf.ops.producer[`oper`index!(op;0i)];  / dict(oper,index), op's source input
opDct:.tf.ops.consumers[`oper`index1!(op;0i)]; / dict(oper,index), op's targets
l:.tf.ops.controlInputs op;                  / long list, input control ops
l:.tf.ops.controlOutputs op;                 / long list, output control ops
j:.tf.ops.inputLength[op;`name];             / long, list length of an input operation
j:.tf.ops.outputLength[op;`name];            / long, list length of an output operation
```

### Scope

Scope is used to put operations into namespaces.
```
.tf.newScope[()]
.tf.newScope[graph]
.tf.newScope[`graph`ns`deps!(graph;`ns;1 2 3)]
```
Graph is created if necessary.

```
.tf.subScope[scope;`name] / enter a subscope
.tf.delScope scope;       / basically it is just .tf.graph.del
```

### Session

```
/ New session.
/ @x (dict|long) Scope or Graph
/ @y long Options, can be 0.
/ @returns long Session
s:.tf.newSession[graph;0]

.tf.delSession s;             / delete a session

/ Runs a session with the given inputs.
/ @sess long session
/ @i (table|dict) input operations: oper,index,tensor
/ @o (table|dict) output operations: oper,index
/ @t (long list) target operations
/ @runOpts long run options, can be 0
/ @gmeta long graph meta, can be 0, it is an output arg, should be a Buffer.
/ @returns (long list) a list of requested tensors
t:.tf.session.run[sess;`oper`index`tensor!(op;0i;.tf.tensor.alloc[`TF_FLOAT;10;10#1.1e]);`oper`index!(op2;0i);`long$();0;0]

/ Partially runs a session with the given inputs.
/ @sess long session
/ @h long handle
/ @i table input operations: oper,index,tensor
/ @o table output operations: oper,index
/ @t (long list) target operations
/ @returns (long list) a list of requested tensors
t:.tf.session.prun[sess;h;i;o;t]

/ Initializes a partial run (when only a part of input variables is defined).
/ @sess long session
/ @i table input operations: oper,index
/ @o table output operations: oper,index
/ @t (long list) target operations
/ @returns long handle
h:.tf.session.newPRun[sess;i;o;t]

/ New session options.
/ @x symbol target, can be `
/ @y (string|byte list) config, can be empty
/ @returns long session options
ops:.tf.session.newOps[`;""];
.tf.session.delOpts ops; / delete session options

.tf.session.listDevices sess; / list devices
```

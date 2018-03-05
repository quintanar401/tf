.tf.i.n:0;
.tf.i.N:{: .tf.i.n+:1};
.tf.i.dt:(``TF_FLOAT`TF_DOUBLE`TF_INT32`TF_UINT8`TF_INT16`TF_INT8`TF_STRING`TF_COMPLEX64`TF_INT64`TF_BOOL`TF_QINT8`TF_QUINT8`TF_QINT32`TF_BFLOAT16,
    `TF_QINT16`TF_QUINT16`TF_UINT16`TF_COMPLEX128`TF_HALF`TF_RESOURCE`TF_VARIANT`TF_UINT32`TF_UINT64)!0N 4 8 4 1 2 1 0N 4 8 1 1 1 4 0N 2 2 2 8 0N 0N 0N 4 8;
.tf.i.st:`TF_OK`TF_CANCELLED`TF_UNKNOWN`TF_INVALID_ARGUMENT`TF_DEADLINE_EXCEEDED`TF_NOT_FOUND`TF_ALREADY_EXISTS`TF_PERMISSION_DENIED`TF_RESOURCE_EXHAUSTED`TF_FAILED_PRECONDITION,
    `TF_ABORTED`TF_OUT_OF_RANGE`TF_UNIMPLEMENTED`TF_INTERNAL`TF_UNAVAILABLE`TF_DATA_LOSS`TF_UNAUTHENTICATED;
.tf.i.qdt:0 1 2 3 4 5 6 7 8 9h!0N 1 0N 0N 1 2 4 8 4 8;
.tf.i.q4t:key[.tf.i.dt]!" efixhx ejxxxi hhhf   ij";
.tf.i.defTy:4 5 6 7 8 9 10h!`TF_INT8`TF_INT16`TF_INT32`TF_INT64`TF_FLOAT`TF_DOUBLE`TF_STRING;
.tf.i.t2q:`TF_COMPLEX64`TF_COMPLEX128!2 2; / q values in one tf value
.tf.i.chkTy:{if[not -11=type y;'x,": type"]; if[not(not y=`)&y in key .tf.i.dt;'x,": wrong datatype"]; y};
.tf.i.chkOut:{y:$[99=type y;enlist y;98=type y;y;'x,": type"]; if[not all `oper`index in cols y;'x,": wrong operation format"]; y};

//
// Operations
//
/ Add an operation.
/ @scope dict graph, namespace, dependencies, opName
/ @t symbol operation type as in ops.q (`FloorMod and etc).
/ @i (dict|table|list) Inputs. For the single input should be a table/dict. Otherwise 0 type list.
/ @a dict Optional attributes. Attribute values are string/str list/(), long/long list, float/double atom/list, bool/bool list, datatype(as a symbol)/symbol list, tensor or shape - long/long list
/ @returns table Operation outputs (even if there are no outputs - dummy tbl is returned).
.tf.addOp:{[scope;t;i;a]
  if[null op:exec first i from .tf.ops.ops where name=t;'".tf.addOp: undefined op ",string n];
  op:.tf.ops.ops op; att:.tf.ops.att (),op`att; inp:.tf.ops.inp (),op`input_arg; out:.tf.ops.inp (),op`output_arg;
  a:(`$()!()),a; opn:$[`opName in key a; a`opName;`opName in key scope;scope`opName;`$string[t],string .tf.i.N[]]; if[count scope`deps; a:a,enlist[`deps]!enlist scope[`deps],$[`deps in key a;a`deps;()]];
  opn:$[null scope`ns;opn;`$string[scope`ns],"/",string opn];
  if[count[inp]<>count i:$[99=type i;enlist enlist i;98=type i;enlist i;i];'".tf.addOp: wrong number of inputs"];
  if[0=op:.tf.i.lib[`.tf.TF_NewOperation][scope`graph;t;opn];'".tf.addOp: newOperation failed"];
  .tf.i.addInput[op;att]'[i;inp]; / inputs
  if[`deps in key a; if[not 7=abs type a`deps;'".tf.addOp: wrong type of deps"]; {.tf.i.lib[`.tf.TF_AddControlInput][x;y]}[op] each a`deps]; / controls
  ioatt:raze{x`type_attr`type_list_attr`number_attr inter key x} each inp,out;
  {[op;a;ioatt;at] if[not (n:at`name)in key a; if[(not n in ioatt)&(::)~at`default_value;'".tf.addOp: no attribute ",string n]; :()]; .tf.i.setAttr[op;n;a n;at`atype]}[op;a;ioatt]each att;
  op:.tf.i.lib[`.tf.TF_FinishOperation][op;s:.tf.newStatus[]];
  .tf.checkAndDelStatus["addOp::finish";s];
  : $[count r:.tf.ops.outputs op;r;enlist`oper`index`dtype!(op;0i;`)];
 };
.tf.i.addInput:{[op;att;i;inp]
  i:.tf.i.chkType[att;i;inp];
  $[98=type i;.tf.i.lib[`.tf.TF_AddInputList][op;i];.tf.i.lib[`.tf.TF_AddInput][op;i]];
 };
.tf.i.setAttr:{[op;n;v;ty]
  if[9=a:abs type v;v:"e"$v];
  if[10=t:type v; :.tf.i.lib[`.tf.TF_SetAttrString][op;n;v]];
  if[(not ty in `shape`tensor)&7=a; :.tf.i.lib[`.tf.TF_SetAttrInt`.tf.TF_SetAttrIntList t>0][op;n;v]];
  if[8=a; :.tf.i.lib[`.tf.TF_SetAttrFloat`.tf.TF_SetAttrFloatList t>0][op;n;v]];
  if[a in 1 4h; :.tf.i.lib[`.tf.TF_SetAttrBool`.tf.TF_SetAttrBoolList t>0][op;n;"c"$v]];
  if[11=a; .tf.i.chkTy[".tf.addOp"] each v; :.tf.i.lib[`.tf.TF_SetAttrType`.tf.TF_SetAttrTypeList t>0][op;n;"i"$key[.tf.i.dt]?v]];
  if[ty in `shape`tensor,`$("list(shape)";"list(tensor)");
    $[f:ty in`tensor,`$"list(tensor)";if[not 7=abs t:type v;'".tf.addOp: wrong tensor type"];if[not (t:7=type v)|all 7=type each v;'".tf.addOp: wrong shape type"]];
    if[not f;:.tf.i.lib[`.tf.TF_SetAttrShape`.tf.TF_SetAttrShapeList t=0][op;n;v]];
    .tf.i.lib[`.tf.TF_SetAttrTensor`.tf.TF_SetAttrTensorList t>0][op;n;v;s:.tf.newStatus[]];
    :.tf.checkAndDelStatus["addOp::setAttr";s];
  ];
  if[(()~v)|all 10=type each v; :.tf.i.lib[`.tf.TF_SetAttrStringList][op;n;v]];
  '".tf.addOp: unknown attribute value";
 };
/ normalizes inputs
.tf.i.chkType:{[att;i;inp]
  if[not 98=type i;'".tf.addOp: wrong input type"];
  if[not all `index`oper in cols i;'".tf.addOp: wrong input table columns"];
  if[null inp`number_attr; if[1<count i;'".tf.addOp: wrong input type, one input is expected"]; i:i 0];
  : i;
 };
/ Get all graph operations.
/ @x (dict|long) Scope or graph.
/ @returns (long list) operations.
.tf.ops.getOperations:{g:$[99=type x;x`graph;x]; if[not -7=type g;'".tf.ops.getOperations: type"]; ops:0#0; pos:(),0; while[1;if[0=o:.tf.i.lib[`.tf.TF_GraphNextOperation][g;pos]; :ops]; ops,:o]};
/ Get an operation by name.
/ @x (dict|long) Scope or graph.
/ @y symbol name.
/ @returns long operation.
.tf.ops.getOpByName:{g:$[99=type x;x`graph;x]; if[not (-11=type y)&-7=type g;'".tf.ops.getOpByName: type"]; .tf.i.lib[`.tf.TF_GraphOperationByName][g;y]};
/ Operation name.
/ @x long operation
/ @returns symbol name
.tf.ops.name:{if[not -7=type x;'".tf.ops.name: type"]; `$.tf.i.lib[`.tf.TF_OperationName]x};
/ Operation type.
/ @x long operation
/ @returns symbol type
.tf.ops.type:{if[not -7=type x;'".tf.ops.type: type"]; `$.tf.i.lib[`.tf.TF_OperationOpType]x};
/ Operation device.
/ @x long operation
/ @returns symbol device
.tf.ops.device:{if[not -7=type x;'".tf.ops.device: type"]; `$.tf.i.lib[`.tf.TF_OperationDevice]x};
/ Operation outputs.
/ @x long operation
/ @returns table operation, index and its data type
.tf.ops.outputs:{if[not -7=type x;'".tf.ops.outputs: type"]; if[1>i:.tf.i.lib[`.tf.TF_OperationNumOutputs]x; :()]; {`oper`index`dtype!(x;y;key[.tf.i.dt].tf.i.lib[`.tf.TF_OperationOutputType]`oper`index!(x;y))}[x]each "i"$til i};
/ Operation outputs.
/ @x long operation
/ @returns table operation, index and its data type
.tf.ops.inputs:{if[not -7=type x;'".tf.ops.inputs: type"]; if[1>i:.tf.i.lib[`.tf.TF_OperationNumInputs]x; :()]; {`oper`index`dtype!(x;y;key[.tf.i.dt].tf.i.lib[`.tf.TF_OperationInputType]`oper`index!(x;y))}[x]each "i"$til i};
/ Source of an input.
/ @x dict operation and input index
/ @returns dict operation and output index
.tf.ops.producer:{if[not 99=type x;'".tf.ops.producer: type"]; .tf.i.lib[`.tf.TF_OperationInput]x};
/ Targets of an output.
/ @x dict operation and output index
/ @returns table operations and input indecies
.tf.ops.consumers:{if[not 99=type x;'".tf.ops.consumers: type"]; .tf.i.lib[`.tf.TF_OperationOutputConsumers]x};
/ Control inputs.
/ @x long operation
/ @returns (long list) control operations
.tf.ops.controlInputs:{if[not -7=type x;'".tf.ops.controlInputs: type"]; if[1>i:.tf.i.lib[`.tf.TF_OperationNumControlInputs]x;:`long$()]; d:i#0; .tf.i.lib[`.tf.TF_OperationGetControlInputs][x;d]; d};
/ Control outputs.
/ @x long operation
/ @returns (long list) control operations
.tf.ops.controlOutputs:{if[not -7=type x;'".tf.ops.controlOutputs: type"]; if[1>i:.tf.i.lib[`.tf.TF_OperationNumControlOutputs]x;:`long$()]; d:i#0; .tf.i.lib[`.tf.TF_OperationGetControlOutputs][x;d]; d};
/ List length of an input operation.
/ @x long operation
/ @y symbol input name
/ @returns long length
.tf.ops.inputLength:{if[not (-11=type y)&-7=type x;'".tf.ops.inputLength: type"]; l:.tf.i.lib[`.tf.TF_OperationInputListLength][x;y;s:.tf.newStatus[]]; .tf.checkAndDelStatus[".tf.ops.inputLength";s]; l};
/ List length of an output operation.
/ @x long operation
/ @y symbol output name
/ @returns long length
.tf.ops.outputLength:{if[not (-11=type y)&-7=type x;'".tf.ops.outputLength: type"]; l:.tf.i.lib[`.tf.TF_OperationOutputListLength][x;y;s:.tf.newStatus[]]; .tf.checkAndDelStatus[".tf.ops.outputLength";s]; l};
/ Show operation's attributes
/ @x symbol operation name
.tf.ops.attr:{t:select from .tf.ops.ops where name=x; .tf.ops.att (),t[0]`att};
/ Show operation's inputs and outputs
/ @x symbol operation name
.tf.ops.args:{t:select from .tf.ops.ops where name=x; (update ty:`input from .tf.ops.inp (),t[0]`input_arg),update ty:`output from .tf.ops.inp (),t[0]`output_arg};

//
// Graphs
//
/ New graph.
/ @returns long graph
.tf.graph.new:{if[0=g:.tf.i.lib[`.tf.TF_NewGraph][]; '".tf.graph.new: can't create a graph"]; g};
/ Delete a graph.
/ @x long graph
.tf.graph.del:{if[not -7=type x;'".tf.graph.del: type"]; .tf.i.lib[`.tf.TF_DeleteGraph]x};
/ Import a graph.
/ @x long graph
/ @y (byte list|string) definition
/ @z symbol prefix
.tf.graph.import:{
  if[not (-7=type x)&(type[y]in 10 4h)&-11=type z;'".tf.graph.import: type"];
  if[0=opts:.tf.i.lib[`.tf.TF_NewImportGraphDefOptions][];'".tf.graph.import: ops alloc failed"];
  .tf.i.lib[`.tf.TF_ImportGraphDefOptionsSetPrefix][opts;z];
  if[0=buf:.tf.i.lib[`.tf.TF_NewBufferFromString][y];.tf.i.lib[`.tf.TF_DeleteImportGraphDefOptions][];'".tf.graph.import: buffer alloc failed"];
  .tf.i.lib[`.tf.TF_GraphImportGraphDef][x;buf;opts;s:.tf.newStatus[]];
  .tf.i.lib[`.tf.TF_DeleteImportGraphDefOptions][opts];
  .tf.i.lib[`.tf.TF_DeleteBuffer][buf];
  .tf.checkAndDelStatus[".tf.graph.import";s];
 };
/ Save a graph.
/ @x long graph
/ @returns (byte list) serialized graph.
.tf.graph.serialize:{
  if[not -7=type x;'".tf.graph.serialize: type"];
  if[0=buf:.tf.i.lib[`.tf.TF_NewBuffer][];'".tf.graph.serialize: buffer alloc failed"];
  .tf.i.lib[`.tf.TF_GraphToGraphDef][x;buf;s:.tf.newStatus[]];
  res:$[`TF_OK=.tf.getStatus s;.tf.i.lib[`.tf.getBuffer] buf;()];
  .tf.i.lib[`.tf.TF_DeleteBuffer][buf];
  .tf.checkAndDelStatus[".tf.graph.serialize";s];
  : res;
 };
 / Get output ops shape in a graph.
 / @x long graph
 / @y dict oper + index
 / @returns (long list) () for unknown, `long$() for scalar, a list otherwise
 .tf.graph.opGetShape:{
   if[not (99=type y)&-7=type x;'".tf.graph.opGetShape: type"];
   n:.tf.i.lib[`.tf.TF_GraphGetTensorNumDims][x;y;s:.tf.newStatus[]]; .tf.checkAndDelStatus[".tf.graph.opGetShape";s];
   $[n<0;:();n=0;:`long$();()]; dims:n#0;
   .tf.i.lib[`.tf.TF_GraphGetTensorShape][x;y;dims;s:.tf.newStatus[]]; .tf.checkAndDelStatus[".tf.graph.opGetShape";s];
   : dims;
 };
 / Set output ops shape in a graph.
 / @x long graph
 / @y dict oper + index
 / @z (long list) shape
 .tf.graph.opSetShape:{if[not (7=type z)&(99=type y)&-7=type x;'".tf.graph.opSetShape: type"]; .tf.i.lib[`.tf.TF_GraphSetTensorShape][x;y;z;s:.tf.newStatus[]]; .tf.checkAndDelStatus[".tf.graph.opSetShape";s];};

/ Create a new scope
/ @op (dict|long) Options - ns, graph, deps.
.tf.newScope:{[op] if[(op~(::))|op~();op:(`$())!()]; if[-7=type op;op:enlist[`graph]!enlist op]; op:(`ns`deps!(`;0#0)),op; if[not `graph in key op; g:.tf.graph.new[]; op[`graph]:g];  op};
.tf.subScope:{[scope;name] if[(n:$[null scope`ns;name;`$string[scope`ns],"/",string name])in .tf.i.scopes;n:`$string[n],"_",string .tf.i.N[]]; scope[`ns]:n; .tf.i.scopes,:n; scope};
.tf.delScope:{.tf.graph.del x`graph};
.tf.i.scopes:`$();

//
// Session
//
/ New session.
/ @x (dict|long) Scope or Graph
/ @y long Options, can be 0.
/ @returns long Session
.tf.newSession:{
  if[99=type x;x:x`graph];
  if[not all -7=type each (x;y);'".tf.newSession: type"];
  if[0=y; y:.tf.i.sessOpts];
  sess:.tf.i.lib[`.tf.TF_NewSession][x;y;s:.tf.newStatus[]];
  .tf.checkAndDelStatus[".tf.newSession";s];
  : sess;
 };
 / Delete a session.
 / @x long Session
 .tf.delSession:{
   if[not -7=type x;'".tf.delSession: type"];
   .tf.i.lib[`.tf.TF_CloseSession][x;s:.tf.newStatus[]];
   .tf.checkAndDelStatus[".tf.delSession";s];
   .tf.i.lib[`.tf.TF_DeleteSession][x;s:.tf.newStatus[]];
   .tf.checkAndDelStatus[".tf.delSession";s];
  };
/ Runs a session with the given inputs.
/ @sess long session
/ @i table input operations: oper,index,tensor
/ @o table output operations: oper,index
/ @t (long list) target operations
/ @runOpts long run options, can be 0
/ @gmeta long graph meta, can be 0, it is an output arg, should be a Buffer.
/ @returns (long list) a list of requested tensors
.tf.session.run:{[sess;i;o;t;runOpts;gmeta]
  if[99=type i; i:enlist i]; if[99=type o; o:enlist o];
  if[not ((i~())|98=type i)&((o~())|98=type o)&(7=type t:t,`long$())&7=type (sess;runOpts;gmeta);'".tf.session.run: type"];
  if[98=type i;if[not all `oper`index`tensor in cols i;'".tf.session.run: input"]]; if[98=type o;if[not all `oper`index in cols o;'".tf.session.run: output"]];
  .tf.i.lib[`.tf.TF_SessionRun][sess;runOpts;$[count i;(i;i`tensor);()];$[count o;(o;r:count[o]#0);()];t;gmeta;s:.tf.newStatus[]];
  .tf.checkAndDelStatus[".tf.session.run";s];
  : r;
 };
 / Partially runs a session with the given inputs.
 / @sess long session
 / @h long handle
 / @i table input operations: oper,index,tensor
 / @o table output operations: oper,index
 / @t (long list) target operations
 / @returns (long list) a list of requested tensors
.tf.session.prun:{[sess;h;i;o;t]
  if[99=type i; i:enlist i]; if[99=type o; o:enlist o];
  if[not ((i~())|98=type i)&((o~())|98=type o)&(7=type t:t,`long$())&7=type (sess;h);'".tf.session.prun: type"];
  if[98=type i;if[not all `oper`index`tensor in cols i;'".tf.session.prun: input"]]; if[98=type o;if[not all `oper`index in cols o;'".tf.session.prun: output"]];
  .tf.i.lib[`.tf.TF_SessionPRun][sess;h;$[count i;(i;i`tensor);()];$[count o;(o;r:count[o]#0);()];t;s:.tf.newStatus[]];
  .tf.checkAndDelStatus[".tf.session.prun";s];
  : r;
 };
/ Sets up a partial run.
/ @sess long session
/ @i table input operations: oper,index
/ @o table output operations: oper,index
/ @t (long list) target operations
/ @returns long handle
.tf.session.newPRun:{[sess;i;o;t]
  i:$[i~();i;.tf.i.chkOut[".tf.session.newPRun";i]]; o:$[o~();o;.tf.i.chkOut[".tf.session.newPRun";o]];
  if[not (7=type t:(),t)&-7=type sess;'".tf.session.newPRun: type"];
  h:.tf.i.lib[`.tf.TF_SessionPRunSetup][sess;i;o;t;s:.tf.newStatus[]];
  .tf.checkAndDelStatus[".tf.session.prun";s];
  : h;
 };
.tf.session.delPRunHandle:{if[not -7=type x;'".tf.session.delPRunHandle: type"]; .tf.i.lib[`.tf.TF_DeletePRunHandle]x};
/ New session options.
/ @x symbol target, can be `
/ @y (string|byte list) config, can be empty
/ @returns long session options
.tf.session.newOps:{
  if[not (-11=type x)&type[y]in 10 4h;'".tf.session.newOps: type"];
  if[0=o:.tf.i.lib[`.tf.TF_NewSessionOptions][];'".tf.session.newOps: alloc"];
  if[not`=x; .tf.i.lib[`.tf.TF_SetTarget][o;x]];
  if[count y; .tf.i.lib[`.tf.TF_SetConfig][o;y;s:.tf.newStatus[]]; if[not`TF_OK=.tf.getStatus s; .tf.session.delOpts o]; .tf.checkAndDelStatus[".tf.session.newOps";s]];
  : o;
 };
/ Delete session options.
/ @x long options
.tf.session.delOpts:{if[not -7=type x;'".tf.session.delOpts: type"]; .tf.i.lib[`.tf.TF_DeleteSessionOptions][]};
/ List associated devices
/ @x long session
/ @returns (symbol list) devices
.tf.session.listDevices:{
  if[not -7=type x;'".tf.listDevices: type"];
  devs:.tf.i.lib[`.tf.TF_SessionListDevices][x;s:.tf.newStatus[]];
  .tf.checkAndDelStatus[".tf.listDevices";s];
  res:@[{.tf.i.getDevice[x] each til .tf.i.lib[`.tf.TF_DeviceListCount][x]};devs;::];
  .tf.i.lib[`.tf.TF_DeleteDeviceList][devs];
  if[10=type res;'res];
  :`$res;
 };
.tf.i.getDevice:{
  name:.tf.i.lib[`.tf.TF_DeviceListName][x;s:.tf.newStatus[]];
  .tf.checkAndDelStatus[".tf.getDevices";s];
  ty:.tf.i.lib[`.tf.TF_DeviceListType][x;s:.tf.newStatus[]];
  .tf.checkAndDelStatus[".tf.getDevices";s];
  memory:.tf.i.lib[`.tf.TF_DeviceListMemoryBytes][x;s:.tf.newStatus[]];
  .tf.checkAndDelStatus[".tf.getDevices";s];
  :`name`ty`memory!(name;ty;memory);
 };

//
//  Tensors
//
/ Get the tensor type.
/ @x long tensor
/ @returns symbol type
.tf.tensor.type:{if[not -7=type x;'".tf.tensor.type: type"]; key[.tf.i.dt] .tf.i.lib[`.tf.TF_TensorType]x};
/ Get the tensor shape.
/ @x long tensor
/ @returns list all dimensions, () means -1, `long$() means scalar
.tf.tensor.shape:{
  if[not -7=type x;'".tf.tensor.shape: type"];
  if[1>d:.tf.i.lib[`.tf.TF_NumDims]x; :(`long$();())d<0];
  :{.tf.i.lib[`.tf.TF_Dim][x;y]}[x]each "i"$til d;
 };
/ Get the tensor size.
/ @x long tensor
/ @returns long size
.tf.tensor.size:{if[not -7=type x;'".tf.tensor.size: type"]; .tf.i.lib[`.tf.TF_TensorByteSize]x};
/ Delete a tensor.
/ @x long tensor
.tf.tensor.del:{if[not -7=type x;'".tf.tensor.del: type"]; .tf.i.lib[`.tf.TF_DeleteTensor]x};
/ Allocate a new tensor using Q data.
/ @x symbol TF data type
/ @y (long|long list) dimensions
/ @z (atom|list) Q data
/ @returns long tensor
.tf.tensor.alloc:{
  if[not 7=type y:(),y;'".tf.tensor.alloc: type"];
  .tf.i.chkTy[".tf.tensor.alloc";x];
  $[(str:x=`TF_STRING)&(all (type each z)in 4 10h)|(type z)in 4 10h;1;null .tf.i.dt x;'".tf.tensor.alloc: unsupported data type";(.tf.i.qdt abs type z)=.tf.i.dt x;1;'".tf.tensor.alloc: incompatible TF and Q types"];
  z:$[str&0<>type z; z:enlist z;0>type z;(),z;z]; if[not count[z]=size:(1^.tf.i.t2q x)*prd y;'".tf.tensor.alloc: size"];
  if[str;size:(8*count z)+sum {.tf.i.lib[`.tf.TF_StringEncodedSize]count x}each z];
  if[0=t:.tf.i.lib[`.tf.TF_AllocateTensor]["i"$key[.tf.i.dt]?x;y;size*(1^.tf.i.dt x)];'".tf.tensor.alloc: alloc"];
  ptr:.tf.i.lib[`.tf.TF_TensorData]t;
  if[str;
    s:.tf.newStatus[];
    r:{[s;l;p;str] if[p<0;:p]; p+:.tf.i.lib[`.tf.TF_StringEncode][str;p;l-p;s]; $[`TF_OK=.tf.getStatus s;p;-1]}[s;ptr+size]\[sptr:ptr+(8*count z);z]; / encoded strings
    if[any r<0; .tf.tensor.del t]; .tf.checkAndDelStatus[".tf.tensor.alloc"] s;
    .tf.i.lib[`.tf.writeToTensor][ptr;(sptr,-1_r)-sptr]; / offsets
    : t;
  ];
  .tf.i.lib[`.tf.writeToTensor][ptr;z];
  : t;
 };
/ weak list of used Q data, if ref cnt of an item is 1 it can be deleted
/ .tf.i.tmap:enlist(::);
/ .tf.i.useTMap:0b;
/ Create a new tensor backed by Q data.
/ @x symbol TF data type
/ @y (long|long list) dimensions
/ @z (atom|list) Q data
/ @returns long tensor
.tf.tensor.new:{
  if[not 7=type y:(),y;'".tf.tensor.new: type"];
  .tf.i.chkTy[".tf.tensor.new";x];
  if[(0>type z)|x=`TF_STRING; :.tf.tensor.alloc[x;y;z]]; / redirect strings and atoms
  $[null .tf.i.dt x;'".tf.tensor.new: unsupported data type";(.tf.i.qdt abs type z)=.tf.i.dt x;1;'".tf.tensor.new: incompatible TF and Q types"];
  / if[.tf.i.useTMap; .tf.i.tmap,:enlist z]; / save Q data to ensure it is not GBed
  if[not count[z]=(1^.tf.i.t2q x)*prd y;'".tf.tensor.new: size"];
  if[0=t:.tf.i.lib[`.tf.TF_NewTensor]["i"$key[.tf.i.dt]?x;y;z];'".tf.tensor.new: alloc"];
  : t;
 };
/ Collect unused Q objs.
.tf.tensor.gb:{if[sum i:where 3>(-16!)each .tf.i.tmap; .tf.i.tmap:.tf.i.tmap where not i]};
/ Get a copy of the tensor data.
/ @x tensor
.tf.tensor.value:{
  ty:.tf.tensor.type x; sz:.tf.tensor.size x; sh:prd sh2:.tf.tensor.shape x;
  if[sh~();:()];
  ptr:.tf.i.lib[`.tf.TF_TensorData]x;
  if[`TF_STRING=ty;
    .tf.i.lib[`.tf.readFromTensor][ptr;off:sh#0];
    r:{$[`TF_OK=.tf.getStatus x; .tf.i.lib[`.tf.TF_StringDecode][z;y-z;x];""]}[stat:.tf.newStatus[];ptr+sz] each off+ptr+sh*8;
    .tf.checkAndDelStatus[".tf.tensor.value";stat];
    :$[0=count sh2;first;::] r;
  ];
  if[null .tf.i.dt ty; '".tf.tensor.value: unsupported data type"];
  buf:(("j"$sz%.tf.i.dt ty)&((1^.tf.i.t2q ty)*sh))#.tf.i.q4t[ty]$(); / take the min as a precaution
  : $[(1=1^.tf.i.t2q ty)&0=count sh2;first;::] .tf.i.lib[`.tf.readFromTensor][ptr;buf];
 };

//
// Misc
//
/ Create a new status.
/ @returns long status
.tf.newStatus:{.tf.i.lib[`.tf.TF_NewStatus][]};
/ Get a status code.
/ @x long status obj
/ @returns symbol status code
.tf.getStatus:{if[not -7=type x;'".tf.getStatus: type"]; .tf.i.st .tf.i.lib[`.tf.TF_GetCode]x};
/ Get a status message.
/ @x long status obj
/ @returns string status message
.tf.getStatusMsg:{$[`TF_OK=.tf.getStatus x;"";.tf.i.lib[`.tf.TF_Message]x]};
/ Delete a status.
/ @x long status
.tf.delStatus:{if[not -7=type x;'".tf.delStatus: type"]; .tf.i.lib[`.tf.TF_DeleteStatus]x};
/ Set status.
/ @x long status
/ @y symbol code
/ @z string message
.tf.setStatus:{if[not (-7=type x)&(-11=type y)&-11=type z;'".tf.setStatus: type"]; if[not y in .tf.i.st;'".tf.setStatus: wrong code"]; .tf.i.lib[`.tf.TF_SetStatus][x;"i"$.tf.i.st?y;z]};
/ Check status, delete it and throw an exception if it is not TF_OK.
/ @x long status
.tf.checkAndDelStatus:{s:.tf.getStatusMsg y; .tf.delStatus y; if[not 0=count s; 'x,": ",s]};
/ Get Tensorflow version.
/ @returns string version
.tf.version:{.tf.i.lib[`.tf.TF_Version][]};
/ Get data type size.
/ @x symbol data type
/ @returns long size
.tf.getDataTypeSize:{.tf.i.chkTy[".tf.getDataTypeSize";x]; .tf.i.lib[`.tf.TF_DataTypeSize]"i"$key[.tf.i.dt]?x};
/ Load a graph from a save
/ @dir symbol export directory
/ @tags (symbol list) tags
/ @opts long session options
/ @runOpts long a buffer with run options, can be 0
/ @gmeta long a buffer with meta graph, can be 0
/ @returns (long list) A pair (session;graph)
.tf.loadSavedModel:{[dir;tags;opts;runOpts;gmeta]
  if[-11=type tags; tags:enlist tags]; if[not (-11=type dir)&(11=type tags)&7=type (opts;runOpts;gmeta);'".tf.loadSavedModel: type"];
  if[opts=0;opts:.tf.i.sessOpts];
  g:.tf.graph.new[];
  sess:.tf.i.lib[`.tf.TF_LoadSessionFromSavedModel][opts;runOpts;dir;tags;g;gmeta;s:.tf.newStatus[]];
  if[not `TF_OK=.tf.getStatus s; .tf.graph.del g];
  .tf.checkAndDelStatus s;
  : (sess;g);
 };
/ Initialize the library.
/ @x symbol tf.so path or `
.tf.init:{x:$[`=x;`:tf;x:` sv x,`tf]; l:x 2: (`tf__init;1); .tf.i.lib:l[]; .tf.i.sessOpts:.tf.session.newOps[`;0#0x00];};
.tf.i.const:{
  if[not(c:count x)within 2 4;'".tf.const: args"]; sc:x 0; qdt:x 1;
  dim:$[(not 7=abs t2:type x 2)&4>c;$[(t=10)|0>t:type qdt;`long$();count qdt];7=abs t2;(),x 2;(7=abs type x 3)&4=c;x 3;'".tf.const: dims"];
  ty:$[0=type qdt;$[all 10=type each qdt;`TF_STRING;`];.tf.i.defTy abs type qdt];
  ty:$[2=c;ty;-11=t2;x 2;(-11=type x 3)&4=c;x 3;ty]; .tf.i.chkTy[".tf.const";ty];
  t:.tf.tensor.alloc[ty;dim;qdt];
  : .[{.tf.addOp[x;`Const;();`dtype`value!(y;z)]};(sc;ty;t);{.tf.tensor.del x;'y}t];
 };
/ Const wrapper. It has 3 modes: 1) (scope;qdata), TF datatype and dimension are calculated. 2) (scope;qdata;dims|tf type) 3) (scope;qdata;dims|tf type;dims|tf type)
/ qdata: INT types + string, atoms or vectors.
/ @sc dict scope
/ @dt any Q data
/ @example .tf.const[scope;1]
.tf.const:(')[.tf.i.const;enlist];
/ Variable wrapper.
/ @sc dict scope
/ @ty symbol TF Datatype
/ @sh (long|long list) shape
/ @example .tf.variable[scope;`TF_FLOAT;10 10]
.tf.variable:{[sc;ty;sh] .tf.addOp[sc;`VarHandleOp;();`dtype`shape!(.tf.i.chkTy[".tf.variable";ty];sh)]};
/ Assign to a variable.
/ @sc dict scope
/ @n (dict|table) variable operation output
/ @v (dict|table) value
/ @example .tf.assign[scope;n:.tf.variable[scope;`TF_FLOAT;10];.tf.const[scope;10#1.0e]]
.tf.assign:{[sc;n;v] .tf.addOp[sc;`AssignVariableOp;(.tf.i.chkOut[".tf.assign";n];.tf.i.chkOut[".tf.assign";v]);()]};
/ Add to a variable.
/ @sc dict scope
/ @n (dict|table) variable operation output
/ @v (dict|table) value
/ @example .tf.assignAdd[scope;n;.tf.const[scope;10#1.0e]]
.tf.assignAdd:{[sc;n;v] .tf.addOp[sc;`AssignAddVariableOp;(.tf.i.chkOut[".tf.assignAdd";n];.tf.i.chkOut[".tf.assignAdd";v]);()]};
/ Sub from a variable.
/ @sc dict scope
/ @n (dict|table) variable operation output
/ @v (dict|table) value
/ @example .tf.assignSub[scope;n;.tf.const[scope;10#1.0e]]
.tf.assignSub:{[sc;n;v] .tf.addOp[sc;`AssignSubVariableOp;(.tf.i.chkOut[".tf.assignSub";n];.tf.i.chkOut[".tf.assignSub";v]);()]};
/ Read a variable.
/ @sc dict scope
/ @n (dict|table) variable operation output
/ @example .tf.readVar[scope;n]
.tf.readVar:{[sc;n;ty] .tf.addOp[sc;`ReadVariableOp;.tf.i.chkOut[".tf.read";n];enlist[`dtype]!enlist .tf.i.chkTy[".tf.readVar";ty]]};
/ Placeholder.
/ @sc dict scope
/ @dt symbol TF datatype
/ option in scope: `shape
.tf.placeholder:{[sc;dt] a:enlist[`dtype]!enlist .tf.i.chkTy[".tf.placeholder";dt]; if[`shape in key sc;a:a,enlist[`shape]!enlist (),sc`shape]; .tf.addOp[sc;`Placeholder;();a]};
/ Matrix multiplication.
/ @sc dict scope
/ @v1 (dict|table) Input 1
/ @v2 (dict|table) Input 2
/ Options in scope: `transpose_a and `transpose_b
.tf.matMul:{[sc;v1;v2] att:"x"$(`transpose_a`transpose_b inter key sc)#sc; .tf.addOp[sc;`MatMul;(.tf.i.chkOut[".tf.matMul";v1];.tf.i.chkOut[".tf.matMul";v2]);att]};
/ Add.
/ @sc dict scope
/ @v1 (dict|table) Input 1
/ @v2 (dict|table) Input 2
.tf.add:{[sc;v1;v2] .tf.addOp[sc;`Add;(.tf.i.chkOut[".tf.add";v1];.tf.i.chkOut[".tf.add";v2]);()]};
/ AddN.
/ @sc dict scope
/ @v1 table Inputs
.tf.addN:{[sc;v1] .tf.addOp[sc;`AddN;.tf.i.chkOut[".tf.add";v1];()]};
/ Sub.
/ @sc dict scope
/ @v1 (dict|table) Input 1
/ @v2 (dict|table) Input 2
.tf.sub:{[sc;v1;v2] .tf.addOp[sc;`Sub;(.tf.i.chkOut[".tf.sub";v1];.tf.i.chkOut[".tf.sub";v2]);()]};
/ Mul.
/ @sc dict scope
/ @v1 (dict|table) Input 1
/ @v2 (dict|table) Input 2
.tf.mul:{[sc;v1;v2] .tf.addOp[sc;`Mul;(.tf.i.chkOut[".tf.mul";v1];.tf.i.chkOut[".tf.mul";v2]);()]};
/ Div.
/ @sc dict scope
/ @v1 (dict|table) Input 1
/ @v2 (dict|table) Input 2
.tf.div:{[sc;v1;v2] .tf.addOp[sc;`Div;(.tf.i.chkOut[".tf.div";v1];.tf.i.chkOut[".tf.div";v2]);()]};
/ Neg.
/ @sc dict scope
/ @v1 (dict|table) Input 1
.tf.neg:{[sc;v1] .tf.addOp[sc;`Neg;.tf.i.chkOut[".tf.neg";v1];()]};
/ Abs.
/ @sc dict scope
/ @v1 (dict|table) Input 1
.tf.abs:{[sc;v1] .tf.addOp[sc;`Abs;.tf.i.chkOut[".tf.abs";v1];()]};
/ TensorDataset
/ @sc dict scope
/ @i table Inputs
/ @sh list shape list
.tf.tensorDataSet:{[sc;i;sh] if[not all 7=type each sh;'".tf.tensorDataSet: shapes"]; .tf.addOp[sc;`TensorDataset;enlist .tf.i.chkOut[".tf.tensorDataSet"] each i;enlist`output_shapes!enlist sh]};
/ Make an iterator.
/ @sc dict scope
/ @d (table|dict) Input
/ @i (table|dict) Iterator
.tf.makeIter:{[sc;d;i] .tf.addOp[sc;`MakeIterator;(.tf.i.chkOut[".tf.makeIter";d];.tf.i.chkOut[".tf.makeIter";i]);()]};
/ Create an iterator
/ @sc dict scope
/ @n symbol name
/ @c symbol container
/ @ty (symbol list) TF types
/ @sh list Shapes
.tf.iter:{[sc;n;c;ty;sh] if[not(all 7=type each sh)&11=type(n;c);'".tf.iter: type"]; .tf.addOp[sc;`Iterator;();`shared_name`container`output_types`output_shapes!(n;c;.tf.i.chkTy[".tf.iter"] each (),ty;sh)]};
/ Cast value to type.
/ @sc dict scope
/ @v table Input
/ @t symbol TF type
.tf.cast:{[sc;v;t] .tf.addOp[sc;`Cast;.tf.i.chkOut[".tf.cast";v];enlist[`DstT]!enlist.tf.i.chkTy[".tf.cast";t]];};

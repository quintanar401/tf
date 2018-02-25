.t.testOpShape:{[]
  s:.tf.newScope[];
  x:.tf.placeholder[.tf.subScope[s;`x],enlist[`shape]!enlist 1;`TF_INT32];
  y:.tf.placeholder[.tf.subScope[s;`y];`TF_INT32];
  z:.tf.add[s;x;y];
  sess:.tf.newSession[s;0];
  i:x,y;
  i[`tensor]:.tf.tensor.alloc[`TF_DOUBLE;1;7f];
  r:.tf.session.run[sess;i;z;();0;0];
  if[not 1=count r;'"unexpected return val"];
  if[not 14f=v:.tf.tensor.value r 0;'"wrong value: ",.Q.s1 v];
  .tf.tensor.del each r;
  .tf.delSession sess;
  .tf.delScope s;
 };

.t.testOpShape2:{
  s:.tf.newScope[];
  c1:.tf.const[s;1];
  c2:.tf.const[s;1 2 3 4;2 2];
  op:.tf.addOp[s;`ShapeN;(c1;c2);()];
  if[not 2=l:.tf.ops.outputLength[op;"output"];'"wrong output length: ",string l];
  if[not 2=count l:.tf.ops.outputs op;'"wrong output: ",.Q.s1 l];
  if[not 2=l:.tf.ops.inputLength[op;"input"];'"wrong input length: ",string l];
  if[not 2=count l:.tf.ops.inputs op;'"wrong output: ",.Q.s1 l];
  .tf.delScope[];
 };

.t.testOp:{
  s:.tf.newScope[];
  op:.tf.add[s,enlist[`opName]!enlist`testAdd;.tf.;c1:.tf.const[s;1];c2:.tf.const[s;2]];
  op1:.tf.sub[s;op;.tf.const[s;3]];
  op2:.tf.sub[s;.tf.const[s;4];op];
  if[not `testAdd~v:.tf.ops.name op;'"wrong name: ",string v];
  if[not `Add~v:.tf.ops.type op;'"wrong type: ",string v];
  if[not `~v:.tf.ops.device op;'"wrong device: ",string v];
  if[not (enlist`oper`index`dtype!(op;0i;`TF_INT64))~v:.tf.ops.outputs op;'"wrong outputs: ",.Q.s1 v];
  if[not (flip`oper`index`dtype!(2#op;0 1i;2#`TF_INT64))~v:.tf.ops.inputs op;'"wrong inputs: ",.Q.s1 v];
  if[not c1=v:(.tf.ops.producer`oper`index!(op;0i))`oper;'"wrong producer: ",string v];
  if[not (op1;op2)~v:(.tf.ops.consumers`oper`index!(op;0i))`oper;'"wrong consumers: ",.Q.s1 v];
  .tf.delScope[];
 };

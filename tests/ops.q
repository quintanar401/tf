.t.testOpShape:{[]
  s:.tf.newScope[];
  x:.tf.placeholder[.tf.subScope[s;`x],enlist[`shape]!enlist 1;`TF_INT32];
  y:.tf.placeholder[.tf.subScope[s;`y];`TF_INT32];
  z:.tf.add[s;x;y];
  sess:.tf.newSession[s;0];
  i:x,y;
  i[`tensor]:.tf.tensor.alloc[`TF_INT32;1;7i];
  r:.tf.session.run[sess;i;z;();0;0];
  if[not 1=count r;'"unexpected return val"];
  if[not enlist[14i]~v:.tf.tensor.value r 0;'"wrong value: ",.Q.s1 v];
  .tf.tensor.del each r;
  .tf.delSession sess;
  .tf.delScope s;
 };

.t.testOpShape2:{
  s:.tf.newScope[];
  c1:.tf.const[s;1];
  c2:.tf.const[s;1 2 3 4;2 2];
  op:.tf.addOp[s;`ShapeN;enlist c1,c2;()];
  if[not 2=l:.tf.ops.outputLength[o:op[0]`oper;`output];'"wrong output length: ",string l];
  if[not 2=count l:.tf.ops.outputs o;'"wrong output: ",.Q.s1 l];
  if[not 2=l:.tf.ops.inputLength[o;`input];'"wrong input length: ",string l];
  if[not 2=count l:.tf.ops.inputs o;'"wrong output: ",.Q.s1 l];
  .tf.delScope[s];
 };

.t.testOp:{
  s:.tf.newScope[];
  op:.tf.add[s,enlist[`opName]!enlist`testAdd;c1:.tf.const[s;1];c2:.tf.const[s;2]];
  op1:.tf.sub[s;op;.tf.const[s;3]];
  op2:.tf.sub[s;.tf.const[s;4];op];
  if[not `testAdd~v:.tf.ops.name o:op[0]`oper;'"wrong name: ",string v];
  if[not `Add~v:.tf.ops.type o;'"wrong type: ",string v];
  if[not `~v:.tf.ops.device o;'"wrong device: ",string v];
  if[not (enlist`oper`index`dtype!(o;0i;`TF_INT64))~v:.tf.ops.outputs o;'"wrong outputs: ",.Q.s1 v];
  if[not (flip`oper`index`dtype!(2#o;0 1i;2#`TF_INT64))~v:.tf.ops.inputs o;'"wrong inputs: ",.Q.s1 v];
  if[not c1[0;`oper]=v:(.tf.ops.producer`oper`index!(o;0i))`oper;'"wrong producer: ",string v];
  if[not (op1[0]`oper;op2[0]`oper)~v:(.tf.ops.consumers`oper`index!(o;0i))`oper;'"wrong consumers: ",.Q.s1 v];
  .tf.delScope[s];
 };

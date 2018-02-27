.tst.data:(
  ((1;`TF_INT64;`long$());-1);
  ((-1 -2 3f;`TF_DOUBLE;3);1 2 -3f);
  ((1 -2 -3 4e;`TF_FLOAT;2 2);-1 2 3 -4e)
 );
.tst.create:{
  s:.tf.newScope[];
  p:.tf.placeholder[s,enlist[`opName]!enlist`p1;x];
  n:.tf.neg[s,enlist[`opName]!enlist`neg1;p];
  :(s;p;n);
 };
.tst.testSession:{[d]
  t:.tf.tensor.alloc . d[0] 1 2 0;
  g:.tst.create d[0] 1; / scope, inp, out
  sess:.tf.newSession[g 0;0];
  r:.tf.session.run[sess;update tensor:t from g 1;g 2;(),g[2;0]`oper;0;0];
  if[not 1=count r;'"wrong output length: ",string count r];
  if[not d[1]~v:.tf.tensor.value r 0; '"wrong result: ",.Q.s1[d 1]," vs ",.Q.s1 v];
  .tf.tensor.del r 0;
  .tf.delSession sess;
 };
.t.testSession:{.tst.testSession each .tst.data};

.t.testSessionConcat:{
  s:.tf.newScope[];
  dim1:.tf.const[s;1i];
  m1:.tf.const[s;1 2 3 4 5 6;2 3];
  m2:.tf.const[s;7 8 9 10 11 12;2 3];
  want:1 2 3 7 8 9 4 5 6 10 11 12;
  concat:.tf.addOp[s;`Concat;(dim1;m1,m2);()];
  sess:.tf.newSession[s;0];
  r:.tf.session.run[sess;();concat;();0;0];
  if[not 1=count r;'"wrong output length: ",string count r];
  if[not want~v:.tf.tensor.value r 0; '"wrong result: ",.Q.s1[want]," vs ",.Q.s1 v];
  .tf.tensor.del r 0;
  .tf.delSession sess;
 };

.t.testSessionString:{
  s:.tf.newScope[];
  feed:.tf.const[s;"PleaseHashMe"];
  hash:.tf.addOp[s;`StringToHashBucketFast;feed;enlist[`num_buckets]!enlist prd 32#2];
  str:.tf.addOp[s;`AsString;hash;()];
  sess:.tf.newSession[s;0];
  r:.tf.session.run[sess;();str;();0;0];
  if[not 1=count r;'"wrong output length: ",string count r];
  if[not (want:"1027741475")~v:.tf.tensor.value r 0; '"wrong result: ",.Q.s1[want]," vs ",.Q.s1 v];
  .tf.tensor.del r 0;
  .tf.delSession sess;
 };

.t.testSessionConcur:{
  if[0=system "s";'"need -s param"];
  g:.tst.create[`TF_INT64];
  t:.tf.tensor.alloc[`TF_INT64;`long$();1];
  sess:.tf.newSession[g 0;0];
  {[x;y;z;a] r:.tf.session.run[x;y;z;();0;0]; v:.tf.tensor.value r 0; .tf.tensor.del r 0; v}[sess;update tensor:t from g 1;g 2] peach til 100;
  .tf.delSession sess;
 };

.t.testSessionPRun:{
  s:.tf.newScope[];
  a:.tf.placeholder[s;`TF_INT32]; b:.tf.placeholder[s;`TF_INT32];
  two:.tf.const[s;2i]; three:.tf.const[s;3i];
  plus2:.tf.add[s;a;two]; plus3:.tf.add[s;plus2;three]; plusB:.tf.add[s;plus3;b];
  sess:.tf.newSession[s;0];
  h:.tf.session.newPRun[sess;a,b;plus2,plusB;plus3`oper];
  val:.tf.tensor.alloc[`TF_INT32;`long$();1i];
  r:.tf.session.prun[sess;h;update tensor:val from a;plus2;()];
  if[not 3=v:.tf.tensor.value r 0;'"wrong plus2 value(3): ",string v];
  .tf.tensor.del r 0; .tf.tensor.del val;
  val:.tf.tensor.alloc[`TF_INT32;`long$();4i];
  r:.tf.session.prun[sess;h;update tensor:val from b;plusB;()];
  if[not 10=v:.tf.tensor.value r 0;'"wrong plus2 value(10): ",string v];
  .tf.tensor.del r 0;
  .tf.session.delPRunHandle h;
  .tf.delSession sess;
 };

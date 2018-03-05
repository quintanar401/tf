.t.testInception:{
  if[not `inception in key `:.; '"load the inception model into test from https://storage.googleapis.com/download.tensorflow.org/models/inception5h.zip"];
  if[not (i:`$.z.x 1) in key `:.;'"provide a jpeg as an argument"];
  m:read1 `$":inception/tensorflow_inception_graph.pb";
  .tst.labels:read0 `$":inception/imagenet_comp_graph_label_strings.txt";
  .tf.graph.import[g:.tf.graph.new[];m;`];
  sess:.tf.newSession[g;0];
  t:.tst.getImage[hsym i];
  o:.tf.session.run[sess;`oper`index`tensor!(.tf.ops.getOpByName[g;`input];0i;t);`oper`index!(.tf.ops.getOpByName[g;`output];0i);();0;0];
  v:v i:idesc v:.tf.tensor.value o 0; / the output tensor is an array of vectors, but with 1 example it is just a vector
  -1 "\nTop 5 predictions"; {-1 .tst.labels[y],"(",string[x],")"}'[5#v;5#i];
  .tf.delSession sess;
  .tf.tensor.del each t,o;
 };

.tst.getImage:{
  t:.tf.tensor.alloc[`TF_STRING;`long$();img:read1 x]; / expects a string but in Q2C a byte list should do as well
  s:.tf.newScope[];
  sess:.tf.newSession[s;0];
  inp:.tf.placeholder[s;`TF_STRING];
  op:.tf.addOp[s;`DecodeJpeg;inp;enlist[`channels]!enlist 3];
  op:.tf.addOp[s;`Cast;op;enlist[`DstT]!enlist`TF_FLOAT];
  op:.tf.addOp[s;`ExpandDims;(op;.tf.const[.tf.subScope[s;`make_batch];0i]);()];
  op:.tf.addOp[s;`ResizeBilinear;(op;.tf.const[.tf.subScope[s;`size];224 224i]);()];
  out:.tf.div[s;.tf.sub[s;op;.tf.const[.tf.subScope[s;`mean];117e]];.tf.const[.tf.subScope[s;`scale];1e]]; / (x-mean)/scale
  o:.tf.session.run[sess;update tensor:t from inp;out;();0;0];
  .tf.tensor.del t; .tf.delSession sess;
  :o 0;
 };

.t.testGraph:{
  sc:.tf.newScope[];
  i:.tf.addOp[sc;`Placeholder;();`dtype`shape`opName!(`TF_INT64;-1 2;`input)];
  n:.tf.addOp[sc;`Neg;i;``opName!(`;`neg)];
  sz:.tf.graph.serialize sc`graph;
  .tf.graph.import[sc`graph;sz;`imported];
  if[not (`$("imported/input";"imported/neg";"input";"neg"))~o:asc .tf.ops.name each .tf.ops.getOperations sc;'"wrong operation names: ",", "sv string o];
  if[not -1 2~sh:.tf.graph.opGetShape[sc`graph;i 0];'"wrong shape: ",.Q.s1 sh];
  .tf.graph.opSetShape[sc`graph;i 0;10 2];
  if[not 10 2~sh:.tf.graph.opGetShape[sc`graph;i 0];'"wrong shape2: ",.Q.s1 sh];
  .tf.delScope sc;
 };

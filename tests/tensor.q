.tst.args:(
  (`TF_BOOL;`long$();0x01);
  (`TF_INT8;`long$();0x05);
  (`TF_INT16;`long$();5h);
  (`TF_INT32;`long$();5i);
  (`TF_INT64;`long$();5);
  (`TF_UINT8;`long$();0x05);
  (`TF_UINT16;`long$();5h);
  (`TF_UINT32;`long$();5i);
  (`TF_UINT64;`long$();5);
  (`TF_FLOAT;`long$();5e);
  (`TF_DOUBLE;`long$();5.0);
  (`TF_COMPLEX64;`long$();5.0 6.0e);
  (`TF_COMPLEX128;`long$();5.0 6.0);
  (`TF_STRING;`long$();"a string");
  (`TF_UINT32;1;(),1i);
  (`TF_UINT64;1;(),1);
  (`TF_BOOL;2;0x0100);
  (`TF_FLOAT;1;(),1e);
  (`TF_DOUBLE;1;(),1.0);
  (`TF_DOUBLE;1 1;(),1.0);
  (`TF_DOUBLE;1 1 1;(),1.0);
  (`TF_DOUBLE;1 1 2;1.0 2.0);
  (`TF_DOUBLE;1 1 1 1;(),1.0);
  (`TF_STRING;2;("string";"array"));
  (`TF_DOUBLE;3 2;1 2 3 4 5 6.0);
  (`TF_DOUBLE;2 3;1 2 3 4 5 6.0);
  (`TF_DOUBLE;4 3 2;1 2 3 4 5 6 7 8 9 10 11 12 0 -1 -2 -3 -4 -5 -6 -7 -8 -9 -10 -11.0);
  (`TF_STRING;2 2;("row0col0";"row0col1";"row1col0";"row1col1"));
  (`TF_STRING;2 3;("row0col0";"row0col1";"row0col2";"row1col0";"row1col1";"row1col2"))
 );


.tst.alloc:{
  t:.tf.tensor.alloc . x;
  if[not x[0]~v:.tf.tensor.type t;'"Tensor types differ: ",string[x 0]," vs ",.Q.s1 v];
  if[not ((),x[1])~v:.tf.tensor.shape t;'"Tensor shapes differ: ",.Q.s1[x 1]," vs ",.Q.s1 v];
  if[not x[2]~v:.tf.tensor.value t;'"Tensor values differ: ",.Q.s1[x 2]," vs ",.Q.s1 v];
  if[x[0]~`TF_DOUBLE; if[not (sz:8*count x 2)=tsz:.tf.tensor.size t;'"Tensor sizes differ: ",string[sz]," vs ",string tsz]];
  if[count[x 1]&not `TF_STRING=x 0;
    ptr:.tf.i.lib[`.tf.TF_TensorData]t;
    .tf.i.lib[`.tf.writeToTensor][ptr;.tf.i.dt[x 0]#0xa0];
    if[x[2]~v:.tf.tensor.value t;'"Q value changed: ",.Q.s1 x 2];
  ];
  .tf.tensor.del t;
 };
.t.testAllocTensor:{.tst.alloc each .tst.args};

.tst.new:{
  t:.tf.tensor.new . x;
  if[not x[0]~v:.tf.tensor.type t;'"Tensor types differ: ",string[x 0]," vs ",.Q.s1 v];
  if[not ((),x[1])~v:.tf.tensor.shape t;'"Tensor shapes differ: ",.Q.s1[x 1]," vs ",.Q.s1 v];
  if[not x[2]~v:.tf.tensor.value t;'"Tensor values differ: ",.Q.s1[x 2]," vs ",.Q.s1 v];
  if[x[0]~`TF_DOUBLE; if[not (sz:8*count x 2)=tsz:.tf.tensor.size t;'"Tensor sizes differ: ",string[sz]," vs ",string tsz]];
  if[count[x 1]&not `TF_STRING=x 0;
    ptr:.tf.i.lib[`.tf.TF_TensorData]t;
    .tf.i.lib[`.tf.writeToTensor][ptr;.tf.i.dt[x 0]#0xa0];
    if[not x[2]~v:.tf.tensor.value t;'"Q value did not change: ",.Q.s1[x 2]," vs ",.Q.s1 v];
  ];
  .tf.tensor.del t;
 };
.t.testNewTensor:{.tst.new each .tst.args};

.t.testDim1Err:{.tf.tensor.new[`TF_INT64;`long$();1 2]};
.t.testDim2Err:{.tf.tensor.new[`TF_INT64;2;1]};
.t.testDim3Err:{.tf.tensor.new[`TF_INT64;2 2;1 2 3 4 5]};
.t.testDim4Err:{.tf.tensor.new[`TF_STRING;2;"st"]};

.t.testType1Err:{.tf.tensor.new[`TF_INT64;2;1 1i]};
.t.testType2Err:{.tf.tensor.new["TF_INT64";2;1 1i]};
.t.testType3Err:{.tf.tensor.new[`TF_INT64;1.0;1 1i]};

.t.testMism1Err:{.tf.tensor.new[`TF_ERR;2;1 1]};
.t.testMism2Err:{.tf.tensor.new[`TF_VARIANT;2;1 1]};

.t.testArg1Err:{.tf.tensor.type 1i};
.t.testArg2Err:{.tf.tensor.shape 1i};
.t.testArg3Err:{.tf.tensor.value 1i};
.t.testArg4Err:{.tf.tensor.size 1i};
.t.testArg5Err:{.tf.tensor.alloc[1;2;1 2]};
.t.testArg6Err:{.tf.tensor.alloc[`TF_ERR;2;1 2]};
.t.testArg7Err:{.tf.tensor.alloc[`TF_FLOAT;`;1 2]};
.t.testArg8Err:{.tf.tensor.new[1;2;1 2]};
.t.testArg9Err:{.tf.tensor.new[`TF_ERR;2;1 2]};
.t.testArg10Err:{.tf.tensor.new[`TF_FLOAT;`;1 2.0]};

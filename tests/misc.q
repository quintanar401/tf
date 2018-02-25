.t.testStatus:{
  s:.tf.newStatus[];
  .tf.setStatus[s;`TF_CANCELLED;"some error"];
  if[not `TF_CANCELLED~v:.tf.getStatus s;'"wrong status code: ",string v];
  if[not "some error"~v:.tf.getStatusMsg s;'"wrong status msg: ",.Q.s1 v];
  .tf.delStatus[s];
 };
.t.testStatus1Err:{.tf.getStatus 0i};
.t.testStatus2Err:{.tf.getStatusMsg 0i};
.t.testStatus3Err:{.tf.setStatus[0i;`TF_CANCELLED;"msg"]};
.t.testStatus4Err:{s:.tf.newStatus[]; .tf.setStatus[s;`TF_ERR;"msg"]};
.t.testStatus5Err:{s:.tf.newStatus[]; .tf.setStatus[s;`TF_CANCELLED;1]};
.t.testStatus6Err:{s:.tf.newStatus[]; .tf.setStatus[s;1;"msg"]};

.t.testVersion:{.tf.version[]};

.t.testDataSize:{if[not 8=sz:.tf.getDataTypeSize`TF_DOUBLE;'"wrong data size: ",string sz]};

.t.testDataSize1Err:{.tf.getDataTypeSize 1};
.t.testDataSize2Err:{.tf.getDataTypeSize `TF_ERR};

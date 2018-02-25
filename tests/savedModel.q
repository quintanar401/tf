.t.testSavedModel:{
  if[not `half_plus_two in key `:.; '"load the model into test from tensorflow/cc/saved_model/testdata/half_plus_two"];
  p:.tf.loadSavedModel[`$":half_plus_two/00000123";enlist`serve;0;0;0];
  if[0=.tf.ops.getOpByName[p 1;`y];'"no operation y"];
 };

.t.testScope:{
  root:.tf.newScope[];
  sub1:.tf.subScope[root;`x];
  sub2:.tf.subScope[root;`x];
  sub1a:.tf.subScope[sub1;`y];
  sub2a:.tf.subScope[sub2;`y];
  {c:.tf.const[x,enlist[`opName]!(),`Const;1];if[not y~n:.tf.ops.name c[0]`oper;'"wrong oper name: ",string[y]," vs ",string n]}'[(root;sub1;sub2;sub1a;sub2a);`$("Const";"x/Const";"x_1/Const";"x/y/Const";"x_1/y/Const")];
  .tf.delScope root;
 };

.t.testControl:{
  s:.tf.newScope();
  zero:.tf.const[.tf.subScope[s;`zero];0i];
  one:.tf.const[.tf.subScope[s;`zero];1i];
  v:.tf.variable[s;`TF_INT32;`long$()];
  init:.tf.assign[s;v;zero];
  upd:.tf.assignAdd[s;v;one];
  r:.tf.readVar[s,enlist[`deps]!enlist upd[0]`oper;v;`TF_INT32];
  sess:.tf.newSession[s;0];
  .tf.session.run[sess;();();enlist init[0]`oper;0;0];
  if[not t~r:{z;r:.tf.session.run[x;();y;();0;0]; .tf.tensor.value r 0}[sess;r] each t:"i"$1+til 10;'"run result differ: ",.Q.s1 r];
 };
.t.testShape:{
  s:.tf.newScope[];
  input:.tf.placeholder[s;`TF_FLOAT];
  output:.tf.matMul[s,enlist[`transpose_b]!(),1b;.tf.const[s;10 20e;2 1];input];
  if[not 2 -1~r:.tf.graph.opGetShape[s`graph;output 0];'"wrong shape: ",.Q.s1 r];
 };

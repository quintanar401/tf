\l ../c/ops.q
\l ../tf.q
system "l ",.z.x 0;

.tf.init`:../c;

.tst.run:{
  tst:` sv/: `.t,/:1_key .t;
  {r:@[get x;::;::]; -1 string[x],": ",$[10=type r;"OK ",r;"FAILED - exception expected"]} each tst where tst like "*Err";
  {r:@[get x;::;::]; -1 string[x],": ",$[10=type r;"FAILED with ",r;"OK"]} each tst where not tst like "*Err";
 };

.tst.run[];

exit 0;
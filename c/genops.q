if[2<>count .z.x; -1 "Usage: q genops.q /path/to/ops.pbtxt /output/file"; exit 1];

-1 "Reading ",f:.z.x 0;
t:{x where not any x~\:/:(),/:"\r\t\n "} -4!"c"$read1 hsym `$f;
pos:0;
ops:enlist(::);

-1 "Parsing defs";
pval:{$["\""~x 0;value ssr[x;"\\'";"'"];x~"true";1b;x~"false";0b;((x[1]in .Q.n)&"-"=x 0)|x[0]in .Q.n;value x;("inf"~t pos)&x~enlist"-";[pos+::1;-0wf];`$x]};
pattr:{n:t pos; if[enlist[":"]~t pos+1; pos+::3; :x,enlist(n;pval t pos-1)]; pos+::1; x,enlist(n;pobj[])};
pobj:{if[not "{"~first t pos;'"expected { at ",string pos]; pos+::1; r:{(`$x[;0])!x[;1]}pattr/[{not enlist["}"]~t pos};enlist("";::)]; pos+:1; r};
pop:{if[not "op"~t pos;'"expected op at ",string pos]; pos+::1; ops,::enlist pobj[]};
pop/[{pos<count t};()];

-1 "Generating tables";
inp:`name`type`type_attr`number_attr`is_ref`type_list_attr!("";`;"";"";0b;"");
att:`name`type`default_value`allowed_values`has_minimum`minimum!("";"";::;();0b;0N);
tens:{if[1=count x;:(::)]; if[all (1_key x)in`i`f;:1_value x]; if[(u:`unknown_rank) in key x;:(`urank;x u)]; (x`dtype;x[`tensor_shape;`dim;`size];value[x]where key[x]like"*_val")};
attf:{if[`default_value in key x;x[`default_value]:{$[99=type x;tens x;x]}last value x`default_value];if[`allowed_values in key x;x[`allowed_values]:1_value x[`allowed_values]`list]; att,x};
addr:{y:``description _ y; if[count[get x]=n:get[x]?y; x upsert y];n};
nmap:`input_arg`output_arg`attr!({addr[`tinp;inp,x]};{addr[`tinp;inp,x]};{addr[`tatt;attf x]});
tinp:enlist inp;
tatt:enlist att;
tops:0#enlist `name`input_arg`output_arg`attr!(`;(),1;(),1;(),1);

proc:{
  {v:nmap[k:key[x]w]@'value[x]w:where(key x)in m:key nmap; `tops upsert (enlist[`name]!enlist[`$x`name]),(`long$m!()),v group k} each 1_ops;
  tinp::`name`itype xcol tinp; ; update `$name, `$type_attr, `$type_list_attr, `$number_attr from `tinp;
  tatt::`name`atype xcol tatt; update `$name, {x^((`$("list(type)";"list(int)";"list(shape)";"list(float)";"list(string)"))!`type_list`int_list`shape_list`float_list`string_list)x}`$atype from `tatt;
  tops::flip `name`input_arg`output_arg`att!value flip tops;
 };
proc[];

-1 "Saving result to ",f:.z.x 1;
sinp:{"  (`",string[x`name],";`",string[x`itype],";`",string[x`type_attr],";`",string[x`number_attr],";",string[x`is_ref],";`",string[x`type_list_attr],");"};
satt:{"  (`",string[x`name],";`",string[x`atype],";",({$[x~(::);"::";"0x",raze string -8!x]}x`default_value),";",({$[()~x;"()";11=type x;raze"`",/:string x;"(",(";"sv .Q.s1 each x),")"]}x`allowed_values),
  ";",string[x`has_minimum],";",.Q.s1[x`minimum],");"};
sops:{f:{$[0=count x;"0#0";" "sv string x]}; "  (`",string[x`name],";",(f -1+x`input_arg),";",(f -1+x`output_arg),";",(f -1+x`att),");"};
res:enlist[".tf.ops.inp:flip `name`itype`type_attr`number_attr`is_ref`type_list_attr!flip("],({x[i]:-1_x i:count[x]-1;x}sinp each 1_tinp),(" );";"");
res,:enlist[".tf.ops.att:flip `name`atype`default_value`allowed_values`has_minimum`minimum!flip("],({x[i]:-1_x i:count[x]-1;x}satt each 1_tatt),(" );";"");
res,:enlist[".tf.ops.ops:flip `name`input_arg`output_arg`att!flip("],({x[i]:-1_x i:count[x]-1;x}sops each 1_tops),(" );";"");
res,:("update {$[4=type x;-9!x;x]} each default_value from `.tf.ops.att;";"");

(hsym`$f) 0: res;

exit 0;

/ Q FFI for Tensorflow
\l ../../q2c/q2b.q
\l ../../q2c/b2c.q
.b2c.it:`c.j; .b2c.is32:0b; .b2c.P:"J"; // ensure 64 bit
\l ../../q2c/std.q

.b2c.include,:enlist "<tensorflow/c/c_api.h>"

.b2c.defExtType[`c.TF_DataType;()]; / enum
.b2c.defExtType[`c.TF_Code;()]; / enum
.b2c.defExtType[`c.TF_Status;()]; / struct
.b2c.defExtType[`c.TF_Tensor;()]; / struct
.b2c.defExtType[`c.TF_SessionOptions;()]; / struct
.b2c.defExtType[`c.TF_Graph;()]; / struct
.b2c.defExtType[`c.TF_OperationDescription;()]; / struct
.b2c.defExtType[`c.TF_Operation;()]; / struct
.b2c.defExtType[`c.TF_Function;()]; / struct
.b2c.defExtType[`c.TF_FunctionOptions;()]; / struct
.b2c.defExtType[`c.TF_AttrType;()]; / enum
.b2c.defExtType[`c.TF_ImportGraphDefOptions;()]; / struct
.b2c.defExtType[`c.TF_ImportGraphDefResults;()]; / struct
.b2c.defExtType[`c.TF_Session;()]; / struct
.b2c.defExtType[`c.TF_DeviceList;()]; / struct
.b2c.defExtType[`c.TF_Library;()]; / struct
.b2c.defExtType[`c.TF_ApiDefMap;()]; / struct
.b2c.defCCast each ((`c.TF_DataType`c.i);(`c.i`c.TF_DataType);(`c.TF_Code`c.i);(`c.i`c.TF_Code);(`c.i`c.TF_AttrType);(`c.TF_AttrType`c.i));
{.b2c.defCompCast[`K`c.j,x]} each `c.TF_Status_p`c.TF_Tensor_p`c.TF_SessionOptions_p`c.TF_Graph_p`c.TF_OperationDescription_p`c.TF_Operation_p,
  `c.TF_Function_p`c.TF_FunctionOptions_p`c.TF_ImportGraphDefOptions_p`c.TF_ImportGraphDefResults_p`c.TF_Session_p`c.TF_DeviceList_p`c.TF_Library_p`c.TF_ApiDefMap_p;
{.b2c.defCompCast[`K`c.i,x]} each `c.TF_DataType`c.TF_Code`c.TF_AttrType;

.b2c.defType[`c.data_deallocator_func;`f`c.void`c.void_p`c.size_t];
.b2c.defExtStruct[`c.TF_Buffer;`data`length`data_deallocator!`c.cvoid_p`c.size_t`c.data_deallocator_func_p;();()];
.b2c.defExtStruct[`c.TF_Input;`oper`index!`c.TF_Operation_p`c.i;`oper`index!`c.TF_Operation_p`c.i;`oper`index!`c.j`c.i];
.b2c.defExtStruct[`c.TF_Output;`oper`index!`c.TF_Operation_p`c.i;`oper`index!`c.TF_Operation_p`c.i;`oper`index!`c.j`c.i];
.b2c.defExtStruct[`c.TF_AttrMetadata;`is_list`list_size`type`total_size!`c.c`c.j`c.TF_AttrType`c.j;`is_list`list_size`type`total_size!`c.c`c.j`c.TF_AttrType`c.j;`is_list`list_size`type`total_size!`c.c`c.j`c.i`c.j];
.b2c.defExtStruct[`c.TF_WhileParams;`ninputs`cond_graph`cond_inputs`cond_output`body_graph`body_inputs`body_outputs`name!`c.i`c.TF_Graph_p`c.TF_Output_p`c.TF_Output`c.TF_Graph_p`c.TF_Output_p`c.TF_Output_p`c.S;();()];
.b2c.defCompCast[`K`c.j`c.TF_Buffer_p];
.tf.getBuffer:{c.TF_Buffer_p.b:`c.TF_Buffer_p$x; res:(l:C.toK `c.j$c.b`length)#0x00; c.C.res:`c.C$res; c.C.src:`c.C$`c.void_p$c.b`data; do[l;c.res[c.do1]:c.src c.do1]; res};
.b2c.defPCast each `c.TF_Tensor_p`c.TF_Operation_p`c.TF_Output_p`c.TF_Operation_p_p`c.S_p`c.TF_Function_p`c.cchar_p`c.long_p`c.cchar_p_p;
.b2c.defCompCast[`K`c.j`c.TF_WhileParams_p];
`.q2b.types upsert ((`c.ccvoid_p_p;"const void* const*";();1b);(`c.cclong_p_p;"const long int* const*";();1b);(`c.ccTF_Operation_p_p;"const TF_Operation* const*";();1b));
.b2c.defCCast each (`c.J`c.long_p;`c.cchar_p`c.C;`c.void_p`c.ccvoid_p_p;`c.void_p`c.cclong_p_p;`c.long`c.j;`c.e`c.f;`c.void_p`c.ccTF_Operation_p_p);
.b2c.defCompCast[`K`c.J`c.long_p];

.tf.encodeOut:{
  r:(count[x]*C.toK `c.j$count`c.TF_Output)#0x00; c.TF_Output_p.o:`c.TF_Output_p$`c.void_p$`c.C$r;
  do[count x; v:x C.toK c.do1; c.o[c.do1;`oper]:`c.TF_Operation_p$`c.j$v`oper; c.o[c.do1;`index]:`c.i$v`index];
  :r;
 };

.b2c.defExtFn[`tf;`C.TF_Version;(`c.cchar_p`c.S;enlist(`chk0;`c.void_p`c.j));`c.void;()]; / const char* TF_Version();
.b2c.defExtFn[`tf;`C.TF_DataTypeSize;enlist`c.size_t`c.j;`c.TF_DataType;()]; / size_t TF_DataTypeSize(TF_DataType dt)
.b2c.defExtFn[`tf;`C.TF_NewStatus;enlist`c.TF_Status_p`c.j;`c.void;()]; / TF_Status* TF_NewStatus();
.b2c.defExtFn[`tf;`C.TF_DeleteStatus;`c.void;`c.TF_Status_p;()]; / void TF_DeleteStatus(TF_Status*);
.b2c.defExtFn[`tf;`C.TF_SetStatus;`c.void;`c.TF_Status_p`c.TF_Code`c.S;()]; / void TF_SetStatus(TF_Status* s, TF_Code code, const char* msg);
.b2c.defExtFn[`tf;`C.TF_GetCode;enlist`c.TF_Code`c.i;`c.TF_Status_p;()]; / TF_Code TF_GetCode(const TF_Status* s);
.b2c.defExtFn[`tf;`C.TF_Message;(`c.cchar_p`c.S;enlist(`chk0;`c.void_p`c.j));`c.TF_Status_p;()];  / const char* TF_Message(const TF_Status* s);

.b2c.defExtFn[`tf;`C.TF_NewBufferFromString;enlist`c.TF_Buffer_p`c.j;(`c.C`c.cvoid_p;(`c.size_t;enlist(`length;1)));()]; / TF_Buffer* TF_NewBufferFromString(const void* proto,size_t proto_len);
.b2c.defExtFn[`tf;`C.TF_NewBuffer;enlist`c.TF_Buffer_p`c.j;`c.void;()]; / TF_Buffer* TF_NewBuffer();
.b2c.defExtFn[`tf;`C.TF_DeleteBuffer;`c.void;`c.TF_Buffer_p;()]; / void TF_DeleteBuffer(TF_Buffer*);
/ TF_Buffer TF_GetBuffer(TF_Buffer* buffer); ???

.b2c.defType[`c.deallocator_func;`f`c.void`c.void_p`c.size_t`c.void_p];
.tf.deallocator:{[d;s;a] "c)`c.void`c.void_p`c.size_t`c.void_p"; c.k.v:`c.k$a; c.v[`r]-:1i;} / decrease the obj's ref count
.tf.getQPtr:{[data]"c)`c.void_p`K"; $[(t:type data) in 4 10h;`c.void_p$`c.C$data;t=5;`c.void_p$`c.H$data;t=6;`c.void_p$`c.I$data;t=7;`c.void_p$`c.J$data;t=9;`c.void_p$`c.F$data;`c.void_p$`c.E$data]};
/ TF_Tensor* TF_NewTensor(TF_DataType, const int64_t* dims, int num_dims, void* data, size_t len, void (*deallocator)(void* data, size_t len, void* arg),void* deallocator_arg);
.b2c.defExtFn[`tf;`C.TF_NewTensor;`c.TF_Tensor_p;`c.TF_DataType`c.long_p`c.i`c.void_p`c.size_t`c.deallocator_func_p`c.void_p;(enlist`nogen)!(),1b];
.tf.TF_NewTensor:{[dt;dims;data]
  if[null sz:(4 5 6 7 8 9 10h!1 2 4 8 4 8 1)t:type data; '"TF_NewTensor: unsupported data"];
  c.void_p.dt:.tf.getQPtr data; c.k.d: `c.k$data;
  r: C.toK `c.j$C.TF_NewTensor[`c.TF_DataType$`c.i$dt;`c.long_p$dims;`c.i$"i"$count dims;c.dt;`c.size_t$`c.j$sz*count data;(&).tf.deallocator;`c.void_p$c.d];
  if[r<>0; c.d[`r]+:1i];
  : r;
 };
.b2c.defExtFn[`tf;`C.TF_AllocateTensor;enlist`c.TF_Tensor_p`c.j;(`c.TF_DataType;`c.long_p;(`c.i;enlist(`length;2));`c.size_t);()];  / TF_Tensor* TF_AllocateTensor(TF_DataType, const int64_t* dims, int num_dims, size_t len);
.b2c.defExtFn[`tf;`C.TF_TensorMaybeMove;enlist`c.TF_Tensor_p`c.j;`c.TF_Tensor_p;()]; / TF_Tensor* TF_TensorMaybeMove(TF_Tensor* tensor)
.b2c.defExtFn[`tf;`C.TF_DeleteTensor;`c.void;`c.TF_Tensor_p;()]; / void TF_DeleteTensor(TF_Tensor*)
.b2c.defExtFn[`tf;`C.TF_TensorType;enlist`c.TF_DataType`c.i;`c.TF_Tensor_p;()]; / TF_DataType TF_TensorType(const TF_Tensor*)
.b2c.defExtFn[`tf;`C.TF_NumDims;`c.i;`c.TF_Tensor_p;()]; / int TF_NumDims(const TF_Tensor*)
.b2c.defExtFn[`tf;`C.TF_Dim;`c.j;`c.TF_Tensor_p`c.i;()]; / int64_t TF_Dim(const TF_Tensor* tensor, int dim_index)
.b2c.defExtFn[`tf;`C.TF_TensorByteSize;enlist`c.size_t`c.j;`c.TF_Tensor_p;()]; / size_t TF_TensorByteSize(const TF_Tensor*)
.b2c.defExtFn[`tf;`C.TF_TensorData;enlist`c.void_p`c.j;`c.TF_Tensor_p;()]; / void* TF_TensorData(const TF_Tensor*)
.tf.writeToTensor:{[ptr;data]
  c.C.t:`c.C$`c.void_p$`c.j$ptr; c.C.d:`c.C$.tf.getQPtr data;
  do[(4 5 6 7 8 9 10h!1 2 4 8 4 8 1)[type data]*count data; c.t[c.do1]: c.d c.do1];
 };
 .tf.readFromTensor:{[ptr;data]
   c.C.t:`c.C$`c.void_p$`c.j$ptr; c.C.d:`c.C$.tf.getQPtr data;
   do[(4 5 6 7 8 9 10h!1 2 4 8 4 8 1)[type data]*count data; c.d[c.do1]: c.t c.do1];
   : data;
  };

.b2c.defExtFn[`tf;`C.TF_StringEncode;enlist`c.size_t`c.j;(`c.C;(`c.size_t;enlist(`length;1));enlist`c.j`c.C;enlist`c.j`c.size_t;`c.TF_Status_p);()]; / size_t TF_StringEncode(const char* src, size_t src_len, char* dst, size_t dst_len, TF_Status* status);
.b2c.defExtFn[`tf;`C.TF_StringDecode;`c.size_t;`c.C`c.size_t`c.cchar_p_p`c.size_t_p`c.TF_Status_p;(enlist`nogen)!(),1b]; / size_t TF_StringDecode(const char* src, size_t src_len,const char** dst, size_t* dst_len,TF_Status* status);
.tf.TF_StringDecode:{[src;sz;st]
  c.size_t.r:C.TF_StringDecode[`c.C$`c.j$src;`c.size_t$sz;(&)c.cchar_p.dst;(&)c.size_t.l;`c.TF_Status_p$`c.j$st];
  if[0=`c.j$c.r;:""];
  : C.toK[`c.C$c.dst;`c.j$c.l];
 };
.b2c.defExtFn[`tf;`C.TF_StringEncodedSize;enlist`c.size_t`c.j;`c.size_t;()]; / size_t TF_StringEncodedSize(size_t len)

.b2c.defExtFn[`tf;`C.TF_NewSessionOptions;enlist`c.TF_SessionOptions_p`c.j;`c.void;()]; / TF_SessionOptions* TF_NewSessionOptions()
.b2c.defExtFn[`tf;`C.TF_SetTarget;`c.void;`c.TF_SessionOptions_p`c.S;()]; / void TF_SetTarget(TF_SessionOptions* options,const char* target);
.b2c.defExtFn[`tf;`C.TF_SetConfig;`c.void;(`c.TF_SessionOptions_p;`c.C;(`c.size_t;enlist(`length;2));`c.TF_Status_p);()];  / void TF_SetConfig(TF_SessionOptions* options,const void* proto, size_t proto_len,TF_Status* status)
.b2c.defExtFn[`tf;`C.TF_DeleteSessionOptions;`c.void;`c.TF_SessionOptions_p;()]; / void TF_DeleteSessionOptions(TF_SessionOptions*)

.b2c.defExtFn[`tf;`C.TF_NewGraph;enlist`c.TF_Graph_p`c.j;`c.void;()]; / TF_Graph* TF_NewGraph()
.b2c.defExtFn[`tf;`C.TF_DeleteGraph;`c.void;`c.TF_Graph_p;()]; / void TF_DeleteGraph(TF_Graph*)
.b2c.defExtFn[`tf;`C.TF_GraphSetTensorShape;`c.void;(`c.TF_Graph_p;`c.TF_Output;`c.long_p;(`c.i;enlist(`length;3));`c.TF_Status_p);()]; / void TF_GraphSetTensorShape(TF_Graph* graph,TF_Output output,const int64_t* dims,const int num_dims,TF_Status* status)
.b2c.defExtFn[`tf;`C.TF_GraphGetTensorNumDims;`c.i;`c.TF_Graph_p`c.TF_Output`c.TF_Status_p;()]; / int TF_GraphGetTensorNumDims(TF_Graph* graph,TF_Output output,TF_Status* status)
.b2c.defExtFn[`tf;`C.TF_GraphGetTensorShape;`c.void;(`c.TF_Graph_p;`c.TF_Output;`c.long_p;(`c.i;enlist(`length;3));`c.TF_Status_p);()]; / void TF_GraphGetTensorShape(TF_Graph* graph,TF_Output output,int64_t* dims, int num_dims,TF_Status* status)

.b2c.defExtFn[`tf;`C.TF_NewOperation;enlist`c.TF_OperationDescription_p`c.j;`c.TF_Graph_p`c.S`c.S;()]; / TF_OperationDescription* TF_NewOperation(TF_Graph* graph, const char* op_type, const char* oper_name)
.b2c.defExtFn[`tf;`C.TF_SetDevice;`c.void;`c.TF_OperationDescription_p`c.S;()]; / void TF_SetDevice(TF_OperationDescription* desc,const char* device)
.b2c.defExtFn[`tf;`C.TF_AddInput;`c.void;`c.TF_OperationDescription_p`c.TF_Output;()]; / void TF_AddInput(TF_OperationDescription* desc,TF_Output input)
.b2c.defExtFn[`tf;`C.TF_AddInputList;`c.void;`c.TF_OperationDescription_p`c.TF_Output_p`c.i;(enlist`nogen)!(),1b]; / void TF_AddInputList(TF_OperationDescription* desc,const TF_Output* inputs,int num_inputs)
.tf.TF_AddInputList:{[op;out] if[not 98=type out;'"TF_AddInputList: type"]; v:.tf.encodeOut out; C.TF_AddInputList[`c.TF_OperationDescription_p$op;`c.TF_Output_p$`c.void_p$`c.C$v;`c.i$"i"$count out];};
.b2c.defExtFn[`tf;`C.TF_AddControlInput;`c.void;`c.TF_OperationDescription_p`c.TF_Operation_p;()]; / void TF_AddControlInput(TF_OperationDescription* desc,TF_Operation* input)
/ deprecated:  void TF_ColocateWith(TF_OperationDescription* desc, TF_Operation* op)
.b2c.defExtFn[`tf;`C.TF_SetAttrString;`c.void;(`c.TF_OperationDescription_p;`c.S;enlist`c.C`c.void_p;(`c.size_t;enlist(`length;3)));()]; / void TF_SetAttrString(TF_OperationDescription* desc,const char* attr_name,const void* value, size_t length)
.b2c.defExtFn[`tf;`C.TF_SetAttrStringList;`c.void;`c.TF_OperationDescription_p`c.S`c.ccvoid_p_p`c.size_t_p`c.i;(enlist`nogen)!(),1b]; / void TF_SetAttrStringList(TF_OperationDescription* desc,const char* attr_name,const void* const* values,const size_t* lengths,int num_values)
.tf.TF_SetAttrStringList:{[op;name;str]
  if[not all(type each str)in 4 10h;'"TF_SetAttrStringList: type"];
  a:count[str]#0; l:count[str]#0; c.J.a: `c.J$a; c.J.l:`c.J$l;
  do[count str;c.a[c.do1]:`c.j$`c.C$s:str C.toK c.do1; c.l[c.do1]:`c.j$count s];
  C.TF_SetAttrStringList[`c.TF_OperationDescription_p$op;`c.S$name;`c.ccvoid_p_p$`c.void_p$c.a;`c.size_t_p$`c.void_p$c.l;`c.i$"i"$count str];
 };
.b2c.defExtFn[`tf;`C.TF_SetAttrInt;`c.void;`c.TF_OperationDescription_p`c.S`c.j;()]; / void TF_SetAttrInt(TF_OperationDescription* desc,const char* attr_name, int64_t value)
.b2c.defExtFn[`tf;`C.TF_SetAttrIntList;`c.void;(`c.TF_OperationDescription_p;`c.S;`c.long_p;(`c.i;enlist(`length;3)));()]; / TF_SetAttrIntList(TF_OperationDescription* desc,const char* attr_name,const int64_t* values,int num_values)
.b2c.defExtFn[`tf;`C.TF_SetAttrFloat;`c.void;`c.TF_OperationDescription_p`c.S`c.f;()]; / TF_SetAttrFloat(TF_OperationDescription* desc,const char* attr_name, float value)
.b2c.defExtFn[`tf;`C.TF_SetAttrFloatList;`c.void;(`c.TF_OperationDescription_p;`c.S;`c.E;(`c.i;enlist(`length;3)));()]; / TF_SetAttrFloatList(TF_OperationDescription* desc,const char* attr_name,const float* values,int num_values)
.b2c.defExtFn[`tf;`C.TF_SetAttrBool;`c.void;(`c.TF_OperationDescription_p;`c.S;enlist`c.c`c.uchar);()]; / TF_SetAttrBool(TF_OperationDescription* desc,const char* attr_name,unsigned char value)
.b2c.defExtFn[`tf;`C.TF_SetAttrBoolList;`c.void;(`c.TF_OperationDescription_p;`c.S;enlist`c.C`c.uchar_p;(`c.i;enlist(`length;3)));()]; / void TF_SetAttrBoolList(TF_OperationDescription* desc,const char* attr_name,const unsigned char* values,int num_values)
.b2c.defExtFn[`tf;`C.TF_SetAttrType;`c.void;`c.TF_OperationDescription_p`c.S`c.TF_DataType;()]; / void TF_SetAttrType(TF_OperationDescription* desc,const char* attr_name,TF_DataType value)
.b2c.defExtFn[`tf;`C.TF_SetAttrTypeList;`c.void;(`c.TF_OperationDescription_p;`c.S;enlist`c.I`c.void_p`c.TF_DataType_p;(`c.i;enlist(`length;3)));()]; / void TF_SetAttrTypeList(TF_OperationDescription* desc,const char* attr_name,const TF_DataType* values,int num_values)
/ .b2c.defExtFn[`tf;`C.TF_SetAttrFuncName;`c.void;(`c.TF_OperationDescription_p;`c.S;`c.S;(`c.i;enlist(`length;3)));()]; / void TF_SetAttrFuncName(TF_OperationDescription* desc,const char* attr_name,const char* value, size_t length)
.b2c.defExtFn[`tf;`C.TF_SetAttrShape;`c.void;(`c.TF_OperationDescription_p;`c.S;`c.long_p;(`c.i;enlist(`length;3)));()]; / void TF_SetAttrShape(TF_OperationDescription* desc,const char* attr_name,const int64_t* dims, int num_dims)
/ void TF_SetAttrShapeList(TF_OperationDescription* desc,const char* attr_name,const int64_t* const* dims,const int* num_dims,int num_shapes)
.b2c.defExtFn[`tf;`C.TF_SetAttrShapeList;`c.void;`c.TF_OperationDescription_p`c.S`c.cclong_p_p`c.I`c.i;(enlist`nogen)!(),1b];
.tf.TF_SetAttrShapeList:{[op;name;dims]
  if[not all 7=type each dims;'"TF_SetAttrShapeList: type"];
  a:count[dims]#0; l:count[dims]#0; c.J.a: `c.J$a; c.I.l:`c.I$l;
  do[count dims;c.a[c.do1]:`c.j$`c.J$s:dims C.toK c.do1; c.l[c.do1]:`c.i$"i"$count s];
  C.TF_SetAttrShapeList[`c.TF_OperationDescription_p$op;`c.S$name;`c.cclong_p_p$`c.void_p$c.a;c.l;`c.i$"i"$count dims];
 };
.b2c.defExtFn[`tf;`C.TF_SetAttrTensorShapeProto;`c.void;(`c.TF_OperationDescription_p;`c.S;enlist`c.C`c.void_p;(`c.i;enlist(`length;3));`c.TF_Status_p);()];  / void TF_SetAttrTensorShapeProto(TF_OperationDescription* desc, const char* attr_name, const void* proto,size_t proto_len, TF_Status* status)
/ void TF_SetAttrTensorShapeProtoList(    TF_OperationDescription* desc, const char* attr_name,    const void* const* protos, const size_t* proto_lens, int num_shapes,TF_Status* status)
.b2c.defExtFn[`tf;`C.TF_SetAttrTensorShapeProtoList;`c.void;`c.TF_OperationDescription_p`c.S`c.ccvoid_p_p`c.size_t_p`c.i`c.TF_Status_p;(enlist`nogen)!(),1b];
.tf.TF_SetAttrTensorShapeProtoList:{[op;name;proto;st]
  if[not all(type each proto)in 4 10h;'"TF_SetAttrTensorShapeProtoList: type"];
  a:count[proto]#0; l:count[proto]#0; c.J.a: `c.J$a; c.J.l:`c.J$l;
  do[count proto;c.a[c.do1]:`c.j$`c.C$s:proto C.toK c.do1; c.l[c.do1]:`c.j$count s];
  C.TF_SetAttrTensorShapeProtoList[`c.TF_OperationDescription_p$op;`c.S$name;`c.ccvoid_p_p$`c.void_p$c.a;`c.size_t_p$`c.void_p$c.l;`c.i$"i"$count proto;`c.TF_Status_p$st];
 };
.b2c.defExtFn[`tf;`C.TF_SetAttrTensor;`c.void;`c.TF_OperationDescription_p`c.S`c.TF_Tensor_p`c.TF_Status_p;()]; / void TF_SetAttrTensor(TF_OperationDescription* desc,const char* attr_name,TF_Tensor* value,TF_Status* status)
.b2c.defExtFn[`tf;`C.TF_SetAttrTensorList;`c.void;(`c.TF_OperationDescription_p;`c.S;enlist`c.J`c.void_p`c.TF_Tensor_p_p;(`c.i;enlist(`length;3));`c.TF_Status_p);()]; / void TF_SetAttrTensorList(TF_OperationDescription* desc,const char* attr_name,TF_Tensor* const* values,int num_values,TF_Status* status)
.b2c.defExtFn[`tf;`C.TF_SetAttrValueProto;`c.void;(`c.TF_OperationDescription_p;`c.S;enlist`c.C`c.void_p;(`c.size_t;enlist(`length;3));`c.TF_Status_p);()]; / void TF_SetAttrValueProto(TF_OperationDescription* desc,const char* attr_name,const void* proto,size_t proto_len,TF_Status* status)

.b2c.defExtFn[`tf;`C.TF_FinishOperation;enlist`c.TF_Operation_p`c.j;`c.TF_OperationDescription_p`c.TF_Status_p;()]; / TF_Operation* TF_FinishOperation(TF_OperationDescription* desc, TF_Status* status)
.b2c.defExtFn[`tf;`C.TF_OperationName;(`c.cchar_p`c.S;enlist(`chk0;`c.j));`c.TF_Operation_p;()]; / const char* TF_OperationName(TF_Operation* oper)
.b2c.defExtFn[`tf;`C.TF_OperationOpType;(`c.cchar_p`c.S;enlist(`chk0;`c.j));`c.TF_Operation_p;()]; / extern const char* TF_OperationOpType(TF_Operation* oper)
.b2c.defExtFn[`tf;`C.TF_OperationDevice;(`c.cchar_p`c.S;enlist(`chk0;`c.j));`c.TF_Operation_p;()]; / const char* TF_OperationDevice(TF_Operation* oper)
.b2c.defExtFn[`tf;`C.TF_OperationNumOutputs;`c.i;`c.TF_Operation_p;()]; / int TF_OperationNumOutputs(TF_Operation* oper)
.b2c.defExtFn[`tf;`C.TF_OperationOutputType;enlist`c.TF_DataType`c.i;`c.TF_Output;()]; / TF_DataType TF_OperationOutputType(TF_Output oper_out)
.b2c.defExtFn[`tf;`C.TF_OperationOutputListLength;`c.i;`c.TF_Operation_p`c.S`c.TF_Status_p;()]; / int TF_OperationOutputListLength(TF_Operation* oper,const char* arg_name,TF_Status* status)
.b2c.defExtFn[`tf;`C.TF_OperationNumInputs;`c.i;`c.TF_Operation_p;()]; / int TF_OperationNumInputs(TF_Operation* oper)
.b2c.defExtFn[`tf;`C.TF_OperationInputType;enlist`c.TF_DataType`c.i;`c.TF_Input;()]; / TF_DataType TF_OperationInputType(TF_Input oper_in)
.b2c.defExtFn[`tf;`C.TF_OperationInputListLength;`c.i;`c.TF_Operation_p`c.S`c.TF_Status_p;()]; / int TF_OperationInputListLength(TF_Operation* oper,const char* arg_name,TF_Status* status)
.b2c.defExtFn[`tf;`C.TF_OperationInput;`c.TF_Output;`c.TF_Input;()]; / TF_Output TF_OperationInput(TF_Input oper_in)
.b2c.defExtFn[`tf;`C.TF_OperationOutputNumConsumers;`c.i;`c.TF_Output;()]; / int TF_OperationOutputNumConsumers(TF_Output oper_out)
/ int TF_OperationOutputConsumers(TF_Output oper_out,TF_Input* consumers,int max_consumers)
.b2c.defExtFn[`tf;`C.TF_OperationOutputConsumers;`c.i;`c.TF_Output`c.TF_Input_p`c.i;(enlist`nogen)!(),1b];
.tf.TF_OperationOutputConsumers:{[out]
  if[0i>=c.i.n:C.TF_OperationOutputNumConsumers `c.TF_Output$out;C.toK c.n];
  v:(C.toK (`c.j$count`c.TF_Input)*c.n)#0x00;
  if[0>=r:C.toK C.TF_OperationOutputConsumers[`c.TF_Output$out;`c.TF_Input_p$`c.void_p$`c.C$v;c.n];:()];
  : r#flip`oper`index!("ji ";8 4 4)1: v;
 };
.b2c.defExtFn[`tf;`C.TF_OperationNumControlInputs;`c.i;`c.TF_Operation_p;()]; / int TF_OperationNumControlInputs(TF_Operation* oper)
.b2c.defExtFn[`tf;`C.TF_OperationGetControlInputs;`c.i;(`c.TF_Operation_p;enlist`c.J`c.void_p`c.TF_Operation_p_p;(`c.i;enlist(`length;2)));()]; / int TF_OperationGetControlInputs(TF_Operation* oper, TF_Operation** control_inputs, int max_control_inputs)
.b2c.defExtFn[`tf;`C.TF_OperationNumControlOutputs;`c.i;`c.TF_Operation_p;()]; / int TF_OperationNumControlOutputs(TF_Operation* oper)
.b2c.defExtFn[`tf;`C.TF_OperationGetControlOutputs;`c.i;(`c.TF_Operation_p;enlist`c.J`c.void_p`c.TF_Operation_p_p;(`c.i;enlist(`length;2)));()]; / int TF_OperationGetControlOutputs(TF_Operation* oper, TF_Operation** control_outputs,int max_control_outputs)

.b2c.defExtFn[`tf;`C.TF_OperationGetAttrMetadata;`c.TF_AttrMetadata;`c.TF_Operation_p`c.S`c.TF_Status_p;()]; / TF_AttrMetadata TF_OperationGetAttrMetadata(TF_Operation* oper, const char* attr_name, TF_Status* status)
.b2c.defExtFn[`tf;`C.TF_OperationGetAttrString;`c.void;(`c.TF_Operation_p;`c.S;enlist`c.C`c.void_p;(`c.size_t;enlist(`length;3));`c.TF_Status_p);()]; / void TF_OperationGetAttrString(TF_Operation* oper,const char* attr_name,void* value,size_t max_length,TF_Status* status)
/ void TF_OperationGetAttrStringList(TF_Operation* oper, const char* attr_name, void** values, size_t* lengths,int max_values, void* storage, size_t storage_size, TF_Status* status)
.b2c.defExtFn[`tf;`C.TF_OperationGetAttrStringList;`c.void;(`c.TF_Operation_p;`c.S;enlist`c.J`c.void_p`c.void_p_p;enlist`c.J`c.void_p`c.size_t_p;(`c.size_t;enlist(`length;3));enlist`c.C`c.void_p;(`c.size_t;enlist(`length;6));`c.TF_Status_p);()];
.b2c.defExtFn[`tf;`C.TF_OperationGetAttrInt;`c.void;(`c.TF_Operation_p;`c.S;(`c.long`c.j;`out);`c.TF_Status_p);()]; / void TF_OperationGetAttrInt(TF_Operation* oper,const char* attr_name,int64_t* value,TF_Status* status)
.b2c.defExtFn[`tf;`C.TF_OperationGetAttrIntList;`c.void;(`c.TF_Operation_p;`c.S;`c.long_p;(`c.i;enlist(`length;3));`c.TF_Status_p);()]; / void TF_OperationGetAttrIntList(TF_Operation* oper,const char* attr_name,int64_t* values,int max_values,TF_Status* status)
.b2c.defExtFn[`tf;`C.TF_OperationGetAttrFloat;`c.void;(`c.TF_Operation_p;`c.S;(`c.e`c.f;`out);`c.TF_Status_p);()]; / void TF_OperationGetAttrFloat(TF_Operation* oper,const char* attr_name,float* value,TF_Status* status)
.b2c.defExtFn[`tf;`C.TF_OperationGetAttrFloatList;`c.void;(`c.TF_Operation_p;`c.S;`c.E;(`c.i;enlist(`length;3));`c.TF_Status_p);()]; / void TF_OperationGetAttrFloatList(TF_Operation* oper,const char* attr_name,float* values,int max_values,TF_Status* status)
.b2c.defExtFn[`tf;`C.TF_OperationGetAttrBool;`c.void;(`c.TF_Operation_p;`c.S;`c.c`out;`c.TF_Status_p);()]; / void TF_OperationGetAttrBool(TF_Operation* oper,const char* attr_name,unsigned char* value,TF_Status* status)
.b2c.defExtFn[`tf;`C.TF_OperationGetAttrBoolList;`c.void;(`c.TF_Operation_p;`c.S;`c.C;(`c.i;enlist(`length;3));`c.TF_Status_p);()]; / void TF_OperationGetAttrBoolList(TF_Operation* oper,const char* attr_name,unsigned char* values,int max_values,TF_Status* status)
.b2c.defExtFn[`tf;`C.TF_OperationGetAttrType;`c.void;(`c.TF_Operation_p;`c.S;(`c.TF_DataType`c.i;`out);`c.TF_Status_p);()]; / void TF_OperationGetAttrType(TF_Operation* oper,const char* attr_name,TF_DataType* value,TF_Status* status)
.b2c.defExtFn[`tf;`C.TF_OperationGetAttrTypeList;`c.void;(`c.TF_Operation_p;`c.S;enlist`c.I`c.void_p`c.TF_DataType_p;(`c.i;enlist(`length;3));`c.TF_Status_p);()]; / void TF_OperationGetAttrTypeList(TF_Operation* oper,const char* attr_name,TF_DataType* values,int max_values,TF_Status* status)
.b2c.defExtFn[`tf;`C.TF_OperationGetAttrShape;`c.void;(`c.TF_Operation_p;`c.S;`c.long_p;(`c.i;enlist(`length;3));`c.TF_Status_p);()]; / void TF_OperationGetAttrShape(TF_Operation* oper,const char* attr_name,int64_t* value,int num_dims,TF_Status* status)
/ void TF_OperationGetAttrShapeList(    TF_Operation* oper, const char* attr_name, int64_t** dims, int* num_dims,int num_shapes, int64_t* storage, int storage_size, TF_Status* status)
.b2c.defExtFn[`tf;`C.TF_OperationGetAttrShapeList;`c.void;(`c.TF_Operation_p;`c.S;enlist`c.J`c.void_p`c.long_p_p;`c.I;(`c.i;enlist(`length;3));`c.long_p;(`c.i;enlist(`length;6));`c.TF_Status_p);()];
.b2c.defExtFn[`tf;`C.TF_OperationGetAttrTensorShapeProto;`c.void;(`c.TF_Operation_p;`c.S;`c.TF_Buffer_p;`c.TF_Status_p);()]; / void TF_OperationGetAttrTensorShapeProto(TF_Operation* oper, const char* attr_name, TF_Buffer* value,TF_Status* status)
/ NOT IMPL ATM  void TF_OperationGetAttrTensorShapeProtoList(TF_Operation* oper, const char* attr_name, TF_Buffer** values,int max_values, TF_Status* status)
.b2c.defExtFn[`tf;`C.TF_OperationGetAttrTensor;`c.void;(`c.TF_Operation_p;`c.S;(`c.TF_Tensor_p`c.j;`out);`c.TF_Status_p);()]; / void TF_OperationGetAttrTensor(TF_Operation* oper,const char* attr_name,TF_Tensor** value,TF_Status* status)
/ void TF_OperationGetAttrTensorList(TF_Operation* oper,const char* attr_name,TF_Tensor** values,int max_values,TF_Status* status)
.b2c.defExtFn[`tf;`C.TF_OperationGetAttrTensorList;`c.void;(`c.TF_Operation_p;`c.S;enlist`c.J`c.void_p`c.TF_Tensor_p_p;`c.i;`c.TF_Status_p);()];
/ NOT IMPL ATM void TF_OperationGetAttrValueProto(TF_Operation* oper, const char* attr_name, TF_Buffer* output_attr_value,TF_Status* status)

.b2c.defExtFn[`tf;`C.TF_GraphOperationByName;enlist`c.TF_Operation_p`c.j;`c.TF_Graph_p`c.S;()]; / TF_Operation* TF_GraphOperationByName(TF_Graph* graph, const char* oper_name)
.b2c.defExtFn[`tf;`C.TF_GraphNextOperation;enlist`c.TF_Operation_p`c.j;(`c.TF_Graph_p;enlist `c.J`c.void_p`c.size_t_p);()]; / TF_Operation* TF_GraphNextOperation(TF_Graph* graph,size_t* pos)
.b2c.defExtFn[`tf;`C.TF_GraphToGraphDef;`c.void;`c.TF_Graph_p`c.TF_Buffer_p`c.TF_Status_p;()]; / void TF_GraphToGraphDef(TF_Graph* graph,TF_Buffer* output_graph_def,TF_Status* status)
.b2c.defExtFn[`tf;`C.TF_GraphGetOpDef;`c.void;`c.TF_Graph_p`c.S`c.TF_Buffer_p`c.TF_Status_p;()]; / void TF_GraphGetOpDef(TF_Graph* graph,const char* op_name,TF_Buffer* output_op_def,TF_Status* status)
.b2c.defExtFn[`tf;`C.TF_GraphVersions;`c.void;`c.TF_Graph_p`c.TF_Buffer_p`c.TF_Status_p;()]; / void TF_GraphVersions(TF_Graph* graph,TF_Buffer* output_version_def,TF_Status* status)
.b2c.defExtFn[`tf;`C.TF_NewImportGraphDefOptions;enlist`c.TF_ImportGraphDefOptions_p`c.j;`c.void;()]; / TF_ImportGraphDefOptions* TF_NewImportGraphDefOptions()
.b2c.defExtFn[`tf;`C.TF_DeleteImportGraphDefOptions;`c.void;`c.TF_ImportGraphDefOptions_p;()]; / void TF_DeleteImportGraphDefOptions(TF_ImportGraphDefOptions* opts)
.b2c.defExtFn[`tf;`C.TF_ImportGraphDefOptionsSetPrefix;`c.void;`c.TF_ImportGraphDefOptions_p`c.S;()]; / void TF_ImportGraphDefOptionsSetPrefix(TF_ImportGraphDefOptions* opts, const char* prefix)
.b2c.defExtFn[`tf;`C.TF_ImportGraphDefOptionsSetUniquifyNames;`c.void;`c.TF_ImportGraphDefOptions_p`c.c;()]; / void TF_ImportGraphDefOptionsSetUniquifyNames(TF_ImportGraphDefOptions* opts, unsigned char uniquify_names)
.b2c.defExtFn[`tf;`C.TF_ImportGraphDefOptionsSetUniquifyPrefix;`c.void;`c.TF_ImportGraphDefOptions_p`c.c;()]; / void TF_ImportGraphDefOptionsSetUniquifyPrefix(TF_ImportGraphDefOptions* opts, unsigned char uniquify_prefix)
.b2c.defExtFn[`tf;`C.TF_ImportGraphDefOptionsAddInputMapping;`c.void;`c.TF_ImportGraphDefOptions_p`c.S`c.i`c.TF_Output;()]; / void TF_ImportGraphDefOptionsAddInputMapping(TF_ImportGraphDefOptions* opts, const char* src_name, int src_index,TF_Output dst)
.b2c.defExtFn[`tf;`C.TF_ImportGraphDefOptionsRemapControlDependency;`c.void;`c.TF_ImportGraphDefOptions_p`c.S`c.TF_Operation_p;()]; / void TF_ImportGraphDefOptionsRemapControlDependency(TF_ImportGraphDefOptions* opts, const char* src_name, TF_Operation* dst)
.b2c.defExtFn[`tf;`C.TF_ImportGraphDefOptionsAddControlDependency;`c.void;`c.TF_ImportGraphDefOptions_p`c.TF_Operation_p;()]; / void TF_ImportGraphDefOptionsAddControlDependency(TF_ImportGraphDefOptions* opts, TF_Operation* oper)
.b2c.defExtFn[`tf;`C.TF_ImportGraphDefOptionsAddReturnOutput;`c.void;`c.TF_ImportGraphDefOptions_p`c.S`c.i;()]; / void TF_ImportGraphDefOptionsAddReturnOutput(TF_ImportGraphDefOptions* opts, const char* oper_name, int index)
.b2c.defExtFn[`tf;`C.TF_ImportGraphDefOptionsNumReturnOutputs;`c.i;`c.TF_ImportGraphDefOptions_p;()]; / int TF_ImportGraphDefOptionsNumReturnOutputs(const TF_ImportGraphDefOptions* opts)
.b2c.defExtFn[`tf;`C.TF_ImportGraphDefOptionsAddReturnOperation;`c.void;`c.TF_ImportGraphDefOptions_p`c.S;()]; / void TF_ImportGraphDefOptionsAddReturnOperation(TF_ImportGraphDefOptions* opts, const char* oper_name)
.b2c.defExtFn[`tf;`C.TF_ImportGraphDefOptionsNumReturnOperations;`c.i;`c.TF_ImportGraphDefOptions_p;()]; / int TF_ImportGraphDefOptionsNumReturnOperations(const TF_ImportGraphDefOptions* opts)
.b2c.defExtFn[`tf;`C.TF_ImportGraphDefResultsReturnOutputs;`c.void;`c.TF_ImportGraphDefResults_p`c.I`c.TF_Output_p_p;(enlist`nogen)!(),1b]; / void TF_ImportGraphDefResultsReturnOutputs(TF_ImportGraphDefResults* results, int* num_outputs, TF_Output** outputs)
.tf.TF_ImportGraphDefResultsReturnOutputs:{[r]
  C.TF_ImportGraphDefResultsReturnOutputs[`c.TF_ImportGraphDefResults_p$r;(&)c.i.n;(&)c.TF_Output_p.o];
  if[c.n<=0i;:()];
  res:([] oper:`long$(); index:`int$());
  do[c.n;res,:(C.toK `c.j$c.o[c.do1;`oper];C.toK c.o[c.do1;`index])];
  : res;
 };
.b2c.defExtFn[`tf;`C.TF_ImportGraphDefResultsReturnOperations;`c.void;`c.TF_ImportGraphDefResults_p`c.I`c.TF_Operation_p_p_p;(enlist`nogen)!(),1b]; / void TF_ImportGraphDefResultsReturnOperations(TF_ImportGraphDefResults* results, int* num_opers, TF_Operation*** opers)
.tf.TF_ImportGraphDefResultsReturnOperations:{[r]
  C.TF_ImportGraphDefResultsReturnOperations[`c.TF_ImportGraphDefResults_p$r;(&)c.i.n;(&)c.TF_Operation_p_p.o];
  if[c.n<=0i;:()];
  res:();
  do[c.n;res,:C.toK `c.j$c.o c.do1];
  :res;
 };
/ void TF_ImportGraphDefResultsMissingUnusedInputMappings(    TF_ImportGraphDefResults* results, int* num_missing_unused_input_mappings,const char*** src_names, int** src_indexes)
.b2c.defExtFn[`tf;`C.TF_ImportGraphDefResultsMissingUnusedInputMappings;`c.void;`c.TF_ImportGraphDefResults_p`c.I`c.cchar_p_p_p`c.I_p;(enlist`nogen)!(),1b];
.tf.TF_ImportGraphDefResultsMissingUnusedInputMappings:{[r]
  C.TF_ImportGraphDefResultsMissingUnusedInputMappings[`c.TF_ImportGraphDefResults_p$r;(&)c.i.n;(&)c.cchar_p_p.c;(&)c.I.i];
  if[c.n<=0i;:()];
  res:([] name:(); index:`int$());
  do[c.n;res,:(C.toK `c.C$c.c c.do1;C.toK c.i c.do1)];
  : res;
 };
.b2c.defExtFn[`tf;`C.TF_DeleteImportGraphDefResults;`c.void;`c.TF_ImportGraphDefResults_p;()]; / void TF_DeleteImportGraphDefResults(TF_ImportGraphDefResults* results)
/ TF_ImportGraphDefResults* TF_GraphImportGraphDefWithResults(TF_Graph* graph, const TF_Buffer* graph_def, const TF_ImportGraphDefOptions* options, TF_Status* status)
.b2c.defExtFn[`tf;`C.TF_GraphImportGraphDefWithResults;enlist`c.TF_ImportGraphDefResults_p`c.j;`c.TF_Graph_p`c.TF_Buffer_p`c.TF_ImportGraphDefOptions_p`c.TF_Status_p;()];
/ void TF_GraphImportGraphDefWithReturnOutputs(TF_Graph* graph, const TF_Buffer* graph_def, const TF_ImportGraphDefOptions* options, TF_Output* return_outputs,int num_return_outputs, TF_Status* status)
.b2c.defExtFn[`tf;`C.TF_GraphImportGraphDefWithReturnOutputs;`c.void;`c.TF_Graph_p`c.TF_Buffer_p`c.TF_ImportGraphDefOptions_p`c.TF_Output_p`c.i`c.TF_Status_p;()];
.tf.TF_GraphImportGraphDefWithReturnOutputs:{[g;b;o;s]
  if[0i>=c.i.n:C.TF_ImportGraphDefOptionsNumReturnOutputs `c.TF_ImportGraphDefOptions_p$o;:()];
  v:(C.toK (`c.j$count`c.TF_Output)*c.n)#0x00;
  C.TF_GraphImportGraphDefWithReturnOutputs[`c.TF_Graph_p$g;`c.TF_Buffer_p$b;`c.TF_ImportGraphDefOptions_p$o;`c.TF_Output_p$`c.void_p$`c.C$v;c.n;`c.TF_Status_p$s];
  : flip`oper`index!(8 4;"ji")1: v;
 };
.b2c.defExtFn[`tf;`C.TF_GraphImportGraphDef;`c.void;`c.TF_Graph_p`c.TF_Buffer_p`c.TF_ImportGraphDefOptions_p`c.TF_Status_p;()]; / void TF_GraphImportGraphDef(TF_Graph* graph, const TF_Buffer* graph_def,const TF_ImportGraphDefOptions* options, TF_Status* status)
.b2c.defExtFn[`tf;`C.TF_GraphCopyFunction;`c.void;`c.TF_Graph_p`c.TF_Function_p`c.TF_Function_p`c.TF_Status_p;()]; / void TF_GraphCopyFunction(TF_Graph* g,const TF_Function* func,const TF_Function* grad,TF_Status* status)
/ .b2c.defExtFn[`tf;`C.TF_GraphNumFunctions;`c.i;`c.TF_Graph_p;()]; / int TF_GraphNumFunctions(TF_Graph* g)
/ .b2c.defExtFn[`tf;`C.TF_GraphGetFunctions;`c.i;(`c.TF_Graph_p;enlist`c.J`c.void_p`c.TF_Function_p_p;(`c.i;enlist(`length;2));`c.TF_Status_p);()]; / int TF_GraphGetFunctions(TF_Graph* g, TF_Function** funcs,int max_func, TF_Status* status)
.b2c.defExtFn[`tf;`C.TF_OperationToNodeDef;`c.void;`c.TF_Operation_p`c.TF_Buffer_p`c.TF_Status_p;()]; / void TF_OperationToNodeDef(TF_Operation* oper,TF_Buffer* output_node_def,TF_Status* status)

.tf.createWhileParams:{[p]"c)`K`c.TF_WhileParams_p"; res:(C.toK `c.j$count`c.TF_WhileParams)#0x00; c.C.res:`c.C$res; c.C.src:`c.C$`c.void_p$p; do[count res;c.res[c.do1]:c.src c.do1]; res};
.tf.setWhileParams:{[p;name;val]
  c.TF_WhileParams_p.p:`c.TF_WhileParams_p$`c.void_p$`c.C$p;
  if[name=`cond_output;c.p[`cond_output;`oper]:`c.TF_Operation_p$val; c.p[`cond_output;`index]:`c.i$0i; :p]; / value = oper
  if[name=`body_outputs; if[not val[1]within(0;-1+C.toK c.p`ninputs);'"Bad while index"]; c.i.i:`c.i$val 1; c.p[`body_outputs;c.i;`oper]:`c.TF_Operation_p$val 0; c.p[`body_outputs;c.i;`index]:c.i; :p]; / val = (oper;index)
  if[name=`name; c.p[`name]:`c.S$val; :p]; / val = symbol
  '"Bad while name";
 };
.b2c.defExtFn[`tf;`C.TF_NewWhile;`c.TF_WhileParams;`c.TF_Graph_p`c.TF_Output_p`c.i`c.TF_Status_p;(enlist`nogen)!(),1b]; / TF_WhileParams TF_NewWhile(TF_Graph* g, TF_Output* inputs,int ninputs,TF_Status* status)
.tff.TF_NewWhile:{[g;i;s] / remove tmp
  v:.tf.encodeOut i;
  c.TF_WhileParams.p: C.TF_NewWhile[`c.TF_Graph_p$g;`c.TF_Output_p$`c.void_p$`c.C$v;`c.i$"i"$count i;`c.TF_Status_p$s];
  : .tf.createWhileParams (&)c.p;
 };
.b2c.defExtFn[`tf;`C.TF_FinishWhile;`c.void;`c.TF_WhileParams_p`c.TF_Status_p`c.TF_Output_p;(enlist`nogen)!(),1b]; / void TF_FinishWhile(const TF_WhileParams* params,TF_Status* status,TF_Output* outputs)
.tf.TF_FinishWhile:{[p;s]
  c.TF_WhileParams_p.p:`c.TF_WhileParams_p$`c.void_p$`c.C$p;
  v:(C.toK (`c.j$count`c.TF_Output)*c.p`ninputs)#0x00;
  C.TF_FinishWhile[c.p;`c.TF_Status_p$s;`c.TF_Output_p$`c.void_p$`c.C$v];
  : (C.toK c.p`ninputs)#flip`oper`index!(8 4;"ji")1: v;
 };
.b2c.defExtFn[`tf;`C.TF_AbortWhile;`c.void;`c.TF_WhileParams_p;()]; / void TF_AbortWhile(const TF_WhileParams* params)

/ void TF_AddGradients(TF_Graph* g, TF_Output* y, int ny,TF_Output* x, int nx, TF_Output* dx,TF_Status* status, TF_Output* dy)
.b2c.defExtFn[`tf;`C.TF_AddGradients;`c.void;`c.TF_Graph_p`c.TF_Output_p`c.i`c.TF_Output_p`c.i`c.TF_Output_p`c.TF_Status_p`c.TF_Output_p;(enlist`nogen)!(),1b];
.tf.TF_AddGradients:{[g;y;x;dx;s]
  yy:.tf.encodeOut y; xx:.tf.encodeOut x; dx:$[count dx;.tf.encodeOut dx;()];
  c.TF_Output_p.dx:`c.TF_Output_p$C.NULL;
  if[count dx;c.dx:`c.TF_Output_p$`c.void_p$`c.C$dx];
  v:((C.toK`c.j$count`c.TF_Output)*count x)#0x00;
  C.TF_AddGradients[`c.TF_Graph_p$g;`c.TF_Output_p$`c.void_p$`c.C$yy;`c.i$"i"$count y;`c.TF_Output_p$`c.void_p$`c.C$xx;`c.i$"i"$count x;c.dx;`c.TF_Status_p$s;`c.TF_Output_p$`c.void_p$`c.C$v];
  : flip`oper`index!(8 4;"ji")1: v;
 };

/ TF_Function* TF_GraphToFunction(const TF_Graph* fn_body, const char* fn_name,unsigned char append_hash_to_fn_name, int num_opers,const TF_Operation* const* opers,
/  int ninputs, const TF_Output* inputs,int noutputs, const TF_Output* outputs, const char* const* output_names,const TF_FunctionOptions* opts, const char* description, TF_Status* status)
.b2c.defExtFn[`tf;`C.TF_GraphToFunction;enlist`c.TF_Function_p`c.j;`c.TF_Graph_p`c.S`c.uchar`c.i`c.ccTF_Operation_p_p`c.i`c.TF_Output_p`c.i`c.TF_Output_p`c.cchar_p_p`c.TF_FunctionOptions_p`c.S`c.TF_Status_p;(enlist`nogen)!(),1b];
.tf.TF_GraphToFunction:{[g;name;hash;args;o;d;s] / args is (ops;in;out;names), count[names]=count[out] or 0
  nops:"i"$$[c:count a:args 0;c;$[a~();-1;0]]; ops:$[nops<0;0#0;a];
  inp:$[count a:args 1;.tf.encodeOut a;0#0x00];
  out:$[count a:args 2;.tf.encodeOut a;0#0x00];
  c.S_p.s:`c.S_p$C.NULL; if[count a:args 3; nms:(8*count a)#0x00; c.s:`c.S_p$`c.void_p$`c.C$nms; do[count a; c.s[c.do1]:`c.S$a C.toK c.do1]];
  : C.toK `c.j$C.TF_GraphToFunction[`c.TF_Graph_p$g;`c.S$name;`c.uchar$`c.c$hash;`c.i$nops;`c.ccTF_Operation_p_p$`c.void_p$`c.J$ops;`c.i$"i"$count args 1;`c.TF_Output_p$`c.void_p$`c.C$inp;
      `c.i$"i"$count args 2;`c.TF_Output_p$`c.void_p$`c.C$out;`c.cchar_p_p$`c.void_p$c.s;`c.TF_FunctionOptions_p$o;`c.S$d;`c.TF_Status_p$s];
 };
.b2c.defExtFn[`tf;`C.TF_FunctionToFunctionDef;`c.void;`c.TF_Function_p`c.TF_Buffer_p`c.TF_Status_p;()]; / void TF_FunctionToFunctionDef(TF_Function* func,TF_Buffer* output_func_def,TF_Status* status)
.b2c.defExtFn[`tf;`C.TF_FunctionImportFunctionDef;enlist`c.TF_Function_p`c.j;(enlist`c.C`c.void_p;(`c.size_t;enlist(`length;1));`c.TF_Status_p);()]; / TF_Function* TF_FunctionImportFunctionDef(const void* proto, size_t proto_len, TF_Status* status)
/ void TF_FunctionSetAttrValueProto(TF_Function* func,const char* attr_name,const void* proto,size_t proto_len,TF_Status* status)
.b2c.defExtFn[`tf;`C.TF_FunctionSetAttrValueProto;`c.void;(`c.TF_Function_p;`c.S;enlist`c.C`c.void_p;(`c.size_t;enlist(`length;3));`c.TF_Status_p);()];
.b2c.defExtFn[`tf;`C.TF_FunctionGetAttrValueProto;`c.void;(`c.TF_Function_p;`c.S;`c.TF_Buffer_p;`c.TF_Status_p);()]; / void TF_FunctionGetAttrValueProto(TF_Function* func, const char* attr_name, TF_Buffer* output_attr_value,TF_Status* status)
.b2c.defExtFn[`tf;`C.TF_DeleteFunction;`c.void;`c.TF_Function_p;()]; / void TF_DeleteFunction(TF_Function* func)

.b2c.defExtFn[`tf;`C.TF_NewSession;enlist`c.TF_Session_p`c.j;`c.TF_Graph_p`c.TF_SessionOptions_p`c.TF_Status_p;()]; / TF_Session* TF_NewSession(TF_Graph* graph,const TF_SessionOptions* opts,TF_Status* status)
/ TF_Session* TF_LoadSessionFromSavedModel(const TF_SessionOptions* session_options, const TF_Buffer* run_options,const char* export_dir, const char* const* tags, int tags_len,TF_Graph* graph, TF_Buffer* meta_graph_def, TF_Status* status)
.b2c.defExtFn[`tf;`C.TF_LoadSessionFromSavedModel;`c.TF_Session_p;`c.TF_SessionOptions_p`c.TF_Buffer_p`c.S`c.cchar_p_p`c.i`c.TF_Graph_p`c.TF_Buffer_p`c.TF_Status_p;(enlist`nogen)!(),1b];
.tf.TF_LoadSessionFromSavedModel:{[sopt;ropt;dir;tags;g;gdef;st]
  a:count[tags]#0; c.J.a: `c.J$a;
  do[count tags;c.a[c.do1]:`c.j$`c.S$t:tags C.toK c.do1];
  : C.toK `c.j$C.TF_LoadSessionFromSavedModel[`c.TF_SessionOptions_p$sopt;`c.TF_Buffer_p$ropt;`c.S$dir;`c.cchar_p_p$`c.void_p$c.a;`c.i$"i"$count tags;`c.TF_Graph_p$g;`c.TF_Buffer_p$gdef;`c.TF_Status_p$st];
 };
.b2c.defExtFn[`tf;`C.TF_CloseSession;`c.void;`c.TF_Session_p`c.TF_Status_p;()]; / void TF_CloseSession(TF_Session*, TF_Status* status)
.b2c.defExtFn[`tf;`C.TF_DeleteSession;`c.void;`c.TF_Session_p`c.TF_Status_p;()]; / void TF_DeleteSession(TF_Session*, TF_Status* status)
/ void TF_SessionRun(TF_Session* session,const TF_Buffer* run_options,const TF_Output* inputs, TF_Tensor* const* input_values, int ninputs,
/ const TF_Output* outputs, TF_Tensor** output_values, int noutputs, const TF_Operation* const* target_opers, int ntargets, TF_Buffer* run_metadata, TF_Status*)
.b2c.defExtFn[`tf;`C.TF_SessionRun;`c.void;`c.TF_Session_p`c.TF_Buffer_p`c.TF_Output_p`c.TF_Tensor_p_p`c.i`c.TF_Output_p`c.TF_Tensor_p_p`c.i`c.ccTF_Operation_p_p`c.i`c.TF_Buffer_p`c.TF_Status_p;(enlist`nogen)!(),1b];
.tf.TF_SessionRun:{[sess;ropts;inp;out;ops;mdata;st] / inp and out are (ops;tens)
  ii:$[count inp;.tf.encodeOut inp 0;0#0x00]; oo:$[count out;.tf.encodeOut out 0;0#0x00];
  it:$[count inp;inp 1;`long$()]; ot:$[count out;out 1;`long$()];
  C.TF_SessionRun[`c.TF_Session_p$sess;`c.TF_Buffer_p$ropts;`c.TF_Output_p$`c.void_p$`c.C$ii;`c.TF_Tensor_p_p$`c.void_p$`c.J$it;`c.i$"i"$count it;
    `c.TF_Output_p$`c.void_p$`c.C$oo;`c.TF_Tensor_p_p$`c.void_p$`c.J$ot;`c.i$"i"$count ot;`c.ccTF_Operation_p_p$`c.void_p$`c.J$ops;`c.i$"i"$count ops;`c.TF_Buffer_p$mdata;`c.TF_Status_p$st];
 };
/ void TF_SessionPRunSetup(TF_Session*,const TF_Output* inputs, int ninputs,const TF_Output* outputs, int noutputs, const TF_Operation* const* target_opers, int ntargets, const char** handle,TF_Status*)
.b2c.defExtFn[`tf;`C.TF_SessionPRunSetup;`c.void;`c.TF_Session_p`c.TF_Output_p`c.i`c.TF_Output_p`c.i`c.ccTF_Operation_p_p`c.i`c.cchar_p_p`c.TF_Status_p;(enlist`nogen)!(),1b];
.tf.TF_SessionPRunSetup:{[sess;inp;out;ops;st]
  ii:$[count inp;.tf.encodeOut inp;0#0x00]; oo:$[count out;.tf.encodeOut out;0#0x00];
  c.C.p:`c.C$`c.void_p$`c.j$0;
  C.TF_SessionPRunSetup[`c.TF_Session_p$sess;`c.TF_Output_p$`c.void_p$`c.C$ii;`c.i$"i"$count inp;`c.TF_Output_p$`c.void_p$`c.C$oo;`c.i$"i"$count out;
    `c.ccTF_Operation_p_p$`c.void_p$`c.J$ops;`c.i$"i"$count ops;`c.cchar_p_p$`c.void_p$(&)c.p;`c.TF_Status_p$st];
  : C.toK `c.j$c.p 0; / handle pointer
 };
/ void TF_SessionPRun(TF_Session*, const char* handle,const TF_Output* inputs, TF_Tensor* const* input_values, int ninputs,
/     const TF_Output* outputs, TF_Tensor** output_values, int noutputs, const TF_Operation* const* target_opers, int ntargets,TF_Status*)
.b2c.defExtFn[`tf;`C.TF_SessionPRun;`c.void;`c.TF_Session_p`c.S`c.TF_Output_p`c.TF_Tensor_p_p`c.i`c.TF_Output_p`c.TF_Tensor_p_p`c.i`c.ccTF_Operation_p_p`c.i`c.TF_Status_p;(enlist`nogen)!(),1b];
.tf.TF_SessionPRun:{[sess;hh;inp;out;ops;st] / inp and out are (ops;tens)
  ii:$[count inp;.tf.encodeOut inp 0;0#0x00]; oo:$[count out;.tf.encodeOut out 0;0#0x00];
  it:$[count inp;inp 1;`long$()]; ot:$[count out;out 1;`long$()];
  C.TF_SessionPRun[`c.TF_Session_p$sess;`c.S$`c.j$hh;`c.TF_Output_p$`c.void_p$`c.C$ii;`c.TF_Tensor_p_p$`c.void_p$`c.J$it;`c.i$"i"$count it;
    `c.TF_Output_p$`c.void_p$`c.C$oo;`c.TF_Tensor_p_p$`c.void_p$`c.J$ot;`c.i$"i"$count ot;`c.ccTF_Operation_p_p$`c.void_p$`c.J$ops;`c.i$"i"$count ops;`c.TF_Status_p$st];
 };
.b2c.defExtFn[`tf;`C.TF_DeletePRunHandle;`c.void;enlist enlist`c.j`c.S;()]; / void TF_DeletePRunHandle(const char* handle)

.b2c.defExtFn[`tf;`C.TF_SessionListDevices;enlist`c.TF_DeviceList_p`c.j;`c.TF_Session_p`c.TF_Status_p;()]; / TF_DeviceList* TF_SessionListDevices(TF_Session* session,TF_Status* status)
.b2c.defExtFn[`tf;`C.TF_DeleteDeviceList;`c.void;`c.TF_DeviceList_p;()]; / void TF_DeleteDeviceList(TF_DeviceList* list)
.b2c.defExtFn[`tf;`C.TF_DeviceListCount;`c.i;`c.TF_DeviceList_p;()]; / int TF_DeviceListCount(const TF_DeviceList* list)
.b2c.defExtFn[`tf;`C.TF_DeviceListName;enlist`c.cchar_p`c.S;`c.TF_DeviceList_p`c.i`c.TF_Status_p;()]; / const char* TF_DeviceListName(const TF_DeviceList* list,int index, TF_Status*)
.b2c.defExtFn[`tf;`C.TF_DeviceListType;enlist`c.cchar_p`c.S;`c.TF_DeviceList_p`c.i`c.TF_Status_p;()]; / const char* TF_DeviceListType(const TF_DeviceList* list, int index, TF_Status*)
.b2c.defExtFn[`tf;`C.TF_DeviceListMemoryBytes;`c.j;`c.TF_DeviceList_p`c.i`c.TF_Status_p;()]; / int64_t TF_DeviceListMemoryBytes(const TF_DeviceList* list, int index, TF_Status*)

.b2c.defExtFn[`tf;`C.TF_LoadLibrary;enlist`c.TF_Library_p`c.j;`c.S`c.TF_Status_p;()]; / TF_Library* TF_LoadLibrary(const char* library_filename,TF_Status* status)
.b2c.defExtFn[`tf;`C.TF_GetOpList;`c.TF_Buffer;`c.TF_Library_p;(enlist`nogen)!(),1b]; / TF_Buffer TF_GetOpList(TF_Library* lib_handle)
.tf.TF_GetOpList:{[l] c.TF_Buffer.b: C.TF_GetOpList `c.TF_Library_p$l; .tf.getBuffer C.toK `c.j$(&)c.b};
.b2c.defExtFn[`tf;`C.TF_DeleteLibraryHandle;`c.void;`c.TF_Library_p;()]; / void TF_DeleteLibraryHandle(TF_Library* lib_handle)
.b2c.defExtFn[`tf;`C.TF_GetAllOpList;enlist`c.TF_Buffer_p`c.j;`c.void;()]; / TF_Buffer* TF_GetAllOpList()

/ .b2c.defExtFn[`tf;`C.TF_NewApiDefMap;enlist`c.TF_ApiDefMap_p`c.j;`c.TF_Buffer_p`c.TF_Status_p;()]; / TF_ApiDefMap* TF_NewApiDefMap(TF_Buffer* op_list_buffer,TF_Status* status)
/ .b2c.defExtFn[`tf;`C.TF_DeleteApiDefMap;`c.void;`c.TF_ApiDefMap_p;()]; / void TF_DeleteApiDefMap(TF_ApiDefMap* apimap)
/ .b2c.defExtFn[`tf;`C.TF_ApiDefMapPut;`c.void;(`c.TF_ApiDefMap_p;`c.S;(`c.size_t;enlist(`length;2));`c.TF_Status_p);()]; / void TF_ApiDefMapPut(TF_ApiDefMap* api_def_map,const char* text, size_t text_len,TF_Status* status)
/ .b2c.defExtFn[`tf;`C.TF_ApiDefMapGet;enlist`c.TF_Buffer_p`c.j;(`c.TF_ApiDefMap_p;`c.S;(`c.size_t;enlist(`length;2));`c.TF_Status_p);()]; / TF_Buffer* TF_ApiDefMapGet(TF_ApiDefMap* api_def_map,const char* name,size_t name_len,TF_Status* status)

/ generate proxy
.b2c.compile[` sv/:`.tf,/:1_key `.tf;`libname`rec`goal`k`debug!(`tf;1b;`generate;"../../q2c";1)];

-1 "Done";
exit 0;

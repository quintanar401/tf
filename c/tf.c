#include <errno.h>
#include <stdio.h>
#include <stdlib.h>
#include <math.h>
#include <tensorflow/c/c_api.h>
#include "../../q2c/k.h"

static inline K kdot(K x,K y) { K res=dot(x,y); r0(x); r0(y); return res;};

#define PE(x) fprintf(stderr,x)
#define QSHOW(x) { K __r=kdot(r1(__q[1]),knk(1,r1(x))); if(__r) r0(__r);}
#define QSET(x,y) { K __r=kdot(r1(__q[0]),knk(2,ks(x),r1(y))); if(__r) r0(__r);}

extern J llabs(J x);
static K kif(K x);
static inline K __enlist(K l);
static K kamend(K ff,K a,K i,K f,K v);
static K kamend3(K ff,int isG,K* a,K i,K f);
static K kamend4(K ff,int isG,K* a,K i,K f,K v);
static K tf__getLib(K x);
K tf__init(K x);

static int __ginited=0;
static K* __q=(K*)0;
static K* __glob=(K*)0;
static K* __consts=(K*)0;
typedef J tfc_ij;
typedef tfc_ij * tfc_ij_p;
typedef void* * tfc_void_p_p;
typedef K  tfc__anontype73(I );
typedef tfc__anontype73 tfc_sd1_fn;
typedef tfc_sd1_fn * tfc_sd1_fn_p;
typedef I  tfc__anontype80(const void* ,const void* );
typedef tfc__anontype80 tfc_cmp_func;
typedef tfc_cmp_func * tfc_cmp_func_p;
typedef void  tfc__anontype121(void* ,size_t );
typedef tfc__anontype121 tfc_data_deallocator_func;
typedef tfc_data_deallocator_func * tfc_data_deallocator_func_p;
typedef TF_Tensor* * tfc_TF_Tensor_p_p;
typedef TF_Operation* * tfc_TF_Operation_p_p;
typedef TF_Output* * tfc_TF_Output_p_p;
typedef tfc_TF_Operation_p_p * tfc_TF_Operation_p_p_p;
typedef char** * tfc_S_p_p;
typedef TF_Function* * tfc_TF_Function_p_p;
typedef const char* * tfc_cchar_p_p;
typedef long* * tfc_long_p_p;
typedef tfc_cchar_p_p * tfc_cchar_p_p_p;
typedef void  tfc__anontype146(void* ,size_t ,void* );
typedef tfc__anontype146 tfc_deallocator_func;
typedef tfc_deallocator_func * tfc_deallocator_func_p;
typedef I tfc__anontype149[20];
static K  __K2i_cast(I* x0,K x1);
static K  __K2j_cast(J* x0,K x1);
static K  __K2f_cast(F* x0,K x1);
static K  __K2c_cast(char* x0,K x1);
static K  __K2I_cast(I** x0,K x1);
static K  __K2J_cast(J** x0,K x1);
static K  __K2H_cast(H** x0,K x1);
static K  __K2F_cast(F** x0,K x1);
static K  __K2E_cast(E** x0,K x1);
static K  __K2S_cast(char** x0,K x1);
static K  __K2C_cast(char** x0,K x1);
static K  __toKS(char* x0);
static K  __toKC(char* x0,J x1);
static K  __K2TF_Input_cast(TF_Input* x0,K x1);
static K  __K2TF_Output_cast(TF_Output* x0,K x1);
static K  __toKTF_Output(TF_Output* x0);
static K  __toKTF_AttrMetadata(TF_AttrMetadata* x0);
K  tf_tf_getBuffer__q(K x0);
static K tf_tf_getBuffer__k=(K)0;
K tf_tf_getBuffer(K x0) { return tf_tf_getBuffer__q(r1(x0));};
K  tf_tf_encodeOut__q(K x0);
static K tf_tf_encodeOut__k=(K)0;
K tf_tf_encodeOut(K x0) { return tf_tf_encodeOut__q(r1(x0));};
K  tf_tf_TF_Version__q(K x0);
static K tf_tf_TF_Version__k=(K)0;
K tf_tf_TF_Version(K x0) { return tf_tf_TF_Version__q(r1(x0));};
K  tf_tf_TF_DataTypeSize__q(K x0);
static K tf_tf_TF_DataTypeSize__k=(K)0;
K tf_tf_TF_DataTypeSize(K x0) { return tf_tf_TF_DataTypeSize__q(r1(x0));};
K  tf_tf_TF_NewStatus__q(K x0);
static K tf_tf_TF_NewStatus__k=(K)0;
K tf_tf_TF_NewStatus(K x0) { return tf_tf_TF_NewStatus__q(r1(x0));};
K  tf_tf_TF_DeleteStatus__q(K x0);
static K tf_tf_TF_DeleteStatus__k=(K)0;
K tf_tf_TF_DeleteStatus(K x0) { return tf_tf_TF_DeleteStatus__q(r1(x0));};
K  tf_tf_TF_SetStatus__q(K x0,K x1,K x2);
static K tf_tf_TF_SetStatus__k=(K)0;
K tf_tf_TF_SetStatus(K x0,K x1,K x2) { return tf_tf_TF_SetStatus__q(r1(x0),r1(x1),r1(x2));};
K  tf_tf_TF_GetCode__q(K x0);
static K tf_tf_TF_GetCode__k=(K)0;
K tf_tf_TF_GetCode(K x0) { return tf_tf_TF_GetCode__q(r1(x0));};
K  tf_tf_TF_Message__q(K x0);
static K tf_tf_TF_Message__k=(K)0;
K tf_tf_TF_Message(K x0) { return tf_tf_TF_Message__q(r1(x0));};
K  tf_tf_TF_NewBufferFromString__q(K x0);
static K tf_tf_TF_NewBufferFromString__k=(K)0;
K tf_tf_TF_NewBufferFromString(K x0) { return tf_tf_TF_NewBufferFromString__q(r1(x0));};
K  tf_tf_TF_NewBuffer__q(K x0);
static K tf_tf_TF_NewBuffer__k=(K)0;
K tf_tf_TF_NewBuffer(K x0) { return tf_tf_TF_NewBuffer__q(r1(x0));};
K  tf_tf_TF_DeleteBuffer__q(K x0);
static K tf_tf_TF_DeleteBuffer__k=(K)0;
K tf_tf_TF_DeleteBuffer(K x0) { return tf_tf_TF_DeleteBuffer__q(r1(x0));};
void  tf_tf_deallocator(void* x0,size_t x1,void* x2);
void*  tf_tf_getQPtr(K x0);
K  tf_tf_TF_NewTensor__q(K x0,K x1,K x2);
static K tf_tf_TF_NewTensor__k=(K)0;
K tf_tf_TF_NewTensor(K x0,K x1,K x2) { return tf_tf_TF_NewTensor__q(r1(x0),r1(x1),r1(x2));};
K  tf_tf_TF_AllocateTensor__q(K x0,K x1,K x2);
static K tf_tf_TF_AllocateTensor__k=(K)0;
K tf_tf_TF_AllocateTensor(K x0,K x1,K x2) { return tf_tf_TF_AllocateTensor__q(r1(x0),r1(x1),r1(x2));};
K  tf_tf_TF_TensorMaybeMove__q(K x0);
static K tf_tf_TF_TensorMaybeMove__k=(K)0;
K tf_tf_TF_TensorMaybeMove(K x0) { return tf_tf_TF_TensorMaybeMove__q(r1(x0));};
K  tf_tf_TF_DeleteTensor__q(K x0);
static K tf_tf_TF_DeleteTensor__k=(K)0;
K tf_tf_TF_DeleteTensor(K x0) { return tf_tf_TF_DeleteTensor__q(r1(x0));};
K  tf_tf_TF_TensorType__q(K x0);
static K tf_tf_TF_TensorType__k=(K)0;
K tf_tf_TF_TensorType(K x0) { return tf_tf_TF_TensorType__q(r1(x0));};
K  tf_tf_TF_NumDims__q(K x0);
static K tf_tf_TF_NumDims__k=(K)0;
K tf_tf_TF_NumDims(K x0) { return tf_tf_TF_NumDims__q(r1(x0));};
K  tf_tf_TF_Dim__q(K x0,K x1);
static K tf_tf_TF_Dim__k=(K)0;
K tf_tf_TF_Dim(K x0,K x1) { return tf_tf_TF_Dim__q(r1(x0),r1(x1));};
K  tf_tf_TF_TensorByteSize__q(K x0);
static K tf_tf_TF_TensorByteSize__k=(K)0;
K tf_tf_TF_TensorByteSize(K x0) { return tf_tf_TF_TensorByteSize__q(r1(x0));};
K  tf_tf_TF_TensorData__q(K x0);
static K tf_tf_TF_TensorData__k=(K)0;
K tf_tf_TF_TensorData(K x0) { return tf_tf_TF_TensorData__q(r1(x0));};
K  tf_tf_writeToTensor__q(K x0,K x1);
static K tf_tf_writeToTensor__k=(K)0;
K tf_tf_writeToTensor(K x0,K x1) { return tf_tf_writeToTensor__q(r1(x0),r1(x1));};
K  tf_tf_readFromTensor__q(K x0,K x1);
static K tf_tf_readFromTensor__k=(K)0;
K tf_tf_readFromTensor(K x0,K x1) { return tf_tf_readFromTensor__q(r1(x0),r1(x1));};
K  tf_tf_TF_StringEncode__q(K x0,K x1,K x2,K x3);
static K tf_tf_TF_StringEncode__k=(K)0;
K tf_tf_TF_StringEncode(K x0,K x1,K x2,K x3) { return tf_tf_TF_StringEncode__q(r1(x0),r1(x1),r1(x2),r1(x3));};
K  tf_tf_TF_StringDecode__q(K x0,K x1,K x2);
static K tf_tf_TF_StringDecode__k=(K)0;
K tf_tf_TF_StringDecode(K x0,K x1,K x2) { return tf_tf_TF_StringDecode__q(r1(x0),r1(x1),r1(x2));};
K  tf_tf_TF_StringEncodedSize__q(K x0);
static K tf_tf_TF_StringEncodedSize__k=(K)0;
K tf_tf_TF_StringEncodedSize(K x0) { return tf_tf_TF_StringEncodedSize__q(r1(x0));};
K  tf_tf_TF_NewSessionOptions__q(K x0);
static K tf_tf_TF_NewSessionOptions__k=(K)0;
K tf_tf_TF_NewSessionOptions(K x0) { return tf_tf_TF_NewSessionOptions__q(r1(x0));};
K  tf_tf_TF_SetTarget__q(K x0,K x1);
static K tf_tf_TF_SetTarget__k=(K)0;
K tf_tf_TF_SetTarget(K x0,K x1) { return tf_tf_TF_SetTarget__q(r1(x0),r1(x1));};
K  tf_tf_TF_SetConfig__q(K x0,K x1,K x2);
static K tf_tf_TF_SetConfig__k=(K)0;
K tf_tf_TF_SetConfig(K x0,K x1,K x2) { return tf_tf_TF_SetConfig__q(r1(x0),r1(x1),r1(x2));};
K  tf_tf_TF_DeleteSessionOptions__q(K x0);
static K tf_tf_TF_DeleteSessionOptions__k=(K)0;
K tf_tf_TF_DeleteSessionOptions(K x0) { return tf_tf_TF_DeleteSessionOptions__q(r1(x0));};
K  tf_tf_TF_NewGraph__q(K x0);
static K tf_tf_TF_NewGraph__k=(K)0;
K tf_tf_TF_NewGraph(K x0) { return tf_tf_TF_NewGraph__q(r1(x0));};
K  tf_tf_TF_DeleteGraph__q(K x0);
static K tf_tf_TF_DeleteGraph__k=(K)0;
K tf_tf_TF_DeleteGraph(K x0) { return tf_tf_TF_DeleteGraph__q(r1(x0));};
K  tf_tf_TF_GraphSetTensorShape__q(K x0,K x1,K x2,K x3);
static K tf_tf_TF_GraphSetTensorShape__k=(K)0;
K tf_tf_TF_GraphSetTensorShape(K x0,K x1,K x2,K x3) { return tf_tf_TF_GraphSetTensorShape__q(r1(x0),r1(x1),r1(x2),r1(x3));};
K  tf_tf_TF_GraphGetTensorNumDims__q(K x0,K x1,K x2);
static K tf_tf_TF_GraphGetTensorNumDims__k=(K)0;
K tf_tf_TF_GraphGetTensorNumDims(K x0,K x1,K x2) { return tf_tf_TF_GraphGetTensorNumDims__q(r1(x0),r1(x1),r1(x2));};
K  tf_tf_TF_GraphGetTensorShape__q(K x0,K x1,K x2,K x3);
static K tf_tf_TF_GraphGetTensorShape__k=(K)0;
K tf_tf_TF_GraphGetTensorShape(K x0,K x1,K x2,K x3) { return tf_tf_TF_GraphGetTensorShape__q(r1(x0),r1(x1),r1(x2),r1(x3));};
K  tf_tf_TF_NewOperation__q(K x0,K x1,K x2);
static K tf_tf_TF_NewOperation__k=(K)0;
K tf_tf_TF_NewOperation(K x0,K x1,K x2) { return tf_tf_TF_NewOperation__q(r1(x0),r1(x1),r1(x2));};
K  tf_tf_TF_SetDevice__q(K x0,K x1);
static K tf_tf_TF_SetDevice__k=(K)0;
K tf_tf_TF_SetDevice(K x0,K x1) { return tf_tf_TF_SetDevice__q(r1(x0),r1(x1));};
K  tf_tf_TF_AddInput__q(K x0,K x1);
static K tf_tf_TF_AddInput__k=(K)0;
K tf_tf_TF_AddInput(K x0,K x1) { return tf_tf_TF_AddInput__q(r1(x0),r1(x1));};
K  tf_tf_TF_AddInputList__q(K x0,K x1);
static K tf_tf_TF_AddInputList__k=(K)0;
K tf_tf_TF_AddInputList(K x0,K x1) { return tf_tf_TF_AddInputList__q(r1(x0),r1(x1));};
K  tf_tf_TF_AddControlInput__q(K x0,K x1);
static K tf_tf_TF_AddControlInput__k=(K)0;
K tf_tf_TF_AddControlInput(K x0,K x1) { return tf_tf_TF_AddControlInput__q(r1(x0),r1(x1));};
K  tf_tf_TF_SetAttrString__q(K x0,K x1,K x2);
static K tf_tf_TF_SetAttrString__k=(K)0;
K tf_tf_TF_SetAttrString(K x0,K x1,K x2) { return tf_tf_TF_SetAttrString__q(r1(x0),r1(x1),r1(x2));};
K  tf_tf_TF_SetAttrStringList__q(K x0,K x1,K x2);
static K tf_tf_TF_SetAttrStringList__k=(K)0;
K tf_tf_TF_SetAttrStringList(K x0,K x1,K x2) { return tf_tf_TF_SetAttrStringList__q(r1(x0),r1(x1),r1(x2));};
K  tf_tf_TF_SetAttrInt__q(K x0,K x1,K x2);
static K tf_tf_TF_SetAttrInt__k=(K)0;
K tf_tf_TF_SetAttrInt(K x0,K x1,K x2) { return tf_tf_TF_SetAttrInt__q(r1(x0),r1(x1),r1(x2));};
K  tf_tf_TF_SetAttrIntList__q(K x0,K x1,K x2);
static K tf_tf_TF_SetAttrIntList__k=(K)0;
K tf_tf_TF_SetAttrIntList(K x0,K x1,K x2) { return tf_tf_TF_SetAttrIntList__q(r1(x0),r1(x1),r1(x2));};
K  tf_tf_TF_SetAttrFloat__q(K x0,K x1,K x2);
static K tf_tf_TF_SetAttrFloat__k=(K)0;
K tf_tf_TF_SetAttrFloat(K x0,K x1,K x2) { return tf_tf_TF_SetAttrFloat__q(r1(x0),r1(x1),r1(x2));};
K  tf_tf_TF_SetAttrFloatList__q(K x0,K x1,K x2);
static K tf_tf_TF_SetAttrFloatList__k=(K)0;
K tf_tf_TF_SetAttrFloatList(K x0,K x1,K x2) { return tf_tf_TF_SetAttrFloatList__q(r1(x0),r1(x1),r1(x2));};
K  tf_tf_TF_SetAttrBool__q(K x0,K x1,K x2);
static K tf_tf_TF_SetAttrBool__k=(K)0;
K tf_tf_TF_SetAttrBool(K x0,K x1,K x2) { return tf_tf_TF_SetAttrBool__q(r1(x0),r1(x1),r1(x2));};
K  tf_tf_TF_SetAttrBoolList__q(K x0,K x1,K x2);
static K tf_tf_TF_SetAttrBoolList__k=(K)0;
K tf_tf_TF_SetAttrBoolList(K x0,K x1,K x2) { return tf_tf_TF_SetAttrBoolList__q(r1(x0),r1(x1),r1(x2));};
K  tf_tf_TF_SetAttrType__q(K x0,K x1,K x2);
static K tf_tf_TF_SetAttrType__k=(K)0;
K tf_tf_TF_SetAttrType(K x0,K x1,K x2) { return tf_tf_TF_SetAttrType__q(r1(x0),r1(x1),r1(x2));};
K  tf_tf_TF_SetAttrTypeList__q(K x0,K x1,K x2);
static K tf_tf_TF_SetAttrTypeList__k=(K)0;
K tf_tf_TF_SetAttrTypeList(K x0,K x1,K x2) { return tf_tf_TF_SetAttrTypeList__q(r1(x0),r1(x1),r1(x2));};
K  tf_tf_TF_SetAttrShape__q(K x0,K x1,K x2);
static K tf_tf_TF_SetAttrShape__k=(K)0;
K tf_tf_TF_SetAttrShape(K x0,K x1,K x2) { return tf_tf_TF_SetAttrShape__q(r1(x0),r1(x1),r1(x2));};
K  tf_tf_TF_SetAttrShapeList__q(K x0,K x1,K x2);
static K tf_tf_TF_SetAttrShapeList__k=(K)0;
K tf_tf_TF_SetAttrShapeList(K x0,K x1,K x2) { return tf_tf_TF_SetAttrShapeList__q(r1(x0),r1(x1),r1(x2));};
K  tf_tf_TF_SetAttrTensorShapeProto__q(K x0,K x1,K x2,K x3);
static K tf_tf_TF_SetAttrTensorShapeProto__k=(K)0;
K tf_tf_TF_SetAttrTensorShapeProto(K x0,K x1,K x2,K x3) { return tf_tf_TF_SetAttrTensorShapeProto__q(r1(x0),r1(x1),r1(x2),r1(x3));};
K  tf_tf_TF_SetAttrTensorShapeProtoList__q(K x0,K x1,K x2,K x3);
static K tf_tf_TF_SetAttrTensorShapeProtoList__k=(K)0;
K tf_tf_TF_SetAttrTensorShapeProtoList(K x0,K x1,K x2,K x3) { return tf_tf_TF_SetAttrTensorShapeProtoList__q(r1(x0),r1(x1),r1(x2),r1(x3));};
K  tf_tf_TF_SetAttrTensor__q(K x0,K x1,K x2,K x3);
static K tf_tf_TF_SetAttrTensor__k=(K)0;
K tf_tf_TF_SetAttrTensor(K x0,K x1,K x2,K x3) { return tf_tf_TF_SetAttrTensor__q(r1(x0),r1(x1),r1(x2),r1(x3));};
K  tf_tf_TF_SetAttrTensorList__q(K x0,K x1,K x2,K x3);
static K tf_tf_TF_SetAttrTensorList__k=(K)0;
K tf_tf_TF_SetAttrTensorList(K x0,K x1,K x2,K x3) { return tf_tf_TF_SetAttrTensorList__q(r1(x0),r1(x1),r1(x2),r1(x3));};
K  tf_tf_TF_SetAttrValueProto__q(K x0,K x1,K x2,K x3);
static K tf_tf_TF_SetAttrValueProto__k=(K)0;
K tf_tf_TF_SetAttrValueProto(K x0,K x1,K x2,K x3) { return tf_tf_TF_SetAttrValueProto__q(r1(x0),r1(x1),r1(x2),r1(x3));};
K  tf_tf_TF_FinishOperation__q(K x0,K x1);
static K tf_tf_TF_FinishOperation__k=(K)0;
K tf_tf_TF_FinishOperation(K x0,K x1) { return tf_tf_TF_FinishOperation__q(r1(x0),r1(x1));};
K  tf_tf_TF_OperationName__q(K x0);
static K tf_tf_TF_OperationName__k=(K)0;
K tf_tf_TF_OperationName(K x0) { return tf_tf_TF_OperationName__q(r1(x0));};
K  tf_tf_TF_OperationOpType__q(K x0);
static K tf_tf_TF_OperationOpType__k=(K)0;
K tf_tf_TF_OperationOpType(K x0) { return tf_tf_TF_OperationOpType__q(r1(x0));};
K  tf_tf_TF_OperationDevice__q(K x0);
static K tf_tf_TF_OperationDevice__k=(K)0;
K tf_tf_TF_OperationDevice(K x0) { return tf_tf_TF_OperationDevice__q(r1(x0));};
K  tf_tf_TF_OperationNumOutputs__q(K x0);
static K tf_tf_TF_OperationNumOutputs__k=(K)0;
K tf_tf_TF_OperationNumOutputs(K x0) { return tf_tf_TF_OperationNumOutputs__q(r1(x0));};
K  tf_tf_TF_OperationOutputType__q(K x0);
static K tf_tf_TF_OperationOutputType__k=(K)0;
K tf_tf_TF_OperationOutputType(K x0) { return tf_tf_TF_OperationOutputType__q(r1(x0));};
K  tf_tf_TF_OperationOutputListLength__q(K x0,K x1,K x2);
static K tf_tf_TF_OperationOutputListLength__k=(K)0;
K tf_tf_TF_OperationOutputListLength(K x0,K x1,K x2) { return tf_tf_TF_OperationOutputListLength__q(r1(x0),r1(x1),r1(x2));};
K  tf_tf_TF_OperationNumInputs__q(K x0);
static K tf_tf_TF_OperationNumInputs__k=(K)0;
K tf_tf_TF_OperationNumInputs(K x0) { return tf_tf_TF_OperationNumInputs__q(r1(x0));};
K  tf_tf_TF_OperationInputType__q(K x0);
static K tf_tf_TF_OperationInputType__k=(K)0;
K tf_tf_TF_OperationInputType(K x0) { return tf_tf_TF_OperationInputType__q(r1(x0));};
K  tf_tf_TF_OperationInputListLength__q(K x0,K x1,K x2);
static K tf_tf_TF_OperationInputListLength__k=(K)0;
K tf_tf_TF_OperationInputListLength(K x0,K x1,K x2) { return tf_tf_TF_OperationInputListLength__q(r1(x0),r1(x1),r1(x2));};
K  tf_tf_TF_OperationInput__q(K x0);
static K tf_tf_TF_OperationInput__k=(K)0;
K tf_tf_TF_OperationInput(K x0) { return tf_tf_TF_OperationInput__q(r1(x0));};
K  tf_tf_TF_OperationOutputNumConsumers__q(K x0);
static K tf_tf_TF_OperationOutputNumConsumers__k=(K)0;
K tf_tf_TF_OperationOutputNumConsumers(K x0) { return tf_tf_TF_OperationOutputNumConsumers__q(r1(x0));};
K  tf_tf_TF_OperationOutputConsumers__q(K x0);
static K tf_tf_TF_OperationOutputConsumers__k=(K)0;
K tf_tf_TF_OperationOutputConsumers(K x0) { return tf_tf_TF_OperationOutputConsumers__q(r1(x0));};
K  tf_tf_TF_OperationNumControlInputs__q(K x0);
static K tf_tf_TF_OperationNumControlInputs__k=(K)0;
K tf_tf_TF_OperationNumControlInputs(K x0) { return tf_tf_TF_OperationNumControlInputs__q(r1(x0));};
K  tf_tf_TF_OperationGetControlInputs__q(K x0,K x1);
static K tf_tf_TF_OperationGetControlInputs__k=(K)0;
K tf_tf_TF_OperationGetControlInputs(K x0,K x1) { return tf_tf_TF_OperationGetControlInputs__q(r1(x0),r1(x1));};
K  tf_tf_TF_OperationNumControlOutputs__q(K x0);
static K tf_tf_TF_OperationNumControlOutputs__k=(K)0;
K tf_tf_TF_OperationNumControlOutputs(K x0) { return tf_tf_TF_OperationNumControlOutputs__q(r1(x0));};
K  tf_tf_TF_OperationGetControlOutputs__q(K x0,K x1);
static K tf_tf_TF_OperationGetControlOutputs__k=(K)0;
K tf_tf_TF_OperationGetControlOutputs(K x0,K x1) { return tf_tf_TF_OperationGetControlOutputs__q(r1(x0),r1(x1));};
K  tf_tf_TF_OperationGetAttrMetadata__q(K x0,K x1,K x2);
static K tf_tf_TF_OperationGetAttrMetadata__k=(K)0;
K tf_tf_TF_OperationGetAttrMetadata(K x0,K x1,K x2) { return tf_tf_TF_OperationGetAttrMetadata__q(r1(x0),r1(x1),r1(x2));};
K  tf_tf_TF_OperationGetAttrString__q(K x0,K x1,K x2,K x3);
static K tf_tf_TF_OperationGetAttrString__k=(K)0;
K tf_tf_TF_OperationGetAttrString(K x0,K x1,K x2,K x3) { return tf_tf_TF_OperationGetAttrString__q(r1(x0),r1(x1),r1(x2),r1(x3));};
K  tf_tf_TF_OperationGetAttrStringList__q(K x0,K x1,K x2,K x3,K x4,K x5);
static K tf_tf_TF_OperationGetAttrStringList__k=(K)0;
K tf_tf_TF_OperationGetAttrStringList(K x0,K x1,K x2,K x3,K x4,K x5) { return tf_tf_TF_OperationGetAttrStringList__q(r1(x0),r1(x1),r1(x2),r1(x3),r1(x4),r1(x5));};
K  tf_tf_TF_OperationGetAttrInt__q(K x0,K x1,K x2);
static K tf_tf_TF_OperationGetAttrInt__k=(K)0;
K tf_tf_TF_OperationGetAttrInt(K x0,K x1,K x2) { return tf_tf_TF_OperationGetAttrInt__q(r1(x0),r1(x1),r1(x2));};
K  tf_tf_TF_OperationGetAttrIntList__q(K x0,K x1,K x2,K x3);
static K tf_tf_TF_OperationGetAttrIntList__k=(K)0;
K tf_tf_TF_OperationGetAttrIntList(K x0,K x1,K x2,K x3) { return tf_tf_TF_OperationGetAttrIntList__q(r1(x0),r1(x1),r1(x2),r1(x3));};
K  tf_tf_TF_OperationGetAttrFloat__q(K x0,K x1,K x2);
static K tf_tf_TF_OperationGetAttrFloat__k=(K)0;
K tf_tf_TF_OperationGetAttrFloat(K x0,K x1,K x2) { return tf_tf_TF_OperationGetAttrFloat__q(r1(x0),r1(x1),r1(x2));};
K  tf_tf_TF_OperationGetAttrFloatList__q(K x0,K x1,K x2,K x3);
static K tf_tf_TF_OperationGetAttrFloatList__k=(K)0;
K tf_tf_TF_OperationGetAttrFloatList(K x0,K x1,K x2,K x3) { return tf_tf_TF_OperationGetAttrFloatList__q(r1(x0),r1(x1),r1(x2),r1(x3));};
K  tf_tf_TF_OperationGetAttrBool__q(K x0,K x1,K x2);
static K tf_tf_TF_OperationGetAttrBool__k=(K)0;
K tf_tf_TF_OperationGetAttrBool(K x0,K x1,K x2) { return tf_tf_TF_OperationGetAttrBool__q(r1(x0),r1(x1),r1(x2));};
K  tf_tf_TF_OperationGetAttrBoolList__q(K x0,K x1,K x2,K x3);
static K tf_tf_TF_OperationGetAttrBoolList__k=(K)0;
K tf_tf_TF_OperationGetAttrBoolList(K x0,K x1,K x2,K x3) { return tf_tf_TF_OperationGetAttrBoolList__q(r1(x0),r1(x1),r1(x2),r1(x3));};
K  tf_tf_TF_OperationGetAttrType__q(K x0,K x1,K x2);
static K tf_tf_TF_OperationGetAttrType__k=(K)0;
K tf_tf_TF_OperationGetAttrType(K x0,K x1,K x2) { return tf_tf_TF_OperationGetAttrType__q(r1(x0),r1(x1),r1(x2));};
K  tf_tf_TF_OperationGetAttrTypeList__q(K x0,K x1,K x2,K x3);
static K tf_tf_TF_OperationGetAttrTypeList__k=(K)0;
K tf_tf_TF_OperationGetAttrTypeList(K x0,K x1,K x2,K x3) { return tf_tf_TF_OperationGetAttrTypeList__q(r1(x0),r1(x1),r1(x2),r1(x3));};
K  tf_tf_TF_OperationGetAttrShape__q(K x0,K x1,K x2,K x3);
static K tf_tf_TF_OperationGetAttrShape__k=(K)0;
K tf_tf_TF_OperationGetAttrShape(K x0,K x1,K x2,K x3) { return tf_tf_TF_OperationGetAttrShape__q(r1(x0),r1(x1),r1(x2),r1(x3));};
K  tf_tf_TF_OperationGetAttrShapeList__q(K x0,K x1,K x2,K x3,K x4,K x5);
static K tf_tf_TF_OperationGetAttrShapeList__k=(K)0;
K tf_tf_TF_OperationGetAttrShapeList(K x0,K x1,K x2,K x3,K x4,K x5) { return tf_tf_TF_OperationGetAttrShapeList__q(r1(x0),r1(x1),r1(x2),r1(x3),r1(x4),r1(x5));};
K  tf_tf_TF_OperationGetAttrTensorShapeProto__q(K x0,K x1,K x2,K x3);
static K tf_tf_TF_OperationGetAttrTensorShapeProto__k=(K)0;
K tf_tf_TF_OperationGetAttrTensorShapeProto(K x0,K x1,K x2,K x3) { return tf_tf_TF_OperationGetAttrTensorShapeProto__q(r1(x0),r1(x1),r1(x2),r1(x3));};
K  tf_tf_TF_OperationGetAttrTensor__q(K x0,K x1,K x2);
static K tf_tf_TF_OperationGetAttrTensor__k=(K)0;
K tf_tf_TF_OperationGetAttrTensor(K x0,K x1,K x2) { return tf_tf_TF_OperationGetAttrTensor__q(r1(x0),r1(x1),r1(x2));};
K  tf_tf_TF_OperationGetAttrTensorList__q(K x0,K x1,K x2,K x3,K x4);
static K tf_tf_TF_OperationGetAttrTensorList__k=(K)0;
K tf_tf_TF_OperationGetAttrTensorList(K x0,K x1,K x2,K x3,K x4) { return tf_tf_TF_OperationGetAttrTensorList__q(r1(x0),r1(x1),r1(x2),r1(x3),r1(x4));};
K  tf_tf_TF_GraphOperationByName__q(K x0,K x1);
static K tf_tf_TF_GraphOperationByName__k=(K)0;
K tf_tf_TF_GraphOperationByName(K x0,K x1) { return tf_tf_TF_GraphOperationByName__q(r1(x0),r1(x1));};
K  tf_tf_TF_GraphNextOperation__q(K x0,K x1);
static K tf_tf_TF_GraphNextOperation__k=(K)0;
K tf_tf_TF_GraphNextOperation(K x0,K x1) { return tf_tf_TF_GraphNextOperation__q(r1(x0),r1(x1));};
K  tf_tf_TF_GraphToGraphDef__q(K x0,K x1,K x2);
static K tf_tf_TF_GraphToGraphDef__k=(K)0;
K tf_tf_TF_GraphToGraphDef(K x0,K x1,K x2) { return tf_tf_TF_GraphToGraphDef__q(r1(x0),r1(x1),r1(x2));};
K  tf_tf_TF_GraphGetOpDef__q(K x0,K x1,K x2,K x3);
static K tf_tf_TF_GraphGetOpDef__k=(K)0;
K tf_tf_TF_GraphGetOpDef(K x0,K x1,K x2,K x3) { return tf_tf_TF_GraphGetOpDef__q(r1(x0),r1(x1),r1(x2),r1(x3));};
K  tf_tf_TF_GraphVersions__q(K x0,K x1,K x2);
static K tf_tf_TF_GraphVersions__k=(K)0;
K tf_tf_TF_GraphVersions(K x0,K x1,K x2) { return tf_tf_TF_GraphVersions__q(r1(x0),r1(x1),r1(x2));};
K  tf_tf_TF_NewImportGraphDefOptions__q(K x0);
static K tf_tf_TF_NewImportGraphDefOptions__k=(K)0;
K tf_tf_TF_NewImportGraphDefOptions(K x0) { return tf_tf_TF_NewImportGraphDefOptions__q(r1(x0));};
K  tf_tf_TF_DeleteImportGraphDefOptions__q(K x0);
static K tf_tf_TF_DeleteImportGraphDefOptions__k=(K)0;
K tf_tf_TF_DeleteImportGraphDefOptions(K x0) { return tf_tf_TF_DeleteImportGraphDefOptions__q(r1(x0));};
K  tf_tf_TF_ImportGraphDefOptionsSetPrefix__q(K x0,K x1);
static K tf_tf_TF_ImportGraphDefOptionsSetPrefix__k=(K)0;
K tf_tf_TF_ImportGraphDefOptionsSetPrefix(K x0,K x1) { return tf_tf_TF_ImportGraphDefOptionsSetPrefix__q(r1(x0),r1(x1));};
K  tf_tf_TF_ImportGraphDefOptionsSetUniquifyNames__q(K x0,K x1);
static K tf_tf_TF_ImportGraphDefOptionsSetUniquifyNames__k=(K)0;
K tf_tf_TF_ImportGraphDefOptionsSetUniquifyNames(K x0,K x1) { return tf_tf_TF_ImportGraphDefOptionsSetUniquifyNames__q(r1(x0),r1(x1));};
K  tf_tf_TF_ImportGraphDefOptionsSetUniquifyPrefix__q(K x0,K x1);
static K tf_tf_TF_ImportGraphDefOptionsSetUniquifyPrefix__k=(K)0;
K tf_tf_TF_ImportGraphDefOptionsSetUniquifyPrefix(K x0,K x1) { return tf_tf_TF_ImportGraphDefOptionsSetUniquifyPrefix__q(r1(x0),r1(x1));};
K  tf_tf_TF_ImportGraphDefOptionsAddInputMapping__q(K x0,K x1,K x2,K x3);
static K tf_tf_TF_ImportGraphDefOptionsAddInputMapping__k=(K)0;
K tf_tf_TF_ImportGraphDefOptionsAddInputMapping(K x0,K x1,K x2,K x3) { return tf_tf_TF_ImportGraphDefOptionsAddInputMapping__q(r1(x0),r1(x1),r1(x2),r1(x3));};
K  tf_tf_TF_ImportGraphDefOptionsRemapControlDependency__q(K x0,K x1,K x2);
static K tf_tf_TF_ImportGraphDefOptionsRemapControlDependency__k=(K)0;
K tf_tf_TF_ImportGraphDefOptionsRemapControlDependency(K x0,K x1,K x2) { return tf_tf_TF_ImportGraphDefOptionsRemapControlDependency__q(r1(x0),r1(x1),r1(x2));};
K  tf_tf_TF_ImportGraphDefOptionsAddControlDependency__q(K x0,K x1);
static K tf_tf_TF_ImportGraphDefOptionsAddControlDependency__k=(K)0;
K tf_tf_TF_ImportGraphDefOptionsAddControlDependency(K x0,K x1) { return tf_tf_TF_ImportGraphDefOptionsAddControlDependency__q(r1(x0),r1(x1));};
K  tf_tf_TF_ImportGraphDefOptionsAddReturnOutput__q(K x0,K x1,K x2);
static K tf_tf_TF_ImportGraphDefOptionsAddReturnOutput__k=(K)0;
K tf_tf_TF_ImportGraphDefOptionsAddReturnOutput(K x0,K x1,K x2) { return tf_tf_TF_ImportGraphDefOptionsAddReturnOutput__q(r1(x0),r1(x1),r1(x2));};
K  tf_tf_TF_ImportGraphDefOptionsNumReturnOutputs__q(K x0);
static K tf_tf_TF_ImportGraphDefOptionsNumReturnOutputs__k=(K)0;
K tf_tf_TF_ImportGraphDefOptionsNumReturnOutputs(K x0) { return tf_tf_TF_ImportGraphDefOptionsNumReturnOutputs__q(r1(x0));};
K  tf_tf_TF_ImportGraphDefOptionsAddReturnOperation__q(K x0,K x1);
static K tf_tf_TF_ImportGraphDefOptionsAddReturnOperation__k=(K)0;
K tf_tf_TF_ImportGraphDefOptionsAddReturnOperation(K x0,K x1) { return tf_tf_TF_ImportGraphDefOptionsAddReturnOperation__q(r1(x0),r1(x1));};
K  tf_tf_TF_ImportGraphDefOptionsNumReturnOperations__q(K x0);
static K tf_tf_TF_ImportGraphDefOptionsNumReturnOperations__k=(K)0;
K tf_tf_TF_ImportGraphDefOptionsNumReturnOperations(K x0) { return tf_tf_TF_ImportGraphDefOptionsNumReturnOperations__q(r1(x0));};
K  tf_tf_TF_ImportGraphDefResultsReturnOutputs__q(K x0);
static K tf_tf_TF_ImportGraphDefResultsReturnOutputs__k=(K)0;
K tf_tf_TF_ImportGraphDefResultsReturnOutputs(K x0) { return tf_tf_TF_ImportGraphDefResultsReturnOutputs__q(r1(x0));};
K  tf_tf_TF_ImportGraphDefResultsReturnOperations__q(K x0);
static K tf_tf_TF_ImportGraphDefResultsReturnOperations__k=(K)0;
K tf_tf_TF_ImportGraphDefResultsReturnOperations(K x0) { return tf_tf_TF_ImportGraphDefResultsReturnOperations__q(r1(x0));};
K  tf_tf_TF_ImportGraphDefResultsMissingUnusedInputMappings__q(K x0);
static K tf_tf_TF_ImportGraphDefResultsMissingUnusedInputMappings__k=(K)0;
K tf_tf_TF_ImportGraphDefResultsMissingUnusedInputMappings(K x0) { return tf_tf_TF_ImportGraphDefResultsMissingUnusedInputMappings__q(r1(x0));};
K  tf_tf_TF_DeleteImportGraphDefResults__q(K x0);
static K tf_tf_TF_DeleteImportGraphDefResults__k=(K)0;
K tf_tf_TF_DeleteImportGraphDefResults(K x0) { return tf_tf_TF_DeleteImportGraphDefResults__q(r1(x0));};
K  tf_tf_TF_GraphImportGraphDefWithResults__q(K x0,K x1,K x2,K x3);
static K tf_tf_TF_GraphImportGraphDefWithResults__k=(K)0;
K tf_tf_TF_GraphImportGraphDefWithResults(K x0,K x1,K x2,K x3) { return tf_tf_TF_GraphImportGraphDefWithResults__q(r1(x0),r1(x1),r1(x2),r1(x3));};
K  tf_tf_TF_GraphImportGraphDefWithReturnOutputs__q(K x0,K x1,K x2,K x3);
static K tf_tf_TF_GraphImportGraphDefWithReturnOutputs__k=(K)0;
K tf_tf_TF_GraphImportGraphDefWithReturnOutputs(K x0,K x1,K x2,K x3) { return tf_tf_TF_GraphImportGraphDefWithReturnOutputs__q(r1(x0),r1(x1),r1(x2),r1(x3));};
K  tf_tf_TF_GraphImportGraphDef__q(K x0,K x1,K x2,K x3);
static K tf_tf_TF_GraphImportGraphDef__k=(K)0;
K tf_tf_TF_GraphImportGraphDef(K x0,K x1,K x2,K x3) { return tf_tf_TF_GraphImportGraphDef__q(r1(x0),r1(x1),r1(x2),r1(x3));};
K  tf_tf_TF_GraphCopyFunction__q(K x0,K x1,K x2,K x3);
static K tf_tf_TF_GraphCopyFunction__k=(K)0;
K tf_tf_TF_GraphCopyFunction(K x0,K x1,K x2,K x3) { return tf_tf_TF_GraphCopyFunction__q(r1(x0),r1(x1),r1(x2),r1(x3));};
K  tf_tf_TF_OperationToNodeDef__q(K x0,K x1,K x2);
static K tf_tf_TF_OperationToNodeDef__k=(K)0;
K tf_tf_TF_OperationToNodeDef(K x0,K x1,K x2) { return tf_tf_TF_OperationToNodeDef__q(r1(x0),r1(x1),r1(x2));};
K  tf_tf_createWhileParams(TF_WhileParams* x0);
K  tf_tf_setWhileParams__q(K x0,K x1,K x2);
static K tf_tf_setWhileParams__k=(K)0;
K tf_tf_setWhileParams(K x0,K x1,K x2) { return tf_tf_setWhileParams__q(r1(x0),r1(x1),r1(x2));};
K  tf_tf_TF_FinishWhile__q(K x0,K x1);
static K tf_tf_TF_FinishWhile__k=(K)0;
K tf_tf_TF_FinishWhile(K x0,K x1) { return tf_tf_TF_FinishWhile__q(r1(x0),r1(x1));};
K  tf_tf_TF_AbortWhile__q(K x0);
static K tf_tf_TF_AbortWhile__k=(K)0;
K tf_tf_TF_AbortWhile(K x0) { return tf_tf_TF_AbortWhile__q(r1(x0));};
K  tf_tf_TF_AddGradients__q(K x0,K x1,K x2,K x3,K x4);
static K tf_tf_TF_AddGradients__k=(K)0;
K tf_tf_TF_AddGradients(K x0,K x1,K x2,K x3,K x4) { return tf_tf_TF_AddGradients__q(r1(x0),r1(x1),r1(x2),r1(x3),r1(x4));};
K  tf_tf_TF_GraphToFunction__q(K x0,K x1,K x2,K x3,K x4,K x5,K x6);
static K tf_tf_TF_GraphToFunction__k=(K)0;
K tf_tf_TF_GraphToFunction(K x0,K x1,K x2,K x3,K x4,K x5,K x6) { return tf_tf_TF_GraphToFunction__q(r1(x0),r1(x1),r1(x2),r1(x3),r1(x4),r1(x5),r1(x6));};
K  tf_tf_TF_FunctionToFunctionDef__q(K x0,K x1,K x2);
static K tf_tf_TF_FunctionToFunctionDef__k=(K)0;
K tf_tf_TF_FunctionToFunctionDef(K x0,K x1,K x2) { return tf_tf_TF_FunctionToFunctionDef__q(r1(x0),r1(x1),r1(x2));};
K  tf_tf_TF_FunctionImportFunctionDef__q(K x0,K x1);
static K tf_tf_TF_FunctionImportFunctionDef__k=(K)0;
K tf_tf_TF_FunctionImportFunctionDef(K x0,K x1) { return tf_tf_TF_FunctionImportFunctionDef__q(r1(x0),r1(x1));};
K  tf_tf_TF_FunctionSetAttrValueProto__q(K x0,K x1,K x2,K x3);
static K tf_tf_TF_FunctionSetAttrValueProto__k=(K)0;
K tf_tf_TF_FunctionSetAttrValueProto(K x0,K x1,K x2,K x3) { return tf_tf_TF_FunctionSetAttrValueProto__q(r1(x0),r1(x1),r1(x2),r1(x3));};
K  tf_tf_TF_FunctionGetAttrValueProto__q(K x0,K x1,K x2,K x3);
static K tf_tf_TF_FunctionGetAttrValueProto__k=(K)0;
K tf_tf_TF_FunctionGetAttrValueProto(K x0,K x1,K x2,K x3) { return tf_tf_TF_FunctionGetAttrValueProto__q(r1(x0),r1(x1),r1(x2),r1(x3));};
K  tf_tf_TF_DeleteFunction__q(K x0);
static K tf_tf_TF_DeleteFunction__k=(K)0;
K tf_tf_TF_DeleteFunction(K x0) { return tf_tf_TF_DeleteFunction__q(r1(x0));};
K  tf_tf_TF_NewSession__q(K x0,K x1,K x2);
static K tf_tf_TF_NewSession__k=(K)0;
K tf_tf_TF_NewSession(K x0,K x1,K x2) { return tf_tf_TF_NewSession__q(r1(x0),r1(x1),r1(x2));};
K  tf_tf_TF_LoadSessionFromSavedModel__q(K x0,K x1,K x2,K x3,K x4,K x5,K x6);
static K tf_tf_TF_LoadSessionFromSavedModel__k=(K)0;
K tf_tf_TF_LoadSessionFromSavedModel(K x0,K x1,K x2,K x3,K x4,K x5,K x6) { return tf_tf_TF_LoadSessionFromSavedModel__q(r1(x0),r1(x1),r1(x2),r1(x3),r1(x4),r1(x5),r1(x6));};
K  tf_tf_TF_CloseSession__q(K x0,K x1);
static K tf_tf_TF_CloseSession__k=(K)0;
K tf_tf_TF_CloseSession(K x0,K x1) { return tf_tf_TF_CloseSession__q(r1(x0),r1(x1));};
K  tf_tf_TF_DeleteSession__q(K x0,K x1);
static K tf_tf_TF_DeleteSession__k=(K)0;
K tf_tf_TF_DeleteSession(K x0,K x1) { return tf_tf_TF_DeleteSession__q(r1(x0),r1(x1));};
K  tf_tf_TF_SessionRun__q(K x0,K x1,K x2,K x3,K x4,K x5,K x6);
static K tf_tf_TF_SessionRun__k=(K)0;
K tf_tf_TF_SessionRun(K x0,K x1,K x2,K x3,K x4,K x5,K x6) { return tf_tf_TF_SessionRun__q(r1(x0),r1(x1),r1(x2),r1(x3),r1(x4),r1(x5),r1(x6));};
K  tf_tf_TF_SessionPRunSetup__q(K x0,K x1,K x2,K x3,K x4);
static K tf_tf_TF_SessionPRunSetup__k=(K)0;
K tf_tf_TF_SessionPRunSetup(K x0,K x1,K x2,K x3,K x4) { return tf_tf_TF_SessionPRunSetup__q(r1(x0),r1(x1),r1(x2),r1(x3),r1(x4));};
K  tf_tf_TF_SessionPRun__q(K x0,K x1,K x2,K x3,K x4,K x5);
static K tf_tf_TF_SessionPRun__k=(K)0;
K tf_tf_TF_SessionPRun(K x0,K x1,K x2,K x3,K x4,K x5) { return tf_tf_TF_SessionPRun__q(r1(x0),r1(x1),r1(x2),r1(x3),r1(x4),r1(x5));};
K  tf_tf_TF_DeletePRunHandle__q(K x0);
static K tf_tf_TF_DeletePRunHandle__k=(K)0;
K tf_tf_TF_DeletePRunHandle(K x0) { return tf_tf_TF_DeletePRunHandle__q(r1(x0));};
K  tf_tf_TF_SessionListDevices__q(K x0,K x1);
static K tf_tf_TF_SessionListDevices__k=(K)0;
K tf_tf_TF_SessionListDevices(K x0,K x1) { return tf_tf_TF_SessionListDevices__q(r1(x0),r1(x1));};
K  tf_tf_TF_DeleteDeviceList__q(K x0);
static K tf_tf_TF_DeleteDeviceList__k=(K)0;
K tf_tf_TF_DeleteDeviceList(K x0) { return tf_tf_TF_DeleteDeviceList__q(r1(x0));};
K  tf_tf_TF_DeviceListCount__q(K x0);
static K tf_tf_TF_DeviceListCount__k=(K)0;
K tf_tf_TF_DeviceListCount(K x0) { return tf_tf_TF_DeviceListCount__q(r1(x0));};
K  tf_tf_TF_DeviceListName__q(K x0,K x1,K x2);
static K tf_tf_TF_DeviceListName__k=(K)0;
K tf_tf_TF_DeviceListName(K x0,K x1,K x2) { return tf_tf_TF_DeviceListName__q(r1(x0),r1(x1),r1(x2));};
K  tf_tf_TF_DeviceListType__q(K x0,K x1,K x2);
static K tf_tf_TF_DeviceListType__k=(K)0;
K tf_tf_TF_DeviceListType(K x0,K x1,K x2) { return tf_tf_TF_DeviceListType__q(r1(x0),r1(x1),r1(x2));};
K  tf_tf_TF_DeviceListMemoryBytes__q(K x0,K x1,K x2);
static K tf_tf_TF_DeviceListMemoryBytes__k=(K)0;
K tf_tf_TF_DeviceListMemoryBytes(K x0,K x1,K x2) { return tf_tf_TF_DeviceListMemoryBytes__q(r1(x0),r1(x1),r1(x2));};
K  tf_tf_TF_LoadLibrary__q(K x0,K x1);
static K tf_tf_TF_LoadLibrary__k=(K)0;
K tf_tf_TF_LoadLibrary(K x0,K x1) { return tf_tf_TF_LoadLibrary__q(r1(x0),r1(x1));};
K  tf_tf_TF_GetOpList__q(K x0);
static K tf_tf_TF_GetOpList__k=(K)0;
K tf_tf_TF_GetOpList(K x0) { return tf_tf_TF_GetOpList__q(r1(x0));};
K  tf_tf_TF_DeleteLibraryHandle__q(K x0);
static K tf_tf_TF_DeleteLibraryHandle__k=(K)0;
K tf_tf_TF_DeleteLibraryHandle(K x0) { return tf_tf_TF_DeleteLibraryHandle__q(r1(x0));};
K  tf_tf_TF_GetAllOpList__q(K x0);
static K tf_tf_TF_GetAllOpList__k=(K)0;
K tf_tf_TF_GetAllOpList(K x0) { return tf_tf_TF_GetAllOpList__q(r1(x0));};
K __wglobals = (K)0;
static K * __consts;
static I __intmap[20] = {0,1,0,0,1,2,4,8,0,0,1,0,8,4,4,0,8,4,4,4};
static K __libFuncs;
static K __libGlobs;
static K __Kerr = (K)0;
static K __K2i_cast(I* _x,K _y){
  K __st[1]; int __stc=0; K __v=(K)1;
  _Bool _vc_bool1; I _vc_i1;
  
  _vc_bool1=0>(_y)->t;  // >[0;<val>]
  if(0==_vc_bool1) goto __l5;  // if/while check condition
  _vc_i1= -(I)(_y)->t;  // neg[<val>]
  _vc_bool1=4==__intmap[_vc_i1];  // =[4;<val>]
  if(0==_vc_bool1) goto __l5;  // if/while check condition
  _x[0]=(_y)->i;  // x[,0]:<val> - no rval, param
  
  // end of statement
  __v=r1(__consts[0]);  // const ()
  goto __return;  // return cmd
  r0(__v); 
  // end of statement

 __l5:
  __v=r1(__consts[80]);  // const "K2i_cast: type"
  __st[__stc++]=__v;  if(__v->t==-KS) __v=krr(__v->s); else if(__v->t==KC)  __v=krr(sn(kC(__v),__v->n)); else __v=krr("stype"); goto __return;  // raise an exception
  goto __return;  // return cmd

 __return:
  r0(_y); 
  while(__stc>0) r0(__st[--__stc]); 
  return __v;
 };
static K __K2j_cast(J* _x,K _y){
  K __st[1]; int __stc=0; K __v=(K)1;
  _Bool _vc_bool1; I _vc_i1;
  
  _vc_bool1=0>(_y)->t;  // >[0;<val>]
  if(0==_vc_bool1) goto __l5;  // if/while check condition
  _vc_i1= -(I)(_y)->t;  // neg[<val>]
  _vc_bool1=8==__intmap[_vc_i1];  // =[8;<val>]
  if(0==_vc_bool1) goto __l5;  // if/while check condition
  _x[0]=(_y)->j;  // x[,0]:<val> - no rval, param
  
  // end of statement
  __v=r1(__consts[0]);  // const ()
  goto __return;  // return cmd
  r0(__v); 
  // end of statement

 __l5:
  __v=r1(__consts[82]);  // const "K2j_cast: type"
  __st[__stc++]=__v;  if(__v->t==-KS) __v=krr(__v->s); else if(__v->t==KC)  __v=krr(sn(kC(__v),__v->n)); else __v=krr("stype"); goto __return;  // raise an exception
  goto __return;  // return cmd

 __return:
  r0(_y); 
  while(__stc>0) r0(__st[--__stc]); 
  return __v;
 };
static K __K2f_cast(F* _x,K _y){
  K __st[1]; int __stc=0; K __v=(K)1;
  _Bool _vc_bool1;
  
  _vc_bool1=-9==(_y)->t;  // =[-9;<val>]
  if(0==_vc_bool1) goto __l3;  // if/while check condition
  _x[0]=(_y)->f;  // x[,0]:<val> - no rval, param
  
  // end of statement
  __v=r1(__consts[0]);  // const ()
  goto __return;  // return cmd
  r0(__v); 
  // end of statement

 __l3:
  __v=r1(__consts[84]);  // const "K2f_cast: type"
  __st[__stc++]=__v;  if(__v->t==-KS) __v=krr(__v->s); else if(__v->t==KC)  __v=krr(sn(kC(__v),__v->n)); else __v=krr("stype"); goto __return;  // raise an exception
  goto __return;  // return cmd

 __return:
  r0(_y); 
  while(__stc>0) r0(__st[--__stc]); 
  return __v;
 };
static K __K2c_cast(char* _x,K _y){
  K __st[1]; int __stc=0; K __v=(K)1;
  _Bool _vc_bool1;
  
  _vc_bool1=-10==(_y)->t;  // =[-10;<val>]
  if(0==_vc_bool1) goto __l3;  // if/while check condition
  _x[0]=(char)(_y)->g;  // x[,0]:<val> - no rval, param
  
  // end of statement
  __v=r1(__consts[0]);  // const ()
  goto __return;  // return cmd
  r0(__v); 
  // end of statement

 __l3:
  __v=r1(__consts[86]);  // const "K2c_cast: type"
  __st[__stc++]=__v;  if(__v->t==-KS) __v=krr(__v->s); else if(__v->t==KC)  __v=krr(sn(kC(__v),__v->n)); else __v=krr("stype"); goto __return;  // raise an exception
  goto __return;  // return cmd

 __return:
  r0(_y); 
  while(__stc>0) r0(__st[--__stc]); 
  return __v;
 };
static K __K2I_cast(I** _x,K _y){
  K __st[1]; int __stc=0; K __v=(K)1;
  K _c_y; _Bool _vc_bool1; _Bool _vc_bool2;
  
  _c_y=_y;  // c.y[()]::<val> - no rval, global
  
  // end of statement
  _vc_bool1=0<_c_y->t;  // <[0;<val>]
  _vc_bool2=20LL>_c_y->t;  // >[20LL;<val>]
  _vc_bool1=_vc_bool2&_vc_bool1;  // &[_vc_bool2;_vc_bool1]
  if(0==_vc_bool1) goto __l7;  // if/while check condition
  _vc_bool1=4==__intmap[(I)_c_y->t];  // =[4;<val>]
  if(0==_vc_bool1) goto __l7;  // if/while check condition
  _vc_bool1=0==_c_y->r;  // =[0;<val>]
  if(0==_vc_bool1) goto __l4;  // if/while check condition
  __v=r1(__consts[88]);  // const "K2I_cast: no ref"
  __st[__stc++]=__v;  if(__v->t==-KS) __v=krr(__v->s); else if(__v->t==KC)  __v=krr(sn(kC(__v),__v->n)); else __v=krr("stype"); goto __return;  // raise an exception
  r0(__v); 
  // end of statement

 __l4:
  _x[0]=(I*)(_y)->G0;  // x[,0]:<val> - no rval, param
  
  // end of statement
  __v=r1(__consts[0]);  // const ()
  goto __return;  // return cmd
  r0(__v); 
  // end of statement

 __l7:
  __v=r1(__consts[90]);  // const "K2I_cast: type"
  __st[__stc++]=__v;  if(__v->t==-KS) __v=krr(__v->s); else if(__v->t==KC)  __v=krr(sn(kC(__v),__v->n)); else __v=krr("stype"); goto __return;  // raise an exception
  goto __return;  // return cmd

 __return:
  r0(_y); 
  while(__stc>0) r0(__st[--__stc]); 
  return __v;
 };
static K __K2J_cast(J** _x,K _y){
  K __st[1]; int __stc=0; K __v=(K)1;
  K _c_y; _Bool _vc_bool1; _Bool _vc_bool2;
  
  _c_y=_y;  // c.y[()]::<val> - no rval, global
  
  // end of statement
  _vc_bool1=0<_c_y->t;  // <[0;<val>]
  _vc_bool2=20LL>_c_y->t;  // >[20LL;<val>]
  _vc_bool1=_vc_bool2&_vc_bool1;  // &[_vc_bool2;_vc_bool1]
  if(0==_vc_bool1) goto __l7;  // if/while check condition
  _vc_bool1=8==__intmap[(I)_c_y->t];  // =[8;<val>]
  if(0==_vc_bool1) goto __l7;  // if/while check condition
  _vc_bool1=0==_c_y->r;  // =[0;<val>]
  if(0==_vc_bool1) goto __l4;  // if/while check condition
  __v=r1(__consts[91]);  // const "K2J_cast: no ref"
  __st[__stc++]=__v;  if(__v->t==-KS) __v=krr(__v->s); else if(__v->t==KC)  __v=krr(sn(kC(__v),__v->n)); else __v=krr("stype"); goto __return;  // raise an exception
  r0(__v); 
  // end of statement

 __l4:
  _x[0]=(J*)(_y)->G0;  // x[,0]:<val> - no rval, param
  
  // end of statement
  __v=r1(__consts[0]);  // const ()
  goto __return;  // return cmd
  r0(__v); 
  // end of statement

 __l7:
  __v=r1(__consts[92]);  // const "K2J_cast: type"
  __st[__stc++]=__v;  if(__v->t==-KS) __v=krr(__v->s); else if(__v->t==KC)  __v=krr(sn(kC(__v),__v->n)); else __v=krr("stype"); goto __return;  // raise an exception
  goto __return;  // return cmd

 __return:
  r0(_y); 
  while(__stc>0) r0(__st[--__stc]); 
  return __v;
 };
static K __K2H_cast(H** _x,K _y){
  K __st[1]; int __stc=0; K __v=(K)1;
  _Bool _vc_bool1;
  
  _vc_bool1=5==(_y)->t;  // =[5;<val>]
  if(0==_vc_bool1) goto __l5;  // if/while check condition
  _vc_bool1=0==(_y)->r;  // =[0;<val>]
  if(0==_vc_bool1) goto __l3;  // if/while check condition
  __v=r1(__consts[93]);  // const "K2H_cast: no ref"
  __st[__stc++]=__v;  if(__v->t==-KS) __v=krr(__v->s); else if(__v->t==KC)  __v=krr(sn(kC(__v),__v->n)); else __v=krr("stype"); goto __return;  // raise an exception
  r0(__v); 
  // end of statement

 __l3:
  _x[0]=(H*)(_y)->G0;  // x[,0]:<val> - no rval, param
  
  // end of statement
  __v=r1(__consts[0]);  // const ()
  goto __return;  // return cmd
  r0(__v); 
  // end of statement

 __l5:
  __v=r1(__consts[94]);  // const "K2H_cast: type"
  __st[__stc++]=__v;  if(__v->t==-KS) __v=krr(__v->s); else if(__v->t==KC)  __v=krr(sn(kC(__v),__v->n)); else __v=krr("stype"); goto __return;  // raise an exception
  goto __return;  // return cmd

 __return:
  r0(_y); 
  while(__stc>0) r0(__st[--__stc]); 
  return __v;
 };
static K __K2F_cast(F** _x,K _y){
  K __st[1]; int __stc=0; K __v=(K)1;
  _Bool _vc_bool1;
  
  _vc_bool1=9==(_y)->t;  // =[9;<val>]
  if(0==_vc_bool1) goto __l5;  // if/while check condition
  _vc_bool1=0==(_y)->r;  // =[0;<val>]
  if(0==_vc_bool1) goto __l3;  // if/while check condition
  __v=r1(__consts[95]);  // const "K2F_cast: no ref"
  __st[__stc++]=__v;  if(__v->t==-KS) __v=krr(__v->s); else if(__v->t==KC)  __v=krr(sn(kC(__v),__v->n)); else __v=krr("stype"); goto __return;  // raise an exception
  r0(__v); 
  // end of statement

 __l3:
  _x[0]=(F*)(_y)->G0;  // x[,0]:<val> - no rval, param
  
  // end of statement
  __v=r1(__consts[0]);  // const ()
  goto __return;  // return cmd
  r0(__v); 
  // end of statement

 __l5:
  __v=r1(__consts[96]);  // const "K2F_cast: type"
  __st[__stc++]=__v;  if(__v->t==-KS) __v=krr(__v->s); else if(__v->t==KC)  __v=krr(sn(kC(__v),__v->n)); else __v=krr("stype"); goto __return;  // raise an exception
  goto __return;  // return cmd

 __return:
  r0(_y); 
  while(__stc>0) r0(__st[--__stc]); 
  return __v;
 };
static K __K2E_cast(E** _x,K _y){
  K __st[1]; int __stc=0; K __v=(K)1;
  _Bool _vc_bool1;
  
  _vc_bool1=8==(_y)->t;  // =[8;<val>]
  if(0==_vc_bool1) goto __l5;  // if/while check condition
  _vc_bool1=0==(_y)->r;  // =[0;<val>]
  if(0==_vc_bool1) goto __l3;  // if/while check condition
  __v=r1(__consts[97]);  // const "K2E_cast: no ref"
  __st[__stc++]=__v;  if(__v->t==-KS) __v=krr(__v->s); else if(__v->t==KC)  __v=krr(sn(kC(__v),__v->n)); else __v=krr("stype"); goto __return;  // raise an exception
  r0(__v); 
  // end of statement

 __l3:
  _x[0]=(E*)(_y)->G0;  // x[,0]:<val> - no rval, param
  
  // end of statement
  __v=r1(__consts[0]);  // const ()
  goto __return;  // return cmd
  r0(__v); 
  // end of statement

 __l5:
  __v=r1(__consts[98]);  // const "K2E_cast: type"
  __st[__stc++]=__v;  if(__v->t==-KS) __v=krr(__v->s); else if(__v->t==KC)  __v=krr(sn(kC(__v),__v->n)); else __v=krr("stype"); goto __return;  // raise an exception
  goto __return;  // return cmd

 __return:
  r0(_y); 
  while(__stc>0) r0(__st[--__stc]); 
  return __v;
 };
static K __K2S_cast(char** _x,K _y){
  K __st[1]; int __stc=0; K __v=(K)1;
  _Bool _vc_bool1; _Bool _vc_bool2;
  
  _vc_bool1=10==(_y)->t;  // =[10;<val>]
  _vc_bool2=-11==(_y)->t;  // =[-11;<val>]
  _vc_bool1=_vc_bool2|_vc_bool1;  // |[_vc_bool2;_vc_bool1]
  if(0==_vc_bool1) goto __l10;  // if/while check condition
  _vc_bool1=0==(_y)->r;  // =[0;<val>]
  if(0==_vc_bool1) goto __l3;  // if/while check condition
  __v=r1(__consts[99]);  // const "K2S_cast: no ref"
  __st[__stc++]=__v;  if(__v->t==-KS) __v=krr(__v->s); else if(__v->t==KC)  __v=krr(sn(kC(__v),__v->n)); else __v=krr("stype"); goto __return;  // raise an exception
  r0(__v); 
  // end of statement

 __l3:
  _vc_bool1=-11==(_y)->t;  // =[-11;<val>]
  if(0==_vc_bool1) goto __l6;  // if/while check condition
  _x[0]=(_y)->s;  // x[,0]:<val> - no rval, param
  
  // end of statement
  __v=r1(__consts[0]);  // const ()
  goto __return;  // return cmd
  r0(__v); 
  // end of statement

 __l6:
  __v=kdot(r1(__consts[47]),knk(2,r1(__consts[1]),r1(_y))); if(0==__v) goto __return;   // =[0;y]
  __v=kdot(r1(__q[3]),knk(1,__v)); if(0==__v) goto __return;   // any[<val>]
  __v=kif(__v); if(0==__v) goto __return; if(0==__v->j) { r0(__v); goto __l9;}; r0(__v);  // if/while check condition
  _x[0]=(char*)(_y)->G0;  // x[,0]:<val> - no rval, param
  
  // end of statement
  __v=r1(__consts[0]);  // const ()
  goto __return;  // return cmd
  r0(__v); 
  // end of statement

 __l9:
  __v=r1(__consts[101]);  // const "K2S_cast: no null t
  __st[__stc++]=__v;  if(__v->t==-KS) __v=krr(__v->s); else if(__v->t==KC)  __v=krr(sn(kC(__v),__v->n)); else __v=krr("stype"); goto __return;  // raise an exception
  r0(__v); 
  // end of statement

 __l10:
  __v=r1(__consts[102]);  // const "K2S_cast: type"
  __st[__stc++]=__v;  if(__v->t==-KS) __v=krr(__v->s); else if(__v->t==KC)  __v=krr(sn(kC(__v),__v->n)); else __v=krr("stype"); goto __return;  // raise an exception
  goto __return;  // return cmd

 __return:
  r0(_y); 
  while(__stc>0) r0(__st[--__stc]); 
  return __v;
 };
static K __K2C_cast(char** _x,K _y){
  K __st[1]; int __stc=0; K __v=(K)1;
  _Bool _vc_bool1; _Bool _vc_bool2;
  
  _vc_bool1=10LL==(_y)->t;  // =[10LL;<val>]
  _vc_bool2=4LL==(_y)->t;  // =[4LL;<val>]
  _vc_bool1=_vc_bool2|_vc_bool1;  // |[_vc_bool2;_vc_bool1]
  if(0==_vc_bool1) goto __l5;  // if/while check condition
  _vc_bool1=0==(_y)->r;  // =[0;<val>]
  if(0==_vc_bool1) goto __l3;  // if/while check condition
  __v=r1(__consts[103]);  // const "K2C_cast: no ref"
  __st[__stc++]=__v;  if(__v->t==-KS) __v=krr(__v->s); else if(__v->t==KC)  __v=krr(sn(kC(__v),__v->n)); else __v=krr("stype"); goto __return;  // raise an exception
  r0(__v); 
  // end of statement

 __l3:
  _x[0]=(char*)(_y)->G0;  // x[,0]:<val> - no rval, param
  
  // end of statement
  __v=r1(__consts[0]);  // const ()
  goto __return;  // return cmd
  r0(__v); 
  // end of statement

 __l5:
  __v=r1(__consts[104]);  // const "K2C_cast: type"
  __st[__stc++]=__v;  if(__v->t==-KS) __v=krr(__v->s); else if(__v->t==KC)  __v=krr(sn(kC(__v),__v->n)); else __v=krr("stype"); goto __return;  // raise an exception
  goto __return;  // return cmd

 __return:
  r0(_y); 
  while(__stc>0) r0(__st[--__stc]); 
  return __v;
 };
static K __toKS(char* _x){
  K __st[1]; int __stc=0; K __v=(K)1;
  J _c_l; char* _c_r; _Bool _vc_bool1; J _c_do1;
  K _r=r1(__consts[0]); 
  _c_l=0LL;  // c.l[()]::0LL - no rval, global
  
  // end of statement

 __l1:
  _vc_bool1=0LL!=(I)_x[_c_l];  // ~=[0LL;<val>]
  if(0==_vc_bool1) goto __l3;  // if/while check condition
  _c_l+=1LL;  // c.l[()]+::1LL - no rval, global
  
  // end of statement
  goto __l1;  // jump back to do/while

 __l3:
  __v=kj(_c_l); if(0==__v) goto __return;   // C.toK[c.l]
  __v=kdot(r1(__consts[52]),knk(2,__v,r1(__consts[106]))); if(0==__v) goto __return;   // #[<val>;" "]
  r0(_r); _r=__v;  // r:<val> - no rval, local
  
  // end of statement
  _c_r=(char*)(_r)->G0;  // c.r[()]::<val> - no rval, global
  
  // end of statement
  _c_do1=_c_l;  // local _c_do1
    // check that do value is correct

 __l4:
  if(0>=_c_do1)goto __l6; _c_do1-=1;  // do condition
  _c_r[_c_do1]=_x[_c_do1];  // c.r[<val>]::<val> - no rval, global
  
  // end of statement
  goto __l4;  // jump back to do/while

 __l6:
  __v=r1(_r);  // local r
  goto __return;  // return cmd

 __return:
  r0(_r); 
  while(__stc>0) r0(__st[--__stc]); 
  return __v;
 };
static K __toKC(char* _x,J _y){
  K __st[1]; int __stc=0; K __v=(K)1;
  char* _c_r; J _c_do1;
  K _r=r1(__consts[0]); 
  __v=ktn(10,_y); if(0==__v) goto __return;   // C.ktn[10;y]
  r0(_r); _r=__v;  // r:<val> - no rval, local
  
  // end of statement
  _c_r=(char*)(_r)->G0;  // c.r[()]::<val> - no rval, global
  
  // end of statement
  _c_do1=_y;  // arg _c_do1
    // check that do value is correct

 __l1:
  if(0>=_c_do1)goto __l3; _c_do1-=1;  // do condition
  _c_r[_c_do1]=_x[_c_do1];  // c.r[<val>]::<val> - no rval, global
  
  // end of statement
  goto __l1;  // jump back to do/while

 __l3:
  __v=r1(_r);  // local r
  goto __return;  // return cmd

 __return:
  r0(_r); 
  while(__stc>0) r0(__st[--__stc]); 
  return __v;
 };
static K __K2TF_Input_cast(TF_Input* _x,K _y){
  K __st[1]; int __stc=0; K __v=(K)1;
  J _vc_j1; I _vc_i1;
  K _k=r1(__consts[0]); K _kk=r1(__consts[0]); K _v=r1(__consts[0]); 
  r0(_k); _k=r1(__consts[107]);  // k:`oper`index - no rval, local
  
  // end of statement
  __v=kdot(r1(__consts[25]),knk(1,r1(_y))); if(0==__v) goto __return;   // type[y]
  __v=kdot(r1(__consts[105]),knk(2,r1(__consts[108]),__v)); if(0==__v) goto __return;   // ~=[99;<val>]
  __v=kif(__v); if(0==__v) goto __return; if(0==__v->j) { r0(__v); goto __l2;}; r0(__v);  // if/while check condition
  __v=r1(__consts[109]);  // const "`c.TF_Input$: type"
  __st[__stc++]=__v;  if(__v->t==-KS) __v=krr(__v->s); else if(__v->t==KC)  __v=krr(sn(kC(__v),__v->n)); else __v=krr("stype"); goto __return;  // raise an exception
  r0(__v); 
  // end of statement

 __l2:
  __v=__enlist(knk(1,r1(_y))); if(0==__v) goto __return;   // enlist[y]
  __v=kdot(r1(__q[11]),__v); if(0==__v) goto __return;   // C.dot[inv;<val>]
  r0(_kk); _kk=__v;  // kk:<val> - no rval, local
  
  // end of statement
  __v=kdot(r1(__consts[62]),knk(2,r1(_k),r1(_kk))); if(0==__v) goto __return;   // in[k;kk]
  __v=kdot(r1(__q[13]),knk(1,__v)); if(0==__v) goto __return;   // all[<val>]
  __v=kdot(r1(__consts[22]),knk(1,__v)); if(0==__v) goto __return;   // not[<val>]
  __v=kif(__v); if(0==__v) goto __return; if(0==__v->j) { r0(__v); goto __l4;}; r0(__v);  // if/while check condition
  __v=r1(__consts[109]);  // const "`c.TF_Input$: type"
  __st[__stc++]=__v;  if(__v->t==-KS) __v=krr(__v->s); else if(__v->t==KC)  __v=krr(sn(kC(__v),__v->n)); else __v=krr("stype"); goto __return;  // raise an exception
  r0(__v); 
  // end of statement

 __l4:
  __v=kdot(r1(_y),knk(1,r1(_k))); if(0==__v) goto __return;   // y[k]
  r0(_v); _v=__v;  // v:<val> - no rval, local
  
  // end of statement
  __v=kdot(r1(_v),knk(1,r1(__consts[1]))); if(0==__v) goto __return;   // v[0]
  __v=__K2j_cast(&_vc_j1,__v); if(0==__v) goto __return; r0(__v);   // `c.j$<val>
  _x->oper=(TF_Operation*)_vc_j1;  // x[,"oper"]:<val> - no rval, param
  
  // end of statement
  __v=kdot(r1(_v),knk(1,r1(__consts[2]))); if(0==__v) goto __return;   // v[1]
  __v=__K2i_cast(&_vc_i1,__v); if(0==__v) goto __return; r0(__v);   // `c.i$<val>
  _x->index=_vc_i1;  // x[,"index"]:_vc_i1 - no rval, param
  
  // end of statement
  __v=r1(__consts[5]);  // const ::
  goto __return;  // return cmd

 __return:
  r0(_k); r0(_kk); r0(_v); r0(_y); 
  while(__stc>0) r0(__st[--__stc]); 
  return __v;
 };
static K __K2TF_Output_cast(TF_Output* _x,K _y){
  K __st[1]; int __stc=0; K __v=(K)1;
  J _vc_j1; I _vc_i1;
  K _k=r1(__consts[0]); K _kk=r1(__consts[0]); K _v=r1(__consts[0]); 
  r0(_k); _k=r1(__consts[107]);  // k:`oper`index - no rval, local
  
  // end of statement
  __v=kdot(r1(__consts[25]),knk(1,r1(_y))); if(0==__v) goto __return;   // type[y]
  __v=kdot(r1(__consts[105]),knk(2,r1(__consts[108]),__v)); if(0==__v) goto __return;   // ~=[99;<val>]
  __v=kif(__v); if(0==__v) goto __return; if(0==__v->j) { r0(__v); goto __l2;}; r0(__v);  // if/while check condition
  __v=r1(__consts[112]);  // const "`c.TF_Output$: type
  __st[__stc++]=__v;  if(__v->t==-KS) __v=krr(__v->s); else if(__v->t==KC)  __v=krr(sn(kC(__v),__v->n)); else __v=krr("stype"); goto __return;  // raise an exception
  r0(__v); 
  // end of statement

 __l2:
  __v=__enlist(knk(1,r1(_y))); if(0==__v) goto __return;   // enlist[y]
  __v=kdot(r1(__q[11]),__v); if(0==__v) goto __return;   // C.dot[inv;<val>]
  r0(_kk); _kk=__v;  // kk:<val> - no rval, local
  
  // end of statement
  __v=kdot(r1(__consts[62]),knk(2,r1(_k),r1(_kk))); if(0==__v) goto __return;   // in[k;kk]
  __v=kdot(r1(__q[13]),knk(1,__v)); if(0==__v) goto __return;   // all[<val>]
  __v=kdot(r1(__consts[22]),knk(1,__v)); if(0==__v) goto __return;   // not[<val>]
  __v=kif(__v); if(0==__v) goto __return; if(0==__v->j) { r0(__v); goto __l4;}; r0(__v);  // if/while check condition
  __v=r1(__consts[112]);  // const "`c.TF_Output$: type
  __st[__stc++]=__v;  if(__v->t==-KS) __v=krr(__v->s); else if(__v->t==KC)  __v=krr(sn(kC(__v),__v->n)); else __v=krr("stype"); goto __return;  // raise an exception
  r0(__v); 
  // end of statement

 __l4:
  __v=kdot(r1(_y),knk(1,r1(_k))); if(0==__v) goto __return;   // y[k]
  r0(_v); _v=__v;  // v:<val> - no rval, local
  
  // end of statement
  __v=kdot(r1(_v),knk(1,r1(__consts[1]))); if(0==__v) goto __return;   // v[0]
  __v=__K2j_cast(&_vc_j1,__v); if(0==__v) goto __return; r0(__v);   // `c.j$<val>
  _x->oper=(TF_Operation*)_vc_j1;  // x[,"oper"]:<val> - no rval, param
  
  // end of statement
  __v=kdot(r1(_v),knk(1,r1(__consts[2]))); if(0==__v) goto __return;   // v[1]
  __v=__K2i_cast(&_vc_i1,__v); if(0==__v) goto __return; r0(__v);   // `c.i$<val>
  _x->index=_vc_i1;  // x[,"index"]:_vc_i1 - no rval, param
  
  // end of statement
  __v=r1(__consts[5]);  // const ::
  goto __return;  // return cmd

 __return:
  r0(_k); r0(_kk); r0(_v); r0(_y); 
  while(__stc>0) r0(__st[--__stc]); 
  return __v;
 };
static K __toKTF_Output(TF_Output* _x){
  K __st[2]; int __stc=0; K __v=(K)1;
  
  K _k=r1(__consts[0]); 
  r0(_k); _k=r1(__consts[107]);  // k:`oper`index - no rval, local
  
  // end of statement
  __v=ki(_x->index); if(0==__v) goto __return;   // C.toK[<val>]
  __st[__stc++]=__v; __v=kj((J)_x->oper); if(0==__v) goto __return;   // C.toK[<val>]
  __v=__enlist(knk(2,__v,__st[__stc-1]));__stc-=1;  if(0==__v) goto __return;   // enlist[<val>;<val>]
  __v=kdot(r1(__consts[55]),knk(2,r1(_k),__v)); if(0==__v) goto __return;   // ![k;<val>]
  goto __return;  // return cmd

 __return:
  r0(_k); 
  while(__stc>0) r0(__st[--__stc]); 
  return __v;
 };
static K __toKTF_AttrMetadata(TF_AttrMetadata* _x){
  K __st[4]; int __stc=0; K __v=(K)1;
  
  K _k=r1(__consts[0]); 
  r0(_k); _k=r1(__consts[115]);  // k:`is_list`list_size`t - no rval, local
  
  // end of statement
  __v=kj((J)_x->total_size); if(0==__v) goto __return;   // C.toK[<val>]
  __st[__stc++]=__v; __v=ki((I)_x->type); if(0==__v) goto __return;   // C.toK[<val>]
  __st[__stc++]=__v; __v=kj((J)_x->list_size); if(0==__v) goto __return;   // C.toK[<val>]
  __st[__stc++]=__v; __v=kc((int)_x->is_list); if(0==__v) goto __return;   // C.toK[<val>]
  __v=__enlist(knk(4,__v,__st[__stc-1],__st[__stc-2],__st[__stc-3]));__stc-=3;  if(0==__v) goto __return;   // enlist[<val>;<val>;<val>;<val>]
  __v=kdot(r1(__consts[55]),knk(2,r1(_k),__v)); if(0==__v) goto __return;   // ![k;<val>]
  goto __return;  // return cmd

 __return:
  r0(_k); 
  while(__stc>0) r0(__st[--__stc]); 
  return __v;
 };
K tf_tf_getBuffer__q(K _x){
  K __st[1]; int __stc=0; K __v=(K)1;
  TF_Buffer* _c_b; char* _c_res; char* _c_src; J _vc_j1; char* _vc_C1; J _c_do1;
  K _l=r1(__consts[0]); K _res=r1(__consts[0]); 
  __v=__K2j_cast(&_vc_j1,r1(_x)); if(0==__v) goto __return; r0(__v);   // `c.j$<val>
  _c_b=(TF_Buffer*)_vc_j1;  // c.b[()]::<val> - no rval, global
  
  // end of statement
  __v=kj((J)_c_b->length); if(0==__v) goto __return;   // C.toK[<val>]
  r0(_l); _l=__v;__v=r1(_l);   // l:<val>
  __v=kdot(r1(__consts[52]),knk(2,__v,r1(__consts[120]))); if(0==__v) goto __return;   // #[<val>;0x00]
  r0(_res); _res=__v;  // res:<val> - no rval, local
  
  // end of statement
  __v=__K2C_cast(&_vc_C1,r1(_res)); if(0==__v) goto __return; r0(__v);   // `c.C$<val>
  _c_res=_vc_C1;  // c.res[()]::_vc_C1 - no rval, global
  
  // end of statement
  _c_src=(char*)(void*)_c_b->data;  // c.src[()]::<val> - no rval, global
  
  // end of statement
  __v=r1(_l);  // local _c_do1
  __v=kif(__v); if(0==__v) goto __return; _c_do1=__v->j; r0(__v);  // check that do value is correct

 __l1:
  if(0>=_c_do1)goto __l3; _c_do1-=1;  // do condition
  _c_res[_c_do1]=_c_src[_c_do1];  // c.res[<val>]::<val> - no rval, global
  
  // end of statement
  goto __l1;  // jump back to do/while

 __l3:
  __v=r1(_res);  // local res
  goto __return;  // return cmd

 __return:
  r0(_l); r0(_res); r0(_x); 
  while(__stc>0) r0(__st[--__stc]); 
  return __v;
 };
K tf_tf_encodeOut__q(K _x){
  K __st[1]; int __stc=0; K __v=(K)1;
  TF_Output* _c_o; char* _vc_C1; J _c_do1; J _vc_j1; I _vc_i1;
  K _r=r1(__consts[0]); K _v=r1(__consts[0]); 
  __v=kj((J)sizeof(TF_Output)); if(0==__v) goto __return;   // C.toK[<val>]
  __st[__stc++]=__v; __v=kdot(r1(__consts[20]),knk(1,r1(_x))); if(0==__v) goto __return;   // count[x]
  __v=kdot(r1(__consts[42]),knk(2,__v,__st[__stc-1]));__stc-=1;  if(0==__v) goto __return;   // *[<val>;<val>]
  __v=kdot(r1(__consts[52]),knk(2,__v,r1(__consts[120]))); if(0==__v) goto __return;   // #[<val>;0x00]
  r0(_r); _r=__v;  // r:<val> - no rval, local
  
  // end of statement
  __v=__K2C_cast(&_vc_C1,r1(_r)); if(0==__v) goto __return; r0(__v);   // `c.C$<val>
  _c_o=(TF_Output*)(void*)_vc_C1;  // c.o[()]::<val> - no rval, global
  
  // end of statement
  __v=kdot(r1(__consts[20]),knk(1,r1(_x))); if(0==__v) goto __return;   // count[x]
  __v=kif(__v); if(0==__v) goto __return; _c_do1=__v->j; r0(__v);  // check that do value is correct

 __l1:
  if(0>=_c_do1)goto __l3; _c_do1-=1;  // do condition
  __v=kj(_c_do1); if(0==__v) goto __return;   // C.toK[c.do1]
  __v=kdot(r1(_x),knk(1,__v)); if(0==__v) goto __return;   // x[<val>]
  r0(_v); _v=__v;  // v:<val> - no rval, local
  
  // end of statement
  __v=kdot(r1(_v),knk(1,r1(__consts[124]))); if(0==__v) goto __return;   // v[`oper]
  __v=__K2j_cast(&_vc_j1,__v); if(0==__v) goto __return; r0(__v);   // `c.j$<val>
  _c_o[_c_do1].oper=(TF_Operation*)_vc_j1;  // c.o[<val>]::<val> - no rval, global
  
  // end of statement
  __v=kdot(r1(_v),knk(1,r1(__consts[125]))); if(0==__v) goto __return;   // v[`index]
  __v=__K2i_cast(&_vc_i1,__v); if(0==__v) goto __return; r0(__v);   // `c.i$<val>
  _c_o[_c_do1].index=_vc_i1;  // c.o[<val>]::_vc_i1 - no rval, global
  
  // end of statement
  goto __l1;  // jump back to do/while

 __l3:
  __v=r1(_r);  // local r
  goto __return;  // return cmd
  r0(__v); 
  // end of statement
  __v=r1(__consts[5]);  // const ::
  goto __return;  // return cmd

 __return:
  r0(_r); r0(_v); r0(_x); 
  while(__stc>0) r0(__st[--__stc]); 
  return __v;
 };
K tf_tf_TF_Version__q(K _x1){
  K __st[1]; int __stc=0; K __v=(K)1;
  const char* _c_res; _Bool _vc_bool1;
  
  _c_res=TF_Version();  // C.TF_Version[::]
  // c.res[()]::<val> - no rval, global
  
  // end of statement
  _vc_bool1=0LL==(J)(void*)_c_res;  // =[0LL;<val>]
  if(0==_vc_bool1) goto __l2;  // if/while check condition
  __v=ki(errno); if(0==__v) goto __return;   // C.toK[C.errno]
  __st[__stc++]=__v; __v=kdot(r1(__consts[26]),knk(1,r1(__glob[17]))); if(0==__v) goto __return;   // global .string.strerror
  __v=kdot(__v,knk(1,__st[__stc-1]));__stc-=1;  if(0==__v) goto __return;   // .string.strerror[<val>]
  __v=kdot(r1(__consts[51]),knk(2,r1(__consts[126]),__v)); if(0==__v) goto __return;   // ,["C.TF_Version: ";<val>]
  __st[__stc++]=__v;  if(__v->t==-KS) __v=krr(__v->s); else if(__v->t==KC)  __v=krr(sn(kC(__v),__v->n)); else __v=krr("stype"); goto __return;  // raise an exception
  r0(__v); 
  // end of statement

 __l2:
  __v=__toKS((char*)_c_res); if(0==__v) goto __return;   // C.toK[<val>]
  goto __return;  // return cmd

 __return:
  r0(_x1); 
  while(__stc>0) r0(__st[--__stc]); 
  return __v;
 };
K tf_tf_TF_DataTypeSize__q(K _x1){
  K __st[1]; int __stc=0; K __v=(K)1;
  size_t _c_res; I _vc_i1;
  
  __v=__K2i_cast(&_vc_i1,r1(_x1)); if(0==__v) goto __return; r0(__v);   // `c.i$<val>
  _c_res=TF_DataTypeSize((TF_DataType)_vc_i1);  // C.TF_DataTypeSize[<val>]
  // c.res[()]::<val> - no rval, global
  
  // end of statement
  __v=kj((J)_c_res); if(0==__v) goto __return;   // C.toK[<val>]
  goto __return;  // return cmd

 __return:
  r0(_x1); 
  while(__stc>0) r0(__st[--__stc]); 
  return __v;
 };
K tf_tf_TF_NewStatus__q(K _x1){
  K __st[1]; int __stc=0; K __v=(K)1;
  TF_Status* _c_res;
  
  _c_res=TF_NewStatus();  // C.TF_NewStatus[::]
  // c.res[()]::<val> - no rval, global
  
  // end of statement
  __v=kj((J)_c_res); if(0==__v) goto __return;   // C.toK[<val>]
  goto __return;  // return cmd

 __return:
  r0(_x1); 
  while(__stc>0) r0(__st[--__stc]); 
  return __v;
 };
K tf_tf_TF_DeleteStatus__q(K _x1){
  K __st[1]; int __stc=0; K __v=(K)1;
  J _vc_j1;
  
  __v=__K2j_cast(&_vc_j1,r1(_x1)); if(0==__v) goto __return; r0(__v);   // `c.j$<val>
  TF_DeleteStatus((TF_Status*)_vc_j1);  // C.TF_DeleteStatus[<val>]
  
  // end of statement
  __v=r1(__consts[5]);  // const ::
  goto __return;  // return cmd

 __return:
  r0(_x1); 
  while(__stc>0) r0(__st[--__stc]); 
  return __v;
 };
K tf_tf_TF_SetStatus__q(K _x1,K _x2,K _x3){
  K __st[1]; int __stc=0; K __v=(K)1;
  char* _vc_S1; I _vc_i2; J _vc_j3;
  
  __v=__K2S_cast(&_vc_S1,r1(_x3)); if(0==__v) goto __return; r0(__v);   // `c.S$<val>
  __v=__K2i_cast(&_vc_i2,r1(_x2)); if(0==__v) goto __return; r0(__v);   // `c.i$<val>
  __v=__K2j_cast(&_vc_j3,r1(_x1)); if(0==__v) goto __return; r0(__v);   // `c.j$<val>
  TF_SetStatus((TF_Status*)_vc_j3,(TF_Code)_vc_i2,_vc_S1);  // C.TF_SetStatus[<val>;<val>;_vc_S1]
  
  // end of statement
  __v=r1(__consts[5]);  // const ::
  goto __return;  // return cmd

 __return:
  r0(_x1); r0(_x2); r0(_x3); 
  while(__stc>0) r0(__st[--__stc]); 
  return __v;
 };
K tf_tf_TF_GetCode__q(K _x1){
  K __st[1]; int __stc=0; K __v=(K)1;
  TF_Code _c_res; J _vc_j1;
  
  __v=__K2j_cast(&_vc_j1,r1(_x1)); if(0==__v) goto __return; r0(__v);   // `c.j$<val>
  _c_res=TF_GetCode((TF_Status*)_vc_j1);  // C.TF_GetCode[<val>]
  // c.res[()]::<val> - no rval, global
  
  // end of statement
  __v=ki((I)_c_res); if(0==__v) goto __return;   // C.toK[<val>]
  goto __return;  // return cmd

 __return:
  r0(_x1); 
  while(__stc>0) r0(__st[--__stc]); 
  return __v;
 };
K tf_tf_TF_Message__q(K _x1){
  K __st[1]; int __stc=0; K __v=(K)1;
  const char* _c_res; J _vc_j1; _Bool _vc_bool1;
  
  __v=__K2j_cast(&_vc_j1,r1(_x1)); if(0==__v) goto __return; r0(__v);   // `c.j$<val>
  _c_res=TF_Message((TF_Status*)_vc_j1);  // C.TF_Message[<val>]
  // c.res[()]::<val> - no rval, global
  
  // end of statement
  _vc_bool1=0LL==(J)(void*)_c_res;  // =[0LL;<val>]
  if(0==_vc_bool1) goto __l2;  // if/while check condition
  __v=ki(errno); if(0==__v) goto __return;   // C.toK[C.errno]
  __st[__stc++]=__v; __v=kdot(r1(__consts[26]),knk(1,r1(__glob[17]))); if(0==__v) goto __return;   // global .string.strerror
  __v=kdot(__v,knk(1,__st[__stc-1]));__stc-=1;  if(0==__v) goto __return;   // .string.strerror[<val>]
  __v=kdot(r1(__consts[51]),knk(2,r1(__consts[127]),__v)); if(0==__v) goto __return;   // ,["C.TF_Message: ";<val>]
  __st[__stc++]=__v;  if(__v->t==-KS) __v=krr(__v->s); else if(__v->t==KC)  __v=krr(sn(kC(__v),__v->n)); else __v=krr("stype"); goto __return;  // raise an exception
  r0(__v); 
  // end of statement

 __l2:
  __v=__toKS((char*)_c_res); if(0==__v) goto __return;   // C.toK[<val>]
  goto __return;  // return cmd

 __return:
  r0(_x1); 
  while(__stc>0) r0(__st[--__stc]); 
  return __v;
 };
K tf_tf_TF_NewBufferFromString__q(K _x1){
  K __st[1]; int __stc=0; K __v=(K)1;
  TF_Buffer* _c_res; J _vc_j1; char* _vc_C2;
  
  __v=kdot(r1(__consts[20]),knk(1,r1(_x1))); if(0==__v) goto __return;   // count[x1]
  __v=__K2j_cast(&_vc_j1,__v); if(0==__v) goto __return; r0(__v);   // `c.j$<val>
  __v=__K2C_cast(&_vc_C2,r1(_x1)); if(0==__v) goto __return; r0(__v);   // `c.C$<val>
  _c_res=TF_NewBufferFromString(_vc_C2,(size_t)(tfc_ij)_vc_j1);  // C.TF_NewBufferFromString[_vc_C2;<val>]
  // c.res[()]::<val> - no rval, global
  
  // end of statement
  __v=kj((J)_c_res); if(0==__v) goto __return;   // C.toK[<val>]
  goto __return;  // return cmd

 __return:
  r0(_x1); 
  while(__stc>0) r0(__st[--__stc]); 
  return __v;
 };
K tf_tf_TF_NewBuffer__q(K _x1){
  K __st[1]; int __stc=0; K __v=(K)1;
  TF_Buffer* _c_res;
  
  _c_res=TF_NewBuffer();  // C.TF_NewBuffer[::]
  // c.res[()]::<val> - no rval, global
  
  // end of statement
  __v=kj((J)_c_res); if(0==__v) goto __return;   // C.toK[<val>]
  goto __return;  // return cmd

 __return:
  r0(_x1); 
  while(__stc>0) r0(__st[--__stc]); 
  return __v;
 };
K tf_tf_TF_DeleteBuffer__q(K _x1){
  K __st[1]; int __stc=0; K __v=(K)1;
  J _vc_j1;
  
  __v=__K2j_cast(&_vc_j1,r1(_x1)); if(0==__v) goto __return; r0(__v);   // `c.j$<val>
  TF_DeleteBuffer((TF_Buffer*)_vc_j1);  // C.TF_DeleteBuffer[<val>]
  
  // end of statement
  __v=r1(__consts[5]);  // const ::
  goto __return;  // return cmd

 __return:
  r0(_x1); 
  while(__stc>0) r0(__st[--__stc]); 
  return __v;
 };
void tf_tf_deallocator(void* _d,size_t _s,void* _a){
  K __st[1]; int __stc=0; K __v=(K)1;
  K _c_v;
  
  _c_v=_a;  // c.v[()]::<val> - no rval, global
  
  // end of statement
  _c_v->r-=1;  // c.v[,`r]-::1 - no rval, global
  
  // end of statement
  __v=r1(__consts[5]);  // const ::
  goto __return;  // return cmd

 __return:
  while(__stc>0) r0(__st[--__stc]); 
  if(0==__v){ PE("exception in tf_tf_deallocator"); exit(1);}; return ;
 };
void* tf_tf_getQPtr(K _data){
  K __st[1]; int __stc=0; K __v=(K)1;
  char* _vc_C1; void* _vc_void_p1; H* _vc_H1; I* _vc_I1; J* _vc_J1; F* _vc_F1; E* _vc_E1; void* __res;
  K _t=r1(__consts[0]); 
  __v=kdot(r1(__consts[25]),knk(1,r1(_data))); if(0==__v) goto __return;   // type[data]
  r0(_t); _t=__v;__v=r1(_t);   // t:<val>
  __v=kdot(r1(__consts[62]),knk(2,__v,r1(__consts[129]))); if(0==__v) goto __return;   // in[<val>;4 10h]
  __v=kif(__v); if(0==__v) goto __return; if(0==__v->j) { r0(__v); goto __l2;}; r0(__v);  // if/while check condition
  __v=__K2C_cast(&_vc_C1,r1(_data)); if(0==__v) goto __return; r0(__v);   // `c.C$<val>
  _vc_void_p1=(void*)_vc_C1;  // `c.void_p$<val>
  goto __l11;  // jmp to if end

 __l2:
  __v=kdot(r1(__consts[47]),knk(2,r1(_t),r1(__consts[130]))); if(0==__v) goto __return;   // =[t;5]
  __v=kif(__v); if(0==__v) goto __return; if(0==__v->j) { r0(__v); goto __l4;}; r0(__v);  // if/while check condition
  __v=__K2H_cast(&_vc_H1,r1(_data)); if(0==__v) goto __return; r0(__v);   // `c.H$<val>
  _vc_void_p1=(void*)_vc_H1;  // `c.void_p$<val>
  goto __l11;  // jmp to if end

 __l4:
  __v=kdot(r1(__consts[47]),knk(2,r1(_t),r1(__consts[131]))); if(0==__v) goto __return;   // =[t;6]
  __v=kif(__v); if(0==__v) goto __return; if(0==__v->j) { r0(__v); goto __l6;}; r0(__v);  // if/while check condition
  __v=__K2I_cast(&_vc_I1,r1(_data)); if(0==__v) goto __return; r0(__v);   // `c.I$<val>
  _vc_void_p1=(void*)_vc_I1;  // `c.void_p$<val>
  goto __l11;  // jmp to if end

 __l6:
  __v=kdot(r1(__consts[47]),knk(2,r1(_t),r1(__consts[132]))); if(0==__v) goto __return;   // =[t;7]
  __v=kif(__v); if(0==__v) goto __return; if(0==__v->j) { r0(__v); goto __l8;}; r0(__v);  // if/while check condition
  __v=__K2J_cast(&_vc_J1,r1(_data)); if(0==__v) goto __return; r0(__v);   // `c.J$<val>
  _vc_void_p1=(void*)_vc_J1;  // `c.void_p$<val>
  goto __l11;  // jmp to if end

 __l8:
  __v=kdot(r1(__consts[47]),knk(2,r1(_t),r1(__consts[133]))); if(0==__v) goto __return;   // =[t;9]
  __v=kif(__v); if(0==__v) goto __return; if(0==__v->j) { r0(__v); goto __l10;}; r0(__v);  // if/while check condition
  __v=__K2F_cast(&_vc_F1,r1(_data)); if(0==__v) goto __return; r0(__v);   // `c.F$<val>
  _vc_void_p1=(void*)_vc_F1;  // `c.void_p$<val>
  goto __l11;  // jmp to if end

 __l10:
  __v=__K2E_cast(&_vc_E1,r1(_data)); if(0==__v) goto __return; r0(__v);   // `c.E$<val>
  _vc_void_p1=(void*)_vc_E1;  // `c.void_p$<val>

 __l11:
  __res=_vc_void_p1; goto __return;  // return cmd

 __return:
  r0(_t); r0(_data); 
  while(__stc>0) r0(__st[--__stc]); 
  if(0==__v){ PE("exception in tf_tf_getQPtr"); exit(1);}; return __res;
 };
K tf_tf_TF_NewTensor__q(K _dt,K _dims,K _data){
  K __st[1]; int __stc=0; K __v=(K)1;
  void* _c_dt; K _c_d; J _vc_j3; I _vc_i5; J* _vc_J6; I _vc_i7; TF_Tensor* _vc_TF_Tensor_p1;
  K _t=r1(__consts[0]); K _sz=r1(__consts[0]); K _r=r1(__consts[0]); 
  __v=kdot(r1(__consts[25]),knk(1,r1(_data))); if(0==__v) goto __return;   // type[data]
  r0(_t); _t=__v;__v=r1(_t);   // t:<val>
  __v=kdot(r1(__consts[134]),knk(1,__v)); if(0==__v) goto __return;   // 4 5 6 7 8 9 10h!1 2 [<val>]
  r0(_sz); _sz=__v;__v=r1(_sz);   // sz:<val>
  __v=kdot(r1(__consts[14]),knk(1,__v)); if(0==__v) goto __return;   // null[<val>]
  __v=kif(__v); if(0==__v) goto __return; if(0==__v->j) { r0(__v); goto __l2;}; r0(__v);  // if/while check condition
  __v=r1(__consts[135]);  // const "TF_NewTensor: unsup
  __st[__stc++]=__v;  if(__v->t==-KS) __v=krr(__v->s); else if(__v->t==KC)  __v=krr(sn(kC(__v),__v->n)); else __v=krr("stype"); goto __return;  // raise an exception
  r0(__v); 
  // end of statement

 __l2:
  _c_dt=tf_tf_getQPtr(r1(_data));  // .tf.getQPtr[data]
  // c.dt[()]::<val> - no rval, global
  
  // end of statement
  _c_d=_data;  // c.d[()]::<val> - no rval, global
  
  // end of statement
  __v=kdot(r1(__consts[20]),knk(1,r1(_data))); if(0==__v) goto __return;   // count[data]
  __v=kdot(r1(__consts[42]),knk(2,r1(_sz),__v)); if(0==__v) goto __return;   // *[sz;<val>]
  __v=__K2j_cast(&_vc_j3,__v); if(0==__v) goto __return; r0(__v);   // `c.j$<val>
  __v=kdot(r1(__consts[20]),knk(1,r1(_dims))); if(0==__v) goto __return;   // count[dims]
  __v=kdot(r1(__consts[50]),knk(2,r1(__consts[136]),__v)); if(0==__v) goto __return;   // $["i";<val>]
  __v=__K2i_cast(&_vc_i5,__v); if(0==__v) goto __return; r0(__v);   // `c.i$<val>
  __v=__K2J_cast(&_vc_J6,r1(_dims)); if(0==__v) goto __return; r0(__v);   // `c.J$<val>
  __v=__K2i_cast(&_vc_i7,r1(_dt)); if(0==__v) goto __return; r0(__v);   // `c.i$<val>
  _vc_TF_Tensor_p1=TF_NewTensor((TF_DataType)_vc_i7,(long*)_vc_J6,_vc_i5,_c_dt,(size_t)_vc_j3,&tf_tf_deallocator,(void*)_c_d);  // C.TF_NewTensor[<val>;<val>;_vc_i5;c.dt;<val>;<val>;<val>]
  __v=kj((J)_vc_TF_Tensor_p1); if(0==__v) goto __return;   // C.toK[<val>]
  r0(_r); _r=__v;  // r:<val> - no rval, local
  
  // end of statement
  __v=kdot(r1(__consts[105]),knk(2,r1(_r),r1(__consts[1]))); if(0==__v) goto __return;   // ~=[r;0]
  __v=kif(__v); if(0==__v) goto __return; if(0==__v->j) { r0(__v); goto __l4;}; r0(__v);  // if/while check condition
  _c_d->r+=1;  // c.d[,`r]+::1 - no rval, global
  
  // end of statement

 __l4:
  __v=r1(_r);  // local r
  goto __return;  // return cmd
  r0(__v); 
  // end of statement
  __v=r1(__consts[5]);  // const ::
  goto __return;  // return cmd

 __return:
  r0(_t); r0(_sz); r0(_r); r0(_dt); r0(_dims); r0(_data); 
  while(__stc>0) r0(__st[--__stc]); 
  return __v;
 };
K tf_tf_TF_AllocateTensor__q(K _x1,K _x2,K _x4){
  K __st[1]; int __stc=0; K __v=(K)1;
  TF_Tensor* _c_res; J _vc_j1; J _vc_j2; J* _vc_J3; I _vc_i4;
  
  __v=__K2j_cast(&_vc_j1,r1(_x4)); if(0==__v) goto __return; r0(__v);   // `c.j$<val>
  __v=kdot(r1(__consts[20]),knk(1,r1(_x2))); if(0==__v) goto __return;   // count[x2]
  __v=__K2j_cast(&_vc_j2,__v); if(0==__v) goto __return; r0(__v);   // `c.j$<val>
  __v=__K2J_cast(&_vc_J3,r1(_x2)); if(0==__v) goto __return; r0(__v);   // `c.J$<val>
  __v=__K2i_cast(&_vc_i4,r1(_x1)); if(0==__v) goto __return; r0(__v);   // `c.i$<val>
  _c_res=TF_AllocateTensor((TF_DataType)_vc_i4,(long*)_vc_J3,(I)(tfc_ij)_vc_j2,(size_t)_vc_j1);  // C.TF_AllocateTensor[<val>;<val>;<val>;<val>]
  // c.res[()]::<val> - no rval, global
  
  // end of statement
  __v=kj((J)_c_res); if(0==__v) goto __return;   // C.toK[<val>]
  goto __return;  // return cmd

 __return:
  r0(_x1); r0(_x2); r0(_x4); 
  while(__stc>0) r0(__st[--__stc]); 
  return __v;
 };
K tf_tf_TF_TensorMaybeMove__q(K _x1){
  K __st[1]; int __stc=0; K __v=(K)1;
  TF_Tensor* _c_res; J _vc_j1;
  
  __v=__K2j_cast(&_vc_j1,r1(_x1)); if(0==__v) goto __return; r0(__v);   // `c.j$<val>
  _c_res=TF_TensorMaybeMove((TF_Tensor*)_vc_j1);  // C.TF_TensorMaybeMove[<val>]
  // c.res[()]::<val> - no rval, global
  
  // end of statement
  __v=kj((J)_c_res); if(0==__v) goto __return;   // C.toK[<val>]
  goto __return;  // return cmd

 __return:
  r0(_x1); 
  while(__stc>0) r0(__st[--__stc]); 
  return __v;
 };
K tf_tf_TF_DeleteTensor__q(K _x1){
  K __st[1]; int __stc=0; K __v=(K)1;
  J _vc_j1;
  
  __v=__K2j_cast(&_vc_j1,r1(_x1)); if(0==__v) goto __return; r0(__v);   // `c.j$<val>
  TF_DeleteTensor((TF_Tensor*)_vc_j1);  // C.TF_DeleteTensor[<val>]
  
  // end of statement
  __v=r1(__consts[5]);  // const ::
  goto __return;  // return cmd

 __return:
  r0(_x1); 
  while(__stc>0) r0(__st[--__stc]); 
  return __v;
 };
K tf_tf_TF_TensorType__q(K _x1){
  K __st[1]; int __stc=0; K __v=(K)1;
  TF_DataType _c_res; J _vc_j1;
  
  __v=__K2j_cast(&_vc_j1,r1(_x1)); if(0==__v) goto __return; r0(__v);   // `c.j$<val>
  _c_res=TF_TensorType((TF_Tensor*)_vc_j1);  // C.TF_TensorType[<val>]
  // c.res[()]::<val> - no rval, global
  
  // end of statement
  __v=ki((I)_c_res); if(0==__v) goto __return;   // C.toK[<val>]
  goto __return;  // return cmd

 __return:
  r0(_x1); 
  while(__stc>0) r0(__st[--__stc]); 
  return __v;
 };
K tf_tf_TF_NumDims__q(K _x1){
  K __st[1]; int __stc=0; K __v=(K)1;
  I _c_res; J _vc_j1;
  
  __v=__K2j_cast(&_vc_j1,r1(_x1)); if(0==__v) goto __return; r0(__v);   // `c.j$<val>
  _c_res=TF_NumDims((TF_Tensor*)_vc_j1);  // C.TF_NumDims[<val>]
  // c.res[()]::<val> - no rval, global
  
  // end of statement
  __v=ki(_c_res); if(0==__v) goto __return;   // C.toK[c.res]
  goto __return;  // return cmd

 __return:
  r0(_x1); 
  while(__stc>0) r0(__st[--__stc]); 
  return __v;
 };
K tf_tf_TF_Dim__q(K _x1,K _x2){
  K __st[1]; int __stc=0; K __v=(K)1;
  J _c_res; I _vc_i1; J _vc_j2;
  
  __v=__K2i_cast(&_vc_i1,r1(_x2)); if(0==__v) goto __return; r0(__v);   // `c.i$<val>
  __v=__K2j_cast(&_vc_j2,r1(_x1)); if(0==__v) goto __return; r0(__v);   // `c.j$<val>
  _c_res=TF_Dim((TF_Tensor*)_vc_j2,_vc_i1);  // C.TF_Dim[<val>;_vc_i1]
  // c.res[()]::<val> - no rval, global
  
  // end of statement
  __v=kj(_c_res); if(0==__v) goto __return;   // C.toK[c.res]
  goto __return;  // return cmd

 __return:
  r0(_x1); r0(_x2); 
  while(__stc>0) r0(__st[--__stc]); 
  return __v;
 };
K tf_tf_TF_TensorByteSize__q(K _x1){
  K __st[1]; int __stc=0; K __v=(K)1;
  size_t _c_res; J _vc_j1;
  
  __v=__K2j_cast(&_vc_j1,r1(_x1)); if(0==__v) goto __return; r0(__v);   // `c.j$<val>
  _c_res=TF_TensorByteSize((TF_Tensor*)_vc_j1);  // C.TF_TensorByteSize[<val>]
  // c.res[()]::<val> - no rval, global
  
  // end of statement
  __v=kj((J)_c_res); if(0==__v) goto __return;   // C.toK[<val>]
  goto __return;  // return cmd

 __return:
  r0(_x1); 
  while(__stc>0) r0(__st[--__stc]); 
  return __v;
 };
K tf_tf_TF_TensorData__q(K _x1){
  K __st[1]; int __stc=0; K __v=(K)1;
  void* _c_res; J _vc_j1;
  
  __v=__K2j_cast(&_vc_j1,r1(_x1)); if(0==__v) goto __return; r0(__v);   // `c.j$<val>
  _c_res=TF_TensorData((TF_Tensor*)_vc_j1);  // C.TF_TensorData[<val>]
  // c.res[()]::<val> - no rval, global
  
  // end of statement
  __v=kj((J)_c_res); if(0==__v) goto __return;   // C.toK[<val>]
  goto __return;  // return cmd

 __return:
  r0(_x1); 
  while(__stc>0) r0(__st[--__stc]); 
  return __v;
 };
K tf_tf_writeToTensor__q(K _ptr,K _data){
  K __st[2]; int __stc=0; K __v=(K)1;
  char* _c_t; char* _c_d; J _vc_j1; void* _vc_void_p1; J _c_do1;
  
  __v=__K2j_cast(&_vc_j1,r1(_ptr)); if(0==__v) goto __return; r0(__v);   // `c.j$<val>
  _c_t=(char*)(void*)_vc_j1;  // c.t[()]::<val> - no rval, global
  
  // end of statement
  _vc_void_p1=tf_tf_getQPtr(r1(_data));  // .tf.getQPtr[data]
  _c_d=(char*)_vc_void_p1;  // c.d[()]::<val> - no rval, global
  
  // end of statement
  __v=kdot(r1(__consts[20]),knk(1,r1(_data))); if(0==__v) goto __return;   // count[data]
  __st[__stc++]=__v; __v=kdot(r1(__consts[25]),knk(1,r1(_data))); if(0==__v) goto __return;   // type[data]
  __v=kdot(r1(__consts[134]),knk(1,__v)); if(0==__v) goto __return;   // 4 5 6 7 8 9 10h!1 2 [<val>]
  __v=kdot(r1(__consts[42]),knk(2,__v,__st[__stc-1]));__stc-=1;  if(0==__v) goto __return;   // *[<val>;<val>]
  __v=kif(__v); if(0==__v) goto __return; _c_do1=__v->j; r0(__v);  // check that do value is correct

 __l1:
  if(0>=_c_do1)goto __l3; _c_do1-=1;  // do condition
  _c_t[_c_do1]=_c_d[_c_do1];  // c.t[<val>]::<val> - no rval, global
  
  // end of statement
  goto __l1;  // jump back to do/while

 __l3:
  __v=r1(__consts[5]);  // const ::
  goto __return;  // return cmd

 __return:
  r0(_ptr); r0(_data); 
  while(__stc>0) r0(__st[--__stc]); 
  return __v;
 };
K tf_tf_readFromTensor__q(K _ptr,K _data){
  K __st[2]; int __stc=0; K __v=(K)1;
  char* _c_t; char* _c_d; J _vc_j1; void* _vc_void_p1; J _c_do1;
  
  __v=__K2j_cast(&_vc_j1,r1(_ptr)); if(0==__v) goto __return; r0(__v);   // `c.j$<val>
  _c_t=(char*)(void*)_vc_j1;  // c.t[()]::<val> - no rval, global
  
  // end of statement
  _vc_void_p1=tf_tf_getQPtr(r1(_data));  // .tf.getQPtr[data]
  _c_d=(char*)_vc_void_p1;  // c.d[()]::<val> - no rval, global
  
  // end of statement
  __v=kdot(r1(__consts[20]),knk(1,r1(_data))); if(0==__v) goto __return;   // count[data]
  __st[__stc++]=__v; __v=kdot(r1(__consts[25]),knk(1,r1(_data))); if(0==__v) goto __return;   // type[data]
  __v=kdot(r1(__consts[134]),knk(1,__v)); if(0==__v) goto __return;   // 4 5 6 7 8 9 10h!1 2 [<val>]
  __v=kdot(r1(__consts[42]),knk(2,__v,__st[__stc-1]));__stc-=1;  if(0==__v) goto __return;   // *[<val>;<val>]
  __v=kif(__v); if(0==__v) goto __return; _c_do1=__v->j; r0(__v);  // check that do value is correct

 __l1:
  if(0>=_c_do1)goto __l3; _c_do1-=1;  // do condition
  _c_d[_c_do1]=_c_t[_c_do1];  // c.d[<val>]::<val> - no rval, global
  
  // end of statement
  goto __l1;  // jump back to do/while

 __l3:
  __v=r1(_data);  // arg data
  goto __return;  // return cmd
  r0(__v); 
  // end of statement
  __v=r1(__consts[5]);  // const ::
  goto __return;  // return cmd

 __return:
  r0(_ptr); r0(_data); 
  while(__stc>0) r0(__st[--__stc]); 
  return __v;
 };
K tf_tf_TF_StringEncode__q(K _x1,K _x3,K _x4,K _x5){
  K __st[1]; int __stc=0; K __v=(K)1;
  size_t _c_res; J _vc_j1; J _vc_j2; J _vc_j3; J _vc_j4; char* _vc_C5;
  
  __v=__K2j_cast(&_vc_j1,r1(_x5)); if(0==__v) goto __return; r0(__v);   // `c.j$<val>
  __v=__K2j_cast(&_vc_j2,r1(_x4)); if(0==__v) goto __return; r0(__v);   // `c.j$<val>
  __v=__K2j_cast(&_vc_j3,r1(_x3)); if(0==__v) goto __return; r0(__v);   // `c.j$<val>
  __v=kdot(r1(__consts[20]),knk(1,r1(_x1))); if(0==__v) goto __return;   // count[x1]
  __v=__K2j_cast(&_vc_j4,__v); if(0==__v) goto __return; r0(__v);   // `c.j$<val>
  __v=__K2C_cast(&_vc_C5,r1(_x1)); if(0==__v) goto __return; r0(__v);   // `c.C$<val>
  _c_res=TF_StringEncode(_vc_C5,(size_t)(tfc_ij)_vc_j4,(char*)_vc_j3,(size_t)_vc_j2,(TF_Status*)_vc_j1);  // C.TF_StringEncode[_vc_C5;<val>;<val>;<val>;<val>]
  // c.res[()]::<val> - no rval, global
  
  // end of statement
  __v=kj((J)_c_res); if(0==__v) goto __return;   // C.toK[<val>]
  goto __return;  // return cmd

 __return:
  r0(_x1); r0(_x3); r0(_x4); r0(_x5); 
  while(__stc>0) r0(__st[--__stc]); 
  return __v;
 };
K tf_tf_TF_StringDecode__q(K _src,K _sz,K _st){
  K __st[1]; int __stc=0; K __v=(K)1;
  size_t _c_r; size_t _c_l; const char* _c_dst; J _vc_j1; J _vc_j4; J _vc_j5; _Bool _vc_bool1;
  
  __v=__K2j_cast(&_vc_j1,r1(_st)); if(0==__v) goto __return; r0(__v);   // `c.j$<val>
  __v=__K2j_cast(&_vc_j4,r1(_sz)); if(0==__v) goto __return; r0(__v);   // `c.j$<val>
  __v=__K2j_cast(&_vc_j5,r1(_src)); if(0==__v) goto __return; r0(__v);   // `c.j$<val>
  _c_r=TF_StringDecode((char*)_vc_j5,(size_t)_vc_j4,&_c_dst,&_c_l,(TF_Status*)_vc_j1);  // C.TF_StringDecode[<val>;<val>;<val>;<val>;<val>]
  // c.r[()]::<val> - no rval, global
  
  // end of statement
  _vc_bool1=0LL==(J)_c_r;  // =[0LL;<val>]
  if(0==_vc_bool1) goto __l3;  // if/while check condition
  __v=r1(__consts[137]);  // const ""
  goto __return;  // return cmd
  r0(__v); 
  // end of statement

 __l3:
  __v=__toKC((char*)_c_dst,(J)_c_l); if(0==__v) goto __return;   // C.toK[<val>;<val>]
  goto __return;  // return cmd
  r0(__v); 
  // end of statement
  __v=r1(__consts[5]);  // const ::
  goto __return;  // return cmd

 __return:
  r0(_src); r0(_sz); r0(_st); 
  while(__stc>0) r0(__st[--__stc]); 
  return __v;
 };
K tf_tf_TF_StringEncodedSize__q(K _x1){
  K __st[1]; int __stc=0; K __v=(K)1;
  size_t _c_res; J _vc_j1;
  
  __v=__K2j_cast(&_vc_j1,r1(_x1)); if(0==__v) goto __return; r0(__v);   // `c.j$<val>
  _c_res=TF_StringEncodedSize((size_t)_vc_j1);  // C.TF_StringEncodedSize[<val>]
  // c.res[()]::<val> - no rval, global
  
  // end of statement
  __v=kj((J)_c_res); if(0==__v) goto __return;   // C.toK[<val>]
  goto __return;  // return cmd

 __return:
  r0(_x1); 
  while(__stc>0) r0(__st[--__stc]); 
  return __v;
 };
K tf_tf_TF_NewSessionOptions__q(K _x1){
  K __st[1]; int __stc=0; K __v=(K)1;
  TF_SessionOptions* _c_res;
  
  _c_res=TF_NewSessionOptions();  // C.TF_NewSessionOptions[::]
  // c.res[()]::<val> - no rval, global
  
  // end of statement
  __v=kj((J)_c_res); if(0==__v) goto __return;   // C.toK[<val>]
  goto __return;  // return cmd

 __return:
  r0(_x1); 
  while(__stc>0) r0(__st[--__stc]); 
  return __v;
 };
K tf_tf_TF_SetTarget__q(K _x1,K _x2){
  K __st[1]; int __stc=0; K __v=(K)1;
  char* _vc_S1; J _vc_j2;
  
  __v=__K2S_cast(&_vc_S1,r1(_x2)); if(0==__v) goto __return; r0(__v);   // `c.S$<val>
  __v=__K2j_cast(&_vc_j2,r1(_x1)); if(0==__v) goto __return; r0(__v);   // `c.j$<val>
  TF_SetTarget((TF_SessionOptions*)_vc_j2,_vc_S1);  // C.TF_SetTarget[<val>;_vc_S1]
  
  // end of statement
  __v=r1(__consts[5]);  // const ::
  goto __return;  // return cmd

 __return:
  r0(_x1); r0(_x2); 
  while(__stc>0) r0(__st[--__stc]); 
  return __v;
 };
K tf_tf_TF_SetConfig__q(K _x1,K _x2,K _x4){
  K __st[1]; int __stc=0; K __v=(K)1;
  J _vc_j1; J _vc_j2; char* _vc_C3; J _vc_j4;
  
  __v=__K2j_cast(&_vc_j1,r1(_x4)); if(0==__v) goto __return; r0(__v);   // `c.j$<val>
  __v=kdot(r1(__consts[20]),knk(1,r1(_x2))); if(0==__v) goto __return;   // count[x2]
  __v=__K2j_cast(&_vc_j2,__v); if(0==__v) goto __return; r0(__v);   // `c.j$<val>
  __v=__K2C_cast(&_vc_C3,r1(_x2)); if(0==__v) goto __return; r0(__v);   // `c.C$<val>
  __v=__K2j_cast(&_vc_j4,r1(_x1)); if(0==__v) goto __return; r0(__v);   // `c.j$<val>
  TF_SetConfig((TF_SessionOptions*)_vc_j4,_vc_C3,(size_t)(tfc_ij)_vc_j2,(TF_Status*)_vc_j1);  // C.TF_SetConfig[<val>;_vc_C3;<val>;<val>]
  
  // end of statement
  __v=r1(__consts[5]);  // const ::
  goto __return;  // return cmd

 __return:
  r0(_x1); r0(_x2); r0(_x4); 
  while(__stc>0) r0(__st[--__stc]); 
  return __v;
 };
K tf_tf_TF_DeleteSessionOptions__q(K _x1){
  K __st[1]; int __stc=0; K __v=(K)1;
  J _vc_j1;
  
  __v=__K2j_cast(&_vc_j1,r1(_x1)); if(0==__v) goto __return; r0(__v);   // `c.j$<val>
  TF_DeleteSessionOptions((TF_SessionOptions*)_vc_j1);  // C.TF_DeleteSessionOptions[<val>]
  
  // end of statement
  __v=r1(__consts[5]);  // const ::
  goto __return;  // return cmd

 __return:
  r0(_x1); 
  while(__stc>0) r0(__st[--__stc]); 
  return __v;
 };
K tf_tf_TF_NewGraph__q(K _x1){
  K __st[1]; int __stc=0; K __v=(K)1;
  TF_Graph* _c_res;
  
  _c_res=TF_NewGraph();  // C.TF_NewGraph[::]
  // c.res[()]::<val> - no rval, global
  
  // end of statement
  __v=kj((J)_c_res); if(0==__v) goto __return;   // C.toK[<val>]
  goto __return;  // return cmd

 __return:
  r0(_x1); 
  while(__stc>0) r0(__st[--__stc]); 
  return __v;
 };
K tf_tf_TF_DeleteGraph__q(K _x1){
  K __st[1]; int __stc=0; K __v=(K)1;
  J _vc_j1;
  
  __v=__K2j_cast(&_vc_j1,r1(_x1)); if(0==__v) goto __return; r0(__v);   // `c.j$<val>
  TF_DeleteGraph((TF_Graph*)_vc_j1);  // C.TF_DeleteGraph[<val>]
  
  // end of statement
  __v=r1(__consts[5]);  // const ::
  goto __return;  // return cmd

 __return:
  r0(_x1); 
  while(__stc>0) r0(__st[--__stc]); 
  return __v;
 };
K tf_tf_TF_GraphSetTensorShape__q(K _x1,K _x2,K _x3,K _x5){
  K __st[1]; int __stc=0; K __v=(K)1;
  J _vc_j1; J _vc_j2; J* _vc_J3; TF_Output _vc_TF_Output4; J _vc_j5;
  
  __v=__K2j_cast(&_vc_j1,r1(_x5)); if(0==__v) goto __return; r0(__v);   // `c.j$<val>
  __v=kdot(r1(__consts[20]),knk(1,r1(_x3))); if(0==__v) goto __return;   // count[x3]
  __v=__K2j_cast(&_vc_j2,__v); if(0==__v) goto __return; r0(__v);   // `c.j$<val>
  __v=__K2J_cast(&_vc_J3,r1(_x3)); if(0==__v) goto __return; r0(__v);   // `c.J$<val>
  __v=__K2TF_Output_cast(&_vc_TF_Output4,r1(_x2)); if(0==__v) goto __return; r0(__v);   // `c.TF_Output$<val>
  __v=__K2j_cast(&_vc_j5,r1(_x1)); if(0==__v) goto __return; r0(__v);   // `c.j$<val>
  TF_GraphSetTensorShape((TF_Graph*)_vc_j5,_vc_TF_Output4,(long*)_vc_J3,(I)(tfc_ij)_vc_j2,(TF_Status*)_vc_j1);  // C.TF_GraphSetTensorShape[<val>;_vc_TF_Output4;<val>;<val>;<val>]
  
  // end of statement
  __v=r1(__consts[5]);  // const ::
  goto __return;  // return cmd

 __return:
  r0(_x1); r0(_x2); r0(_x3); r0(_x5); 
  while(__stc>0) r0(__st[--__stc]); 
  return __v;
 };
K tf_tf_TF_GraphGetTensorNumDims__q(K _x1,K _x2,K _x3){
  K __st[1]; int __stc=0; K __v=(K)1;
  I _c_res; J _vc_j1; TF_Output _vc_TF_Output2; J _vc_j3;
  
  __v=__K2j_cast(&_vc_j1,r1(_x3)); if(0==__v) goto __return; r0(__v);   // `c.j$<val>
  __v=__K2TF_Output_cast(&_vc_TF_Output2,r1(_x2)); if(0==__v) goto __return; r0(__v);   // `c.TF_Output$<val>
  __v=__K2j_cast(&_vc_j3,r1(_x1)); if(0==__v) goto __return; r0(__v);   // `c.j$<val>
  _c_res=TF_GraphGetTensorNumDims((TF_Graph*)_vc_j3,_vc_TF_Output2,(TF_Status*)_vc_j1);  // C.TF_GraphGetTensorNumDims[<val>;_vc_TF_Output2;<val>]
  // c.res[()]::<val> - no rval, global
  
  // end of statement
  __v=ki(_c_res); if(0==__v) goto __return;   // C.toK[c.res]
  goto __return;  // return cmd

 __return:
  r0(_x1); r0(_x2); r0(_x3); 
  while(__stc>0) r0(__st[--__stc]); 
  return __v;
 };
K tf_tf_TF_GraphGetTensorShape__q(K _x1,K _x2,K _x3,K _x5){
  K __st[1]; int __stc=0; K __v=(K)1;
  J _vc_j1; J _vc_j2; J* _vc_J3; TF_Output _vc_TF_Output4; J _vc_j5;
  
  __v=__K2j_cast(&_vc_j1,r1(_x5)); if(0==__v) goto __return; r0(__v);   // `c.j$<val>
  __v=kdot(r1(__consts[20]),knk(1,r1(_x3))); if(0==__v) goto __return;   // count[x3]
  __v=__K2j_cast(&_vc_j2,__v); if(0==__v) goto __return; r0(__v);   // `c.j$<val>
  __v=__K2J_cast(&_vc_J3,r1(_x3)); if(0==__v) goto __return; r0(__v);   // `c.J$<val>
  __v=__K2TF_Output_cast(&_vc_TF_Output4,r1(_x2)); if(0==__v) goto __return; r0(__v);   // `c.TF_Output$<val>
  __v=__K2j_cast(&_vc_j5,r1(_x1)); if(0==__v) goto __return; r0(__v);   // `c.j$<val>
  TF_GraphGetTensorShape((TF_Graph*)_vc_j5,_vc_TF_Output4,(long*)_vc_J3,(I)(tfc_ij)_vc_j2,(TF_Status*)_vc_j1);  // C.TF_GraphGetTensorShape[<val>;_vc_TF_Output4;<val>;<val>;<val>]
  
  // end of statement
  __v=r1(__consts[5]);  // const ::
  goto __return;  // return cmd

 __return:
  r0(_x1); r0(_x2); r0(_x3); r0(_x5); 
  while(__stc>0) r0(__st[--__stc]); 
  return __v;
 };
K tf_tf_TF_NewOperation__q(K _x1,K _x2,K _x3){
  K __st[1]; int __stc=0; K __v=(K)1;
  TF_OperationDescription* _c_res; char* _vc_S1; char* _vc_S2; J _vc_j3;
  
  __v=__K2S_cast(&_vc_S1,r1(_x3)); if(0==__v) goto __return; r0(__v);   // `c.S$<val>
  __v=__K2S_cast(&_vc_S2,r1(_x2)); if(0==__v) goto __return; r0(__v);   // `c.S$<val>
  __v=__K2j_cast(&_vc_j3,r1(_x1)); if(0==__v) goto __return; r0(__v);   // `c.j$<val>
  _c_res=TF_NewOperation((TF_Graph*)_vc_j3,_vc_S2,_vc_S1);  // C.TF_NewOperation[<val>;_vc_S2;_vc_S1]
  // c.res[()]::<val> - no rval, global
  
  // end of statement
  __v=kj((J)_c_res); if(0==__v) goto __return;   // C.toK[<val>]
  goto __return;  // return cmd

 __return:
  r0(_x1); r0(_x2); r0(_x3); 
  while(__stc>0) r0(__st[--__stc]); 
  return __v;
 };
K tf_tf_TF_SetDevice__q(K _x1,K _x2){
  K __st[1]; int __stc=0; K __v=(K)1;
  char* _vc_S1; J _vc_j2;
  
  __v=__K2S_cast(&_vc_S1,r1(_x2)); if(0==__v) goto __return; r0(__v);   // `c.S$<val>
  __v=__K2j_cast(&_vc_j2,r1(_x1)); if(0==__v) goto __return; r0(__v);   // `c.j$<val>
  TF_SetDevice((TF_OperationDescription*)_vc_j2,_vc_S1);  // C.TF_SetDevice[<val>;_vc_S1]
  
  // end of statement
  __v=r1(__consts[5]);  // const ::
  goto __return;  // return cmd

 __return:
  r0(_x1); r0(_x2); 
  while(__stc>0) r0(__st[--__stc]); 
  return __v;
 };
K tf_tf_TF_AddInput__q(K _x1,K _x2){
  K __st[1]; int __stc=0; K __v=(K)1;
  TF_Output _vc_TF_Output1; J _vc_j2;
  
  __v=__K2TF_Output_cast(&_vc_TF_Output1,r1(_x2)); if(0==__v) goto __return; r0(__v);   // `c.TF_Output$<val>
  __v=__K2j_cast(&_vc_j2,r1(_x1)); if(0==__v) goto __return; r0(__v);   // `c.j$<val>
  TF_AddInput((TF_OperationDescription*)_vc_j2,_vc_TF_Output1);  // C.TF_AddInput[<val>;_vc_TF_Output1]
  
  // end of statement
  __v=r1(__consts[5]);  // const ::
  goto __return;  // return cmd

 __return:
  r0(_x1); r0(_x2); 
  while(__stc>0) r0(__st[--__stc]); 
  return __v;
 };
K tf_tf_TF_AddInputList__q(K _op,K _out){
  K __st[1]; int __stc=0; K __v=(K)1;
  I _vc_i1; char* _vc_C2; J _vc_j3;
  K _v=r1(__consts[0]); 
  __v=kdot(r1(__consts[25]),knk(1,r1(_out))); if(0==__v) goto __return;   // type[out]
  __v=kdot(r1(__consts[47]),knk(2,r1(__consts[138]),__v)); if(0==__v) goto __return;   // =[98;<val>]
  __v=kdot(r1(__consts[22]),knk(1,__v)); if(0==__v) goto __return;   // not[<val>]
  __v=kif(__v); if(0==__v) goto __return; if(0==__v->j) { r0(__v); goto __l2;}; r0(__v);  // if/while check condition
  __v=r1(__consts[139]);  // const "TF_AddInputList: ty
  __st[__stc++]=__v;  if(__v->t==-KS) __v=krr(__v->s); else if(__v->t==KC)  __v=krr(sn(kC(__v),__v->n)); else __v=krr("stype"); goto __return;  // raise an exception
  r0(__v); 
  // end of statement

 __l2:
  __v=tf_tf_encodeOut__q(r1(_out)); if(0==__v) goto __return;   // .tf.encodeOut[out]
  r0(_v); _v=__v;  // v:<val> - no rval, local
  
  // end of statement
  __v=kdot(r1(__consts[20]),knk(1,r1(_out))); if(0==__v) goto __return;   // count[out]
  __v=kdot(r1(__consts[50]),knk(2,r1(__consts[136]),__v)); if(0==__v) goto __return;   // $["i";<val>]
  __v=__K2i_cast(&_vc_i1,__v); if(0==__v) goto __return; r0(__v);   // `c.i$<val>
  __v=__K2C_cast(&_vc_C2,r1(_v)); if(0==__v) goto __return; r0(__v);   // `c.C$<val>
  __v=__K2j_cast(&_vc_j3,r1(_op)); if(0==__v) goto __return; r0(__v);   // `c.j$<val>
  TF_AddInputList((TF_OperationDescription*)_vc_j3,(TF_Output*)(void*)_vc_C2,_vc_i1);  // C.TF_AddInputList[<val>;<val>;_vc_i1]
  
  // end of statement
  __v=r1(__consts[5]);  // const ::
  goto __return;  // return cmd

 __return:
  r0(_v); r0(_op); r0(_out); 
  while(__stc>0) r0(__st[--__stc]); 
  return __v;
 };
K tf_tf_TF_AddControlInput__q(K _x1,K _x2){
  K __st[1]; int __stc=0; K __v=(K)1;
  J _vc_j1; J _vc_j2;
  
  __v=__K2j_cast(&_vc_j1,r1(_x2)); if(0==__v) goto __return; r0(__v);   // `c.j$<val>
  __v=__K2j_cast(&_vc_j2,r1(_x1)); if(0==__v) goto __return; r0(__v);   // `c.j$<val>
  TF_AddControlInput((TF_OperationDescription*)_vc_j2,(TF_Operation*)_vc_j1);  // C.TF_AddControlInput[<val>;<val>]
  
  // end of statement
  __v=r1(__consts[5]);  // const ::
  goto __return;  // return cmd

 __return:
  r0(_x1); r0(_x2); 
  while(__stc>0) r0(__st[--__stc]); 
  return __v;
 };
K tf_tf_TF_SetAttrString__q(K _x1,K _x2,K _x3){
  K __st[1]; int __stc=0; K __v=(K)1;
  J _vc_j1; char* _vc_C2; char* _vc_S3; J _vc_j4;
  
  __v=kdot(r1(__consts[20]),knk(1,r1(_x3))); if(0==__v) goto __return;   // count[x3]
  __v=__K2j_cast(&_vc_j1,__v); if(0==__v) goto __return; r0(__v);   // `c.j$<val>
  __v=__K2C_cast(&_vc_C2,r1(_x3)); if(0==__v) goto __return; r0(__v);   // `c.C$<val>
  __v=__K2S_cast(&_vc_S3,r1(_x2)); if(0==__v) goto __return; r0(__v);   // `c.S$<val>
  __v=__K2j_cast(&_vc_j4,r1(_x1)); if(0==__v) goto __return; r0(__v);   // `c.j$<val>
  TF_SetAttrString((TF_OperationDescription*)_vc_j4,_vc_S3,(void*)_vc_C2,(size_t)(tfc_ij)_vc_j1);  // C.TF_SetAttrString[<val>;_vc_S3;<val>;<val>]
  
  // end of statement
  __v=r1(__consts[5]);  // const ::
  goto __return;  // return cmd

 __return:
  r0(_x1); r0(_x2); r0(_x3); 
  while(__stc>0) r0(__st[--__stc]); 
  return __v;
 };
K tf_tf_TF_SetAttrStringList__q(K _op,K _name,K _str){
  K __st[1]; int __stc=0; K __v=(K)1;
  J* _c_a; J* _c_l; J* _vc_J1; J _c_do1; char* _vc_C1; J _vc_j1; I _vc_i1; char* _vc_S4; J _vc_j5;
  K _a=r1(__consts[0]); K _l=r1(__consts[0]); K _s=r1(__consts[0]); 
  __v=kdot(r1(__q[15]),knk(2,r1(__q[14]),r1(_str))); if(0==__v) goto __return;   // each[type;str]
  __v=kdot(r1(__consts[62]),knk(2,__v,r1(__consts[129]))); if(0==__v) goto __return;   // in[<val>;4 10h]
  __v=kdot(r1(__q[13]),knk(1,__v)); if(0==__v) goto __return;   // all[<val>]
  __v=kdot(r1(__consts[22]),knk(1,__v)); if(0==__v) goto __return;   // not[<val>]
  __v=kif(__v); if(0==__v) goto __return; if(0==__v->j) { r0(__v); goto __l2;}; r0(__v);  // if/while check condition
  __v=r1(__consts[140]);  // const "TF_SetAttrStringLis
  __st[__stc++]=__v;  if(__v->t==-KS) __v=krr(__v->s); else if(__v->t==KC)  __v=krr(sn(kC(__v),__v->n)); else __v=krr("stype"); goto __return;  // raise an exception
  r0(__v); 
  // end of statement

 __l2:
  __v=kdot(r1(__consts[20]),knk(1,r1(_str))); if(0==__v) goto __return;   // count[str]
  __v=kdot(r1(__consts[52]),knk(2,__v,r1(__consts[1]))); if(0==__v) goto __return;   // #[<val>;0]
  r0(_a); _a=__v;  // a:<val> - no rval, local
  
  // end of statement
  __v=kdot(r1(__consts[20]),knk(1,r1(_str))); if(0==__v) goto __return;   // count[str]
  __v=kdot(r1(__consts[52]),knk(2,__v,r1(__consts[1]))); if(0==__v) goto __return;   // #[<val>;0]
  r0(_l); _l=__v;  // l:<val> - no rval, local
  
  // end of statement
  __v=__K2J_cast(&_vc_J1,r1(_a)); if(0==__v) goto __return; r0(__v);   // `c.J$<val>
  _c_a=_vc_J1;  // c.a[()]::_vc_J1 - no rval, global
  
  // end of statement
  __v=__K2J_cast(&_vc_J1,r1(_l)); if(0==__v) goto __return; r0(__v);   // `c.J$<val>
  _c_l=_vc_J1;  // c.l[()]::_vc_J1 - no rval, global
  
  // end of statement
  __v=kdot(r1(__consts[20]),knk(1,r1(_str))); if(0==__v) goto __return;   // count[str]
  __v=kif(__v); if(0==__v) goto __return; _c_do1=__v->j; r0(__v);  // check that do value is correct

 __l3:
  if(0>=_c_do1)goto __l5; _c_do1-=1;  // do condition
  __v=kj(_c_do1); if(0==__v) goto __return;   // C.toK[c.do1]
  __v=kdot(r1(_str),knk(1,__v)); if(0==__v) goto __return;   // str[<val>]
  r0(_s); _s=__v;__v=r1(_s);   // s:<val>
  __v=__K2C_cast(&_vc_C1,__v); if(0==__v) goto __return; r0(__v);   // `c.C$<val>
  _c_a[_c_do1]=(J)_vc_C1;  // c.a[<val>]::<val> - no rval, global
  
  // end of statement
  __v=kdot(r1(__consts[20]),knk(1,r1(_s))); if(0==__v) goto __return;   // count[s]
  __v=__K2j_cast(&_vc_j1,__v); if(0==__v) goto __return; r0(__v);   // `c.j$<val>
  _c_l[_c_do1]=_vc_j1;  // c.l[<val>]::_vc_j1 - no rval, global
  
  // end of statement
  goto __l3;  // jump back to do/while

 __l5:
  __v=kdot(r1(__consts[20]),knk(1,r1(_str))); if(0==__v) goto __return;   // count[str]
  __v=kdot(r1(__consts[50]),knk(2,r1(__consts[136]),__v)); if(0==__v) goto __return;   // $["i";<val>]
  __v=__K2i_cast(&_vc_i1,__v); if(0==__v) goto __return; r0(__v);   // `c.i$<val>
  __v=__K2S_cast(&_vc_S4,r1(_name)); if(0==__v) goto __return; r0(__v);   // `c.S$<val>
  __v=__K2j_cast(&_vc_j5,r1(_op)); if(0==__v) goto __return; r0(__v);   // `c.j$<val>
  TF_SetAttrStringList((TF_OperationDescription*)_vc_j5,_vc_S4,(const void* const*)(void*)_c_a,(size_t*)(void*)_c_l,_vc_i1);  // C.TF_SetAttrStringList[<val>;_vc_S4;<val>;<val>;_vc_i1]
  
  // end of statement
  __v=r1(__consts[5]);  // const ::
  goto __return;  // return cmd

 __return:
  r0(_a); r0(_l); r0(_s); r0(_op); r0(_name); r0(_str); 
  while(__stc>0) r0(__st[--__stc]); 
  return __v;
 };
K tf_tf_TF_SetAttrInt__q(K _x1,K _x2,K _x3){
  K __st[1]; int __stc=0; K __v=(K)1;
  J _vc_j1; char* _vc_S2; J _vc_j3;
  
  __v=__K2j_cast(&_vc_j1,r1(_x3)); if(0==__v) goto __return; r0(__v);   // `c.j$<val>
  __v=__K2S_cast(&_vc_S2,r1(_x2)); if(0==__v) goto __return; r0(__v);   // `c.S$<val>
  __v=__K2j_cast(&_vc_j3,r1(_x1)); if(0==__v) goto __return; r0(__v);   // `c.j$<val>
  TF_SetAttrInt((TF_OperationDescription*)_vc_j3,_vc_S2,_vc_j1);  // C.TF_SetAttrInt[<val>;_vc_S2;_vc_j1]
  
  // end of statement
  __v=r1(__consts[5]);  // const ::
  goto __return;  // return cmd

 __return:
  r0(_x1); r0(_x2); r0(_x3); 
  while(__stc>0) r0(__st[--__stc]); 
  return __v;
 };
K tf_tf_TF_SetAttrIntList__q(K _x1,K _x2,K _x3){
  K __st[1]; int __stc=0; K __v=(K)1;
  J _vc_j1; J* _vc_J2; char* _vc_S3; J _vc_j4;
  
  __v=kdot(r1(__consts[20]),knk(1,r1(_x3))); if(0==__v) goto __return;   // count[x3]
  __v=__K2j_cast(&_vc_j1,__v); if(0==__v) goto __return; r0(__v);   // `c.j$<val>
  __v=__K2J_cast(&_vc_J2,r1(_x3)); if(0==__v) goto __return; r0(__v);   // `c.J$<val>
  __v=__K2S_cast(&_vc_S3,r1(_x2)); if(0==__v) goto __return; r0(__v);   // `c.S$<val>
  __v=__K2j_cast(&_vc_j4,r1(_x1)); if(0==__v) goto __return; r0(__v);   // `c.j$<val>
  TF_SetAttrIntList((TF_OperationDescription*)_vc_j4,_vc_S3,(long*)_vc_J2,(I)(tfc_ij)_vc_j1);  // C.TF_SetAttrIntList[<val>;_vc_S3;<val>;<val>]
  
  // end of statement
  __v=r1(__consts[5]);  // const ::
  goto __return;  // return cmd

 __return:
  r0(_x1); r0(_x2); r0(_x3); 
  while(__stc>0) r0(__st[--__stc]); 
  return __v;
 };
K tf_tf_TF_SetAttrFloat__q(K _x1,K _x2,K _x3){
  K __st[1]; int __stc=0; K __v=(K)1;
  F _vc_f1; char* _vc_S2; J _vc_j3;
  
  __v=__K2f_cast(&_vc_f1,r1(_x3)); if(0==__v) goto __return; r0(__v);   // `c.f$<val>
  __v=__K2S_cast(&_vc_S2,r1(_x2)); if(0==__v) goto __return; r0(__v);   // `c.S$<val>
  __v=__K2j_cast(&_vc_j3,r1(_x1)); if(0==__v) goto __return; r0(__v);   // `c.j$<val>
  TF_SetAttrFloat((TF_OperationDescription*)_vc_j3,_vc_S2,_vc_f1);  // C.TF_SetAttrFloat[<val>;_vc_S2;_vc_f1]
  
  // end of statement
  __v=r1(__consts[5]);  // const ::
  goto __return;  // return cmd

 __return:
  r0(_x1); r0(_x2); r0(_x3); 
  while(__stc>0) r0(__st[--__stc]); 
  return __v;
 };
K tf_tf_TF_SetAttrFloatList__q(K _x1,K _x2,K _x3){
  K __st[1]; int __stc=0; K __v=(K)1;
  J _vc_j1; E* _vc_E2; char* _vc_S3; J _vc_j4;
  
  __v=kdot(r1(__consts[20]),knk(1,r1(_x3))); if(0==__v) goto __return;   // count[x3]
  __v=__K2j_cast(&_vc_j1,__v); if(0==__v) goto __return; r0(__v);   // `c.j$<val>
  __v=__K2E_cast(&_vc_E2,r1(_x3)); if(0==__v) goto __return; r0(__v);   // `c.E$<val>
  __v=__K2S_cast(&_vc_S3,r1(_x2)); if(0==__v) goto __return; r0(__v);   // `c.S$<val>
  __v=__K2j_cast(&_vc_j4,r1(_x1)); if(0==__v) goto __return; r0(__v);   // `c.j$<val>
  TF_SetAttrFloatList((TF_OperationDescription*)_vc_j4,_vc_S3,_vc_E2,(I)(tfc_ij)_vc_j1);  // C.TF_SetAttrFloatList[<val>;_vc_S3;_vc_E2;<val>]
  
  // end of statement
  __v=r1(__consts[5]);  // const ::
  goto __return;  // return cmd

 __return:
  r0(_x1); r0(_x2); r0(_x3); 
  while(__stc>0) r0(__st[--__stc]); 
  return __v;
 };
K tf_tf_TF_SetAttrBool__q(K _x1,K _x2,K _x3){
  K __st[1]; int __stc=0; K __v=(K)1;
  char _vc_c1; char* _vc_S2; J _vc_j3;
  
  __v=__K2c_cast(&_vc_c1,r1(_x3)); if(0==__v) goto __return; r0(__v);   // `c.c$<val>
  __v=__K2S_cast(&_vc_S2,r1(_x2)); if(0==__v) goto __return; r0(__v);   // `c.S$<val>
  __v=__K2j_cast(&_vc_j3,r1(_x1)); if(0==__v) goto __return; r0(__v);   // `c.j$<val>
  TF_SetAttrBool((TF_OperationDescription*)_vc_j3,_vc_S2,(unsigned char)_vc_c1);  // C.TF_SetAttrBool[<val>;_vc_S2;<val>]
  
  // end of statement
  __v=r1(__consts[5]);  // const ::
  goto __return;  // return cmd

 __return:
  r0(_x1); r0(_x2); r0(_x3); 
  while(__stc>0) r0(__st[--__stc]); 
  return __v;
 };
K tf_tf_TF_SetAttrBoolList__q(K _x1,K _x2,K _x3){
  K __st[1]; int __stc=0; K __v=(K)1;
  J _vc_j1; char* _vc_C2; char* _vc_S3; J _vc_j4;
  
  __v=kdot(r1(__consts[20]),knk(1,r1(_x3))); if(0==__v) goto __return;   // count[x3]
  __v=__K2j_cast(&_vc_j1,__v); if(0==__v) goto __return; r0(__v);   // `c.j$<val>
  __v=__K2C_cast(&_vc_C2,r1(_x3)); if(0==__v) goto __return; r0(__v);   // `c.C$<val>
  __v=__K2S_cast(&_vc_S3,r1(_x2)); if(0==__v) goto __return; r0(__v);   // `c.S$<val>
  __v=__K2j_cast(&_vc_j4,r1(_x1)); if(0==__v) goto __return; r0(__v);   // `c.j$<val>
  TF_SetAttrBoolList((TF_OperationDescription*)_vc_j4,_vc_S3,(unsigned char*)_vc_C2,(I)(tfc_ij)_vc_j1);  // C.TF_SetAttrBoolList[<val>;_vc_S3;<val>;<val>]
  
  // end of statement
  __v=r1(__consts[5]);  // const ::
  goto __return;  // return cmd

 __return:
  r0(_x1); r0(_x2); r0(_x3); 
  while(__stc>0) r0(__st[--__stc]); 
  return __v;
 };
K tf_tf_TF_SetAttrType__q(K _x1,K _x2,K _x3){
  K __st[1]; int __stc=0; K __v=(K)1;
  I _vc_i1; char* _vc_S2; J _vc_j3;
  
  __v=__K2i_cast(&_vc_i1,r1(_x3)); if(0==__v) goto __return; r0(__v);   // `c.i$<val>
  __v=__K2S_cast(&_vc_S2,r1(_x2)); if(0==__v) goto __return; r0(__v);   // `c.S$<val>
  __v=__K2j_cast(&_vc_j3,r1(_x1)); if(0==__v) goto __return; r0(__v);   // `c.j$<val>
  TF_SetAttrType((TF_OperationDescription*)_vc_j3,_vc_S2,(TF_DataType)_vc_i1);  // C.TF_SetAttrType[<val>;_vc_S2;<val>]
  
  // end of statement
  __v=r1(__consts[5]);  // const ::
  goto __return;  // return cmd

 __return:
  r0(_x1); r0(_x2); r0(_x3); 
  while(__stc>0) r0(__st[--__stc]); 
  return __v;
 };
K tf_tf_TF_SetAttrTypeList__q(K _x1,K _x2,K _x3){
  K __st[1]; int __stc=0; K __v=(K)1;
  J _vc_j1; I* _vc_I2; char* _vc_S3; J _vc_j4;
  
  __v=kdot(r1(__consts[20]),knk(1,r1(_x3))); if(0==__v) goto __return;   // count[x3]
  __v=__K2j_cast(&_vc_j1,__v); if(0==__v) goto __return; r0(__v);   // `c.j$<val>
  __v=__K2I_cast(&_vc_I2,r1(_x3)); if(0==__v) goto __return; r0(__v);   // `c.I$<val>
  __v=__K2S_cast(&_vc_S3,r1(_x2)); if(0==__v) goto __return; r0(__v);   // `c.S$<val>
  __v=__K2j_cast(&_vc_j4,r1(_x1)); if(0==__v) goto __return; r0(__v);   // `c.j$<val>
  TF_SetAttrTypeList((TF_OperationDescription*)_vc_j4,_vc_S3,(TF_DataType*)(void*)_vc_I2,(I)(tfc_ij)_vc_j1);  // C.TF_SetAttrTypeList[<val>;_vc_S3;<val>;<val>]
  
  // end of statement
  __v=r1(__consts[5]);  // const ::
  goto __return;  // return cmd

 __return:
  r0(_x1); r0(_x2); r0(_x3); 
  while(__stc>0) r0(__st[--__stc]); 
  return __v;
 };
K tf_tf_TF_SetAttrShape__q(K _x1,K _x2,K _x3){
  K __st[1]; int __stc=0; K __v=(K)1;
  J _vc_j1; J* _vc_J2; char* _vc_S3; J _vc_j4;
  
  __v=kdot(r1(__consts[20]),knk(1,r1(_x3))); if(0==__v) goto __return;   // count[x3]
  __v=__K2j_cast(&_vc_j1,__v); if(0==__v) goto __return; r0(__v);   // `c.j$<val>
  __v=__K2J_cast(&_vc_J2,r1(_x3)); if(0==__v) goto __return; r0(__v);   // `c.J$<val>
  __v=__K2S_cast(&_vc_S3,r1(_x2)); if(0==__v) goto __return; r0(__v);   // `c.S$<val>
  __v=__K2j_cast(&_vc_j4,r1(_x1)); if(0==__v) goto __return; r0(__v);   // `c.j$<val>
  TF_SetAttrShape((TF_OperationDescription*)_vc_j4,_vc_S3,(long*)_vc_J2,(I)(tfc_ij)_vc_j1);  // C.TF_SetAttrShape[<val>;_vc_S3;<val>;<val>]
  
  // end of statement
  __v=r1(__consts[5]);  // const ::
  goto __return;  // return cmd

 __return:
  r0(_x1); r0(_x2); r0(_x3); 
  while(__stc>0) r0(__st[--__stc]); 
  return __v;
 };
K tf_tf_TF_SetAttrShapeList__q(K _op,K _name,K _dims){
  K __st[1]; int __stc=0; K __v=(K)1;
  J* _c_a; I* _c_l; J* _vc_J1; I* _vc_I1; J _c_do1; I _vc_i1; char* _vc_S4; J _vc_j5;
  K _a=r1(__consts[0]); K _l=r1(__consts[0]); K _s=r1(__consts[0]); 
  __v=kdot(r1(__q[15]),knk(2,r1(__q[14]),r1(_dims))); if(0==__v) goto __return;   // each[type;dims]
  __v=kdot(r1(__consts[47]),knk(2,r1(__consts[132]),__v)); if(0==__v) goto __return;   // =[7;<val>]
  __v=kdot(r1(__q[13]),knk(1,__v)); if(0==__v) goto __return;   // all[<val>]
  __v=kdot(r1(__consts[22]),knk(1,__v)); if(0==__v) goto __return;   // not[<val>]
  __v=kif(__v); if(0==__v) goto __return; if(0==__v->j) { r0(__v); goto __l2;}; r0(__v);  // if/while check condition
  __v=r1(__consts[141]);  // const "TF_SetAttrShapeList
  __st[__stc++]=__v;  if(__v->t==-KS) __v=krr(__v->s); else if(__v->t==KC)  __v=krr(sn(kC(__v),__v->n)); else __v=krr("stype"); goto __return;  // raise an exception
  r0(__v); 
  // end of statement

 __l2:
  __v=kdot(r1(__consts[20]),knk(1,r1(_dims))); if(0==__v) goto __return;   // count[dims]
  __v=kdot(r1(__consts[52]),knk(2,__v,r1(__consts[1]))); if(0==__v) goto __return;   // #[<val>;0]
  r0(_a); _a=__v;  // a:<val> - no rval, local
  
  // end of statement
  __v=kdot(r1(__consts[20]),knk(1,r1(_dims))); if(0==__v) goto __return;   // count[dims]
  __v=kdot(r1(__consts[52]),knk(2,__v,r1(__consts[1]))); if(0==__v) goto __return;   // #[<val>;0]
  r0(_l); _l=__v;  // l:<val> - no rval, local
  
  // end of statement
  __v=__K2J_cast(&_vc_J1,r1(_a)); if(0==__v) goto __return; r0(__v);   // `c.J$<val>
  _c_a=_vc_J1;  // c.a[()]::_vc_J1 - no rval, global
  
  // end of statement
  __v=__K2I_cast(&_vc_I1,r1(_l)); if(0==__v) goto __return; r0(__v);   // `c.I$<val>
  _c_l=_vc_I1;  // c.l[()]::_vc_I1 - no rval, global
  
  // end of statement
  __v=kdot(r1(__consts[20]),knk(1,r1(_dims))); if(0==__v) goto __return;   // count[dims]
  __v=kif(__v); if(0==__v) goto __return; _c_do1=__v->j; r0(__v);  // check that do value is correct

 __l3:
  if(0>=_c_do1)goto __l5; _c_do1-=1;  // do condition
  __v=kj(_c_do1); if(0==__v) goto __return;   // C.toK[c.do1]
  __v=kdot(r1(_dims),knk(1,__v)); if(0==__v) goto __return;   // dims[<val>]
  r0(_s); _s=__v;__v=r1(_s);   // s:<val>
  __v=__K2J_cast(&_vc_J1,__v); if(0==__v) goto __return; r0(__v);   // `c.J$<val>
  _c_a[_c_do1]=(J)_vc_J1;  // c.a[<val>]::<val> - no rval, global
  
  // end of statement
  __v=kdot(r1(__consts[20]),knk(1,r1(_s))); if(0==__v) goto __return;   // count[s]
  __v=kdot(r1(__consts[50]),knk(2,r1(__consts[136]),__v)); if(0==__v) goto __return;   // $["i";<val>]
  __v=__K2i_cast(&_vc_i1,__v); if(0==__v) goto __return; r0(__v);   // `c.i$<val>
  _c_l[_c_do1]=_vc_i1;  // c.l[<val>]::_vc_i1 - no rval, global
  
  // end of statement
  goto __l3;  // jump back to do/while

 __l5:
  __v=kdot(r1(__consts[20]),knk(1,r1(_dims))); if(0==__v) goto __return;   // count[dims]
  __v=kdot(r1(__consts[50]),knk(2,r1(__consts[136]),__v)); if(0==__v) goto __return;   // $["i";<val>]
  __v=__K2i_cast(&_vc_i1,__v); if(0==__v) goto __return; r0(__v);   // `c.i$<val>
  __v=__K2S_cast(&_vc_S4,r1(_name)); if(0==__v) goto __return; r0(__v);   // `c.S$<val>
  __v=__K2j_cast(&_vc_j5,r1(_op)); if(0==__v) goto __return; r0(__v);   // `c.j$<val>
  TF_SetAttrShapeList((TF_OperationDescription*)_vc_j5,_vc_S4,(const long int* const*)(void*)_c_a,_c_l,_vc_i1);  // C.TF_SetAttrShapeList[<val>;_vc_S4;<val>;c.l;_vc_i1]
  
  // end of statement
  __v=r1(__consts[5]);  // const ::
  goto __return;  // return cmd

 __return:
  r0(_a); r0(_l); r0(_s); r0(_op); r0(_name); r0(_dims); 
  while(__stc>0) r0(__st[--__stc]); 
  return __v;
 };
K tf_tf_TF_SetAttrTensorShapeProto__q(K _x1,K _x2,K _x3,K _x5){
  K __st[1]; int __stc=0; K __v=(K)1;
  J _vc_j1; J _vc_j2; char* _vc_C3; char* _vc_S4; J _vc_j5;
  
  __v=__K2j_cast(&_vc_j1,r1(_x5)); if(0==__v) goto __return; r0(__v);   // `c.j$<val>
  __v=kdot(r1(__consts[20]),knk(1,r1(_x3))); if(0==__v) goto __return;   // count[x3]
  __v=__K2j_cast(&_vc_j2,__v); if(0==__v) goto __return; r0(__v);   // `c.j$<val>
  __v=__K2C_cast(&_vc_C3,r1(_x3)); if(0==__v) goto __return; r0(__v);   // `c.C$<val>
  __v=__K2S_cast(&_vc_S4,r1(_x2)); if(0==__v) goto __return; r0(__v);   // `c.S$<val>
  __v=__K2j_cast(&_vc_j5,r1(_x1)); if(0==__v) goto __return; r0(__v);   // `c.j$<val>
  TF_SetAttrTensorShapeProto((TF_OperationDescription*)_vc_j5,_vc_S4,(void*)_vc_C3,(I)(tfc_ij)_vc_j2,(TF_Status*)_vc_j1);  // C.TF_SetAttrTensorShapeProto[<val>;_vc_S4;<val>;<val>;<val>]
  
  // end of statement
  __v=r1(__consts[5]);  // const ::
  goto __return;  // return cmd

 __return:
  r0(_x1); r0(_x2); r0(_x3); r0(_x5); 
  while(__stc>0) r0(__st[--__stc]); 
  return __v;
 };
K tf_tf_TF_SetAttrTensorShapeProtoList__q(K _op,K _name,K _proto,K _st){
  K __st[1]; int __stc=0; K __v=(K)1;
  J* _c_a; J* _c_l; J* _vc_J1; J _c_do1; char* _vc_C1; J _vc_j1; I _vc_i2; char* _vc_S5; J _vc_j6;
  K _a=r1(__consts[0]); K _l=r1(__consts[0]); K _s=r1(__consts[0]); 
  __v=kdot(r1(__q[15]),knk(2,r1(__q[14]),r1(_proto))); if(0==__v) goto __return;   // each[type;proto]
  __v=kdot(r1(__consts[62]),knk(2,__v,r1(__consts[129]))); if(0==__v) goto __return;   // in[<val>;4 10h]
  __v=kdot(r1(__q[13]),knk(1,__v)); if(0==__v) goto __return;   // all[<val>]
  __v=kdot(r1(__consts[22]),knk(1,__v)); if(0==__v) goto __return;   // not[<val>]
  __v=kif(__v); if(0==__v) goto __return; if(0==__v->j) { r0(__v); goto __l2;}; r0(__v);  // if/while check condition
  __v=r1(__consts[142]);  // const "TF_SetAttrTensorSha
  __st[__stc++]=__v;  if(__v->t==-KS) __v=krr(__v->s); else if(__v->t==KC)  __v=krr(sn(kC(__v),__v->n)); else __v=krr("stype"); goto __return;  // raise an exception
  r0(__v); 
  // end of statement

 __l2:
  __v=kdot(r1(__consts[20]),knk(1,r1(_proto))); if(0==__v) goto __return;   // count[proto]
  __v=kdot(r1(__consts[52]),knk(2,__v,r1(__consts[1]))); if(0==__v) goto __return;   // #[<val>;0]
  r0(_a); _a=__v;  // a:<val> - no rval, local
  
  // end of statement
  __v=kdot(r1(__consts[20]),knk(1,r1(_proto))); if(0==__v) goto __return;   // count[proto]
  __v=kdot(r1(__consts[52]),knk(2,__v,r1(__consts[1]))); if(0==__v) goto __return;   // #[<val>;0]
  r0(_l); _l=__v;  // l:<val> - no rval, local
  
  // end of statement
  __v=__K2J_cast(&_vc_J1,r1(_a)); if(0==__v) goto __return; r0(__v);   // `c.J$<val>
  _c_a=_vc_J1;  // c.a[()]::_vc_J1 - no rval, global
  
  // end of statement
  __v=__K2J_cast(&_vc_J1,r1(_l)); if(0==__v) goto __return; r0(__v);   // `c.J$<val>
  _c_l=_vc_J1;  // c.l[()]::_vc_J1 - no rval, global
  
  // end of statement
  __v=kdot(r1(__consts[20]),knk(1,r1(_proto))); if(0==__v) goto __return;   // count[proto]
  __v=kif(__v); if(0==__v) goto __return; _c_do1=__v->j; r0(__v);  // check that do value is correct

 __l3:
  if(0>=_c_do1)goto __l5; _c_do1-=1;  // do condition
  __v=kj(_c_do1); if(0==__v) goto __return;   // C.toK[c.do1]
  __v=kdot(r1(_proto),knk(1,__v)); if(0==__v) goto __return;   // proto[<val>]
  r0(_s); _s=__v;__v=r1(_s);   // s:<val>
  __v=__K2C_cast(&_vc_C1,__v); if(0==__v) goto __return; r0(__v);   // `c.C$<val>
  _c_a[_c_do1]=(J)_vc_C1;  // c.a[<val>]::<val> - no rval, global
  
  // end of statement
  __v=kdot(r1(__consts[20]),knk(1,r1(_s))); if(0==__v) goto __return;   // count[s]
  __v=__K2j_cast(&_vc_j1,__v); if(0==__v) goto __return; r0(__v);   // `c.j$<val>
  _c_l[_c_do1]=_vc_j1;  // c.l[<val>]::_vc_j1 - no rval, global
  
  // end of statement
  goto __l3;  // jump back to do/while

 __l5:
  __v=__K2j_cast(&_vc_j1,r1(_st)); if(0==__v) goto __return; r0(__v);   // `c.j$<val>
  __v=kdot(r1(__consts[20]),knk(1,r1(_proto))); if(0==__v) goto __return;   // count[proto]
  __v=kdot(r1(__consts[50]),knk(2,r1(__consts[136]),__v)); if(0==__v) goto __return;   // $["i";<val>]
  __v=__K2i_cast(&_vc_i2,__v); if(0==__v) goto __return; r0(__v);   // `c.i$<val>
  __v=__K2S_cast(&_vc_S5,r1(_name)); if(0==__v) goto __return; r0(__v);   // `c.S$<val>
  __v=__K2j_cast(&_vc_j6,r1(_op)); if(0==__v) goto __return; r0(__v);   // `c.j$<val>
  TF_SetAttrTensorShapeProtoList((TF_OperationDescription*)_vc_j6,_vc_S5,(const void* const*)(void*)_c_a,(size_t*)(void*)_c_l,_vc_i2,(TF_Status*)_vc_j1);  // C.TF_SetAttrTensorShapeProtoList[<val>;_vc_S5;<val>;<val>;_vc_i2;<val>]
  
  // end of statement
  __v=r1(__consts[5]);  // const ::
  goto __return;  // return cmd

 __return:
  r0(_a); r0(_l); r0(_s); r0(_op); r0(_name); r0(_proto); r0(_st); 
  while(__stc>0) r0(__st[--__stc]); 
  return __v;
 };
K tf_tf_TF_SetAttrTensor__q(K _x1,K _x2,K _x3,K _x4){
  K __st[1]; int __stc=0; K __v=(K)1;
  J _vc_j1; J _vc_j2; char* _vc_S3; J _vc_j4;
  
  __v=__K2j_cast(&_vc_j1,r1(_x4)); if(0==__v) goto __return; r0(__v);   // `c.j$<val>
  __v=__K2j_cast(&_vc_j2,r1(_x3)); if(0==__v) goto __return; r0(__v);   // `c.j$<val>
  __v=__K2S_cast(&_vc_S3,r1(_x2)); if(0==__v) goto __return; r0(__v);   // `c.S$<val>
  __v=__K2j_cast(&_vc_j4,r1(_x1)); if(0==__v) goto __return; r0(__v);   // `c.j$<val>
  TF_SetAttrTensor((TF_OperationDescription*)_vc_j4,_vc_S3,(TF_Tensor*)_vc_j2,(TF_Status*)_vc_j1);  // C.TF_SetAttrTensor[<val>;_vc_S3;<val>;<val>]
  
  // end of statement
  __v=r1(__consts[5]);  // const ::
  goto __return;  // return cmd

 __return:
  r0(_x1); r0(_x2); r0(_x3); r0(_x4); 
  while(__stc>0) r0(__st[--__stc]); 
  return __v;
 };
K tf_tf_TF_SetAttrTensorList__q(K _x1,K _x2,K _x3,K _x5){
  K __st[1]; int __stc=0; K __v=(K)1;
  J _vc_j1; J _vc_j2; J* _vc_J3; char* _vc_S4; J _vc_j5;
  
  __v=__K2j_cast(&_vc_j1,r1(_x5)); if(0==__v) goto __return; r0(__v);   // `c.j$<val>
  __v=kdot(r1(__consts[20]),knk(1,r1(_x3))); if(0==__v) goto __return;   // count[x3]
  __v=__K2j_cast(&_vc_j2,__v); if(0==__v) goto __return; r0(__v);   // `c.j$<val>
  __v=__K2J_cast(&_vc_J3,r1(_x3)); if(0==__v) goto __return; r0(__v);   // `c.J$<val>
  __v=__K2S_cast(&_vc_S4,r1(_x2)); if(0==__v) goto __return; r0(__v);   // `c.S$<val>
  __v=__K2j_cast(&_vc_j5,r1(_x1)); if(0==__v) goto __return; r0(__v);   // `c.j$<val>
  TF_SetAttrTensorList((TF_OperationDescription*)_vc_j5,_vc_S4,(tfc_TF_Tensor_p_p)(void*)_vc_J3,(I)(tfc_ij)_vc_j2,(TF_Status*)_vc_j1);  // C.TF_SetAttrTensorList[<val>;_vc_S4;<val>;<val>;<val>]
  
  // end of statement
  __v=r1(__consts[5]);  // const ::
  goto __return;  // return cmd

 __return:
  r0(_x1); r0(_x2); r0(_x3); r0(_x5); 
  while(__stc>0) r0(__st[--__stc]); 
  return __v;
 };
K tf_tf_TF_SetAttrValueProto__q(K _x1,K _x2,K _x3,K _x5){
  K __st[1]; int __stc=0; K __v=(K)1;
  J _vc_j1; J _vc_j2; char* _vc_C3; char* _vc_S4; J _vc_j5;
  
  __v=__K2j_cast(&_vc_j1,r1(_x5)); if(0==__v) goto __return; r0(__v);   // `c.j$<val>
  __v=kdot(r1(__consts[20]),knk(1,r1(_x3))); if(0==__v) goto __return;   // count[x3]
  __v=__K2j_cast(&_vc_j2,__v); if(0==__v) goto __return; r0(__v);   // `c.j$<val>
  __v=__K2C_cast(&_vc_C3,r1(_x3)); if(0==__v) goto __return; r0(__v);   // `c.C$<val>
  __v=__K2S_cast(&_vc_S4,r1(_x2)); if(0==__v) goto __return; r0(__v);   // `c.S$<val>
  __v=__K2j_cast(&_vc_j5,r1(_x1)); if(0==__v) goto __return; r0(__v);   // `c.j$<val>
  TF_SetAttrValueProto((TF_OperationDescription*)_vc_j5,_vc_S4,(void*)_vc_C3,(size_t)(tfc_ij)_vc_j2,(TF_Status*)_vc_j1);  // C.TF_SetAttrValueProto[<val>;_vc_S4;<val>;<val>;<val>]
  
  // end of statement
  __v=r1(__consts[5]);  // const ::
  goto __return;  // return cmd

 __return:
  r0(_x1); r0(_x2); r0(_x3); r0(_x5); 
  while(__stc>0) r0(__st[--__stc]); 
  return __v;
 };
K tf_tf_TF_FinishOperation__q(K _x1,K _x2){
  K __st[1]; int __stc=0; K __v=(K)1;
  TF_Operation* _c_res; J _vc_j1; J _vc_j2;
  
  __v=__K2j_cast(&_vc_j1,r1(_x2)); if(0==__v) goto __return; r0(__v);   // `c.j$<val>
  __v=__K2j_cast(&_vc_j2,r1(_x1)); if(0==__v) goto __return; r0(__v);   // `c.j$<val>
  _c_res=TF_FinishOperation((TF_OperationDescription*)_vc_j2,(TF_Status*)_vc_j1);  // C.TF_FinishOperation[<val>;<val>]
  // c.res[()]::<val> - no rval, global
  
  // end of statement
  __v=kj((J)_c_res); if(0==__v) goto __return;   // C.toK[<val>]
  goto __return;  // return cmd

 __return:
  r0(_x1); r0(_x2); 
  while(__stc>0) r0(__st[--__stc]); 
  return __v;
 };
K tf_tf_TF_OperationName__q(K _x1){
  K __st[1]; int __stc=0; K __v=(K)1;
  const char* _c_res; J _vc_j1; _Bool _vc_bool1;
  
  __v=__K2j_cast(&_vc_j1,r1(_x1)); if(0==__v) goto __return; r0(__v);   // `c.j$<val>
  _c_res=TF_OperationName((TF_Operation*)_vc_j1);  // C.TF_OperationName[<val>]
  // c.res[()]::<val> - no rval, global
  
  // end of statement
  _vc_bool1=0LL==(J)_c_res;  // =[0LL;<val>]
  if(0==_vc_bool1) goto __l2;  // if/while check condition
  __v=ki(errno); if(0==__v) goto __return;   // C.toK[C.errno]
  __st[__stc++]=__v; __v=kdot(r1(__consts[26]),knk(1,r1(__glob[17]))); if(0==__v) goto __return;   // global .string.strerror
  __v=kdot(__v,knk(1,__st[__stc-1]));__stc-=1;  if(0==__v) goto __return;   // .string.strerror[<val>]
  __v=kdot(r1(__consts[51]),knk(2,r1(__consts[143]),__v)); if(0==__v) goto __return;   // ,["C.TF_OperationName:;<val>]
  __st[__stc++]=__v;  if(__v->t==-KS) __v=krr(__v->s); else if(__v->t==KC)  __v=krr(sn(kC(__v),__v->n)); else __v=krr("stype"); goto __return;  // raise an exception
  r0(__v); 
  // end of statement

 __l2:
  __v=__toKS((char*)_c_res); if(0==__v) goto __return;   // C.toK[<val>]
  goto __return;  // return cmd

 __return:
  r0(_x1); 
  while(__stc>0) r0(__st[--__stc]); 
  return __v;
 };
K tf_tf_TF_OperationOpType__q(K _x1){
  K __st[1]; int __stc=0; K __v=(K)1;
  const char* _c_res; J _vc_j1; _Bool _vc_bool1;
  
  __v=__K2j_cast(&_vc_j1,r1(_x1)); if(0==__v) goto __return; r0(__v);   // `c.j$<val>
  _c_res=TF_OperationOpType((TF_Operation*)_vc_j1);  // C.TF_OperationOpType[<val>]
  // c.res[()]::<val> - no rval, global
  
  // end of statement
  _vc_bool1=0LL==(J)_c_res;  // =[0LL;<val>]
  if(0==_vc_bool1) goto __l2;  // if/while check condition
  __v=ki(errno); if(0==__v) goto __return;   // C.toK[C.errno]
  __st[__stc++]=__v; __v=kdot(r1(__consts[26]),knk(1,r1(__glob[17]))); if(0==__v) goto __return;   // global .string.strerror
  __v=kdot(__v,knk(1,__st[__stc-1]));__stc-=1;  if(0==__v) goto __return;   // .string.strerror[<val>]
  __v=kdot(r1(__consts[51]),knk(2,r1(__consts[144]),__v)); if(0==__v) goto __return;   // ,["C.TF_OperationOpTyp;<val>]
  __st[__stc++]=__v;  if(__v->t==-KS) __v=krr(__v->s); else if(__v->t==KC)  __v=krr(sn(kC(__v),__v->n)); else __v=krr("stype"); goto __return;  // raise an exception
  r0(__v); 
  // end of statement

 __l2:
  __v=__toKS((char*)_c_res); if(0==__v) goto __return;   // C.toK[<val>]
  goto __return;  // return cmd

 __return:
  r0(_x1); 
  while(__stc>0) r0(__st[--__stc]); 
  return __v;
 };
K tf_tf_TF_OperationDevice__q(K _x1){
  K __st[1]; int __stc=0; K __v=(K)1;
  const char* _c_res; J _vc_j1; _Bool _vc_bool1;
  
  __v=__K2j_cast(&_vc_j1,r1(_x1)); if(0==__v) goto __return; r0(__v);   // `c.j$<val>
  _c_res=TF_OperationDevice((TF_Operation*)_vc_j1);  // C.TF_OperationDevice[<val>]
  // c.res[()]::<val> - no rval, global
  
  // end of statement
  _vc_bool1=0LL==(J)_c_res;  // =[0LL;<val>]
  if(0==_vc_bool1) goto __l2;  // if/while check condition
  __v=ki(errno); if(0==__v) goto __return;   // C.toK[C.errno]
  __st[__stc++]=__v; __v=kdot(r1(__consts[26]),knk(1,r1(__glob[17]))); if(0==__v) goto __return;   // global .string.strerror
  __v=kdot(__v,knk(1,__st[__stc-1]));__stc-=1;  if(0==__v) goto __return;   // .string.strerror[<val>]
  __v=kdot(r1(__consts[51]),knk(2,r1(__consts[145]),__v)); if(0==__v) goto __return;   // ,["C.TF_OperationDevic;<val>]
  __st[__stc++]=__v;  if(__v->t==-KS) __v=krr(__v->s); else if(__v->t==KC)  __v=krr(sn(kC(__v),__v->n)); else __v=krr("stype"); goto __return;  // raise an exception
  r0(__v); 
  // end of statement

 __l2:
  __v=__toKS((char*)_c_res); if(0==__v) goto __return;   // C.toK[<val>]
  goto __return;  // return cmd

 __return:
  r0(_x1); 
  while(__stc>0) r0(__st[--__stc]); 
  return __v;
 };
K tf_tf_TF_OperationNumOutputs__q(K _x1){
  K __st[1]; int __stc=0; K __v=(K)1;
  I _c_res; J _vc_j1;
  
  __v=__K2j_cast(&_vc_j1,r1(_x1)); if(0==__v) goto __return; r0(__v);   // `c.j$<val>
  _c_res=TF_OperationNumOutputs((TF_Operation*)_vc_j1);  // C.TF_OperationNumOutputs[<val>]
  // c.res[()]::<val> - no rval, global
  
  // end of statement
  __v=ki(_c_res); if(0==__v) goto __return;   // C.toK[c.res]
  goto __return;  // return cmd

 __return:
  r0(_x1); 
  while(__stc>0) r0(__st[--__stc]); 
  return __v;
 };
K tf_tf_TF_OperationOutputType__q(K _x1){
  K __st[1]; int __stc=0; K __v=(K)1;
  TF_DataType _c_res; TF_Output _vc_TF_Output1;
  
  __v=__K2TF_Output_cast(&_vc_TF_Output1,r1(_x1)); if(0==__v) goto __return; r0(__v);   // `c.TF_Output$<val>
  _c_res=TF_OperationOutputType(_vc_TF_Output1);  // C.TF_OperationOutputType[_vc_TF_Output1]
  // c.res[()]::<val> - no rval, global
  
  // end of statement
  __v=ki((I)_c_res); if(0==__v) goto __return;   // C.toK[<val>]
  goto __return;  // return cmd

 __return:
  r0(_x1); 
  while(__stc>0) r0(__st[--__stc]); 
  return __v;
 };
K tf_tf_TF_OperationOutputListLength__q(K _x1,K _x2,K _x3){
  K __st[1]; int __stc=0; K __v=(K)1;
  I _c_res; J _vc_j1; char* _vc_S2; J _vc_j3;
  
  __v=__K2j_cast(&_vc_j1,r1(_x3)); if(0==__v) goto __return; r0(__v);   // `c.j$<val>
  __v=__K2S_cast(&_vc_S2,r1(_x2)); if(0==__v) goto __return; r0(__v);   // `c.S$<val>
  __v=__K2j_cast(&_vc_j3,r1(_x1)); if(0==__v) goto __return; r0(__v);   // `c.j$<val>
  _c_res=TF_OperationOutputListLength((TF_Operation*)_vc_j3,_vc_S2,(TF_Status*)_vc_j1);  // C.TF_OperationOutputListLength[<val>;_vc_S2;<val>]
  // c.res[()]::<val> - no rval, global
  
  // end of statement
  __v=ki(_c_res); if(0==__v) goto __return;   // C.toK[c.res]
  goto __return;  // return cmd

 __return:
  r0(_x1); r0(_x2); r0(_x3); 
  while(__stc>0) r0(__st[--__stc]); 
  return __v;
 };
K tf_tf_TF_OperationNumInputs__q(K _x1){
  K __st[1]; int __stc=0; K __v=(K)1;
  I _c_res; J _vc_j1;
  
  __v=__K2j_cast(&_vc_j1,r1(_x1)); if(0==__v) goto __return; r0(__v);   // `c.j$<val>
  _c_res=TF_OperationNumInputs((TF_Operation*)_vc_j1);  // C.TF_OperationNumInputs[<val>]
  // c.res[()]::<val> - no rval, global
  
  // end of statement
  __v=ki(_c_res); if(0==__v) goto __return;   // C.toK[c.res]
  goto __return;  // return cmd

 __return:
  r0(_x1); 
  while(__stc>0) r0(__st[--__stc]); 
  return __v;
 };
K tf_tf_TF_OperationInputType__q(K _x1){
  K __st[1]; int __stc=0; K __v=(K)1;
  TF_DataType _c_res; TF_Input _vc_TF_Input1;
  
  __v=__K2TF_Input_cast(&_vc_TF_Input1,r1(_x1)); if(0==__v) goto __return; r0(__v);   // `c.TF_Input$<val>
  _c_res=TF_OperationInputType(_vc_TF_Input1);  // C.TF_OperationInputType[_vc_TF_Input1]
  // c.res[()]::<val> - no rval, global
  
  // end of statement
  __v=ki((I)_c_res); if(0==__v) goto __return;   // C.toK[<val>]
  goto __return;  // return cmd

 __return:
  r0(_x1); 
  while(__stc>0) r0(__st[--__stc]); 
  return __v;
 };
K tf_tf_TF_OperationInputListLength__q(K _x1,K _x2,K _x3){
  K __st[1]; int __stc=0; K __v=(K)1;
  I _c_res; J _vc_j1; char* _vc_S2; J _vc_j3;
  
  __v=__K2j_cast(&_vc_j1,r1(_x3)); if(0==__v) goto __return; r0(__v);   // `c.j$<val>
  __v=__K2S_cast(&_vc_S2,r1(_x2)); if(0==__v) goto __return; r0(__v);   // `c.S$<val>
  __v=__K2j_cast(&_vc_j3,r1(_x1)); if(0==__v) goto __return; r0(__v);   // `c.j$<val>
  _c_res=TF_OperationInputListLength((TF_Operation*)_vc_j3,_vc_S2,(TF_Status*)_vc_j1);  // C.TF_OperationInputListLength[<val>;_vc_S2;<val>]
  // c.res[()]::<val> - no rval, global
  
  // end of statement
  __v=ki(_c_res); if(0==__v) goto __return;   // C.toK[c.res]
  goto __return;  // return cmd

 __return:
  r0(_x1); r0(_x2); r0(_x3); 
  while(__stc>0) r0(__st[--__stc]); 
  return __v;
 };
K tf_tf_TF_OperationInput__q(K _x1){
  K __st[1]; int __stc=0; K __v=(K)1;
  TF_Output _c_res; TF_Input _vc_TF_Input1;
  
  __v=__K2TF_Input_cast(&_vc_TF_Input1,r1(_x1)); if(0==__v) goto __return; r0(__v);   // `c.TF_Input$<val>
  _c_res=TF_OperationInput(_vc_TF_Input1);  // C.TF_OperationInput[_vc_TF_Input1]
  // c.res[()]::<val> - no rval, global
  
  // end of statement
  __v=__toKTF_Output(&_c_res); if(0==__v) goto __return;   // C.toK[c.res]
  goto __return;  // return cmd

 __return:
  r0(_x1); 
  while(__stc>0) r0(__st[--__stc]); 
  return __v;
 };
K tf_tf_TF_OperationOutputNumConsumers__q(K _x1){
  K __st[1]; int __stc=0; K __v=(K)1;
  I _c_res; TF_Output _vc_TF_Output1;
  
  __v=__K2TF_Output_cast(&_vc_TF_Output1,r1(_x1)); if(0==__v) goto __return; r0(__v);   // `c.TF_Output$<val>
  _c_res=TF_OperationOutputNumConsumers(_vc_TF_Output1);  // C.TF_OperationOutputNumConsumers[_vc_TF_Output1]
  // c.res[()]::<val> - no rval, global
  
  // end of statement
  __v=ki(_c_res); if(0==__v) goto __return;   // C.toK[c.res]
  goto __return;  // return cmd

 __return:
  r0(_x1); 
  while(__stc>0) r0(__st[--__stc]); 
  return __v;
 };
K tf_tf_TF_OperationOutputConsumers__q(K _out){
  K __st[1]; int __stc=0; K __v=(K)1;
  I _c_n; TF_Output _vc_TF_Output1; _Bool _vc_bool1; J _vc_j2; char* _vc_C2; TF_Output _vc_TF_Output3; I _vc_i1;
  K _v=r1(__consts[0]); K _r=r1(__consts[0]); 
  __v=__K2TF_Output_cast(&_vc_TF_Output1,r1(_out)); if(0==__v) goto __return; r0(__v);   // `c.TF_Output$<val>
  _c_n=TF_OperationOutputNumConsumers(_vc_TF_Output1);  // C.TF_OperationOutputNumConsumers[_vc_TF_Output1]
  // c.n[()]::<val>
  _vc_bool1=0>=_c_n;  // ~<[0;<val>]
  if(0==_vc_bool1) goto __l2;  // if/while check condition
  __v=ki(_c_n); if(0==__v) goto __return;   // C.toK[c.n]
  r0(__v); 
  // end of statement

 __l2:
  _vc_j2=(J)sizeof(TF_Input)*_c_n;  // *[<val>;c.n]
  __v=kj(_vc_j2); if(0==__v) goto __return;   // C.toK[_vc_j2]
  __v=kdot(r1(__consts[52]),knk(2,__v,r1(__consts[120]))); if(0==__v) goto __return;   // #[<val>;0x00]
  r0(_v); _v=__v;  // v:<val> - no rval, local
  
  // end of statement
  __v=__K2C_cast(&_vc_C2,r1(_v)); if(0==__v) goto __return; r0(__v);   // `c.C$<val>
  __v=__K2TF_Output_cast(&_vc_TF_Output3,r1(_out)); if(0==__v) goto __return; r0(__v);   // `c.TF_Output$<val>
  _vc_i1=TF_OperationOutputConsumers(_vc_TF_Output3,(TF_Input*)(void*)_vc_C2,_c_n);  // C.TF_OperationOutputConsumers[_vc_TF_Output3;<val>;c.n]
  __v=ki(_vc_i1); if(0==__v) goto __return;   // C.toK[_vc_i1]
  r0(_r); _r=__v;__v=r1(_r);   // r:<val>
  __v=kdot(r1(__consts[146]),knk(2,r1(__consts[1]),__v)); if(0==__v) goto __return;   // ~<[0;<val>]
  __v=kif(__v); if(0==__v) goto __return; if(0==__v->j) { r0(__v); goto __l5;}; r0(__v);  // if/while check condition
  __v=r1(__consts[0]);  // const ()
  goto __return;  // return cmd
  r0(__v); 
  // end of statement

 __l5:
  __v=kdot(r1(__consts[60]),knk(2,r1(__consts[148]),r1(_v))); if(0==__v) goto __return;   // 1:[("ji ";8 4 4);v]
  __v=kdot(r1(__consts[55]),knk(2,r1(__consts[107]),__v)); if(0==__v) goto __return;   // ![`oper`index;<val>]
  __v=kdot(r1(__consts[8]),knk(1,__v)); if(0==__v) goto __return;   // flip[<val>]
  __v=kdot(r1(__consts[52]),knk(2,r1(_r),__v)); if(0==__v) goto __return;   // #[r;<val>]
  goto __return;  // return cmd
  r0(__v); 
  // end of statement
  __v=r1(__consts[5]);  // const ::
  goto __return;  // return cmd

 __return:
  r0(_v); r0(_r); r0(_out); 
  while(__stc>0) r0(__st[--__stc]); 
  return __v;
 };
K tf_tf_TF_OperationNumControlInputs__q(K _x1){
  K __st[1]; int __stc=0; K __v=(K)1;
  I _c_res; J _vc_j1;
  
  __v=__K2j_cast(&_vc_j1,r1(_x1)); if(0==__v) goto __return; r0(__v);   // `c.j$<val>
  _c_res=TF_OperationNumControlInputs((TF_Operation*)_vc_j1);  // C.TF_OperationNumControlInputs[<val>]
  // c.res[()]::<val> - no rval, global
  
  // end of statement
  __v=ki(_c_res); if(0==__v) goto __return;   // C.toK[c.res]
  goto __return;  // return cmd

 __return:
  r0(_x1); 
  while(__stc>0) r0(__st[--__stc]); 
  return __v;
 };
K tf_tf_TF_OperationGetControlInputs__q(K _x1,K _x2){
  K __st[1]; int __stc=0; K __v=(K)1;
  I _c_res; J _vc_j1; J* _vc_J2; J _vc_j3;
  
  __v=kdot(r1(__consts[20]),knk(1,r1(_x2))); if(0==__v) goto __return;   // count[x2]
  __v=__K2j_cast(&_vc_j1,__v); if(0==__v) goto __return; r0(__v);   // `c.j$<val>
  __v=__K2J_cast(&_vc_J2,r1(_x2)); if(0==__v) goto __return; r0(__v);   // `c.J$<val>
  __v=__K2j_cast(&_vc_j3,r1(_x1)); if(0==__v) goto __return; r0(__v);   // `c.j$<val>
  _c_res=TF_OperationGetControlInputs((TF_Operation*)_vc_j3,(tfc_TF_Operation_p_p)(void*)_vc_J2,(I)(tfc_ij)_vc_j1);  // C.TF_OperationGetControlInputs[<val>;<val>;<val>]
  // c.res[()]::<val> - no rval, global
  
  // end of statement
  __v=ki(_c_res); if(0==__v) goto __return;   // C.toK[c.res]
  goto __return;  // return cmd

 __return:
  r0(_x1); r0(_x2); 
  while(__stc>0) r0(__st[--__stc]); 
  return __v;
 };
K tf_tf_TF_OperationNumControlOutputs__q(K _x1){
  K __st[1]; int __stc=0; K __v=(K)1;
  I _c_res; J _vc_j1;
  
  __v=__K2j_cast(&_vc_j1,r1(_x1)); if(0==__v) goto __return; r0(__v);   // `c.j$<val>
  _c_res=TF_OperationNumControlOutputs((TF_Operation*)_vc_j1);  // C.TF_OperationNumControlOutputs[<val>]
  // c.res[()]::<val> - no rval, global
  
  // end of statement
  __v=ki(_c_res); if(0==__v) goto __return;   // C.toK[c.res]
  goto __return;  // return cmd

 __return:
  r0(_x1); 
  while(__stc>0) r0(__st[--__stc]); 
  return __v;
 };
K tf_tf_TF_OperationGetControlOutputs__q(K _x1,K _x2){
  K __st[1]; int __stc=0; K __v=(K)1;
  I _c_res; J _vc_j1; J* _vc_J2; J _vc_j3;
  
  __v=kdot(r1(__consts[20]),knk(1,r1(_x2))); if(0==__v) goto __return;   // count[x2]
  __v=__K2j_cast(&_vc_j1,__v); if(0==__v) goto __return; r0(__v);   // `c.j$<val>
  __v=__K2J_cast(&_vc_J2,r1(_x2)); if(0==__v) goto __return; r0(__v);   // `c.J$<val>
  __v=__K2j_cast(&_vc_j3,r1(_x1)); if(0==__v) goto __return; r0(__v);   // `c.j$<val>
  _c_res=TF_OperationGetControlOutputs((TF_Operation*)_vc_j3,(tfc_TF_Operation_p_p)(void*)_vc_J2,(I)(tfc_ij)_vc_j1);  // C.TF_OperationGetControlOutputs[<val>;<val>;<val>]
  // c.res[()]::<val> - no rval, global
  
  // end of statement
  __v=ki(_c_res); if(0==__v) goto __return;   // C.toK[c.res]
  goto __return;  // return cmd

 __return:
  r0(_x1); r0(_x2); 
  while(__stc>0) r0(__st[--__stc]); 
  return __v;
 };
K tf_tf_TF_OperationGetAttrMetadata__q(K _x1,K _x2,K _x3){
  K __st[1]; int __stc=0; K __v=(K)1;
  TF_AttrMetadata _c_res; J _vc_j1; char* _vc_S2; J _vc_j3;
  
  __v=__K2j_cast(&_vc_j1,r1(_x3)); if(0==__v) goto __return; r0(__v);   // `c.j$<val>
  __v=__K2S_cast(&_vc_S2,r1(_x2)); if(0==__v) goto __return; r0(__v);   // `c.S$<val>
  __v=__K2j_cast(&_vc_j3,r1(_x1)); if(0==__v) goto __return; r0(__v);   // `c.j$<val>
  _c_res=TF_OperationGetAttrMetadata((TF_Operation*)_vc_j3,_vc_S2,(TF_Status*)_vc_j1);  // C.TF_OperationGetAttrMetadata[<val>;_vc_S2;<val>]
  // c.res[()]::<val> - no rval, global
  
  // end of statement
  __v=__toKTF_AttrMetadata(&_c_res); if(0==__v) goto __return;   // C.toK[c.res]
  goto __return;  // return cmd

 __return:
  r0(_x1); r0(_x2); r0(_x3); 
  while(__stc>0) r0(__st[--__stc]); 
  return __v;
 };
K tf_tf_TF_OperationGetAttrString__q(K _x1,K _x2,K _x3,K _x5){
  K __st[1]; int __stc=0; K __v=(K)1;
  J _vc_j1; J _vc_j2; char* _vc_C3; char* _vc_S4; J _vc_j5;
  
  __v=__K2j_cast(&_vc_j1,r1(_x5)); if(0==__v) goto __return; r0(__v);   // `c.j$<val>
  __v=kdot(r1(__consts[20]),knk(1,r1(_x3))); if(0==__v) goto __return;   // count[x3]
  __v=__K2j_cast(&_vc_j2,__v); if(0==__v) goto __return; r0(__v);   // `c.j$<val>
  __v=__K2C_cast(&_vc_C3,r1(_x3)); if(0==__v) goto __return; r0(__v);   // `c.C$<val>
  __v=__K2S_cast(&_vc_S4,r1(_x2)); if(0==__v) goto __return; r0(__v);   // `c.S$<val>
  __v=__K2j_cast(&_vc_j5,r1(_x1)); if(0==__v) goto __return; r0(__v);   // `c.j$<val>
  TF_OperationGetAttrString((TF_Operation*)_vc_j5,_vc_S4,(void*)_vc_C3,(size_t)(tfc_ij)_vc_j2,(TF_Status*)_vc_j1);  // C.TF_OperationGetAttrString[<val>;_vc_S4;<val>;<val>;<val>]
  
  // end of statement
  __v=r1(__consts[5]);  // const ::
  goto __return;  // return cmd

 __return:
  r0(_x1); r0(_x2); r0(_x3); r0(_x5); 
  while(__stc>0) r0(__st[--__stc]); 
  return __v;
 };
K tf_tf_TF_OperationGetAttrStringList__q(K _x1,K _x2,K _x3,K _x4,K _x6,K _x8){
  K __st[1]; int __stc=0; K __v=(K)1;
  J _vc_j1; J _vc_j2; char* _vc_C3; J _vc_j4; J* _vc_J5; J* _vc_J6; char* _vc_S7; J _vc_j8;
  
  __v=__K2j_cast(&_vc_j1,r1(_x8)); if(0==__v) goto __return; r0(__v);   // `c.j$<val>
  __v=kdot(r1(__consts[20]),knk(1,r1(_x6))); if(0==__v) goto __return;   // count[x6]
  __v=__K2j_cast(&_vc_j2,__v); if(0==__v) goto __return; r0(__v);   // `c.j$<val>
  __v=__K2C_cast(&_vc_C3,r1(_x6)); if(0==__v) goto __return; r0(__v);   // `c.C$<val>
  __v=kdot(r1(__consts[20]),knk(1,r1(_x3))); if(0==__v) goto __return;   // count[x3]
  __v=__K2j_cast(&_vc_j4,__v); if(0==__v) goto __return; r0(__v);   // `c.j$<val>
  __v=__K2J_cast(&_vc_J5,r1(_x4)); if(0==__v) goto __return; r0(__v);   // `c.J$<val>
  __v=__K2J_cast(&_vc_J6,r1(_x3)); if(0==__v) goto __return; r0(__v);   // `c.J$<val>
  __v=__K2S_cast(&_vc_S7,r1(_x2)); if(0==__v) goto __return; r0(__v);   // `c.S$<val>
  __v=__K2j_cast(&_vc_j8,r1(_x1)); if(0==__v) goto __return; r0(__v);   // `c.j$<val>
  TF_OperationGetAttrStringList((TF_Operation*)_vc_j8,_vc_S7,(tfc_void_p_p)(void*)_vc_J6,(size_t*)(void*)_vc_J5,(size_t)(tfc_ij)_vc_j4,(void*)_vc_C3,(size_t)(tfc_ij)_vc_j2,(TF_Status*)_vc_j1);  // C.TF_OperationGetAttrStringList[<val>;_vc_S7;<val>;<val>;<val>;<val>;<val>;<val>]
  
  // end of statement
  __v=r1(__consts[5]);  // const ::
  goto __return;  // return cmd

 __return:
  r0(_x1); r0(_x2); r0(_x3); r0(_x4); r0(_x6); r0(_x8); 
  while(__stc>0) r0(__st[--__stc]); 
  return __v;
 };
K tf_tf_TF_OperationGetAttrInt__q(K _x1,K _x2,K _x4){
  K __st[1]; int __stc=0; K __v=(K)1;
  long _c_c3; J _vc_j1; char* _vc_S3; J _vc_j4;
  
  __v=__K2j_cast(&_vc_j1,r1(_x4)); if(0==__v) goto __return; r0(__v);   // `c.j$<val>
  __v=__K2S_cast(&_vc_S3,r1(_x2)); if(0==__v) goto __return; r0(__v);   // `c.S$<val>
  __v=__K2j_cast(&_vc_j4,r1(_x1)); if(0==__v) goto __return; r0(__v);   // `c.j$<val>
  TF_OperationGetAttrInt((TF_Operation*)_vc_j4,_vc_S3,&_c_c3,(TF_Status*)_vc_j1);  // C.TF_OperationGetAttrInt[<val>;_vc_S3;<val>;<val>]
  
  // end of statement
  __v=kj((J)_c_c3); if(0==__v) goto __return;   // C.toK[<val>]
  goto __return;  // return cmd

 __return:
  r0(_x1); r0(_x2); r0(_x4); 
  while(__stc>0) r0(__st[--__stc]); 
  return __v;
 };
K tf_tf_TF_OperationGetAttrIntList__q(K _x1,K _x2,K _x3,K _x5){
  K __st[1]; int __stc=0; K __v=(K)1;
  J _vc_j1; J _vc_j2; J* _vc_J3; char* _vc_S4; J _vc_j5;
  
  __v=__K2j_cast(&_vc_j1,r1(_x5)); if(0==__v) goto __return; r0(__v);   // `c.j$<val>
  __v=kdot(r1(__consts[20]),knk(1,r1(_x3))); if(0==__v) goto __return;   // count[x3]
  __v=__K2j_cast(&_vc_j2,__v); if(0==__v) goto __return; r0(__v);   // `c.j$<val>
  __v=__K2J_cast(&_vc_J3,r1(_x3)); if(0==__v) goto __return; r0(__v);   // `c.J$<val>
  __v=__K2S_cast(&_vc_S4,r1(_x2)); if(0==__v) goto __return; r0(__v);   // `c.S$<val>
  __v=__K2j_cast(&_vc_j5,r1(_x1)); if(0==__v) goto __return; r0(__v);   // `c.j$<val>
  TF_OperationGetAttrIntList((TF_Operation*)_vc_j5,_vc_S4,(long*)_vc_J3,(I)(tfc_ij)_vc_j2,(TF_Status*)_vc_j1);  // C.TF_OperationGetAttrIntList[<val>;_vc_S4;<val>;<val>;<val>]
  
  // end of statement
  __v=r1(__consts[5]);  // const ::
  goto __return;  // return cmd

 __return:
  r0(_x1); r0(_x2); r0(_x3); r0(_x5); 
  while(__stc>0) r0(__st[--__stc]); 
  return __v;
 };
K tf_tf_TF_OperationGetAttrFloat__q(K _x1,K _x2,K _x4){
  K __st[1]; int __stc=0; K __v=(K)1;
  E _c_c3; J _vc_j1; char* _vc_S3; J _vc_j4;
  
  __v=__K2j_cast(&_vc_j1,r1(_x4)); if(0==__v) goto __return; r0(__v);   // `c.j$<val>
  __v=__K2S_cast(&_vc_S3,r1(_x2)); if(0==__v) goto __return; r0(__v);   // `c.S$<val>
  __v=__K2j_cast(&_vc_j4,r1(_x1)); if(0==__v) goto __return; r0(__v);   // `c.j$<val>
  TF_OperationGetAttrFloat((TF_Operation*)_vc_j4,_vc_S3,&_c_c3,(TF_Status*)_vc_j1);  // C.TF_OperationGetAttrFloat[<val>;_vc_S3;<val>;<val>]
  
  // end of statement
  __v=kf((F)_c_c3); if(0==__v) goto __return;   // C.toK[<val>]
  goto __return;  // return cmd

 __return:
  r0(_x1); r0(_x2); r0(_x4); 
  while(__stc>0) r0(__st[--__stc]); 
  return __v;
 };
K tf_tf_TF_OperationGetAttrFloatList__q(K _x1,K _x2,K _x3,K _x5){
  K __st[1]; int __stc=0; K __v=(K)1;
  J _vc_j1; J _vc_j2; E* _vc_E3; char* _vc_S4; J _vc_j5;
  
  __v=__K2j_cast(&_vc_j1,r1(_x5)); if(0==__v) goto __return; r0(__v);   // `c.j$<val>
  __v=kdot(r1(__consts[20]),knk(1,r1(_x3))); if(0==__v) goto __return;   // count[x3]
  __v=__K2j_cast(&_vc_j2,__v); if(0==__v) goto __return; r0(__v);   // `c.j$<val>
  __v=__K2E_cast(&_vc_E3,r1(_x3)); if(0==__v) goto __return; r0(__v);   // `c.E$<val>
  __v=__K2S_cast(&_vc_S4,r1(_x2)); if(0==__v) goto __return; r0(__v);   // `c.S$<val>
  __v=__K2j_cast(&_vc_j5,r1(_x1)); if(0==__v) goto __return; r0(__v);   // `c.j$<val>
  TF_OperationGetAttrFloatList((TF_Operation*)_vc_j5,_vc_S4,_vc_E3,(I)(tfc_ij)_vc_j2,(TF_Status*)_vc_j1);  // C.TF_OperationGetAttrFloatList[<val>;_vc_S4;_vc_E3;<val>;<val>]
  
  // end of statement
  __v=r1(__consts[5]);  // const ::
  goto __return;  // return cmd

 __return:
  r0(_x1); r0(_x2); r0(_x3); r0(_x5); 
  while(__stc>0) r0(__st[--__stc]); 
  return __v;
 };
K tf_tf_TF_OperationGetAttrBool__q(K _x1,K _x2,K _x4){
  K __st[1]; int __stc=0; K __v=(K)1;
  char _c_c3; J _vc_j1; char* _vc_S3; J _vc_j4;
  
  __v=__K2j_cast(&_vc_j1,r1(_x4)); if(0==__v) goto __return; r0(__v);   // `c.j$<val>
  __v=__K2S_cast(&_vc_S3,r1(_x2)); if(0==__v) goto __return; r0(__v);   // `c.S$<val>
  __v=__K2j_cast(&_vc_j4,r1(_x1)); if(0==__v) goto __return; r0(__v);   // `c.j$<val>
  TF_OperationGetAttrBool((TF_Operation*)_vc_j4,_vc_S3,&_c_c3,(TF_Status*)_vc_j1);  // C.TF_OperationGetAttrBool[<val>;_vc_S3;<val>;<val>]
  
  // end of statement
  __v=kc((int)_c_c3); if(0==__v) goto __return;   // C.toK[c.c3]
  goto __return;  // return cmd

 __return:
  r0(_x1); r0(_x2); r0(_x4); 
  while(__stc>0) r0(__st[--__stc]); 
  return __v;
 };
K tf_tf_TF_OperationGetAttrBoolList__q(K _x1,K _x2,K _x3,K _x5){
  K __st[1]; int __stc=0; K __v=(K)1;
  J _vc_j1; J _vc_j2; char* _vc_C3; char* _vc_S4; J _vc_j5;
  
  __v=__K2j_cast(&_vc_j1,r1(_x5)); if(0==__v) goto __return; r0(__v);   // `c.j$<val>
  __v=kdot(r1(__consts[20]),knk(1,r1(_x3))); if(0==__v) goto __return;   // count[x3]
  __v=__K2j_cast(&_vc_j2,__v); if(0==__v) goto __return; r0(__v);   // `c.j$<val>
  __v=__K2C_cast(&_vc_C3,r1(_x3)); if(0==__v) goto __return; r0(__v);   // `c.C$<val>
  __v=__K2S_cast(&_vc_S4,r1(_x2)); if(0==__v) goto __return; r0(__v);   // `c.S$<val>
  __v=__K2j_cast(&_vc_j5,r1(_x1)); if(0==__v) goto __return; r0(__v);   // `c.j$<val>
  TF_OperationGetAttrBoolList((TF_Operation*)_vc_j5,_vc_S4,_vc_C3,(I)(tfc_ij)_vc_j2,(TF_Status*)_vc_j1);  // C.TF_OperationGetAttrBoolList[<val>;_vc_S4;_vc_C3;<val>;<val>]
  
  // end of statement
  __v=r1(__consts[5]);  // const ::
  goto __return;  // return cmd

 __return:
  r0(_x1); r0(_x2); r0(_x3); r0(_x5); 
  while(__stc>0) r0(__st[--__stc]); 
  return __v;
 };
K tf_tf_TF_OperationGetAttrType__q(K _x1,K _x2,K _x4){
  K __st[1]; int __stc=0; K __v=(K)1;
  TF_DataType _c_c3; J _vc_j1; char* _vc_S3; J _vc_j4;
  
  __v=__K2j_cast(&_vc_j1,r1(_x4)); if(0==__v) goto __return; r0(__v);   // `c.j$<val>
  __v=__K2S_cast(&_vc_S3,r1(_x2)); if(0==__v) goto __return; r0(__v);   // `c.S$<val>
  __v=__K2j_cast(&_vc_j4,r1(_x1)); if(0==__v) goto __return; r0(__v);   // `c.j$<val>
  TF_OperationGetAttrType((TF_Operation*)_vc_j4,_vc_S3,&_c_c3,(TF_Status*)_vc_j1);  // C.TF_OperationGetAttrType[<val>;_vc_S3;<val>;<val>]
  
  // end of statement
  __v=ki((I)_c_c3); if(0==__v) goto __return;   // C.toK[<val>]
  goto __return;  // return cmd

 __return:
  r0(_x1); r0(_x2); r0(_x4); 
  while(__stc>0) r0(__st[--__stc]); 
  return __v;
 };
K tf_tf_TF_OperationGetAttrTypeList__q(K _x1,K _x2,K _x3,K _x5){
  K __st[1]; int __stc=0; K __v=(K)1;
  J _vc_j1; J _vc_j2; I* _vc_I3; char* _vc_S4; J _vc_j5;
  
  __v=__K2j_cast(&_vc_j1,r1(_x5)); if(0==__v) goto __return; r0(__v);   // `c.j$<val>
  __v=kdot(r1(__consts[20]),knk(1,r1(_x3))); if(0==__v) goto __return;   // count[x3]
  __v=__K2j_cast(&_vc_j2,__v); if(0==__v) goto __return; r0(__v);   // `c.j$<val>
  __v=__K2I_cast(&_vc_I3,r1(_x3)); if(0==__v) goto __return; r0(__v);   // `c.I$<val>
  __v=__K2S_cast(&_vc_S4,r1(_x2)); if(0==__v) goto __return; r0(__v);   // `c.S$<val>
  __v=__K2j_cast(&_vc_j5,r1(_x1)); if(0==__v) goto __return; r0(__v);   // `c.j$<val>
  TF_OperationGetAttrTypeList((TF_Operation*)_vc_j5,_vc_S4,(TF_DataType*)(void*)_vc_I3,(I)(tfc_ij)_vc_j2,(TF_Status*)_vc_j1);  // C.TF_OperationGetAttrTypeList[<val>;_vc_S4;<val>;<val>;<val>]
  
  // end of statement
  __v=r1(__consts[5]);  // const ::
  goto __return;  // return cmd

 __return:
  r0(_x1); r0(_x2); r0(_x3); r0(_x5); 
  while(__stc>0) r0(__st[--__stc]); 
  return __v;
 };
K tf_tf_TF_OperationGetAttrShape__q(K _x1,K _x2,K _x3,K _x5){
  K __st[1]; int __stc=0; K __v=(K)1;
  J _vc_j1; J _vc_j2; J* _vc_J3; char* _vc_S4; J _vc_j5;
  
  __v=__K2j_cast(&_vc_j1,r1(_x5)); if(0==__v) goto __return; r0(__v);   // `c.j$<val>
  __v=kdot(r1(__consts[20]),knk(1,r1(_x3))); if(0==__v) goto __return;   // count[x3]
  __v=__K2j_cast(&_vc_j2,__v); if(0==__v) goto __return; r0(__v);   // `c.j$<val>
  __v=__K2J_cast(&_vc_J3,r1(_x3)); if(0==__v) goto __return; r0(__v);   // `c.J$<val>
  __v=__K2S_cast(&_vc_S4,r1(_x2)); if(0==__v) goto __return; r0(__v);   // `c.S$<val>
  __v=__K2j_cast(&_vc_j5,r1(_x1)); if(0==__v) goto __return; r0(__v);   // `c.j$<val>
  TF_OperationGetAttrShape((TF_Operation*)_vc_j5,_vc_S4,(long*)_vc_J3,(I)(tfc_ij)_vc_j2,(TF_Status*)_vc_j1);  // C.TF_OperationGetAttrShape[<val>;_vc_S4;<val>;<val>;<val>]
  
  // end of statement
  __v=r1(__consts[5]);  // const ::
  goto __return;  // return cmd

 __return:
  r0(_x1); r0(_x2); r0(_x3); r0(_x5); 
  while(__stc>0) r0(__st[--__stc]); 
  return __v;
 };
K tf_tf_TF_OperationGetAttrShapeList__q(K _x1,K _x2,K _x3,K _x4,K _x6,K _x8){
  K __st[1]; int __stc=0; K __v=(K)1;
  J _vc_j1; J _vc_j2; J* _vc_J3; J _vc_j4; I* _vc_I5; J* _vc_J6; char* _vc_S7; J _vc_j8;
  
  __v=__K2j_cast(&_vc_j1,r1(_x8)); if(0==__v) goto __return; r0(__v);   // `c.j$<val>
  __v=kdot(r1(__consts[20]),knk(1,r1(_x6))); if(0==__v) goto __return;   // count[x6]
  __v=__K2j_cast(&_vc_j2,__v); if(0==__v) goto __return; r0(__v);   // `c.j$<val>
  __v=__K2J_cast(&_vc_J3,r1(_x6)); if(0==__v) goto __return; r0(__v);   // `c.J$<val>
  __v=kdot(r1(__consts[20]),knk(1,r1(_x3))); if(0==__v) goto __return;   // count[x3]
  __v=__K2j_cast(&_vc_j4,__v); if(0==__v) goto __return; r0(__v);   // `c.j$<val>
  __v=__K2I_cast(&_vc_I5,r1(_x4)); if(0==__v) goto __return; r0(__v);   // `c.I$<val>
  __v=__K2J_cast(&_vc_J6,r1(_x3)); if(0==__v) goto __return; r0(__v);   // `c.J$<val>
  __v=__K2S_cast(&_vc_S7,r1(_x2)); if(0==__v) goto __return; r0(__v);   // `c.S$<val>
  __v=__K2j_cast(&_vc_j8,r1(_x1)); if(0==__v) goto __return; r0(__v);   // `c.j$<val>
  TF_OperationGetAttrShapeList((TF_Operation*)_vc_j8,_vc_S7,(tfc_long_p_p)(void*)_vc_J6,_vc_I5,(I)(tfc_ij)_vc_j4,(long*)_vc_J3,(I)(tfc_ij)_vc_j2,(TF_Status*)_vc_j1);  // C.TF_OperationGetAttrShapeList[<val>;_vc_S7;<val>;_vc_I5;<val>;<val>;<val>;<val>]
  
  // end of statement
  __v=r1(__consts[5]);  // const ::
  goto __return;  // return cmd

 __return:
  r0(_x1); r0(_x2); r0(_x3); r0(_x4); r0(_x6); r0(_x8); 
  while(__stc>0) r0(__st[--__stc]); 
  return __v;
 };
K tf_tf_TF_OperationGetAttrTensorShapeProto__q(K _x1,K _x2,K _x3,K _x4){
  K __st[1]; int __stc=0; K __v=(K)1;
  J _vc_j1; J _vc_j2; char* _vc_S3; J _vc_j4;
  
  __v=__K2j_cast(&_vc_j1,r1(_x4)); if(0==__v) goto __return; r0(__v);   // `c.j$<val>
  __v=__K2j_cast(&_vc_j2,r1(_x3)); if(0==__v) goto __return; r0(__v);   // `c.j$<val>
  __v=__K2S_cast(&_vc_S3,r1(_x2)); if(0==__v) goto __return; r0(__v);   // `c.S$<val>
  __v=__K2j_cast(&_vc_j4,r1(_x1)); if(0==__v) goto __return; r0(__v);   // `c.j$<val>
  TF_OperationGetAttrTensorShapeProto((TF_Operation*)_vc_j4,_vc_S3,(TF_Buffer*)_vc_j2,(TF_Status*)_vc_j1);  // C.TF_OperationGetAttrTensorShapeProto[<val>;_vc_S3;<val>;<val>]
  
  // end of statement
  __v=r1(__consts[5]);  // const ::
  goto __return;  // return cmd

 __return:
  r0(_x1); r0(_x2); r0(_x3); r0(_x4); 
  while(__stc>0) r0(__st[--__stc]); 
  return __v;
 };
K tf_tf_TF_OperationGetAttrTensor__q(K _x1,K _x2,K _x4){
  K __st[1]; int __stc=0; K __v=(K)1;
  TF_Tensor* _c_c3; J _vc_j1; char* _vc_S3; J _vc_j4;
  
  __v=__K2j_cast(&_vc_j1,r1(_x4)); if(0==__v) goto __return; r0(__v);   // `c.j$<val>
  __v=__K2S_cast(&_vc_S3,r1(_x2)); if(0==__v) goto __return; r0(__v);   // `c.S$<val>
  __v=__K2j_cast(&_vc_j4,r1(_x1)); if(0==__v) goto __return; r0(__v);   // `c.j$<val>
  TF_OperationGetAttrTensor((TF_Operation*)_vc_j4,_vc_S3,&_c_c3,(TF_Status*)_vc_j1);  // C.TF_OperationGetAttrTensor[<val>;_vc_S3;<val>;<val>]
  
  // end of statement
  __v=kj((J)_c_c3); if(0==__v) goto __return;   // C.toK[<val>]
  goto __return;  // return cmd

 __return:
  r0(_x1); r0(_x2); r0(_x4); 
  while(__stc>0) r0(__st[--__stc]); 
  return __v;
 };
K tf_tf_TF_OperationGetAttrTensorList__q(K _x1,K _x2,K _x3,K _x4,K _x5){
  K __st[1]; int __stc=0; K __v=(K)1;
  J _vc_j1; I _vc_i2; J* _vc_J3; char* _vc_S4; J _vc_j5;
  
  __v=__K2j_cast(&_vc_j1,r1(_x5)); if(0==__v) goto __return; r0(__v);   // `c.j$<val>
  __v=__K2i_cast(&_vc_i2,r1(_x4)); if(0==__v) goto __return; r0(__v);   // `c.i$<val>
  __v=__K2J_cast(&_vc_J3,r1(_x3)); if(0==__v) goto __return; r0(__v);   // `c.J$<val>
  __v=__K2S_cast(&_vc_S4,r1(_x2)); if(0==__v) goto __return; r0(__v);   // `c.S$<val>
  __v=__K2j_cast(&_vc_j5,r1(_x1)); if(0==__v) goto __return; r0(__v);   // `c.j$<val>
  TF_OperationGetAttrTensorList((TF_Operation*)_vc_j5,_vc_S4,(tfc_TF_Tensor_p_p)(void*)_vc_J3,_vc_i2,(TF_Status*)_vc_j1);  // C.TF_OperationGetAttrTensorList[<val>;_vc_S4;<val>;_vc_i2;<val>]
  
  // end of statement
  __v=r1(__consts[5]);  // const ::
  goto __return;  // return cmd

 __return:
  r0(_x1); r0(_x2); r0(_x3); r0(_x4); r0(_x5); 
  while(__stc>0) r0(__st[--__stc]); 
  return __v;
 };
K tf_tf_TF_GraphOperationByName__q(K _x1,K _x2){
  K __st[1]; int __stc=0; K __v=(K)1;
  TF_Operation* _c_res; char* _vc_S1; J _vc_j2;
  
  __v=__K2S_cast(&_vc_S1,r1(_x2)); if(0==__v) goto __return; r0(__v);   // `c.S$<val>
  __v=__K2j_cast(&_vc_j2,r1(_x1)); if(0==__v) goto __return; r0(__v);   // `c.j$<val>
  _c_res=TF_GraphOperationByName((TF_Graph*)_vc_j2,_vc_S1);  // C.TF_GraphOperationByName[<val>;_vc_S1]
  // c.res[()]::<val> - no rval, global
  
  // end of statement
  __v=kj((J)_c_res); if(0==__v) goto __return;   // C.toK[<val>]
  goto __return;  // return cmd

 __return:
  r0(_x1); r0(_x2); 
  while(__stc>0) r0(__st[--__stc]); 
  return __v;
 };
K tf_tf_TF_GraphNextOperation__q(K _x1,K _x2){
  K __st[1]; int __stc=0; K __v=(K)1;
  TF_Operation* _c_res; J* _vc_J1; J _vc_j2;
  
  __v=__K2J_cast(&_vc_J1,r1(_x2)); if(0==__v) goto __return; r0(__v);   // `c.J$<val>
  __v=__K2j_cast(&_vc_j2,r1(_x1)); if(0==__v) goto __return; r0(__v);   // `c.j$<val>
  _c_res=TF_GraphNextOperation((TF_Graph*)_vc_j2,(size_t*)(void*)_vc_J1);  // C.TF_GraphNextOperation[<val>;<val>]
  // c.res[()]::<val> - no rval, global
  
  // end of statement
  __v=kj((J)_c_res); if(0==__v) goto __return;   // C.toK[<val>]
  goto __return;  // return cmd

 __return:
  r0(_x1); r0(_x2); 
  while(__stc>0) r0(__st[--__stc]); 
  return __v;
 };
K tf_tf_TF_GraphToGraphDef__q(K _x1,K _x2,K _x3){
  K __st[1]; int __stc=0; K __v=(K)1;
  J _vc_j1; J _vc_j2; J _vc_j3;
  
  __v=__K2j_cast(&_vc_j1,r1(_x3)); if(0==__v) goto __return; r0(__v);   // `c.j$<val>
  __v=__K2j_cast(&_vc_j2,r1(_x2)); if(0==__v) goto __return; r0(__v);   // `c.j$<val>
  __v=__K2j_cast(&_vc_j3,r1(_x1)); if(0==__v) goto __return; r0(__v);   // `c.j$<val>
  TF_GraphToGraphDef((TF_Graph*)_vc_j3,(TF_Buffer*)_vc_j2,(TF_Status*)_vc_j1);  // C.TF_GraphToGraphDef[<val>;<val>;<val>]
  
  // end of statement
  __v=r1(__consts[5]);  // const ::
  goto __return;  // return cmd

 __return:
  r0(_x1); r0(_x2); r0(_x3); 
  while(__stc>0) r0(__st[--__stc]); 
  return __v;
 };
K tf_tf_TF_GraphGetOpDef__q(K _x1,K _x2,K _x3,K _x4){
  K __st[1]; int __stc=0; K __v=(K)1;
  J _vc_j1; J _vc_j2; char* _vc_S3; J _vc_j4;
  
  __v=__K2j_cast(&_vc_j1,r1(_x4)); if(0==__v) goto __return; r0(__v);   // `c.j$<val>
  __v=__K2j_cast(&_vc_j2,r1(_x3)); if(0==__v) goto __return; r0(__v);   // `c.j$<val>
  __v=__K2S_cast(&_vc_S3,r1(_x2)); if(0==__v) goto __return; r0(__v);   // `c.S$<val>
  __v=__K2j_cast(&_vc_j4,r1(_x1)); if(0==__v) goto __return; r0(__v);   // `c.j$<val>
  TF_GraphGetOpDef((TF_Graph*)_vc_j4,_vc_S3,(TF_Buffer*)_vc_j2,(TF_Status*)_vc_j1);  // C.TF_GraphGetOpDef[<val>;_vc_S3;<val>;<val>]
  
  // end of statement
  __v=r1(__consts[5]);  // const ::
  goto __return;  // return cmd

 __return:
  r0(_x1); r0(_x2); r0(_x3); r0(_x4); 
  while(__stc>0) r0(__st[--__stc]); 
  return __v;
 };
K tf_tf_TF_GraphVersions__q(K _x1,K _x2,K _x3){
  K __st[1]; int __stc=0; K __v=(K)1;
  J _vc_j1; J _vc_j2; J _vc_j3;
  
  __v=__K2j_cast(&_vc_j1,r1(_x3)); if(0==__v) goto __return; r0(__v);   // `c.j$<val>
  __v=__K2j_cast(&_vc_j2,r1(_x2)); if(0==__v) goto __return; r0(__v);   // `c.j$<val>
  __v=__K2j_cast(&_vc_j3,r1(_x1)); if(0==__v) goto __return; r0(__v);   // `c.j$<val>
  TF_GraphVersions((TF_Graph*)_vc_j3,(TF_Buffer*)_vc_j2,(TF_Status*)_vc_j1);  // C.TF_GraphVersions[<val>;<val>;<val>]
  
  // end of statement
  __v=r1(__consts[5]);  // const ::
  goto __return;  // return cmd

 __return:
  r0(_x1); r0(_x2); r0(_x3); 
  while(__stc>0) r0(__st[--__stc]); 
  return __v;
 };
K tf_tf_TF_NewImportGraphDefOptions__q(K _x1){
  K __st[1]; int __stc=0; K __v=(K)1;
  TF_ImportGraphDefOptions* _c_res;
  
  _c_res=TF_NewImportGraphDefOptions();  // C.TF_NewImportGraphDefOptions[::]
  // c.res[()]::<val> - no rval, global
  
  // end of statement
  __v=kj((J)_c_res); if(0==__v) goto __return;   // C.toK[<val>]
  goto __return;  // return cmd

 __return:
  r0(_x1); 
  while(__stc>0) r0(__st[--__stc]); 
  return __v;
 };
K tf_tf_TF_DeleteImportGraphDefOptions__q(K _x1){
  K __st[1]; int __stc=0; K __v=(K)1;
  J _vc_j1;
  
  __v=__K2j_cast(&_vc_j1,r1(_x1)); if(0==__v) goto __return; r0(__v);   // `c.j$<val>
  TF_DeleteImportGraphDefOptions((TF_ImportGraphDefOptions*)_vc_j1);  // C.TF_DeleteImportGraphDefOptions[<val>]
  
  // end of statement
  __v=r1(__consts[5]);  // const ::
  goto __return;  // return cmd

 __return:
  r0(_x1); 
  while(__stc>0) r0(__st[--__stc]); 
  return __v;
 };
K tf_tf_TF_ImportGraphDefOptionsSetPrefix__q(K _x1,K _x2){
  K __st[1]; int __stc=0; K __v=(K)1;
  char* _vc_S1; J _vc_j2;
  
  __v=__K2S_cast(&_vc_S1,r1(_x2)); if(0==__v) goto __return; r0(__v);   // `c.S$<val>
  __v=__K2j_cast(&_vc_j2,r1(_x1)); if(0==__v) goto __return; r0(__v);   // `c.j$<val>
  TF_ImportGraphDefOptionsSetPrefix((TF_ImportGraphDefOptions*)_vc_j2,_vc_S1);  // C.TF_ImportGraphDefOptionsSetPrefix[<val>;_vc_S1]
  
  // end of statement
  __v=r1(__consts[5]);  // const ::
  goto __return;  // return cmd

 __return:
  r0(_x1); r0(_x2); 
  while(__stc>0) r0(__st[--__stc]); 
  return __v;
 };
K tf_tf_TF_ImportGraphDefOptionsSetUniquifyNames__q(K _x1,K _x2){
  K __st[1]; int __stc=0; K __v=(K)1;
  char _vc_c1; J _vc_j2;
  
  __v=__K2c_cast(&_vc_c1,r1(_x2)); if(0==__v) goto __return; r0(__v);   // `c.c$<val>
  __v=__K2j_cast(&_vc_j2,r1(_x1)); if(0==__v) goto __return; r0(__v);   // `c.j$<val>
  TF_ImportGraphDefOptionsSetUniquifyNames((TF_ImportGraphDefOptions*)_vc_j2,_vc_c1);  // C.TF_ImportGraphDefOptionsSetUniquifyNames[<val>;_vc_c1]
  
  // end of statement
  __v=r1(__consts[5]);  // const ::
  goto __return;  // return cmd

 __return:
  r0(_x1); r0(_x2); 
  while(__stc>0) r0(__st[--__stc]); 
  return __v;
 };
K tf_tf_TF_ImportGraphDefOptionsSetUniquifyPrefix__q(K _x1,K _x2){
  K __st[1]; int __stc=0; K __v=(K)1;
  char _vc_c1; J _vc_j2;
  
  __v=__K2c_cast(&_vc_c1,r1(_x2)); if(0==__v) goto __return; r0(__v);   // `c.c$<val>
  __v=__K2j_cast(&_vc_j2,r1(_x1)); if(0==__v) goto __return; r0(__v);   // `c.j$<val>
  TF_ImportGraphDefOptionsSetUniquifyPrefix((TF_ImportGraphDefOptions*)_vc_j2,_vc_c1);  // C.TF_ImportGraphDefOptionsSetUniquifyPrefix[<val>;_vc_c1]
  
  // end of statement
  __v=r1(__consts[5]);  // const ::
  goto __return;  // return cmd

 __return:
  r0(_x1); r0(_x2); 
  while(__stc>0) r0(__st[--__stc]); 
  return __v;
 };
K tf_tf_TF_ImportGraphDefOptionsAddInputMapping__q(K _x1,K _x2,K _x3,K _x4){
  K __st[1]; int __stc=0; K __v=(K)1;
  TF_Output _vc_TF_Output1; I _vc_i2; char* _vc_S3; J _vc_j4;
  
  __v=__K2TF_Output_cast(&_vc_TF_Output1,r1(_x4)); if(0==__v) goto __return; r0(__v);   // `c.TF_Output$<val>
  __v=__K2i_cast(&_vc_i2,r1(_x3)); if(0==__v) goto __return; r0(__v);   // `c.i$<val>
  __v=__K2S_cast(&_vc_S3,r1(_x2)); if(0==__v) goto __return; r0(__v);   // `c.S$<val>
  __v=__K2j_cast(&_vc_j4,r1(_x1)); if(0==__v) goto __return; r0(__v);   // `c.j$<val>
  TF_ImportGraphDefOptionsAddInputMapping((TF_ImportGraphDefOptions*)_vc_j4,_vc_S3,_vc_i2,_vc_TF_Output1);  // C.TF_ImportGraphDefOptionsAddInputMapping[<val>;_vc_S3;_vc_i2;_vc_TF_Output1]
  
  // end of statement
  __v=r1(__consts[5]);  // const ::
  goto __return;  // return cmd

 __return:
  r0(_x1); r0(_x2); r0(_x3); r0(_x4); 
  while(__stc>0) r0(__st[--__stc]); 
  return __v;
 };
K tf_tf_TF_ImportGraphDefOptionsRemapControlDependency__q(K _x1,K _x2,K _x3){
  K __st[1]; int __stc=0; K __v=(K)1;
  J _vc_j1; char* _vc_S2; J _vc_j3;
  
  __v=__K2j_cast(&_vc_j1,r1(_x3)); if(0==__v) goto __return; r0(__v);   // `c.j$<val>
  __v=__K2S_cast(&_vc_S2,r1(_x2)); if(0==__v) goto __return; r0(__v);   // `c.S$<val>
  __v=__K2j_cast(&_vc_j3,r1(_x1)); if(0==__v) goto __return; r0(__v);   // `c.j$<val>
  TF_ImportGraphDefOptionsRemapControlDependency((TF_ImportGraphDefOptions*)_vc_j3,_vc_S2,(TF_Operation*)_vc_j1);  // C.TF_ImportGraphDefOptionsRemapControlDependency[<val>;_vc_S2;<val>]
  
  // end of statement
  __v=r1(__consts[5]);  // const ::
  goto __return;  // return cmd

 __return:
  r0(_x1); r0(_x2); r0(_x3); 
  while(__stc>0) r0(__st[--__stc]); 
  return __v;
 };
K tf_tf_TF_ImportGraphDefOptionsAddControlDependency__q(K _x1,K _x2){
  K __st[1]; int __stc=0; K __v=(K)1;
  J _vc_j1; J _vc_j2;
  
  __v=__K2j_cast(&_vc_j1,r1(_x2)); if(0==__v) goto __return; r0(__v);   // `c.j$<val>
  __v=__K2j_cast(&_vc_j2,r1(_x1)); if(0==__v) goto __return; r0(__v);   // `c.j$<val>
  TF_ImportGraphDefOptionsAddControlDependency((TF_ImportGraphDefOptions*)_vc_j2,(TF_Operation*)_vc_j1);  // C.TF_ImportGraphDefOptionsAddControlDependency[<val>;<val>]
  
  // end of statement
  __v=r1(__consts[5]);  // const ::
  goto __return;  // return cmd

 __return:
  r0(_x1); r0(_x2); 
  while(__stc>0) r0(__st[--__stc]); 
  return __v;
 };
K tf_tf_TF_ImportGraphDefOptionsAddReturnOutput__q(K _x1,K _x2,K _x3){
  K __st[1]; int __stc=0; K __v=(K)1;
  I _vc_i1; char* _vc_S2; J _vc_j3;
  
  __v=__K2i_cast(&_vc_i1,r1(_x3)); if(0==__v) goto __return; r0(__v);   // `c.i$<val>
  __v=__K2S_cast(&_vc_S2,r1(_x2)); if(0==__v) goto __return; r0(__v);   // `c.S$<val>
  __v=__K2j_cast(&_vc_j3,r1(_x1)); if(0==__v) goto __return; r0(__v);   // `c.j$<val>
  TF_ImportGraphDefOptionsAddReturnOutput((TF_ImportGraphDefOptions*)_vc_j3,_vc_S2,_vc_i1);  // C.TF_ImportGraphDefOptionsAddReturnOutput[<val>;_vc_S2;_vc_i1]
  
  // end of statement
  __v=r1(__consts[5]);  // const ::
  goto __return;  // return cmd

 __return:
  r0(_x1); r0(_x2); r0(_x3); 
  while(__stc>0) r0(__st[--__stc]); 
  return __v;
 };
K tf_tf_TF_ImportGraphDefOptionsNumReturnOutputs__q(K _x1){
  K __st[1]; int __stc=0; K __v=(K)1;
  I _c_res; J _vc_j1;
  
  __v=__K2j_cast(&_vc_j1,r1(_x1)); if(0==__v) goto __return; r0(__v);   // `c.j$<val>
  _c_res=TF_ImportGraphDefOptionsNumReturnOutputs((TF_ImportGraphDefOptions*)_vc_j1);  // C.TF_ImportGraphDefOptionsNumReturnOutputs[<val>]
  // c.res[()]::<val> - no rval, global
  
  // end of statement
  __v=ki(_c_res); if(0==__v) goto __return;   // C.toK[c.res]
  goto __return;  // return cmd

 __return:
  r0(_x1); 
  while(__stc>0) r0(__st[--__stc]); 
  return __v;
 };
K tf_tf_TF_ImportGraphDefOptionsAddReturnOperation__q(K _x1,K _x2){
  K __st[1]; int __stc=0; K __v=(K)1;
  char* _vc_S1; J _vc_j2;
  
  __v=__K2S_cast(&_vc_S1,r1(_x2)); if(0==__v) goto __return; r0(__v);   // `c.S$<val>
  __v=__K2j_cast(&_vc_j2,r1(_x1)); if(0==__v) goto __return; r0(__v);   // `c.j$<val>
  TF_ImportGraphDefOptionsAddReturnOperation((TF_ImportGraphDefOptions*)_vc_j2,_vc_S1);  // C.TF_ImportGraphDefOptionsAddReturnOperation[<val>;_vc_S1]
  
  // end of statement
  __v=r1(__consts[5]);  // const ::
  goto __return;  // return cmd

 __return:
  r0(_x1); r0(_x2); 
  while(__stc>0) r0(__st[--__stc]); 
  return __v;
 };
K tf_tf_TF_ImportGraphDefOptionsNumReturnOperations__q(K _x1){
  K __st[1]; int __stc=0; K __v=(K)1;
  I _c_res; J _vc_j1;
  
  __v=__K2j_cast(&_vc_j1,r1(_x1)); if(0==__v) goto __return; r0(__v);   // `c.j$<val>
  _c_res=TF_ImportGraphDefOptionsNumReturnOperations((TF_ImportGraphDefOptions*)_vc_j1);  // C.TF_ImportGraphDefOptionsNumReturnOperations[<val>]
  // c.res[()]::<val> - no rval, global
  
  // end of statement
  __v=ki(_c_res); if(0==__v) goto __return;   // C.toK[c.res]
  goto __return;  // return cmd

 __return:
  r0(_x1); 
  while(__stc>0) r0(__st[--__stc]); 
  return __v;
 };
K tf_tf_TF_ImportGraphDefResultsReturnOutputs__q(K _r){
  K __st[2]; int __stc=0; K __v=(K)1;
  TF_Output* _c_o; I _c_n; J _vc_j3; _Bool _vc_bool1; J _c_do1;
  K _res=r1(__consts[0]); 
  __v=__K2j_cast(&_vc_j3,r1(_r)); if(0==__v) goto __return; r0(__v);   // `c.j$<val>
  TF_ImportGraphDefResultsReturnOutputs((TF_ImportGraphDefResults*)_vc_j3,&_c_n,&_c_o);  // C.TF_ImportGraphDefResultsReturnOutputs[<val>;<val>;<val>]
  
  // end of statement
  _vc_bool1=_c_n<=0;  // ~>[c.n;0]
  if(0==_vc_bool1) goto __l3;  // if/while check condition
  __v=r1(__consts[0]);  // const ()
  goto __return;  // return cmd
  r0(__v); 
  // end of statement

 __l3:
  r0(_res); _res=r1(__consts[150]);  // res:+`oper`index!(`long$ - no rval, local
  
  // end of statement
  _c_do1=_c_n;  // local _c_do1
    // check that do value is correct

 __l4:
  if(0>=_c_do1)goto __l6; _c_do1-=1;  // do condition
  __v=ki(_c_o[_c_do1].index); if(0==__v) goto __return;   // C.toK[<val>]
  __st[__stc++]=__v; __v=kj((J)_c_o[_c_do1].oper); if(0==__v) goto __return;   // C.toK[<val>]
  __v=__enlist(knk(2,__v,__st[__stc-1]));__stc-=1;  if(0==__v) goto __return;   // enlist[<val>;<val>]
  { K __v1=r1(__consts[0]); K __v2=__v; __v = kamend(__consts[58],_res,__v1,r1(__consts[51]),__v2);}; if(0==__v){_res=r1(__consts[0]);goto __return;}; _res=__v;  // res[()],:<val> - no rval, local
  
  // end of statement
  goto __l4;  // jump back to do/while

 __l6:
  __v=r1(_res);  // local res
  goto __return;  // return cmd
  r0(__v); 
  // end of statement
  __v=r1(__consts[5]);  // const ::
  goto __return;  // return cmd

 __return:
  r0(_res); r0(_r); 
  while(__stc>0) r0(__st[--__stc]); 
  return __v;
 };
K tf_tf_TF_ImportGraphDefResultsReturnOperations__q(K _r){
  K __st[1]; int __stc=0; K __v=(K)1;
  tfc_TF_Operation_p_p _c_o; I _c_n; J _vc_j3; _Bool _vc_bool1; J _c_do1;
  K _res=r1(__consts[0]); 
  __v=__K2j_cast(&_vc_j3,r1(_r)); if(0==__v) goto __return; r0(__v);   // `c.j$<val>
  TF_ImportGraphDefResultsReturnOperations((TF_ImportGraphDefResults*)_vc_j3,&_c_n,&_c_o);  // C.TF_ImportGraphDefResultsReturnOperations[<val>;<val>;<val>]
  
  // end of statement
  _vc_bool1=_c_n<=0;  // ~>[c.n;0]
  if(0==_vc_bool1) goto __l3;  // if/while check condition
  __v=r1(__consts[0]);  // const ()
  goto __return;  // return cmd
  r0(__v); 
  // end of statement

 __l3:
  r0(_res); _res=r1(__consts[0]);  // res:() - no rval, local
  
  // end of statement
  _c_do1=_c_n;  // local _c_do1
    // check that do value is correct

 __l4:
  if(0>=_c_do1)goto __l6; _c_do1-=1;  // do condition
  __v=kj((J)_c_o[_c_do1]); if(0==__v) goto __return;   // C.toK[<val>]
  { K __v1=r1(__consts[0]); K __v2=__v; __v = kamend(__consts[58],_res,__v1,r1(__consts[51]),__v2);}; if(0==__v){_res=r1(__consts[0]);goto __return;}; _res=__v;  // res[()],:<val> - no rval, local
  
  // end of statement
  goto __l4;  // jump back to do/while

 __l6:
  __v=r1(_res);  // local res
  goto __return;  // return cmd
  r0(__v); 
  // end of statement
  __v=r1(__consts[5]);  // const ::
  goto __return;  // return cmd

 __return:
  r0(_res); r0(_r); 
  while(__stc>0) r0(__st[--__stc]); 
  return __v;
 };
K tf_tf_TF_ImportGraphDefResultsMissingUnusedInputMappings__q(K _r){
  K __st[2]; int __stc=0; K __v=(K)1;
  I* _c_i; tfc_cchar_p_p _c_c; I _c_n; J _vc_j4; _Bool _vc_bool1; J _c_do1;
  K _res=r1(__consts[0]); 
  __v=__K2j_cast(&_vc_j4,r1(_r)); if(0==__v) goto __return; r0(__v);   // `c.j$<val>
  TF_ImportGraphDefResultsMissingUnusedInputMappings((TF_ImportGraphDefResults*)_vc_j4,&_c_n,&_c_c,&_c_i);  // C.TF_ImportGraphDefResultsMissingUnusedInputMappings[<val>;<val>;<val>;<val>]
  
  // end of statement
  _vc_bool1=_c_n<=0;  // ~>[c.n;0]
  if(0==_vc_bool1) goto __l3;  // if/while check condition
  __v=r1(__consts[0]);  // const ()
  goto __return;  // return cmd
  r0(__v); 
  // end of statement

 __l3:
  r0(_res); _res=r1(__consts[151]);  // res:+`name`index!(();`in - no rval, local
  
  // end of statement
  _c_do1=_c_n;  // local _c_do1
    // check that do value is correct

 __l4:
  if(0>=_c_do1)goto __l6; _c_do1-=1;  // do condition
  __v=ki(_c_i[_c_do1]); if(0==__v) goto __return;   // C.toK[<val>]
  __st[__stc++]=__v; __v=__toKS((char*)_c_c[_c_do1]); if(0==__v) goto __return;   // C.toK[<val>]
  __v=__enlist(knk(2,__v,__st[__stc-1]));__stc-=1;  if(0==__v) goto __return;   // enlist[<val>;<val>]
  { K __v1=r1(__consts[0]); K __v2=__v; __v = kamend(__consts[58],_res,__v1,r1(__consts[51]),__v2);}; if(0==__v){_res=r1(__consts[0]);goto __return;}; _res=__v;  // res[()],:<val> - no rval, local
  
  // end of statement
  goto __l4;  // jump back to do/while

 __l6:
  __v=r1(_res);  // local res
  goto __return;  // return cmd
  r0(__v); 
  // end of statement
  __v=r1(__consts[5]);  // const ::
  goto __return;  // return cmd

 __return:
  r0(_res); r0(_r); 
  while(__stc>0) r0(__st[--__stc]); 
  return __v;
 };
K tf_tf_TF_DeleteImportGraphDefResults__q(K _x1){
  K __st[1]; int __stc=0; K __v=(K)1;
  J _vc_j1;
  
  __v=__K2j_cast(&_vc_j1,r1(_x1)); if(0==__v) goto __return; r0(__v);   // `c.j$<val>
  TF_DeleteImportGraphDefResults((TF_ImportGraphDefResults*)_vc_j1);  // C.TF_DeleteImportGraphDefResults[<val>]
  
  // end of statement
  __v=r1(__consts[5]);  // const ::
  goto __return;  // return cmd

 __return:
  r0(_x1); 
  while(__stc>0) r0(__st[--__stc]); 
  return __v;
 };
K tf_tf_TF_GraphImportGraphDefWithResults__q(K _x1,K _x2,K _x3,K _x4){
  K __st[1]; int __stc=0; K __v=(K)1;
  TF_ImportGraphDefResults* _c_res; J _vc_j1; J _vc_j2; J _vc_j3; J _vc_j4;
  
  __v=__K2j_cast(&_vc_j1,r1(_x4)); if(0==__v) goto __return; r0(__v);   // `c.j$<val>
  __v=__K2j_cast(&_vc_j2,r1(_x3)); if(0==__v) goto __return; r0(__v);   // `c.j$<val>
  __v=__K2j_cast(&_vc_j3,r1(_x2)); if(0==__v) goto __return; r0(__v);   // `c.j$<val>
  __v=__K2j_cast(&_vc_j4,r1(_x1)); if(0==__v) goto __return; r0(__v);   // `c.j$<val>
  _c_res=TF_GraphImportGraphDefWithResults((TF_Graph*)_vc_j4,(TF_Buffer*)_vc_j3,(TF_ImportGraphDefOptions*)_vc_j2,(TF_Status*)_vc_j1);  // C.TF_GraphImportGraphDefWithResults[<val>;<val>;<val>;<val>]
  // c.res[()]::<val> - no rval, global
  
  // end of statement
  __v=kj((J)_c_res); if(0==__v) goto __return;   // C.toK[<val>]
  goto __return;  // return cmd

 __return:
  r0(_x1); r0(_x2); r0(_x3); r0(_x4); 
  while(__stc>0) r0(__st[--__stc]); 
  return __v;
 };
K tf_tf_TF_GraphImportGraphDefWithReturnOutputs__q(K _g,K _b,K _o,K _s){
  K __st[1]; int __stc=0; K __v=(K)1;
  I _c_n; J _vc_j1; _Bool _vc_bool1; J _vc_j2; char* _vc_C3; J _vc_j4; J _vc_j5; J _vc_j6;
  K _v=r1(__consts[0]); 
  __v=__K2j_cast(&_vc_j1,r1(_o)); if(0==__v) goto __return; r0(__v);   // `c.j$<val>
  _c_n=TF_ImportGraphDefOptionsNumReturnOutputs((TF_ImportGraphDefOptions*)_vc_j1);  // C.TF_ImportGraphDefOptionsNumReturnOutputs[<val>]
  // c.n[()]::<val>
  _vc_bool1=0>=_c_n;  // ~<[0;<val>]
  if(0==_vc_bool1) goto __l3;  // if/while check condition
  __v=r1(__consts[0]);  // const ()
  goto __return;  // return cmd
  r0(__v); 
  // end of statement

 __l3:
  _vc_j2=(J)sizeof(TF_Output)*_c_n;  // *[<val>;c.n]
  __v=kj(_vc_j2); if(0==__v) goto __return;   // C.toK[_vc_j2]
  __v=kdot(r1(__consts[52]),knk(2,__v,r1(__consts[120]))); if(0==__v) goto __return;   // #[<val>;0x00]
  r0(_v); _v=__v;  // v:<val> - no rval, local
  
  // end of statement
  __v=__K2j_cast(&_vc_j1,r1(_s)); if(0==__v) goto __return; r0(__v);   // `c.j$<val>
  __v=__K2C_cast(&_vc_C3,r1(_v)); if(0==__v) goto __return; r0(__v);   // `c.C$<val>
  __v=__K2j_cast(&_vc_j4,r1(_o)); if(0==__v) goto __return; r0(__v);   // `c.j$<val>
  __v=__K2j_cast(&_vc_j5,r1(_b)); if(0==__v) goto __return; r0(__v);   // `c.j$<val>
  __v=__K2j_cast(&_vc_j6,r1(_g)); if(0==__v) goto __return; r0(__v);   // `c.j$<val>
  TF_GraphImportGraphDefWithReturnOutputs((TF_Graph*)_vc_j6,(TF_Buffer*)_vc_j5,(TF_ImportGraphDefOptions*)_vc_j4,(TF_Output*)(void*)_vc_C3,_c_n,(TF_Status*)_vc_j1);  // C.TF_GraphImportGraphDefWithReturnOutputs[<val>;<val>;<val>;<val>;c.n;<val>]
  
  // end of statement
  __v=kdot(r1(__consts[60]),knk(2,r1(__consts[152]),r1(_v))); if(0==__v) goto __return;   // 1:[(8 4;"ji");v]
  __v=kdot(r1(__consts[55]),knk(2,r1(__consts[107]),__v)); if(0==__v) goto __return;   // ![`oper`index;<val>]
  __v=kdot(r1(__consts[8]),knk(1,__v)); if(0==__v) goto __return;   // flip[<val>]
  goto __return;  // return cmd
  r0(__v); 
  // end of statement
  __v=r1(__consts[5]);  // const ::
  goto __return;  // return cmd

 __return:
  r0(_v); r0(_g); r0(_b); r0(_o); r0(_s); 
  while(__stc>0) r0(__st[--__stc]); 
  return __v;
 };
K tf_tf_TF_GraphImportGraphDef__q(K _x1,K _x2,K _x3,K _x4){
  K __st[1]; int __stc=0; K __v=(K)1;
  J _vc_j1; J _vc_j2; J _vc_j3; J _vc_j4;
  
  __v=__K2j_cast(&_vc_j1,r1(_x4)); if(0==__v) goto __return; r0(__v);   // `c.j$<val>
  __v=__K2j_cast(&_vc_j2,r1(_x3)); if(0==__v) goto __return; r0(__v);   // `c.j$<val>
  __v=__K2j_cast(&_vc_j3,r1(_x2)); if(0==__v) goto __return; r0(__v);   // `c.j$<val>
  __v=__K2j_cast(&_vc_j4,r1(_x1)); if(0==__v) goto __return; r0(__v);   // `c.j$<val>
  TF_GraphImportGraphDef((TF_Graph*)_vc_j4,(TF_Buffer*)_vc_j3,(TF_ImportGraphDefOptions*)_vc_j2,(TF_Status*)_vc_j1);  // C.TF_GraphImportGraphDef[<val>;<val>;<val>;<val>]
  
  // end of statement
  __v=r1(__consts[5]);  // const ::
  goto __return;  // return cmd

 __return:
  r0(_x1); r0(_x2); r0(_x3); r0(_x4); 
  while(__stc>0) r0(__st[--__stc]); 
  return __v;
 };
K tf_tf_TF_GraphCopyFunction__q(K _x1,K _x2,K _x3,K _x4){
  K __st[1]; int __stc=0; K __v=(K)1;
  J _vc_j1; J _vc_j2; J _vc_j3; J _vc_j4;
  
  __v=__K2j_cast(&_vc_j1,r1(_x4)); if(0==__v) goto __return; r0(__v);   // `c.j$<val>
  __v=__K2j_cast(&_vc_j2,r1(_x3)); if(0==__v) goto __return; r0(__v);   // `c.j$<val>
  __v=__K2j_cast(&_vc_j3,r1(_x2)); if(0==__v) goto __return; r0(__v);   // `c.j$<val>
  __v=__K2j_cast(&_vc_j4,r1(_x1)); if(0==__v) goto __return; r0(__v);   // `c.j$<val>
  TF_GraphCopyFunction((TF_Graph*)_vc_j4,(TF_Function*)_vc_j3,(TF_Function*)_vc_j2,(TF_Status*)_vc_j1);  // C.TF_GraphCopyFunction[<val>;<val>;<val>;<val>]
  
  // end of statement
  __v=r1(__consts[5]);  // const ::
  goto __return;  // return cmd

 __return:
  r0(_x1); r0(_x2); r0(_x3); r0(_x4); 
  while(__stc>0) r0(__st[--__stc]); 
  return __v;
 };
K tf_tf_TF_OperationToNodeDef__q(K _x1,K _x2,K _x3){
  K __st[1]; int __stc=0; K __v=(K)1;
  J _vc_j1; J _vc_j2; J _vc_j3;
  
  __v=__K2j_cast(&_vc_j1,r1(_x3)); if(0==__v) goto __return; r0(__v);   // `c.j$<val>
  __v=__K2j_cast(&_vc_j2,r1(_x2)); if(0==__v) goto __return; r0(__v);   // `c.j$<val>
  __v=__K2j_cast(&_vc_j3,r1(_x1)); if(0==__v) goto __return; r0(__v);   // `c.j$<val>
  TF_OperationToNodeDef((TF_Operation*)_vc_j3,(TF_Buffer*)_vc_j2,(TF_Status*)_vc_j1);  // C.TF_OperationToNodeDef[<val>;<val>;<val>]
  
  // end of statement
  __v=r1(__consts[5]);  // const ::
  goto __return;  // return cmd

 __return:
  r0(_x1); r0(_x2); r0(_x3); 
  while(__stc>0) r0(__st[--__stc]); 
  return __v;
 };
K tf_tf_createWhileParams(TF_WhileParams* _p){
  K __st[1]; int __stc=0; K __v=(K)1;
  char* _c_res; char* _c_src; char* _vc_C1; J _c_do1;
  K _res=r1(__consts[0]); 
  __v=kj((J)sizeof(TF_WhileParams)); if(0==__v) goto __return;   // C.toK[<val>]
  __v=kdot(r1(__consts[52]),knk(2,__v,r1(__consts[120]))); if(0==__v) goto __return;   // #[<val>;0x00]
  r0(_res); _res=__v;  // res:<val> - no rval, local
  
  // end of statement
  __v=__K2C_cast(&_vc_C1,r1(_res)); if(0==__v) goto __return; r0(__v);   // `c.C$<val>
  _c_res=_vc_C1;  // c.res[()]::_vc_C1 - no rval, global
  
  // end of statement
  _c_src=(char*)(void*)_p;  // c.src[()]::<val> - no rval, global
  
  // end of statement
  __v=kdot(r1(__consts[20]),knk(1,r1(_res))); if(0==__v) goto __return;   // count[res]
  __v=kif(__v); if(0==__v) goto __return; _c_do1=__v->j; r0(__v);  // check that do value is correct

 __l1:
  if(0>=_c_do1)goto __l3; _c_do1-=1;  // do condition
  _c_res[_c_do1]=_c_src[_c_do1];  // c.res[<val>]::<val> - no rval, global
  
  // end of statement
  goto __l1;  // jump back to do/while

 __l3:
  __v=r1(_res);  // local res
  goto __return;  // return cmd

 __return:
  r0(_res); 
  while(__stc>0) r0(__st[--__stc]); 
  return __v;
 };
K tf_tf_setWhileParams__q(K _p,K _name,K _val){
  K __st[1]; int __stc=0; K __v=(K)1;
  TF_WhileParams* _c_p; I _c_i; char* _vc_C1; J _vc_j1; I _vc_i1; char* _vc_S1;
  
  __v=__K2C_cast(&_vc_C1,r1(_p)); if(0==__v) goto __return; r0(__v);   // `c.C$<val>
  _c_p=(TF_WhileParams*)(void*)_vc_C1;  // c.p[()]::<val> - no rval, global
  
  // end of statement
  __v=kdot(r1(__consts[47]),knk(2,r1(_name),r1(__consts[154]))); if(0==__v) goto __return;   // =[name;`cond_output]
  __v=kif(__v); if(0==__v) goto __return; if(0==__v->j) { r0(__v); goto __l3;}; r0(__v);  // if/while check condition
  __v=__K2j_cast(&_vc_j1,r1(_val)); if(0==__v) goto __return; r0(__v);   // `c.j$<val>
  _c_p->cond_output.oper=(TF_Operation*)_vc_j1;  // c.p[`cond_output`oper]::<val> - no rval, global
  
  // end of statement
  _c_p->cond_output.index=0;  // c.p[`cond_output`index]::0 - no rval, global
  
  // end of statement
  __v=r1(_p);  // arg p
  goto __return;  // return cmd
  r0(__v); 
  // end of statement

 __l3:
  __v=kdot(r1(__consts[47]),knk(2,r1(_name),r1(__consts[157]))); if(0==__v) goto __return;   // =[name;`body_outputs]
  __v=kif(__v); if(0==__v) goto __return; if(0==__v->j) { r0(__v); goto __l8;}; r0(__v);  // if/while check condition
  __v=ki(_c_p->ninputs); if(0==__v) goto __return;   // C.toK[<val>]
  __v=kdot(r1(__consts[40]),knk(2,r1(__consts[159]),__v)); if(0==__v) goto __return;   // +[-1;<val>]
  __v=__enlist(knk(2,r1(__consts[1]),__v)); if(0==__v) goto __return;   // enlist[0;<val>]
  __st[__stc++]=__v; __v=kdot(r1(_val),knk(1,r1(__consts[2]))); if(0==__v) goto __return;   // val[1]
  __v=kdot(r1(__consts[63]),knk(2,__v,__st[__stc-1]));__stc-=1;  if(0==__v) goto __return;   // within[<val>;<val>]
  __v=kdot(r1(__consts[22]),knk(1,__v)); if(0==__v) goto __return;   // not[<val>]
  __v=kif(__v); if(0==__v) goto __return; if(0==__v->j) { r0(__v); goto __l6;}; r0(__v);  // if/while check condition
  __v=r1(__consts[160]);  // const "Bad while index"
  __st[__stc++]=__v;  if(__v->t==-KS) __v=krr(__v->s); else if(__v->t==KC)  __v=krr(sn(kC(__v),__v->n)); else __v=krr("stype"); goto __return;  // raise an exception
  r0(__v); 
  // end of statement

 __l6:
  __v=kdot(r1(_val),knk(1,r1(__consts[2]))); if(0==__v) goto __return;   // val[1]
  __v=__K2i_cast(&_vc_i1,__v); if(0==__v) goto __return; r0(__v);   // `c.i$<val>
  _c_i=_vc_i1;  // c.i[()]::_vc_i1 - no rval, global
  
  // end of statement
  __v=kdot(r1(_val),knk(1,r1(__consts[1]))); if(0==__v) goto __return;   // val[0]
  __v=__K2j_cast(&_vc_j1,__v); if(0==__v) goto __return; r0(__v);   // `c.j$<val>
  _c_p->body_outputs[_c_i].oper=(TF_Operation*)_vc_j1;  // c.p[<val>]::<val> - no rval, global
  
  // end of statement
  _c_p->body_outputs[_c_i].index=_c_i;  // c.p[<val>]::c.i - no rval, global
  
  // end of statement
  __v=r1(_p);  // arg p
  goto __return;  // return cmd
  r0(__v); 
  // end of statement

 __l8:
  __v=kdot(r1(__consts[47]),knk(2,r1(_name),r1(__consts[161]))); if(0==__v) goto __return;   // =[name;`name]
  __v=kif(__v); if(0==__v) goto __return; if(0==__v->j) { r0(__v); goto __l11;}; r0(__v);  // if/while check condition
  __v=__K2S_cast(&_vc_S1,r1(_val)); if(0==__v) goto __return; r0(__v);   // `c.S$<val>
  _c_p->name=_vc_S1;  // c.p[,`name]::_vc_S1 - no rval, global
  
  // end of statement
  __v=r1(_p);  // arg p
  goto __return;  // return cmd
  r0(__v); 
  // end of statement

 __l11:
  __v=r1(__consts[163]);  // const "Bad while name"
  __st[__stc++]=__v;  if(__v->t==-KS) __v=krr(__v->s); else if(__v->t==KC)  __v=krr(sn(kC(__v),__v->n)); else __v=krr("stype"); goto __return;  // raise an exception
  r0(__v); 
  // end of statement
  __v=r1(__consts[5]);  // const ::
  goto __return;  // return cmd

 __return:
  r0(_p); r0(_name); r0(_val); 
  while(__stc>0) r0(__st[--__stc]); 
  return __v;
 };
K tf_tf_TF_FinishWhile__q(K _p,K _s){
  K __st[1]; int __stc=0; K __v=(K)1;
  TF_WhileParams* _c_p; char* _vc_C1; J _vc_j2;
  K _v=r1(__consts[0]); 
  __v=__K2C_cast(&_vc_C1,r1(_p)); if(0==__v) goto __return; r0(__v);   // `c.C$<val>
  _c_p=(TF_WhileParams*)(void*)_vc_C1;  // c.p[()]::<val> - no rval, global
  
  // end of statement
  _vc_j2=(J)sizeof(TF_Output)*_c_p->ninputs;  // *[<val>;<val>]
  __v=kj(_vc_j2); if(0==__v) goto __return;   // C.toK[_vc_j2]
  __v=kdot(r1(__consts[52]),knk(2,__v,r1(__consts[120]))); if(0==__v) goto __return;   // #[<val>;0x00]
  r0(_v); _v=__v;  // v:<val> - no rval, local
  
  // end of statement
  __v=__K2C_cast(&_vc_C1,r1(_v)); if(0==__v) goto __return; r0(__v);   // `c.C$<val>
  __v=__K2j_cast(&_vc_j2,r1(_s)); if(0==__v) goto __return; r0(__v);   // `c.j$<val>
  TF_FinishWhile(_c_p,(TF_Status*)_vc_j2,(TF_Output*)(void*)_vc_C1);  // C.TF_FinishWhile[c.p;<val>;<val>]
  
  // end of statement
  __v=kdot(r1(__consts[60]),knk(2,r1(__consts[152]),r1(_v))); if(0==__v) goto __return;   // 1:[(8 4;"ji");v]
  __v=kdot(r1(__consts[55]),knk(2,r1(__consts[107]),__v)); if(0==__v) goto __return;   // ![`oper`index;<val>]
  __v=kdot(r1(__consts[8]),knk(1,__v)); if(0==__v) goto __return;   // flip[<val>]
  __st[__stc++]=__v; __v=ki(_c_p->ninputs); if(0==__v) goto __return;   // C.toK[<val>]
  __v=kdot(r1(__consts[52]),knk(2,__v,__st[__stc-1]));__stc-=1;  if(0==__v) goto __return;   // #[<val>;<val>]
  goto __return;  // return cmd
  r0(__v); 
  // end of statement
  __v=r1(__consts[5]);  // const ::
  goto __return;  // return cmd

 __return:
  r0(_v); r0(_p); r0(_s); 
  while(__stc>0) r0(__st[--__stc]); 
  return __v;
 };
K tf_tf_TF_AbortWhile__q(K _x1){
  K __st[1]; int __stc=0; K __v=(K)1;
  J _vc_j1;
  
  __v=__K2j_cast(&_vc_j1,r1(_x1)); if(0==__v) goto __return; r0(__v);   // `c.j$<val>
  TF_AbortWhile((TF_WhileParams*)_vc_j1);  // C.TF_AbortWhile[<val>]
  
  // end of statement
  __v=r1(__consts[5]);  // const ::
  goto __return;  // return cmd

 __return:
  r0(_x1); 
  while(__stc>0) r0(__st[--__stc]); 
  return __v;
 };
K tf_tf_TF_AddGradients__q(K _g,K _y,K _x,K _dx,K _s){
  K __st[1]; int __stc=0; K __v=(K)1;
  TF_Output* _c_dx; char* _vc_C1; J _vc_j2; I _vc_i4; char* _vc_C5; I _vc_i6; char* _vc_C7; J _vc_j8;
  K _yy=r1(__consts[0]); K _xx=r1(__consts[0]); K _v=r1(__consts[0]); 
  __v=tf_tf_encodeOut__q(r1(_y)); if(0==__v) goto __return;   // .tf.encodeOut[y]
  r0(_yy); _yy=__v;  // yy:<val> - no rval, local
  
  // end of statement
  __v=tf_tf_encodeOut__q(r1(_x)); if(0==__v) goto __return;   // .tf.encodeOut[x]
  r0(_xx); _xx=__v;  // xx:<val> - no rval, local
  
  // end of statement
  __v=kdot(r1(__consts[20]),knk(1,r1(_dx))); if(0==__v) goto __return;   // count[dx]
  __v=kif(__v); if(0==__v) goto __return; if(0==__v->j) { r0(__v); goto __l2;}; r0(__v);  // if/while check condition
  __v=tf_tf_encodeOut__q(r1(_dx)); if(0==__v) goto __return;   // .tf.encodeOut[dx]
  goto __l3;  // jmp to if end

 __l2:
  __v=r1(__consts[0]);  // const <val>

 __l3:
  r0(_dx); _dx=__v;  // dx:<val> - no rval, param
  
  // end of statement
  _c_dx=(TF_Output*)NULL;  // c.dx[()]::<val> - no rval, global
  
  // end of statement
  __v=kdot(r1(__consts[20]),knk(1,r1(_dx))); if(0==__v) goto __return;   // count[dx]
  __v=kif(__v); if(0==__v) goto __return; if(0==__v->j) { r0(__v); goto __l5;}; r0(__v);  // if/while check condition
  __v=__K2C_cast(&_vc_C1,r1(_dx)); if(0==__v) goto __return; r0(__v);   // `c.C$<val>
  _c_dx=(TF_Output*)(void*)_vc_C1;  // c.dx[()]::<val> - no rval, global
  
  // end of statement

 __l5:
  __v=kdot(r1(__consts[20]),knk(1,r1(_x))); if(0==__v) goto __return;   // count[x]
  __st[__stc++]=__v; __v=kj((J)sizeof(TF_Output)); if(0==__v) goto __return;   // C.toK[<val>]
  __v=kdot(r1(__consts[42]),knk(2,__v,__st[__stc-1]));__stc-=1;  if(0==__v) goto __return;   // *[<val>;<val>]
  __v=kdot(r1(__consts[52]),knk(2,__v,r1(__consts[120]))); if(0==__v) goto __return;   // #[<val>;0x00]
  r0(_v); _v=__v;  // v:<val> - no rval, local
  
  // end of statement
  __v=__K2C_cast(&_vc_C1,r1(_v)); if(0==__v) goto __return; r0(__v);   // `c.C$<val>
  __v=__K2j_cast(&_vc_j2,r1(_s)); if(0==__v) goto __return; r0(__v);   // `c.j$<val>
  __v=kdot(r1(__consts[20]),knk(1,r1(_x))); if(0==__v) goto __return;   // count[x]
  __v=kdot(r1(__consts[50]),knk(2,r1(__consts[136]),__v)); if(0==__v) goto __return;   // $["i";<val>]
  __v=__K2i_cast(&_vc_i4,__v); if(0==__v) goto __return; r0(__v);   // `c.i$<val>
  __v=__K2C_cast(&_vc_C5,r1(_xx)); if(0==__v) goto __return; r0(__v);   // `c.C$<val>
  __v=kdot(r1(__consts[20]),knk(1,r1(_y))); if(0==__v) goto __return;   // count[y]
  __v=kdot(r1(__consts[50]),knk(2,r1(__consts[136]),__v)); if(0==__v) goto __return;   // $["i";<val>]
  __v=__K2i_cast(&_vc_i6,__v); if(0==__v) goto __return; r0(__v);   // `c.i$<val>
  __v=__K2C_cast(&_vc_C7,r1(_yy)); if(0==__v) goto __return; r0(__v);   // `c.C$<val>
  __v=__K2j_cast(&_vc_j8,r1(_g)); if(0==__v) goto __return; r0(__v);   // `c.j$<val>
  TF_AddGradients((TF_Graph*)_vc_j8,(TF_Output*)(void*)_vc_C7,_vc_i6,(TF_Output*)(void*)_vc_C5,_vc_i4,_c_dx,(TF_Status*)_vc_j2,(TF_Output*)(void*)_vc_C1);  // C.TF_AddGradients[<val>;<val>;_vc_i6;<val>;_vc_i4;c.dx;<val>;<val>]
  
  // end of statement
  __v=kdot(r1(__consts[60]),knk(2,r1(__consts[152]),r1(_v))); if(0==__v) goto __return;   // 1:[(8 4;"ji");v]
  __v=kdot(r1(__consts[55]),knk(2,r1(__consts[107]),__v)); if(0==__v) goto __return;   // ![`oper`index;<val>]
  __v=kdot(r1(__consts[8]),knk(1,__v)); if(0==__v) goto __return;   // flip[<val>]
  goto __return;  // return cmd
  r0(__v); 
  // end of statement
  __v=r1(__consts[5]);  // const ::
  goto __return;  // return cmd

 __return:
  r0(_yy); r0(_xx); r0(_v); r0(_g); r0(_y); r0(_x); r0(_dx); r0(_s); 
  while(__stc>0) r0(__st[--__stc]); 
  return __v;
 };
K tf_tf_TF_GraphToFunction__q(K _g,K _name,K _hash,K _args,K _o,K _d,K _s){
  K __st[1]; int __stc=0; K __v=(K)1;
  char** _c_s; char* _vc_C1; J _c_do1; char* _vc_S1; J _vc_j1; char* _vc_S2; J _vc_j3; char* _vc_C5; I _vc_i6; char* _vc_C7; I _vc_i8; J* _vc_J9; I _vc_i10; char _vc_c11; char* _vc_S12; J _vc_j13; TF_Function* _vc_TF_Function_p1;
  K _a=r1(__consts[0]); K _c=r1(__consts[0]); K _nops=r1(__consts[0]); K _ops=r1(__consts[0]); K _inp=r1(__consts[0]); K _out=r1(__consts[0]); K _nms=r1(__consts[0]); 
  __v=kdot(r1(_args),knk(1,r1(__consts[1]))); if(0==__v) goto __return;   // args[0]
  r0(_a); _a=__v;__v=r1(_a);   // a:<val>
  __v=kdot(r1(__consts[20]),knk(1,__v)); if(0==__v) goto __return;   // count[<val>]
  r0(_c); _c=__v;__v=r1(_c);   // c:<val>
  __v=kif(__v); if(0==__v) goto __return; if(0==__v->j) { r0(__v); goto __l2;}; r0(__v);  // if/while check condition
  __v=r1(_c);  // local c
  goto __l5;  // jmp to if end

 __l2:
  __v=kdot(r1(__consts[54]),knk(2,r1(_a),r1(__consts[0]))); if(0==__v) goto __return;   // ~[a;()]
  __v=kif(__v); if(0==__v) goto __return; if(0==__v->j) { r0(__v); goto __l4;}; r0(__v);  // if/while check condition
  __v=r1(__consts[159]);  // const -1
  goto __l5;  // jmp to if end

 __l4:
  __v=r1(__consts[1]);  // const <val>

 __l5:
  __v=kdot(r1(__consts[50]),knk(2,r1(__consts[136]),__v)); if(0==__v) goto __return;   // $["i";<val>]
  r0(_nops); _nops=__v;  // nops:<val> - no rval, local
  
  // end of statement
  __v=kdot(r1(__consts[48]),knk(2,r1(_nops),r1(__consts[1]))); if(0==__v) goto __return;   // <[nops;0]
  __v=kif(__v); if(0==__v) goto __return; if(0==__v->j) { r0(__v); goto __l7;}; r0(__v);  // if/while check condition
  __v=r1(__consts[164]);  // const `long$()
  goto __l8;  // jmp to if end

 __l7:
  __v=r1(_a);  // local <val>

 __l8:
  r0(_ops); _ops=__v;  // ops:<val> - no rval, local
  
  // end of statement
  __v=kdot(r1(_args),knk(1,r1(__consts[2]))); if(0==__v) goto __return;   // args[1]
  r0(_a); _a=__v;__v=r1(_a);   // a:<val>
  __v=kdot(r1(__consts[20]),knk(1,__v)); if(0==__v) goto __return;   // count[<val>]
  __v=kif(__v); if(0==__v) goto __return; if(0==__v->j) { r0(__v); goto __l10;}; r0(__v);  // if/while check condition
  __v=tf_tf_encodeOut__q(r1(_a)); if(0==__v) goto __return;   // .tf.encodeOut[a]
  goto __l11;  // jmp to if end

 __l10:
  __v=r1(__consts[165]);  // const <val>

 __l11:
  r0(_inp); _inp=__v;  // inp:<val> - no rval, local
  
  // end of statement
  __v=kdot(r1(_args),knk(1,r1(__consts[166]))); if(0==__v) goto __return;   // args[2]
  r0(_a); _a=__v;__v=r1(_a);   // a:<val>
  __v=kdot(r1(__consts[20]),knk(1,__v)); if(0==__v) goto __return;   // count[<val>]
  __v=kif(__v); if(0==__v) goto __return; if(0==__v->j) { r0(__v); goto __l13;}; r0(__v);  // if/while check condition
  __v=tf_tf_encodeOut__q(r1(_a)); if(0==__v) goto __return;   // .tf.encodeOut[a]
  goto __l14;  // jmp to if end

 __l13:
  __v=r1(__consts[165]);  // const <val>

 __l14:
  r0(_out); _out=__v;  // out:<val> - no rval, local
  
  // end of statement
  _c_s=(char**)NULL;  // c.s[()]::<val> - no rval, global
  
  // end of statement
  __v=kdot(r1(_args),knk(1,r1(__consts[167]))); if(0==__v) goto __return;   // args[3]
  r0(_a); _a=__v;__v=r1(_a);   // a:<val>
  __v=kdot(r1(__consts[20]),knk(1,__v)); if(0==__v) goto __return;   // count[<val>]
  __v=kif(__v); if(0==__v) goto __return; if(0==__v->j) { r0(__v); goto __l19;}; r0(__v);  // if/while check condition
  __v=kdot(r1(__consts[20]),knk(1,r1(_a))); if(0==__v) goto __return;   // count[a]
  __v=kdot(r1(__consts[42]),knk(2,r1(__consts[168]),__v)); if(0==__v) goto __return;   // *[8;<val>]
  __v=kdot(r1(__consts[52]),knk(2,__v,r1(__consts[120]))); if(0==__v) goto __return;   // #[<val>;0x00]
  r0(_nms); _nms=__v;  // nms:<val> - no rval, local
  
  // end of statement
  __v=__K2C_cast(&_vc_C1,r1(_nms)); if(0==__v) goto __return; r0(__v);   // `c.C$<val>
  _c_s=(char**)(void*)_vc_C1;  // c.s[()]::<val> - no rval, global
  
  // end of statement
  __v=kdot(r1(__consts[20]),knk(1,r1(_a))); if(0==__v) goto __return;   // count[a]
  __v=kif(__v); if(0==__v) goto __return; _c_do1=__v->j; r0(__v);  // check that do value is correct

 __l16:
  if(0>=_c_do1)goto __l19; _c_do1-=1;  // do condition
  __v=kj(_c_do1); if(0==__v) goto __return;   // C.toK[c.do1]
  __v=kdot(r1(_a),knk(1,__v)); if(0==__v) goto __return;   // a[<val>]
  __v=__K2S_cast(&_vc_S1,__v); if(0==__v) goto __return; r0(__v);   // `c.S$<val>
  _c_s[_c_do1]=_vc_S1;  // c.s[<val>]::_vc_S1 - no rval, global
  
  // end of statement
  goto __l16;  // jump back to do/while

 __l19:
  __v=__K2j_cast(&_vc_j1,r1(_s)); if(0==__v) goto __return; r0(__v);   // `c.j$<val>
  __v=__K2S_cast(&_vc_S2,r1(_d)); if(0==__v) goto __return; r0(__v);   // `c.S$<val>
  __v=__K2j_cast(&_vc_j3,r1(_o)); if(0==__v) goto __return; r0(__v);   // `c.j$<val>
  __v=__K2C_cast(&_vc_C5,r1(_out)); if(0==__v) goto __return; r0(__v);   // `c.C$<val>
  __v=kdot(r1(_args),knk(1,r1(__consts[166]))); if(0==__v) goto __return;   // args[2]
  __v=kdot(r1(__consts[20]),knk(1,__v)); if(0==__v) goto __return;   // count[<val>]
  __v=kdot(r1(__consts[50]),knk(2,r1(__consts[136]),__v)); if(0==__v) goto __return;   // $["i";<val>]
  __v=__K2i_cast(&_vc_i6,__v); if(0==__v) goto __return; r0(__v);   // `c.i$<val>
  __v=__K2C_cast(&_vc_C7,r1(_inp)); if(0==__v) goto __return; r0(__v);   // `c.C$<val>
  __v=kdot(r1(_args),knk(1,r1(__consts[2]))); if(0==__v) goto __return;   // args[1]
  __v=kdot(r1(__consts[20]),knk(1,__v)); if(0==__v) goto __return;   // count[<val>]
  __v=kdot(r1(__consts[50]),knk(2,r1(__consts[136]),__v)); if(0==__v) goto __return;   // $["i";<val>]
  __v=__K2i_cast(&_vc_i8,__v); if(0==__v) goto __return; r0(__v);   // `c.i$<val>
  __v=__K2J_cast(&_vc_J9,r1(_ops)); if(0==__v) goto __return; r0(__v);   // `c.J$<val>
  __v=__K2i_cast(&_vc_i10,r1(_nops)); if(0==__v) goto __return; r0(__v);   // `c.i$<val>
  __v=__K2c_cast(&_vc_c11,r1(_hash)); if(0==__v) goto __return; r0(__v);   // `c.c$<val>
  __v=__K2S_cast(&_vc_S12,r1(_name)); if(0==__v) goto __return; r0(__v);   // `c.S$<val>
  __v=__K2j_cast(&_vc_j13,r1(_g)); if(0==__v) goto __return; r0(__v);   // `c.j$<val>
  _vc_TF_Function_p1=TF_GraphToFunction((TF_Graph*)_vc_j13,_vc_S12,(unsigned char)_vc_c11,_vc_i10,(const TF_Operation* const*)(void*)_vc_J9,_vc_i8,(TF_Output*)(void*)_vc_C7,_vc_i6,(TF_Output*)(void*)_vc_C5,(tfc_cchar_p_p)(void*)_c_s,(TF_FunctionOptions*)_vc_j3,_vc_S2,(TF_Status*)_vc_j1);  // C.TF_GraphToFunction[<val>;_vc_S12;<val>;_vc_i10;<val>;_vc_i8;<val>;_vc_i6;<val>;<val>;<val>;_vc_S2;<val>]
  __v=kj((J)_vc_TF_Function_p1); if(0==__v) goto __return;   // C.toK[<val>]
  goto __return;  // return cmd
  r0(__v); 
  // end of statement
  __v=r1(__consts[5]);  // const ::
  goto __return;  // return cmd

 __return:
  r0(_a); r0(_c); r0(_nops); r0(_ops); r0(_inp); r0(_out); r0(_nms); r0(_g); r0(_name); r0(_hash); r0(_args); r0(_o); r0(_d); r0(_s); 
  while(__stc>0) r0(__st[--__stc]); 
  return __v;
 };
K tf_tf_TF_FunctionToFunctionDef__q(K _x1,K _x2,K _x3){
  K __st[1]; int __stc=0; K __v=(K)1;
  J _vc_j1; J _vc_j2; J _vc_j3;
  
  __v=__K2j_cast(&_vc_j1,r1(_x3)); if(0==__v) goto __return; r0(__v);   // `c.j$<val>
  __v=__K2j_cast(&_vc_j2,r1(_x2)); if(0==__v) goto __return; r0(__v);   // `c.j$<val>
  __v=__K2j_cast(&_vc_j3,r1(_x1)); if(0==__v) goto __return; r0(__v);   // `c.j$<val>
  TF_FunctionToFunctionDef((TF_Function*)_vc_j3,(TF_Buffer*)_vc_j2,(TF_Status*)_vc_j1);  // C.TF_FunctionToFunctionDef[<val>;<val>;<val>]
  
  // end of statement
  __v=r1(__consts[5]);  // const ::
  goto __return;  // return cmd

 __return:
  r0(_x1); r0(_x2); r0(_x3); 
  while(__stc>0) r0(__st[--__stc]); 
  return __v;
 };
K tf_tf_TF_FunctionImportFunctionDef__q(K _x1,K _x3){
  K __st[1]; int __stc=0; K __v=(K)1;
  TF_Function* _c_res; J _vc_j1; J _vc_j2; char* _vc_C3;
  
  __v=__K2j_cast(&_vc_j1,r1(_x3)); if(0==__v) goto __return; r0(__v);   // `c.j$<val>
  __v=kdot(r1(__consts[20]),knk(1,r1(_x1))); if(0==__v) goto __return;   // count[x1]
  __v=__K2j_cast(&_vc_j2,__v); if(0==__v) goto __return; r0(__v);   // `c.j$<val>
  __v=__K2C_cast(&_vc_C3,r1(_x1)); if(0==__v) goto __return; r0(__v);   // `c.C$<val>
  _c_res=TF_FunctionImportFunctionDef((void*)_vc_C3,(size_t)(tfc_ij)_vc_j2,(TF_Status*)_vc_j1);  // C.TF_FunctionImportFunctionDef[<val>;<val>;<val>]
  // c.res[()]::<val> - no rval, global
  
  // end of statement
  __v=kj((J)_c_res); if(0==__v) goto __return;   // C.toK[<val>]
  goto __return;  // return cmd

 __return:
  r0(_x1); r0(_x3); 
  while(__stc>0) r0(__st[--__stc]); 
  return __v;
 };
K tf_tf_TF_FunctionSetAttrValueProto__q(K _x1,K _x2,K _x3,K _x5){
  K __st[1]; int __stc=0; K __v=(K)1;
  J _vc_j1; J _vc_j2; char* _vc_C3; char* _vc_S4; J _vc_j5;
  
  __v=__K2j_cast(&_vc_j1,r1(_x5)); if(0==__v) goto __return; r0(__v);   // `c.j$<val>
  __v=kdot(r1(__consts[20]),knk(1,r1(_x3))); if(0==__v) goto __return;   // count[x3]
  __v=__K2j_cast(&_vc_j2,__v); if(0==__v) goto __return; r0(__v);   // `c.j$<val>
  __v=__K2C_cast(&_vc_C3,r1(_x3)); if(0==__v) goto __return; r0(__v);   // `c.C$<val>
  __v=__K2S_cast(&_vc_S4,r1(_x2)); if(0==__v) goto __return; r0(__v);   // `c.S$<val>
  __v=__K2j_cast(&_vc_j5,r1(_x1)); if(0==__v) goto __return; r0(__v);   // `c.j$<val>
  TF_FunctionSetAttrValueProto((TF_Function*)_vc_j5,_vc_S4,(void*)_vc_C3,(size_t)(tfc_ij)_vc_j2,(TF_Status*)_vc_j1);  // C.TF_FunctionSetAttrValueProto[<val>;_vc_S4;<val>;<val>;<val>]
  
  // end of statement
  __v=r1(__consts[5]);  // const ::
  goto __return;  // return cmd

 __return:
  r0(_x1); r0(_x2); r0(_x3); r0(_x5); 
  while(__stc>0) r0(__st[--__stc]); 
  return __v;
 };
K tf_tf_TF_FunctionGetAttrValueProto__q(K _x1,K _x2,K _x3,K _x4){
  K __st[1]; int __stc=0; K __v=(K)1;
  J _vc_j1; J _vc_j2; char* _vc_S3; J _vc_j4;
  
  __v=__K2j_cast(&_vc_j1,r1(_x4)); if(0==__v) goto __return; r0(__v);   // `c.j$<val>
  __v=__K2j_cast(&_vc_j2,r1(_x3)); if(0==__v) goto __return; r0(__v);   // `c.j$<val>
  __v=__K2S_cast(&_vc_S3,r1(_x2)); if(0==__v) goto __return; r0(__v);   // `c.S$<val>
  __v=__K2j_cast(&_vc_j4,r1(_x1)); if(0==__v) goto __return; r0(__v);   // `c.j$<val>
  TF_FunctionGetAttrValueProto((TF_Function*)_vc_j4,_vc_S3,(TF_Buffer*)_vc_j2,(TF_Status*)_vc_j1);  // C.TF_FunctionGetAttrValueProto[<val>;_vc_S3;<val>;<val>]
  
  // end of statement
  __v=r1(__consts[5]);  // const ::
  goto __return;  // return cmd

 __return:
  r0(_x1); r0(_x2); r0(_x3); r0(_x4); 
  while(__stc>0) r0(__st[--__stc]); 
  return __v;
 };
K tf_tf_TF_DeleteFunction__q(K _x1){
  K __st[1]; int __stc=0; K __v=(K)1;
  J _vc_j1;
  
  __v=__K2j_cast(&_vc_j1,r1(_x1)); if(0==__v) goto __return; r0(__v);   // `c.j$<val>
  TF_DeleteFunction((TF_Function*)_vc_j1);  // C.TF_DeleteFunction[<val>]
  
  // end of statement
  __v=r1(__consts[5]);  // const ::
  goto __return;  // return cmd

 __return:
  r0(_x1); 
  while(__stc>0) r0(__st[--__stc]); 
  return __v;
 };
K tf_tf_TF_NewSession__q(K _x1,K _x2,K _x3){
  K __st[1]; int __stc=0; K __v=(K)1;
  TF_Session* _c_res; J _vc_j1; J _vc_j2; J _vc_j3;
  
  __v=__K2j_cast(&_vc_j1,r1(_x3)); if(0==__v) goto __return; r0(__v);   // `c.j$<val>
  __v=__K2j_cast(&_vc_j2,r1(_x2)); if(0==__v) goto __return; r0(__v);   // `c.j$<val>
  __v=__K2j_cast(&_vc_j3,r1(_x1)); if(0==__v) goto __return; r0(__v);   // `c.j$<val>
  _c_res=TF_NewSession((TF_Graph*)_vc_j3,(TF_SessionOptions*)_vc_j2,(TF_Status*)_vc_j1);  // C.TF_NewSession[<val>;<val>;<val>]
  // c.res[()]::<val> - no rval, global
  
  // end of statement
  __v=kj((J)_c_res); if(0==__v) goto __return;   // C.toK[<val>]
  goto __return;  // return cmd

 __return:
  r0(_x1); r0(_x2); r0(_x3); 
  while(__stc>0) r0(__st[--__stc]); 
  return __v;
 };
K tf_tf_TF_LoadSessionFromSavedModel__q(K _sopt,K _ropt,K _dir,K _tags,K _g,K _gdef,K _st){
  K __st[1]; int __stc=0; K __v=(K)1;
  J* _c_a; J* _vc_J1; J _c_do1; char* _vc_S1; J _vc_j1; J _vc_j2; J _vc_j3; I _vc_i4; char* _vc_S6; J _vc_j7; J _vc_j8; TF_Session* _vc_TF_Session_p1;
  K _a=r1(__consts[0]); K _t=r1(__consts[0]); 
  __v=kdot(r1(__consts[20]),knk(1,r1(_tags))); if(0==__v) goto __return;   // count[tags]
  __v=kdot(r1(__consts[52]),knk(2,__v,r1(__consts[1]))); if(0==__v) goto __return;   // #[<val>;0]
  r0(_a); _a=__v;  // a:<val> - no rval, local
  
  // end of statement
  __v=__K2J_cast(&_vc_J1,r1(_a)); if(0==__v) goto __return; r0(__v);   // `c.J$<val>
  _c_a=_vc_J1;  // c.a[()]::_vc_J1 - no rval, global
  
  // end of statement
  __v=kdot(r1(__consts[20]),knk(1,r1(_tags))); if(0==__v) goto __return;   // count[tags]
  __v=kif(__v); if(0==__v) goto __return; _c_do1=__v->j; r0(__v);  // check that do value is correct

 __l1:
  if(0>=_c_do1)goto __l3; _c_do1-=1;  // do condition
  __v=kj(_c_do1); if(0==__v) goto __return;   // C.toK[c.do1]
  __v=kdot(r1(_tags),knk(1,__v)); if(0==__v) goto __return;   // tags[<val>]
  r0(_t); _t=__v;__v=r1(_t);   // t:<val>
  __v=__K2S_cast(&_vc_S1,__v); if(0==__v) goto __return; r0(__v);   // `c.S$<val>
  _c_a[_c_do1]=(J)_vc_S1;  // c.a[<val>]::<val> - no rval, global
  
  // end of statement
  goto __l1;  // jump back to do/while

 __l3:
  __v=__K2j_cast(&_vc_j1,r1(_st)); if(0==__v) goto __return; r0(__v);   // `c.j$<val>
  __v=__K2j_cast(&_vc_j2,r1(_gdef)); if(0==__v) goto __return; r0(__v);   // `c.j$<val>
  __v=__K2j_cast(&_vc_j3,r1(_g)); if(0==__v) goto __return; r0(__v);   // `c.j$<val>
  __v=kdot(r1(__consts[20]),knk(1,r1(_tags))); if(0==__v) goto __return;   // count[tags]
  __v=kdot(r1(__consts[50]),knk(2,r1(__consts[136]),__v)); if(0==__v) goto __return;   // $["i";<val>]
  __v=__K2i_cast(&_vc_i4,__v); if(0==__v) goto __return; r0(__v);   // `c.i$<val>
  __v=__K2S_cast(&_vc_S6,r1(_dir)); if(0==__v) goto __return; r0(__v);   // `c.S$<val>
  __v=__K2j_cast(&_vc_j7,r1(_ropt)); if(0==__v) goto __return; r0(__v);   // `c.j$<val>
  __v=__K2j_cast(&_vc_j8,r1(_sopt)); if(0==__v) goto __return; r0(__v);   // `c.j$<val>
  _vc_TF_Session_p1=TF_LoadSessionFromSavedModel((TF_SessionOptions*)_vc_j8,(TF_Buffer*)_vc_j7,_vc_S6,(tfc_cchar_p_p)(void*)_c_a,_vc_i4,(TF_Graph*)_vc_j3,(TF_Buffer*)_vc_j2,(TF_Status*)_vc_j1);  // C.TF_LoadSessionFromSavedModel[<val>;<val>;_vc_S6;<val>;_vc_i4;<val>;<val>;<val>]
  __v=kj((J)_vc_TF_Session_p1); if(0==__v) goto __return;   // C.toK[<val>]
  goto __return;  // return cmd
  r0(__v); 
  // end of statement
  __v=r1(__consts[5]);  // const ::
  goto __return;  // return cmd

 __return:
  r0(_a); r0(_t); r0(_sopt); r0(_ropt); r0(_dir); r0(_tags); r0(_g); r0(_gdef); r0(_st); 
  while(__stc>0) r0(__st[--__stc]); 
  return __v;
 };
K tf_tf_TF_CloseSession__q(K _x1,K _x2){
  K __st[1]; int __stc=0; K __v=(K)1;
  J _vc_j1; J _vc_j2;
  
  __v=__K2j_cast(&_vc_j1,r1(_x2)); if(0==__v) goto __return; r0(__v);   // `c.j$<val>
  __v=__K2j_cast(&_vc_j2,r1(_x1)); if(0==__v) goto __return; r0(__v);   // `c.j$<val>
  TF_CloseSession((TF_Session*)_vc_j2,(TF_Status*)_vc_j1);  // C.TF_CloseSession[<val>;<val>]
  
  // end of statement
  __v=r1(__consts[5]);  // const ::
  goto __return;  // return cmd

 __return:
  r0(_x1); r0(_x2); 
  while(__stc>0) r0(__st[--__stc]); 
  return __v;
 };
K tf_tf_TF_DeleteSession__q(K _x1,K _x2){
  K __st[1]; int __stc=0; K __v=(K)1;
  J _vc_j1; J _vc_j2;
  
  __v=__K2j_cast(&_vc_j1,r1(_x2)); if(0==__v) goto __return; r0(__v);   // `c.j$<val>
  __v=__K2j_cast(&_vc_j2,r1(_x1)); if(0==__v) goto __return; r0(__v);   // `c.j$<val>
  TF_DeleteSession((TF_Session*)_vc_j2,(TF_Status*)_vc_j1);  // C.TF_DeleteSession[<val>;<val>]
  
  // end of statement
  __v=r1(__consts[5]);  // const ::
  goto __return;  // return cmd

 __return:
  r0(_x1); r0(_x2); 
  while(__stc>0) r0(__st[--__stc]); 
  return __v;
 };
K tf_tf_TF_SessionRun__q(K _sess,K _ropts,K _inp,K _out,K _ops,K _mdata,K _st){
  K __st[1]; int __stc=0; K __v=(K)1;
  J _vc_j1; J _vc_j2; I _vc_i3; J* _vc_J4; I _vc_i5; J* _vc_J6; char* _vc_C7; I _vc_i8; J* _vc_J9; char* _vc_C10; J _vc_j11; J _vc_j12;
  K _ii=r1(__consts[0]); K _oo=r1(__consts[0]); K _it=r1(__consts[0]); K _ot=r1(__consts[0]); 
  __v=kdot(r1(__consts[20]),knk(1,r1(_inp))); if(0==__v) goto __return;   // count[inp]
  __v=kif(__v); if(0==__v) goto __return; if(0==__v->j) { r0(__v); goto __l2;}; r0(__v);  // if/while check condition
  __v=kdot(r1(_inp),knk(1,r1(__consts[1]))); if(0==__v) goto __return;   // inp[0]
  __v=tf_tf_encodeOut__q(__v); if(0==__v) goto __return;   // .tf.encodeOut[<val>]
  goto __l3;  // jmp to if end

 __l2:
  __v=r1(__consts[165]);  // const <val>

 __l3:
  r0(_ii); _ii=__v;  // ii:<val> - no rval, local
  
  // end of statement
  __v=kdot(r1(__consts[20]),knk(1,r1(_out))); if(0==__v) goto __return;   // count[out]
  __v=kif(__v); if(0==__v) goto __return; if(0==__v->j) { r0(__v); goto __l5;}; r0(__v);  // if/while check condition
  __v=kdot(r1(_out),knk(1,r1(__consts[1]))); if(0==__v) goto __return;   // out[0]
  __v=tf_tf_encodeOut__q(__v); if(0==__v) goto __return;   // .tf.encodeOut[<val>]
  goto __l6;  // jmp to if end

 __l5:
  __v=r1(__consts[165]);  // const <val>

 __l6:
  r0(_oo); _oo=__v;  // oo:<val> - no rval, local
  
  // end of statement
  __v=kdot(r1(__consts[20]),knk(1,r1(_inp))); if(0==__v) goto __return;   // count[inp]
  __v=kif(__v); if(0==__v) goto __return; if(0==__v->j) { r0(__v); goto __l8;}; r0(__v);  // if/while check condition
  __v=kdot(r1(_inp),knk(1,r1(__consts[2]))); if(0==__v) goto __return;   // inp[1]
  goto __l9;  // jmp to if end

 __l8:
  __v=r1(__consts[164]);  // const <val>

 __l9:
  r0(_it); _it=__v;  // it:<val> - no rval, local
  
  // end of statement
  __v=kdot(r1(__consts[20]),knk(1,r1(_out))); if(0==__v) goto __return;   // count[out]
  __v=kif(__v); if(0==__v) goto __return; if(0==__v->j) { r0(__v); goto __l11;}; r0(__v);  // if/while check condition
  __v=kdot(r1(_out),knk(1,r1(__consts[2]))); if(0==__v) goto __return;   // out[1]
  goto __l12;  // jmp to if end

 __l11:
  __v=r1(__consts[164]);  // const <val>

 __l12:
  r0(_ot); _ot=__v;  // ot:<val> - no rval, local
  
  // end of statement
  __v=__K2j_cast(&_vc_j1,r1(_st)); if(0==__v) goto __return; r0(__v);   // `c.j$<val>
  __v=__K2j_cast(&_vc_j2,r1(_mdata)); if(0==__v) goto __return; r0(__v);   // `c.j$<val>
  __v=kdot(r1(__consts[20]),knk(1,r1(_ops))); if(0==__v) goto __return;   // count[ops]
  __v=kdot(r1(__consts[50]),knk(2,r1(__consts[136]),__v)); if(0==__v) goto __return;   // $["i";<val>]
  __v=__K2i_cast(&_vc_i3,__v); if(0==__v) goto __return; r0(__v);   // `c.i$<val>
  __v=__K2J_cast(&_vc_J4,r1(_ops)); if(0==__v) goto __return; r0(__v);   // `c.J$<val>
  __v=kdot(r1(__consts[20]),knk(1,r1(_ot))); if(0==__v) goto __return;   // count[ot]
  __v=kdot(r1(__consts[50]),knk(2,r1(__consts[136]),__v)); if(0==__v) goto __return;   // $["i";<val>]
  __v=__K2i_cast(&_vc_i5,__v); if(0==__v) goto __return; r0(__v);   // `c.i$<val>
  __v=__K2J_cast(&_vc_J6,r1(_ot)); if(0==__v) goto __return; r0(__v);   // `c.J$<val>
  __v=__K2C_cast(&_vc_C7,r1(_oo)); if(0==__v) goto __return; r0(__v);   // `c.C$<val>
  __v=kdot(r1(__consts[20]),knk(1,r1(_it))); if(0==__v) goto __return;   // count[it]
  __v=kdot(r1(__consts[50]),knk(2,r1(__consts[136]),__v)); if(0==__v) goto __return;   // $["i";<val>]
  __v=__K2i_cast(&_vc_i8,__v); if(0==__v) goto __return; r0(__v);   // `c.i$<val>
  __v=__K2J_cast(&_vc_J9,r1(_it)); if(0==__v) goto __return; r0(__v);   // `c.J$<val>
  __v=__K2C_cast(&_vc_C10,r1(_ii)); if(0==__v) goto __return; r0(__v);   // `c.C$<val>
  __v=__K2j_cast(&_vc_j11,r1(_ropts)); if(0==__v) goto __return; r0(__v);   // `c.j$<val>
  __v=__K2j_cast(&_vc_j12,r1(_sess)); if(0==__v) goto __return; r0(__v);   // `c.j$<val>
  TF_SessionRun((TF_Session*)_vc_j12,(TF_Buffer*)_vc_j11,(TF_Output*)(void*)_vc_C10,(tfc_TF_Tensor_p_p)(void*)_vc_J9,_vc_i8,(TF_Output*)(void*)_vc_C7,(tfc_TF_Tensor_p_p)(void*)_vc_J6,_vc_i5,(const TF_Operation* const*)(void*)_vc_J4,_vc_i3,(TF_Buffer*)_vc_j2,(TF_Status*)_vc_j1);  // C.TF_SessionRun[<val>;<val>;<val>;<val>;_vc_i8;<val>;<val>;_vc_i5;<val>;_vc_i3;<val>;<val>]
  
  // end of statement
  __v=r1(__consts[5]);  // const ::
  goto __return;  // return cmd

 __return:
  r0(_ii); r0(_oo); r0(_it); r0(_ot); r0(_sess); r0(_ropts); r0(_inp); r0(_out); r0(_ops); r0(_mdata); r0(_st); 
  while(__stc>0) r0(__st[--__stc]); 
  return __v;
 };
K tf_tf_TF_SessionPRunSetup__q(K _sess,K _inp,K _out,K _ops,K _st){
  K __st[1]; int __stc=0; K __v=(K)1;
  char* _c_p; J _vc_j1; I _vc_i3; J* _vc_J4; I _vc_i5; char* _vc_C6; I _vc_i7; char* _vc_C8; J _vc_j9;
  K _ii=r1(__consts[0]); K _oo=r1(__consts[0]); 
  __v=kdot(r1(__consts[20]),knk(1,r1(_inp))); if(0==__v) goto __return;   // count[inp]
  __v=kif(__v); if(0==__v) goto __return; if(0==__v->j) { r0(__v); goto __l2;}; r0(__v);  // if/while check condition
  __v=tf_tf_encodeOut__q(r1(_inp)); if(0==__v) goto __return;   // .tf.encodeOut[inp]
  goto __l3;  // jmp to if end

 __l2:
  __v=r1(__consts[165]);  // const <val>

 __l3:
  r0(_ii); _ii=__v;  // ii:<val> - no rval, local
  
  // end of statement
  __v=kdot(r1(__consts[20]),knk(1,r1(_out))); if(0==__v) goto __return;   // count[out]
  __v=kif(__v); if(0==__v) goto __return; if(0==__v->j) { r0(__v); goto __l5;}; r0(__v);  // if/while check condition
  __v=tf_tf_encodeOut__q(r1(_out)); if(0==__v) goto __return;   // .tf.encodeOut[out]
  goto __l6;  // jmp to if end

 __l5:
  __v=r1(__consts[165]);  // const <val>

 __l6:
  r0(_oo); _oo=__v;  // oo:<val> - no rval, local
  
  // end of statement
  _c_p=(char*)(void*)0LL;  // c.p[()]::<val> - no rval, global
  
  // end of statement
  __v=__K2j_cast(&_vc_j1,r1(_st)); if(0==__v) goto __return; r0(__v);   // `c.j$<val>
  __v=kdot(r1(__consts[20]),knk(1,r1(_ops))); if(0==__v) goto __return;   // count[ops]
  __v=kdot(r1(__consts[50]),knk(2,r1(__consts[136]),__v)); if(0==__v) goto __return;   // $["i";<val>]
  __v=__K2i_cast(&_vc_i3,__v); if(0==__v) goto __return; r0(__v);   // `c.i$<val>
  __v=__K2J_cast(&_vc_J4,r1(_ops)); if(0==__v) goto __return; r0(__v);   // `c.J$<val>
  __v=kdot(r1(__consts[20]),knk(1,r1(_out))); if(0==__v) goto __return;   // count[out]
  __v=kdot(r1(__consts[50]),knk(2,r1(__consts[136]),__v)); if(0==__v) goto __return;   // $["i";<val>]
  __v=__K2i_cast(&_vc_i5,__v); if(0==__v) goto __return; r0(__v);   // `c.i$<val>
  __v=__K2C_cast(&_vc_C6,r1(_oo)); if(0==__v) goto __return; r0(__v);   // `c.C$<val>
  __v=kdot(r1(__consts[20]),knk(1,r1(_inp))); if(0==__v) goto __return;   // count[inp]
  __v=kdot(r1(__consts[50]),knk(2,r1(__consts[136]),__v)); if(0==__v) goto __return;   // $["i";<val>]
  __v=__K2i_cast(&_vc_i7,__v); if(0==__v) goto __return; r0(__v);   // `c.i$<val>
  __v=__K2C_cast(&_vc_C8,r1(_ii)); if(0==__v) goto __return; r0(__v);   // `c.C$<val>
  __v=__K2j_cast(&_vc_j9,r1(_sess)); if(0==__v) goto __return; r0(__v);   // `c.j$<val>
  TF_SessionPRunSetup((TF_Session*)_vc_j9,(TF_Output*)(void*)_vc_C8,_vc_i7,(TF_Output*)(void*)_vc_C6,_vc_i5,(const TF_Operation* const*)(void*)_vc_J4,_vc_i3,(tfc_cchar_p_p)(void*)&_c_p,(TF_Status*)_vc_j1);  // C.TF_SessionPRunSetup[<val>;<val>;_vc_i7;<val>;_vc_i5;<val>;_vc_i3;<val>;<val>]
  
  // end of statement
  __v=kj((J)_c_p[0]); if(0==__v) goto __return;   // C.toK[<val>]
  goto __return;  // return cmd
  r0(__v); 
  // end of statement
  __v=r1(__consts[5]);  // const ::
  goto __return;  // return cmd

 __return:
  r0(_ii); r0(_oo); r0(_sess); r0(_inp); r0(_out); r0(_ops); r0(_st); 
  while(__stc>0) r0(__st[--__stc]); 
  return __v;
 };
K tf_tf_TF_SessionPRun__q(K _sess,K _hh,K _inp,K _out,K _ops,K _st){
  K __st[1]; int __stc=0; K __v=(K)1;
  J _vc_j1; I _vc_i2; J* _vc_J3; I _vc_i4; J* _vc_J5; char* _vc_C6; I _vc_i7; J* _vc_J8; char* _vc_C9; J _vc_j10; J _vc_j11;
  K _ii=r1(__consts[0]); K _oo=r1(__consts[0]); K _it=r1(__consts[0]); K _ot=r1(__consts[0]); 
  __v=kdot(r1(__consts[20]),knk(1,r1(_inp))); if(0==__v) goto __return;   // count[inp]
  __v=kif(__v); if(0==__v) goto __return; if(0==__v->j) { r0(__v); goto __l2;}; r0(__v);  // if/while check condition
  __v=kdot(r1(_inp),knk(1,r1(__consts[1]))); if(0==__v) goto __return;   // inp[0]
  __v=tf_tf_encodeOut__q(__v); if(0==__v) goto __return;   // .tf.encodeOut[<val>]
  goto __l3;  // jmp to if end

 __l2:
  __v=r1(__consts[165]);  // const <val>

 __l3:
  r0(_ii); _ii=__v;  // ii:<val> - no rval, local
  
  // end of statement
  __v=kdot(r1(__consts[20]),knk(1,r1(_out))); if(0==__v) goto __return;   // count[out]
  __v=kif(__v); if(0==__v) goto __return; if(0==__v->j) { r0(__v); goto __l5;}; r0(__v);  // if/while check condition
  __v=kdot(r1(_out),knk(1,r1(__consts[1]))); if(0==__v) goto __return;   // out[0]
  __v=tf_tf_encodeOut__q(__v); if(0==__v) goto __return;   // .tf.encodeOut[<val>]
  goto __l6;  // jmp to if end

 __l5:
  __v=r1(__consts[165]);  // const <val>

 __l6:
  r0(_oo); _oo=__v;  // oo:<val> - no rval, local
  
  // end of statement
  __v=kdot(r1(__consts[20]),knk(1,r1(_inp))); if(0==__v) goto __return;   // count[inp]
  __v=kif(__v); if(0==__v) goto __return; if(0==__v->j) { r0(__v); goto __l8;}; r0(__v);  // if/while check condition
  __v=kdot(r1(_inp),knk(1,r1(__consts[2]))); if(0==__v) goto __return;   // inp[1]
  goto __l9;  // jmp to if end

 __l8:
  __v=r1(__consts[164]);  // const <val>

 __l9:
  r0(_it); _it=__v;  // it:<val> - no rval, local
  
  // end of statement
  __v=kdot(r1(__consts[20]),knk(1,r1(_out))); if(0==__v) goto __return;   // count[out]
  __v=kif(__v); if(0==__v) goto __return; if(0==__v->j) { r0(__v); goto __l11;}; r0(__v);  // if/while check condition
  __v=kdot(r1(_out),knk(1,r1(__consts[2]))); if(0==__v) goto __return;   // out[1]
  goto __l12;  // jmp to if end

 __l11:
  __v=r1(__consts[164]);  // const <val>

 __l12:
  r0(_ot); _ot=__v;  // ot:<val> - no rval, local
  
  // end of statement
  __v=__K2j_cast(&_vc_j1,r1(_st)); if(0==__v) goto __return; r0(__v);   // `c.j$<val>
  __v=kdot(r1(__consts[20]),knk(1,r1(_ops))); if(0==__v) goto __return;   // count[ops]
  __v=kdot(r1(__consts[50]),knk(2,r1(__consts[136]),__v)); if(0==__v) goto __return;   // $["i";<val>]
  __v=__K2i_cast(&_vc_i2,__v); if(0==__v) goto __return; r0(__v);   // `c.i$<val>
  __v=__K2J_cast(&_vc_J3,r1(_ops)); if(0==__v) goto __return; r0(__v);   // `c.J$<val>
  __v=kdot(r1(__consts[20]),knk(1,r1(_ot))); if(0==__v) goto __return;   // count[ot]
  __v=kdot(r1(__consts[50]),knk(2,r1(__consts[136]),__v)); if(0==__v) goto __return;   // $["i";<val>]
  __v=__K2i_cast(&_vc_i4,__v); if(0==__v) goto __return; r0(__v);   // `c.i$<val>
  __v=__K2J_cast(&_vc_J5,r1(_ot)); if(0==__v) goto __return; r0(__v);   // `c.J$<val>
  __v=__K2C_cast(&_vc_C6,r1(_oo)); if(0==__v) goto __return; r0(__v);   // `c.C$<val>
  __v=kdot(r1(__consts[20]),knk(1,r1(_it))); if(0==__v) goto __return;   // count[it]
  __v=kdot(r1(__consts[50]),knk(2,r1(__consts[136]),__v)); if(0==__v) goto __return;   // $["i";<val>]
  __v=__K2i_cast(&_vc_i7,__v); if(0==__v) goto __return; r0(__v);   // `c.i$<val>
  __v=__K2J_cast(&_vc_J8,r1(_it)); if(0==__v) goto __return; r0(__v);   // `c.J$<val>
  __v=__K2C_cast(&_vc_C9,r1(_ii)); if(0==__v) goto __return; r0(__v);   // `c.C$<val>
  __v=__K2j_cast(&_vc_j10,r1(_hh)); if(0==__v) goto __return; r0(__v);   // `c.j$<val>
  __v=__K2j_cast(&_vc_j11,r1(_sess)); if(0==__v) goto __return; r0(__v);   // `c.j$<val>
  TF_SessionPRun((TF_Session*)_vc_j11,(char*)_vc_j10,(TF_Output*)(void*)_vc_C9,(tfc_TF_Tensor_p_p)(void*)_vc_J8,_vc_i7,(TF_Output*)(void*)_vc_C6,(tfc_TF_Tensor_p_p)(void*)_vc_J5,_vc_i4,(const TF_Operation* const*)(void*)_vc_J3,_vc_i2,(TF_Status*)_vc_j1);  // C.TF_SessionPRun[<val>;<val>;<val>;<val>;_vc_i7;<val>;<val>;_vc_i4;<val>;_vc_i2;<val>]
  
  // end of statement
  __v=r1(__consts[5]);  // const ::
  goto __return;  // return cmd

 __return:
  r0(_ii); r0(_oo); r0(_it); r0(_ot); r0(_sess); r0(_hh); r0(_inp); r0(_out); r0(_ops); r0(_st); 
  while(__stc>0) r0(__st[--__stc]); 
  return __v;
 };
K tf_tf_TF_DeletePRunHandle__q(K _x1){
  K __st[1]; int __stc=0; K __v=(K)1;
  J _vc_j1;
  
  __v=__K2j_cast(&_vc_j1,r1(_x1)); if(0==__v) goto __return; r0(__v);   // `c.j$<val>
  TF_DeletePRunHandle((char*)_vc_j1);  // C.TF_DeletePRunHandle[<val>]
  
  // end of statement
  __v=r1(__consts[5]);  // const ::
  goto __return;  // return cmd

 __return:
  r0(_x1); 
  while(__stc>0) r0(__st[--__stc]); 
  return __v;
 };
K tf_tf_TF_SessionListDevices__q(K _x1,K _x2){
  K __st[1]; int __stc=0; K __v=(K)1;
  TF_DeviceList* _c_res; J _vc_j1; J _vc_j2;
  
  __v=__K2j_cast(&_vc_j1,r1(_x2)); if(0==__v) goto __return; r0(__v);   // `c.j$<val>
  __v=__K2j_cast(&_vc_j2,r1(_x1)); if(0==__v) goto __return; r0(__v);   // `c.j$<val>
  _c_res=TF_SessionListDevices((TF_Session*)_vc_j2,(TF_Status*)_vc_j1);  // C.TF_SessionListDevices[<val>;<val>]
  // c.res[()]::<val> - no rval, global
  
  // end of statement
  __v=kj((J)_c_res); if(0==__v) goto __return;   // C.toK[<val>]
  goto __return;  // return cmd

 __return:
  r0(_x1); r0(_x2); 
  while(__stc>0) r0(__st[--__stc]); 
  return __v;
 };
K tf_tf_TF_DeleteDeviceList__q(K _x1){
  K __st[1]; int __stc=0; K __v=(K)1;
  J _vc_j1;
  
  __v=__K2j_cast(&_vc_j1,r1(_x1)); if(0==__v) goto __return; r0(__v);   // `c.j$<val>
  TF_DeleteDeviceList((TF_DeviceList*)_vc_j1);  // C.TF_DeleteDeviceList[<val>]
  
  // end of statement
  __v=r1(__consts[5]);  // const ::
  goto __return;  // return cmd

 __return:
  r0(_x1); 
  while(__stc>0) r0(__st[--__stc]); 
  return __v;
 };
K tf_tf_TF_DeviceListCount__q(K _x1){
  K __st[1]; int __stc=0; K __v=(K)1;
  I _c_res; J _vc_j1;
  
  __v=__K2j_cast(&_vc_j1,r1(_x1)); if(0==__v) goto __return; r0(__v);   // `c.j$<val>
  _c_res=TF_DeviceListCount((TF_DeviceList*)_vc_j1);  // C.TF_DeviceListCount[<val>]
  // c.res[()]::<val> - no rval, global
  
  // end of statement
  __v=ki(_c_res); if(0==__v) goto __return;   // C.toK[c.res]
  goto __return;  // return cmd

 __return:
  r0(_x1); 
  while(__stc>0) r0(__st[--__stc]); 
  return __v;
 };
K tf_tf_TF_DeviceListName__q(K _x1,K _x2,K _x3){
  K __st[1]; int __stc=0; K __v=(K)1;
  const char* _c_res; J _vc_j1; I _vc_i2; J _vc_j3;
  
  __v=__K2j_cast(&_vc_j1,r1(_x3)); if(0==__v) goto __return; r0(__v);   // `c.j$<val>
  __v=__K2i_cast(&_vc_i2,r1(_x2)); if(0==__v) goto __return; r0(__v);   // `c.i$<val>
  __v=__K2j_cast(&_vc_j3,r1(_x1)); if(0==__v) goto __return; r0(__v);   // `c.j$<val>
  _c_res=TF_DeviceListName((TF_DeviceList*)_vc_j3,_vc_i2,(TF_Status*)_vc_j1);  // C.TF_DeviceListName[<val>;_vc_i2;<val>]
  // c.res[()]::<val> - no rval, global
  
  // end of statement
  __v=__toKS((char*)_c_res); if(0==__v) goto __return;   // C.toK[<val>]
  goto __return;  // return cmd

 __return:
  r0(_x1); r0(_x2); r0(_x3); 
  while(__stc>0) r0(__st[--__stc]); 
  return __v;
 };
K tf_tf_TF_DeviceListType__q(K _x1,K _x2,K _x3){
  K __st[1]; int __stc=0; K __v=(K)1;
  const char* _c_res; J _vc_j1; I _vc_i2; J _vc_j3;
  
  __v=__K2j_cast(&_vc_j1,r1(_x3)); if(0==__v) goto __return; r0(__v);   // `c.j$<val>
  __v=__K2i_cast(&_vc_i2,r1(_x2)); if(0==__v) goto __return; r0(__v);   // `c.i$<val>
  __v=__K2j_cast(&_vc_j3,r1(_x1)); if(0==__v) goto __return; r0(__v);   // `c.j$<val>
  _c_res=TF_DeviceListType((TF_DeviceList*)_vc_j3,_vc_i2,(TF_Status*)_vc_j1);  // C.TF_DeviceListType[<val>;_vc_i2;<val>]
  // c.res[()]::<val> - no rval, global
  
  // end of statement
  __v=__toKS((char*)_c_res); if(0==__v) goto __return;   // C.toK[<val>]
  goto __return;  // return cmd

 __return:
  r0(_x1); r0(_x2); r0(_x3); 
  while(__stc>0) r0(__st[--__stc]); 
  return __v;
 };
K tf_tf_TF_DeviceListMemoryBytes__q(K _x1,K _x2,K _x3){
  K __st[1]; int __stc=0; K __v=(K)1;
  J _c_res; J _vc_j1; I _vc_i2; J _vc_j3;
  
  __v=__K2j_cast(&_vc_j1,r1(_x3)); if(0==__v) goto __return; r0(__v);   // `c.j$<val>
  __v=__K2i_cast(&_vc_i2,r1(_x2)); if(0==__v) goto __return; r0(__v);   // `c.i$<val>
  __v=__K2j_cast(&_vc_j3,r1(_x1)); if(0==__v) goto __return; r0(__v);   // `c.j$<val>
  _c_res=TF_DeviceListMemoryBytes((TF_DeviceList*)_vc_j3,_vc_i2,(TF_Status*)_vc_j1);  // C.TF_DeviceListMemoryBytes[<val>;_vc_i2;<val>]
  // c.res[()]::<val> - no rval, global
  
  // end of statement
  __v=kj(_c_res); if(0==__v) goto __return;   // C.toK[c.res]
  goto __return;  // return cmd

 __return:
  r0(_x1); r0(_x2); r0(_x3); 
  while(__stc>0) r0(__st[--__stc]); 
  return __v;
 };
K tf_tf_TF_LoadLibrary__q(K _x1,K _x2){
  K __st[1]; int __stc=0; K __v=(K)1;
  TF_Library* _c_res; J _vc_j1; char* _vc_S2;
  
  __v=__K2j_cast(&_vc_j1,r1(_x2)); if(0==__v) goto __return; r0(__v);   // `c.j$<val>
  __v=__K2S_cast(&_vc_S2,r1(_x1)); if(0==__v) goto __return; r0(__v);   // `c.S$<val>
  _c_res=TF_LoadLibrary(_vc_S2,(TF_Status*)_vc_j1);  // C.TF_LoadLibrary[_vc_S2;<val>]
  // c.res[()]::<val> - no rval, global
  
  // end of statement
  __v=kj((J)_c_res); if(0==__v) goto __return;   // C.toK[<val>]
  goto __return;  // return cmd

 __return:
  r0(_x1); r0(_x2); 
  while(__stc>0) r0(__st[--__stc]); 
  return __v;
 };
K tf_tf_TF_GetOpList__q(K _l){
  K __st[1]; int __stc=0; K __v=(K)1;
  TF_Buffer _c_b; J _vc_j1;
  
  __v=__K2j_cast(&_vc_j1,r1(_l)); if(0==__v) goto __return; r0(__v);   // `c.j$<val>
  _c_b=TF_GetOpList((TF_Library*)_vc_j1);  // C.TF_GetOpList[<val>]
  // c.b[()]::<val> - no rval, global
  
  // end of statement
  __v=kj((J)&_c_b); if(0==__v) goto __return;   // C.toK[<val>]
  __v=tf_tf_getBuffer__q(__v); if(0==__v) goto __return;   // .tf.getBuffer[<val>]
  goto __return;  // return cmd

 __return:
  r0(_l); 
  while(__stc>0) r0(__st[--__stc]); 
  return __v;
 };
K tf_tf_TF_DeleteLibraryHandle__q(K _x1){
  K __st[1]; int __stc=0; K __v=(K)1;
  J _vc_j1;
  
  __v=__K2j_cast(&_vc_j1,r1(_x1)); if(0==__v) goto __return; r0(__v);   // `c.j$<val>
  TF_DeleteLibraryHandle((TF_Library*)_vc_j1);  // C.TF_DeleteLibraryHandle[<val>]
  
  // end of statement
  __v=r1(__consts[5]);  // const ::
  goto __return;  // return cmd

 __return:
  r0(_x1); 
  while(__stc>0) r0(__st[--__stc]); 
  return __v;
 };
K tf_tf_TF_GetAllOpList__q(K _x1){
  K __st[1]; int __stc=0; K __v=(K)1;
  TF_Buffer* _c_res;
  
  _c_res=TF_GetAllOpList();  // C.TF_GetAllOpList[::]
  // c.res[()]::<val> - no rval, global
  
  // end of statement
  __v=kj((J)_c_res); if(0==__v) goto __return;   // C.toK[<val>]
  goto __return;  // return cmd

 __return:
  r0(_x1); 
  while(__stc>0) r0(__st[--__stc]); 
  return __v;
 };

K kif(K x) { static int tmap[20]={0,1,0,0,1,2,4,8,0,0,1,0,8,4,4,0,8,4,4,4}; J r=0; if((x->t>=0)||(x->t<-19)) { r0(x); return krr("type");}; SW(tmap[-(x->t)]){CS(1,r=x->g)CS(2,r=x->h)CS(4,r=x->i)CS(8,r=x->j)CD:r0(x);return krr("type");}; r0(x); return kj(r); };

static inline K __enlist(K l) { if(0==l->n) return l; J t=kK(l)[0]->t; if((t>=0)&&(t!=99)) return l; DO(l->n,if(kK(l)[i]->t!=t) return l;); if(l->n>8) return kdot(r1(__consts[57]),knk(3,l,r1(__consts[1]),r1(__consts[5]))); return kdot(r1(__consts[19]),l);};
static K kamend(K ff,K a,K i,K f,K v){ K res=(K)0, lst=knk(4,a,i,f,v); I r = a->r; if(0==r) a->r-=1; res=dot(ff,lst); if(0==r) {if(a==res) a->r+=1; else kK(lst)[0]=kj(0);}; r0(lst); return res;};
static K kamend3(K ff,int isG,K* a,K i,K f){if(isG)r1(*a); I r=(*a)->r; K lst=knk(3,(*a),i,f); if(0==r) (*a)->r-=1; K res=dot(ff,lst); if(0==r) {if((*a)==res) (*a)->r+=1; else kK(lst)[0]=kj(0);}; r0(lst); if((!isG)&&(0==res))a[0]=r1(__consts[0]); if(0!=res){if(isG)r0(*a); a[0]=r1(res);}; return res;};
static K kamend4(K ff,int isG,K* a,K i,K f,K v){if(isG)r1(*a); K res=kamend(ff,(*a),i,f,v); if((!isG)&&(0==res))a[0]=r1(__consts[0]); if(0!=res){if(isG)r0(*a); a[0]=r1(res);}; return res;};
static unsigned char __cnstArr[] = 
  {1,0,0,0,217,6,0,0,0,0,170,0,0,0,0,0,0,0,0,0,249,0,0,0,0,0,0,0,0,249,1,0,0,0,0,0,0,0,102,12,245,0,101,0,101,255,101,0,101,1,101,2,101,3,101,4,101,5,101,6,101,7,101,8,101,9,101,10,101,11,101,41,101,13,101,14,101,15,101,16,101,17,101,18,101,19,101,20,101,21,101,22,101,23,101,24,101,25,101,26,101,27,101,28,101,29,101,30,101,31,102,0,102,1,102,2,102,3,102,4,102,5,102,6,102,7,102,8,102,9,102,10,102,11,102,12,102,13,102,14,102,15,102,16,102,17,102,18,102,19,102,20,102,21,102,22,102,23,102,24,102,25,102,26,102,27,102,28,102,29,102,30,102,31,103,0,103,1,103,2,103,3,103,4,103,5,245,116,0,245,105,0,7,0,1,0,0,0,0,0,
  0,0,0,0,0,0,10,0,14,0,0,0,75,50,105,95,99,97,115,116,58,32,116,121,112,101,245,106,0,10,0,14,0,0,0,75,50,106,95,99,97,115,116,58,32,116,121,112,101,245,102,0,10,0,14,0,0,0,75,50,102,95,99,97,115,116,58,32,116,121,112,101,245,103,0,10,0,14,0,0,0,75,50,99,95,99,97,115,116,58,32,116,121,112,101,245,114,0,10,0,16,0,0,0,75,50,73,95,99,97,115,116,58,32,110,111,32,114,101,102,245,71,48,0,10,0,14,0,0,0,75,50,73,95,99,97,115,116,58,32,116,121,112,101,10,0,16,0,0,0,75,50,74,95,99,97,115,116,58,32,110,111,32,114,101,102,10,0,14,0,0,0,75,50,74,95,99,97,115,116,58,32,116,121,112,101,10,0,16,0,0,0,75,50,72,95,99,97,115,116,
  58,32,110,111,32,114,101,102,10,0,14,0,0,0,75,50,72,95,99,97,115,116,58,32,116,121,112,101,10,0,16,0,0,0,75,50,70,95,99,97,115,116,58,32,110,111,32,114,101,102,10,0,14,0,0,0,75,50,70,95,99,97,115,116,58,32,116,121,112,101,10,0,16,0,0,0,75,50,69,95,99,97,115,116,58,32,110,111,32,114,101,102,10,0,14,0,0,0,75,50,69,95,99,97,115,116,58,32,116,121,112,101,10,0,16,0,0,0,75,50,83,95,99,97,115,116,58,32,110,111,32,114,101,102,245,115,0,10,0,28,0,0,0,75,50,83,95,99,97,115,116,58,32,110,111,32,110,117,108,108,32,116,101,114,109,105,110,97,116,111,114,10,0,14,0,0,0,75,50,83,95,99,97,115,116,58,32,116,121,112,101,10,0,16,0,0,0,75,50,67,
  95,99,97,115,116,58,32,110,111,32,114,101,102,10,0,14,0,0,0,75,50,67,95,99,97,115,116,58,32,116,121,112,101,105,2,0,0,0,101,15,102,8,246,32,11,0,2,0,0,0,111,112,101,114,0,105,110,100,101,120,0,249,99,0,0,0,0,0,0,0,10,0,18,0,0,0,96,99,46,84,70,95,73,110,112,117,116,36,58,32,116,121,112,101,0,0,1,0,0,0,10,0,4,0,0,0,111,112,101,114,0,0,1,0,0,0,10,0,5,0,0,0,105,110,100,101,120,10,0,19,0,0,0,96,99,46,84,70,95,79,117,116,112,117,116,36,58,32,116,121,112,101,10,0,5,0,0,0,105,110,100,101,120,10,0,4,0,0,0,111,112,101,114,11,0,4,0,0,0,105,115,95,108,105,115,116,0,108,105,115,116,95,115,105,122,101,0,116,121,112,
  101,0,116,111,116,97,108,95,115,105,122,101,0,10,0,10,0,0,0,116,111,116,97,108,95,115,105,122,101,10,0,4,0,0,0,116,121,112,101,10,0,9,0,0,0,108,105,115,116,95,115,105,122,101,10,0,7,0,0,0,105,115,95,108,105,115,116,252,0,245,108,101,110,103,116,104,0,245,100,97,116,97,0,245,99,46,84,70,95,79,117,116,112,117,116,0,245,111,112,101,114,0,245,105,110,100,101,120,0,10,0,14,0,0,0,67,46,84,70,95,86,101,114,115,105,111,110,58,32,10,0,14,0,0,0,67,46,84,70,95,77,101,115,115,97,103,101,58,32,11,0,1,0,0,0,114,0,5,0,2,0,0,0,4,0,10,0,249,5,0,0,0,0,0,0,0,249,6,0,0,0,0,0,0,0,249,7,0,0,0,0,0,0,0,249,9,0,0,0,0,
  0,0,0,99,5,0,7,0,0,0,4,0,5,0,6,0,7,0,8,0,9,0,10,0,7,0,7,0,0,0,1,0,0,0,0,0,0,0,2,0,0,0,0,0,0,0,4,0,0,0,0,0,0,0,8,0,0,0,0,0,0,0,4,0,0,0,0,0,0,0,8,0,0,0,0,0,0,0,1,0,0,0,0,0,0,0,10,0,30,0,0,0,84,70,95,78,101,119,84,101,110,115,111,114,58,32,117,110,115,117,112,112,111,114,116,101,100,32,100,97,116,97,246,105,10,0,0,0,0,0,249,98,0,0,0,0,0,0,0,10,0,21,0,0,0,84,70,95,65,100,100,73,110,112,117,116,76,105,115,116,58,32,116,121,112,101,10,0,26,0,0,0,84,70,95,83,101,116,65,116,116,114,83,116,114,105,110,103,76,105,115,116,58,32,116,121,112,101,10,0,
  25,0,0,0,84,70,95,83,101,116,65,116,116,114,83,104,97,112,101,76,105,115,116,58,32,116,121,112,101,10,0,36,0,0,0,84,70,95,83,101,116,65,116,116,114,84,101,110,115,111,114,83,104,97,112,101,80,114,111,116,111,76,105,115,116,58,32,116,121,112,101,10,0,20,0,0,0,67,46,84,70,95,79,112,101,114,97,116,105,111,110,78,97,109,101,58,32,10,0,22,0,0,0,67,46,84,70,95,79,112,101,114,97,116,105,111,110,79,112,84,121,112,101,58,32,10,0,22,0,0,0,67,46,84,70,95,79,112,101,114,97,116,105,111,110,68,101,118,105,99,101,58,32,105,2,0,0,0,101,15,102,9,245,99,46,84,70,95,73,110,112,117,116,0,0,0,2,0,0,0,10,0,3,0,0,0,106,105,32,7,0,3,0,0,0,8,0,0,0,0,
  0,0,0,4,0,0,0,0,0,0,0,4,0,0,0,0,0,0,0,105,2,0,0,0,101,15,102,10,98,0,99,11,0,2,0,0,0,111,112,101,114,0,105,110,100,101,120,0,0,0,2,0,0,0,7,0,0,0,0,0,6,0,0,0,0,0,98,0,99,11,0,2,0,0,0,110,97,109,101,0,105,110,100,101,120,0,0,0,2,0,0,0,0,0,0,0,0,0,6,0,0,0,0,0,0,0,2,0,0,0,7,0,2,0,0,0,8,0,0,0,0,0,0,0,4,0,0,0,0,0,0,0,10,0,2,0,0,0,106,105,245,99,46,84,70,95,87,104,105,108,101,80,97,114,97,109,115,0,245,99,111,110,100,95,111,117,116,112,117,116,0,11,0,2,0,0,0,99,111,110,100,95,111,117,116,112,117,116,0,111,112,101,114,0,11,0,2,0,0,0,
  99,111,110,100,95,111,117,116,112,117,116,0,105,110,100,101,120,0,245,98,111,100,121,95,111,117,116,112,117,116,115,0,245,110,105,110,112,117,116,115,0,249,255,255,255,255,255,255,255,255,10,0,15,0,0,0,66,97,100,32,119,104,105,108,101,32,105,110,100,101,120,245,110,97,109,101,0,11,0,1,0,0,0,110,97,109,101,0,10,0,14,0,0,0,66,97,100,32,119,104,105,108,101,32,110,97,109,101,7,0,0,0,0,0,4,0,0,0,0,0,249,2,0,0,0,0,0,0,0,249,3,0,0,0,0,0,0,0,249,8,0,0,0,0,0,0,0,0,0,0,0,0,0};
static K tf__cnstInit() {
  K v = ktn(KG,sizeof(__cnstArr)); DO(v->n,kG(v)[i]=__cnstArr[i]);
  K res=d9(v); r0(v); if((0==res)||(-128==res->t)) { __ginited=0; return res;}; __consts=(K*)res->G0;
  __wglobals=__consts[169];
  return (K)1;
 };

static K tf__getLib(K x) {
  K k=(K)0, v=(K)0, k1=(K)0, v1=(K)0;
  if(0==__ginited) { K res=tf__init((K)0); if((0==res)||(-128==res->t)) return res; r0(res); };
  k=ktn(KS,144); v=ktn(0,144);
  k1=ktn(KS,1); v1=ktn(KJ,1);
  kS(k)[0]=ss(".tf.getBuffer"); kK(v)[0]=r1(tf_tf_getBuffer__k);
  kS(k)[1]=ss(".tf.encodeOut"); kK(v)[1]=r1(tf_tf_encodeOut__k);
  kS(k)[2]=ss(".tf.TF_Version"); kK(v)[2]=r1(tf_tf_TF_Version__k);
  kS(k)[3]=ss(".tf.TF_DataTypeSize"); kK(v)[3]=r1(tf_tf_TF_DataTypeSize__k);
  kS(k)[4]=ss(".tf.TF_NewStatus"); kK(v)[4]=r1(tf_tf_TF_NewStatus__k);
  kS(k)[5]=ss(".tf.TF_DeleteStatus"); kK(v)[5]=r1(tf_tf_TF_DeleteStatus__k);
  kS(k)[6]=ss(".tf.TF_SetStatus"); kK(v)[6]=r1(tf_tf_TF_SetStatus__k);
  kS(k)[7]=ss(".tf.TF_GetCode"); kK(v)[7]=r1(tf_tf_TF_GetCode__k);
  kS(k)[8]=ss(".tf.TF_Message"); kK(v)[8]=r1(tf_tf_TF_Message__k);
  kS(k)[9]=ss(".tf.TF_NewBufferFromString"); kK(v)[9]=r1(tf_tf_TF_NewBufferFromString__k);
  kS(k)[10]=ss(".tf.TF_NewBuffer"); kK(v)[10]=r1(tf_tf_TF_NewBuffer__k);
  kS(k)[11]=ss(".tf.TF_DeleteBuffer"); kK(v)[11]=r1(tf_tf_TF_DeleteBuffer__k);
  kS(k)[12]=ss(".tf.TF_NewTensor"); kK(v)[12]=r1(tf_tf_TF_NewTensor__k);
  kS(k)[13]=ss(".tf.TF_AllocateTensor"); kK(v)[13]=r1(tf_tf_TF_AllocateTensor__k);
  kS(k)[14]=ss(".tf.TF_TensorMaybeMove"); kK(v)[14]=r1(tf_tf_TF_TensorMaybeMove__k);
  kS(k)[15]=ss(".tf.TF_DeleteTensor"); kK(v)[15]=r1(tf_tf_TF_DeleteTensor__k);
  kS(k)[16]=ss(".tf.TF_TensorType"); kK(v)[16]=r1(tf_tf_TF_TensorType__k);
  kS(k)[17]=ss(".tf.TF_NumDims"); kK(v)[17]=r1(tf_tf_TF_NumDims__k);
  kS(k)[18]=ss(".tf.TF_Dim"); kK(v)[18]=r1(tf_tf_TF_Dim__k);
  kS(k)[19]=ss(".tf.TF_TensorByteSize"); kK(v)[19]=r1(tf_tf_TF_TensorByteSize__k);
  kS(k)[20]=ss(".tf.TF_TensorData"); kK(v)[20]=r1(tf_tf_TF_TensorData__k);
  kS(k)[21]=ss(".tf.writeToTensor"); kK(v)[21]=r1(tf_tf_writeToTensor__k);
  kS(k)[22]=ss(".tf.readFromTensor"); kK(v)[22]=r1(tf_tf_readFromTensor__k);
  kS(k)[23]=ss(".tf.TF_StringEncode"); kK(v)[23]=r1(tf_tf_TF_StringEncode__k);
  kS(k)[24]=ss(".tf.TF_StringDecode"); kK(v)[24]=r1(tf_tf_TF_StringDecode__k);
  kS(k)[25]=ss(".tf.TF_StringEncodedSize"); kK(v)[25]=r1(tf_tf_TF_StringEncodedSize__k);
  kS(k)[26]=ss(".tf.TF_NewSessionOptions"); kK(v)[26]=r1(tf_tf_TF_NewSessionOptions__k);
  kS(k)[27]=ss(".tf.TF_SetTarget"); kK(v)[27]=r1(tf_tf_TF_SetTarget__k);
  kS(k)[28]=ss(".tf.TF_SetConfig"); kK(v)[28]=r1(tf_tf_TF_SetConfig__k);
  kS(k)[29]=ss(".tf.TF_DeleteSessionOptions"); kK(v)[29]=r1(tf_tf_TF_DeleteSessionOptions__k);
  kS(k)[30]=ss(".tf.TF_NewGraph"); kK(v)[30]=r1(tf_tf_TF_NewGraph__k);
  kS(k)[31]=ss(".tf.TF_DeleteGraph"); kK(v)[31]=r1(tf_tf_TF_DeleteGraph__k);
  kS(k)[32]=ss(".tf.TF_GraphSetTensorShape"); kK(v)[32]=r1(tf_tf_TF_GraphSetTensorShape__k);
  kS(k)[33]=ss(".tf.TF_GraphGetTensorNumDims"); kK(v)[33]=r1(tf_tf_TF_GraphGetTensorNumDims__k);
  kS(k)[34]=ss(".tf.TF_GraphGetTensorShape"); kK(v)[34]=r1(tf_tf_TF_GraphGetTensorShape__k);
  kS(k)[35]=ss(".tf.TF_NewOperation"); kK(v)[35]=r1(tf_tf_TF_NewOperation__k);
  kS(k)[36]=ss(".tf.TF_SetDevice"); kK(v)[36]=r1(tf_tf_TF_SetDevice__k);
  kS(k)[37]=ss(".tf.TF_AddInput"); kK(v)[37]=r1(tf_tf_TF_AddInput__k);
  kS(k)[38]=ss(".tf.TF_AddInputList"); kK(v)[38]=r1(tf_tf_TF_AddInputList__k);
  kS(k)[39]=ss(".tf.TF_AddControlInput"); kK(v)[39]=r1(tf_tf_TF_AddControlInput__k);
  kS(k)[40]=ss(".tf.TF_SetAttrString"); kK(v)[40]=r1(tf_tf_TF_SetAttrString__k);
  kS(k)[41]=ss(".tf.TF_SetAttrStringList"); kK(v)[41]=r1(tf_tf_TF_SetAttrStringList__k);
  kS(k)[42]=ss(".tf.TF_SetAttrInt"); kK(v)[42]=r1(tf_tf_TF_SetAttrInt__k);
  kS(k)[43]=ss(".tf.TF_SetAttrIntList"); kK(v)[43]=r1(tf_tf_TF_SetAttrIntList__k);
  kS(k)[44]=ss(".tf.TF_SetAttrFloat"); kK(v)[44]=r1(tf_tf_TF_SetAttrFloat__k);
  kS(k)[45]=ss(".tf.TF_SetAttrFloatList"); kK(v)[45]=r1(tf_tf_TF_SetAttrFloatList__k);
  kS(k)[46]=ss(".tf.TF_SetAttrBool"); kK(v)[46]=r1(tf_tf_TF_SetAttrBool__k);
  kS(k)[47]=ss(".tf.TF_SetAttrBoolList"); kK(v)[47]=r1(tf_tf_TF_SetAttrBoolList__k);
  kS(k)[48]=ss(".tf.TF_SetAttrType"); kK(v)[48]=r1(tf_tf_TF_SetAttrType__k);
  kS(k)[49]=ss(".tf.TF_SetAttrTypeList"); kK(v)[49]=r1(tf_tf_TF_SetAttrTypeList__k);
  kS(k)[50]=ss(".tf.TF_SetAttrShape"); kK(v)[50]=r1(tf_tf_TF_SetAttrShape__k);
  kS(k)[51]=ss(".tf.TF_SetAttrShapeList"); kK(v)[51]=r1(tf_tf_TF_SetAttrShapeList__k);
  kS(k)[52]=ss(".tf.TF_SetAttrTensorShapeProto"); kK(v)[52]=r1(tf_tf_TF_SetAttrTensorShapeProto__k);
  kS(k)[53]=ss(".tf.TF_SetAttrTensorShapeProtoList"); kK(v)[53]=r1(tf_tf_TF_SetAttrTensorShapeProtoList__k);
  kS(k)[54]=ss(".tf.TF_SetAttrTensor"); kK(v)[54]=r1(tf_tf_TF_SetAttrTensor__k);
  kS(k)[55]=ss(".tf.TF_SetAttrTensorList"); kK(v)[55]=r1(tf_tf_TF_SetAttrTensorList__k);
  kS(k)[56]=ss(".tf.TF_SetAttrValueProto"); kK(v)[56]=r1(tf_tf_TF_SetAttrValueProto__k);
  kS(k)[57]=ss(".tf.TF_FinishOperation"); kK(v)[57]=r1(tf_tf_TF_FinishOperation__k);
  kS(k)[58]=ss(".tf.TF_OperationName"); kK(v)[58]=r1(tf_tf_TF_OperationName__k);
  kS(k)[59]=ss(".tf.TF_OperationOpType"); kK(v)[59]=r1(tf_tf_TF_OperationOpType__k);
  kS(k)[60]=ss(".tf.TF_OperationDevice"); kK(v)[60]=r1(tf_tf_TF_OperationDevice__k);
  kS(k)[61]=ss(".tf.TF_OperationNumOutputs"); kK(v)[61]=r1(tf_tf_TF_OperationNumOutputs__k);
  kS(k)[62]=ss(".tf.TF_OperationOutputType"); kK(v)[62]=r1(tf_tf_TF_OperationOutputType__k);
  kS(k)[63]=ss(".tf.TF_OperationOutputListLength"); kK(v)[63]=r1(tf_tf_TF_OperationOutputListLength__k);
  kS(k)[64]=ss(".tf.TF_OperationNumInputs"); kK(v)[64]=r1(tf_tf_TF_OperationNumInputs__k);
  kS(k)[65]=ss(".tf.TF_OperationInputType"); kK(v)[65]=r1(tf_tf_TF_OperationInputType__k);
  kS(k)[66]=ss(".tf.TF_OperationInputListLength"); kK(v)[66]=r1(tf_tf_TF_OperationInputListLength__k);
  kS(k)[67]=ss(".tf.TF_OperationInput"); kK(v)[67]=r1(tf_tf_TF_OperationInput__k);
  kS(k)[68]=ss(".tf.TF_OperationOutputNumConsumers"); kK(v)[68]=r1(tf_tf_TF_OperationOutputNumConsumers__k);
  kS(k)[69]=ss(".tf.TF_OperationOutputConsumers"); kK(v)[69]=r1(tf_tf_TF_OperationOutputConsumers__k);
  kS(k)[70]=ss(".tf.TF_OperationNumControlInputs"); kK(v)[70]=r1(tf_tf_TF_OperationNumControlInputs__k);
  kS(k)[71]=ss(".tf.TF_OperationGetControlInputs"); kK(v)[71]=r1(tf_tf_TF_OperationGetControlInputs__k);
  kS(k)[72]=ss(".tf.TF_OperationNumControlOutputs"); kK(v)[72]=r1(tf_tf_TF_OperationNumControlOutputs__k);
  kS(k)[73]=ss(".tf.TF_OperationGetControlOutputs"); kK(v)[73]=r1(tf_tf_TF_OperationGetControlOutputs__k);
  kS(k)[74]=ss(".tf.TF_OperationGetAttrMetadata"); kK(v)[74]=r1(tf_tf_TF_OperationGetAttrMetadata__k);
  kS(k)[75]=ss(".tf.TF_OperationGetAttrString"); kK(v)[75]=r1(tf_tf_TF_OperationGetAttrString__k);
  kS(k)[76]=ss(".tf.TF_OperationGetAttrStringList"); kK(v)[76]=r1(tf_tf_TF_OperationGetAttrStringList__k);
  kS(k)[77]=ss(".tf.TF_OperationGetAttrInt"); kK(v)[77]=r1(tf_tf_TF_OperationGetAttrInt__k);
  kS(k)[78]=ss(".tf.TF_OperationGetAttrIntList"); kK(v)[78]=r1(tf_tf_TF_OperationGetAttrIntList__k);
  kS(k)[79]=ss(".tf.TF_OperationGetAttrFloat"); kK(v)[79]=r1(tf_tf_TF_OperationGetAttrFloat__k);
  kS(k)[80]=ss(".tf.TF_OperationGetAttrFloatList"); kK(v)[80]=r1(tf_tf_TF_OperationGetAttrFloatList__k);
  kS(k)[81]=ss(".tf.TF_OperationGetAttrBool"); kK(v)[81]=r1(tf_tf_TF_OperationGetAttrBool__k);
  kS(k)[82]=ss(".tf.TF_OperationGetAttrBoolList"); kK(v)[82]=r1(tf_tf_TF_OperationGetAttrBoolList__k);
  kS(k)[83]=ss(".tf.TF_OperationGetAttrType"); kK(v)[83]=r1(tf_tf_TF_OperationGetAttrType__k);
  kS(k)[84]=ss(".tf.TF_OperationGetAttrTypeList"); kK(v)[84]=r1(tf_tf_TF_OperationGetAttrTypeList__k);
  kS(k)[85]=ss(".tf.TF_OperationGetAttrShape"); kK(v)[85]=r1(tf_tf_TF_OperationGetAttrShape__k);
  kS(k)[86]=ss(".tf.TF_OperationGetAttrShapeList"); kK(v)[86]=r1(tf_tf_TF_OperationGetAttrShapeList__k);
  kS(k)[87]=ss(".tf.TF_OperationGetAttrTensorShapeProto"); kK(v)[87]=r1(tf_tf_TF_OperationGetAttrTensorShapeProto__k);
  kS(k)[88]=ss(".tf.TF_OperationGetAttrTensor"); kK(v)[88]=r1(tf_tf_TF_OperationGetAttrTensor__k);
  kS(k)[89]=ss(".tf.TF_OperationGetAttrTensorList"); kK(v)[89]=r1(tf_tf_TF_OperationGetAttrTensorList__k);
  kS(k)[90]=ss(".tf.TF_GraphOperationByName"); kK(v)[90]=r1(tf_tf_TF_GraphOperationByName__k);
  kS(k)[91]=ss(".tf.TF_GraphNextOperation"); kK(v)[91]=r1(tf_tf_TF_GraphNextOperation__k);
  kS(k)[92]=ss(".tf.TF_GraphToGraphDef"); kK(v)[92]=r1(tf_tf_TF_GraphToGraphDef__k);
  kS(k)[93]=ss(".tf.TF_GraphGetOpDef"); kK(v)[93]=r1(tf_tf_TF_GraphGetOpDef__k);
  kS(k)[94]=ss(".tf.TF_GraphVersions"); kK(v)[94]=r1(tf_tf_TF_GraphVersions__k);
  kS(k)[95]=ss(".tf.TF_NewImportGraphDefOptions"); kK(v)[95]=r1(tf_tf_TF_NewImportGraphDefOptions__k);
  kS(k)[96]=ss(".tf.TF_DeleteImportGraphDefOptions"); kK(v)[96]=r1(tf_tf_TF_DeleteImportGraphDefOptions__k);
  kS(k)[97]=ss(".tf.TF_ImportGraphDefOptionsSetPrefix"); kK(v)[97]=r1(tf_tf_TF_ImportGraphDefOptionsSetPrefix__k);
  kS(k)[98]=ss(".tf.TF_ImportGraphDefOptionsSetUniquifyNames"); kK(v)[98]=r1(tf_tf_TF_ImportGraphDefOptionsSetUniquifyNames__k);
  kS(k)[99]=ss(".tf.TF_ImportGraphDefOptionsSetUniquifyPrefix"); kK(v)[99]=r1(tf_tf_TF_ImportGraphDefOptionsSetUniquifyPrefix__k);
  kS(k)[100]=ss(".tf.TF_ImportGraphDefOptionsAddInputMapping"); kK(v)[100]=r1(tf_tf_TF_ImportGraphDefOptionsAddInputMapping__k);
  kS(k)[101]=ss(".tf.TF_ImportGraphDefOptionsRemapControlDependency"); kK(v)[101]=r1(tf_tf_TF_ImportGraphDefOptionsRemapControlDependency__k);
  kS(k)[102]=ss(".tf.TF_ImportGraphDefOptionsAddControlDependency"); kK(v)[102]=r1(tf_tf_TF_ImportGraphDefOptionsAddControlDependency__k);
  kS(k)[103]=ss(".tf.TF_ImportGraphDefOptionsAddReturnOutput"); kK(v)[103]=r1(tf_tf_TF_ImportGraphDefOptionsAddReturnOutput__k);
  kS(k)[104]=ss(".tf.TF_ImportGraphDefOptionsNumReturnOutputs"); kK(v)[104]=r1(tf_tf_TF_ImportGraphDefOptionsNumReturnOutputs__k);
  kS(k)[105]=ss(".tf.TF_ImportGraphDefOptionsAddReturnOperation"); kK(v)[105]=r1(tf_tf_TF_ImportGraphDefOptionsAddReturnOperation__k);
  kS(k)[106]=ss(".tf.TF_ImportGraphDefOptionsNumReturnOperations"); kK(v)[106]=r1(tf_tf_TF_ImportGraphDefOptionsNumReturnOperations__k);
  kS(k)[107]=ss(".tf.TF_ImportGraphDefResultsReturnOutputs"); kK(v)[107]=r1(tf_tf_TF_ImportGraphDefResultsReturnOutputs__k);
  kS(k)[108]=ss(".tf.TF_ImportGraphDefResultsReturnOperations"); kK(v)[108]=r1(tf_tf_TF_ImportGraphDefResultsReturnOperations__k);
  kS(k)[109]=ss(".tf.TF_ImportGraphDefResultsMissingUnusedInputMappings"); kK(v)[109]=r1(tf_tf_TF_ImportGraphDefResultsMissingUnusedInputMappings__k);
  kS(k)[110]=ss(".tf.TF_DeleteImportGraphDefResults"); kK(v)[110]=r1(tf_tf_TF_DeleteImportGraphDefResults__k);
  kS(k)[111]=ss(".tf.TF_GraphImportGraphDefWithResults"); kK(v)[111]=r1(tf_tf_TF_GraphImportGraphDefWithResults__k);
  kS(k)[112]=ss(".tf.TF_GraphImportGraphDefWithReturnOutputs"); kK(v)[112]=r1(tf_tf_TF_GraphImportGraphDefWithReturnOutputs__k);
  kS(k)[113]=ss(".tf.TF_GraphImportGraphDef"); kK(v)[113]=r1(tf_tf_TF_GraphImportGraphDef__k);
  kS(k)[114]=ss(".tf.TF_GraphCopyFunction"); kK(v)[114]=r1(tf_tf_TF_GraphCopyFunction__k);
  kS(k)[115]=ss(".tf.TF_OperationToNodeDef"); kK(v)[115]=r1(tf_tf_TF_OperationToNodeDef__k);
  kS(k)[116]=ss(".tf.setWhileParams"); kK(v)[116]=r1(tf_tf_setWhileParams__k);
  kS(k)[117]=ss(".tf.TF_FinishWhile"); kK(v)[117]=r1(tf_tf_TF_FinishWhile__k);
  kS(k)[118]=ss(".tf.TF_AbortWhile"); kK(v)[118]=r1(tf_tf_TF_AbortWhile__k);
  kS(k)[119]=ss(".tf.TF_AddGradients"); kK(v)[119]=r1(tf_tf_TF_AddGradients__k);
  kS(k)[120]=ss(".tf.TF_GraphToFunction"); kK(v)[120]=r1(tf_tf_TF_GraphToFunction__k);
  kS(k)[121]=ss(".tf.TF_FunctionToFunctionDef"); kK(v)[121]=r1(tf_tf_TF_FunctionToFunctionDef__k);
  kS(k)[122]=ss(".tf.TF_FunctionImportFunctionDef"); kK(v)[122]=r1(tf_tf_TF_FunctionImportFunctionDef__k);
  kS(k)[123]=ss(".tf.TF_FunctionSetAttrValueProto"); kK(v)[123]=r1(tf_tf_TF_FunctionSetAttrValueProto__k);
  kS(k)[124]=ss(".tf.TF_FunctionGetAttrValueProto"); kK(v)[124]=r1(tf_tf_TF_FunctionGetAttrValueProto__k);
  kS(k)[125]=ss(".tf.TF_DeleteFunction"); kK(v)[125]=r1(tf_tf_TF_DeleteFunction__k);
  kS(k)[126]=ss(".tf.TF_NewSession"); kK(v)[126]=r1(tf_tf_TF_NewSession__k);
  kS(k)[127]=ss(".tf.TF_LoadSessionFromSavedModel"); kK(v)[127]=r1(tf_tf_TF_LoadSessionFromSavedModel__k);
  kS(k)[128]=ss(".tf.TF_CloseSession"); kK(v)[128]=r1(tf_tf_TF_CloseSession__k);
  kS(k)[129]=ss(".tf.TF_DeleteSession"); kK(v)[129]=r1(tf_tf_TF_DeleteSession__k);
  kS(k)[130]=ss(".tf.TF_SessionRun"); kK(v)[130]=r1(tf_tf_TF_SessionRun__k);
  kS(k)[131]=ss(".tf.TF_SessionPRunSetup"); kK(v)[131]=r1(tf_tf_TF_SessionPRunSetup__k);
  kS(k)[132]=ss(".tf.TF_SessionPRun"); kK(v)[132]=r1(tf_tf_TF_SessionPRun__k);
  kS(k)[133]=ss(".tf.TF_DeletePRunHandle"); kK(v)[133]=r1(tf_tf_TF_DeletePRunHandle__k);
  kS(k)[134]=ss(".tf.TF_SessionListDevices"); kK(v)[134]=r1(tf_tf_TF_SessionListDevices__k);
  kS(k)[135]=ss(".tf.TF_DeleteDeviceList"); kK(v)[135]=r1(tf_tf_TF_DeleteDeviceList__k);
  kS(k)[136]=ss(".tf.TF_DeviceListCount"); kK(v)[136]=r1(tf_tf_TF_DeviceListCount__k);
  kS(k)[137]=ss(".tf.TF_DeviceListName"); kK(v)[137]=r1(tf_tf_TF_DeviceListName__k);
  kS(k)[138]=ss(".tf.TF_DeviceListType"); kK(v)[138]=r1(tf_tf_TF_DeviceListType__k);
  kS(k)[139]=ss(".tf.TF_DeviceListMemoryBytes"); kK(v)[139]=r1(tf_tf_TF_DeviceListMemoryBytes__k);
  kS(k)[140]=ss(".tf.TF_LoadLibrary"); kK(v)[140]=r1(tf_tf_TF_LoadLibrary__k);
  kS(k)[141]=ss(".tf.TF_GetOpList"); kK(v)[141]=r1(tf_tf_TF_GetOpList__k);
  kS(k)[142]=ss(".tf.TF_DeleteLibraryHandle"); kK(v)[142]=r1(tf_tf_TF_DeleteLibraryHandle__k);
  kS(k)[143]=ss(".tf.TF_GetAllOpList"); kK(v)[143]=r1(tf_tf_TF_GetAllOpList__k);
  kS(k1)[0]=ss(".b2c.wglobals"); kJ(v1)[0]=(J)&__wglobals;
  __libFuncs=xD(k,v); __libGlobs=xD(k1,v1);
  return r1(__libFuncs);
 };


K tf__init(K x) {
  K res=(K)0;

  if(__ginited>0) return tf__getLib((K)0);
  __ginited=1; K lst;

  res=k(0,".q`set`show`enlist`any`not`get`cols`upsert`meta`xasc`xdesc`inv`keys`all`type`each",(K)0); if((0==res)||(-128==res->t)) { __ginited=0; return res;}; __q=(K*)res->G0;
  res=k(0,"``.b2c.intmap`.b2c.libFuncs`C.toK`.b2c.libGlobs`C.knk`C.dot`.b2c.kapp1`.b2c.wglobals`C.kamend4`C.r0`C.r1`.b2c.kxsc`C.kamend3`C.ktn`C.TF_Version`C.errno`.string.strerror`C.TF_DataTypeSize`C.TF_NewStatus`C.TF_DeleteStatus`C.TF_SetStatus`C.TF_GetCode`C.TF_Message`C.TF_NewBufferFromString`C.TF_NewBuffer`C.TF_DeleteBuffer`.tf.getQPtr`.tf.deallocator`C.TF_NewTensor`C.TF_AllocateTensor`C.TF_TensorMaybeMove`C.TF_DeleteTensor`C.TF_TensorType`C.TF_NumDims`C.TF_Dim`C.TF_TensorByteSize`C.TF_TensorData`C.TF_StringEncode`C.TF_StringDecode`C.TF_StringEncodedSize`C.TF_NewSessionOptions`C.TF_SetTarget`C.TF_SetConfig`C.TF_DeleteSessionOptions`C.TF_NewGraph`C.TF_DeleteGraph`C.TF_GraphSetTensorShape`C.TF_GraphGetTensorNumDims`C.TF_GraphGetTensorShape`C.TF_NewOperation`C.TF_SetDevice`C.TF_AddInput`.tf.encodeOut`C.TF_AddInputList`C.TF_AddControlInput`C.TF_SetAttrString`C.TF_SetAttrStringList`C.TF_SetAttrInt`C.TF_SetAttrIntList`C.TF_SetAttrFloat`C.TF_SetAttrFloatList`C.TF_SetAttrBool`C.TF_SetAttrBoolList`C.TF_SetAttrType`C.TF_SetAttrTypeList`C.TF_SetAttrShape`C.TF_SetAttrShapeList`C.TF_SetAttrTensorShapeProto`C.TF_SetAttrTensorShapeProtoList`C.TF_SetAttrTensor`C.TF_SetAttrTensorList`C.TF_SetAttrValueProto`C.TF_FinishOperation`C.TF_OperationName`C.TF_OperationOpType`C.TF_OperationDevice`C.TF_OperationNumOutputs`C.TF_OperationOutputType`C.TF_OperationOutputListLength`C.TF_OperationNumInputs`C.TF_OperationInputType`C.TF_OperationInputListLength`C.TF_OperationInput`C.TF_OperationOutputNumConsumers`C.TF_OperationOutputConsumers`C.TF_OperationNumControlInputs`C.TF_OperationGetControlInputs`C.TF_OperationNumControlOutputs`C.TF_OperationGetControlOutputs`C.TF_OperationGetAttrMetadata`C.TF_OperationGetAttrString`C.TF_OperationGetAttrStringList`C.TF_OperationGetAttrInt`C.TF_OperationGetAttrIntList`C.TF_OperationGetAttrFloat`C.TF_OperationGetAttrFloatList`C.TF_OperationGetAttrBool`C.TF_OperationGetAttrBoolList`C.TF_OperationGetAttrType`C.TF_OperationGetAttrTypeList`C.TF_OperationGetAttrShape`C.TF_OperationGetAttrShapeList`C.TF_OperationGetAttrTensorShapeProto`C.TF_OperationGetAttrTensor`C.TF_OperationGetAttrTensorList`C.TF_GraphOperationByName`C.TF_GraphNextOperation`C.TF_GraphToGraphDef`C.TF_GraphGetOpDef`C.TF_GraphVersions`C.TF_NewImportGraphDefOptions`C.TF_DeleteImportGraphDefOptions`C.TF_ImportGraphDefOptionsSetPrefix`C.TF_ImportGraphDefOptionsSetUniquifyNames`C.TF_ImportGraphDefOptionsSetUniquifyPrefix`C.TF_ImportGraphDefOptionsAddInputMapping`C.TF_ImportGraphDefOptionsRemapControlDependency`C.TF_ImportGraphDefOptionsAddControlDependency`C.TF_ImportGraphDefOptionsAddReturnOutput`C.TF_ImportGraphDefOptionsNumReturnOutputs`C.TF_ImportGraphDefOptionsAddReturnOperation`C.TF_ImportGraphDefOptionsNumReturnOperations`C.TF_ImportGraphDefResultsReturnOutputs`C.TF_ImportGraphDefResultsReturnOperations`C.TF_ImportGraphDefResultsMissingUnusedInputMappings`C.TF_DeleteImportGraphDefResults`C.TF_GraphImportGraphDefWithResults`C.TF_GraphImportGraphDefWithReturnOutputs`C.TF_GraphImportGraphDef`C.TF_GraphCopyFunction`C.TF_OperationToNodeDef`C.TF_FinishWhile`C.TF_AbortWhile`C.NULL`C.TF_AddGradients`C.TF_GraphToFunction`C.TF_FunctionToFunctionDef`C.TF_FunctionImportFunctionDef`C.TF_FunctionSetAttrValueProto`C.TF_FunctionGetAttrValueProto`C.TF_DeleteFunction`C.TF_NewSession`C.TF_LoadSessionFromSavedModel`C.TF_CloseSession`C.TF_DeleteSession`C.TF_SessionRun`C.TF_SessionPRunSetup`C.TF_SessionPRun`C.TF_DeletePRunHandle`C.TF_SessionListDevices`C.TF_DeleteDeviceList`C.TF_DeviceListCount`C.TF_DeviceListName`C.TF_DeviceListType`C.TF_DeviceListMemoryBytes`C.TF_LoadLibrary`C.TF_GetOpList`.tf.getBuffer`C.TF_DeleteLibraryHandle`C.TF_GetAllOpList,1",(K)0); if((0==res)||(-128==res->t)) { __ginited=0; return res;}; __glob=(K*)res->G0;
  tf_tf_getBuffer__k=dl(tf_tf_getBuffer,1);
  tf_tf_encodeOut__k=dl(tf_tf_encodeOut,1);
  tf_tf_TF_Version__k=dl(tf_tf_TF_Version,1);
  tf_tf_TF_DataTypeSize__k=dl(tf_tf_TF_DataTypeSize,1);
  tf_tf_TF_NewStatus__k=dl(tf_tf_TF_NewStatus,1);
  tf_tf_TF_DeleteStatus__k=dl(tf_tf_TF_DeleteStatus,1);
  tf_tf_TF_SetStatus__k=dl(tf_tf_TF_SetStatus,3);
  tf_tf_TF_GetCode__k=dl(tf_tf_TF_GetCode,1);
  tf_tf_TF_Message__k=dl(tf_tf_TF_Message,1);
  tf_tf_TF_NewBufferFromString__k=dl(tf_tf_TF_NewBufferFromString,1);
  tf_tf_TF_NewBuffer__k=dl(tf_tf_TF_NewBuffer,1);
  tf_tf_TF_DeleteBuffer__k=dl(tf_tf_TF_DeleteBuffer,1);
  tf_tf_TF_NewTensor__k=dl(tf_tf_TF_NewTensor,3);
  tf_tf_TF_AllocateTensor__k=dl(tf_tf_TF_AllocateTensor,3);
  tf_tf_TF_TensorMaybeMove__k=dl(tf_tf_TF_TensorMaybeMove,1);
  tf_tf_TF_DeleteTensor__k=dl(tf_tf_TF_DeleteTensor,1);
  tf_tf_TF_TensorType__k=dl(tf_tf_TF_TensorType,1);
  tf_tf_TF_NumDims__k=dl(tf_tf_TF_NumDims,1);
  tf_tf_TF_Dim__k=dl(tf_tf_TF_Dim,2);
  tf_tf_TF_TensorByteSize__k=dl(tf_tf_TF_TensorByteSize,1);
  tf_tf_TF_TensorData__k=dl(tf_tf_TF_TensorData,1);
  tf_tf_writeToTensor__k=dl(tf_tf_writeToTensor,2);
  tf_tf_readFromTensor__k=dl(tf_tf_readFromTensor,2);
  tf_tf_TF_StringEncode__k=dl(tf_tf_TF_StringEncode,4);
  tf_tf_TF_StringDecode__k=dl(tf_tf_TF_StringDecode,3);
  tf_tf_TF_StringEncodedSize__k=dl(tf_tf_TF_StringEncodedSize,1);
  tf_tf_TF_NewSessionOptions__k=dl(tf_tf_TF_NewSessionOptions,1);
  tf_tf_TF_SetTarget__k=dl(tf_tf_TF_SetTarget,2);
  tf_tf_TF_SetConfig__k=dl(tf_tf_TF_SetConfig,3);
  tf_tf_TF_DeleteSessionOptions__k=dl(tf_tf_TF_DeleteSessionOptions,1);
  tf_tf_TF_NewGraph__k=dl(tf_tf_TF_NewGraph,1);
  tf_tf_TF_DeleteGraph__k=dl(tf_tf_TF_DeleteGraph,1);
  tf_tf_TF_GraphSetTensorShape__k=dl(tf_tf_TF_GraphSetTensorShape,4);
  tf_tf_TF_GraphGetTensorNumDims__k=dl(tf_tf_TF_GraphGetTensorNumDims,3);
  tf_tf_TF_GraphGetTensorShape__k=dl(tf_tf_TF_GraphGetTensorShape,4);
  tf_tf_TF_NewOperation__k=dl(tf_tf_TF_NewOperation,3);
  tf_tf_TF_SetDevice__k=dl(tf_tf_TF_SetDevice,2);
  tf_tf_TF_AddInput__k=dl(tf_tf_TF_AddInput,2);
  tf_tf_TF_AddInputList__k=dl(tf_tf_TF_AddInputList,2);
  tf_tf_TF_AddControlInput__k=dl(tf_tf_TF_AddControlInput,2);
  tf_tf_TF_SetAttrString__k=dl(tf_tf_TF_SetAttrString,3);
  tf_tf_TF_SetAttrStringList__k=dl(tf_tf_TF_SetAttrStringList,3);
  tf_tf_TF_SetAttrInt__k=dl(tf_tf_TF_SetAttrInt,3);
  tf_tf_TF_SetAttrIntList__k=dl(tf_tf_TF_SetAttrIntList,3);
  tf_tf_TF_SetAttrFloat__k=dl(tf_tf_TF_SetAttrFloat,3);
  tf_tf_TF_SetAttrFloatList__k=dl(tf_tf_TF_SetAttrFloatList,3);
  tf_tf_TF_SetAttrBool__k=dl(tf_tf_TF_SetAttrBool,3);
  tf_tf_TF_SetAttrBoolList__k=dl(tf_tf_TF_SetAttrBoolList,3);
  tf_tf_TF_SetAttrType__k=dl(tf_tf_TF_SetAttrType,3);
  tf_tf_TF_SetAttrTypeList__k=dl(tf_tf_TF_SetAttrTypeList,3);
  tf_tf_TF_SetAttrShape__k=dl(tf_tf_TF_SetAttrShape,3);
  tf_tf_TF_SetAttrShapeList__k=dl(tf_tf_TF_SetAttrShapeList,3);
  tf_tf_TF_SetAttrTensorShapeProto__k=dl(tf_tf_TF_SetAttrTensorShapeProto,4);
  tf_tf_TF_SetAttrTensorShapeProtoList__k=dl(tf_tf_TF_SetAttrTensorShapeProtoList,4);
  tf_tf_TF_SetAttrTensor__k=dl(tf_tf_TF_SetAttrTensor,4);
  tf_tf_TF_SetAttrTensorList__k=dl(tf_tf_TF_SetAttrTensorList,4);
  tf_tf_TF_SetAttrValueProto__k=dl(tf_tf_TF_SetAttrValueProto,4);
  tf_tf_TF_FinishOperation__k=dl(tf_tf_TF_FinishOperation,2);
  tf_tf_TF_OperationName__k=dl(tf_tf_TF_OperationName,1);
  tf_tf_TF_OperationOpType__k=dl(tf_tf_TF_OperationOpType,1);
  tf_tf_TF_OperationDevice__k=dl(tf_tf_TF_OperationDevice,1);
  tf_tf_TF_OperationNumOutputs__k=dl(tf_tf_TF_OperationNumOutputs,1);
  tf_tf_TF_OperationOutputType__k=dl(tf_tf_TF_OperationOutputType,1);
  tf_tf_TF_OperationOutputListLength__k=dl(tf_tf_TF_OperationOutputListLength,3);
  tf_tf_TF_OperationNumInputs__k=dl(tf_tf_TF_OperationNumInputs,1);
  tf_tf_TF_OperationInputType__k=dl(tf_tf_TF_OperationInputType,1);
  tf_tf_TF_OperationInputListLength__k=dl(tf_tf_TF_OperationInputListLength,3);
  tf_tf_TF_OperationInput__k=dl(tf_tf_TF_OperationInput,1);
  tf_tf_TF_OperationOutputNumConsumers__k=dl(tf_tf_TF_OperationOutputNumConsumers,1);
  tf_tf_TF_OperationOutputConsumers__k=dl(tf_tf_TF_OperationOutputConsumers,1);
  tf_tf_TF_OperationNumControlInputs__k=dl(tf_tf_TF_OperationNumControlInputs,1);
  tf_tf_TF_OperationGetControlInputs__k=dl(tf_tf_TF_OperationGetControlInputs,2);
  tf_tf_TF_OperationNumControlOutputs__k=dl(tf_tf_TF_OperationNumControlOutputs,1);
  tf_tf_TF_OperationGetControlOutputs__k=dl(tf_tf_TF_OperationGetControlOutputs,2);
  tf_tf_TF_OperationGetAttrMetadata__k=dl(tf_tf_TF_OperationGetAttrMetadata,3);
  tf_tf_TF_OperationGetAttrString__k=dl(tf_tf_TF_OperationGetAttrString,4);
  tf_tf_TF_OperationGetAttrStringList__k=dl(tf_tf_TF_OperationGetAttrStringList,6);
  tf_tf_TF_OperationGetAttrInt__k=dl(tf_tf_TF_OperationGetAttrInt,3);
  tf_tf_TF_OperationGetAttrIntList__k=dl(tf_tf_TF_OperationGetAttrIntList,4);
  tf_tf_TF_OperationGetAttrFloat__k=dl(tf_tf_TF_OperationGetAttrFloat,3);
  tf_tf_TF_OperationGetAttrFloatList__k=dl(tf_tf_TF_OperationGetAttrFloatList,4);
  tf_tf_TF_OperationGetAttrBool__k=dl(tf_tf_TF_OperationGetAttrBool,3);
  tf_tf_TF_OperationGetAttrBoolList__k=dl(tf_tf_TF_OperationGetAttrBoolList,4);
  tf_tf_TF_OperationGetAttrType__k=dl(tf_tf_TF_OperationGetAttrType,3);
  tf_tf_TF_OperationGetAttrTypeList__k=dl(tf_tf_TF_OperationGetAttrTypeList,4);
  tf_tf_TF_OperationGetAttrShape__k=dl(tf_tf_TF_OperationGetAttrShape,4);
  tf_tf_TF_OperationGetAttrShapeList__k=dl(tf_tf_TF_OperationGetAttrShapeList,6);
  tf_tf_TF_OperationGetAttrTensorShapeProto__k=dl(tf_tf_TF_OperationGetAttrTensorShapeProto,4);
  tf_tf_TF_OperationGetAttrTensor__k=dl(tf_tf_TF_OperationGetAttrTensor,3);
  tf_tf_TF_OperationGetAttrTensorList__k=dl(tf_tf_TF_OperationGetAttrTensorList,5);
  tf_tf_TF_GraphOperationByName__k=dl(tf_tf_TF_GraphOperationByName,2);
  tf_tf_TF_GraphNextOperation__k=dl(tf_tf_TF_GraphNextOperation,2);
  tf_tf_TF_GraphToGraphDef__k=dl(tf_tf_TF_GraphToGraphDef,3);
  tf_tf_TF_GraphGetOpDef__k=dl(tf_tf_TF_GraphGetOpDef,4);
  tf_tf_TF_GraphVersions__k=dl(tf_tf_TF_GraphVersions,3);
  tf_tf_TF_NewImportGraphDefOptions__k=dl(tf_tf_TF_NewImportGraphDefOptions,1);
  tf_tf_TF_DeleteImportGraphDefOptions__k=dl(tf_tf_TF_DeleteImportGraphDefOptions,1);
  tf_tf_TF_ImportGraphDefOptionsSetPrefix__k=dl(tf_tf_TF_ImportGraphDefOptionsSetPrefix,2);
  tf_tf_TF_ImportGraphDefOptionsSetUniquifyNames__k=dl(tf_tf_TF_ImportGraphDefOptionsSetUniquifyNames,2);
  tf_tf_TF_ImportGraphDefOptionsSetUniquifyPrefix__k=dl(tf_tf_TF_ImportGraphDefOptionsSetUniquifyPrefix,2);
  tf_tf_TF_ImportGraphDefOptionsAddInputMapping__k=dl(tf_tf_TF_ImportGraphDefOptionsAddInputMapping,4);
  tf_tf_TF_ImportGraphDefOptionsRemapControlDependency__k=dl(tf_tf_TF_ImportGraphDefOptionsRemapControlDependency,3);
  tf_tf_TF_ImportGraphDefOptionsAddControlDependency__k=dl(tf_tf_TF_ImportGraphDefOptionsAddControlDependency,2);
  tf_tf_TF_ImportGraphDefOptionsAddReturnOutput__k=dl(tf_tf_TF_ImportGraphDefOptionsAddReturnOutput,3);
  tf_tf_TF_ImportGraphDefOptionsNumReturnOutputs__k=dl(tf_tf_TF_ImportGraphDefOptionsNumReturnOutputs,1);
  tf_tf_TF_ImportGraphDefOptionsAddReturnOperation__k=dl(tf_tf_TF_ImportGraphDefOptionsAddReturnOperation,2);
  tf_tf_TF_ImportGraphDefOptionsNumReturnOperations__k=dl(tf_tf_TF_ImportGraphDefOptionsNumReturnOperations,1);
  tf_tf_TF_ImportGraphDefResultsReturnOutputs__k=dl(tf_tf_TF_ImportGraphDefResultsReturnOutputs,1);
  tf_tf_TF_ImportGraphDefResultsReturnOperations__k=dl(tf_tf_TF_ImportGraphDefResultsReturnOperations,1);
  tf_tf_TF_ImportGraphDefResultsMissingUnusedInputMappings__k=dl(tf_tf_TF_ImportGraphDefResultsMissingUnusedInputMappings,1);
  tf_tf_TF_DeleteImportGraphDefResults__k=dl(tf_tf_TF_DeleteImportGraphDefResults,1);
  tf_tf_TF_GraphImportGraphDefWithResults__k=dl(tf_tf_TF_GraphImportGraphDefWithResults,4);
  tf_tf_TF_GraphImportGraphDefWithReturnOutputs__k=dl(tf_tf_TF_GraphImportGraphDefWithReturnOutputs,4);
  tf_tf_TF_GraphImportGraphDef__k=dl(tf_tf_TF_GraphImportGraphDef,4);
  tf_tf_TF_GraphCopyFunction__k=dl(tf_tf_TF_GraphCopyFunction,4);
  tf_tf_TF_OperationToNodeDef__k=dl(tf_tf_TF_OperationToNodeDef,3);
  tf_tf_setWhileParams__k=dl(tf_tf_setWhileParams,3);
  tf_tf_TF_FinishWhile__k=dl(tf_tf_TF_FinishWhile,2);
  tf_tf_TF_AbortWhile__k=dl(tf_tf_TF_AbortWhile,1);
  tf_tf_TF_AddGradients__k=dl(tf_tf_TF_AddGradients,5);
  tf_tf_TF_GraphToFunction__k=dl(tf_tf_TF_GraphToFunction,7);
  tf_tf_TF_FunctionToFunctionDef__k=dl(tf_tf_TF_FunctionToFunctionDef,3);
  tf_tf_TF_FunctionImportFunctionDef__k=dl(tf_tf_TF_FunctionImportFunctionDef,2);
  tf_tf_TF_FunctionSetAttrValueProto__k=dl(tf_tf_TF_FunctionSetAttrValueProto,4);
  tf_tf_TF_FunctionGetAttrValueProto__k=dl(tf_tf_TF_FunctionGetAttrValueProto,4);
  tf_tf_TF_DeleteFunction__k=dl(tf_tf_TF_DeleteFunction,1);
  tf_tf_TF_NewSession__k=dl(tf_tf_TF_NewSession,3);
  tf_tf_TF_LoadSessionFromSavedModel__k=dl(tf_tf_TF_LoadSessionFromSavedModel,7);
  tf_tf_TF_CloseSession__k=dl(tf_tf_TF_CloseSession,2);
  tf_tf_TF_DeleteSession__k=dl(tf_tf_TF_DeleteSession,2);
  tf_tf_TF_SessionRun__k=dl(tf_tf_TF_SessionRun,7);
  tf_tf_TF_SessionPRunSetup__k=dl(tf_tf_TF_SessionPRunSetup,5);
  tf_tf_TF_SessionPRun__k=dl(tf_tf_TF_SessionPRun,6);
  tf_tf_TF_DeletePRunHandle__k=dl(tf_tf_TF_DeletePRunHandle,1);
  tf_tf_TF_SessionListDevices__k=dl(tf_tf_TF_SessionListDevices,2);
  tf_tf_TF_DeleteDeviceList__k=dl(tf_tf_TF_DeleteDeviceList,1);
  tf_tf_TF_DeviceListCount__k=dl(tf_tf_TF_DeviceListCount,1);
  tf_tf_TF_DeviceListName__k=dl(tf_tf_TF_DeviceListName,3);
  tf_tf_TF_DeviceListType__k=dl(tf_tf_TF_DeviceListType,3);
  tf_tf_TF_DeviceListMemoryBytes__k=dl(tf_tf_TF_DeviceListMemoryBytes,3);
  tf_tf_TF_LoadLibrary__k=dl(tf_tf_TF_LoadLibrary,2);
  tf_tf_TF_GetOpList__k=dl(tf_tf_TF_GetOpList,1);
  tf_tf_TF_DeleteLibraryHandle__k=dl(tf_tf_TF_DeleteLibraryHandle,1);
  tf_tf_TF_GetAllOpList__k=dl(tf_tf_TF_GetAllOpList,1);
  res=tf__cnstInit(); if(!(res==(K)1)) { __ginited=0; return res;};

  return tf__getLib((K)0);
 };

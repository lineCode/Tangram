// Created by Microsoft (R) C/C++ Compiler Version 15.00.21022.08 (a8dffad6).
// C++ source equivalent of Win32 type library C:\Program Files\Common Files\Microsoft Shared\OFFICE14\ACEDAO.DLL
// compiler-generated file created 01/01/10 at 00:14:59 - DO NOT EDIT!

//
// Cross-referenced type libraries:
//
//#include "msado25.h"
#include "mso.h"
//

#pragma once
#pragma pack(push, 8)

#include <comdef.h>

namespace DAO {

//
// Forward references and typedefs
//

struct __declspec(uuid("4ac9e1da-5bad-4ac7-86e3-24f4cdceca28"))
/* LIBID */ __DAO;
enum RecordsetTypeEnum;
enum EditModeEnum;
enum RecordsetOptionEnum;
enum LockTypeEnum;
enum UpdateCriteriaEnum;
enum FieldAttributeEnum;
enum DataTypeEnum;
enum RelationAttributeEnum;
enum TableDefAttributeEnum;
enum QueryDefTypeEnum;
enum QueryDefStateEnum;
enum DatabaseTypeEnum;
enum CollatingOrderEnum;
enum IdleEnum;
enum PermissionEnum;
enum SynchronizeTypeEnum;
enum ReplicaTypeEnum;
enum WorkspaceTypeEnum;
enum CursorDriverEnum;
enum DriverPromptEnum;
enum SetOptionEnum;
enum ParameterDirectionEnum;
enum UpdateTypeEnum;
enum RecordStatusEnum;
enum CommitTransOptionsEnum;
enum _DAOSuppHelp;
struct __declspec(uuid("0000000a-0000-0010-8000-00aa006d2ea4"))
/* dual interface */ _DAO;
struct __declspec(uuid("00000029-0000-0010-8000-00aa006d2ea4"))
/* dual interface */ Properties;
struct __declspec(uuid("000000a2-0000-0010-8000-00aa006d2ea4"))
/* dual interface */ _DynaCollection;
struct __declspec(uuid("000000a0-0000-0010-8000-00aa006d2ea4"))
/* dual interface */ _Collection;
struct __declspec(uuid("00000027-0000-0010-8000-00aa006d2ea4"))
/* dual interface */ Property;
struct __declspec(uuid("00000021-0000-0010-8000-00aa006d2ea4"))
/* dual interface */ _DBEngine;
struct __declspec(uuid("0000003b-0000-0010-8000-00aa006d2ea4"))
/* dual interface */ Workspaces;
struct __declspec(uuid("00000039-0000-0010-8000-00aa006d2ea4"))
/* dual interface */ Workspace;
struct __declspec(uuid("00000073-0000-0010-8000-00aa006d2ea4"))
/* dual interface */ Databases;
struct __declspec(uuid("00000071-0000-0010-8000-00aa006d2ea4"))
/* dual interface */ Database;
struct __declspec(uuid("0000004b-0000-0010-8000-00aa006d2ea4"))
/* dual interface */ TableDefs;
struct /* coclass */ TableDef;
struct __declspec(uuid("00000049-0000-0010-8000-00aa006d2ea4"))
/* dual interface */ _TableDef;
struct __declspec(uuid("00000053-0000-0010-8000-00aa006d2ea4"))
/* dual interface */ Fields;
struct /* coclass */ Field;
struct __declspec(uuid("00000051-0000-0010-8000-00aa006d2ea4"))
/* dual interface */ _Field;
struct __declspec(uuid("0000005b-0000-0010-8000-00aa006d2ea4"))
/* dual interface */ Indexes;
struct /* coclass */ Index;
struct __declspec(uuid("00000059-0000-0010-8000-00aa006d2ea4"))
/* dual interface */ _Index;
struct __declspec(uuid("00000031-0000-0010-8000-00aa006d2ea4"))
/* dual interface */ Recordset;
struct /* coclass */ QueryDef;
struct __declspec(uuid("00000079-0000-0010-8000-00aa006d2ea4"))
/* dual interface */ _QueryDef;
struct __declspec(uuid("00000083-0000-0010-8000-00aa006d2ea4"))
/* dual interface */ Parameters;
struct __declspec(uuid("00000081-0000-0010-8000-00aa006d2ea4"))
/* dual interface */ Parameter;
struct __declspec(uuid("00000041-0000-0010-8000-00aa006d2ea4"))
/* dual interface */ Connection;
struct __declspec(uuid("0000007b-0000-0010-8000-00aa006d2ea4"))
/* dual interface */ QueryDefs;
struct __declspec(uuid("00000033-0000-0010-8000-00aa006d2ea4"))
/* dual interface */ Recordsets;
struct __declspec(uuid("0000008b-0000-0010-8000-00aa006d2ea4"))
/* dual interface */ Relations;
struct /* coclass */ Relation;
struct __declspec(uuid("00000089-0000-0010-8000-00aa006d2ea4"))
/* dual interface */ _Relation;
struct __declspec(uuid("00000093-0000-0010-8000-00aa006d2ea4"))
/* dual interface */ Containers;
struct __declspec(uuid("00000091-0000-0010-8000-00aa006d2ea4"))
/* dual interface */ Container;
struct __declspec(uuid("0000009b-0000-0010-8000-00aa006d2ea4"))
/* dual interface */ Documents;
struct __declspec(uuid("00000099-0000-0010-8000-00aa006d2ea4"))
/* dual interface */ Document;
struct __declspec(uuid("0000006b-0000-0010-8000-00aa006d2ea4"))
/* dual interface */ Users;
struct /* coclass */ User;
struct __declspec(uuid("00000069-0000-0010-8000-00aa006d2ea4"))
/* dual interface */ _User;
struct __declspec(uuid("00000063-0000-0010-8000-00aa006d2ea4"))
/* dual interface */ Groups;
struct /* coclass */ Group;
struct __declspec(uuid("00000061-0000-0010-8000-00aa006d2ea4"))
/* dual interface */ _Group;
struct __declspec(uuid("00000043-0000-0010-8000-00aa006d2ea4"))
/* dual interface */ Connections;
struct __declspec(uuid("00000025-0000-0010-8000-00aa006d2ea4"))
/* dual interface */ Errors;
struct __declspec(uuid("00000023-0000-0010-8000-00aa006d2ea4"))
/* dual interface */ Error;
struct __declspec(uuid("0000009d-0000-0010-8000-00aa006d2ea4"))
/* dual interface */ ComplexType;
struct /* coclass */ DBEngine;
struct /* coclass */ PrivDBEngine;
struct __declspec(uuid("0000005d-0000-0010-8000-00aa006d2ea4"))
/* dual interface */ IndexFields;
struct __declspec(uuid("00000035-0000-0010-8000-00aa006d2ea4"))
/* dual interface */ Recordset2;
struct __declspec(uuid("00000054-0000-0010-8000-00aa006d2ea4"))
/* dual interface */ Field2;

//
// Smart pointer typedef declarations
//

_COM_SMARTPTR_TYPEDEF(_Collection, __uuidof(_Collection));
_COM_SMARTPTR_TYPEDEF(_DynaCollection, __uuidof(_DynaCollection));
_COM_SMARTPTR_TYPEDEF(TableDefs, __uuidof(TableDefs));
_COM_SMARTPTR_TYPEDEF(Fields, __uuidof(Fields));
_COM_SMARTPTR_TYPEDEF(Indexes, __uuidof(Indexes));
_COM_SMARTPTR_TYPEDEF(QueryDefs, __uuidof(QueryDefs));
_COM_SMARTPTR_TYPEDEF(Relations, __uuidof(Relations));
_COM_SMARTPTR_TYPEDEF(Users, __uuidof(Users));
_COM_SMARTPTR_TYPEDEF(Groups, __uuidof(Groups));
_COM_SMARTPTR_TYPEDEF(Error, __uuidof(Error));
_COM_SMARTPTR_TYPEDEF(Errors, __uuidof(Errors));
_COM_SMARTPTR_TYPEDEF(ComplexType, __uuidof(ComplexType));
_COM_SMARTPTR_TYPEDEF(IndexFields, __uuidof(IndexFields));
_COM_SMARTPTR_TYPEDEF(_DAO, __uuidof(_DAO));
_COM_SMARTPTR_TYPEDEF(Property, __uuidof(Property));
_COM_SMARTPTR_TYPEDEF(Properties, __uuidof(Properties));
_COM_SMARTPTR_TYPEDEF(_Field, __uuidof(_Field));
_COM_SMARTPTR_TYPEDEF(_Index, __uuidof(_Index));
_COM_SMARTPTR_TYPEDEF(Parameter, __uuidof(Parameter));
_COM_SMARTPTR_TYPEDEF(Parameters, __uuidof(Parameters));
_COM_SMARTPTR_TYPEDEF(_Relation, __uuidof(_Relation));
_COM_SMARTPTR_TYPEDEF(Document, __uuidof(Document));
_COM_SMARTPTR_TYPEDEF(Documents, __uuidof(Documents));
_COM_SMARTPTR_TYPEDEF(Container, __uuidof(Container));
_COM_SMARTPTR_TYPEDEF(Containers, __uuidof(Containers));
_COM_SMARTPTR_TYPEDEF(_User, __uuidof(_User));
_COM_SMARTPTR_TYPEDEF(_Group, __uuidof(_Group));
_COM_SMARTPTR_TYPEDEF(Field2, __uuidof(Field2));
_COM_SMARTPTR_TYPEDEF(_DBEngine, __uuidof(_DBEngine));
_COM_SMARTPTR_TYPEDEF(Workspaces, __uuidof(Workspaces));
_COM_SMARTPTR_TYPEDEF(Workspace, __uuidof(Workspace));
_COM_SMARTPTR_TYPEDEF(Databases, __uuidof(Databases));
_COM_SMARTPTR_TYPEDEF(Database, __uuidof(Database));
_COM_SMARTPTR_TYPEDEF(_TableDef, __uuidof(_TableDef));
_COM_SMARTPTR_TYPEDEF(Recordset, __uuidof(Recordset));
_COM_SMARTPTR_TYPEDEF(_QueryDef, __uuidof(_QueryDef));
_COM_SMARTPTR_TYPEDEF(Recordsets, __uuidof(Recordsets));
_COM_SMARTPTR_TYPEDEF(Connection, __uuidof(Connection));
_COM_SMARTPTR_TYPEDEF(Connections, __uuidof(Connections));
_COM_SMARTPTR_TYPEDEF(Recordset2, __uuidof(Recordset2));

//
// Type library items
//

enum __declspec(uuid("b6ce0046-20c3-340f-985c-3559e85dc5e1"))
RecordsetTypeEnum
{
    dbOpenTable = 1,
    dbOpenDynaset = 2,
    dbOpenSnapshot = 4,
    dbOpenForwardOnly = 8,
    dbOpenDynamic = 16
};

enum __declspec(uuid("5ebef31f-3496-3c51-9e36-c66df55584d7"))
EditModeEnum
{
    dbEditNone = 0,
    dbEditInProgress = 1,
    dbEditAdd = 2
};

enum __declspec(uuid("86dbaf96-c3be-3773-a5e6-97eb2f1749f4"))
RecordsetOptionEnum
{
    dbDenyWrite = 1,
    dbDenyRead = 2,
    dbReadOnly = 4,
    dbAppendOnly = 8,
    dbInconsistent = 16,
    dbConsistent = 32,
    dbSQLPassThrough = 64,
    dbFailOnError = 128,
    dbForwardOnly = 256,
    dbSeeChanges = 512,
    dbRunAsync = 1024,
    dbExecDirect = 2048
};

enum __declspec(uuid("d5662dfd-b471-3e11-865d-f0177e687e3d"))
LockTypeEnum
{
    dbPessimistic = 2,
    dbOptimistic = 3,
    dbOptimisticValue = 1,
    dbOptimisticBatch = 5
};

enum __declspec(uuid("76903150-be34-3fc0-a76f-5d6eea439388"))
UpdateCriteriaEnum
{
    dbCriteriaKey = 1,
    dbCriteriaModValues = 2,
    dbCriteriaAllCols = 4,
    dbCriteriaTimestamp = 8,
    dbCriteriaDeleteInsert = 16,
    dbCriteriaUpdate = 32
};

enum __declspec(uuid("0699599d-a8a7-32ec-9b88-690482209ba5"))
FieldAttributeEnum
{
    dbFixedField = 1,
    dbVariableField = 2,
    dbAutoIncrField = 16,
    dbUpdatableField = 32,
    dbSystemField = 8192,
    dbHyperlinkField = 32768,
    dbDescending = 1
};

enum __declspec(uuid("a692012e-5124-3b74-8929-14ecb6aa5d57"))
DataTypeEnum
{
    dbBoolean = 1,
    dbByte = 2,
    dbInteger = 3,
    dbLong = 4,
    dbCurrency = 5,
    dbSingle = 6,
    dbDouble = 7,
    dbDate = 8,
    dbBinary = 9,
    dbText = 10,
    dbLongBinary = 11,
    dbMemo = 12,
    dbGUID = 15,
    dbBigInt = 16,
    dbVarBinary = 17,
    dbChar = 18,
    dbNumeric = 19,
    dbDecimal = 20,
    dbFloat = 21,
    dbTime = 22,
    dbTimeStamp = 23,
    dbAttachment = 101,
    dbComplexByte = 102,
    dbComplexInteger = 103,
    dbComplexLong = 104,
    dbComplexSingle = 105,
    dbComplexDouble = 106,
    dbComplexGUID = 107,
    dbComplexDecimal = 108,
    dbComplexText = 109
};

enum __declspec(uuid("e9e3cb7c-052b-3808-a4a1-1ddb096de50c"))
RelationAttributeEnum
{
    dbRelationUnique = 1,
    dbRelationDontEnforce = 2,
    dbRelationInherited = 4,
    dbRelationUpdateCascade = 256,
    dbRelationDeleteCascade = 4096,
    dbRelationLeft = 16777216,
    dbRelationRight = 33554432
};

enum __declspec(uuid("42ea269e-1b51-38ce-9eba-78f23f4d8fdd"))
TableDefAttributeEnum
{
    dbAttachExclusive = 65536,
    dbAttachSavePWD = 131072,
    dbSystemObject = -2147483646,
    dbAttachedTable = 1073741824,
    dbAttachedODBC = 536870912,
    dbHiddenObject = 1
};

enum __declspec(uuid("a9be12a3-d3a1-3306-b4c3-73dc51cb7503"))
QueryDefTypeEnum
{
    dbQSelect = 0,
    dbQProcedure = 224,
    dbQAction = 240,
    dbQCrosstab = 16,
    dbQDelete = 32,
    dbQUpdate = 48,
    dbQAppend = 64,
    dbQMakeTable = 80,
    dbQDDL = 96,
    dbQSQLPassThrough = 112,
    dbQSetOperation = 128,
    dbQSPTBulk = 144,
    dbQCompound = 160
};

enum __declspec(uuid("aca374f6-9ca0-36fc-b36d-f90ff0e8683f"))
QueryDefStateEnum
{
    dbQPrepare = 1,
    dbQUnprepare = 2
};

enum __declspec(uuid("57cd4321-2aec-3a3a-b673-e9542ed0c9a3"))
DatabaseTypeEnum
{
    dbVersion10 = 1,
    dbEncrypt = 2,
    dbDecrypt = 4,
    dbVersion11 = 8,
    dbVersion20 = 16,
    dbVersion30 = 32,
    dbVersion40 = 64,
    dbVersion120 = 128,
    dbVersion140 = 256
};

enum __declspec(uuid("c5bc1285-0a45-3c8c-8514-84979cfd0139"))
CollatingOrderEnum
{
    dbSortNeutral = 1024,
    dbSortArabic = 1025,
    dbSortCyrillic = 1049,
    dbSortCzech = 1029,
    dbSortDutch = 1043,
    dbSortGeneral = 1033,
    dbSortGreek = 1032,
    dbSortHebrew = 1037,
    dbSortHungarian = 1038,
    dbSortIcelandic = 1039,
    dbSortNorwdan = 1030,
    dbSortPDXIntl = 1033,
    dbSortPDXNor = 1030,
    dbSortPDXSwe = 1053,
    dbSortPolish = 1045,
    dbSortSpanish = 1034,
    dbSortSwedFin = 1053,
    dbSortTurkish = 1055,
    dbSortJapanese = 1041,
    dbSortChineseSimplified = 2052,
    dbSortChineseTraditional = 1028,
    dbSortKorean = 1042,
    dbSortThai = 1054,
    dbSortSlovenian = 1060,
    dbSortJapaneseRadicalStrokeCount = 263185,
    dbSortHindi = 1081,
    dbSortUndefined = -1
};

enum __declspec(uuid("191f6c41-7ae0-3fae-a6fc-b51be325c767"))
IdleEnum
{
    dbFreeLocks = 1,
    dbRefreshCache = 8
};

enum __declspec(uuid("2ef8e039-f0c8-3a24-b0c7-f151d7f584e5"))
PermissionEnum
{
    dbSecNoAccess = 0,
    dbSecFullAccess = 1048575,
    dbSecDelete = 65536,
    dbSecReadSec = 131072,
    dbSecWriteSec = 262144,
    dbSecWriteOwner = 524288,
    dbSecDBCreate = 1,
    dbSecDBOpen = 2,
    dbSecDBExclusive = 4,
    dbSecDBAdmin = 8,
    dbSecCreate = 1,
    dbSecReadDef = 4,
    dbSecWriteDef = 65548,
    dbSecRetrieveData = 20,
    dbSecInsertData = 32,
    dbSecReplaceData = 64,
    dbSecDeleteData = 128
};

enum __declspec(uuid("91de8e14-dee2-3ac6-bb31-415ee24effc9"))
SynchronizeTypeEnum
{
    dbRepExportChanges = 1,
    dbRepImportChanges = 2,
    dbRepImpExpChanges = 4,
    dbRepSyncInternet = 16
};

enum __declspec(uuid("7ad902d0-2c9f-3a6b-a1b6-a242d1206be9"))
ReplicaTypeEnum
{
    dbRepMakeReadOnly = 2,
    dbRepMakePartial = 1
};

enum __declspec(uuid("04465b7d-fd0c-38df-8ba5-6dae7b103dc9"))
WorkspaceTypeEnum
{
    dbUseODBC = 1,
    dbUseJet = 2
};

enum __declspec(uuid("d81a5990-6f34-3189-9f1d-1d503f601aed"))
CursorDriverEnum
{
    dbUseDefaultCursor = -1,
    dbUseODBCCursor = 1,
    dbUseServerCursor = 2,
    dbUseClientBatchCursor = 3,
    dbUseNoCursor = 4
};

enum __declspec(uuid("b8526372-3e87-3232-b6b5-3e5b10e11239"))
DriverPromptEnum
{
    dbDriverPrompt = 2,
    dbDriverNoPrompt = 1,
    dbDriverComplete = 0,
    dbDriverCompleteRequired = 3
};

enum __declspec(uuid("32e7bbc7-c15f-38f5-a17f-a073e51c1db3"))
SetOptionEnum
{
    dbPageTimeout = 6,
    dbLockRetry = 57,
    dbMaxBufferSize = 8,
    dbUserCommitSync = 58,
    dbImplicitCommitSync = 59,
    dbExclusiveAsyncDelay = 60,
    dbSharedAsyncDelay = 61,
    dbMaxLocksPerFile = 62,
    dbLockDelay = 63,
    dbRecycleLVs = 65,
    dbFlushTransactionTimeout = 66,
    dbPasswordEncryptionProvider = 80,
    dbPasswordEncryptionAlgorithm = 81,
    dbPasswordEncryptionKeyLength = 82
};

enum __declspec(uuid("70e6bc1d-51e5-389e-a24e-9ac51a17ea35"))
ParameterDirectionEnum
{
    dbParamInput = 1,
    dbParamOutput = 2,
    dbParamInputOutput = 3,
    dbParamReturnValue = 4
};

enum __declspec(uuid("384d0656-2a34-36fc-ac92-f2fb3072d0f8"))
UpdateTypeEnum
{
    dbUpdateBatch = 4,
    dbUpdateRegular = 1,
    dbUpdateCurrentRecord = 2
};

enum __declspec(uuid("9bc090b2-682f-3cee-ada0-09759acde44d"))
RecordStatusEnum
{
    dbRecordUnmodified = 0,
    dbRecordModified = 1,
    dbRecordNew = 2,
    dbRecordDeleted = 3,
    dbRecordDBDeleted = 4
};

enum __declspec(uuid("ab46cb4a-d340-3172-b681-3204abca661f"))
CommitTransOptionsEnum
{
    dbForceOSFlush = 1
};

enum __declspec(uuid("c8d258d0-9239-3c8d-a2f1-f483968220f6"))
_DAOSuppHelp
{
    LogMessages = 0,
    KeepLocal = 0,
    Replicable = 0,
    ReplicableBool = 0,
    V1xNullBehavior = 0
};
    const LPSTR dbLangArabic = (char*) ";LANGID=0x0401;CP=1256;COUNTRY=0";
    const LPSTR dbLangCzech = (char*) ";LANGID=0x0405;CP=1250;COUNTRY=0";
    const LPSTR dbLangDutch = (char*) ";LANGID=0x0413;CP=1252;COUNTRY=0";
    const LPSTR dbLangGeneral = (char*) ";LANGID=0x0409;CP=1252;COUNTRY=0";
    const LPSTR dbLangGreek = (char*) ";LANGID=0x0408;CP=1253;COUNTRY=0";
    const LPSTR dbLangHebrew = (char*) ";LANGID=0x040D;CP=1255;COUNTRY=0";
    const LPSTR dbLangHungarian = (char*) ";LANGID=0x040E;CP=1250;COUNTRY=0";
    const LPSTR dbLangIcelandic = (char*) ";LANGID=0x040F;CP=1252;COUNTRY=0";
    const LPSTR dbLangNordic = (char*) ";LANGID=0x041D;CP=1252;COUNTRY=0";
    const LPSTR dbLangNorwDan = (char*) ";LANGID=0x0406;CP=1252;COUNTRY=0";
    const LPSTR dbLangPolish = (char*) ";LANGID=0x0415;CP=1250;COUNTRY=0";
    const LPSTR dbLangCyrillic = (char*) ";LANGID=0x0419;CP=1251;COUNTRY=0";
    const LPSTR dbLangSpanish = (char*) ";LANGID=0x040A;CP=1252;COUNTRY=0";
    const LPSTR dbLangSwedFin = (char*) ";LANGID=0x041D;CP=1252;COUNTRY=0";
    const LPSTR dbLangTurkish = (char*) ";LANGID=0x041F;CP=1254;COUNTRY=0";
    const LPSTR dbLangJapanese = (char*) ";LANGID=0x0411;CP=932;COUNTRY=0";
    const LPSTR dbLangChineseSimplified = (char*) ";LANGID=0x0804;CP=936;COUNTRY=0";
    const LPSTR dbLangChineseTraditional = (char*) ";LANGID=0x0404;CP=950;COUNTRY=0";
    const LPSTR dbLangKorean = (char*) ";LANGID=0x0412;CP=949;COUNTRY=0";
    const LPSTR dbLangThai = (char*) ";LANGID=0x041E;CP=874;COUNTRY=0";
    const LPSTR dbLangSlovenian = (char*) ";LANGID=0x0424;CP=1250;COUNTRY=0";
    const LPSTR dbLangJapaneseRadicalStrokeCount = (char*) ";LANGID=0x00040411;CP=65001;COUNTRY=0";
    const LPSTR dbLangHindi = (char*) ";LANGID=0x00000439;CP=65001;COUNTRY=0";

struct __declspec(uuid("000000a0-0000-0010-8000-00aa006d2ea4"))
_Collection : IDispatch
{
    //
    // Raw methods provided by interface
    //

      virtual HRESULT __stdcall get_Count (
        /*[out,retval]*/ short * c ) = 0;
      virtual HRESULT __stdcall _NewEnum (
        /*[out,retval]*/ IUnknown * * ppunk ) = 0;
      virtual HRESULT __stdcall Refresh ( ) = 0;
};

struct __declspec(uuid("000000a2-0000-0010-8000-00aa006d2ea4"))
_DynaCollection : _Collection
{
    //
    // Raw methods provided by interface
    //

      virtual HRESULT __stdcall Append (
        /*[in]*/ IDispatch * Object ) = 0;
      virtual HRESULT __stdcall Delete (
        /*[in]*/ BSTR Name ) = 0;
};

struct __declspec(uuid("367e582c-f71c-4bf9-aa1b-9f62b793e9c5"))
TableDef;
    // [ default ] interface _TableDef

struct __declspec(uuid("0000004b-0000-0010-8000-00aa006d2ea4"))
TableDefs : _DynaCollection
{
    //
    // Raw methods provided by interface
    //

      virtual HRESULT __stdcall get_Item (
        /*[in]*/ VARIANT Item,
        /*[out,retval]*/ struct _TableDef * * pptdf ) = 0;
};

struct __declspec(uuid("a1eb89d6-0a9c-4575-a0ae-654a990a454c"))
Field;
    // [ default ] interface _Field

struct __declspec(uuid("00000053-0000-0010-8000-00aa006d2ea4"))
Fields : _DynaCollection
{
    //
    // Raw methods provided by interface
    //

      virtual HRESULT __stdcall get_Item (
        /*[in]*/ VARIANT Item,
        /*[out,retval]*/ struct _Field * * ppfld ) = 0;
};

struct __declspec(uuid("8d4f994c-ebbe-4f8d-ba4b-ae20cd36e72d"))
Index;
    // [ default ] interface _Index

struct __declspec(uuid("0000005b-0000-0010-8000-00aa006d2ea4"))
Indexes : _DynaCollection
{
    //
    // Raw methods provided by interface
    //

      virtual HRESULT __stdcall get_Item (
        /*[in]*/ VARIANT Item,
        /*[out,retval]*/ struct _Index * * ppidx ) = 0;
};

struct __declspec(uuid("d5ec4d34-77da-4f7a-b8c4-8a910c1c1cfe"))
QueryDef;
    // [ default ] interface _QueryDef

struct __declspec(uuid("0000007b-0000-0010-8000-00aa006d2ea4"))
QueryDefs : _DynaCollection
{
    //
    // Raw methods provided by interface
    //

      virtual HRESULT __stdcall get_Item (
        /*[in]*/ VARIANT Item,
        /*[out,retval]*/ struct _QueryDef * * ppqdef ) = 0;
};

struct __declspec(uuid("d0b22d03-d05d-4c6d-8ab7-9392e84a87b9"))
Relation;
    // [ default ] interface _Relation

struct __declspec(uuid("0000008b-0000-0010-8000-00aa006d2ea4"))
Relations : _DynaCollection
{
    //
    // Raw methods provided by interface
    //

      virtual HRESULT __stdcall get_Item (
        /*[in]*/ VARIANT Item,
        /*[out,retval]*/ struct _Relation * * pprel ) = 0;
};

struct __declspec(uuid("805b7f91-c9cf-4edf-aca6-775664fdfb3e"))
User;
    // [ default ] interface _User

struct __declspec(uuid("0000006b-0000-0010-8000-00aa006d2ea4"))
Users : _DynaCollection
{
    //
    // Raw methods provided by interface
    //

      virtual HRESULT __stdcall get_Item (
        /*[in]*/ VARIANT Item,
        /*[out,retval]*/ struct _User * * ppusr ) = 0;
};

struct __declspec(uuid("97a2762c-403c-4953-a121-7a75abce4373"))
Group;
    // [ default ] interface _Group

struct __declspec(uuid("00000063-0000-0010-8000-00aa006d2ea4"))
Groups : _DynaCollection
{
    //
    // Raw methods provided by interface
    //

      virtual HRESULT __stdcall get_Item (
        /*[in]*/ VARIANT Item,
        /*[out,retval]*/ struct _Group * * ppgrp ) = 0;
};

struct __declspec(uuid("00000023-0000-0010-8000-00aa006d2ea4"))
Error : IDispatch
{
    //
    // Raw methods provided by interface
    //

      virtual HRESULT __stdcall get_Number (
        /*[out,retval]*/ long * pl ) = 0;
      virtual HRESULT __stdcall get_Source (
        /*[out,retval]*/ BSTR * pbstr ) = 0;
      virtual HRESULT __stdcall get_Description (
        /*[out,retval]*/ BSTR * pbstr ) = 0;
      virtual HRESULT __stdcall get_HelpFile (
        /*[out,retval]*/ BSTR * pbstr ) = 0;
      virtual HRESULT __stdcall get_HelpContext (
        /*[out,retval]*/ long * pl ) = 0;
};

struct __declspec(uuid("00000025-0000-0010-8000-00aa006d2ea4"))
Errors : _Collection
{
    //
    // Raw methods provided by interface
    //

      virtual HRESULT __stdcall get_Item (
        /*[in]*/ VARIANT Item,
        /*[out,retval]*/ struct Error * * pperr ) = 0;
};

struct __declspec(uuid("0000009d-0000-0010-8000-00aa006d2ea4"))
ComplexType : IDispatch
{
    //
    // Raw methods provided by interface
    //

      virtual HRESULT __stdcall get_Fields (
        /*[out,retval]*/ struct Fields * * ppflds ) = 0;
};

struct __declspec(uuid("cd7791b9-43fd-42c5-ae42-8dd2811f0419"))
DBEngine;
    // [ default ] interface _DBEngine

struct __declspec(uuid("6f3dd387-5af2-492b-bde2-30ff2f451241"))
PrivDBEngine;
    // [ default ] interface _DBEngine

struct __declspec(uuid("0000005d-0000-0010-8000-00aa006d2ea4"))
IndexFields : _DynaCollection
{
    //
    // Raw methods provided by interface
    //

      virtual HRESULT __stdcall get_Item (
        /*[in]*/ VARIANT Item,
        /*[out,retval]*/ VARIANT * pvar ) = 0;
};

struct __declspec(uuid("0000000a-0000-0010-8000-00aa006d2ea4"))
_DAO : IDispatch
{
    //
    // Raw methods provided by interface
    //

      virtual HRESULT __stdcall get_Properties (
        /*[out,retval]*/ struct Properties * * ppprops ) = 0;
};

struct __declspec(uuid("00000027-0000-0010-8000-00aa006d2ea4"))
Property : _DAO
{
    //
    // Raw methods provided by interface
    //

      virtual HRESULT __stdcall get_Value (
        /*[out,retval]*/ VARIANT * pval ) = 0;
      virtual HRESULT __stdcall put_Value (
        /*[in]*/ VARIANT pval ) = 0;
      virtual HRESULT __stdcall get_Name (
        /*[out,retval]*/ BSTR * pbstr ) = 0;
      virtual HRESULT __stdcall put_Name (
        /*[in]*/ BSTR pbstr ) = 0;
      virtual HRESULT __stdcall get_Type (
        /*[out,retval]*/ short * ptype ) = 0;
      virtual HRESULT __stdcall put_Type (
        /*[in]*/ short ptype ) = 0;
      virtual HRESULT __stdcall get_Inherited (
        /*[out,retval]*/ VARIANT_BOOL * pb ) = 0;
};

struct __declspec(uuid("00000029-0000-0010-8000-00aa006d2ea4"))
Properties : _DynaCollection
{
    //
    // Raw methods provided by interface
    //

      virtual HRESULT __stdcall get_Item (
        /*[in]*/ VARIANT Item,
        /*[out,retval]*/ struct Property * * ppprop ) = 0;
};

struct __declspec(uuid("00000051-0000-0010-8000-00aa006d2ea4"))
_Field : _DAO
{
    //
    // Raw methods provided by interface
    //

      virtual HRESULT __stdcall get_CollatingOrder (
        /*[out,retval]*/ long * pl ) = 0;
      virtual HRESULT __stdcall get_Type (
        /*[out,retval]*/ short * ps ) = 0;
      virtual HRESULT __stdcall put_Type (
        /*[in]*/ short ps ) = 0;
      virtual HRESULT __stdcall get_Name (
        /*[out,retval]*/ BSTR * pbstr ) = 0;
      virtual HRESULT __stdcall put_Name (
        /*[in]*/ BSTR pbstr ) = 0;
      virtual HRESULT __stdcall get_Size (
        /*[out,retval]*/ long * pl ) = 0;
      virtual HRESULT __stdcall put_Size (
        /*[in]*/ long pl ) = 0;
      virtual HRESULT __stdcall get_SourceField (
        /*[out,retval]*/ BSTR * pbstr ) = 0;
      virtual HRESULT __stdcall get_SourceTable (
        /*[out,retval]*/ BSTR * pbstr ) = 0;
      virtual HRESULT __stdcall get_Value (
        /*[out,retval]*/ VARIANT * pvar ) = 0;
      virtual HRESULT __stdcall put_Value (
        /*[in]*/ VARIANT pvar ) = 0;
      virtual HRESULT __stdcall get_Attributes (
        /*[out,retval]*/ long * pl ) = 0;
      virtual HRESULT __stdcall put_Attributes (
        /*[in]*/ long pl ) = 0;
      virtual HRESULT __stdcall get_OrdinalPosition (
        /*[out,retval]*/ short * ps ) = 0;
      virtual HRESULT __stdcall put_OrdinalPosition (
        /*[in]*/ short ps ) = 0;
      virtual HRESULT __stdcall get_ValidationText (
        /*[out,retval]*/ BSTR * pbstr ) = 0;
      virtual HRESULT __stdcall put_ValidationText (
        /*[in]*/ BSTR pbstr ) = 0;
      virtual HRESULT __stdcall get_ValidateOnSet (
        /*[out,retval]*/ VARIANT_BOOL * pb ) = 0;
      virtual HRESULT __stdcall put_ValidateOnSet (
        /*[in]*/ VARIANT_BOOL pb ) = 0;
      virtual HRESULT __stdcall get_ValidationRule (
        /*[out,retval]*/ BSTR * pbstr ) = 0;
      virtual HRESULT __stdcall put_ValidationRule (
        /*[in]*/ BSTR pbstr ) = 0;
      virtual HRESULT __stdcall get_DefaultValue (
        /*[out,retval]*/ VARIANT * pvar ) = 0;
      virtual HRESULT __stdcall put_DefaultValue (
        /*[in]*/ VARIANT pvar ) = 0;
      virtual HRESULT __stdcall get_Required (
        /*[out,retval]*/ VARIANT_BOOL * pb ) = 0;
      virtual HRESULT __stdcall put_Required (
        /*[in]*/ VARIANT_BOOL pb ) = 0;
      virtual HRESULT __stdcall get_AllowZeroLength (
        /*[out,retval]*/ VARIANT_BOOL * pb ) = 0;
      virtual HRESULT __stdcall put_AllowZeroLength (
        /*[in]*/ VARIANT_BOOL pb ) = 0;
      virtual HRESULT __stdcall get_DataUpdatable (
        /*[out,retval]*/ VARIANT_BOOL * pb ) = 0;
      virtual HRESULT __stdcall get_ForeignName (
        /*[out,retval]*/ BSTR * pbstr ) = 0;
      virtual HRESULT __stdcall put_ForeignName (
        /*[in]*/ BSTR pbstr ) = 0;
      virtual HRESULT __stdcall AppendChunk (
        /*[in]*/ VARIANT Val ) = 0;
      virtual HRESULT __stdcall GetChunk (
        /*[in]*/ long Offset,
        /*[in]*/ long Bytes,
        /*[out,retval]*/ VARIANT * pvar ) = 0;
      virtual HRESULT __stdcall _30_FieldSize (
        /*[out,retval]*/ long * pl ) = 0;
      virtual HRESULT __stdcall CreateProperty (
        /*[in]*/ VARIANT Name,
        /*[in]*/ VARIANT Type,
        /*[in]*/ VARIANT Value,
        /*[in]*/ VARIANT DDL,
        /*[out,retval]*/ struct Property * * pprp ) = 0;
      virtual HRESULT __stdcall get_CollectionIndex (
        /*[out,retval]*/ short * i ) = 0;
      virtual HRESULT __stdcall get_OriginalValue (
        /*[out,retval]*/ VARIANT * pvar ) = 0;
      virtual HRESULT __stdcall get_VisibleValue (
        /*[out,retval]*/ VARIANT * pvar ) = 0;
      virtual HRESULT __stdcall get_FieldSize (
        /*[out,retval]*/ long * pl ) = 0;
};

struct __declspec(uuid("00000059-0000-0010-8000-00aa006d2ea4"))
_Index : _DAO
{
    //
    // Raw methods provided by interface
    //

      virtual HRESULT __stdcall get_Name (
        /*[out,retval]*/ BSTR * pbstr ) = 0;
      virtual HRESULT __stdcall put_Name (
        /*[in]*/ BSTR pbstr ) = 0;
      virtual HRESULT __stdcall get_Foreign (
        /*[out,retval]*/ VARIANT_BOOL * pb ) = 0;
      virtual HRESULT __stdcall get_Unique (
        /*[out,retval]*/ VARIANT_BOOL * pb ) = 0;
      virtual HRESULT __stdcall put_Unique (
        /*[in]*/ VARIANT_BOOL pb ) = 0;
      virtual HRESULT __stdcall get_Clustered (
        /*[out,retval]*/ VARIANT_BOOL * pb ) = 0;
      virtual HRESULT __stdcall put_Clustered (
        /*[in]*/ VARIANT_BOOL pb ) = 0;
      virtual HRESULT __stdcall get_Required (
        /*[out,retval]*/ VARIANT_BOOL * pb ) = 0;
      virtual HRESULT __stdcall put_Required (
        /*[in]*/ VARIANT_BOOL pb ) = 0;
      virtual HRESULT __stdcall get_IgnoreNulls (
        /*[out,retval]*/ VARIANT_BOOL * pb ) = 0;
      virtual HRESULT __stdcall put_IgnoreNulls (
        /*[in]*/ VARIANT_BOOL pb ) = 0;
      virtual HRESULT __stdcall get_Primary (
        /*[out,retval]*/ VARIANT_BOOL * pb ) = 0;
      virtual HRESULT __stdcall put_Primary (
        /*[in]*/ VARIANT_BOOL pb ) = 0;
      virtual HRESULT __stdcall get_DistinctCount (
        /*[out,retval]*/ long * pl ) = 0;
      virtual HRESULT __stdcall get_Fields (
        /*[out,retval]*/ VARIANT * pv ) = 0;
      virtual HRESULT __stdcall put_Fields (
        /*[in]*/ VARIANT pv ) = 0;
      virtual HRESULT __stdcall CreateField (
        /*[in]*/ VARIANT Name,
        /*[in]*/ VARIANT Type,
        /*[in]*/ VARIANT Size,
        /*[out,retval]*/ struct _Field * * ppfld ) = 0;
      virtual HRESULT __stdcall CreateProperty (
        /*[in]*/ VARIANT Name,
        /*[in]*/ VARIANT Type,
        /*[in]*/ VARIANT Value,
        /*[in]*/ VARIANT DDL,
        /*[out,retval]*/ struct Property * * pprp ) = 0;
};

struct __declspec(uuid("00000081-0000-0010-8000-00aa006d2ea4"))
Parameter : _DAO
{
    //
    // Raw methods provided by interface
    //

      virtual HRESULT __stdcall get_Name (
        /*[out,retval]*/ BSTR * pbstr ) = 0;
      virtual HRESULT __stdcall get_Value (
        /*[out,retval]*/ VARIANT * pvar ) = 0;
      virtual HRESULT __stdcall put_Value (
        /*[in]*/ VARIANT pvar ) = 0;
      virtual HRESULT __stdcall get_Type (
        /*[out,retval]*/ short * ps ) = 0;
      virtual HRESULT __stdcall put_Type (
        /*[in]*/ short ps ) = 0;
      virtual HRESULT __stdcall get_Direction (
        /*[out,retval]*/ short * pOption ) = 0;
      virtual HRESULT __stdcall put_Direction (
        /*[in]*/ short pOption ) = 0;
};

struct __declspec(uuid("00000083-0000-0010-8000-00aa006d2ea4"))
Parameters : _Collection
{
    //
    // Raw methods provided by interface
    //

      virtual HRESULT __stdcall get_Item (
        /*[in]*/ VARIANT Item,
        /*[out,retval]*/ struct Parameter * * ppprm ) = 0;
};

struct __declspec(uuid("00000089-0000-0010-8000-00aa006d2ea4"))
_Relation : _DAO
{
    //
    // Raw methods provided by interface
    //

      virtual HRESULT __stdcall get_Name (
        /*[out,retval]*/ BSTR * pbstr ) = 0;
      virtual HRESULT __stdcall put_Name (
        /*[in]*/ BSTR pbstr ) = 0;
      virtual HRESULT __stdcall get_Table (
        /*[out,retval]*/ BSTR * pbstr ) = 0;
      virtual HRESULT __stdcall put_Table (
        /*[in]*/ BSTR pbstr ) = 0;
      virtual HRESULT __stdcall get_ForeignTable (
        /*[out,retval]*/ BSTR * pbstr ) = 0;
      virtual HRESULT __stdcall put_ForeignTable (
        /*[in]*/ BSTR pbstr ) = 0;
      virtual HRESULT __stdcall get_Attributes (
        /*[out,retval]*/ long * pl ) = 0;
      virtual HRESULT __stdcall put_Attributes (
        /*[in]*/ long pl ) = 0;
      virtual HRESULT __stdcall get_Fields (
        /*[out,retval]*/ struct Fields * * ppflds ) = 0;
      virtual HRESULT __stdcall CreateField (
        /*[in]*/ VARIANT Name,
        /*[in]*/ VARIANT Type,
        /*[in]*/ VARIANT Size,
        /*[out,retval]*/ struct _Field * * ppfld ) = 0;
      virtual HRESULT __stdcall get_PartialReplica (
        /*[out,retval]*/ VARIANT_BOOL * pfPartialReplica ) = 0;
      virtual HRESULT __stdcall put_PartialReplica (
        /*[in]*/ VARIANT_BOOL pfPartialReplica ) = 0;
};

struct __declspec(uuid("00000099-0000-0010-8000-00aa006d2ea4"))
Document : _DAO
{
    //
    // Raw methods provided by interface
    //

      virtual HRESULT __stdcall get_Name (
        /*[out,retval]*/ BSTR * pbstr ) = 0;
      virtual HRESULT __stdcall get_Owner (
        /*[out,retval]*/ BSTR * pbstr ) = 0;
      virtual HRESULT __stdcall put_Owner (
        /*[in]*/ BSTR pbstr ) = 0;
      virtual HRESULT __stdcall get_Container (
        /*[out,retval]*/ BSTR * pbstr ) = 0;
      virtual HRESULT __stdcall get_UserName (
        /*[out,retval]*/ BSTR * pbstr ) = 0;
      virtual HRESULT __stdcall put_UserName (
        /*[in]*/ BSTR pbstr ) = 0;
      virtual HRESULT __stdcall get_Permissions (
        /*[out,retval]*/ long * pl ) = 0;
      virtual HRESULT __stdcall put_Permissions (
        /*[in]*/ long pl ) = 0;
      virtual HRESULT __stdcall get_DateCreated (
        /*[out,retval]*/ VARIANT * pvar ) = 0;
      virtual HRESULT __stdcall get_LastUpdated (
        /*[out,retval]*/ VARIANT * pvar ) = 0;
      virtual HRESULT __stdcall get_AllPermissions (
        /*[out,retval]*/ long * pl ) = 0;
      virtual HRESULT __stdcall CreateProperty (
        /*[in]*/ VARIANT Name,
        /*[in]*/ VARIANT Type,
        /*[in]*/ VARIANT Value,
        /*[in]*/ VARIANT DDL,
        /*[out,retval]*/ struct Property * * pprp ) = 0;
};

struct __declspec(uuid("0000009b-0000-0010-8000-00aa006d2ea4"))
Documents : _Collection
{
    //
    // Raw methods provided by interface
    //

      virtual HRESULT __stdcall get_Item (
        /*[in]*/ VARIANT Item,
        /*[out,retval]*/ struct Document * * ppdoc ) = 0;
};

struct __declspec(uuid("00000091-0000-0010-8000-00aa006d2ea4"))
Container : _DAO
{
    //
    // Raw methods provided by interface
    //

      virtual HRESULT __stdcall get_Name (
        /*[out,retval]*/ BSTR * pbstr ) = 0;
      virtual HRESULT __stdcall get_Owner (
        /*[out,retval]*/ BSTR * pbstr ) = 0;
      virtual HRESULT __stdcall put_Owner (
        /*[in]*/ BSTR pbstr ) = 0;
      virtual HRESULT __stdcall get_UserName (
        /*[out,retval]*/ BSTR * pbstr ) = 0;
      virtual HRESULT __stdcall put_UserName (
        /*[in]*/ BSTR pbstr ) = 0;
      virtual HRESULT __stdcall get_Permissions (
        /*[out,retval]*/ long * pl ) = 0;
      virtual HRESULT __stdcall put_Permissions (
        /*[in]*/ long pl ) = 0;
      virtual HRESULT __stdcall get_Inherit (
        /*[out,retval]*/ VARIANT_BOOL * pb ) = 0;
      virtual HRESULT __stdcall put_Inherit (
        /*[in]*/ VARIANT_BOOL pb ) = 0;
      virtual HRESULT __stdcall get_Documents (
        /*[out,retval]*/ struct Documents * * ppdocs ) = 0;
      virtual HRESULT __stdcall get_AllPermissions (
        /*[out,retval]*/ long * pl ) = 0;
};

struct __declspec(uuid("00000093-0000-0010-8000-00aa006d2ea4"))
Containers : _Collection
{
    //
    // Raw methods provided by interface
    //

      virtual HRESULT __stdcall get_Item (
        /*[in]*/ VARIANT Item,
        /*[out,retval]*/ struct Container * * ppctn ) = 0;
};

struct __declspec(uuid("00000069-0000-0010-8000-00aa006d2ea4"))
_User : _DAO
{
    //
    // Raw methods provided by interface
    //

      virtual HRESULT __stdcall get_Name (
        /*[out,retval]*/ BSTR * pbstr ) = 0;
      virtual HRESULT __stdcall put_Name (
        /*[in]*/ BSTR pbstr ) = 0;
      virtual HRESULT __stdcall put_PID (
        /*[in]*/ BSTR _arg1 ) = 0;
      virtual HRESULT __stdcall put_Password (
        /*[in]*/ BSTR _arg1 ) = 0;
      virtual HRESULT __stdcall get_Groups (
        /*[out,retval]*/ struct Groups * * ppgrps ) = 0;
      virtual HRESULT __stdcall NewPassword (
        /*[in]*/ BSTR bstrOld,
        /*[in]*/ BSTR bstrNew ) = 0;
      virtual HRESULT __stdcall CreateGroup (
        /*[in]*/ VARIANT Name,
        /*[in]*/ VARIANT PID,
        /*[out,retval]*/ struct _Group * * ppgrp ) = 0;
};

struct __declspec(uuid("00000061-0000-0010-8000-00aa006d2ea4"))
_Group : _DAO
{
    //
    // Raw methods provided by interface
    //

      virtual HRESULT __stdcall get_Name (
        /*[out,retval]*/ BSTR * pbstr ) = 0;
      virtual HRESULT __stdcall put_Name (
        /*[in]*/ BSTR pbstr ) = 0;
      virtual HRESULT __stdcall put_PID (
        /*[in]*/ BSTR _arg1 ) = 0;
      virtual HRESULT __stdcall get_Users (
        /*[out,retval]*/ struct Users * * ppusrs ) = 0;
      virtual HRESULT __stdcall CreateUser (
        /*[in]*/ VARIANT Name,
        /*[in]*/ VARIANT PID,
        /*[in]*/ VARIANT Password,
        /*[out,retval]*/ struct _User * * ppusr ) = 0;
};

struct __declspec(uuid("00000054-0000-0010-8000-00aa006d2ea4"))
Field2 : _Field
{
    //
    // Raw methods provided by interface
    //

      virtual HRESULT __stdcall get_ComplexType (
        /*[out,retval]*/ struct ComplexType * * ppComplexType ) = 0;
      virtual HRESULT __stdcall LoadFromFile (
        /*[in]*/ BSTR FileName ) = 0;
      virtual HRESULT __stdcall SaveToFile (
        /*[in]*/ BSTR FileName ) = 0;
      virtual HRESULT __stdcall get_IsComplex (
        /*[out,retval]*/ VARIANT_BOOL * pb ) = 0;
      virtual HRESULT __stdcall get_AppendOnly (
        /*[out,retval]*/ VARIANT_BOOL * pb ) = 0;
      virtual HRESULT __stdcall put_AppendOnly (
        /*[in]*/ VARIANT_BOOL pb ) = 0;
      virtual HRESULT __stdcall get_Expression (
        /*[out,retval]*/ BSTR * pbstr ) = 0;
      virtual HRESULT __stdcall put_Expression (
        /*[in]*/ BSTR pbstr ) = 0;
};

struct __declspec(uuid("00000021-0000-0010-8000-00aa006d2ea4"))
_DBEngine : _DAO
{
    //
    // Raw methods provided by interface
    //

      virtual HRESULT __stdcall get_Version (
        /*[out,retval]*/ BSTR * pbstr ) = 0;
      virtual HRESULT __stdcall get_IniPath (
        /*[out,retval]*/ BSTR * pbstr ) = 0;
      virtual HRESULT __stdcall put_IniPath (
        /*[in]*/ BSTR pbstr ) = 0;
      virtual HRESULT __stdcall put_DefaultUser (
        /*[in]*/ BSTR _arg1 ) = 0;
      virtual HRESULT __stdcall put_DefaultPassword (
        /*[in]*/ BSTR _arg1 ) = 0;
      virtual HRESULT __stdcall get_LoginTimeout (
        /*[out,retval]*/ short * ps ) = 0;
      virtual HRESULT __stdcall put_LoginTimeout (
        /*[in]*/ short ps ) = 0;
      virtual HRESULT __stdcall get_Workspaces (
        /*[out,retval]*/ struct Workspaces * * ppworks ) = 0;
      virtual HRESULT __stdcall get_Errors (
        /*[out,retval]*/ struct Errors * * pperrs ) = 0;
      virtual HRESULT __stdcall Idle (
        /*[in]*/ VARIANT Action = vtMissing ) = 0;
      virtual HRESULT __stdcall CompactDatabase (
        /*[in]*/ BSTR SrcName,
        /*[in]*/ BSTR DstName,
        /*[in]*/ VARIANT DstLocale = vtMissing,
        /*[in]*/ VARIANT Options = vtMissing,
        /*[in]*/ VARIANT SrcLocale = vtMissing ) = 0;
      virtual HRESULT __stdcall RepairDatabase (
        /*[in]*/ BSTR Name ) = 0;
      virtual HRESULT __stdcall RegisterDatabase (
        /*[in]*/ BSTR Dsn,
        /*[in]*/ BSTR Driver,
        /*[in]*/ VARIANT_BOOL Silent,
        /*[in]*/ BSTR Attributes ) = 0;
      virtual HRESULT __stdcall _30_CreateWorkspace (
        /*[in]*/ BSTR Name,
        /*[in]*/ BSTR UserName,
        /*[in]*/ BSTR Password,
        /*[out,retval]*/ struct Workspace * * ppwrk ) = 0;
      virtual HRESULT __stdcall OpenDatabase (
        /*[in]*/ BSTR Name,
        /*[in]*/ VARIANT Options,
        /*[in]*/ VARIANT ReadOnly,
        /*[in]*/ VARIANT Connect,
        /*[out,retval]*/ struct Database * * ppDb ) = 0;
      virtual HRESULT __stdcall CreateDatabase (
        /*[in]*/ BSTR Name,
        /*[in]*/ BSTR Locale,
        /*[in]*/ VARIANT Option,
        /*[out,retval]*/ struct Database * * ppDb ) = 0;
      virtual HRESULT __stdcall FreeLocks ( ) = 0;
      virtual HRESULT __stdcall BeginTrans ( ) = 0;
      virtual HRESULT __stdcall CommitTrans (
        /*[in]*/ long Option ) = 0;
      virtual HRESULT __stdcall Rollback ( ) = 0;
      virtual HRESULT __stdcall SetDefaultWorkspace (
        /*[in]*/ BSTR Name,
        /*[in]*/ BSTR Password ) = 0;
      virtual HRESULT __stdcall SetDataAccessOption (
        /*[in]*/ short Option,
        /*[in]*/ VARIANT Value ) = 0;
      virtual HRESULT __stdcall ISAMStats (
        /*[in]*/ long StatNum,
        /*[in]*/ VARIANT Reset,
        /*[out,retval]*/ long * pl ) = 0;
      virtual HRESULT __stdcall get_SystemDB (
        /*[out,retval]*/ BSTR * pbstr ) = 0;
      virtual HRESULT __stdcall put_SystemDB (
        /*[in]*/ BSTR pbstr ) = 0;
      virtual HRESULT __stdcall CreateWorkspace (
        /*[in]*/ BSTR Name,
        /*[in]*/ BSTR UserName,
        /*[in]*/ BSTR Password,
        /*[in]*/ VARIANT UseType,
        /*[out,retval]*/ struct Workspace * * ppwrk ) = 0;
      virtual HRESULT __stdcall OpenConnection (
        /*[in]*/ BSTR Name,
        /*[in]*/ VARIANT Options,
        /*[in]*/ VARIANT ReadOnly,
        /*[in]*/ VARIANT Connect,
        /*[out,retval]*/ struct Connection * * ppconn ) = 0;
      virtual HRESULT __stdcall get_DefaultType (
        /*[out,retval]*/ long * Option ) = 0;
      virtual HRESULT __stdcall put_DefaultType (
        /*[in]*/ long Option ) = 0;
      virtual HRESULT __stdcall SetOption (
        /*[in]*/ long Option,
        /*[in]*/ VARIANT Value ) = 0;
};

struct __declspec(uuid("0000003b-0000-0010-8000-00aa006d2ea4"))
Workspaces : _DynaCollection
{
    //
    // Raw methods provided by interface
    //

      virtual HRESULT __stdcall get_Item (
        /*[in]*/ VARIANT Item,
        /*[out,retval]*/ struct Workspace * * ppwrk ) = 0;
};

struct __declspec(uuid("00000039-0000-0010-8000-00aa006d2ea4"))
Workspace : _DAO
{
    //
    // Raw methods provided by interface
    //

      virtual HRESULT __stdcall get_Name (
        /*[out,retval]*/ BSTR * pbstr ) = 0;
      virtual HRESULT __stdcall put_Name (
        /*[in]*/ BSTR pbstr ) = 0;
      virtual HRESULT __stdcall get_UserName (
        /*[out,retval]*/ BSTR * pbstr ) = 0;
      virtual HRESULT __stdcall put__30_UserName (
        /*[in]*/ BSTR _arg1 ) = 0;
      virtual HRESULT __stdcall put__30_Password (
        /*[in]*/ BSTR _arg1 ) = 0;
      virtual HRESULT __stdcall get_IsolateODBCTrans (
        /*[out,retval]*/ short * ps ) = 0;
      virtual HRESULT __stdcall put_IsolateODBCTrans (
        /*[in]*/ short ps ) = 0;
      virtual HRESULT __stdcall get_Databases (
        /*[out,retval]*/ struct Databases * * ppdbs ) = 0;
      virtual HRESULT __stdcall get_Users (
        /*[out,retval]*/ struct Users * * ppusrs ) = 0;
      virtual HRESULT __stdcall get_Groups (
        /*[out,retval]*/ struct Groups * * ppgrps ) = 0;
      virtual HRESULT __stdcall BeginTrans ( ) = 0;
      virtual HRESULT __stdcall CommitTrans (
        /*[in]*/ long Options ) = 0;
      virtual HRESULT __stdcall Close ( ) = 0;
      virtual HRESULT __stdcall Rollback ( ) = 0;
      virtual HRESULT __stdcall OpenDatabase (
        /*[in]*/ BSTR Name,
        /*[in]*/ VARIANT Options,
        /*[in]*/ VARIANT ReadOnly,
        /*[in]*/ VARIANT Connect,
        /*[out,retval]*/ struct Database * * ppDb ) = 0;
      virtual HRESULT __stdcall CreateDatabase (
        /*[in]*/ BSTR Name,
        /*[in]*/ BSTR Connect,
        /*[in]*/ VARIANT Option,
        /*[out,retval]*/ struct Database * * ppDb ) = 0;
      virtual HRESULT __stdcall CreateUser (
        /*[in]*/ VARIANT Name,
        /*[in]*/ VARIANT PID,
        /*[in]*/ VARIANT Password,
        /*[out,retval]*/ struct _User * * ppusr ) = 0;
      virtual HRESULT __stdcall CreateGroup (
        /*[in]*/ VARIANT Name,
        /*[in]*/ VARIANT PID,
        /*[out,retval]*/ struct _Group * * ppgrp ) = 0;
      virtual HRESULT __stdcall OpenConnection (
        /*[in]*/ BSTR Name,
        /*[in]*/ VARIANT Options,
        /*[in]*/ VARIANT ReadOnly,
        /*[in]*/ VARIANT Connect,
        /*[out,retval]*/ struct Connection * * ppconn ) = 0;
      virtual HRESULT __stdcall get_LoginTimeout (
        /*[out,retval]*/ long * pTimeout ) = 0;
      virtual HRESULT __stdcall put_LoginTimeout (
        /*[in]*/ long pTimeout ) = 0;
      virtual HRESULT __stdcall get_DefaultCursorDriver (
        /*[out,retval]*/ long * pCursorType ) = 0;
      virtual HRESULT __stdcall put_DefaultCursorDriver (
        /*[in]*/ long pCursorType ) = 0;
      virtual HRESULT __stdcall get_hEnv (
        /*[out,retval]*/ long * phEnv ) = 0;
      virtual HRESULT __stdcall get_Type (
        /*[out,retval]*/ long * ptype ) = 0;
      virtual HRESULT __stdcall get_Connections (
        /*[out,retval]*/ struct Connections * * ppcns ) = 0;
};

struct __declspec(uuid("00000073-0000-0010-8000-00aa006d2ea4"))
Databases : _Collection
{
    //
    // Raw methods provided by interface
    //

      virtual HRESULT __stdcall get_Item (
        /*[in]*/ VARIANT Item,
        /*[out,retval]*/ struct Database * * ppDb ) = 0;
};

struct __declspec(uuid("00000071-0000-0010-8000-00aa006d2ea4"))
Database : _DAO
{
    //
    // Raw methods provided by interface
    //

      virtual HRESULT __stdcall get_CollatingOrder (
        /*[out,retval]*/ long * pl ) = 0;
      virtual HRESULT __stdcall get_Connect (
        /*[out,retval]*/ BSTR * pbstr ) = 0;
      virtual HRESULT __stdcall get_Name (
        /*[out,retval]*/ BSTR * pbstr ) = 0;
      virtual HRESULT __stdcall get_QueryTimeout (
        /*[out,retval]*/ short * ps ) = 0;
      virtual HRESULT __stdcall put_QueryTimeout (
        /*[in]*/ short ps ) = 0;
      virtual HRESULT __stdcall get_Transactions (
        /*[out,retval]*/ VARIANT_BOOL * pb ) = 0;
      virtual HRESULT __stdcall get_Updatable (
        /*[out,retval]*/ VARIANT_BOOL * pb ) = 0;
      virtual HRESULT __stdcall get_Version (
        /*[out,retval]*/ BSTR * pbstr ) = 0;
      virtual HRESULT __stdcall get_RecordsAffected (
        /*[out,retval]*/ long * pl ) = 0;
      virtual HRESULT __stdcall get_TableDefs (
        /*[out,retval]*/ struct TableDefs * * pptdfs ) = 0;
      virtual HRESULT __stdcall get_QueryDefs (
        /*[out,retval]*/ struct QueryDefs * * ppqdfs ) = 0;
      virtual HRESULT __stdcall get_Relations (
        /*[out,retval]*/ struct Relations * * pprls ) = 0;
      virtual HRESULT __stdcall get_Containers (
        /*[out,retval]*/ struct Containers * * ppctns ) = 0;
      virtual HRESULT __stdcall get_Recordsets (
        /*[out,retval]*/ struct Recordsets * * pprsts ) = 0;
      virtual HRESULT __stdcall Close ( ) = 0;
      virtual HRESULT __stdcall Execute (
        /*[in]*/ BSTR Query,
        /*[in]*/ VARIANT Options = vtMissing ) = 0;
      virtual HRESULT __stdcall _30_OpenRecordset (
        /*[in]*/ BSTR Name,
        /*[in]*/ VARIANT Type,
        /*[in]*/ VARIANT Options,
        /*[out,retval]*/ struct Recordset * * pprst ) = 0;
      virtual HRESULT __stdcall CreateProperty (
        /*[in]*/ VARIANT Name,
        /*[in]*/ VARIANT Type,
        /*[in]*/ VARIANT Value,
        /*[in]*/ VARIANT DDL,
        /*[out,retval]*/ struct Property * * pprp ) = 0;
      virtual HRESULT __stdcall CreateRelation (
        /*[in]*/ VARIANT Name,
        /*[in]*/ VARIANT Table,
        /*[in]*/ VARIANT ForeignTable,
        /*[in]*/ VARIANT Attributes,
        /*[out,retval]*/ struct _Relation * * pprel ) = 0;
      virtual HRESULT __stdcall CreateTableDef (
        /*[in]*/ VARIANT Name,
        /*[in]*/ VARIANT Attributes,
        /*[in]*/ VARIANT SourceTableName,
        /*[in]*/ VARIANT Connect,
        /*[out,retval]*/ struct _TableDef * * pptdf ) = 0;
      virtual HRESULT __stdcall BeginTrans ( ) = 0;
      virtual HRESULT __stdcall CommitTrans (
        /*[in]*/ long Options ) = 0;
      virtual HRESULT __stdcall Rollback ( ) = 0;
      virtual HRESULT __stdcall CreateDynaset (
        /*[in]*/ BSTR Name,
        /*[in]*/ VARIANT Options,
        /*[in]*/ VARIANT Inconsistent,
        /*[out,retval]*/ struct Recordset * * pprst ) = 0;
      virtual HRESULT __stdcall CreateQueryDef (
        /*[in]*/ VARIANT Name,
        /*[in]*/ VARIANT SQLText,
        /*[out,retval]*/ struct _QueryDef * * ppqdf ) = 0;
      virtual HRESULT __stdcall CreateSnapshot (
        /*[in]*/ BSTR Source,
        /*[in]*/ VARIANT Options,
        /*[out,retval]*/ struct Recordset * * pprst ) = 0;
      virtual HRESULT __stdcall DeleteQueryDef (
        /*[in]*/ BSTR Name ) = 0;
      virtual HRESULT __stdcall ExecuteSQL (
        /*[in]*/ BSTR SQL,
        /*[out,retval]*/ long * pl ) = 0;
      virtual HRESULT __stdcall ListFields (
        /*[in]*/ BSTR Name,
        /*[out,retval]*/ struct Recordset * * pprst ) = 0;
      virtual HRESULT __stdcall ListTables (
        /*[out,retval]*/ struct Recordset * * pprst ) = 0;
      virtual HRESULT __stdcall OpenQueryDef (
        /*[in]*/ BSTR Name,
        /*[out,retval]*/ struct _QueryDef * * ppqdf ) = 0;
      virtual HRESULT __stdcall OpenTable (
        /*[in]*/ BSTR Name,
        /*[in]*/ VARIANT Options,
        /*[out,retval]*/ struct Recordset * * pprst ) = 0;
      virtual HRESULT __stdcall get_ReplicaID (
        /*[out,retval]*/ BSTR * pbstr ) = 0;
      virtual HRESULT __stdcall get_DesignMasterID (
        /*[out,retval]*/ BSTR * pbstr ) = 0;
      virtual HRESULT __stdcall put_DesignMasterID (
        /*[in]*/ BSTR pbstr ) = 0;
      virtual HRESULT __stdcall Synchronize (
        /*[in]*/ BSTR DbPathName,
        /*[in]*/ VARIANT ExchangeType = vtMissing ) = 0;
      virtual HRESULT __stdcall MakeReplica (
        /*[in]*/ BSTR PathName,
        /*[in]*/ BSTR Description,
        /*[in]*/ VARIANT Options = vtMissing ) = 0;
      virtual HRESULT __stdcall put_Connect (
        /*[in]*/ BSTR pbstr ) = 0;
      virtual HRESULT __stdcall NewPassword (
        /*[in]*/ BSTR bstrOld,
        /*[in]*/ BSTR bstrNew ) = 0;
      virtual HRESULT __stdcall OpenRecordset (
        /*[in]*/ BSTR Name,
        /*[in]*/ VARIANT Type,
        /*[in]*/ VARIANT Options,
        /*[in]*/ VARIANT LockEdit,
        /*[out,retval]*/ struct Recordset * * pprst ) = 0;
      virtual HRESULT __stdcall get_Connection (
        /*[out,retval]*/ struct Connection * * ppCn ) = 0;
      virtual HRESULT __stdcall PopulatePartial (
        /*[in]*/ BSTR DbPathName ) = 0;
};

struct __declspec(uuid("00000049-0000-0010-8000-00aa006d2ea4"))
_TableDef : _DAO
{
    //
    // Raw methods provided by interface
    //

      virtual HRESULT __stdcall get_Attributes (
        /*[out,retval]*/ long * pl ) = 0;
      virtual HRESULT __stdcall put_Attributes (
        /*[in]*/ long pl ) = 0;
      virtual HRESULT __stdcall get_Connect (
        /*[out,retval]*/ BSTR * pbstr ) = 0;
      virtual HRESULT __stdcall put_Connect (
        /*[in]*/ BSTR pbstr ) = 0;
      virtual HRESULT __stdcall get_DateCreated (
        /*[out,retval]*/ VARIANT * pvar ) = 0;
      virtual HRESULT __stdcall get_LastUpdated (
        /*[out,retval]*/ VARIANT * pvar ) = 0;
      virtual HRESULT __stdcall get_Name (
        /*[out,retval]*/ BSTR * pbstr ) = 0;
      virtual HRESULT __stdcall put_Name (
        /*[in]*/ BSTR pbstr ) = 0;
      virtual HRESULT __stdcall get_SourceTableName (
        /*[out,retval]*/ BSTR * pbstr ) = 0;
      virtual HRESULT __stdcall put_SourceTableName (
        /*[in]*/ BSTR pbstr ) = 0;
      virtual HRESULT __stdcall get_Updatable (
        /*[out,retval]*/ VARIANT_BOOL * pb ) = 0;
      virtual HRESULT __stdcall get_ValidationText (
        /*[out,retval]*/ BSTR * pbstr ) = 0;
      virtual HRESULT __stdcall put_ValidationText (
        /*[in]*/ BSTR pbstr ) = 0;
      virtual HRESULT __stdcall get_ValidationRule (
        /*[out,retval]*/ BSTR * pbstr ) = 0;
      virtual HRESULT __stdcall put_ValidationRule (
        /*[in]*/ BSTR pbstr ) = 0;
      virtual HRESULT __stdcall get_RecordCount (
        /*[out,retval]*/ long * pl ) = 0;
      virtual HRESULT __stdcall get_Fields (
        /*[out,retval]*/ struct Fields * * ppflds ) = 0;
      virtual HRESULT __stdcall get_Indexes (
        /*[out,retval]*/ struct Indexes * * ppidxs ) = 0;
      virtual HRESULT __stdcall OpenRecordset (
        /*[in]*/ VARIANT Type,
        /*[in]*/ VARIANT Options,
        /*[out,retval]*/ struct Recordset * * pprst ) = 0;
      virtual HRESULT __stdcall RefreshLink ( ) = 0;
      virtual HRESULT __stdcall CreateField (
        /*[in]*/ VARIANT Name,
        /*[in]*/ VARIANT Type,
        /*[in]*/ VARIANT Size,
        /*[out,retval]*/ struct _Field * * ppfld ) = 0;
      virtual HRESULT __stdcall CreateIndex (
        /*[in]*/ VARIANT Name,
        /*[out,retval]*/ struct _Index * * ppidx ) = 0;
      virtual HRESULT __stdcall CreateProperty (
        /*[in]*/ VARIANT Name,
        /*[in]*/ VARIANT Type,
        /*[in]*/ VARIANT Value,
        /*[in]*/ VARIANT DDL,
        /*[out,retval]*/ struct Property * * pprp ) = 0;
      virtual HRESULT __stdcall get_ConflictTable (
        /*[out,retval]*/ BSTR * pbstr ) = 0;
      virtual HRESULT __stdcall get_ReplicaFilter (
        /*[out,retval]*/ VARIANT * pFilter ) = 0;
      virtual HRESULT __stdcall put_ReplicaFilter (
        /*[in]*/ VARIANT pFilter ) = 0;
};

struct __declspec(uuid("00000031-0000-0010-8000-00aa006d2ea4"))
Recordset : _DAO
{
    //
    // Raw methods provided by interface
    //

      virtual HRESULT __stdcall get_BOF (
        /*[out,retval]*/ VARIANT_BOOL * pb ) = 0;
      virtual HRESULT __stdcall get_Bookmark (
        /*[out,retval]*/ SAFEARRAY * * ppsach ) = 0;
      virtual HRESULT __stdcall put_Bookmark (
        /*[in]*/ SAFEARRAY * * ppsach ) = 0;
      virtual HRESULT __stdcall get_Bookmarkable (
        /*[out,retval]*/ VARIANT_BOOL * pb ) = 0;
      virtual HRESULT __stdcall get_DateCreated (
        /*[out,retval]*/ VARIANT * pvar ) = 0;
      virtual HRESULT __stdcall get_EOF (
        /*[out,retval]*/ VARIANT_BOOL * pb ) = 0;
      virtual HRESULT __stdcall get_Filter (
        /*[out,retval]*/ BSTR * pbstr ) = 0;
      virtual HRESULT __stdcall put_Filter (
        /*[in]*/ BSTR pbstr ) = 0;
      virtual HRESULT __stdcall get_Index (
        /*[out,retval]*/ BSTR * pbstr ) = 0;
      virtual HRESULT __stdcall put_Index (
        /*[in]*/ BSTR pbstr ) = 0;
      virtual HRESULT __stdcall get_LastModified (
        /*[out,retval]*/ SAFEARRAY * * ppsa ) = 0;
      virtual HRESULT __stdcall get_LastUpdated (
        /*[out,retval]*/ VARIANT * pvar ) = 0;
      virtual HRESULT __stdcall get_LockEdits (
        /*[out,retval]*/ VARIANT_BOOL * pb ) = 0;
      virtual HRESULT __stdcall put_LockEdits (
        /*[in]*/ VARIANT_BOOL pb ) = 0;
      virtual HRESULT __stdcall get_Name (
        /*[out,retval]*/ BSTR * pbstr ) = 0;
      virtual HRESULT __stdcall get_NoMatch (
        /*[out,retval]*/ VARIANT_BOOL * pb ) = 0;
      virtual HRESULT __stdcall get_Sort (
        /*[out,retval]*/ BSTR * pbstr ) = 0;
      virtual HRESULT __stdcall put_Sort (
        /*[in]*/ BSTR pbstr ) = 0;
      virtual HRESULT __stdcall get_Transactions (
        /*[out,retval]*/ VARIANT_BOOL * pb ) = 0;
      virtual HRESULT __stdcall get_Type (
        /*[out,retval]*/ short * ps ) = 0;
      virtual HRESULT __stdcall get_RecordCount (
        /*[out,retval]*/ long * pl ) = 0;
      virtual HRESULT __stdcall get_Updatable (
        /*[out,retval]*/ VARIANT_BOOL * pb ) = 0;
      virtual HRESULT __stdcall get_Restartable (
        /*[out,retval]*/ VARIANT_BOOL * pb ) = 0;
      virtual HRESULT __stdcall get_ValidationText (
        /*[out,retval]*/ BSTR * pbstr ) = 0;
      virtual HRESULT __stdcall get_ValidationRule (
        /*[out,retval]*/ BSTR * pbstr ) = 0;
      virtual HRESULT __stdcall get_CacheStart (
        /*[out,retval]*/ SAFEARRAY * * ppsa ) = 0;
      virtual HRESULT __stdcall put_CacheStart (
        /*[in]*/ SAFEARRAY * * ppsa ) = 0;
      virtual HRESULT __stdcall get_CacheSize (
        /*[out,retval]*/ long * pl ) = 0;
      virtual HRESULT __stdcall put_CacheSize (
        /*[in]*/ long pl ) = 0;
      virtual HRESULT __stdcall get_PercentPosition (
        /*[out,retval]*/ float * pd ) = 0;
      virtual HRESULT __stdcall put_PercentPosition (
        /*[in]*/ float pd ) = 0;
      virtual HRESULT __stdcall get_AbsolutePosition (
        /*[out,retval]*/ long * pl ) = 0;
      virtual HRESULT __stdcall put_AbsolutePosition (
        /*[in]*/ long pl ) = 0;
      virtual HRESULT __stdcall get_EditMode (
        /*[out,retval]*/ short * pi ) = 0;
      virtual HRESULT __stdcall get_ODBCFetchCount (
        /*[out,retval]*/ long * pl ) = 0;
      virtual HRESULT __stdcall get_ODBCFetchDelay (
        /*[out,retval]*/ long * pl ) = 0;
      virtual HRESULT __stdcall get_Parent (
        /*[out,retval]*/ struct Database * * pdb ) = 0;
      virtual HRESULT __stdcall get_Fields (
        /*[out,retval]*/ struct Fields * * ppflds ) = 0;
      virtual HRESULT __stdcall get_Indexes (
        /*[out,retval]*/ struct Indexes * * ppidxs ) = 0;
      virtual HRESULT __stdcall _30_CancelUpdate ( ) = 0;
      virtual HRESULT __stdcall AddNew ( ) = 0;
      virtual HRESULT __stdcall Close ( ) = 0;
      virtual HRESULT __stdcall OpenRecordset (
        /*[in]*/ VARIANT Type,
        /*[in]*/ VARIANT Options,
        /*[out,retval]*/ struct Recordset * * pprst ) = 0;
      virtual HRESULT __stdcall Delete ( ) = 0;
      virtual HRESULT __stdcall Edit ( ) = 0;
      virtual HRESULT __stdcall FindFirst (
        /*[in]*/ BSTR Criteria ) = 0;
      virtual HRESULT __stdcall FindLast (
        /*[in]*/ BSTR Criteria ) = 0;
      virtual HRESULT __stdcall FindNext (
        /*[in]*/ BSTR Criteria ) = 0;
      virtual HRESULT __stdcall FindPrevious (
        /*[in]*/ BSTR Criteria ) = 0;
      virtual HRESULT __stdcall MoveFirst ( ) = 0;
      virtual HRESULT __stdcall _30_MoveLast ( ) = 0;
      virtual HRESULT __stdcall MoveNext ( ) = 0;
      virtual HRESULT __stdcall MovePrevious ( ) = 0;
      virtual HRESULT __stdcall Seek (
        /*[in]*/ BSTR Comparison,
        /*[in]*/ VARIANT Key1,
        /*[in]*/ VARIANT Key2 = vtMissing,
        /*[in]*/ VARIANT Key3 = vtMissing,
        /*[in]*/ VARIANT Key4 = vtMissing,
        /*[in]*/ VARIANT Key5 = vtMissing,
        /*[in]*/ VARIANT Key6 = vtMissing,
        /*[in]*/ VARIANT Key7 = vtMissing,
        /*[in]*/ VARIANT Key8 = vtMissing,
        /*[in]*/ VARIANT Key9 = vtMissing,
        /*[in]*/ VARIANT Key10 = vtMissing,
        /*[in]*/ VARIANT Key11 = vtMissing,
        /*[in]*/ VARIANT Key12 = vtMissing,
        /*[in]*/ VARIANT Key13 = vtMissing ) = 0;
      virtual HRESULT __stdcall _30_Update ( ) = 0;
      virtual HRESULT __stdcall Clone (
        /*[out,retval]*/ struct Recordset * * pprst ) = 0;
      virtual HRESULT __stdcall Requery (
        /*[in]*/ VARIANT NewQueryDef = vtMissing ) = 0;
      virtual HRESULT __stdcall Move (
        /*[in]*/ long Rows,
        /*[in]*/ VARIANT StartBookmark = vtMissing ) = 0;
      virtual HRESULT __stdcall FillCache (
        /*[in]*/ VARIANT Rows = vtMissing,
        /*[in]*/ VARIANT StartBookmark = vtMissing ) = 0;
      virtual HRESULT __stdcall CreateDynaset (
        /*[in]*/ VARIANT Options,
        /*[in]*/ VARIANT Inconsistent,
        /*[out,retval]*/ struct Recordset * * pprst ) = 0;
      virtual HRESULT __stdcall CreateSnapshot (
        /*[in]*/ VARIANT Options,
        /*[out,retval]*/ struct Recordset * * pprst ) = 0;
      virtual HRESULT __stdcall CopyQueryDef (
        /*[out,retval]*/ struct _QueryDef * * ppqdf ) = 0;
      virtual HRESULT __stdcall ListFields (
        /*[out,retval]*/ struct Recordset * * pprst ) = 0;
      virtual HRESULT __stdcall ListIndexes (
        /*[out,retval]*/ struct Recordset * * pprst ) = 0;
      virtual HRESULT __stdcall GetRows (
        /*[in]*/ VARIANT NumRows,
        /*[out,retval]*/ VARIANT * pvar ) = 0;
      virtual HRESULT __stdcall get_Collect (
        /*[in]*/ VARIANT Item,
        /*[out,retval]*/ VARIANT * pvar ) = 0;
      virtual HRESULT __stdcall put_Collect (
        /*[in]*/ VARIANT Item,
        /*[in]*/ VARIANT pvar ) = 0;
      virtual HRESULT __stdcall Cancel ( ) = 0;
      virtual HRESULT __stdcall NextRecordset (
        /*[out,retval]*/ VARIANT_BOOL * pb ) = 0;
      virtual HRESULT __stdcall get_hStmt (
        /*[out,retval]*/ long * phStmt ) = 0;
      virtual HRESULT __stdcall get_StillExecuting (
        /*[out,retval]*/ VARIANT_BOOL * pStillExec ) = 0;
      virtual HRESULT __stdcall get_BatchSize (
        /*[out,retval]*/ long * pl ) = 0;
      virtual HRESULT __stdcall put_BatchSize (
        /*[in]*/ long pl ) = 0;
      virtual HRESULT __stdcall get_BatchCollisionCount (
        /*[out,retval]*/ long * pl ) = 0;
      virtual HRESULT __stdcall get_BatchCollisions (
        /*[out,retval]*/ VARIANT * pvar ) = 0;
      virtual HRESULT __stdcall get_Connection (
        /*[out,retval]*/ struct Connection * * ppCn ) = 0;
      virtual HRESULT __stdcall putref_Connection (
        /*[in]*/ struct Connection * ppCn ) = 0;
      virtual HRESULT __stdcall get_RecordStatus (
        /*[out,retval]*/ short * pi ) = 0;
      virtual HRESULT __stdcall get_UpdateOptions (
        /*[out,retval]*/ long * pl ) = 0;
      virtual HRESULT __stdcall put_UpdateOptions (
        /*[in]*/ long pl ) = 0;
      virtual HRESULT __stdcall CancelUpdate (
        /*[in]*/ long UpdateType ) = 0;
      virtual HRESULT __stdcall Update (
        /*[in]*/ long UpdateType,
        /*[in]*/ VARIANT_BOOL Force ) = 0;
      virtual HRESULT __stdcall MoveLast (
        /*[in]*/ long Options ) = 0;
};

struct __declspec(uuid("00000079-0000-0010-8000-00aa006d2ea4"))
_QueryDef : _DAO
{
    //
    // Raw methods provided by interface
    //

      virtual HRESULT __stdcall get_DateCreated (
        /*[out,retval]*/ VARIANT * pvar ) = 0;
      virtual HRESULT __stdcall get_LastUpdated (
        /*[out,retval]*/ VARIANT * pvar ) = 0;
      virtual HRESULT __stdcall get_Name (
        /*[out,retval]*/ BSTR * pbstr ) = 0;
      virtual HRESULT __stdcall put_Name (
        /*[in]*/ BSTR pbstr ) = 0;
      virtual HRESULT __stdcall get_ODBCTimeout (
        /*[out,retval]*/ short * ps ) = 0;
      virtual HRESULT __stdcall put_ODBCTimeout (
        /*[in]*/ short ps ) = 0;
      virtual HRESULT __stdcall get_Type (
        /*[out,retval]*/ short * pi ) = 0;
      virtual HRESULT __stdcall get_SQL (
        /*[out,retval]*/ BSTR * pbstr ) = 0;
      virtual HRESULT __stdcall put_SQL (
        /*[in]*/ BSTR pbstr ) = 0;
      virtual HRESULT __stdcall get_Updatable (
        /*[out,retval]*/ VARIANT_BOOL * pb ) = 0;
      virtual HRESULT __stdcall get_Connect (
        /*[out,retval]*/ BSTR * pbstr ) = 0;
      virtual HRESULT __stdcall put_Connect (
        /*[in]*/ BSTR pbstr ) = 0;
      virtual HRESULT __stdcall get_ReturnsRecords (
        /*[out,retval]*/ VARIANT_BOOL * pb ) = 0;
      virtual HRESULT __stdcall put_ReturnsRecords (
        /*[in]*/ VARIANT_BOOL pb ) = 0;
      virtual HRESULT __stdcall get_RecordsAffected (
        /*[out,retval]*/ long * pl ) = 0;
      virtual HRESULT __stdcall get_Fields (
        /*[out,retval]*/ struct Fields * * ppflds ) = 0;
      virtual HRESULT __stdcall get_Parameters (
        /*[out,retval]*/ struct Parameters * * ppprms ) = 0;
      virtual HRESULT __stdcall Close ( ) = 0;
      virtual HRESULT __stdcall _30_OpenRecordset (
        /*[in]*/ VARIANT Type,
        /*[in]*/ VARIANT Options,
        /*[out,retval]*/ struct Recordset * * pprst ) = 0;
      virtual HRESULT __stdcall _30__OpenRecordset (
        /*[in]*/ VARIANT Type,
        /*[in]*/ VARIANT Options,
        /*[out,retval]*/ struct Recordset * * pprst ) = 0;
      virtual HRESULT __stdcall _Copy (
        /*[out,retval]*/ struct _QueryDef * * ppqdf ) = 0;
      virtual HRESULT __stdcall Execute (
        /*[in]*/ VARIANT Options = vtMissing ) = 0;
      virtual HRESULT __stdcall Compare (
        /*[in]*/ struct _QueryDef * pQdef,
        /*[in]*/ short * lps ) = 0;
      virtual HRESULT __stdcall CreateDynaset (
        /*[in]*/ VARIANT Options,
        /*[in]*/ VARIANT Inconsistent,
        /*[out,retval]*/ struct Recordset * * pprst ) = 0;
      virtual HRESULT __stdcall CreateSnapshot (
        /*[in]*/ VARIANT Options,
        /*[out,retval]*/ struct Recordset * * pprst ) = 0;
      virtual HRESULT __stdcall ListParameters (
        /*[out,retval]*/ struct Recordset * * pprst ) = 0;
      virtual HRESULT __stdcall CreateProperty (
        /*[in]*/ VARIANT Name,
        /*[in]*/ VARIANT Type,
        /*[in]*/ VARIANT Value,
        /*[in]*/ VARIANT DDL,
        /*[out,retval]*/ struct Property * * pprp ) = 0;
      virtual HRESULT __stdcall OpenRecordset (
        /*[in]*/ VARIANT Type,
        /*[in]*/ VARIANT Options,
        /*[in]*/ VARIANT LockEdit,
        /*[out,retval]*/ struct Recordset * * pprst ) = 0;
      virtual HRESULT __stdcall _OpenRecordset (
        /*[in]*/ VARIANT Type,
        /*[in]*/ VARIANT Options,
        /*[in]*/ VARIANT LockEdit,
        /*[out,retval]*/ struct Recordset * * pprst ) = 0;
      virtual HRESULT __stdcall Cancel ( ) = 0;
      virtual HRESULT __stdcall get_hStmt (
        /*[out,retval]*/ long * phStmt ) = 0;
      virtual HRESULT __stdcall get_MaxRecords (
        /*[out,retval]*/ long * pMxRecs ) = 0;
      virtual HRESULT __stdcall put_MaxRecords (
        /*[in]*/ long pMxRecs ) = 0;
      virtual HRESULT __stdcall get_StillExecuting (
        /*[out,retval]*/ VARIANT_BOOL * pStillExec ) = 0;
      virtual HRESULT __stdcall get_CacheSize (
        /*[out,retval]*/ long * lCacheSize ) = 0;
      virtual HRESULT __stdcall put_CacheSize (
        /*[in]*/ long lCacheSize ) = 0;
      virtual HRESULT __stdcall get_Prepare (
        /*[out,retval]*/ VARIANT * pb ) = 0;
      virtual HRESULT __stdcall put_Prepare (
        /*[in]*/ VARIANT pb ) = 0;
};

struct __declspec(uuid("00000033-0000-0010-8000-00aa006d2ea4"))
Recordsets : _Collection
{
    //
    // Raw methods provided by interface
    //

      virtual HRESULT __stdcall get_Item (
        /*[in]*/ VARIANT Item,
        /*[out,retval]*/ struct Recordset * * pprst ) = 0;
};

struct __declspec(uuid("00000041-0000-0010-8000-00aa006d2ea4"))
Connection : IDispatch
{
    //
    // Raw methods provided by interface
    //

      virtual HRESULT __stdcall get_Name (
        /*[out,retval]*/ BSTR * pbstr ) = 0;
      virtual HRESULT __stdcall get_Connect (
        /*[out,retval]*/ BSTR * pbstr ) = 0;
      virtual HRESULT __stdcall get_Database (
        /*[out,retval]*/ struct Database * * ppDb ) = 0;
      virtual HRESULT __stdcall get_hDbc (
        /*[out,retval]*/ long * phDbc ) = 0;
      virtual HRESULT __stdcall get_QueryTimeout (
        /*[out,retval]*/ short * pSeconds ) = 0;
      virtual HRESULT __stdcall put_QueryTimeout (
        /*[in]*/ short pSeconds ) = 0;
      virtual HRESULT __stdcall get_Transactions (
        /*[out,retval]*/ VARIANT_BOOL * pb ) = 0;
      virtual HRESULT __stdcall get_RecordsAffected (
        /*[out,retval]*/ long * pRecords ) = 0;
      virtual HRESULT __stdcall get_StillExecuting (
        /*[out,retval]*/ VARIANT_BOOL * pStillExec ) = 0;
      virtual HRESULT __stdcall get_Updatable (
        /*[out,retval]*/ VARIANT_BOOL * pStillExec ) = 0;
      virtual HRESULT __stdcall get_QueryDefs (
        /*[out,retval]*/ struct QueryDefs * * ppqdfs ) = 0;
      virtual HRESULT __stdcall get_Recordsets (
        /*[out,retval]*/ struct Recordsets * * pprsts ) = 0;
      virtual HRESULT __stdcall Cancel ( ) = 0;
      virtual HRESULT __stdcall Close ( ) = 0;
      virtual HRESULT __stdcall CreateQueryDef (
        /*[in]*/ VARIANT Name,
        /*[in]*/ VARIANT SQLText,
        /*[out,retval]*/ struct _QueryDef * * ppqdf ) = 0;
      virtual HRESULT __stdcall Execute (
        /*[in]*/ BSTR Query,
        /*[in]*/ VARIANT Options = vtMissing ) = 0;
      virtual HRESULT __stdcall OpenRecordset (
        /*[in]*/ BSTR Name,
        /*[in]*/ VARIANT Type,
        /*[in]*/ VARIANT Options,
        /*[in]*/ VARIANT LockEdit,
        /*[out,retval]*/ struct Recordset * * pprst ) = 0;
};

struct __declspec(uuid("00000043-0000-0010-8000-00aa006d2ea4"))
Connections : _Collection
{
    //
    // Raw methods provided by interface
    //

      virtual HRESULT __stdcall get_Item (
        /*[in]*/ VARIANT Item,
        /*[out,retval]*/ struct Connection * * ppconn ) = 0;
};

struct __declspec(uuid("00000035-0000-0010-8000-00aa006d2ea4"))
Recordset2 : Recordset
{
    //
    // Raw methods provided by interface
    //

      virtual HRESULT __stdcall get_ParentRecordset (
        /*[out,retval]*/ struct Recordset * * pprst ) = 0;
};

//
// Named GUID constants initializations
//

extern "C" const GUID __declspec(selectany) LIBID_DAO =
    {0x4ac9e1da,0x5bad,0x4ac7,{0x86,0xe3,0x24,0xf4,0xcd,0xce,0xca,0x28}};
//extern "C" const GUID __declspec(selectany) IID__Collection =
//    {0x000000a0,0x0000,0x0010,{0x80,0x00,0x00,0xaa,0x00,0x6d,0x2e,0xa4}};
//extern "C" const GUID __declspec(selectany) IID__DynaCollection =
//    {0x000000a2,0x0000,0x0010,{0x80,0x00,0x00,0xaa,0x00,0x6d,0x2e,0xa4}};
//extern "C" const GUID __declspec(selectany) CLSID_TableDef =
//    {0x367e582c,0xf71c,0x4bf9,{0xaa,0x1b,0x9f,0x62,0xb7,0x93,0xe9,0xc5}};
//extern "C" const GUID __declspec(selectany) IID_TableDefs =
//    {0x0000004b,0x0000,0x0010,{0x80,0x00,0x00,0xaa,0x00,0x6d,0x2e,0xa4}};
//extern "C" const GUID __declspec(selectany) CLSID_Field =
//    {0xa1eb89d6,0x0a9c,0x4575,{0xa0,0xae,0x65,0x4a,0x99,0x0a,0x45,0x4c}};
//extern "C" const GUID __declspec(selectany) IID_Fields =
//    {0x00000053,0x0000,0x0010,{0x80,0x00,0x00,0xaa,0x00,0x6d,0x2e,0xa4}};
//extern "C" const GUID __declspec(selectany) CLSID_Index =
//    {0x8d4f994c,0xebbe,0x4f8d,{0xba,0x4b,0xae,0x20,0xcd,0x36,0xe7,0x2d}};
//extern "C" const GUID __declspec(selectany) IID_Indexes =
//    {0x0000005b,0x0000,0x0010,{0x80,0x00,0x00,0xaa,0x00,0x6d,0x2e,0xa4}};
//extern "C" const GUID __declspec(selectany) CLSID_QueryDef =
//    {0xd5ec4d34,0x77da,0x4f7a,{0xb8,0xc4,0x8a,0x91,0x0c,0x1c,0x1c,0xfe}};
//extern "C" const GUID __declspec(selectany) IID_QueryDefs =
//    {0x0000007b,0x0000,0x0010,{0x80,0x00,0x00,0xaa,0x00,0x6d,0x2e,0xa4}};
//extern "C" const GUID __declspec(selectany) CLSID_Relation =
//    {0xd0b22d03,0xd05d,0x4c6d,{0x8a,0xb7,0x93,0x92,0xe8,0x4a,0x87,0xb9}};
//extern "C" const GUID __declspec(selectany) IID_Relations =
//    {0x0000008b,0x0000,0x0010,{0x80,0x00,0x00,0xaa,0x00,0x6d,0x2e,0xa4}};
//extern "C" const GUID __declspec(selectany) CLSID_User =
//    {0x805b7f91,0xc9cf,0x4edf,{0xac,0xa6,0x77,0x56,0x64,0xfd,0xfb,0x3e}};
//extern "C" const GUID __declspec(selectany) IID_Users =
//    {0x0000006b,0x0000,0x0010,{0x80,0x00,0x00,0xaa,0x00,0x6d,0x2e,0xa4}};
//extern "C" const GUID __declspec(selectany) CLSID_Group =
//    {0x97a2762c,0x403c,0x4953,{0xa1,0x21,0x7a,0x75,0xab,0xce,0x43,0x73}};
//extern "C" const GUID __declspec(selectany) IID_Groups =
//    {0x00000063,0x0000,0x0010,{0x80,0x00,0x00,0xaa,0x00,0x6d,0x2e,0xa4}};
//extern "C" const GUID __declspec(selectany) IID_Error =
//    {0x00000023,0x0000,0x0010,{0x80,0x00,0x00,0xaa,0x00,0x6d,0x2e,0xa4}};
//extern "C" const GUID __declspec(selectany) IID_Errors =
//    {0x00000025,0x0000,0x0010,{0x80,0x00,0x00,0xaa,0x00,0x6d,0x2e,0xa4}};
//extern "C" const GUID __declspec(selectany) IID_ComplexType =
//    {0x0000009d,0x0000,0x0010,{0x80,0x00,0x00,0xaa,0x00,0x6d,0x2e,0xa4}};
//extern "C" const GUID __declspec(selectany) CLSID_DBEngine =
//    {0xcd7791b9,0x43fd,0x42c5,{0xae,0x42,0x8d,0xd2,0x81,0x1f,0x04,0x19}};
//extern "C" const GUID __declspec(selectany) CLSID_PrivDBEngine =
//    {0x6f3dd387,0x5af2,0x492b,{0xbd,0xe2,0x30,0xff,0x2f,0x45,0x12,0x41}};
//extern "C" const GUID __declspec(selectany) IID_IndexFields =
//    {0x0000005d,0x0000,0x0010,{0x80,0x00,0x00,0xaa,0x00,0x6d,0x2e,0xa4}};
//extern "C" const GUID __declspec(selectany) IID__DAO =
//    {0x0000000a,0x0000,0x0010,{0x80,0x00,0x00,0xaa,0x00,0x6d,0x2e,0xa4}};
//extern "C" const GUID __declspec(selectany) IID_Property =
//    {0x00000027,0x0000,0x0010,{0x80,0x00,0x00,0xaa,0x00,0x6d,0x2e,0xa4}};
//extern "C" const GUID __declspec(selectany) IID_Properties =
//    {0x00000029,0x0000,0x0010,{0x80,0x00,0x00,0xaa,0x00,0x6d,0x2e,0xa4}};
//extern "C" const GUID __declspec(selectany) IID__Field =
//    {0x00000051,0x0000,0x0010,{0x80,0x00,0x00,0xaa,0x00,0x6d,0x2e,0xa4}};
//extern "C" const GUID __declspec(selectany) IID__Index =
//    {0x00000059,0x0000,0x0010,{0x80,0x00,0x00,0xaa,0x00,0x6d,0x2e,0xa4}};
//extern "C" const GUID __declspec(selectany) IID_Parameter =
//    {0x00000081,0x0000,0x0010,{0x80,0x00,0x00,0xaa,0x00,0x6d,0x2e,0xa4}};
//extern "C" const GUID __declspec(selectany) IID_Parameters =
//    {0x00000083,0x0000,0x0010,{0x80,0x00,0x00,0xaa,0x00,0x6d,0x2e,0xa4}};
//extern "C" const GUID __declspec(selectany) IID__Relation =
//    {0x00000089,0x0000,0x0010,{0x80,0x00,0x00,0xaa,0x00,0x6d,0x2e,0xa4}};
//extern "C" const GUID __declspec(selectany) IID_Document =
//    {0x00000099,0x0000,0x0010,{0x80,0x00,0x00,0xaa,0x00,0x6d,0x2e,0xa4}};
//extern "C" const GUID __declspec(selectany) IID_Documents =
//    {0x0000009b,0x0000,0x0010,{0x80,0x00,0x00,0xaa,0x00,0x6d,0x2e,0xa4}};
//extern "C" const GUID __declspec(selectany) IID_Container =
//    {0x00000091,0x0000,0x0010,{0x80,0x00,0x00,0xaa,0x00,0x6d,0x2e,0xa4}};
//extern "C" const GUID __declspec(selectany) IID_Containers =
//    {0x00000093,0x0000,0x0010,{0x80,0x00,0x00,0xaa,0x00,0x6d,0x2e,0xa4}};
//extern "C" const GUID __declspec(selectany) IID__User =
//    {0x00000069,0x0000,0x0010,{0x80,0x00,0x00,0xaa,0x00,0x6d,0x2e,0xa4}};
//extern "C" const GUID __declspec(selectany) IID__Group =
//    {0x00000061,0x0000,0x0010,{0x80,0x00,0x00,0xaa,0x00,0x6d,0x2e,0xa4}};
//extern "C" const GUID __declspec(selectany) IID_Field2 =
//    {0x00000054,0x0000,0x0010,{0x80,0x00,0x00,0xaa,0x00,0x6d,0x2e,0xa4}};
//extern "C" const GUID __declspec(selectany) IID__DBEngine =
//    {0x00000021,0x0000,0x0010,{0x80,0x00,0x00,0xaa,0x00,0x6d,0x2e,0xa4}};
//extern "C" const GUID __declspec(selectany) IID_Workspaces =
//    {0x0000003b,0x0000,0x0010,{0x80,0x00,0x00,0xaa,0x00,0x6d,0x2e,0xa4}};
//extern "C" const GUID __declspec(selectany) IID_Workspace =
//    {0x00000039,0x0000,0x0010,{0x80,0x00,0x00,0xaa,0x00,0x6d,0x2e,0xa4}};
//extern "C" const GUID __declspec(selectany) IID_Databases =
//    {0x00000073,0x0000,0x0010,{0x80,0x00,0x00,0xaa,0x00,0x6d,0x2e,0xa4}};
//extern "C" const GUID __declspec(selectany) IID_Database =
//    {0x00000071,0x0000,0x0010,{0x80,0x00,0x00,0xaa,0x00,0x6d,0x2e,0xa4}};
//extern "C" const GUID __declspec(selectany) IID__TableDef =
//    {0x00000049,0x0000,0x0010,{0x80,0x00,0x00,0xaa,0x00,0x6d,0x2e,0xa4}};
//extern "C" const GUID __declspec(selectany) IID_Recordset =
//    {0x00000031,0x0000,0x0010,{0x80,0x00,0x00,0xaa,0x00,0x6d,0x2e,0xa4}};
//extern "C" const GUID __declspec(selectany) IID__QueryDef =
//    {0x00000079,0x0000,0x0010,{0x80,0x00,0x00,0xaa,0x00,0x6d,0x2e,0xa4}};
//extern "C" const GUID __declspec(selectany) IID_Recordsets =
//    {0x00000033,0x0000,0x0010,{0x80,0x00,0x00,0xaa,0x00,0x6d,0x2e,0xa4}};
//extern "C" const GUID __declspec(selectany) IID_Connection =
//    {0x00000041,0x0000,0x0010,{0x80,0x00,0x00,0xaa,0x00,0x6d,0x2e,0xa4}};
//extern "C" const GUID __declspec(selectany) IID_Connections =
//    {0x00000043,0x0000,0x0010,{0x80,0x00,0x00,0xaa,0x00,0x6d,0x2e,0xa4}};
//extern "C" const GUID __declspec(selectany) IID_Recordset2 =
//    {0x00000035,0x0000,0x0010,{0x80,0x00,0x00,0xaa,0x00,0x6d,0x2e,0xa4}};

} // namespace DAO

#pragma pack(pop)

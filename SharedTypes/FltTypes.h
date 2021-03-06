#pragma once

enum KbFltTypes {
    KbObCallbacks,
    KbPsProcess,
    KbPsThread,
    KbPsImage,
    KbFltPreCreate,
    KbFltPreWrite
};

DECLARE_STRUCT(KB_FLT_CONTEXT, {
    KbFltTypes Type;
    WdkTypes::CLIENT_ID Client;    
});

DECLARE_STRUCT(KB_FLT_OB_CALLBACK_INFO, {
    WdkTypes::CLIENT_ID Client;
    WdkTypes::CLIENT_ID Target;
    ACCESS_MASK CreateDesiredAccess;
    ACCESS_MASK DuplicateDesiredAccess;
    ACCESS_MASK CreateResultAccess;
    ACCESS_MASK DuplicateResultAccess;
});

DECLARE_STRUCT(KB_FLT_PS_PROCESS_INFO, {
    WdkTypes::HANDLE ParentId;
    WdkTypes::HANDLE ProcessId;
    BOOLEAN Created;
});

DECLARE_STRUCT(KB_FLT_PS_THREAD_INFO, {
    WdkTypes::HANDLE ProcessId;
    WdkTypes::HANDLE ThreadId;
    BOOLEAN Created;
});

DECLARE_STRUCT(KB_FLT_PS_IMAGE_INFO, {
    WdkTypes::HANDLE ProcessId;
    WdkTypes::PVOID BaseAddress;
    UINT64 ImageSize;
    WCHAR FullImageName[384]; // Fixed size! Enough for paths.
});

DECLARE_STRUCT(KB_FLT_PRE_CREATE_INFO, {
    WdkTypes::HANDLE ProcessId;
    ACCESS_MASK AccessMask;
    WdkTypes::NTSTATUS Status;
    WCHAR Path[384]; // Fixed size! Enough for paths.
});

DECLARE_STRUCT(KB_FLT_PRE_WRITE_INFO, {
    WdkTypes::HANDLE ProcessId;
    WdkTypes::PMDL Mdl;
    ULONG Size;
    WdkTypes::NTSTATUS Status;
    WCHAR Path[384];
});
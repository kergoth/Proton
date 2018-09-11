/*** Autogenerated by WIDL 3.8 from include/vkd3d_dxgi.idl - Do not edit ***/

#ifndef __REQUIRED_RPCNDR_H_VERSION__
#define __REQUIRED_RPCNDR_H_VERSION__ 475
#endif


#ifndef COM_NO_WINDOWS_H
#include <windows.h>
#include <ole2.h>
#endif

#ifndef __vkd3d_dxgi_h__
#define __vkd3d_dxgi_h__

/* Forward declarations */

#ifndef __IUnknown_FWD_DEFINED__
#define __IUnknown_FWD_DEFINED__
typedef interface IUnknown IUnknown;
#ifdef __cplusplus
interface IUnknown;
#endif /* __cplusplus */
#endif

#ifndef __IDXGIObject_FWD_DEFINED__
#define __IDXGIObject_FWD_DEFINED__
typedef interface IDXGIObject IDXGIObject;
#ifdef __cplusplus
interface IDXGIObject;
#endif /* __cplusplus */
#endif

#ifndef __IDXGIDeviceSubObject_FWD_DEFINED__
#define __IDXGIDeviceSubObject_FWD_DEFINED__
typedef interface IDXGIDeviceSubObject IDXGIDeviceSubObject;
#ifdef __cplusplus
interface IDXGIDeviceSubObject;
#endif /* __cplusplus */
#endif

#ifndef __IDXGISwapChain_FWD_DEFINED__
#define __IDXGISwapChain_FWD_DEFINED__
typedef interface IDXGISwapChain IDXGISwapChain;
#ifdef __cplusplus
interface IDXGISwapChain;
#endif /* __cplusplus */
#endif

#ifndef __IDXGIFactory_FWD_DEFINED__
#define __IDXGIFactory_FWD_DEFINED__
typedef interface IDXGIFactory IDXGIFactory;
#ifdef __cplusplus
interface IDXGIFactory;
#endif /* __cplusplus */
#endif

#ifndef __IDXGIFactory1_FWD_DEFINED__
#define __IDXGIFactory1_FWD_DEFINED__
typedef interface IDXGIFactory1 IDXGIFactory1;
#ifdef __cplusplus
interface IDXGIFactory1;
#endif /* __cplusplus */
#endif

/* Headers for imported files */

#include <vkd3d_dxgitype.h>

#ifdef __cplusplus
extern "C" {
#endif

#ifndef __VKD3D_UNKNOWN_H
#define __VKD3D_UNKNOWN_H
#if 0
typedef IID *REFIID;
typedef IID *REFGUID;
#endif
#if !defined(_WIN32)
typedef void *HWND;
typedef void *HMODULE;
typedef struct LUID {
    DWORD LowPart;
    LONG HighPart;
} LUID;
typedef struct _RECT {
    LONG left;
    LONG top;
    LONG right;
    LONG bottom;
} RECT;
#endif
/*****************************************************************************
 * IUnknown interface
 */
#ifndef __IUnknown_INTERFACE_DEFINED__
#define __IUnknown_INTERFACE_DEFINED__

DEFINE_GUID(IID_IUnknown, 0x00000000, 0x0000, 0x0000, 0xc0,0x00, 0x00,0x00,0x00,0x00,0x00,0x46);
#if defined(__cplusplus) && !defined(CINTERFACE)
MIDL_INTERFACE("00000000-0000-0000-c000-000000000046")
IUnknown
{

    BEGIN_INTERFACE

    virtual HRESULT STDMETHODCALLTYPE QueryInterface(
        REFIID riid,
        void **object) = 0;

    virtual ULONG STDMETHODCALLTYPE AddRef(
        ) = 0;

    virtual ULONG STDMETHODCALLTYPE Release(
        ) = 0;

    END_INTERFACE

};
#ifdef __CRT_UUID_DECL
__CRT_UUID_DECL(IUnknown, 0x00000000, 0x0000, 0x0000, 0xc0,0x00, 0x00,0x00,0x00,0x00,0x00,0x46)
#endif
#else
typedef struct IUnknownVtbl {
    BEGIN_INTERFACE

    /*** IUnknown methods ***/
    HRESULT (STDMETHODCALLTYPE *QueryInterface)(
        IUnknown *This,
        REFIID riid,
        void **object);

    ULONG (STDMETHODCALLTYPE *AddRef)(
        IUnknown *This);

    ULONG (STDMETHODCALLTYPE *Release)(
        IUnknown *This);

    END_INTERFACE
} IUnknownVtbl;

interface IUnknown {
    CONST_VTBL IUnknownVtbl* lpVtbl;
};

#ifdef COBJMACROS
#ifndef WIDL_C_INLINE_WRAPPERS
/*** IUnknown methods ***/
#define IUnknown_QueryInterface(This,riid,object) (This)->lpVtbl->QueryInterface(This,riid,object)
#define IUnknown_AddRef(This) (This)->lpVtbl->AddRef(This)
#define IUnknown_Release(This) (This)->lpVtbl->Release(This)
#else
/*** IUnknown methods ***/
static FORCEINLINE HRESULT IUnknown_QueryInterface(IUnknown* This,REFIID riid,void **object) {
    return This->lpVtbl->QueryInterface(This,riid,object);
}
static FORCEINLINE ULONG IUnknown_AddRef(IUnknown* This) {
    return This->lpVtbl->AddRef(This);
}
static FORCEINLINE ULONG IUnknown_Release(IUnknown* This) {
    return This->lpVtbl->Release(This);
}
#endif
#endif

#endif


#endif  /* __IUnknown_INTERFACE_DEFINED__ */

#endif   /* __VKD3D_UNKNOWN_H */
typedef enum DXGI_SWAP_EFFECT {
    DXGI_SWAP_EFFECT_DISCARD = 0x0,
    DXGI_SWAP_EFFECT_SEQUENTIAL = 0x1,
    DXGI_SWAP_EFFECT_FLIP_SEQUENTIAL = 0x3,
    DXGI_SWAP_EFFECT_FLIP_DISCARD = 0x4
} DXGI_SWAP_EFFECT;
typedef enum DXGI_MODE_ROTATION {
    DXGI_MODE_ROTATION_UNSPECIFIED = 0x0,
    DXGI_MODE_ROTATION_IDENTITY = 0x1,
    DXGI_MODE_ROTATION_ROTATE90 = 0x2,
    DXGI_MODE_ROTATION_ROTATE180 = 0x3,
    DXGI_MODE_ROTATION_ROTATE270 = 0x4
} DXGI_MODE_ROTATION;
#ifndef __IDXGIAdapter_FWD_DEFINED__
#define __IDXGIAdapter_FWD_DEFINED__
typedef interface IDXGIAdapter IDXGIAdapter;
#ifdef __cplusplus
interface IDXGIAdapter;
#endif /* __cplusplus */
#endif

#ifndef __IDXGIAdapter1_FWD_DEFINED__
#define __IDXGIAdapter1_FWD_DEFINED__
typedef interface IDXGIAdapter1 IDXGIAdapter1;
#ifdef __cplusplus
interface IDXGIAdapter1;
#endif /* __cplusplus */
#endif

#ifndef __IDXGIOutput_FWD_DEFINED__
#define __IDXGIOutput_FWD_DEFINED__
typedef interface IDXGIOutput IDXGIOutput;
#ifdef __cplusplus
interface IDXGIOutput;
#endif /* __cplusplus */
#endif

typedef struct DXGI_SWAP_CHAIN_DESC DXGI_SWAP_CHAIN_DESC;
typedef struct DXGI_FRAME_STATISTICS DXGI_FRAME_STATISTICS;
typedef UINT DXGI_USAGE;
#define DXGI_USAGE_SHADER_INPUT (0x10)

#define DXGI_USAGE_RENDER_TARGET_OUTPUT (0x20)

#define DXGI_USAGE_BACK_BUFFER (0x40)

#define DXGI_USAGE_SHARED (0x80)

#define DXGI_USAGE_READ_ONLY (0x100)

#define DXGI_USAGE_DISCARD_ON_PRESENT (0x200)

#define DXGI_USAGE_UNORDERED_ACCESS (0x400)

/*****************************************************************************
 * IDXGIObject interface
 */
#ifndef __IDXGIObject_INTERFACE_DEFINED__
#define __IDXGIObject_INTERFACE_DEFINED__

DEFINE_GUID(IID_IDXGIObject, 0xaec22fb8, 0x76f3, 0x4639, 0x9b,0xe0, 0x28,0xeb,0x43,0xa6,0x7a,0x2e);
#if defined(__cplusplus) && !defined(CINTERFACE)
MIDL_INTERFACE("aec22fb8-76f3-4639-9be0-28eb43a67a2e")
IDXGIObject : public IUnknown
{
    virtual HRESULT STDMETHODCALLTYPE SetPrivateData(
        REFGUID name,
        UINT data_size,
        const void *data) = 0;

    virtual HRESULT STDMETHODCALLTYPE GetPrivateDataInterface(
        REFGUID name,
        const IUnknown *unknown) = 0;

    virtual HRESULT STDMETHODCALLTYPE GetPrivateData(
        REFGUID name,
        UINT *data_size,
        void *data) = 0;

    virtual HRESULT STDMETHODCALLTYPE GetParent(
        REFIID riid,
        void **parent) = 0;

};
#ifdef __CRT_UUID_DECL
__CRT_UUID_DECL(IDXGIObject, 0xaec22fb8, 0x76f3, 0x4639, 0x9b,0xe0, 0x28,0xeb,0x43,0xa6,0x7a,0x2e)
#endif
#else
typedef struct IDXGIObjectVtbl {
    BEGIN_INTERFACE

    /*** IUnknown methods ***/
    HRESULT (STDMETHODCALLTYPE *QueryInterface)(
        IDXGIObject *This,
        REFIID riid,
        void **object);

    ULONG (STDMETHODCALLTYPE *AddRef)(
        IDXGIObject *This);

    ULONG (STDMETHODCALLTYPE *Release)(
        IDXGIObject *This);

    /*** IDXGIObject methods ***/
    HRESULT (STDMETHODCALLTYPE *SetPrivateData)(
        IDXGIObject *This,
        REFGUID name,
        UINT data_size,
        const void *data);

    HRESULT (STDMETHODCALLTYPE *GetPrivateDataInterface)(
        IDXGIObject *This,
        REFGUID name,
        const IUnknown *unknown);

    HRESULT (STDMETHODCALLTYPE *GetPrivateData)(
        IDXGIObject *This,
        REFGUID name,
        UINT *data_size,
        void *data);

    HRESULT (STDMETHODCALLTYPE *GetParent)(
        IDXGIObject *This,
        REFIID riid,
        void **parent);

    END_INTERFACE
} IDXGIObjectVtbl;

interface IDXGIObject {
    CONST_VTBL IDXGIObjectVtbl* lpVtbl;
};

#ifdef COBJMACROS
#ifndef WIDL_C_INLINE_WRAPPERS
/*** IUnknown methods ***/
#define IDXGIObject_QueryInterface(This,riid,object) (This)->lpVtbl->QueryInterface(This,riid,object)
#define IDXGIObject_AddRef(This) (This)->lpVtbl->AddRef(This)
#define IDXGIObject_Release(This) (This)->lpVtbl->Release(This)
/*** IDXGIObject methods ***/
#define IDXGIObject_SetPrivateData(This,name,data_size,data) (This)->lpVtbl->SetPrivateData(This,name,data_size,data)
#define IDXGIObject_GetPrivateDataInterface(This,name,unknown) (This)->lpVtbl->GetPrivateDataInterface(This,name,unknown)
#define IDXGIObject_GetPrivateData(This,name,data_size,data) (This)->lpVtbl->GetPrivateData(This,name,data_size,data)
#define IDXGIObject_GetParent(This,riid,parent) (This)->lpVtbl->GetParent(This,riid,parent)
#else
/*** IUnknown methods ***/
static FORCEINLINE HRESULT IDXGIObject_QueryInterface(IDXGIObject* This,REFIID riid,void **object) {
    return This->lpVtbl->QueryInterface(This,riid,object);
}
static FORCEINLINE ULONG IDXGIObject_AddRef(IDXGIObject* This) {
    return This->lpVtbl->AddRef(This);
}
static FORCEINLINE ULONG IDXGIObject_Release(IDXGIObject* This) {
    return This->lpVtbl->Release(This);
}
/*** IDXGIObject methods ***/
static FORCEINLINE HRESULT IDXGIObject_SetPrivateData(IDXGIObject* This,REFGUID name,UINT data_size,const void *data) {
    return This->lpVtbl->SetPrivateData(This,name,data_size,data);
}
static FORCEINLINE HRESULT IDXGIObject_GetPrivateDataInterface(IDXGIObject* This,REFGUID name,const IUnknown *unknown) {
    return This->lpVtbl->GetPrivateDataInterface(This,name,unknown);
}
static FORCEINLINE HRESULT IDXGIObject_GetPrivateData(IDXGIObject* This,REFGUID name,UINT *data_size,void *data) {
    return This->lpVtbl->GetPrivateData(This,name,data_size,data);
}
static FORCEINLINE HRESULT IDXGIObject_GetParent(IDXGIObject* This,REFIID riid,void **parent) {
    return This->lpVtbl->GetParent(This,riid,parent);
}
#endif
#endif

#endif


#endif  /* __IDXGIObject_INTERFACE_DEFINED__ */

/*****************************************************************************
 * IDXGIDeviceSubObject interface
 */
#ifndef __IDXGIDeviceSubObject_INTERFACE_DEFINED__
#define __IDXGIDeviceSubObject_INTERFACE_DEFINED__

DEFINE_GUID(IID_IDXGIDeviceSubObject, 0x3d3e0379, 0xf9de, 0x4d58, 0xbb,0x6c, 0x18,0xd6,0x29,0x92,0xf1,0xa6);
#if defined(__cplusplus) && !defined(CINTERFACE)
MIDL_INTERFACE("3d3e0379-f9de-4d58-bb6c-18d62992f1a6")
IDXGIDeviceSubObject : public IDXGIObject
{
    virtual HRESULT STDMETHODCALLTYPE GetDevice(
        REFIID riid,
        void **device) = 0;

};
#ifdef __CRT_UUID_DECL
__CRT_UUID_DECL(IDXGIDeviceSubObject, 0x3d3e0379, 0xf9de, 0x4d58, 0xbb,0x6c, 0x18,0xd6,0x29,0x92,0xf1,0xa6)
#endif
#else
typedef struct IDXGIDeviceSubObjectVtbl {
    BEGIN_INTERFACE

    /*** IUnknown methods ***/
    HRESULT (STDMETHODCALLTYPE *QueryInterface)(
        IDXGIDeviceSubObject *This,
        REFIID riid,
        void **object);

    ULONG (STDMETHODCALLTYPE *AddRef)(
        IDXGIDeviceSubObject *This);

    ULONG (STDMETHODCALLTYPE *Release)(
        IDXGIDeviceSubObject *This);

    /*** IDXGIObject methods ***/
    HRESULT (STDMETHODCALLTYPE *SetPrivateData)(
        IDXGIDeviceSubObject *This,
        REFGUID name,
        UINT data_size,
        const void *data);

    HRESULT (STDMETHODCALLTYPE *GetPrivateDataInterface)(
        IDXGIDeviceSubObject *This,
        REFGUID name,
        const IUnknown *unknown);

    HRESULT (STDMETHODCALLTYPE *GetPrivateData)(
        IDXGIDeviceSubObject *This,
        REFGUID name,
        UINT *data_size,
        void *data);

    HRESULT (STDMETHODCALLTYPE *GetParent)(
        IDXGIDeviceSubObject *This,
        REFIID riid,
        void **parent);

    /*** IDXGIDeviceSubObject methods ***/
    HRESULT (STDMETHODCALLTYPE *GetDevice)(
        IDXGIDeviceSubObject *This,
        REFIID riid,
        void **device);

    END_INTERFACE
} IDXGIDeviceSubObjectVtbl;

interface IDXGIDeviceSubObject {
    CONST_VTBL IDXGIDeviceSubObjectVtbl* lpVtbl;
};

#ifdef COBJMACROS
#ifndef WIDL_C_INLINE_WRAPPERS
/*** IUnknown methods ***/
#define IDXGIDeviceSubObject_QueryInterface(This,riid,object) (This)->lpVtbl->QueryInterface(This,riid,object)
#define IDXGIDeviceSubObject_AddRef(This) (This)->lpVtbl->AddRef(This)
#define IDXGIDeviceSubObject_Release(This) (This)->lpVtbl->Release(This)
/*** IDXGIObject methods ***/
#define IDXGIDeviceSubObject_SetPrivateData(This,name,data_size,data) (This)->lpVtbl->SetPrivateData(This,name,data_size,data)
#define IDXGIDeviceSubObject_GetPrivateDataInterface(This,name,unknown) (This)->lpVtbl->GetPrivateDataInterface(This,name,unknown)
#define IDXGIDeviceSubObject_GetPrivateData(This,name,data_size,data) (This)->lpVtbl->GetPrivateData(This,name,data_size,data)
#define IDXGIDeviceSubObject_GetParent(This,riid,parent) (This)->lpVtbl->GetParent(This,riid,parent)
/*** IDXGIDeviceSubObject methods ***/
#define IDXGIDeviceSubObject_GetDevice(This,riid,device) (This)->lpVtbl->GetDevice(This,riid,device)
#else
/*** IUnknown methods ***/
static FORCEINLINE HRESULT IDXGIDeviceSubObject_QueryInterface(IDXGIDeviceSubObject* This,REFIID riid,void **object) {
    return This->lpVtbl->QueryInterface(This,riid,object);
}
static FORCEINLINE ULONG IDXGIDeviceSubObject_AddRef(IDXGIDeviceSubObject* This) {
    return This->lpVtbl->AddRef(This);
}
static FORCEINLINE ULONG IDXGIDeviceSubObject_Release(IDXGIDeviceSubObject* This) {
    return This->lpVtbl->Release(This);
}
/*** IDXGIObject methods ***/
static FORCEINLINE HRESULT IDXGIDeviceSubObject_SetPrivateData(IDXGIDeviceSubObject* This,REFGUID name,UINT data_size,const void *data) {
    return This->lpVtbl->SetPrivateData(This,name,data_size,data);
}
static FORCEINLINE HRESULT IDXGIDeviceSubObject_GetPrivateDataInterface(IDXGIDeviceSubObject* This,REFGUID name,const IUnknown *unknown) {
    return This->lpVtbl->GetPrivateDataInterface(This,name,unknown);
}
static FORCEINLINE HRESULT IDXGIDeviceSubObject_GetPrivateData(IDXGIDeviceSubObject* This,REFGUID name,UINT *data_size,void *data) {
    return This->lpVtbl->GetPrivateData(This,name,data_size,data);
}
static FORCEINLINE HRESULT IDXGIDeviceSubObject_GetParent(IDXGIDeviceSubObject* This,REFIID riid,void **parent) {
    return This->lpVtbl->GetParent(This,riid,parent);
}
/*** IDXGIDeviceSubObject methods ***/
static FORCEINLINE HRESULT IDXGIDeviceSubObject_GetDevice(IDXGIDeviceSubObject* This,REFIID riid,void **device) {
    return This->lpVtbl->GetDevice(This,riid,device);
}
#endif
#endif

#endif


#endif  /* __IDXGIDeviceSubObject_INTERFACE_DEFINED__ */

/*****************************************************************************
 * IDXGISwapChain interface
 */
#ifndef __IDXGISwapChain_INTERFACE_DEFINED__
#define __IDXGISwapChain_INTERFACE_DEFINED__

DEFINE_GUID(IID_IDXGISwapChain, 0x310d36a0, 0xd2e7, 0x4c0a, 0xaa,0x04, 0x6a,0x9d,0x23,0xb8,0x88,0x6a);
#if defined(__cplusplus) && !defined(CINTERFACE)
MIDL_INTERFACE("310d36a0-d2e7-4c0a-aa04-6a9d23b8886a")
IDXGISwapChain : public IDXGIDeviceSubObject
{
    virtual HRESULT STDMETHODCALLTYPE Present(
        UINT sync_interval,
        UINT flags) = 0;

    virtual HRESULT STDMETHODCALLTYPE GetBuffer(
        UINT buffer_idx,
        REFIID riid,
        void **surface) = 0;

    virtual HRESULT STDMETHODCALLTYPE SetFullscreenState(
        BOOL fullscreen,
        IDXGIOutput *target) = 0;

    virtual HRESULT STDMETHODCALLTYPE GetFullscreenState(
        BOOL *fullscreen,
        IDXGIOutput **target) = 0;

    virtual HRESULT STDMETHODCALLTYPE GetDesc(
        DXGI_SWAP_CHAIN_DESC *desc) = 0;

    virtual HRESULT STDMETHODCALLTYPE ResizeBuffers(
        UINT buffer_count,
        UINT width,
        UINT height,
        DXGI_FORMAT format,
        UINT flags) = 0;

    virtual HRESULT STDMETHODCALLTYPE ResizeTarget(
        const DXGI_MODE_DESC *desc) = 0;

    virtual HRESULT STDMETHODCALLTYPE GetContainingOutput(
        IDXGIOutput **output) = 0;

    virtual HRESULT STDMETHODCALLTYPE GetFrameStatistics(
        DXGI_FRAME_STATISTICS *stats) = 0;

    virtual HRESULT STDMETHODCALLTYPE GetLastPresentCount(
        UINT *last_present_count) = 0;

};
#ifdef __CRT_UUID_DECL
__CRT_UUID_DECL(IDXGISwapChain, 0x310d36a0, 0xd2e7, 0x4c0a, 0xaa,0x04, 0x6a,0x9d,0x23,0xb8,0x88,0x6a)
#endif
#else
typedef struct IDXGISwapChainVtbl {
    BEGIN_INTERFACE

    /*** IUnknown methods ***/
    HRESULT (STDMETHODCALLTYPE *QueryInterface)(
        IDXGISwapChain *This,
        REFIID riid,
        void **object);

    ULONG (STDMETHODCALLTYPE *AddRef)(
        IDXGISwapChain *This);

    ULONG (STDMETHODCALLTYPE *Release)(
        IDXGISwapChain *This);

    /*** IDXGIObject methods ***/
    HRESULT (STDMETHODCALLTYPE *SetPrivateData)(
        IDXGISwapChain *This,
        REFGUID name,
        UINT data_size,
        const void *data);

    HRESULT (STDMETHODCALLTYPE *GetPrivateDataInterface)(
        IDXGISwapChain *This,
        REFGUID name,
        const IUnknown *unknown);

    HRESULT (STDMETHODCALLTYPE *GetPrivateData)(
        IDXGISwapChain *This,
        REFGUID name,
        UINT *data_size,
        void *data);

    HRESULT (STDMETHODCALLTYPE *GetParent)(
        IDXGISwapChain *This,
        REFIID riid,
        void **parent);

    /*** IDXGIDeviceSubObject methods ***/
    HRESULT (STDMETHODCALLTYPE *GetDevice)(
        IDXGISwapChain *This,
        REFIID riid,
        void **device);

    /*** IDXGISwapChain methods ***/
    HRESULT (STDMETHODCALLTYPE *Present)(
        IDXGISwapChain *This,
        UINT sync_interval,
        UINT flags);

    HRESULT (STDMETHODCALLTYPE *GetBuffer)(
        IDXGISwapChain *This,
        UINT buffer_idx,
        REFIID riid,
        void **surface);

    HRESULT (STDMETHODCALLTYPE *SetFullscreenState)(
        IDXGISwapChain *This,
        BOOL fullscreen,
        IDXGIOutput *target);

    HRESULT (STDMETHODCALLTYPE *GetFullscreenState)(
        IDXGISwapChain *This,
        BOOL *fullscreen,
        IDXGIOutput **target);

    HRESULT (STDMETHODCALLTYPE *GetDesc)(
        IDXGISwapChain *This,
        DXGI_SWAP_CHAIN_DESC *desc);

    HRESULT (STDMETHODCALLTYPE *ResizeBuffers)(
        IDXGISwapChain *This,
        UINT buffer_count,
        UINT width,
        UINT height,
        DXGI_FORMAT format,
        UINT flags);

    HRESULT (STDMETHODCALLTYPE *ResizeTarget)(
        IDXGISwapChain *This,
        const DXGI_MODE_DESC *desc);

    HRESULT (STDMETHODCALLTYPE *GetContainingOutput)(
        IDXGISwapChain *This,
        IDXGIOutput **output);

    HRESULT (STDMETHODCALLTYPE *GetFrameStatistics)(
        IDXGISwapChain *This,
        DXGI_FRAME_STATISTICS *stats);

    HRESULT (STDMETHODCALLTYPE *GetLastPresentCount)(
        IDXGISwapChain *This,
        UINT *last_present_count);

    END_INTERFACE
} IDXGISwapChainVtbl;

interface IDXGISwapChain {
    CONST_VTBL IDXGISwapChainVtbl* lpVtbl;
};

#ifdef COBJMACROS
#ifndef WIDL_C_INLINE_WRAPPERS
/*** IUnknown methods ***/
#define IDXGISwapChain_QueryInterface(This,riid,object) (This)->lpVtbl->QueryInterface(This,riid,object)
#define IDXGISwapChain_AddRef(This) (This)->lpVtbl->AddRef(This)
#define IDXGISwapChain_Release(This) (This)->lpVtbl->Release(This)
/*** IDXGIObject methods ***/
#define IDXGISwapChain_SetPrivateData(This,name,data_size,data) (This)->lpVtbl->SetPrivateData(This,name,data_size,data)
#define IDXGISwapChain_GetPrivateDataInterface(This,name,unknown) (This)->lpVtbl->GetPrivateDataInterface(This,name,unknown)
#define IDXGISwapChain_GetPrivateData(This,name,data_size,data) (This)->lpVtbl->GetPrivateData(This,name,data_size,data)
#define IDXGISwapChain_GetParent(This,riid,parent) (This)->lpVtbl->GetParent(This,riid,parent)
/*** IDXGIDeviceSubObject methods ***/
#define IDXGISwapChain_GetDevice(This,riid,device) (This)->lpVtbl->GetDevice(This,riid,device)
/*** IDXGISwapChain methods ***/
#define IDXGISwapChain_Present(This,sync_interval,flags) (This)->lpVtbl->Present(This,sync_interval,flags)
#define IDXGISwapChain_GetBuffer(This,buffer_idx,riid,surface) (This)->lpVtbl->GetBuffer(This,buffer_idx,riid,surface)
#define IDXGISwapChain_SetFullscreenState(This,fullscreen,target) (This)->lpVtbl->SetFullscreenState(This,fullscreen,target)
#define IDXGISwapChain_GetFullscreenState(This,fullscreen,target) (This)->lpVtbl->GetFullscreenState(This,fullscreen,target)
#define IDXGISwapChain_GetDesc(This,desc) (This)->lpVtbl->GetDesc(This,desc)
#define IDXGISwapChain_ResizeBuffers(This,buffer_count,width,height,format,flags) (This)->lpVtbl->ResizeBuffers(This,buffer_count,width,height,format,flags)
#define IDXGISwapChain_ResizeTarget(This,desc) (This)->lpVtbl->ResizeTarget(This,desc)
#define IDXGISwapChain_GetContainingOutput(This,output) (This)->lpVtbl->GetContainingOutput(This,output)
#define IDXGISwapChain_GetFrameStatistics(This,stats) (This)->lpVtbl->GetFrameStatistics(This,stats)
#define IDXGISwapChain_GetLastPresentCount(This,last_present_count) (This)->lpVtbl->GetLastPresentCount(This,last_present_count)
#else
/*** IUnknown methods ***/
static FORCEINLINE HRESULT IDXGISwapChain_QueryInterface(IDXGISwapChain* This,REFIID riid,void **object) {
    return This->lpVtbl->QueryInterface(This,riid,object);
}
static FORCEINLINE ULONG IDXGISwapChain_AddRef(IDXGISwapChain* This) {
    return This->lpVtbl->AddRef(This);
}
static FORCEINLINE ULONG IDXGISwapChain_Release(IDXGISwapChain* This) {
    return This->lpVtbl->Release(This);
}
/*** IDXGIObject methods ***/
static FORCEINLINE HRESULT IDXGISwapChain_SetPrivateData(IDXGISwapChain* This,REFGUID name,UINT data_size,const void *data) {
    return This->lpVtbl->SetPrivateData(This,name,data_size,data);
}
static FORCEINLINE HRESULT IDXGISwapChain_GetPrivateDataInterface(IDXGISwapChain* This,REFGUID name,const IUnknown *unknown) {
    return This->lpVtbl->GetPrivateDataInterface(This,name,unknown);
}
static FORCEINLINE HRESULT IDXGISwapChain_GetPrivateData(IDXGISwapChain* This,REFGUID name,UINT *data_size,void *data) {
    return This->lpVtbl->GetPrivateData(This,name,data_size,data);
}
static FORCEINLINE HRESULT IDXGISwapChain_GetParent(IDXGISwapChain* This,REFIID riid,void **parent) {
    return This->lpVtbl->GetParent(This,riid,parent);
}
/*** IDXGIDeviceSubObject methods ***/
static FORCEINLINE HRESULT IDXGISwapChain_GetDevice(IDXGISwapChain* This,REFIID riid,void **device) {
    return This->lpVtbl->GetDevice(This,riid,device);
}
/*** IDXGISwapChain methods ***/
static FORCEINLINE HRESULT IDXGISwapChain_Present(IDXGISwapChain* This,UINT sync_interval,UINT flags) {
    return This->lpVtbl->Present(This,sync_interval,flags);
}
static FORCEINLINE HRESULT IDXGISwapChain_GetBuffer(IDXGISwapChain* This,UINT buffer_idx,REFIID riid,void **surface) {
    return This->lpVtbl->GetBuffer(This,buffer_idx,riid,surface);
}
static FORCEINLINE HRESULT IDXGISwapChain_SetFullscreenState(IDXGISwapChain* This,BOOL fullscreen,IDXGIOutput *target) {
    return This->lpVtbl->SetFullscreenState(This,fullscreen,target);
}
static FORCEINLINE HRESULT IDXGISwapChain_GetFullscreenState(IDXGISwapChain* This,BOOL *fullscreen,IDXGIOutput **target) {
    return This->lpVtbl->GetFullscreenState(This,fullscreen,target);
}
static FORCEINLINE HRESULT IDXGISwapChain_GetDesc(IDXGISwapChain* This,DXGI_SWAP_CHAIN_DESC *desc) {
    return This->lpVtbl->GetDesc(This,desc);
}
static FORCEINLINE HRESULT IDXGISwapChain_ResizeBuffers(IDXGISwapChain* This,UINT buffer_count,UINT width,UINT height,DXGI_FORMAT format,UINT flags) {
    return This->lpVtbl->ResizeBuffers(This,buffer_count,width,height,format,flags);
}
static FORCEINLINE HRESULT IDXGISwapChain_ResizeTarget(IDXGISwapChain* This,const DXGI_MODE_DESC *desc) {
    return This->lpVtbl->ResizeTarget(This,desc);
}
static FORCEINLINE HRESULT IDXGISwapChain_GetContainingOutput(IDXGISwapChain* This,IDXGIOutput **output) {
    return This->lpVtbl->GetContainingOutput(This,output);
}
static FORCEINLINE HRESULT IDXGISwapChain_GetFrameStatistics(IDXGISwapChain* This,DXGI_FRAME_STATISTICS *stats) {
    return This->lpVtbl->GetFrameStatistics(This,stats);
}
static FORCEINLINE HRESULT IDXGISwapChain_GetLastPresentCount(IDXGISwapChain* This,UINT *last_present_count) {
    return This->lpVtbl->GetLastPresentCount(This,last_present_count);
}
#endif
#endif

#endif


#endif  /* __IDXGISwapChain_INTERFACE_DEFINED__ */

/*****************************************************************************
 * IDXGIFactory interface
 */
#ifndef __IDXGIFactory_INTERFACE_DEFINED__
#define __IDXGIFactory_INTERFACE_DEFINED__

DEFINE_GUID(IID_IDXGIFactory, 0x7b7166ec, 0x21c7, 0x44ae, 0xb2,0x1a, 0xc9,0xae,0x32,0x1a,0xe3,0x69);
#if defined(__cplusplus) && !defined(CINTERFACE)
MIDL_INTERFACE("7b7166ec-21c7-44ae-b21a-c9ae321ae369")
IDXGIFactory : public IDXGIObject
{
    virtual HRESULT STDMETHODCALLTYPE EnumAdapters(
        UINT adapter_idx,
        IDXGIAdapter **adapter) = 0;

    virtual HRESULT STDMETHODCALLTYPE MakeWindowAssociation(
        HWND hwnd,
        UINT flags) = 0;

    virtual HRESULT STDMETHODCALLTYPE GetWindowAssociation(
        HWND *hwnd) = 0;

    virtual HRESULT STDMETHODCALLTYPE CreateSwapChain(
        IUnknown *device,
        DXGI_SWAP_CHAIN_DESC *desc,
        IDXGISwapChain **swapchain) = 0;

    virtual HRESULT STDMETHODCALLTYPE CreateSoftwareAdapter(
        HMODULE hmodule,
        IDXGIAdapter **adapter) = 0;

};
#ifdef __CRT_UUID_DECL
__CRT_UUID_DECL(IDXGIFactory, 0x7b7166ec, 0x21c7, 0x44ae, 0xb2,0x1a, 0xc9,0xae,0x32,0x1a,0xe3,0x69)
#endif
#else
typedef struct IDXGIFactoryVtbl {
    BEGIN_INTERFACE

    /*** IUnknown methods ***/
    HRESULT (STDMETHODCALLTYPE *QueryInterface)(
        IDXGIFactory *This,
        REFIID riid,
        void **object);

    ULONG (STDMETHODCALLTYPE *AddRef)(
        IDXGIFactory *This);

    ULONG (STDMETHODCALLTYPE *Release)(
        IDXGIFactory *This);

    /*** IDXGIObject methods ***/
    HRESULT (STDMETHODCALLTYPE *SetPrivateData)(
        IDXGIFactory *This,
        REFGUID name,
        UINT data_size,
        const void *data);

    HRESULT (STDMETHODCALLTYPE *GetPrivateDataInterface)(
        IDXGIFactory *This,
        REFGUID name,
        const IUnknown *unknown);

    HRESULT (STDMETHODCALLTYPE *GetPrivateData)(
        IDXGIFactory *This,
        REFGUID name,
        UINT *data_size,
        void *data);

    HRESULT (STDMETHODCALLTYPE *GetParent)(
        IDXGIFactory *This,
        REFIID riid,
        void **parent);

    /*** IDXGIFactory methods ***/
    HRESULT (STDMETHODCALLTYPE *EnumAdapters)(
        IDXGIFactory *This,
        UINT adapter_idx,
        IDXGIAdapter **adapter);

    HRESULT (STDMETHODCALLTYPE *MakeWindowAssociation)(
        IDXGIFactory *This,
        HWND hwnd,
        UINT flags);

    HRESULT (STDMETHODCALLTYPE *GetWindowAssociation)(
        IDXGIFactory *This,
        HWND *hwnd);

    HRESULT (STDMETHODCALLTYPE *CreateSwapChain)(
        IDXGIFactory *This,
        IUnknown *device,
        DXGI_SWAP_CHAIN_DESC *desc,
        IDXGISwapChain **swapchain);

    HRESULT (STDMETHODCALLTYPE *CreateSoftwareAdapter)(
        IDXGIFactory *This,
        HMODULE hmodule,
        IDXGIAdapter **adapter);

    END_INTERFACE
} IDXGIFactoryVtbl;

interface IDXGIFactory {
    CONST_VTBL IDXGIFactoryVtbl* lpVtbl;
};

#ifdef COBJMACROS
#ifndef WIDL_C_INLINE_WRAPPERS
/*** IUnknown methods ***/
#define IDXGIFactory_QueryInterface(This,riid,object) (This)->lpVtbl->QueryInterface(This,riid,object)
#define IDXGIFactory_AddRef(This) (This)->lpVtbl->AddRef(This)
#define IDXGIFactory_Release(This) (This)->lpVtbl->Release(This)
/*** IDXGIObject methods ***/
#define IDXGIFactory_SetPrivateData(This,name,data_size,data) (This)->lpVtbl->SetPrivateData(This,name,data_size,data)
#define IDXGIFactory_GetPrivateDataInterface(This,name,unknown) (This)->lpVtbl->GetPrivateDataInterface(This,name,unknown)
#define IDXGIFactory_GetPrivateData(This,name,data_size,data) (This)->lpVtbl->GetPrivateData(This,name,data_size,data)
#define IDXGIFactory_GetParent(This,riid,parent) (This)->lpVtbl->GetParent(This,riid,parent)
/*** IDXGIFactory methods ***/
#define IDXGIFactory_EnumAdapters(This,adapter_idx,adapter) (This)->lpVtbl->EnumAdapters(This,adapter_idx,adapter)
#define IDXGIFactory_MakeWindowAssociation(This,hwnd,flags) (This)->lpVtbl->MakeWindowAssociation(This,hwnd,flags)
#define IDXGIFactory_GetWindowAssociation(This,hwnd) (This)->lpVtbl->GetWindowAssociation(This,hwnd)
#define IDXGIFactory_CreateSwapChain(This,device,desc,swapchain) (This)->lpVtbl->CreateSwapChain(This,device,desc,swapchain)
#define IDXGIFactory_CreateSoftwareAdapter(This,hmodule,adapter) (This)->lpVtbl->CreateSoftwareAdapter(This,hmodule,adapter)
#else
/*** IUnknown methods ***/
static FORCEINLINE HRESULT IDXGIFactory_QueryInterface(IDXGIFactory* This,REFIID riid,void **object) {
    return This->lpVtbl->QueryInterface(This,riid,object);
}
static FORCEINLINE ULONG IDXGIFactory_AddRef(IDXGIFactory* This) {
    return This->lpVtbl->AddRef(This);
}
static FORCEINLINE ULONG IDXGIFactory_Release(IDXGIFactory* This) {
    return This->lpVtbl->Release(This);
}
/*** IDXGIObject methods ***/
static FORCEINLINE HRESULT IDXGIFactory_SetPrivateData(IDXGIFactory* This,REFGUID name,UINT data_size,const void *data) {
    return This->lpVtbl->SetPrivateData(This,name,data_size,data);
}
static FORCEINLINE HRESULT IDXGIFactory_GetPrivateDataInterface(IDXGIFactory* This,REFGUID name,const IUnknown *unknown) {
    return This->lpVtbl->GetPrivateDataInterface(This,name,unknown);
}
static FORCEINLINE HRESULT IDXGIFactory_GetPrivateData(IDXGIFactory* This,REFGUID name,UINT *data_size,void *data) {
    return This->lpVtbl->GetPrivateData(This,name,data_size,data);
}
static FORCEINLINE HRESULT IDXGIFactory_GetParent(IDXGIFactory* This,REFIID riid,void **parent) {
    return This->lpVtbl->GetParent(This,riid,parent);
}
/*** IDXGIFactory methods ***/
static FORCEINLINE HRESULT IDXGIFactory_EnumAdapters(IDXGIFactory* This,UINT adapter_idx,IDXGIAdapter **adapter) {
    return This->lpVtbl->EnumAdapters(This,adapter_idx,adapter);
}
static FORCEINLINE HRESULT IDXGIFactory_MakeWindowAssociation(IDXGIFactory* This,HWND hwnd,UINT flags) {
    return This->lpVtbl->MakeWindowAssociation(This,hwnd,flags);
}
static FORCEINLINE HRESULT IDXGIFactory_GetWindowAssociation(IDXGIFactory* This,HWND *hwnd) {
    return This->lpVtbl->GetWindowAssociation(This,hwnd);
}
static FORCEINLINE HRESULT IDXGIFactory_CreateSwapChain(IDXGIFactory* This,IUnknown *device,DXGI_SWAP_CHAIN_DESC *desc,IDXGISwapChain **swapchain) {
    return This->lpVtbl->CreateSwapChain(This,device,desc,swapchain);
}
static FORCEINLINE HRESULT IDXGIFactory_CreateSoftwareAdapter(IDXGIFactory* This,HMODULE hmodule,IDXGIAdapter **adapter) {
    return This->lpVtbl->CreateSoftwareAdapter(This,hmodule,adapter);
}
#endif
#endif

#endif


#endif  /* __IDXGIFactory_INTERFACE_DEFINED__ */

/*****************************************************************************
 * IDXGIFactory1 interface
 */
#ifndef __IDXGIFactory1_INTERFACE_DEFINED__
#define __IDXGIFactory1_INTERFACE_DEFINED__

DEFINE_GUID(IID_IDXGIFactory1, 0x770aae78, 0xf26f, 0x4dba, 0xa8,0x29, 0x25,0x3c,0x83,0xd1,0xb3,0x87);
#if defined(__cplusplus) && !defined(CINTERFACE)
MIDL_INTERFACE("770aae78-f26f-4dba-a829-253c83d1b387")
IDXGIFactory1 : public IDXGIFactory
{
    virtual HRESULT STDMETHODCALLTYPE EnumAdapters1(
        UINT adapter_idx,
        IDXGIAdapter1 **adpter) = 0;

    virtual BOOL STDMETHODCALLTYPE IsCurrent(
        ) = 0;

};
#ifdef __CRT_UUID_DECL
__CRT_UUID_DECL(IDXGIFactory1, 0x770aae78, 0xf26f, 0x4dba, 0xa8,0x29, 0x25,0x3c,0x83,0xd1,0xb3,0x87)
#endif
#else
typedef struct IDXGIFactory1Vtbl {
    BEGIN_INTERFACE

    /*** IUnknown methods ***/
    HRESULT (STDMETHODCALLTYPE *QueryInterface)(
        IDXGIFactory1 *This,
        REFIID riid,
        void **object);

    ULONG (STDMETHODCALLTYPE *AddRef)(
        IDXGIFactory1 *This);

    ULONG (STDMETHODCALLTYPE *Release)(
        IDXGIFactory1 *This);

    /*** IDXGIObject methods ***/
    HRESULT (STDMETHODCALLTYPE *SetPrivateData)(
        IDXGIFactory1 *This,
        REFGUID name,
        UINT data_size,
        const void *data);

    HRESULT (STDMETHODCALLTYPE *GetPrivateDataInterface)(
        IDXGIFactory1 *This,
        REFGUID name,
        const IUnknown *unknown);

    HRESULT (STDMETHODCALLTYPE *GetPrivateData)(
        IDXGIFactory1 *This,
        REFGUID name,
        UINT *data_size,
        void *data);

    HRESULT (STDMETHODCALLTYPE *GetParent)(
        IDXGIFactory1 *This,
        REFIID riid,
        void **parent);

    /*** IDXGIFactory methods ***/
    HRESULT (STDMETHODCALLTYPE *EnumAdapters)(
        IDXGIFactory1 *This,
        UINT adapter_idx,
        IDXGIAdapter **adapter);

    HRESULT (STDMETHODCALLTYPE *MakeWindowAssociation)(
        IDXGIFactory1 *This,
        HWND hwnd,
        UINT flags);

    HRESULT (STDMETHODCALLTYPE *GetWindowAssociation)(
        IDXGIFactory1 *This,
        HWND *hwnd);

    HRESULT (STDMETHODCALLTYPE *CreateSwapChain)(
        IDXGIFactory1 *This,
        IUnknown *device,
        DXGI_SWAP_CHAIN_DESC *desc,
        IDXGISwapChain **swapchain);

    HRESULT (STDMETHODCALLTYPE *CreateSoftwareAdapter)(
        IDXGIFactory1 *This,
        HMODULE hmodule,
        IDXGIAdapter **adapter);

    /*** IDXGIFactory1 methods ***/
    HRESULT (STDMETHODCALLTYPE *EnumAdapters1)(
        IDXGIFactory1 *This,
        UINT adapter_idx,
        IDXGIAdapter1 **adpter);

    BOOL (STDMETHODCALLTYPE *IsCurrent)(
        IDXGIFactory1 *This);

    END_INTERFACE
} IDXGIFactory1Vtbl;

interface IDXGIFactory1 {
    CONST_VTBL IDXGIFactory1Vtbl* lpVtbl;
};

#ifdef COBJMACROS
#ifndef WIDL_C_INLINE_WRAPPERS
/*** IUnknown methods ***/
#define IDXGIFactory1_QueryInterface(This,riid,object) (This)->lpVtbl->QueryInterface(This,riid,object)
#define IDXGIFactory1_AddRef(This) (This)->lpVtbl->AddRef(This)
#define IDXGIFactory1_Release(This) (This)->lpVtbl->Release(This)
/*** IDXGIObject methods ***/
#define IDXGIFactory1_SetPrivateData(This,name,data_size,data) (This)->lpVtbl->SetPrivateData(This,name,data_size,data)
#define IDXGIFactory1_GetPrivateDataInterface(This,name,unknown) (This)->lpVtbl->GetPrivateDataInterface(This,name,unknown)
#define IDXGIFactory1_GetPrivateData(This,name,data_size,data) (This)->lpVtbl->GetPrivateData(This,name,data_size,data)
#define IDXGIFactory1_GetParent(This,riid,parent) (This)->lpVtbl->GetParent(This,riid,parent)
/*** IDXGIFactory methods ***/
#define IDXGIFactory1_EnumAdapters(This,adapter_idx,adapter) (This)->lpVtbl->EnumAdapters(This,adapter_idx,adapter)
#define IDXGIFactory1_MakeWindowAssociation(This,hwnd,flags) (This)->lpVtbl->MakeWindowAssociation(This,hwnd,flags)
#define IDXGIFactory1_GetWindowAssociation(This,hwnd) (This)->lpVtbl->GetWindowAssociation(This,hwnd)
#define IDXGIFactory1_CreateSwapChain(This,device,desc,swapchain) (This)->lpVtbl->CreateSwapChain(This,device,desc,swapchain)
#define IDXGIFactory1_CreateSoftwareAdapter(This,hmodule,adapter) (This)->lpVtbl->CreateSoftwareAdapter(This,hmodule,adapter)
/*** IDXGIFactory1 methods ***/
#define IDXGIFactory1_EnumAdapters1(This,adapter_idx,adpter) (This)->lpVtbl->EnumAdapters1(This,adapter_idx,adpter)
#define IDXGIFactory1_IsCurrent(This) (This)->lpVtbl->IsCurrent(This)
#else
/*** IUnknown methods ***/
static FORCEINLINE HRESULT IDXGIFactory1_QueryInterface(IDXGIFactory1* This,REFIID riid,void **object) {
    return This->lpVtbl->QueryInterface(This,riid,object);
}
static FORCEINLINE ULONG IDXGIFactory1_AddRef(IDXGIFactory1* This) {
    return This->lpVtbl->AddRef(This);
}
static FORCEINLINE ULONG IDXGIFactory1_Release(IDXGIFactory1* This) {
    return This->lpVtbl->Release(This);
}
/*** IDXGIObject methods ***/
static FORCEINLINE HRESULT IDXGIFactory1_SetPrivateData(IDXGIFactory1* This,REFGUID name,UINT data_size,const void *data) {
    return This->lpVtbl->SetPrivateData(This,name,data_size,data);
}
static FORCEINLINE HRESULT IDXGIFactory1_GetPrivateDataInterface(IDXGIFactory1* This,REFGUID name,const IUnknown *unknown) {
    return This->lpVtbl->GetPrivateDataInterface(This,name,unknown);
}
static FORCEINLINE HRESULT IDXGIFactory1_GetPrivateData(IDXGIFactory1* This,REFGUID name,UINT *data_size,void *data) {
    return This->lpVtbl->GetPrivateData(This,name,data_size,data);
}
static FORCEINLINE HRESULT IDXGIFactory1_GetParent(IDXGIFactory1* This,REFIID riid,void **parent) {
    return This->lpVtbl->GetParent(This,riid,parent);
}
/*** IDXGIFactory methods ***/
static FORCEINLINE HRESULT IDXGIFactory1_EnumAdapters(IDXGIFactory1* This,UINT adapter_idx,IDXGIAdapter **adapter) {
    return This->lpVtbl->EnumAdapters(This,adapter_idx,adapter);
}
static FORCEINLINE HRESULT IDXGIFactory1_MakeWindowAssociation(IDXGIFactory1* This,HWND hwnd,UINT flags) {
    return This->lpVtbl->MakeWindowAssociation(This,hwnd,flags);
}
static FORCEINLINE HRESULT IDXGIFactory1_GetWindowAssociation(IDXGIFactory1* This,HWND *hwnd) {
    return This->lpVtbl->GetWindowAssociation(This,hwnd);
}
static FORCEINLINE HRESULT IDXGIFactory1_CreateSwapChain(IDXGIFactory1* This,IUnknown *device,DXGI_SWAP_CHAIN_DESC *desc,IDXGISwapChain **swapchain) {
    return This->lpVtbl->CreateSwapChain(This,device,desc,swapchain);
}
static FORCEINLINE HRESULT IDXGIFactory1_CreateSoftwareAdapter(IDXGIFactory1* This,HMODULE hmodule,IDXGIAdapter **adapter) {
    return This->lpVtbl->CreateSoftwareAdapter(This,hmodule,adapter);
}
/*** IDXGIFactory1 methods ***/
static FORCEINLINE HRESULT IDXGIFactory1_EnumAdapters1(IDXGIFactory1* This,UINT adapter_idx,IDXGIAdapter1 **adpter) {
    return This->lpVtbl->EnumAdapters1(This,adapter_idx,adpter);
}
static FORCEINLINE BOOL IDXGIFactory1_IsCurrent(IDXGIFactory1* This) {
    return This->lpVtbl->IsCurrent(This);
}
#endif
#endif

#endif


#endif  /* __IDXGIFactory1_INTERFACE_DEFINED__ */

HRESULT __stdcall  CreateDXGIFactory(REFIID riid,void **factory);

HRESULT __stdcall  CreateDXGIFactory1(REFIID riid,void **factory);

/* Begin additional prototypes for all interfaces */


/* End additional prototypes */

#ifdef __cplusplus
}
#endif

#endif /* __vkd3d_dxgi_h__ */

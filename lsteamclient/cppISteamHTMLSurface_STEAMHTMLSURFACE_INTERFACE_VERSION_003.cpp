#include "steam_defs.h"
#include "steamworks_sdk_140/steam_api.h"
#include "steamclient_private.h"
#include "cppISteamHTMLSurface_STEAMHTMLSURFACE_INTERFACE_VERSION_003.h"
#ifdef __cplusplus
extern "C" {
#endif
#include "struct_converters_140.h"
bool cppISteamHTMLSurface_STEAMHTMLSURFACE_INTERFACE_VERSION_003_Init(void *linux_side)
{
    return ((ISteamHTMLSurface*)linux_side)->Init();
}

bool cppISteamHTMLSurface_STEAMHTMLSURFACE_INTERFACE_VERSION_003_Shutdown(void *linux_side)
{
    return ((ISteamHTMLSurface*)linux_side)->Shutdown();
}

SteamAPICall_t cppISteamHTMLSurface_STEAMHTMLSURFACE_INTERFACE_VERSION_003_CreateBrowser(void *linux_side, const char * pchUserAgent, const char * pchUserCSS)
{
    return ((ISteamHTMLSurface*)linux_side)->CreateBrowser((const char *)pchUserAgent, (const char *)pchUserCSS);
}

void cppISteamHTMLSurface_STEAMHTMLSURFACE_INTERFACE_VERSION_003_RemoveBrowser(void *linux_side, HHTMLBrowser unBrowserHandle)
{
    ((ISteamHTMLSurface*)linux_side)->RemoveBrowser((HHTMLBrowser)unBrowserHandle);
}

void cppISteamHTMLSurface_STEAMHTMLSURFACE_INTERFACE_VERSION_003_LoadURL(void *linux_side, HHTMLBrowser unBrowserHandle, const char * pchURL, const char * pchPostData)
{
    ((ISteamHTMLSurface*)linux_side)->LoadURL((HHTMLBrowser)unBrowserHandle, (const char *)pchURL, (const char *)pchPostData);
}

void cppISteamHTMLSurface_STEAMHTMLSURFACE_INTERFACE_VERSION_003_SetSize(void *linux_side, HHTMLBrowser unBrowserHandle, uint32 unWidth, uint32 unHeight)
{
    ((ISteamHTMLSurface*)linux_side)->SetSize((HHTMLBrowser)unBrowserHandle, (uint32)unWidth, (uint32)unHeight);
}

void cppISteamHTMLSurface_STEAMHTMLSURFACE_INTERFACE_VERSION_003_StopLoad(void *linux_side, HHTMLBrowser unBrowserHandle)
{
    ((ISteamHTMLSurface*)linux_side)->StopLoad((HHTMLBrowser)unBrowserHandle);
}

void cppISteamHTMLSurface_STEAMHTMLSURFACE_INTERFACE_VERSION_003_Reload(void *linux_side, HHTMLBrowser unBrowserHandle)
{
    ((ISteamHTMLSurface*)linux_side)->Reload((HHTMLBrowser)unBrowserHandle);
}

void cppISteamHTMLSurface_STEAMHTMLSURFACE_INTERFACE_VERSION_003_GoBack(void *linux_side, HHTMLBrowser unBrowserHandle)
{
    ((ISteamHTMLSurface*)linux_side)->GoBack((HHTMLBrowser)unBrowserHandle);
}

void cppISteamHTMLSurface_STEAMHTMLSURFACE_INTERFACE_VERSION_003_GoForward(void *linux_side, HHTMLBrowser unBrowserHandle)
{
    ((ISteamHTMLSurface*)linux_side)->GoForward((HHTMLBrowser)unBrowserHandle);
}

void cppISteamHTMLSurface_STEAMHTMLSURFACE_INTERFACE_VERSION_003_AddHeader(void *linux_side, HHTMLBrowser unBrowserHandle, const char * pchKey, const char * pchValue)
{
    ((ISteamHTMLSurface*)linux_side)->AddHeader((HHTMLBrowser)unBrowserHandle, (const char *)pchKey, (const char *)pchValue);
}

void cppISteamHTMLSurface_STEAMHTMLSURFACE_INTERFACE_VERSION_003_ExecuteJavascript(void *linux_side, HHTMLBrowser unBrowserHandle, const char * pchScript)
{
    ((ISteamHTMLSurface*)linux_side)->ExecuteJavascript((HHTMLBrowser)unBrowserHandle, (const char *)pchScript);
}

void cppISteamHTMLSurface_STEAMHTMLSURFACE_INTERFACE_VERSION_003_MouseUp(void *linux_side, HHTMLBrowser unBrowserHandle, EHTMLMouseButton eMouseButton)
{
    ((ISteamHTMLSurface*)linux_side)->MouseUp((HHTMLBrowser)unBrowserHandle, (ISteamHTMLSurface::EHTMLMouseButton)eMouseButton);
}

void cppISteamHTMLSurface_STEAMHTMLSURFACE_INTERFACE_VERSION_003_MouseDown(void *linux_side, HHTMLBrowser unBrowserHandle, EHTMLMouseButton eMouseButton)
{
    ((ISteamHTMLSurface*)linux_side)->MouseDown((HHTMLBrowser)unBrowserHandle, (ISteamHTMLSurface::EHTMLMouseButton)eMouseButton);
}

void cppISteamHTMLSurface_STEAMHTMLSURFACE_INTERFACE_VERSION_003_MouseDoubleClick(void *linux_side, HHTMLBrowser unBrowserHandle, EHTMLMouseButton eMouseButton)
{
    ((ISteamHTMLSurface*)linux_side)->MouseDoubleClick((HHTMLBrowser)unBrowserHandle, (ISteamHTMLSurface::EHTMLMouseButton)eMouseButton);
}

void cppISteamHTMLSurface_STEAMHTMLSURFACE_INTERFACE_VERSION_003_MouseMove(void *linux_side, HHTMLBrowser unBrowserHandle, int x, int y)
{
    ((ISteamHTMLSurface*)linux_side)->MouseMove((HHTMLBrowser)unBrowserHandle, (int)x, (int)y);
}

void cppISteamHTMLSurface_STEAMHTMLSURFACE_INTERFACE_VERSION_003_MouseWheel(void *linux_side, HHTMLBrowser unBrowserHandle, int32 nDelta)
{
    ((ISteamHTMLSurface*)linux_side)->MouseWheel((HHTMLBrowser)unBrowserHandle, (int32)nDelta);
}

void cppISteamHTMLSurface_STEAMHTMLSURFACE_INTERFACE_VERSION_003_KeyDown(void *linux_side, HHTMLBrowser unBrowserHandle, uint32 nNativeKeyCode, EHTMLKeyModifiers eHTMLKeyModifiers)
{
    ((ISteamHTMLSurface*)linux_side)->KeyDown((HHTMLBrowser)unBrowserHandle, (uint32)nNativeKeyCode, (ISteamHTMLSurface::EHTMLKeyModifiers)eHTMLKeyModifiers);
}

void cppISteamHTMLSurface_STEAMHTMLSURFACE_INTERFACE_VERSION_003_KeyUp(void *linux_side, HHTMLBrowser unBrowserHandle, uint32 nNativeKeyCode, EHTMLKeyModifiers eHTMLKeyModifiers)
{
    ((ISteamHTMLSurface*)linux_side)->KeyUp((HHTMLBrowser)unBrowserHandle, (uint32)nNativeKeyCode, (ISteamHTMLSurface::EHTMLKeyModifiers)eHTMLKeyModifiers);
}

void cppISteamHTMLSurface_STEAMHTMLSURFACE_INTERFACE_VERSION_003_KeyChar(void *linux_side, HHTMLBrowser unBrowserHandle, uint32 cUnicodeChar, EHTMLKeyModifiers eHTMLKeyModifiers)
{
    ((ISteamHTMLSurface*)linux_side)->KeyChar((HHTMLBrowser)unBrowserHandle, (uint32)cUnicodeChar, (ISteamHTMLSurface::EHTMLKeyModifiers)eHTMLKeyModifiers);
}

void cppISteamHTMLSurface_STEAMHTMLSURFACE_INTERFACE_VERSION_003_SetHorizontalScroll(void *linux_side, HHTMLBrowser unBrowserHandle, uint32 nAbsolutePixelScroll)
{
    ((ISteamHTMLSurface*)linux_side)->SetHorizontalScroll((HHTMLBrowser)unBrowserHandle, (uint32)nAbsolutePixelScroll);
}

void cppISteamHTMLSurface_STEAMHTMLSURFACE_INTERFACE_VERSION_003_SetVerticalScroll(void *linux_side, HHTMLBrowser unBrowserHandle, uint32 nAbsolutePixelScroll)
{
    ((ISteamHTMLSurface*)linux_side)->SetVerticalScroll((HHTMLBrowser)unBrowserHandle, (uint32)nAbsolutePixelScroll);
}

void cppISteamHTMLSurface_STEAMHTMLSURFACE_INTERFACE_VERSION_003_SetKeyFocus(void *linux_side, HHTMLBrowser unBrowserHandle, bool bHasKeyFocus)
{
    ((ISteamHTMLSurface*)linux_side)->SetKeyFocus((HHTMLBrowser)unBrowserHandle, (bool)bHasKeyFocus);
}

void cppISteamHTMLSurface_STEAMHTMLSURFACE_INTERFACE_VERSION_003_ViewSource(void *linux_side, HHTMLBrowser unBrowserHandle)
{
    ((ISteamHTMLSurface*)linux_side)->ViewSource((HHTMLBrowser)unBrowserHandle);
}

void cppISteamHTMLSurface_STEAMHTMLSURFACE_INTERFACE_VERSION_003_CopyToClipboard(void *linux_side, HHTMLBrowser unBrowserHandle)
{
    ((ISteamHTMLSurface*)linux_side)->CopyToClipboard((HHTMLBrowser)unBrowserHandle);
}

void cppISteamHTMLSurface_STEAMHTMLSURFACE_INTERFACE_VERSION_003_PasteFromClipboard(void *linux_side, HHTMLBrowser unBrowserHandle)
{
    ((ISteamHTMLSurface*)linux_side)->PasteFromClipboard((HHTMLBrowser)unBrowserHandle);
}

void cppISteamHTMLSurface_STEAMHTMLSURFACE_INTERFACE_VERSION_003_Find(void *linux_side, HHTMLBrowser unBrowserHandle, const char * pchSearchStr, bool bCurrentlyInFind, bool bReverse)
{
    ((ISteamHTMLSurface*)linux_side)->Find((HHTMLBrowser)unBrowserHandle, (const char *)pchSearchStr, (bool)bCurrentlyInFind, (bool)bReverse);
}

void cppISteamHTMLSurface_STEAMHTMLSURFACE_INTERFACE_VERSION_003_StopFind(void *linux_side, HHTMLBrowser unBrowserHandle)
{
    ((ISteamHTMLSurface*)linux_side)->StopFind((HHTMLBrowser)unBrowserHandle);
}

void cppISteamHTMLSurface_STEAMHTMLSURFACE_INTERFACE_VERSION_003_GetLinkAtPosition(void *linux_side, HHTMLBrowser unBrowserHandle, int x, int y)
{
    ((ISteamHTMLSurface*)linux_side)->GetLinkAtPosition((HHTMLBrowser)unBrowserHandle, (int)x, (int)y);
}

void cppISteamHTMLSurface_STEAMHTMLSURFACE_INTERFACE_VERSION_003_SetCookie(void *linux_side, const char * pchHostname, const char * pchKey, const char * pchValue, const char * pchPath, RTime32 nExpires, bool bSecure, bool bHTTPOnly)
{
    ((ISteamHTMLSurface*)linux_side)->SetCookie((const char *)pchHostname, (const char *)pchKey, (const char *)pchValue, (const char *)pchPath, (RTime32)nExpires, (bool)bSecure, (bool)bHTTPOnly);
}

void cppISteamHTMLSurface_STEAMHTMLSURFACE_INTERFACE_VERSION_003_SetPageScaleFactor(void *linux_side, HHTMLBrowser unBrowserHandle, float flZoom, int nPointX, int nPointY)
{
    ((ISteamHTMLSurface*)linux_side)->SetPageScaleFactor((HHTMLBrowser)unBrowserHandle, (float)flZoom, (int)nPointX, (int)nPointY);
}

void cppISteamHTMLSurface_STEAMHTMLSURFACE_INTERFACE_VERSION_003_SetBackgroundMode(void *linux_side, HHTMLBrowser unBrowserHandle, bool bBackgroundMode)
{
    ((ISteamHTMLSurface*)linux_side)->SetBackgroundMode((HHTMLBrowser)unBrowserHandle, (bool)bBackgroundMode);
}

void cppISteamHTMLSurface_STEAMHTMLSURFACE_INTERFACE_VERSION_003_AllowStartRequest(void *linux_side, HHTMLBrowser unBrowserHandle, bool bAllowed)
{
    ((ISteamHTMLSurface*)linux_side)->AllowStartRequest((HHTMLBrowser)unBrowserHandle, (bool)bAllowed);
}

void cppISteamHTMLSurface_STEAMHTMLSURFACE_INTERFACE_VERSION_003_JSDialogResponse(void *linux_side, HHTMLBrowser unBrowserHandle, bool bResult)
{
    ((ISteamHTMLSurface*)linux_side)->JSDialogResponse((HHTMLBrowser)unBrowserHandle, (bool)bResult);
}

void cppISteamHTMLSurface_STEAMHTMLSURFACE_INTERFACE_VERSION_003_FileLoadDialogResponse(void *linux_side, HHTMLBrowser unBrowserHandle, const char ** pchSelectedFiles)
{
    ((ISteamHTMLSurface*)linux_side)->FileLoadDialogResponse((HHTMLBrowser)unBrowserHandle, (const char **)pchSelectedFiles);
}

#ifdef __cplusplus
}
#endif

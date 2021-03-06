#ifdef __cplusplus
extern "C" {
#endif
extern HSteamPipe cppISteamClient_SteamClient008_CreateSteamPipe(void *);
extern bool cppISteamClient_SteamClient008_BReleaseSteamPipe(void *, HSteamPipe);
extern HSteamUser cppISteamClient_SteamClient008_ConnectToGlobalUser(void *, HSteamPipe);
extern HSteamUser cppISteamClient_SteamClient008_CreateLocalUser(void *, HSteamPipe *, EAccountType);
extern void cppISteamClient_SteamClient008_ReleaseUser(void *, HSteamPipe, HSteamUser);
extern void *cppISteamClient_SteamClient008_GetISteamUser(void *, HSteamUser, HSteamPipe, const char *);
extern void *cppISteamClient_SteamClient008_GetISteamGameServer(void *, HSteamUser, HSteamPipe, const char *);
extern void cppISteamClient_SteamClient008_SetLocalIPBinding(void *, uint32, uint16);
extern void *cppISteamClient_SteamClient008_GetISteamFriends(void *, HSteamUser, HSteamPipe, const char *);
extern void *cppISteamClient_SteamClient008_GetISteamUtils(void *, HSteamPipe, const char *);
extern void *cppISteamClient_SteamClient008_GetISteamMatchmaking(void *, HSteamUser, HSteamPipe, const char *);
extern void *cppISteamClient_SteamClient008_GetISteamMasterServerUpdater(void *, HSteamUser, HSteamPipe, const char *);
extern void *cppISteamClient_SteamClient008_GetISteamMatchmakingServers(void *, HSteamUser, HSteamPipe, const char *);
extern void * cppISteamClient_SteamClient008_GetISteamGenericInterface(void *, HSteamUser, HSteamPipe, const char *);
extern void *cppISteamClient_SteamClient008_GetISteamUserStats(void *, HSteamUser, HSteamPipe, const char *);
extern void *cppISteamClient_SteamClient008_GetISteamApps(void *, HSteamUser, HSteamPipe, const char *);
extern void *cppISteamClient_SteamClient008_GetISteamNetworking(void *, HSteamUser, HSteamPipe, const char *);
extern void *cppISteamClient_SteamClient008_GetISteamRemoteStorage(void *, HSteamUser, HSteamPipe, const char *);
extern void cppISteamClient_SteamClient008_RunFrame(void *);
extern uint32 cppISteamClient_SteamClient008_GetIPCCallCount(void *);
extern void cppISteamClient_SteamClient008_SetWarningMessageHook(void *, SteamAPIWarningMessageHook_t);
#ifdef __cplusplus
}
#endif

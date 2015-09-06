// Niclas Schad, Loic Fernau, Tim Zachow

#pragma once

#include "Object.h"
#include "S42PhotonListener.h"
#include "S42PhotonBaseHandler.h"
#include "S42PhotonClient.generated.h"

/**
 * 
 */
UCLASS()
class SPERRGEBIET42_API US42PhotonClient : public UObject
{
	GENERATED_BODY()
public:

	US42PhotonClient(const FObjectInitializer& ObjectInitializer);

	virtual void PostInitProperties() override;

	void PhotonConnect(FString ServerAddress, FString ApplicationName);

	void PhotonDisconnect();

	void PhotonCallServer(bool bDispatchIncomingCommands);

	void PhotonOperationRequest(nByte OperationCode, TMap<int, FString> Parameters);

	void PhotonSetConnectionState(bool bPhotonConnected, bool bPhotonConnecting);

	void PhotonSetCurrentHandler(US42PhotonBaseHandler* Handler);

	int PhotonGetPeerState();

	bool PhotonGetIsConnecting();

	bool PhotonGetIsConnected();

private:
	
	bool bPhotonIsConnecting = false;
	bool bPhotonIsConnected = false;

	S42PhotonListener* Listener;
	PhotonPeer* Peer;
};

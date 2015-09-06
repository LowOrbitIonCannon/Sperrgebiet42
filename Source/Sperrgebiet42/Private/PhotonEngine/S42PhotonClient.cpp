// Niclas Schad, Loic Fernau, Tim Zachow

#include "Sperrgebiet42.h"
#include "S42PhotonClient.h"




US42PhotonClient::US42PhotonClient(const FObjectInitializer& ObjectInitializer)
	:Super(ObjectInitializer)
{

}

void US42PhotonClient::PostInitProperties()
{
	Super::PostInitProperties();
	Listener = new S42PhotonListener();

	if (!Listener)
	{
		UE_LOG(S42Net, Error, TEXT("Photon Listener could not be created"));
	}

	Peer = new PhotonPeer(*Listener, ConnectionProtocol::UDP);

	if (!Peer)
	{
		UE_LOG(S42Net, Error, TEXT("Photon Peer could not be created"));
	}

}

void US42PhotonClient::PhotonConnect(FString ServerAddress, FString ApplicationName)
{
	if (Peer)
	{
		bPhotonIsConnecting = Peer->connect(*ServerAddress, reinterpret_cast<nByte*>(TCHAR_TO_UTF8(*ApplicationName)));
	}
}

void US42PhotonClient::PhotonDisconnect()
{
	if (Peer && bPhotonIsConnected)
	{
		Peer->disconnect();
	}
}

void US42PhotonClient::PhotonCallServer(bool bDispatchIncomingCommands)
{
	if (Peer && (bPhotonIsConnected || bPhotonIsConnecting))
	{
		Peer->service(bDispatchIncomingCommands);
	}
}

void US42PhotonClient::PhotonOperationRequest(nByte OperationCode, TMap<int, FString> Parameters)
{
	OperationRequestParameters parameters;

	for (auto It = Parameters.CreateConstIterator(); It; ++It)
	{
		parameters.put(It.Key(), ValueObject<JString>(*It.Value()));
	}

	OperationRequest request(OperationCode, parameters);

	Peer->opCustom(request, true, 0, false);

}

void US42PhotonClient::PhotonSetConnectionState(bool bPhotonConnected, bool bPhotonConnecting)
{
	bPhotonIsConnecting = bPhotonConnecting;
	bPhotonIsConnected = bPhotonConnected;
}

void US42PhotonClient::PhotonSetCurrentHandler(US42PhotonBaseHandler* Handler)
{
	if (Handler && Handler->IsValidLowLevelFast(true))
	{
		Listener->setCurrentHandler(Handler);
	}
}

int US42PhotonClient::PhotonGetPeerState()
{
	if (Peer)
	{
		return Peer->getPeerState();
	}

	return NULL;
}

bool US42PhotonClient::PhotonGetIsConnecting()
{
	return bPhotonIsConnecting;
}

bool US42PhotonClient::PhotonGetIsConnected()
{
	return bPhotonIsConnected;
}

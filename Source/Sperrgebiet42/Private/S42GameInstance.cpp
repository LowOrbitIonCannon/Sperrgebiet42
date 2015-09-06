// Niclas Schad, Loic Fernau, Tim Zachow

#include "Sperrgebiet42.h"
#include "S42GameInstance.h"




void US42GameInstance::Init()
{
	PhotonClient = NewObject<US42PhotonClient>();
	
	if (PhotonClient && PhotonClient->IsValidLowLevelFast(true))
	{
		PhotonClient->PhotonConnect(ServerAddress, ApplicationName);
	}

	Super::Init();
}

void US42GameInstance::Shutdown()
{
	Super::Shutdown();
}

void US42GameInstance::PhotonCallService(bool bDispatchIncomingCommands)
{
	if (PhotonClient && PhotonClient->IsValidLowLevelFast(true))
	{
		PhotonClient->PhotonCallServer(bDispatchIncomingCommands);
	}
}

void US42GameInstance::PhotonSetConnectionState(bool bConnecting, bool bConnected)
{
	if (PhotonClient && PhotonClient->IsValidLowLevelFast(true))
	{
		PhotonClient->PhotonSetConnectionState(bConnecting, bConnected);
	}
}

void US42GameInstance::PhotonSetCurrentHandler(US42PhotonBaseHandler* Handler)
{
	if (Handler && Handler->IsValidLowLevelFast(true))
	{
		PhotonClient->PhotonSetCurrentHandler(Handler);
	}
}

bool US42GameInstance::PhotonGetPhotonIsConnecting()
{
	return PhotonClient->PhotonGetIsConnecting();
}

bool US42GameInstance::PhotonGetPhotonIsConnected()
{
	return PhotonClient->PhotonGetIsConnected();
}

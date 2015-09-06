// Niclas Schad, Loic Fernau, Tim Zachow

#pragma once

#include "Engine/GameInstance.h"
#include "S42PhotonClient.h"
#include "S42PhotonBaseHandler.h"
#include "S42GameInstance.generated.h"

/**
 * 
 */
UCLASS()
class SPERRGEBIET42_API US42GameInstance : public UGameInstance
{
	GENERATED_BODY()
	
public:

	virtual void Init() override;

	virtual void Shutdown() override;

	void PhotonCallService(bool bDispatchIncomingCommands);

	void PhotonSetConnectionState(bool bConnecting, bool bConnected);

	void PhotonSetCurrentHandler(US42PhotonBaseHandler* Handler);

	bool PhotonGetPhotonIsConnecting();

	bool PhotonGetPhotonIsConnected();

private:
	UPROPERTY()
		US42PhotonClient* PhotonClient;
	UPROPERTY()
		FString ServerAddress = "127.0.0.1:5055";
	UPROPERTY()
		FString ApplicationName = "MasterServer";
	
	
	
};

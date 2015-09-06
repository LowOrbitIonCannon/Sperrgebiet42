// Niclas Schad, Loic Fernau, Tim Zachow

#pragma once

#include "Components/ActorComponent.h"
#include "PhotonImport.h"
#include "S42PhotonBaseHandler.generated.h"

using namespace ExitGames::Common;
using namespace ExitGames::Photon;

UCLASS( ClassGroup=(Custom), meta=(BlueprintSpawnableComponent) )
class SPERRGEBIET42_API US42PhotonBaseHandler : public UActorComponent
{
	GENERATED_BODY()

public:	
	// Sets default values for this component's properties
	US42PhotonBaseHandler(const FObjectInitializer& ObjectInitializer);

	virtual void HandleOnOperationResponse(const OperationResponse& operationResponse);

	virtual void HandleOnStatusChanged(int statusCode);

	virtual void HandleOnEvent(const EventData& eventData);

	virtual void HandleDebugReturn(int debugLevel, const JString& string);
	
};

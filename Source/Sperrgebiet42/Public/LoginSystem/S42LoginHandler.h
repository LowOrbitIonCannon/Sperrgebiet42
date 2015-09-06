// Niclas Schad, Loic Fernau, Tim Zachow

#pragma once

#include "PhotonEngine/S42PhotonBaseHandler.h"
#include "S42GameInstance.h"
#include "S42LoginHandler.generated.h"

/**
 * 
 */
UCLASS(ClassGroup = (Custom), meta = (BlueprintSpawnableComponent))
class SPERRGEBIET42_API US42LoginHandler : public US42PhotonBaseHandler
{
	GENERATED_BODY()
	
public:

	virtual void InitializeComponent();

	virtual void HandleOnOperationResponse(const OperationResponse& operationResponse) override;

	virtual void HandleOnStatusChanged(int statusCode) override;

	virtual void HandleOnEvent(const EventData& eventData) override;

	virtual void HandleDebugReturn(int debugLevel, const JString& string) override;

	UPROPERTY()
		US42GameInstance* S42GameInstance;
	
	
};

// Niclas Schad, Loic Fernau, Tim Zachow

#include "Sperrgebiet42.h"
#include "S42LoginHandler.h"




void US42LoginHandler::InitializeComponent()
{
	S42GameInstance = Cast<US42GameInstance>(this->GetOwner()->GetGameInstance());

	S42GameInstance->PhotonSetCurrentHandler(this);

	Super::InitializeComponent();
}

void US42LoginHandler::HandleOnOperationResponse(const OperationResponse& operationResponse)
{
	//TODO: Implement later on
}

void US42LoginHandler::HandleOnStatusChanged(int statusCode)
{
	Super::HandleOnStatusChanged(statusCode);
}

void US42LoginHandler::HandleOnEvent(const EventData& eventData)
{
	//TODO: Implement later on
}

void US42LoginHandler::HandleDebugReturn(int debugLevel, const JString& string)
{
	Super::HandleDebugReturn(debugLevel, string);
}

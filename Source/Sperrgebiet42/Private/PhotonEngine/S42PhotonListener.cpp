// Niclas Schad, Loic Fernau, Tim Zachow

#include "Sperrgebiet42.h"
#include "S42PhotonListener.h"

S42PhotonListener::S42PhotonListener()
{
}

void S42PhotonListener::onOperationResponse(const OperationResponse& operationResponse)
{
	if (CurrentHandler && CurrentHandler->IsValidLowLevelFast(true))
	{
		CurrentHandler->HandleOnOperationResponse(operationResponse);
	}
}

void S42PhotonListener::onStatusChanged(int statusCode)
{
	if (CurrentHandler && CurrentHandler->IsValidLowLevelFast(true))
	{
		CurrentHandler->HandleOnStatusChanged(statusCode);
	}
}

void S42PhotonListener::onEvent(const EventData& eventData)
{
	if (CurrentHandler && CurrentHandler->IsValidLowLevelFast(true))
	{
		CurrentHandler->HandleOnEvent(eventData);
	}
}

void S42PhotonListener::debugReturn(int debugLevel, const JString& string)
{
	if (CurrentHandler && CurrentHandler->IsValidLowLevelFast(true))
	{
		CurrentHandler->HandleDebugReturn(debugLevel, string);
	}
}

void S42PhotonListener::setCurrentHandler(US42PhotonBaseHandler* Handler)
{
	if (Handler && Handler->IsValidLowLevelFast(true))
	{
		CurrentHandler = Handler;
	}
}

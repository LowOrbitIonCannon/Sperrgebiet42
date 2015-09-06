// Niclas Schad, Loic Fernau, Tim Zachow

#pragma once

#include "S42PhotonBaseHandler.h"
#include "PhotonImport.h"

using namespace ExitGames::Common;
using namespace ExitGames::Photon;


/**
 * 
 */
class S42PhotonListener : public PhotonListener
{
public:
	S42PhotonListener();

	virtual void onOperationResponse(const OperationResponse& operationResponse) override;

	virtual void onStatusChanged(int statusCode) override;

	virtual void onEvent(const EventData& eventData) override;

	virtual void debugReturn(int debugLevel, const JString& string) override;

	void setCurrentHandler(US42PhotonBaseHandler* Handler);

private:
	UPROPERTY()
	US42PhotonBaseHandler* CurrentHandler;

};

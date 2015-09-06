// Niclas Schad, Loic Fernau, Tim Zachow

#include "Sperrgebiet42.h"
#include "S42PhotonBaseHandler.h"
#include "S42GameInstance.h"

US42PhotonBaseHandler::US42PhotonBaseHandler(const FObjectInitializer& ObjectInitializer)
	:Super(ObjectInitializer)
{
	bWantsInitializeComponent = true;
	bWantsBeginPlay = true;
	bAutoActivate = true;
	bAutoRegister = true;
	PrimaryComponentTick.bCanEverTick = false;
}

void US42PhotonBaseHandler::HandleOnOperationResponse(const OperationResponse& operationResponse)
{
	//This will be implemented in the specific handler
}

void US42PhotonBaseHandler::HandleOnStatusChanged(int statusCode)
{
	switch (statusCode)
	{
		case StatusCode::EXCEPTION_ON_CONNECT:
		{
			//PhotonSetConnectionState(bool bConnected, bool bConnecting)
			Cast<US42GameInstance>(GetWorld()->GetGameInstance())->PhotonSetConnectionState(false, false);
			UE_LOG(S42Net, Error, TEXT("The PhotonPeer excountered an exception connecting to the server. Perhaps server down!"));
			if (GEngine)
			{
				GEngine->AddOnScreenDebugMessage(-1, 5.f, FColor::Red, TEXT("The PhotonPeer excountered an exception connecting to the server. Perhaps server down!"));
			}
		} break;
		case StatusCode::CONNECT:
		{
			Cast<US42GameInstance>(GetWorld()->GetGameInstance())->PhotonSetConnectionState(true, false);
			UE_LOG(S42Net, Log, TEXT("The PhotonPeer is connected to the Server."));
			if (GEngine)
			{
				GEngine->AddOnScreenDebugMessage(-1, 5.f, FColor::Green, TEXT("The PhotonPeer is connected to the Server."));
			}
		} break;
		case StatusCode::DISCONNECT:
		{
			Cast<US42GameInstance>(GetWorld()->GetGameInstance())->PhotonSetConnectionState(false, false);
			UE_LOG(S42Net, Log, TEXT("The PhotonPeer just disconnected from the Server."));
			if (GEngine)
			{
				GEngine->AddOnScreenDebugMessage(-1, 5.f, FColor::Yellow, TEXT("The PhotonPeer just disconnected from the Server."));
			}
		} break;
		case StatusCode::EXCEPTION:
		{
			//Cast<US42GameInstance>(GetWorld()->GetGameInstance())->PhotonSetConnectionState(false, false);
			UE_LOG(S42Net, Error, TEXT("The PhotonPeer encountered an exception and will disconnect!"));
			if (GEngine)
			{
				GEngine->AddOnScreenDebugMessage(-1, 5.f, FColor::Red, TEXT("The PhotonPeer encountered an exception and will disconnect!"));
			}
		} break;
		case StatusCode::QUEUE_OUTGOING_ACKS_WARNING:
		{
			//Cast<US42GameInstance>(GetWorld()->GetGameInstance())->PhotonSetConnectionState(false, false);
			UE_LOG(S42Net, Warning, TEXT("The PhotonPeer outgoing acks queue is filling up - call service more often."));
			if (GEngine)
			{
				GEngine->AddOnScreenDebugMessage(-1, 5.f, FColor::Yellow, TEXT("The PhotonPeer outgoing acks queue is filling up - call service more often."));
			}
		} break;
		case StatusCode::QUEUE_INCOMING_RELIABLE_WARNING:
		{
			//Cast<US42GameInstance>(GetWorld()->GetGameInstance())->PhotonSetConnectionState(false, false);
			UE_LOG(S42Net, Warning, TEXT("The PhotonPeer incoming reliable queue is filling up - call service more often."));
			if (GEngine)
			{
				GEngine->AddOnScreenDebugMessage(-1, 5.f, FColor::Yellow, TEXT("The PhotonPeer incoming reliable queue is filling up - call service more often."));
			}
		} break;
		case StatusCode::QUEUE_INCOMING_UNRELIABLE_WARNING:
		{
			//Cast<US42GameInstance>(GetWorld()->GetGameInstance())->PhotonSetConnectionState(false, false);
			UE_LOG(S42Net, Warning, TEXT("The PhotonPeer incoming unreliable queue is filling up - call service more often."));
			if (GEngine)
			{
				GEngine->AddOnScreenDebugMessage(-1, 5.f, FColor::Yellow, TEXT("The PhotonPeer incoming unreliable queue is filling up - call service more often."));
			}
		} break;
		case StatusCode::QUEUE_SENT_WARNING:
		{
			//Cast<US42GameInstance>(GetWorld()->GetGameInstance())->PhotonSetConnectionState(false, false);
			UE_LOG(S42Net, Warning, TEXT("The PhotonPeer's sent queue is filling up. Check why the server does not send acks for reliable commands"));
			if (GEngine)
			{
				GEngine->AddOnScreenDebugMessage(-1, 5.f, FColor::Yellow, TEXT("The PhotonPeer's sent queue is filling up. Check why the server does not send acks for reliable commands"));
			}
		} break;
		case StatusCode::SEND_ERROR:
		{
			//Cast<US42GameInstance>(GetWorld()->GetGameInstance())->PhotonSetConnectionState(false, false);
			UE_LOG(S42Net, Error, TEXT("Sending command failed. Either not connected, or the requested channel is bigger than the number of initialiazed channels"));
			if (GEngine)
			{
				GEngine->AddOnScreenDebugMessage(-1, 5.f, FColor::Red, TEXT("Sending command failed. Either not connected, or the requested channel is bigger than the number of initialiazed channels"));
			}
		} break;
		case StatusCode::INTERNAL_RECEIVE_EXCEPTION:
		{
			//Cast<US42GameInstance>(GetWorld()->GetGameInstance())->PhotonSetConnectionState(false, false);
			UE_LOG(S42Net, Warning, TEXT("Exception, if a Server cannot be connected. The Server does not respond. Try again later."));
			if (GEngine)
			{
				GEngine->AddOnScreenDebugMessage(-1, 5.f, FColor::Yellow, TEXT("Exception, if a Server cannot be connected. The Server does not respond. Try again later."));
			}
		} break;
		case StatusCode::TIMEOUT_DISCONNECT:
		{
			Cast<US42GameInstance>(GetWorld()->GetGameInstance())->PhotonSetConnectionState(false, false);
			UE_LOG(S42Net, Warning, TEXT("Disconnected due to a timeout (client receives no longer acks from the server)!"));
			if (GEngine)
			{
				GEngine->AddOnScreenDebugMessage(-1, 5.f, FColor::Yellow, TEXT("Disconnected due to a timeout (client receives no longer acks from the server)!"));
			}
		} break;
		case StatusCode::DISCONNECT_BY_SERVER:
		{
			Cast<US42GameInstance>(GetWorld()->GetGameInstance())->PhotonSetConnectionState(false, false);
			UE_LOG(S42Net, Warning, TEXT("Disconnected due to a timeout (received a disconnect command from the server. Server missed acks from the client)!"));
			if (GEngine)
			{
				GEngine->AddOnScreenDebugMessage(-1, 5.f, FColor::Yellow, TEXT("Disconnected due to a timeout (received a disconnect command from the server. Server missed acks from the client)!"));
			}
		} break;
		case StatusCode::DISCONNECT_BY_SERVER_LOGIC:
		{
			Cast<US42GameInstance>(GetWorld()->GetGameInstance())->PhotonSetConnectionState(false, false);
			UE_LOG(S42Net, Warning, TEXT("Disconnected by server logic - received a disconnect command."));
			if (GEngine)
			{
				GEngine->AddOnScreenDebugMessage(-1, 5.f, FColor::Yellow, TEXT("Disconnected by server logic - received a disconnect command."));
			}
		} break;
		case StatusCode::DISCONNECT_BY_SERVER_USER_LIMIT:
		{
			Cast<US42GameInstance>(GetWorld()->GetGameInstance())->PhotonSetConnectionState(false, false);
			UE_LOG(S42Net, Warning, TEXT("Disconnect due to server user limit reached."));
			if (GEngine)
			{
				GEngine->AddOnScreenDebugMessage(-1, 5.f, FColor::Yellow, TEXT("Disconnect due to server user limit reached."));
			}
		} break;
		case StatusCode::ENCRYPTION_ESTABLISHED:
		{
			//Cast<US42GameInstance>(GetWorld()->GetGameInstance())->PhotonSetConnectionState(false, false);
			UE_LOG(S42Net, Log, TEXT("The encryption system setup successfully."));
			if (GEngine)
			{
				GEngine->AddOnScreenDebugMessage(-1, 5.f, FColor::Green, TEXT("The encryption system setup successfully."));
			}
		} break;
		case StatusCode::ENCRYPTION_FAILED_TO_ESTABLISH:
		{
			//Cast<US42GameInstance>(GetWorld()->GetGameInstance())->PhotonSetConnectionState(false, false);
			UE_LOG(S42Net, Error, TEXT("The encryption system has not setup successfully."));
			if (GEngine)
			{
				GEngine->AddOnScreenDebugMessage(-1, 5.f, FColor::Red, TEXT("The encryption system has not setup successfully."));
			}
		} break;

	}
}

void US42PhotonBaseHandler::HandleOnEvent(const EventData& eventData)
{
	//This will be implemented in the specific handler
}

void US42PhotonBaseHandler::HandleDebugReturn(int debugLevel, const JString& string)
{
#if defined(UE_BUILD_DEBUG) || defined(UE_BUILD_DEVELOPMENT)
	switch (debugLevel)
	{
	case DebugLevel::ERRORS: UE_LOG(S42Net, Error, TEXT("Received DebugMessage from the Server: %s"), string.cstr()); break;
	case DebugLevel::WARNINGS: UE_LOG(S42Net, Warning, TEXT("Received DebugMessage from the Server: %s"), string.cstr()); break;
	case DebugLevel::INFO: UE_LOG(S42Net, Log, TEXT("Received DebugMessage from the Server: %s"), string.cstr()); break;
	case DebugLevel::ALL: UE_LOG(S42Net, Log, TEXT("Received DebugMessage from the Server: %s"), string.cstr()); break;
	}
#endif
}

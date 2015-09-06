// Niclas Schad, Loic Fernau, Tim Zachow

#include "Sperrgebiet42.h"
#include "S42LoginController.h"



// Sets default values
AS42LoginController::AS42LoginController(const FObjectInitializer& ObjectInitializer)
	:Super(ObjectInitializer)
{
 	// Set this actor to call Tick() every frame.  You can turn this off to improve performance if you don't need it.
	PrimaryActorTick.bCanEverTick = false;

}

// Called when the game starts or when spawned
void AS42LoginController::BeginPlay()
{
	Super::BeginPlay();

	UWorld* World = GetWorld();
	
	if (World)
	{
		S42GameInstance = Cast<US42GameInstance>(World->GetGameInstance());
	}

	FTimerHandle LoginControllerTimerHandle;

	GetWorldTimerManager().SetTimer(LoginControllerTimerHandle, this, &AS42LoginController::PhotonService, 1.0f, true);


	
}

// Called every frame
void AS42LoginController::Tick( float DeltaTime )
{
	Super::Tick( DeltaTime );

}

void AS42LoginController::PhotonService()
{
	if (S42GameInstance)
	{
		if (S42GameInstance->PhotonGetPhotonIsConnected() || S42GameInstance->PhotonGetPhotonIsConnecting())
		{
			S42GameInstance->PhotonCallService(true);
		}
	}
	
}


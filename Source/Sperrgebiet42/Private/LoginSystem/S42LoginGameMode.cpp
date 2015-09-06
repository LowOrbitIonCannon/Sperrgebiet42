// Niclas Schad, Loic Fernau, Tim Zachow

#include "Sperrgebiet42.h"
#include "S42LoginGameMode.h"




void AS42LoginGameMode::InitGame(const FString& MapName, const FString& Options, FString& ErrorMessage)
{
	Super::InitGame(MapName, Options, ErrorMessage);
}

void AS42LoginGameMode::BeginPlay()
{
	Super::BeginPlay();

	UWorld* World = GetWorld();

	if (World)
	{
		if (World->GetMapName().Contains("LoginMap"))
		{
			Controller = World->SpawnActor<AS42LoginController>(AS42LoginController::StaticClass());
			Handler = NewObject<US42LoginHandler>(Controller, "LoginHandler");
			Handler->RegisterComponent();
		}
		else
		{
			UE_LOG(S42, Error, TEXT("Startup map not correct: %s"), *World->GetMapName());
		}
	}
}

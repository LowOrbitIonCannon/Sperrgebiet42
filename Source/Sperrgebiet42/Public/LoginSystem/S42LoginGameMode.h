// Niclas Schad, Loic Fernau, Tim Zachow

#pragma once

#include "GameFramework/GameMode.h"
#include "S42LoginController.h"
#include "S42LoginHandler.h"
#include "S42LoginGameMode.generated.h"

/**
 * 
 */
UCLASS()
class SPERRGEBIET42_API AS42LoginGameMode : public AGameMode
{
	GENERATED_BODY()
	
public:

	virtual void InitGame(const FString& MapName, const FString& Options, FString& ErrorMessage) override;

	virtual void BeginPlay() override;

	UPROPERTY()
		AS42LoginController* Controller;
	UPROPERTY()
		US42LoginHandler* Handler;
	
	
};

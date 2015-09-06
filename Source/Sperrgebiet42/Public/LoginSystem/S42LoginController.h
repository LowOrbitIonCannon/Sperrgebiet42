// Niclas Schad, Loic Fernau, Tim Zachow

#pragma once

#include "GameFramework/Actor.h"
#include "S42GameInstance.h"
#include "S42LoginHandler.h"
#include "S42LoginController.generated.h"

UCLASS()
class SPERRGEBIET42_API AS42LoginController : public AActor
{
	GENERATED_BODY()
	
public:	
	// Sets default values for this actor's properties
	AS42LoginController(const FObjectInitializer& ObjectInitializer);

	// Called when the game starts or when spawned
	virtual void BeginPlay() override;
	
	// Called every frame
	virtual void Tick( float DeltaSeconds ) override;

	void PhotonService();

	US42GameInstance* S42GameInstance;

	
	
};

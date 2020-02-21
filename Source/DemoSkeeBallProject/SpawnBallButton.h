// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "VRBase/AWorldButton/AWorldButton.h"
#include "Components/StaticMeshComponent.h"
#include "SpawnBallButton.generated.h"

/**
 * 
 */
UCLASS()
class DEMOSKEEBALLPROJECT_API ASpawnBallButton : public AWorldButton
{
	GENERATED_BODY()

	UPROPERTY(EditAnywhere)
	UStaticMeshComponent* m_pSpawnLocationMesh;
	
public:
	ASpawnBallButton();

	virtual void OnPressed_Implementation(ABaseController*) override;
	
	
};

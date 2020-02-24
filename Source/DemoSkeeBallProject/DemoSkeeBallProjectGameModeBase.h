// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "GameFramework/GameModeBase.h"
#include "DemoSkeeBallProjectGameModeBase.generated.h"

/**
 * 
 */
UCLASS()
class DEMOSKEEBALLPROJECT_API ADemoSkeeBallProjectGameModeBase : public AGameModeBase
{
	GENERATED_BODY()

private:
public:
	ADemoSkeeBallProjectGameModeBase();

	int m_iScore;
	int m_iWinScore;
	bool m_bHasPlayerWon;

	void BeginPlay() override;

	UFUNCTION(BlueprintCallable)
	int GetScore();
	UFUNCTION(BlueprintCallable)
	void SetScore(int newScore);	
	
};

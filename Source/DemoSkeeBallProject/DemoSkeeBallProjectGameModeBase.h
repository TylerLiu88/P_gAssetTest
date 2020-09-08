// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "GameFramework/GameModeBase.h"
#include "System/EHandle.h"
#include "DemoSkeeBallProjectGameModeBase.generated.h"

/**
 * 
 */
UCLASS()
class DEMOSKEEBALLPROJECT_API ADemoSkeeBallProjectGameModeBase : public AGameModeBase
{
	GENERATED_BODY()
	
private:
	//Represents the players score
	int m_iScore;
	

public:

	ADemoSkeeBallProjectGameModeBase();

	void BeginPlay() override;

	//Score to win
	int m_iWinScore;
	
	//SkeeBall Object Pool
	TArray<EHANDLE> m_aESkeeBalls;

	//C++ Macro to allow use of Blueprints
	UFUNCTION(BlueprintCallable)
	int GetScore();

	UFUNCTION(BlueprintCallable)
	void SetScore(int newScore);
	
	
};

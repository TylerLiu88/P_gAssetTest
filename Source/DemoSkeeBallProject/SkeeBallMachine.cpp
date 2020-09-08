// Fill out your copyright notice in the Description page of Project Settings.

#include "SkeeBallMachine.h"
#include "DemoSkeeBallProjectGameModeBase.h"
#include "System/NLogger.h"

ASkeeBallMachine::ASkeeBallMachine() {

	//Construct the Component
	m_pStaticMeshComponent = CreateDefaultSubobject<UStaticMeshComponent>("static mesh");

	//Set Static mesh to be the root component
	RootComponent = m_pStaticMeshComponent;

	//Find mesh
	UStaticMesh* mesh = FindMesh("StaticMesh'/Game/Meshes/SkeeBallMachine.SkeeBallMachine'");

	//Set mesh
	m_pStaticMeshComponent->SetStaticMesh(mesh);

	//Scale SkeeBallMachine
	float scaleFactor = 1.5f; 
	FVector scale = FVector(scaleFactor);
	m_pStaticMeshComponent->SetWorldScale3D(scale);

	//Set to false 
	m_bHasPlayerWon = false;


}

//Add Points function
void ASkeeBallMachine::AddToScore(int points) {

	//Cast GameModeBase to SkeeBallMachine
	ADemoSkeeBallProjectGameModeBase* mode = Cast<ADemoSkeeBallProjectGameModeBase>(GetWorld()->GetAuthGameMode());

	if (mode) {

		//Get the Current Score
		int currScore = mode->GetScore();

		//Add Score (Current Score and points passed in)
		mode->SetScore(currScore + points);

		//The player wins
		//If get score is equal to or greater than win condition
		m_bHasPlayerWon = (mode->GetScore() >= mode->m_iWinScore);
	}



}

void ASkeeBallMachine::DefaultThink() {

	if (m_bHasPlayerWon) {
		Msg("You won!");
	}


}


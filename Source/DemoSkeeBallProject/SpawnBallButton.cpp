// Fill out your copyright notice in the Description page of Project Settings.

#include "SpawnBallButton.h"
//#include "SkeeBall.h"
//#include "DemoSkeeBallProjectGameModeBase.h"

//Max SkeeBall Constant
#define MAX_SKEEBALLS 12


ASpawnBallButton::ASpawnBallButton() {

	//GO AND FIX MESHES OF THE TWO

	/*
	This is the Mesh for the ball spawning location	
	*/

	//Create mesh for component
	m_pSpawnLocationMesh = CreateDefaultSubobject<UStaticMeshComponent>("location mesh");

	//Find mesh
	UStaticMesh* mesh = FindMesh("StaticMesh'/Game/Meshes/SkeeBall.SkeeBall'");
	//Set Mesh
	m_pSpawnLocationMesh->SetStaticMesh(mesh);

	/*
	This will be the mesh for the Button
	*/
	UStaticMesh* buttonMesh = FindMesh("StaticMesh'/Game/StarterContent/Shapes/Shape_Cylinder.Shape_Cylinder'");

	m_pMeshComponent->SetStaticMesh(buttonMesh);



	/*
	Scaling of the button
	*/

	//Scale SkeeBallButton
	float scaleFactor = 0.3f;
	FVector scale = FVector(scaleFactor);
	m_pMeshComponent->SetWorldScale3D(scale);
	m_pSpawnLocationMesh->SetWorldScale3D(scale);

	//Set the tracking index 
	m_iSkeeBallsIndex = 0;
}

void ASpawnBallButton::OnPressed_Implementation(ABaseController* pController) {

	//Get the ball position from GameMode
	 gameMode = Cast<ADemoSkeeBallProjectGameModeBase>(GetWorld()->GetAuthGameMode());
	
	//Note: Location is a vector, so the return type will be type FVector
	//Get location of the 
	FVector loc = m_pSpawnLocationMesh->GetComponentLocation();

	//Using Unreal GetWorld Function: It gets a pointer reference to the world as an object
	//Then we can use SpawnActor to spawn at that point
	//SpawnActor takes a class reference and a location
	//Its better to store actor into variable. C++ Cast not Unreal
	
	//skeeball = (ASkeeBall*)GetWorld()->SpawnActor(ASkeeBall::StaticClass(), &loc);


	//**START OF POOL, SHOULD I MAKE SEPARATE FUNCTIONS?

	/*Check array for how many balls currently
	Use gameMode for this and the Num() function from TArray
	https://docs.unrealengine.com/en-US/Programming/UnrealArchitecture/TArrays/index.html
	*/

	 //if current balls is less than max, keep spawning 
	 if (gameMode->m_aESkeeBalls.Num() < MAX_SKEEBALLS) {

		skeeball = (ASkeeBall*)GetWorld()->SpawnActor(ASkeeBall::StaticClass(), &loc);

		//Add to array
		gameMode->m_aESkeeBalls.Add(skeeball->GetEHandle());

		
		//Add counter here and it crashes
		//Originally assumed that we need to update counter
		//m_iSkeeBallsIndex++;
	 }
	 else {

		 //Should I remove? I know its better to recycle according to different docs online.
		 //If I recycle, how do I update the counter? Do I reset it back to 0? I'll do that, 
		 //but for feedback could you let me know what to do lol, thank you! -> DELETE LATER
		 //Oh wait, Im stupid, if i recycle, i will always have MAX in it, so no need to reset.

		 //https://docs.unrealengine.com/en-US/API/Runtime/Engine/GameFramework/AActor/SetActorLocation/index.html
		 //Get skeeball actors and set them at spawn
		 gameMode->m_aESkeeBalls[m_iSkeeBallsIndex]->GetActor()->SetActorLocation(loc);

		
		 //Add here and it works fine, but not sure if its recycling? or have correct index
		 m_iSkeeBallsIndex++;

	 }







}
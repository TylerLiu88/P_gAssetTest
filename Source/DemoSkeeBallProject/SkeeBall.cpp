// Fill out your copyright notice in the Description page of Project Settings.

#include "SkeeBall.h"
#include "Components/PrimitiveComponent.h"

ASkeeBall::ASkeeBall() {

	//Construct the component
	m_pPickupMeshComponent = CreateDefaultSubobject<UStaticMeshComponent>("static mesh");
	//Set root component
	RootComponent = m_pPickupMeshComponent;

	//Find mesh
	UStaticMesh* mesh = FindMesh("StaticMesh'/Game/Meshes/SkeeBall.skeeball'");
	//Set Mesh
	m_pPickupMeshComponent->SetStaticMesh(mesh);

	//Scale the Skeeball
	float scaleFactor = 0.2f;
	FVector scale = FVector(scaleFactor);
	m_pPickupMeshComponent->SetWorldScale3D(scale);

}




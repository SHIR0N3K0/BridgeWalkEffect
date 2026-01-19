// Fill out your copyright notice in the Description page of Project Settings.


#include "RoadChunckManager.h"
#include "GeometryCollection/GeometryCollectionComponent.h"

ARoadChunckManager::ARoadChunckManager()
{
	PrimaryActorTick.bCanEverTick = false; // Tick pas nécessaire pour l'instant
}

void ARoadChunckManager::BeginPlay()
{
	Super::BeginPlay();

	// Tu peux appeler ici directement l'initialisation ou laisser BP l'appeler
	// InitializeChunkTransforms();
}

void ARoadChunckManager::InitializeChunkTransforms()
{
	if (!GCComp)
	{
		UE_LOG(LogTemp, Warning, TEXT("GCComp non assigné !"));
		return;
	}

	WorldChunkTransforms.Empty();

	// 1️⃣ Récupère les transforms locaux des chunks
	TArray<FTransform> LocalTransforms = GCComp->GetLocalRestTransforms(true);

	// 2️⃣ Transform du composant pour passer en monde
	FTransform CompTM = GCComp->GetComponentTransform();

	// 3️⃣ Conversion en espace monde
	for (const FTransform& LocalT : LocalTransforms)
	{
		FTransform WorldT = LocalT * CompTM;
		WorldChunkTransforms.Add(WorldT);
	}

	UE_LOG(LogTemp, Log, TEXT("Initialized %d chunk transforms"), WorldChunkTransforms.Num());
}
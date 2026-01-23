// RoadChunckManager.cpp
#include "RoadChunckManager.h"
#include "GeometryCollection/GeometryCollectionComponent.h"

ARoadChunckManager::ARoadChunckManager()
{
	PrimaryActorTick.bCanEverTick = false; // We don't need tick for now
}

void ARoadChunckManager::BeginPlay()
{
	Super::BeginPlay();

	// Call manually from BP or here
	// InitializeChunkTransforms();
}

void ARoadChunckManager::InitializeChunkTransforms()
{
	if (!GCComp)
	{
		UE_LOG(LogTemp, Warning, TEXT("GCComp not assigned!"));
		return;
	}

	WorldChunkTransformMap.Empty();

	// Get all local transforms
	// NOTE: GetLocalRestTransforms(true) is real and returns TArray<FTransform>
	TArray<FTransform> LocalTransforms = GCComp->GetLocalRestTransforms(true);

	if (LocalTransforms.Num() == 0)
	{
		UE_LOG(LogTemp, Warning, TEXT("GCComp has no Level 1 bones!"));
		return;
	}

	FTransform CompTransform = GCComp->GetComponentTransform();

	// Loop through Level 1 bones (skip root at index 0)
	for (int32 BoneIndex = 1; BoneIndex < LocalTransforms.Num(); ++BoneIndex)
	{
		// Local transform relative to parent/root
		const FTransform& LocalT = LocalTransforms[BoneIndex];

		// Multiply by component transform to get world transform
		FTransform WorldT = LocalT * CompTransform;

		WorldChunkTransformMap.Add(BoneIndex, WorldT);
	}

	UE_LOG(LogTemp, Log, TEXT("Initialized %d chunk transforms"), WorldChunkTransformMap.Num());
}

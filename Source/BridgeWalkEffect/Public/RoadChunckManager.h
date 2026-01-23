// RoadChunckManager.h
#pragma once

#include "CoreMinimal.h"
#include "GameFramework/Actor.h"
#include "GeometryCollection/GeometryCollectionComponent.h"
#include "RoadChunckManager.generated.h"

UCLASS()
class BRIDGEWALKEFFECT_API ARoadChunckManager : public AActor
{
	GENERATED_BODY()

public:
	ARoadChunckManager();

	virtual void BeginPlay() override;

	/** Geometry Collection Component to read */
	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category="Chunks")
	UGeometryCollectionComponent* GCComp;

	/** World transform of each chunk, index = bone index */
	UPROPERTY(BlueprintReadOnly, Category="Chunks")
	TMap<int32, FTransform> WorldChunkTransformMap;

	/** Initialize chunk transforms in world space */
	UFUNCTION(BlueprintCallable, Category="Chunks")
	void InitializeChunkTransforms();
};

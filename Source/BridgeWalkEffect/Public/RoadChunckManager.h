// Fill out your copyright notice in the Description page of Project Settings.

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

	/** Component Geometry Collection à lire */
	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category="Chunks")
	UGeometryCollectionComponent* GCComp;

	/** Transform final de chaque chunk dans le monde */
	UPROPERTY(BlueprintReadOnly, Category="Chunks")
	TArray<FTransform> WorldChunkTransforms;

	/** Fonction à appeler pour initialiser les transforms */
	UFUNCTION(BlueprintCallable, Category="Chunks")
	void InitializeChunkTransforms();

};

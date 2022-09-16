// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "GameFramework/Actor.h"
#include "BalanceObstacle.generated.h"

UCLASS()
class CASTINGANDANIMATIONS_API ABalanceObstacle : public AActor
{
	GENERATED_BODY()
	
public:	
	// Sets default values for this actor's properties
	ABalanceObstacle();
	UPROPERTY(EditAnywhere , BlueprintReadWrite)
	class UStaticMeshComponent* StaticMesh;
	UPROPERTY(EditAnywhere , BlueprintReadWrite)
	class USphereComponent* Sphere;
};

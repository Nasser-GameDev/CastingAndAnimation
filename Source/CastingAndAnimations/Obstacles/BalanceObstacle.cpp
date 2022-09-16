// Fill out your copyright notice in the Description page of Project Settings.


#include "BalanceObstacle.h"
#include "Components/StaticMeshComponent.h"
#include "Components/SphereComponent.h"
// Sets default values
ABalanceObstacle::ABalanceObstacle()
{
 	// Set this actor to call Tick() every frame.  You can turn this off to improve performance if you don't need it.
	PrimaryActorTick.bCanEverTick = false;

	StaticMesh = CreateDefaultSubobject<UStaticMeshComponent>(TEXT("My Static Mesh"));
	Sphere = CreateDefaultSubobject<USphereComponent>(TEXT("My Sphere Component"));

	StaticMesh->SetupAttachment(RootComponent);
	Sphere->InitSphereRadius(150.0f);
	Sphere->SetupAttachment(StaticMesh);
}




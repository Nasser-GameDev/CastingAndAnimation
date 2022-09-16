// Fill out your copyright notice in the Description page of Project Settings.


#include "WorkerCharacter.h"
#include "GameFramework/SpringArmComponent.h" // since we use a spring arm 
#include "Camera/CameraComponent.h" // To adjust our camera viewport
#include "Components/CapsuleComponent.h" // to use the capsule component in the Character class

#include "../Obstacles/FlippingObstacle.h"
#include "../Obstacles/BalanceObstacle.h"
#include "../Animations/WorkerAnim.h"
#include "Engine/World.h" // for the get world function 
#include "Components/SkeletalMeshComponent.h" // to use the SkeletalMesh Component in the Character class
AWorkerCharacter::AWorkerCharacter()
{
 	// Set this character to call Tick() every frame.  You can turn this off to improve performance if you don't need it.
	PrimaryActorTick.bCanEverTick = false;
	SpringArm = CreateDefaultSubobject<USpringArmComponent>(TEXT("Spring Arm"));
	CameraComponent = CreateDefaultSubobject<UCameraComponent>(TEXT("Camera Comp"));
	SpringArm->SetupAttachment(RootComponent);
	CameraComponent->SetupAttachment(SpringArm);
	// Two Overlap Events 
	CapsuleComponent->OnComponentBeginOverlap.AddDynamic(this,&AWorkerCharacter::OverlapFunction);
	
	CapsuleComponent->OnComponentEndOverlap.AddDynamic(this,&AWorkerCharacter::EndOverlapFunction);
}





// Called to bind functionality to input
void AWorkerCharacter::SetupPlayerInputComponent(UInputComponent* PlayerInputComponent)
{
	Super::SetupPlayerInputComponent(PlayerInputComponent);
	PlayerInputComponent->BindAxis("MoveForward" , this , &AWorkerCharacter::MoveForward);
}

void AWorkerCharacter::OverlapFunction(class UPrimitiveComponent* OverlappedComp, class AActor* OtherActor, class UPrimitiveComponent* OtherComp, int32 OtherBodyIndex, bool bFromSweep, const FHitResult& SweepResult)
{
	AFlippingObstacle* RunTimeFlippingObstacle = Cast<AFlippingObstacle>(OtherActor);
	if(RunTimeFlippingObstacle)
	{
		UAnimInstance* CharacterAnimtion =  Mesh->GetAnimInstance();
		UWorkerAnim* WorkerAnimation = Cast<UWorkerAnim>(CharacterAnimtion);
		if(WorkerAnimation && GetWorld())
		{
			WorkerAnimation->bIsInFrontOfFlippingObstacle = true;
		}
	}
	else 
	{
		ABalanceObstacle* RunTimeBalanceBall = Cast<ABalanceObstacle>(OtherActor);
		if(RunTimeBalanceBall)
		{
			UAnimInstance* CharacterAnimtion =  Mesh->GetAnimInstance();
			UWorkerAnim* WorkerAnimation = Cast<UWorkerAnim>(CharacterAnimtion);
			if(WorkerAnimation && GetWorld())
			{
				WorkerAnimation->bIsOnTopOfBalanceBall = true;
			}
		}
	}
}

void AWorkerCharacter::EndOverlapFunction(class UPrimitiveComponent* OverlappedComp, class AActor* OtherActor, class UPrimitiveComponent* OtherComp, int32 OtherBodyIndex)
{
	AFlippingObstacle* RunTimeFlippingObstacle = Cast<AFlippingObstacle>(OtherActor);
	if(RunTimeFlippingObstacle)
	{
		UAnimInstance* CharacterAnimtion =  Mesh->GetAnimInstance();
		UWorkerAnim* WorkerAnimation = Cast<UWorkerAnim>(CharacterAnimtion);
		if(WorkerAnimation && GetWorld())
		{
			WorkerAnimation->bIsInFrontOfFlippingObstacle = false;
		}
	}
	else 
	{
		ABalanceObstacle* RunTimeBalanceBall = Cast<ABalanceObstacle>(OtherActor);
		if(RunTimeBalanceBall)
		{
			UAnimInstance* CharacterAnimtion =  Mesh->GetAnimInstance();
			UWorkerAnim* WorkerAnimation = Cast<UWorkerAnim>(CharacterAnimtion);
			if(WorkerAnimation && GetWorld())
			{
				WorkerAnimation->bIsOnTopOfBalanceBall = false;
			}
		}
	}	
}

void AWorkerCharacter::MoveForward(float AmountToMove)
{
	AddMovementInput(GetActorForwardVector(), AmountToMove);
}


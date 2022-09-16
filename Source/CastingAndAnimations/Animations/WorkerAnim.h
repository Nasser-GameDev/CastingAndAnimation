// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "Animation/AnimInstance.h"
#include "WorkerAnim.generated.h"

/**
 * 
 */
UCLASS()
class CASTINGANDANIMATIONS_API UWorkerAnim : public UAnimInstance
{
	GENERATED_BODY()
	public:
	UWorkerAnim();
	UPROPERTY(VisibleAnywhere,BlueprintReadOnly)
	float Speed;
	UPROPERTY(VisibleAnywhere,BlueprintReadOnly)
	bool bIsInFrontOfFlippingObstacle;
	UPROPERTY(VisibleAnywhere,BlueprintReadOnly)
	bool bIsOnTopOfBalanceBall;
	virtual void NativeUpdateAnimation(float DeltaSeconds);
};

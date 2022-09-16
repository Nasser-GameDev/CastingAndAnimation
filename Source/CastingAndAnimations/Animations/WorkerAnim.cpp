// Fill out your copyright notice in the Description page of Project Settings.


#include "WorkerAnim.h"


UWorkerAnim::UWorkerAnim()
{
   Speed = 0.0f; 
    bIsInFrontOfFlippingObstacle = false;
    bIsOnTopOfBalanceBall = false; 
}

void UWorkerAnim::NativeUpdateAnimation(float DeltaSeconds)
{
   APawn* PawnOwner = TryGetPawnOwner();
   if(PawnOwner)
   {
        Speed = PawnOwner->GetVelocity().Size();
   }
}

// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "HealthComponent.h"
#include "EnemyHealthComponent.generated.h"

/**
 * 
 */
UCLASS(ClassGroup = (Custom), meta = (BlueprintSpawnableComponent))
class FPS_CODINGCHALLENGE_API UEnemyHealthComponent : public UHealthComponent
{
	GENERATED_BODY()

protected:
	virtual void BeginPlay() override;

private:
	virtual void HandleDestruction() override;
	
	virtual void DamageTaken(AActor* DamagedActor, float Damage, const UDamageType* DamageType, class AController* Instigator, AActor* DamageCauser) override;

	UPROPERTY(EditAnywhere, Category = "Death")
	class UParticleSystem* DeathParticles;
	UPROPERTY(EditAnywhere, Category = "Death")
	class USoundBase* DeathSound;
	UPROPERTY(EditAnywhere, Category = "Death")
	TSubclassOf<class UCameraShakeBase> DeathCameraShakeClass;
};
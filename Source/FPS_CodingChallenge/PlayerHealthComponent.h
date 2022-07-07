// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "HealthComponent.h"
#include "PlayerHealthComponent.generated.h"

DECLARE_DYNAMIC_MULTICAST_DELEGATE(FPlayerDeathDelegate);

UCLASS(ClassGroup = (Custom), meta = (BlueprintSpawnableComponent))
class FPS_CODINGCHALLENGE_API UPlayerHealthComponent : public UHealthComponent
{
	GENERATED_BODY()

protected:
	virtual void BeginPlay() override;

private:
	virtual void HandleDestruction() override;

	virtual void DamageTaken(AActor* DamagedActor, float Damage, const UDamageType* DamageType, class AController* Instigator, AActor* DamageCauser) override;

	UPROPERTY(EditAnywhere, Category = "Death")
	class USoundBase* DeathSound;

	FTimerHandle RespawnTimer;
	UPROPERTY(EditAnywhere, Category = "Respawn")
	float RespawnTime = 3.f;

	UPROPERTY(BlueprintAssignable, Category = "Delegate")
	FPlayerDeathDelegate OnPlayerDeath;
};
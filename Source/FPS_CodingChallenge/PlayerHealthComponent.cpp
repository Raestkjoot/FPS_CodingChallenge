// Fill out your copyright notice in the Description page of Project Settings.


#include "PlayerHealthComponent.h"
#include "Kismet/GameplayStatics.h"
#include "TimerManager.h"


void UPlayerHealthComponent::BeginPlay()
{
	Super::BeginPlay();
}

void UPlayerHealthComponent::HandleDestruction()
{
	Super::HandleDestruction();

	AActor* Owner = GetOwner();

	if (DeathSound)
		UGameplayStatics::PlaySoundAtLocation(this, DeathSound, Owner->GetActorLocation());

	// Game Over
	OnPlayerDeath.Broadcast();
}

void UPlayerHealthComponent::DamageTaken(AActor* DamagedActor, float Damage, const UDamageType* DamageType, class AController* Instigator, AActor* DamageCauser)
{
	Super::DamageTaken(DamagedActor, Damage, DamageType, Instigator, DamageCauser);
}
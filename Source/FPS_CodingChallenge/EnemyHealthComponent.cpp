// Fill out your copyright notice in the Description page of Project Settings.


#include "EnemyHealthComponent.h"
#include "Kismet/GameplayStatics.h"


void UEnemyHealthComponent::BeginPlay()
{
	Super::BeginPlay();
}

void UEnemyHealthComponent::HandleDestruction()
{
	Super::HandleDestruction();

	AActor* Owner = GetOwner();

	if (DeathParticles)
		UGameplayStatics::SpawnEmitterAtLocation(this, DeathParticles, Owner->GetActorLocation(), Owner->GetActorRotation());
	if (DeathSound)
		UGameplayStatics::PlaySoundAtLocation(this, DeathSound, Owner->GetActorLocation());
	if (DeathCameraShakeClass)
		GetWorld()->GetFirstPlayerController()->ClientStartCameraShake(DeathCameraShakeClass);

	Owner->Destroy();
}

void UEnemyHealthComponent::DamageTaken(AActor* DamagedActor, float Damage, const UDamageType* DamageType, class AController* Instigator, AActor* DamageCauser)
{
	Super::DamageTaken(DamagedActor, Damage, DamageType, Instigator, DamageCauser);
}
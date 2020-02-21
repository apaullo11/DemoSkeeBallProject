// Fill out your copyright notice in the Description page of Project Settings.

#include "SpawnBallButton.h"
#include "SkeeBall.h"


ASpawnBallButton::ASpawnBallButton() {
	m_pSpawnLocationMesh = CreateDefaultSubobject<UStaticMeshComponent>("static mesh");
	UStaticMesh* mesh = FindMesh("StaticMesh'/Game/Meshes/SkeeBall.SkeeBall'");
	m_pSpawnLocationMesh->SetStaticMesh(mesh);
}

void ASpawnBallButton::OnPressed_Implementation(ABaseController* pController) {
	Super::OnPressed_Implementation(pController);

	FVector loc = m_pSpawnLocationMesh->GetComponentLocation();

	ASkeeBall* skeeball = (ASkeeBall*)
	GetWorld()->SpawnActor(ASkeeBall::StaticClass(), &loc);
}



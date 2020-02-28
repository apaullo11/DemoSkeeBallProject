// Fill out your copyright notice in the Description page of Project Settings.

#include "SpawnBallButton.h"
#include "SkeeBall.h"
#include "DemoSkeeBallProjectGameModeBase.h"

#define MAX_NUM_SKEEBALLS 10

ASpawnBallButton::ASpawnBallButton() {
	m_pSpawnLocationMesh = CreateDefaultSubobject<UStaticMeshComponent>("static mesh");
	UStaticMesh* mesh = FindMesh("StaticMesh'/Game/Meshes/SkeeBall.SkeeBall'");
	m_pSpawnLocationMesh->SetStaticMesh(mesh);

	m_iSkeeBallIndex = 0;

	m_pSpawnLocationMesh->SetHiddenInGame(true);
}

void ASpawnBallButton::OnPressed_Implementation(ABaseController* pController) {

	Super::OnPressed_Implementation(pController);

	// get gamemode
	ADemoSkeeBallProjectGameModeBase* mode = Cast<ADemoSkeeBallProjectGameModeBase>(GetWorld()->GetAuthGameMode());

	// new ball location
	FVector loc = m_pSpawnLocationMesh->GetComponentLocation();

	// spawn new actor if num is less than max
	if (mode->m_aESkeeBalls.Num() < MAX_NUM_SKEEBALLS) {
		// spawn skeeball
		ASkeeBall* skeeball = (ASkeeBall*)
			GetWorld()->SpawnActor(ASkeeBall::StaticClass(), &loc);
		
		mode->m_aESkeeBalls.Add(skeeball->GetEHandle());

	}
	else {
		EHANDLE ent = mode->m_aESkeeBalls[m_iSkeeBallIndex];

		if (ent) {

			// respawn actor at skeebal spawn point
			((ASkeeBall*)ent->GetActor())->SetActorLocation(loc);
		}
		else {

			mode->m_aESkeeBalls.RemoveAt(m_iSkeeBallIndex);
		}

		m_iSkeeBallIndex = (m_iSkeeBallIndex >= MAX_NUM_SKEEBALLS - 1) ? 0 : m_iSkeeBallIndex + 1;
	}

}



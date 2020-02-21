// Fill out your copyright notice in the Description page of Project Settings.

#include "SkeeBall.h"

ASkeeBall::ASkeeBall() {
	RootComponent = m_pPickupMeshComponent;

	m_pStaticMesh = FindMesh("StaticMesh'/Game/Meshes/SkeeBall.SkeeBall'");
	m_pPickupMeshComponent->SetStaticMesh(m_pStaticMesh);
}



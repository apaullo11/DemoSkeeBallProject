// Fill out your copyright notice in the Description page of Project Settings.

#include "DemoSkeeBallProjectGameModeBase.h"

ADemoSkeeBallProjectGameModeBase::ADemoSkeeBallProjectGameModeBase() {
	m_iWinScore = 100;
	m_bHasPlayerWon = false;
}

void ADemoSkeeBallProjectGameModeBase::BeginPlay() {
	SetScore(0);
}

int ADemoSkeeBallProjectGameModeBase::GetScore() {
	return m_iScore;
}

void ADemoSkeeBallProjectGameModeBase::SetScore(int newScore = 0) {
	m_iScore = newScore;

}


// Fill out your copyright notice in the Description page of Project Settings.


#include "MyCubeManager.h"

#include "Kismet/GameplayStatics.h"


// Sets default values
AMyCubeManager::AMyCubeManager()
{
 	// Set this actor to call Tick() every frame.  You can turn this off to improve performance if you don't need it.
	PrimaryActorTick.bCanEverTick = false;

}

// Called when the game starts or when spawned
void AMyCubeManager::BeginPlay()
{
	Super::BeginPlay();
	FindAllMyCubes();
	RandomlyModifyCubes();
}

// Called every frame
void AMyCubeManager::Tick(float DeltaTime)
{
	Super::Tick(DeltaTime);

}
void AMyCubeManager::FindAllMyCubes()
{
	TArray<AActor*> TempActors;
	UGameplayStatics::GetAllActorsOfClass(GetWorld(), AMyCube::StaticClass(), TempActors);
	for (AActor* Actor : TempActors)
	{
		AMyCube* MyCube = Cast<AMyCube>(Actor);
		if (MyCube)
		{
			MyCubeInstances.Add(MyCube);
		}
	}
}

void AMyCubeManager::RandomlyModifyCubes()
{
	if (!ImportantMaterial || MyCubeInstances.Num() == 0)
	{
		return;
	}
	
	for (int32 i = 0; i < MyCubeInstances.Num(); i++)
	{
		int32 RandomIndex = FMath::RandRange(i, MyCubeInstances.Num() - 1);
		MyCubeInstances.Swap(i, RandomIndex);
	}
	
	for (int32 i = 0; i < MyCubeInstances.Num(); i++)
	{
		AMyCube* Cube = MyCubeInstances[i];
		Cube->ScaleSize = ScaleSize;
		if (i<ImportantCube)
		{
			UStaticMeshComponent* Mesh = Cube->FindComponentByClass<UStaticMeshComponent>();
			if (Mesh)
			{
				Mesh->SetMaterial(0, ImportantMaterial);
			}
			
			Cube->ScoreValue = CommonValue * 2;
		}
		else
		{
			Cube->ScoreValue = CommonValue;
		}
	}
	
}


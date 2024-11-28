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
	// 查找所有 MyCube 实例
	FindAllMyCubes();

	// 随机选取并修改方块
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
	// 获取场景中所有 AMyCube 类型的实例
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


	// 打乱数组顺序
	for (int32 i = 0; i < MyCubeInstances.Num(); i++)
	{
		int32 RandomIndex = FMath::RandRange(i, MyCubeInstances.Num() - 1);
		MyCubeInstances.Swap(i, RandomIndex);
	}
	
	// 修改前 CountToModify 个方块
	for (int32 i = 0; i < MyCubeInstances.Num(); i++)
	{
		AMyCube* Cube = MyCubeInstances[i];
		if (i<NumberOfCubesToModify)
		{
			// 修改材质为 B
			UStaticMeshComponent* Mesh = Cube->FindComponentByClass<UStaticMeshComponent>();
			if (Mesh)
			{
				Mesh->SetMaterial(0, ImportantMaterial);
			}

			// 修改分数值
			Cube->ScoreValue = CommonValue * 2;
		}
		else
		{
			Cube->ScoreValue = CommonValue;
		}
	}
	
}


// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "MyCube.h"
#include "GameFramework/Actor.h"
#include "MyCubeManager.generated.h"

UCLASS()
class WZPROJECT_API AMyCubeManager : public AActor
{
	GENERATED_BODY()
	
public:	
	// Sets default values for this actor's properties
	AMyCubeManager();

protected:
	// Called when the game starts or when spawned
	virtual void BeginPlay() override;

public:	
	// Called every frame
	virtual void Tick(float DeltaTime) override;
	
	UPROPERTY(EditAnywhere, Category = "Cube Settings")
	int32 CommonValue;
	UPROPERTY(EditAnywhere, Category = "Cube Settings")
	int32 NumberOfCubesToModify; // 设置需要随机选择的方块数量

	UPROPERTY()
	TArray<AMyCube*> MyCubeInstances; // 存储场景中的所有 MyCube 实例
	
private:

	UPROPERTY(EditAnywhere, Category = "Materials")
	UMaterialInterface* ImportantMaterial; // 材质 B 的引用

	void FindAllMyCubes(); // 查找所有 MyCube 实例
	void RandomlyModifyCubes(); // 随机选取和修改方块

	
	
};

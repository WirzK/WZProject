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
	int32 ImportantCube; 
	UPROPERTY(EditAnywhere, Category = "Cube Settings")
	float ScaleSize; 

	UPROPERTY()
	TArray<AMyCube*> MyCubeInstances; 
	
private:

	UPROPERTY(EditAnywhere, Category = "Materials")
	UMaterialInterface* ImportantMaterial; 

	void FindAllMyCubes(); 
	void RandomlyModifyCubes(); 

	
	
};

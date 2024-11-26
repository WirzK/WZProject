// MyCube.h
#pragma once

#include "CoreMinimal.h"
#include "Components/BoxComponent.h"
#include "GameFramework/Actor.h"
#include "MyCube.generated.h"

UCLASS()
class WZPROJECT_API AMyCube : public AActor
{
	GENERATED_BODY()

public:
	AMyCube();
protected:
	UPROPERTY(VisibleAnywhere)
	UBoxComponent* CollisionBox;

	UPROPERTY(VisibleAnywhere)
	UStaticMeshComponent* CubeMesh;

	UPROPERTY(EditAnywhere)
	int32 ScoreValue;

	UPROPERTY()
	bool bHasScaled;

private:
	UFUNCTION()
	void OnHit(UPrimitiveComponent* HitComponent, AActor* OtherActor, UPrimitiveComponent* OtherComp, FVector NormalImpulse, const FHitResult& Hit);
	UFUNCTION()
	void ScaleCube();
};

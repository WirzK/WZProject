// MyCube.cpp
#include "MyCube.h"

#include "WZProjectCharacter.h"
#include "Components/BoxComponent.h"
#include "Components/StaticMeshComponent.h"
#include "WZProjectProjectile.h"

AMyCube::AMyCube()
{
	PrimaryActorTick.bCanEverTick = true;

	CollisionBox = CreateDefaultSubobject<UBoxComponent>(TEXT("CollisionBox"));
	CollisionBox->SetBoxExtent(FVector(50.0f, 50.0f, 50.0f));
	CollisionBox->SetCollisionProfileName(TEXT("BlockAllDynamic"));
	CollisionBox->OnComponentHit.AddDynamic(this, &AMyCube::OnHit);
	RootComponent = CollisionBox;

	CubeMesh = CreateDefaultSubobject<UStaticMeshComponent>(TEXT("CubeMesh"));
	CubeMesh->SetupAttachment(RootComponent);
	bHasScaled = false;
}
void AMyCube::OnHit(UPrimitiveComponent* HitComponent, AActor* OtherActor, UPrimitiveComponent* OtherComp, FVector NormalImpulse, const FHitResult& Hit)
{
	FString OtherCompClassName = OtherActor->GetClass()->GetName();
	ScaleCube();
}
void AMyCube::ScaleCube()
{
	if (!bHasScaled)
	{
		// 缩放方块
		FVector NewScale = FVector(0.5f, 0.5f, 0.5f); // 缩放为0.5倍
		CubeMesh->SetWorldScale3D(NewScale);
		bHasScaled = true;
	}
	else
	{
		// 销毁方块
		Destroy();
		AWZProjectCharacter* PlayerCharacter = Cast<AWZProjectCharacter>(GetWorld()->GetFirstPlayerController()->GetPawn());
		if (PlayerCharacter)
		{
			PlayerCharacter->AddScore(ScoreValue);
			UE_LOG(LogTemp, Warning, TEXT("当前分数: %d"), PlayerCharacter->GetCurrentScore());
		}
	}
}


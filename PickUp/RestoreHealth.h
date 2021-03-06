// This code was written by 康子秋

#pragma once

#include "CoreMinimal.h"
#include "Weapon/WeaponBase.h"
#include "RestoreHealth.generated.h"

class UStaticMeshComponent;
class USoundBase;

UCLASS()
class FPS_TESTGAME_API ARestoreHealth : public AWeaponBase
{
	GENERATED_BODY()
	
public:
	ARestoreHealth();

public:

	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "Components")
		UStaticMeshComponent * MeshComp;
	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "BasicValue")
		float HealthAmount;

	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "BasicValue")
	    USoundBase * DestroySound;
protected:
	virtual void BeginPlay() override;
	
	virtual void BeginHit(UPrimitiveComponent* OverlappedComponent, AActor* OtherActor, UPrimitiveComponent* OtherComp, int32 OtherBodyIndex, bool bFromSweep, const FHitResult & SweepResult) override;

	virtual void SetCurrentMeshCollision(bool bCollision) override;
};

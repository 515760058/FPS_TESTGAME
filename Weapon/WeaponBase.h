
#pragma once

#include "CoreMinimal.h"
#include "GameFramework/Actor.h"
#include "Interface/AttackInterface/I_Fire.h"
#include "WeaponBase.generated.h"

//template<class T>
//class Point
//{
//	GENERATED_BODY()
//		Point();
//};

UCLASS()
class FPS_TESTGAME_API AWeaponBase : public AActor , public II_Fire
{
	GENERATED_BODY()
	
public:	

	AWeaponBase();

	UFUNCTION(BlueprintCallable)
		float GetAttackHP()const;
	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "WeaponHitBox")
		class USphereComponent * WeaponHitSphere;

	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "TrenchName")
		FName TrenchName;

	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "Bullet")
		int32 MaxReserveBullet;
	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "Bullet")
		int32 MaxCurrentBullet;

private:
	int32 ReserveBullet;
	int32 CurrentBullet;

	float WeaponTime;
	bool isHit;
protected:
	virtual void BeginPlay() override;

protected:
	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "WeponeBasicValue")
		float AttackHP_Value;

	UPROPERTY(EditAnywhere, Category = "WeponeBasicValue")
		float AttackTimeInterval;

public:	
	virtual void Tick(float DeltaTime) override;

	virtual bool Fire_Int_Implementation(bool isFire,float Time);


	UFUNCTION()
		void BeginHit(UPrimitiveComponent* OverlappedComponent, AActor* OtherActor, UPrimitiveComponent* OtherComp, int32 OtherBodyIndex, bool bFromSweep, const FHitResult & SweepResult);

	UFUNCTION(BlueprintCallable)
		virtual bool SetWeaponBullet(int32 Currentbullet, int32 Reservebullet);
	UFUNCTION(BlueprintCallable)
		virtual void AddWeaponBullet(int32 Reservebullet);
	UFUNCTION(BlueprintCallable)
		virtual bool Reload();

	UFUNCTION(BlueprintCallable)
	virtual bool OnAttack();
	UFUNCTION(BlueprintCallable)
	virtual bool OffAttack();

	UFUNCTION(BlueprintCallable)
	virtual AWeaponBase * ClonWeapon(FTransform ClonWeaponTransform);

	UFUNCTION(BlueprintCallable)
	virtual bool IsReserveBullet();
	UFUNCTION(BlueprintCallable)
	virtual bool IsCurrentBullet();
	UFUNCTION(BlueprintCallable)
		virtual int32 GetReserveBullet() { return ReserveBullet; };
	UFUNCTION(BlueprintCallable)
		virtual int32 GetCurrentBullet() { return CurrentBullet; };
};

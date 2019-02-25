#pragma once
#include "CoreMinimal.h"
#include "GameFramework/Actor.h"
#include "VMValue.generated.h"

UENUM()
enum class EVMValueType : uint8
{
	VM_INT,
	VM_FLOAT,
	VM_BOOL,
	VM_INSTRUCTION
};

USTRUCT()
struct FVMValue
{
	//GENERATED_USTRUCT_BODY()
	GENERATED_BODY()

	UPROPERTY(EditAnywhere)
	EVMValueType type;

	union Value
	{
		UPROPERTY(EditAnywhere)
		int intValue;
		UPROPERTY(EditAnywhere)
		float floatValue;
		UPROPERTY(EditAnywhere)
		bool boolValue;
		UPROPERTY(EditAnywhere)
		int instructValue;
	};
};
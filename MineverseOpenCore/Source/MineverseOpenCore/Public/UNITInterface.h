// Copyright 2026 Emmanuel Bala
// SPDX-License-Identifier: Apache-2.0

#pragma once

#include "CoreMinimal.h"
#include "UObject/Interface.h"
#include "UNITInterface.generated.h"

UINTERFACE(BlueprintType)
class MINEVERSEOPENCORE_API UUNITInterface : public UInterface
{
    GENERATED_BODY()
};

class MINEVERSEOPENCORE_API IUNITInterface
{
    GENERATED_BODY()

public:
    UFUNCTION(BlueprintNativeEvent, BlueprintCallable, Category = "Mineverse|OpenCore|UNIT")
    void RegisterWithNetwork(const FString& NodeSignature);

    UFUNCTION(BlueprintNativeEvent, BlueprintCallable, Category = "Mineverse|OpenCore|UNIT")
    void BroadcastResourceEvent(int32 ResourceID, int32 Quantity, FName BiomeTag);

    UFUNCTION(BlueprintNativeEvent, BlueprintCallable, Category = "Mineverse|OpenCore|UNIT")
    FString GetNodeSignature() const;

    UFUNCTION(BlueprintNativeEvent, BlueprintCallable, Category = "Mineverse|OpenCore|UNIT")
    bool IsNetworkVerified() const;
};

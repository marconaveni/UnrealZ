// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "Kismet/BlueprintFunctionLibrary.h"
#include "MyBlueprintFunctionLibrary.generated.h"

/**
 * 
 */
UCLASS()
class UNREALZ_API UMyBlueprintFunctionLibrary : public UBlueprintFunctionLibrary
{
	GENERATED_BODY()

public:

	//cpu

	//Uses cpuid instruction to get the CPU brand string
	UFUNCTION(BlueprintPure, meta = (DisplayName = "Get CPU Brand Name", Keywords = "CPU brand"), Category = "Unreal-Z") 
	static FString GetCPUBrandName();

	//Returns the CPU chipset if known
	UFUNCTION(BlueprintPure, meta = (DisplayName = "Get CPU Chipset Name", Keywords = "CPU chipset"), Category = "Unreal-Z")
	static FString GetCPUChipsetName();


	//Uses cpuid instruction to get the vendor string
	UFUNCTION(BlueprintPure, meta = (DisplayName = "Get CPU Vendor Name", Keywords = "CPU vendor"), Category = "Unreal-Z")
	static FString GetCPUVendorName();



	UFUNCTION(BlueprintPure, meta = (DisplayName = "Get Number of CPU Cores", Keywords = "CPU cores"), Category = "Unreal-Z")
	static int32 GetCPUCores();

	//Gets the OS Version and OS Subversion.
	UFUNCTION(BlueprintPure, meta = (DisplayName = "Get O.S. Version Info", Keywords = "CPU os version"), Category = "Unreal-Z")
	static void GetOSVersionsInfo(FString& OSVersionLabel, FString& OSSubVersionLabel);


	UFUNCTION(BlueprintPure, meta = (DisplayName = "Get GPU Driver Info", Keywords = "CPU vendor"), Category = "Unreal-Z")
	static void GetGPUDriverInfo(FString& DeviceDescription, FString& Provider, FString& DriverVersion, FString& DriverDate);
	

	//gpu

	UFUNCTION(BlueprintPure, meta = (DisplayName = "Get GPU Brand Name", Keywords = "GPU brand"), Category = "Unreal-Z")
		static FString GetGPUBrandName();
	
};

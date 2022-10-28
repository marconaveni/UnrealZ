// Fill out your copyright notice in the Description page of Project Settings.


#include "MyBlueprintFunctionLibrary.h"
#include "GenericPlatform/GenericPlatformDriver.h"


FString UMyBlueprintFunctionLibrary::GetCPUBrandName()
{
	return FPlatformMisc::GetCPUBrand();
}

FString UMyBlueprintFunctionLibrary::GetCPUChipsetName()
{
	return FPlatformMisc::GetCPUChipset();
}

FString UMyBlueprintFunctionLibrary::GetCPUVendorName()
{
	return FPlatformMisc::GetCPUVendor();
}

FString UMyBlueprintFunctionLibrary::GetGPUBrandName()
{
	return FPlatformMisc::GetPrimaryGPUBrand();
}

int32 UMyBlueprintFunctionLibrary::GetCPUCores()
{
	return FPlatformMisc::NumberOfCores();
}

void UMyBlueprintFunctionLibrary::GetOSVersionsInfo(FString& OSVersionLabel, FString& OSSubVersionLabel)
{
	FPlatformMisc::GetOSVersions(OSVersionLabel, OSSubVersionLabel);
}

void UMyBlueprintFunctionLibrary::GetGPUDriverInfo(FString& DeviceDescription, FString& Provider, FString& DriverVersion, FString& DriverDate)
{
	FGPUDriverInfo GPUDriverInfo = FPlatformMisc::GetGPUDriverInfo(GRHIAdapterName);

	DeviceDescription = GPUDriverInfo.DeviceDescription;
	Provider = GPUDriverInfo.ProviderName;
	DriverVersion = GPUDriverInfo.UserDriverVersion;
	DriverDate = GPUDriverInfo.DriverDate;
}

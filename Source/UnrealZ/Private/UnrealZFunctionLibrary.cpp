// Copyright 2022 Marco Naveni. All Rights Reserved.


#include "UnrealZFunctionLibrary.h"
#include "GenericPlatform/GenericPlatformDriver.h"


FString UUnrealZFunctionLibrary::GetCPUBrandName()
{
	return FPlatformMisc::GetCPUBrand();
}

FString UUnrealZFunctionLibrary::GetCPUChipsetName()
{
	return FPlatformMisc::GetCPUChipset();
}

FString UUnrealZFunctionLibrary::GetCPUVendorName()
{
	return FPlatformMisc::GetCPUVendor();
}

FString UUnrealZFunctionLibrary::GetGPUBrandName()
{
	return FPlatformMisc::GetPrimaryGPUBrand();
}

int32 UUnrealZFunctionLibrary::GetCPUCores()
{
	return FPlatformMisc::NumberOfCores();
}

void UUnrealZFunctionLibrary::GetOSVersionsInfo(FString& OsVersionLabel, FString& OsSubVersionLabel)
{
	FPlatformMisc::GetOSVersions(OsVersionLabel, OsSubVersionLabel);
}

void UUnrealZFunctionLibrary::GetGPUDriverInfo(FString& DeviceDescription, FString& Provider, FString& DriverVersion, FString& DriverDate)
{
	FGPUDriverInfo GPUDriverInfo = FPlatformMisc::GetGPUDriverInfo(GRHIAdapterName);

	DeviceDescription = GPUDriverInfo.DeviceDescription;
	Provider = GPUDriverInfo.ProviderName;
	DriverVersion = GPUDriverInfo.UserDriverVersion;
	DriverDate = GPUDriverInfo.DriverDate;
}

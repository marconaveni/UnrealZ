// Copyright 2022 Marco Naveni. All Rights Reserved.


#include "UnrealZFunctionLibrary.h"
#include "GenericPlatform/GenericPlatformDriver.h"


void UUnrealZFunctionLibrary::GetMemoryInfo(int64& TotalMemoryPhysicalByte, int64& AvailableMemoryPhysicalByte)
{
	TotalMemoryPhysicalByte = FPlatformMemory::GetStats().TotalPhysical;
	AvailableMemoryPhysicalByte = FPlatformMemory::GetStats().AvailablePhysical;
}

void UUnrealZFunctionLibrary::GetDiskInfo(int64& TotalSizeBytes, int64& FreeSizeBytes, FString DefaultDiskPath)
{
	FString RootAppDir = (DefaultDiskPath.Equals(TEXT(""))) ? FPaths::ConvertRelativePathToFull(FPaths::ProjectDir()) : DefaultDiskPath;
	RootAppDir = RootAppDir.Replace(TEXT("/"), TEXT("\\"));
	UE_LOG(LogTemp, Warning, TEXT("Root Dir %s"), *RootAppDir);

	uint64 TotalNumberOfBytes;
	uint64 NumberOfFreeBytes;

	if(FPlatformMisc::GetDiskTotalAndFreeSpace(RootAppDir, TotalNumberOfBytes,NumberOfFreeBytes))
	{
		TotalSizeBytes = TotalNumberOfBytes;
		FreeSizeBytes = NumberOfFreeBytes;
	}
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

bool UUnrealZFunctionLibrary::IsGamePadConnected()
{
	const auto genericApplication = FSlateApplication::Get().GetPlatformApplication();
	if (genericApplication.Get() != nullptr && genericApplication->IsGamepadAttached())
	{
		return true;
	}
	return false;
}

// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "Kismet/BlueprintFunctionLibrary.h"
#include "UnrealZFunctionLibrary.generated.h"


/**
 * 
 */
UCLASS()
class UNREALZ_API UUnrealZFunctionLibrary : public UBlueprintFunctionLibrary
{
	GENERATED_BODY()

public:

	/** @return Percentage CPU utilization for the last interval. */
	UFUNCTION(BlueprintPure, meta = (DisplayName = "Get CPU Usage", Keywords = "CPU brand"), Category = "Unreal-Z")
	static FORCEINLINE float GetCPUUsage() { return FPlatformTime::GetCPUTime().CPUTimePctRelative; }

	/** @return Uses CPUID instruction to get the CPU brand string */
	UFUNCTION(BlueprintPure, meta = (DisplayName = "Get CPU Brand Name", Keywords = "CPU brand"), Category = "Unreal-Z")
	static FORCEINLINE FString GetCPUBrandName() { return FPlatformMisc::GetCPUBrand(); };

	/** @return the CPU chipset if known */
	UFUNCTION(BlueprintPure, meta = (DisplayName = "Get CPU Chipset Name", Keywords = "CPU chipset"), Category = "Unreal-Z")
	static FORCEINLINE FString GetCPUChipsetName() { return FPlatformMisc::GetCPUChipset(); }

	/** @return Uses CPUID instruction to get the vendor string */
	UFUNCTION(BlueprintPure, meta = (DisplayName = "Get CPU Vendor Name", Keywords = "CPU vendor"), Category = "Unreal-Z")
	static FORCEINLINE FString GetCPUVendorName() { return FPlatformMisc::GetCPUVendor(); }

	/** @return the number of CPU cores */
	UFUNCTION(BlueprintPure, meta = (DisplayName = "Get Number of CPU Cores", Keywords = "CPU cores"), Category = "Unreal-Z")
	static FORCEINLINE int32 GetCPUCores() { return FPlatformMisc::NumberOfCores(); }

	/** @return number of CPU cores including Hyperthreads */
	UFUNCTION(BlueprintPure, meta = (DisplayName = "Get Number of CPU Cores with HT", Keywords = "CPU cores"), Category = "Unreal-Z")
	static FORCEINLINE int32 GetCPUCoresWithHT() { return FPlatformMisc::NumberOfCoresIncludingHyperthreads(); }

	/** @return Get primary GPU brand */
	UFUNCTION(BlueprintPure, meta = (DisplayName = "Get GPU Brand Name", Keywords = "GPU brand"), Category = "Unreal-Z")
	static FORCEINLINE FString GetGPUBrandName() { return FPlatformMisc::GetPrimaryGPUBrand(); };

	/** @return Bytes to Kilobyte */
	UFUNCTION(BlueprintPure, meta = (DisplayName = "Convert Bytes to KB", Keywords = "Convert"), Category = "Unreal-Z")
	static FORCEINLINE int64 BytesToKilobyte(const int64 Number) { return Number / 1024; }

	/** @return Bytes to Megabyte */
	UFUNCTION(BlueprintPure, meta = (DisplayName = "Convert Bytes to MB", Keywords = "Convert"), Category = "Unreal-Z")
	static FORCEINLINE int32 BytesToMegabyte(const int64 Number) { return Number / (1024 * 1024) ; }

	/** @return Bytes to Gigabyte */
	UFUNCTION(BlueprintPure, meta = (DisplayName = "Convert Bytes to GB", Keywords = "Convert"), Category = "Unreal-Z")
	static FORCEINLINE double BytesToGigabyte(const int64 Number) { return Number / pow(1024 , 3) ; }

	/** @return Bytes to Terabyte */
	UFUNCTION(BlueprintPure, meta = (DisplayName = "Convert Bytes to TB", Keywords = "Convert"), Category = "Unreal-Z")
	static FORCEINLINE double BytesToTerabyte(const int64 Number) { return Number / (pow(1024,4)); }

	/** @return Bytes to print */
	UFUNCTION(BlueprintPure, meta = (DisplayName = "Convert Bytes to String to Print", Keywords = "Convert"), Category = "Unreal-Z")
	static FORCEINLINE FString BytesToString(const int64 Number) { return FString::Printf(TEXT("%llu"), Number); }

	/** @return Memory physical total */
	UFUNCTION(BlueprintPure, meta = (DisplayName = "Get Memory Information in GB", Keywords = "Memory"), Category = "Unreal-Z")
	static FORCEINLINE int32 GetMemoryGB() { return FPlatformMemory::GetPhysicalGBRam(); };

	/**
	 * get information memory in byte
	 * @param TotalMemoryPhysicalByte Total memory size in byte
	 * @param AvailableMemoryPhysicalByte Total memory available
	 */
	UFUNCTION(BlueprintPure, meta = (DisplayName = "Get Memory Information", Keywords = "Memory"), Category = "Unreal-Z")
	static void GetMemoryInfo(int64& TotalMemoryPhysicalByte, int64& AvailableMemoryPhysicalByte);

	/**
	 * Get info size disk
	 * @param TotalSizeBytes full size disk
	 * @param FreeSizeBytes free size disk
	 * @param DefaultDiskPath Optional parameter if empty is default disk location executable
	 */
	UFUNCTION(BlueprintPure, meta = (DisplayName = "Get Disk Information", Keywords = "Disk"), Category = "Unreal-Z")
	static void GetDiskInfo(int64& TotalSizeBytes, int64& FreeSizeBytes, FString DefaultDiskPath = TEXT(""));

	/**
	 * Gets the OS Version and OS Subversion.
	 * @param OsVersionLabel 
	 * @param OsSubVersionLabel 
	 */
	UFUNCTION(BlueprintPure, meta = (DisplayName = "Get O.S. Version Info", Keywords = "CPU os version"), Category = "Unreal-Z")
	static void GetOSVersionsInfo(FString& OsVersionLabel, FString& OsSubVersionLabel);

	/**
	 * Uses gpuid instruction to get the CPU brand string
	 * @param DeviceDescription 
	 * @param Provider 
	 * @param DriverVersion 
	 * @param DriverDate 
	 */
	UFUNCTION(BlueprintPure, meta = (DisplayName = "Get GPU Driver Info", Keywords = "CPU vendor"), Category = "Unreal-Z")
	static void GetGPUDriverInfo(FString& DeviceDescription, FString& Provider, FString& DriverVersion, FString& DriverDate);

	/* Check if gamepad is connected at Runtime. */
	UFUNCTION(BlueprintPure, meta = (DisplayName = "Is Gamepad Connected"), Category = "Unreal-Z")
	static bool IsGamePadConnected();
};

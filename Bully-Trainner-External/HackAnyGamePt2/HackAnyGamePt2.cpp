#include "stdafx.h"
#include <iostream>
#include <vector>
#include <Windows.h>
#include "proc.h"

int main()
{

	// Get ProcId of the target process
	DWORD procId = GetProcId(L"Bully.exe");

	// Get Module Base Address
	uintptr_t moduleBase = GetModuleBaseAddress(procId, L"Bully.exe");

	// Get Handle to process
	HANDLE hProcess = 0;
	hProcess = OpenProcess(PROCESS_ALL_ACCESS, NULL, procId);

	// Resolve base address of the pointer chain
	uintptr_t dynamicPtrBaseAddr   = moduleBase + 0x1CC438C;  // Pointer 
	uintptr_t dynamicPtrBaseAddr3  = moduleBase + 0x082AA68;  // Pointer x,y, z

	system("color 2");
	std::cout << "#####################################################################################################################" << std::endl;
	std::cout << "############################### Bully Trainner v1.0 by:S4iph ########################################################" << std::endl;
	std::cout << "#####################################################################################################################\n" << std::endl;


	// Money Pointer chain
	std::vector<unsigned int> moneyOffsets = { 0x00001CA0 };
	uintptr_t moneyAddr = FindDMAAddy(hProcess, dynamicPtrBaseAddr, moneyOffsets);
	

	// Wanted Pointer chain
	std::vector<unsigned int> wantedOffsets = { 0x00001D40 };
	uintptr_t wantedAddr = FindDMAAddy(hProcess, dynamicPtrBaseAddr, wantedOffsets);
	

	// Health Pointer chain
	std::vector<unsigned int> healthOffsets = { 0x00001CB8 };
	uintptr_t healthAddr = FindDMAAddy(hProcess, dynamicPtrBaseAddr, healthOffsets);
	

	// Egg Pointer chain
	std::vector<unsigned int> eggOffsets = { 0x378F8 };
	uintptr_t eggAddr = FindDMAAddy(hProcess, dynamicPtrBaseAddr, eggOffsets);
	

	// Gun Pointer chain
	std::vector<unsigned int> gunOffsets = { 0x379C0 };
	uintptr_t gunAddr = FindDMAAddy(hProcess, dynamicPtrBaseAddr, gunOffsets);
	

	// Rocket Launcher Pointer chain
	std::vector<unsigned int> gunRocketOffsets = { 0x37970 };
	uintptr_t gunRocketAddr = FindDMAAddy(hProcess, dynamicPtrBaseAddr, gunRocketOffsets);
	

	// Dinamite Pointer chain
	std::vector<unsigned int> gunDinamiteOffsets = { 0x37A38 };
	uintptr_t gunDinamiteAddr = FindDMAAddy(hProcess, dynamicPtrBaseAddr, gunDinamiteOffsets);
	

	// Dust Pointer chain
	std::vector<unsigned int> gunDustOffsets = { 0x379E8 };
	uintptr_t gunDustAddr = FindDMAAddy(hProcess, dynamicPtrBaseAddr, gunDustOffsets);
	

	// Stinks bomb Pointer chain
	std::vector<unsigned int> gunStinksOffsets = { 0x37A10 };
	uintptr_t gunStinksAddr = FindDMAAddy(hProcess, dynamicPtrBaseAddr, gunStinksOffsets);
	

	// Teleport
	std::vector<unsigned int> xLocationOffsets = { 0x30 };
	uintptr_t xAddr = FindDMAAddy(hProcess, dynamicPtrBaseAddr3, xLocationOffsets);
	
	std::vector<unsigned int> yLocationOffsets = { 0x34 };
	uintptr_t yAddr = FindDMAAddy(hProcess, dynamicPtrBaseAddr3, yLocationOffsets);
	

	std::vector<unsigned int> zLocationOffsets = { 0x38 };
	uintptr_t zAddr = FindDMAAddy(hProcess, dynamicPtrBaseAddr3, zLocationOffsets);
	
	std::cout << "---------------------------------------------------------------------------------------------------------------------\n\n" << std::endl;

	std::cout << " # Player						   # Teleport\n";
	std::cout << "[F1] Health"				<<"						[F7] School" << std::endl;
	std::cout << "[F3] Money"				<<"						[F8] Market" << std::endl;
	std::cout << "[F4] Wanted"				<<"						[F9] Boxe Academy"	<< std::endl;
	std::cout << "[F5] Infinite Ammo"		<<"					[F10] Amusement Park"   << std::endl;
	std::cout << "[F11] Developer Information about Memory\n"   << std::endl;
	
	

	std::cout << "---------------------------------------------------------------------------------------------------------------------\n\n" << std::endl;
	// Read Variables Values
	int moneyValue = 0;
	int wantedgValue = 0;
	int healthValue = 0;
	int eggValue = 0;
	int gunValue = 0;
	int gunRocketValue = 0;
	int gunDinamiteValue = 0;
	int gunDustValue = 0;
	int gunStinksValue = 0;
	float xValue = 0.0;
	float yValue = 0.0;
	float zValue = 0.0;
	

	// Write to it
	int newMoney = 9999999;
	int newWanted = 0;
	int newHealth = 9999999999;
	int newEgg = 20447244;
	int newGun = 20709384;
	int newGunRocket = 20185100;
	int newGunDinamite = 19726341;
	int newGunDust = 25821189;
	int newGunStinks = 20250629;


	DWORD dwExit = 0;
	bool bHealth = false, bMoney = false, bWanted = false, bEgg = false, bGun = false, bGunRocket = false, bGunDinamite = false, bGunDust = false, bStinks = false, bxLocation = false, byLocation = false, bzLocation = false;

	while (GetExitCodeProcess(hProcess, &dwExit) && dwExit == STILL_ACTIVE)
	{
		//Health continuous write
		if (GetAsyncKeyState(VK_F1) & 1)
		{
			bHealth = !bHealth;

			if (bHealth)
			{
				WriteProcessMemory(hProcess, (BYTE*)healthAddr, &newHealth, sizeof(newHealth), nullptr);
				ReadProcessMemory(hProcess, (BYTE*)healthAddr, &healthValue, sizeof(healthValue), nullptr);
				std::cout << "[+] New health = " << std::dec << healthValue << std::endl;
			}
			else
			{
				WriteProcessMemory(hProcess, (BYTE*)healthAddr, &newHealth, sizeof(newHealth), nullptr);
			}
		}

		// Money unlimited
		if (GetAsyncKeyState(VK_F3) & 1)
		{
			bMoney = !bMoney;

			if (bMoney)
			{
				WriteProcessMemory(hProcess, (BYTE*)moneyAddr, &newMoney, sizeof(newMoney), nullptr);
				ReadProcessMemory(hProcess, (BYTE*)moneyAddr, &moneyValue, sizeof(moneyValue), nullptr);
				std::cout << "[+] New money = " << std::dec << moneyValue << std::endl;
			}
			else
			{
				WriteProcessMemory(hProcess, (BYTE*)moneyAddr, &newMoney, sizeof(newMoney), nullptr);
			}
		}

		// Wanted level
		if (GetAsyncKeyState(VK_F4) & 1)
		{
			bWanted = !bWanted;

			if (bWanted)
			{
				WriteProcessMemory(hProcess, (BYTE*)wantedAddr, &newWanted, sizeof(newWanted), nullptr);
				ReadProcessMemory(hProcess, (BYTE*)wantedAddr, &wantedgValue, sizeof(wantedgValue), nullptr);
				std::cout << "[+] New Level Wanted = " << std::dec << wantedgValue << std::endl;
			}

			else
			{
				WriteProcessMemory(hProcess, (BYTE*)wantedAddr, &newWanted, sizeof(newWanted), nullptr);
			}
		}
		// Ammo
		if (GetAsyncKeyState(VK_F5) & 1)
		{
			bEgg = !bEgg;
			bGun = !bGun;
			bGunRocket = !bGunRocket;
			bGunDinamite = !bGunDinamite;
			bGunDust = !bGunDust;
			bStinks = !bStinks;

			if (bEgg || bGun || bGunRocket || bGunDinamite || bGunDust || bStinks)
			{
				WriteProcessMemory(hProcess, (BYTE*)eggAddr, &newEgg, sizeof(newEgg), nullptr);
				ReadProcessMemory(hProcess, (BYTE*)eggAddr, &eggValue, sizeof(eggValue), nullptr);
				std::cout << "[+] New Egg Ammo = " << std::dec << eggValue << std::endl;

				WriteProcessMemory(hProcess, (BYTE*)gunAddr, &newGun, sizeof(newGun), nullptr);
				ReadProcessMemory(hProcess, (BYTE*)gunAddr, &gunValue, sizeof(gunValue), nullptr);
				std::cout << "[+] New Egg Ammo = " << std::dec << gunValue << std::endl;

				WriteProcessMemory(hProcess, (BYTE*)gunRocketAddr, &newGunRocket, sizeof(newGunRocket), nullptr);
				ReadProcessMemory(hProcess, (BYTE*)gunRocketAddr, &gunRocketValue, sizeof(gunRocketValue), nullptr);
				std::cout << "[+] New Rocket Ammo = " << std::dec << gunRocketValue << std::endl;

				WriteProcessMemory(hProcess, (BYTE*)gunDinamiteAddr, &newGunDinamite, sizeof(newGunDinamite), nullptr);
				ReadProcessMemory(hProcess, (BYTE*)gunDinamiteAddr, &gunDinamiteValue, sizeof(gunDinamiteValue), nullptr);
				std::cout << "[+] New Dinamite Ammo = " << std::dec << gunDinamiteValue << std::endl;

				WriteProcessMemory(hProcess, (BYTE*)gunDustAddr, &newGunDust, sizeof(newGunDust), nullptr);
				ReadProcessMemory(hProcess, (BYTE*)gunDustAddr, &gunDustValue, sizeof(gunDustValue), nullptr);
				std::cout << "[+] New Dust Ammo = " << std::dec << gunDustValue << std::endl;

				WriteProcessMemory(hProcess, (BYTE*)gunStinksAddr, &newGunStinks, sizeof(newGunStinks), nullptr);
				ReadProcessMemory(hProcess, (BYTE*)gunStinksAddr, &gunStinksValue, sizeof(gunStinksValue), nullptr);
				std::cout << "[+] New Stinks Ammo = " << std::dec << gunStinksValue << std::endl;
			}

			else
			{
				WriteProcessMemory(hProcess, (BYTE*)eggAddr, &newEgg, sizeof(newEgg), nullptr);
				WriteProcessMemory(hProcess, (BYTE*)gunAddr, &newGun, sizeof(newGun), nullptr);
				WriteProcessMemory(hProcess, (BYTE*)gunRocketAddr, &newGunRocket, sizeof(newGunRocket), nullptr);
				WriteProcessMemory(hProcess, (BYTE*)gunDinamiteAddr, &newGunDinamite, sizeof(newGunDinamite), nullptr);
				WriteProcessMemory(hProcess, (BYTE*)gunDustAddr, &newGunDust, sizeof(newGunDust), nullptr);
				WriteProcessMemory(hProcess, (BYTE*)gunStinksAddr, &newGunStinks, sizeof(newGunStinks), nullptr);
			}
		}
		
		// Teleport

		// School 
		if (GetAsyncKeyState(VK_F7) & 1)
		{
			bxLocation = !bxLocation;
			byLocation = !byLocation;
			bzLocation = !bzLocation;

			if (bxLocation || byLocation || bzLocation)
			{
				float xSchoolValue = 218.315;
				float ySchoolValue = -73.2767;
				float zSchoolValue = 9.56027;
				WriteProcessMemory(hProcess, (BYTE*)xAddr, &xSchoolValue, sizeof(xSchoolValue), nullptr);
				WriteProcessMemory(hProcess, (BYTE*)yAddr, &ySchoolValue, sizeof(ySchoolValue), nullptr);
				WriteProcessMemory(hProcess, (BYTE*)zAddr, &zSchoolValue, sizeof(zSchoolValue), nullptr);
			}
		}
		// Market
		if (GetAsyncKeyState(VK_F8) & 1)
		{
			bxLocation = !bxLocation;
			byLocation = !byLocation;
			bzLocation = !bzLocation;
			if (bxLocation || byLocation || bzLocation)
			{
				float xMarketValue = 349.764;
				float yMarketValue = 149.158;
				float zMarketValue = 5.56027;
				WriteProcessMemory(hProcess, (BYTE*)xAddr, &xMarketValue, sizeof(xMarketValue), nullptr);
				WriteProcessMemory(hProcess, (BYTE*)yAddr, &yMarketValue, sizeof(yMarketValue), nullptr);
				WriteProcessMemory(hProcess, (BYTE*)zAddr, &zMarketValue, sizeof(zMarketValue), nullptr);
			}
		}
		// Boxe Academy
		if (GetAsyncKeyState(VK_F9) & 1)
		{
			bxLocation = !bxLocation;
			byLocation = !byLocation;
			bzLocation = !bzLocation;
			if (bxLocation || byLocation || bzLocation)
			{
				float xBoxeAcademyValue = 392.832;
				float yBoxeAcademyValue = 144.702;
				float zBoxeAcademyValue = 5.25696;
				WriteProcessMemory(hProcess, (BYTE*)xAddr, &xBoxeAcademyValue, sizeof(xBoxeAcademyValue), nullptr);
				WriteProcessMemory(hProcess, (BYTE*)yAddr, &yBoxeAcademyValue, sizeof(yBoxeAcademyValue), nullptr);
				WriteProcessMemory(hProcess, (BYTE*)zAddr, &zBoxeAcademyValue, sizeof(zBoxeAcademyValue), nullptr);
			}
		}
		// Amusement Park
		if (GetAsyncKeyState(VK_F10) & 1)
		{
			bxLocation = !bxLocation;
			byLocation = !byLocation;
			bzLocation = !bzLocation;
			if (bxLocation || byLocation || bzLocation)
			{
				float xAmusementParkValue = 205.568;
				float yAmusementParkValue = 427.53;
				float zAmusementParkValue = 8.34017;
				WriteProcessMemory(hProcess, (BYTE*)xAddr, &xAmusementParkValue, sizeof(xAmusementParkValue), nullptr);
				WriteProcessMemory(hProcess, (BYTE*)yAddr, &yAmusementParkValue, sizeof(yAmusementParkValue), nullptr);
				WriteProcessMemory(hProcess, (BYTE*)zAddr, &zAmusementParkValue, sizeof(zAmusementParkValue), nullptr);
			}
		}
		if (GetAsyncKeyState(VK_F11) & 1)
		{
			std::cout << "                                    \n## MEMORY INFORMATION ##\n" << std::endl;
			std::cout << "[+] Pointer Address   -> "			<< "0x" << std::hex << dynamicPtrBaseAddr << std::endl;
			std::cout << "[+] Pointer Teleport Address   -> "	<< "0x" << std::hex << dynamicPtrBaseAddr3 << "\n" << std::endl;

			std::cout << "[+] Money Address Memory -> "			<< "0x" << std::hex << moneyAddr << std::endl;
			std::cout << "[+] Wanted Address Memory -> "		<< "0x" << std::hex << wantedAddr << std::endl;
			std::cout << "[+] Wanted Address Memory -> "		<< "0x" << std::hex << healthAddr << std::endl;
			std::cout << "[+] Gun Egg Ammo Address Memory -> "	<< "0x" << std::hex << eggAddr << std::endl;
			std::cout << "[+] Gun Address Memory -> "			<< "0x" << std::hex << gunAddr << std::endl;
			std::cout << "[+] Gun Rocket  Address Memory -> "	<< "0x" << std::hex << gunRocketAddr << std::endl;
			std::cout << "[+] Gun Dinamite  Address Memory -> " << "0x" << std::hex << gunDinamiteAddr << std::endl;
			std::cout << "[+] Gun Dust  Address Memory -> "		<< "0x" << std::hex << gunDustAddr << std::endl;
			std::cout << "[+] Gun Stinks  Address Memory -> "	<< "0x" << std::hex << gunStinksAddr << std::endl;
			std::cout << "[+] Level Teleport x Address Memory -> " << "0x" << std::hex << xAddr << std::endl;
			std::cout << "[+] Level Teleport y Address Memory -> " << "0x" << std::hex << yAddr << std::endl;
			std::cout << "[+] Level Teleport Z Address Memory -> " << "0x" << std::hex << zAddr << std::endl;
		}


		if (GetAsyncKeyState(VK_INSERT) & 1)
		{
			return 0;
		}


		Sleep(10);
	}

	getchar();

	return 0;
}
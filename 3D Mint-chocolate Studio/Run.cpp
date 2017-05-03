
/*
	2017.04.23
	Created by AcrylicShrimp.
*/

#include "MintChocolateStudio.h"

#include <cstdint>
#include <Windows.h>

int32_t APIENTRY WinMain(HINSTANCE hInstance, HINSTANCE hPrevInstance, LPSTR lpCmdLine, int32_t nShowCmd)
{
	D3MCS::MintChocolateStudio::initialize(hInstance);

	for (MSG sMsg; GetMessage(&sMsg, nullptr, 0u, 0u);)
	{
		TranslateMessage(&sMsg);
		DispatchMessage(&sMsg);
	}

	D3MCS::MintChocolateStudio::finalize();

	return 0;
}
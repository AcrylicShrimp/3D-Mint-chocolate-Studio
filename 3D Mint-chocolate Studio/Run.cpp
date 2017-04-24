
/*
	2017.04.23
	Created by AcrylicShrimp.
*/

#include "MintChocolateStudio.h"

#include <cstdint>
#include <Windows.h>

int32_t APIENTRY WinMain(HINSTANCE hInstance, HINSTANCE hPrevInstance, LPSTR lpCmdLine, int32_t nShowCmd)
{
	D3MCS::MintChocolateStudio::initialize();

	for (MSG sMsg; GetMessage(&sMsg, nullptr, 0u, 0u);)
	{
		if (sMsg.message == WM_QUIT)
			break;

		TranslateMessage(&sMsg);
		DispatchMessage(&sMsg);
	}

	D3MCS::MintChocolateStudio::finalize();

	return 0;
}
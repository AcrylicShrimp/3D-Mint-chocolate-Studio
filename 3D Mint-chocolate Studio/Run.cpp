
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

	for (MSG sMsg;;)
	{
		if (PeekMessage(&sMsg, nullptr, 0u, 0u, PM_REMOVE))
		{
			if (sMsg.message == WM_QUIT)
				break;

			TranslateMessage(&sMsg);
			DispatchMessage(&sMsg);

			continue;
		}

		D3MCS::MintChocolateStudio::process();
	}

	D3MCS::MintChocolateStudio::finalize();

	return 0;
}
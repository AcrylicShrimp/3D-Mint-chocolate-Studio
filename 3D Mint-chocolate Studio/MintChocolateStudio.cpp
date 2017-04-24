
/*
	2017.04.23
	Created by AcrylicShrimp.
*/

#include "MintChocolateStudio.h"

namespace D3MCS
{
	void MintChocolateStudio::initialize()
	{
		//Initialize all manager;
		UI::FrameManager::initialize();
		UI::InputManager::initialize();
		UI::RenderManager::initialize();

		//Create the main frame.
		RECT sWorkArea;
		SystemParametersInfo(SPI_GETWORKAREA, 0u, &sWorkArea, 0u);
		UI::FrameManager::instance().createFrame((sWorkArea.right - sWorkArea.left) / 4u, (sWorkArea.bottom - sWorkArea.top) / 4u, (sWorkArea.right - sWorkArea.left) / 2u, (sWorkArea.bottom - sWorkArea.top) / 2u, 32u, 32u, false, L"3D Mint-chocolate Studio", L"3D Mint-chocolate Studio", LoadIcon(nullptr, IDI_APPLICATION));

		//Make current.
		UI::FrameManager::instance().frame().linkCurrentThread();

		//Init GLEW.
		glewInit();

		//Make the frame visible.
		UI::FrameManager::instance().frame().setVisible(true);
	}

	void MintChocolateStudio::finalize()
	{
		UI::RenderManager::finalize();
		UI::InputManager::finalize();
		UI::FrameManager::finalize();
	}
}
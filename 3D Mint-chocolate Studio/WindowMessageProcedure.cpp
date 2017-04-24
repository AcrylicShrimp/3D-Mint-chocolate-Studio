
/*
	2017.04.23
	Created by AcrylicShrimp.
*/

#include "WindowMessageProcedure.h"

namespace D3MCS::UI
{
	std::unordered_map<UINT, std::vector<WindowMessageProcedure *>> WindowMessageProcedure::sProcedureListMap{};

	WindowMessageProcedure::WindowMessageProcedure(const std::initializer_list<UINT> &sNewMessageList) :
		sMessageList(sNewMessageList)
	{
		for (auto nMessage : this->sMessageList)
			WindowMessageProcedure::sProcedureListMap[nMessage].emplace_back(this);
	}

	WindowMessageProcedure::WindowMessageProcedure(std::initializer_list<UINT> &&sNewMessageList) :
		sMessageList(std::move(sNewMessageList))
	{
		for (auto nMessage : this->sMessageList)
			WindowMessageProcedure::sProcedureListMap[nMessage].emplace_back(this);
	}

	WindowMessageProcedure::WindowMessageProcedure(const WindowMessageProcedure &sSrc) :
		sMessageList(sSrc.sMessageList)
	{
		for (auto nMessage : this->sMessageList)
			WindowMessageProcedure::sProcedureListMap[nMessage].emplace_back(this);
	}

	WindowMessageProcedure::WindowMessageProcedure(WindowMessageProcedure &&sSrc) :
		sMessageList(std::move(sSrc.sMessageList))
	{
		sSrc.~WindowMessageProcedure();
		sSrc.sMessageList = {};

		for (auto nMessage : this->sMessageList)
			WindowMessageProcedure::sProcedureListMap[nMessage].emplace_back(this);
	}

	WindowMessageProcedure::~WindowMessageProcedure()
	{
		for (auto nMessage : this->sMessageList)
		{
			auto &sProcedureList{WindowMessageProcedure::sProcedureListMap[nMessage]};

			for (auto iIndex = sProcedureList.cbegin(), iEnd = sProcedureList.cend(); iIndex != iEnd; ++iIndex)
				if (*iIndex == this)
				{
					sProcedureList.erase(iIndex);
					break;
				}
		}
	}

	WindowMessageProcedure &WindowMessageProcedure::operator=(const WindowMessageProcedure &sSrc)
	{
		if (&sSrc == this)
			return *this;

		this->~WindowMessageProcedure();
		this->sMessageList = std::move(sSrc.sMessageList);

		for (auto nMessage : this->sMessageList)
			WindowMessageProcedure::sProcedureListMap[nMessage].emplace_back(this);

		return *this;
	}

	WindowMessageProcedure &WindowMessageProcedure::operator=(WindowMessageProcedure &&sSrc)
	{
		if (&sSrc == this)
			return *this;

		this->~WindowMessageProcedure();
		sSrc.~WindowMessageProcedure();

		this->sMessageList = std::move(sSrc.sMessageList);
		sSrc.sMessageList = {};

		for (auto nMessage : this->sMessageList)
			WindowMessageProcedure::sProcedureListMap[nMessage].emplace_back(this);

		return *this;
	}

	LRESULT CALLBACK WindowMessageProcedure::processWindowMessage(HWND hWindow, UINT nMessage, WPARAM wParam, LPARAM lParam)
	{
		auto iIndex = WindowMessageProcedure::sProcedureListMap.find(nMessage);

		if (iIndex == WindowMessageProcedure::sProcedureListMap.cend() || iIndex->second.empty())
			return DefWindowProc(hWindow, nMessage, wParam, lParam);

		LRESULT sSum{0};

		for (auto pHandler : iIndex->second)
			sSum += pHandler->handleWindowMessage(hWindow, nMessage, wParam, lParam);

		return sSum;
	}
}
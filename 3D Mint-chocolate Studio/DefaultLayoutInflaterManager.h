
/*
	2017.06.17
	Created by AcrylicShrimp.
*/

#ifndef _CLASS_D3MCS_UI_LAYOUT_DEFAULT_LAYOUT_INFLATER_MANAGER_H

#define _CLASS_D3MCS_UI_LAYOUT_DEFAULT_LAYOUT_INFLATER_MANAGER_H

#include "LayoutElementInflater.h"
#include "ManagerBase.h"

namespace D3MCS::UI::Layout
{
	class DefaultLayoutInflaterManager final : public ManagerBase<DefaultLayoutInflaterManager>
	{
	public:
		friend ManagerBase<DefaultLayoutInflaterManager>;
		
	private:
		DefaultLayoutInflaterManager();
		DefaultLayoutInflaterManager(const DefaultLayoutInflaterManager &sSrc) = delete;
		DefaultLayoutInflaterManager(DefaultLayoutInflaterManager &&sSrc) = delete;
		~DefaultLayoutInflaterManager();
		
	public:
		DefaultLayoutInflaterManager &operator=(const DefaultLayoutInflaterManager &sSrc) = delete;
		DefaultLayoutInflaterManager &operator=(DefaultLayoutInflaterManager &&sSrc) = delete;
	};
}

#endif
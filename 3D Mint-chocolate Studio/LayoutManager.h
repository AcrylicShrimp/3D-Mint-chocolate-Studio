
/*
	2017.05.15
	Created by AcrylicShrimp.
*/

#ifndef _CLASS_D3MCS_UI_LAYOUT_LAYOUT_MANAGER_H

#define _CLASS_D3MCS_UI_LAYOUT_LAYOUT_MANAGER_H

/*
	TODO : Place your include directives here.
*/
#include <utility>

namespace D3MCS::UI::Layout
{
	class LayoutManager
	{
	private:
		/*
			TODO : Place your field declarations here.
		*/
		
		
	public:
		LayoutManager();
		LayoutManager(const LayoutManager &sSrc);
		LayoutManager(LayoutManager &&sSrc);
		~LayoutManager();
		/*
			TODO : Place your other constructors here.
		*/
		
		
	public:
		LayoutManager &operator=(const LayoutManager &sSrc);
		LayoutManager &operator=(LayoutManager &&sSrc);
		/*
			TODO : Place your other operator overloadings here.
		*/
		
		
	public:
		/*
			TODO : Place your member function declarations here.
		*/
		
	};
}

#endif

/*
	2017.04.25
	Created by AcrylicShrimp.
*/

namespace D3MCS::UI
{
	template<class UIType> inline UIType *UIManager::findUIElementByName(const std::wstring &sName)
	{
		auto iIndex = this->sUIElementMap.find(sName);

		return iIndex != this->sUIElementMap.cend() ? static_cast <UIType *>(iIndex->second) : nullptr;
	}

	template<class UIType> inline const UIType *UIManager::findUIElementByName(const std::wstring &sName) const
	{
		auto iIndex = this->sUIElementMap.find(sName);

		return iIndex != this->sUIElementMap.cend() ? static_cast <UIType *>(iIndex->second) : nullptr;
	}

	template<class UIType, class ...ConstructorParameter> bool UIManager::addUIElementByName(const std::wstring &sName, ConstructorParameter &&...sConstructorParameter)
	{
		auto iIndex = this->sUIElementMap.find(sName);

		if (iIndex != this->sUIElementMap.cend())
			return false;

		this->sUIElementMap.emplace<UIType>(new UIType(std::forward<UIType>(sConstructorParameter)...));

		return true;
	}
}
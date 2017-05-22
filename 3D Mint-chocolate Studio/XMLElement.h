
/*
	2017.05.20
	Created by AcrylicShrimp.
*/

#ifndef _CLASS_D3MCS_UTILITY_XML_XMLELEMENT_H

#define _CLASS_D3MCS_UTILITY_XML_XMLELEMENT_H

#include <string>
#include <unordered_map>
#include <utility>
#include <vector>

namespace D3MCS::Utility::XML
{
	class XMLElement;

	using Index = std::wstring::const_iterator;
	using ChildMap = std::unordered_multimap<std::wstring, XMLElement>;
	using AttributeMap = std::unordered_map<std::wstring, std::wstring>;

	class XMLElement final
	{
	private:
		std::wstring sName;
		std::vector<std::wstring> sValue;
		ChildMap sChildMap;
		AttributeMap sAttributeMap;
		
	public:
		XMLElement() = default;
		XMLElement(Index &iCurrent, const Index &iEnd);
		XMLElement(const XMLElement &sSrc);
		XMLElement(XMLElement &&sSrc);
		~XMLElement() = default;
		
	public:
		XMLElement &operator=(const XMLElement &sSrc);
		XMLElement &operator=(XMLElement &&sSrc);
		
	public:
		inline const std::wstring &name() const;
		inline const std::vector<std::wstring> &value() const;
		inline ChildMap::_Paircc findChild(const std::wstring &sChildName) const;
		inline const std::wstring *findAttribute(const std::wstring &sChildName) const;

	private:
		void parseElement(Index &iCurrent, const Index &iEnd);
	};

	inline const std::wstring &XMLElement::name() const
	{
		return this->sName;
	}

	inline const std::vector<std::wstring> &XMLElement::value() const
	{
		return this->sValue;
	}

	inline ChildMap::_Paircc XMLElement::findChild(const std::wstring &sChildName) const
	{
		return this->sChildMap.equal_range(sChildName);
	}

	inline const std::wstring *XMLElement::findAttribute(const std::wstring &sChildName) const
	{
		auto iIndex{this->sAttributeMap.find(sChildName)};

		return iIndex != this->sAttributeMap.cend() ? &iIndex->second : nullptr;
	}
}

#endif
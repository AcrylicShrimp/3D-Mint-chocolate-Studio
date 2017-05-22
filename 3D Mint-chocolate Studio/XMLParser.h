
/*
	2017.05.21
	Created by AcrylicShrimp.
*/

#ifndef _CLASS_XMLPARSER_XMLPARSER_H

#define _CLASS_XMLPARSER_XMLPARSER_H

#include "XMLElement.h"

#include <codecvt>
#include <fstream>
#include <locale>
#include <regex>
#include <sstream>
#include <string>
#include <unordered_map>

namespace D3MCS::Utility::XML
{
	class XMLParser final
	{
	private:
		XMLParser() = delete;
		XMLParser(const XMLParser &sSrc) = delete;
		XMLParser(XMLParser &&sSrc) = delete;
		~XMLParser() = delete;
		
	private:
		XMLParser &operator=(const XMLParser &sSrc) = delete;
		XMLParser &operator=(XMLParser &&sSrc) = delete;
		
	public:
		static std::unordered_multimap<std::wstring, XMLElement> parseXMLFromFile(const wchar_t *pXMLPath);
		static std::unordered_multimap<std::wstring, XMLElement> parseXMLFromContent(const std::wstring &sXMLContent);
	};
}

#endif
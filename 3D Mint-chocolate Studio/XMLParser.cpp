
/*
	2017.05.21
	Created by AcrylicShrimp.
*/

#include "XMLParser.h"

namespace D3MCS::Utility::XML
{
	std::unordered_multimap<std::wstring, XMLElement> XMLParser::parseXMLFromFile(const wchar_t *pXMLPath)
	{
		std::wifstream sInput{pXMLPath, std::wifstream::in};

		if (!sInput.is_open())
			return std::unordered_multimap<std::wstring, XMLElement>{};

		sInput.imbue(std::locale(std::locale::empty(), new std::codecvt_utf8<wchar_t>()));

		std::wstringstream sStream;
		sStream << sInput.rdbuf();

		return XMLParser::parseXMLFromContent(sStream.str());
	}

	std::unordered_multimap<std::wstring, XMLElement> XMLParser::parseXMLFromContent(const std::wstring &sXMLContent)
	{
		std::wregex sProlog{L"<\\?xml[\\s\\S]*\\?>"};
		std::wregex sComment{L"<!--(?:(?!--)[\\s\\S])*-->"};
		auto sContent{std::regex_replace(std::regex_replace(sXMLContent, sComment, L""), sProlog, L"")};

		auto iCurrent{sContent.cbegin()};
		auto iEnd{sContent.cend()};
		std::unordered_multimap<std::wstring, XMLElement> sElementMap;

		for (auto iCurrent{sContent.cbegin()}, iEnd{sContent.cend()}; iCurrent != iEnd;)
		{
			while (iCurrent != iEnd &&
				(*iCurrent == ' ' ||
				   *iCurrent == '\r' ||
				   *iCurrent == '\n' ||
				   *iCurrent == '\t'))
				++iCurrent;

			XMLElement sRoot{iCurrent, iEnd};

			if (sRoot.name().empty())
				return std::unordered_multimap<std::wstring, XMLElement>{};

			sElementMap.emplace(sRoot.name(), std::move(sRoot));
		}

		return sElementMap;
	}
}
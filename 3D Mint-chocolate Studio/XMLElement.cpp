
/*
	2017.05.20
	Created by AcrylicShrimp.
*/

#include "XMLElement.h"

namespace D3MCS::Utility::XML
{
	XMLElement::XMLElement(Index &iCurrent, const Index &iEnd)
	{
		this->parseElement(iCurrent, iEnd);
	}

	XMLElement::XMLElement(const XMLElement &sSrc) :
		sName{sSrc.sName},
		sValue{sSrc.sValue},
		sChildMap{sSrc.sChildMap},
		sAttributeMap{sSrc.sAttributeMap}
	{
		//Empty.
	}

	XMLElement::XMLElement(XMLElement &&sSrc) :
		sName{std::move(sSrc.sName)},
		sValue{std::move(sSrc.sValue)},
		sChildMap{std::move(sSrc.sChildMap)},
		sAttributeMap{std::move(sSrc.sAttributeMap)}
	{
		//Empty.
	}

	XMLElement &XMLElement::operator=(const XMLElement &sSrc)
	{
		if (&sSrc == this)
			return *this;

		this->sName = sSrc.sName;
		this->sValue = sSrc.sValue;
		this->sChildMap = sSrc.sChildMap;
		this->sAttributeMap = sSrc.sAttributeMap;

		return *this;
	}

	XMLElement &XMLElement::operator=(XMLElement &&sSrc)
	{
		if (&sSrc == this)
			return *this;

		this->sName = std::move(sSrc.sName);
		this->sValue = std::move(sSrc.sValue);
		this->sChildMap = std::move(sSrc.sChildMap);
		this->sAttributeMap = std::move(sSrc.sAttributeMap);

		return *this;
	}

	void XMLElement::parseElement(Index &iCurrent, const Index &iEnd)
	{
		if (iCurrent == iEnd || *iCurrent != L'<')
			return;

		++iCurrent;

		while (iCurrent != iEnd &&
			   *iCurrent == L' ' ||
			   *iCurrent == L'\n' ||
			   *iCurrent == L'\r' ||
			   *iCurrent == L'\t')
		{
			++iCurrent;
			continue;
		}

		if (iCurrent == iEnd)
			return;

		{
			std::wstring sNameBuffer;

			while (iCurrent != iEnd &&
				   *iCurrent != L' ' &&
				   *iCurrent != L'\n' &&
				   *iCurrent != L'\r' &&
				   *iCurrent != L'\t' &&
				   *iCurrent != L'/' &&
				   *iCurrent != L'>' &&
				   *iCurrent != L'<')
				sNameBuffer += *(iCurrent++);

			this->sName = std::move(sNameBuffer);
		}

		{
			std::wstring sAttributeNameBuffer;
			std::wstring sAttributeValueBuffer;

			while (iCurrent != iEnd &&
				   *iCurrent != L'>' &&
				   *iCurrent != L'/')
			{
				if (*iCurrent == L' ' ||
					*iCurrent == L'\n' ||
					*iCurrent == L'\r' ||
					*iCurrent == L'\t')
				{
					++iCurrent;
					continue;
				}

				sAttributeNameBuffer.clear();
				sAttributeValueBuffer.clear();

				while (iCurrent != iEnd &&
					   *iCurrent != L' ' &&
					   *iCurrent != L'\n' &&
					   *iCurrent != L'\r' &&
					   *iCurrent != L'\t' &&
					   *iCurrent != L'>' &&
					   *iCurrent != L'/' &&
					   *iCurrent != L'=')
					sAttributeNameBuffer += *(iCurrent++);

				if (iCurrent != iEnd &&
					(*iCurrent == L' ' ||
					*iCurrent == L'\n' ||
					*iCurrent == L'\r' ||
					*iCurrent == L'\t'))
					++iCurrent;

				if (iCurrent == iEnd || *iCurrent != L'=')
					continue;

				++iCurrent;

				if (iCurrent != iEnd &&
					(*iCurrent == L' ' ||
					*iCurrent == L'\n' ||
					*iCurrent == L'\r' ||
					*iCurrent == L'\t'))
					++iCurrent;

				if (iCurrent == iEnd || *iCurrent != L'"')
					continue;

				++iCurrent;

				while (iCurrent != iEnd &&
					   *iCurrent != L'"')
					sAttributeValueBuffer += *(iCurrent++);

				this->sAttributeMap[sAttributeNameBuffer] = sAttributeValueBuffer;

				if (iCurrent != iEnd &&
					*iCurrent == L'"')
					++iCurrent;
			}
		}

		if (iCurrent == iEnd)
		{
			this->sName.clear();
			this->sAttributeMap.clear();

			return;
		}

		if (*iCurrent == L'/')
		{
			++iCurrent;

			while (iCurrent != iEnd &&
				   *iCurrent != L'>')
				++iCurrent;

			if (iCurrent != iEnd)
				++iCurrent;

			return;
		}

		++iCurrent;

		while (iCurrent != iEnd)
		{
			if (*iCurrent != L'<')
			{
				std::wstring sValueBuffer;

				while (iCurrent != iEnd &&
					   *iCurrent != L'<')
					sValueBuffer += *(iCurrent++);

				auto nIndex{sValueBuffer.find_last_not_of(L" \n\r\t")};

				if (nIndex != std::wstring::npos)
					sValueBuffer = sValueBuffer.substr(0, nIndex + 1);

				nIndex = sValueBuffer.find_first_not_of(L" \n\r\t");

				if (nIndex != std::wstring::npos)
					sValueBuffer = sValueBuffer.substr(nIndex);

				this->sValue.emplace_back(std::move(sValueBuffer));

				continue;
			}

			auto iTemp{iCurrent};
			++iCurrent;

			while (iCurrent != iEnd &&
				(*iCurrent == L' ' ||
				   *iCurrent == L'\n' ||
				   *iCurrent == L'\r' ||
				   *iCurrent == L'\t'))
				++iCurrent;

			if (iCurrent == iEnd)
			{
				this->sName.clear();
				this->sChildMap.clear();
				this->sAttributeMap.clear();

				return;
			}

			if (*iCurrent != L'/')
			{
				XMLElement sChild{iTemp, iEnd};

				if (sChild.sName.empty())
				{
					this->sName.clear();
					this->sChildMap.clear();
					this->sAttributeMap.clear();

					return;
				}

				this->sChildMap.emplace(sChild.sName, std::move(sChild));
				iCurrent = iTemp;

				continue;
			}

			++iCurrent;

			while (iCurrent != iEnd &&
				(*iCurrent == L' ' ||
				   *iCurrent == L'\n' ||
				   *iCurrent == L'\r' ||
				   *iCurrent == L'\t'))
				++iCurrent;

			std::wstring sNameBuffer;

			while (iCurrent != iEnd &&
				   *iCurrent != L' ' &&
				   *iCurrent != L'\n' &&
				   *iCurrent != L'\r' &&
				   *iCurrent != L'\t' &&
				   *iCurrent != L'/' &&
				   *iCurrent != L'>' &&
				   *iCurrent != L'<')
				sNameBuffer += *(iCurrent++);

			if (sNameBuffer != this->sName)
			{
				this->sName.clear();
				this->sChildMap.clear();
				this->sAttributeMap.clear();

				return;
			}

			while (iCurrent != iEnd &&
				   *iCurrent != L'>')
				++iCurrent;

			if (iCurrent != iEnd)
				++iCurrent;

			return;
		}
	}
}
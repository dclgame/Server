
#ifndef H_GUID_H
#define H_GUID_H

#include "NFPlatform.h"
#include <iostream>
#include <stdio.h>
#include <stdlib.h>
#include "HtString.h"


namespace module
{
	struct GUID
	{
		INT64 nData64;
		INT64 nHead64;

		GUID()
		{
			nData64 = 0;
			nHead64 = 0;
		}

		GUID(INT64 nHeadData, INT64 nData)
		{
			nHead64 = nHeadData;
			nData64 = nData;
		}

		GUID(const GUID& xData)
		{
			nHead64 = xData.nHead64;
			nData64 = xData.nData64;
		}

		GUID& operator=(const GUID& xData)
		{
			nHead64 = xData.nHead64;
			nData64 = xData.nData64;

			return *this;
		}

		const INT64 GetData() const
		{
			return nData64;
		}

		const INT64 GetHead() const
		{
			return nHead64;
		}

		void SetData(const INT64 nData)
		{
			nData64 = nData;
		}

		void SetHead(const INT64 nData)
		{
			nHead64 = nData;
		}

		bool IsNull() const
		{
			return 0 == nData64 && 0 == nHead64;
		}

		bool operator == (const GUID& id) const
		{
			return this->nData64 == id.nData64 && this->nHead64 == id.nHead64;
		}

		bool operator != (const GUID& id) const
		{
			return this->nData64 != id.nData64 || this->nHead64 != id.nHead64;
		}

		bool operator < (const GUID& id) const
		{
			if (this->nHead64 == id.nHead64)
			{
				return this->nData64 < id.nData64;
			}

			return this->nHead64 < id.nHead64;
		}

		std::string ToString() const
		{
			return HtString::StrConvertFromLong(nHead64) + "-" + HtString::StrConvertFromLong(nData64);
			//return lexical_cast<std::string>(nHead64)+"-" + lexical_cast<std::string>(nData64);
		}

		bool FromString(const std::string& strID)
		{
			size_t nStrLength = strID.length();
			size_t nPos = strID.find('-');
			if (nPos == std::string::npos)
			{
				return false;
			}

			std::string strHead = strID.substr(0, nPos);
			std::string strData = "";
			if (nPos + 1 < nStrLength)
			{
				strData = strID.substr(nPos + 1, nStrLength - nPos);
			}

			try
			{
				nHead64 = HtString::StrConvertToInt(strHead);
				nData64 = HtString::StrConvertToInt(strData);
				//nHead64 = lexical_cast<INT64>(strHead);
				//nData64 = lexical_cast<INT64>(strData);

				return true;
			}
			catch (...)
			{
				return false;
			}
		}
	};

}


#endif


#ifndef H_Guid_H
#define H_Guid_H

#include "Define.h"
#include <iostream>
#include <stdio.h>
#include <stdlib.h>
#include "HtString.h"


namespace module
{
	struct Guid
	{
		INT64 nData64;
		INT64 nHead64;

		Guid()
		{
			nData64 = 0;
			nHead64 = 0;
		}

		Guid(INT64 nHeadData, INT64 nData)
		{
			nHead64 = nHeadData;
			nData64 = nData;
		}

		Guid(const Guid& xData)
		{
			nHead64 = xData.nHead64;
			nData64 = xData.nData64;
		}

		Guid& operator=(const Guid& xData)
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

		bool operator == (const Guid& id) const
		{
			return this->nData64 == id.nData64 && this->nHead64 == id.nHead64;
		}

		bool operator != (const Guid& id) const
		{
			return this->nData64 != id.nData64 || this->nHead64 != id.nHead64;
		}

		bool operator < (const Guid& id) const
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

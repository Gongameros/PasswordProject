#include "Cipher.h"
#include <sstream>

std::string CryptString(std::string text)
{
	std::string cryptedData = "";
	for (size_t i = 0; i < text.size(); i++)
	{
		int asciiNumber = static_cast<int>(text[i]);
		std::stringstream ss;
		ss << asciiNumber;
		std::string strAsciiNumber;
		ss >> strAsciiNumber;
		for (size_t j = 0; j < strAsciiNumber.size(); j++)
		{
			switch (strAsciiNumber[j])
			{
				case '0':
					cryptedData += "@#62)52";
					continue;
				case '1':
					cryptedData += "%4210";
					continue;
				case '2':
					cryptedData += "%!=76";
					continue;
				case '3':
					cryptedData += "^5353!#";
					continue;
				case '4':
					cryptedData += "#46.315";
					continue;
				case '5':
					cryptedData += "'fg34P`";
					continue;
				case '6':
					cryptedData += ",+53DgW*";
					continue;
				case '7':
					cryptedData += "@#65)";
					continue;
				case '8':
					cryptedData += "&%9*/72";
					continue;
				case '9':
					cryptedData += "%446)%!";
					continue;
				
			}
		}

		
	}
	return cryptedData;
}

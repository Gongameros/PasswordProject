#include "FileLogic.h"

void ReadClearFile(std::vector<pss::Password>& passwordsArr, std::string fileName)
{
	std::ifstream passwordFile(fileName);

	if (passwordFile)
	{
		std::string encryptPassword = generatePasswordForDocument(fileName);
		std::string encryptPasswordByUser;
		std::string cryptData = "";

		std::cout << "Type password to open the file." << std::endl;
		getline(std::cin, encryptPasswordByUser);
		if (encryptPassword == encryptPasswordByUser)
		{
			std::string line;
			size_t firstIndex = 0;
			size_t secondIndex = 0;
			while (getline(passwordFile, line))
			{

				if (secondIndex == 0)
				{
					std::string realPassword = line.substr(10);
					passwordsArr.push_back(realPassword);
					secondIndex++;
					continue;
				}

				if (secondIndex == 1)
				{
					std::string realName = line.substr(6);
					passwordsArr[firstIndex].setCompanyName(realName);
					secondIndex++;
					continue;
				}

				if (secondIndex == 2)
				{
					std::string realCategory = line.substr(10);
					passwordsArr[firstIndex].setCategory(realCategory);
					secondIndex++;
					continue;
				}

				if (secondIndex == 3)
				{
					std::string realLogin = line.substr(7);
					passwordsArr[firstIndex].setLogin(realLogin);
					secondIndex++;
					continue;
				}

				if (secondIndex == 4)
				{
					secondIndex = 0;
					firstIndex++;
				}
			}
		}

		else
		{
			std::cout << "File is locked." << std::endl;
		}
	}

	else
		std::cout << "Wrong name of file or absolute path.";
}
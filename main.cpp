#include <iostream>
#include <fstream>
#include <string>
#include <sstream>
#include <vector>
#include <algorithm>
#include "PasswordClass.h"
#include "PasswordAlgorithms.h"


int main()
{
	bool isRunning = true;

	std::cout << "Type name of file located in the program`s folder or provide absoulte directory to the existing file." << std::endl;

	std::vector<pss::Password> passwordsArr;
	std::string fileName;

	getline(std::cin, fileName);

	std::ifstream passwordFile(fileName);
	std::ofstream cryptedFile;

	if (passwordFile)
	{
		std::string encryptPassword = generatePasswordForDocument(fileName);
		std::string encryptPasswordByUser;
		std::string cryptData = "";

		std::cout << "Type password to open the file." << std::endl;
		std::cin >> encryptPasswordByUser;
		if(encryptPassword == encryptPasswordByUser)
		{ 
			std::string line;
			while (getline(passwordFile, line))
			{ 
				passwordsArr.push_back(line);
			}
				

			passwordsArr[0].setCategory("Web");
			passwordsArr[2].setCategory("Web");
			passwordsArr[1].setCategory("currency");

			passwordsArr[0].setCompanyName("Pornhub");
			passwordsArr[2].setCompanyName("Udemy");
			passwordsArr[1].setCompanyName("Binance");

			std::cout << std::endl;

			std::cout << "Before sorting" << std::endl<<std::endl;
			for (auto i : passwordsArr)
				std::cout << i << std::endl;

			//sort elements by category and company name
			std::sort(passwordsArr.begin(), passwordsArr.end(), compareByNameAndCategory);
			std::cout << "After sorting" << std::endl << std::endl;
			for (auto i : passwordsArr)
				std::cout << i << std::endl;


			//delete elements by category
			std::cout << std::endl << std::endl;
			deleteElementsByCategory(passwordsArr, "Web");
			for (auto i : passwordsArr)
				std::cout << i << std::endl;
		}

		else
		{
			std::cout << "File is locked." << std::endl;
		}
	}

	else
		std::cout << "Wrong name of file or absolute path.";


	

	passwordFile.close();

}
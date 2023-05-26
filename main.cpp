#include <iostream>
#include <fstream>
#include <string>
#include <sstream>
#include <vector>
#include <algorithm>
#include "PasswordClass.h"
#include "PasswordAlgorithms.h"
#include "Cipher.h"
#include "FileLogic.h"


int main()
{
	bool isRunning = true;

	std::vector<pss::Password> passwordsArr;
	
	std::string ofFileName;
	
	std::ofstream cryptedFile;

	while(isRunning)
	{
		std::cout << "Type name of file located in the program`s folder or provide absoulte directory to the existing file." << std::endl;

		std::string fileName;

		getline(std::cin, fileName);

		ReadClearFile(passwordsArr, fileName);

		std::cout << std::endl;
		
		for (auto i : passwordsArr)
			std::cout << i << std::endl;

		isRunning = false;

	}

	cryptedFile.close();

}
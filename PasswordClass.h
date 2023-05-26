#pragma once
#include <iostream>
#include <ostream>
#include <istream>
#include <string>

namespace pss
{
	class Password
	{
	private:
		std::string password;
		std::string name;
		std::string login;
		std::string category;

	public:
		Password(std::string password);

		Password(std::string password, std::string name, std::string login, std::string category);

		void setCategory(std::string category);

		void setCompanyName(std::string name);

		void setLogin(std::string login);

		std::string getCompanyName();

		std::string getPassword();

		std::string getLogin();

		std::string getCategory();

		friend std::ostream& operator << (std::ostream& os, const Password& password)
		{
			os << "Login: " << password.login << std::endl;
			os << "Password: " << password.password << std::endl;
			os << "Company: " << password.name << std::endl;
			os << "Category: " << password.category << std::endl;
			return os;
		}

	};
}
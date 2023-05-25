#include "PasswordClass.h"

pss::Password::Password(std::string password)
{
	this->password = password;
}

pss::Password::Password(std::string password, std::string name, std::string login, std::string catgory)
{
	this->password = password;
	this->name = name;
	this->login = login;
	this->category = category;
}

void pss::Password::setCategory(std::string category)
{
	this->category = category;
}

void pss::Password::setCompanyName(std::string name)
{
	this->name = name;
}

void pss::Password::setLogin(std::string login)
{
	this->login = login;
}

std::string pss::Password::getCompanyName()
{
	return name;
}

std::string pss::Password::getPassword()
{
	return password;
}

std::string pss::Password::getLogin()
{
	return login;
}

std::string pss::Password::getCategory()
{
	return category;
}
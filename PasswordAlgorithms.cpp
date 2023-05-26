#include "PasswordAlgorithms.h"

bool compareByNameAndCategory (pss::Password& item1, pss::Password& item2) 
{
    if (item1.getCompanyName() == item2.getCompanyName()) {
        return item1.getCategory() < item2.getCategory();
    }
    return item1.getCompanyName() < item2.getCompanyName();
}

void deleteElementsByCategory(std::vector<pss::Password> &passwordsArr, std::string category)
{
    for (size_t i = 0; i < passwordsArr.size(); i++)
    {
        if (category == passwordsArr[i].getCategory())
        { 
            passwordsArr.erase(passwordsArr.begin() + i);
            i--;
        }

    }
}

std::string generatePasswordForDocument(std::string fileName)
{
    std::string genPassword = "";
    int tempIndex = 0;

    for (size_t i = 0; i < fileName.size(); i++)
        if (fileName[i] == '/' || fileName[i] == '\\')
            tempIndex = i + 1;
            
    genPassword += fileName[tempIndex];
    for (size_t i = tempIndex + 2; i < fileName.size(); i++)
    {
        if (fileName[i] == '.' || fileName[i - 1] == '.')
            break;

        genPassword += fileName[i];
        i++;
    }

    return genPassword;
}

int findByCategory(std::vector<pss::Password>& passwordsArr, std::string category)
{
    if (passwordsArr.empty())
        throw std::exception("No passwords to find.");
    for (int i = 0; i < passwordsArr.size(); i++)
        if (passwordsArr[i].getCategory() == category)
            return i;
    throw std::exception("Element wasn`t found.");
}


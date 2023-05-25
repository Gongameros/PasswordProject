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


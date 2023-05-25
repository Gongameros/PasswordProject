#pragma once
#include <algorithm>
#include <vector>
#include "PasswordClass.h"

bool compareByNameAndCategory(pss::Password& item1, pss::Password& item2);

void deleteElementsByCategory(std::vector<pss::Password> &passwordsArr, std::string category);


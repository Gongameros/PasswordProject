#pragma once
#include <algorithm>
#include <vector>
#include "PasswordClass.h"

bool compareByNameAndCategory(pss::Password& item1, pss::Password& item2);

void deleteElementsByCategory(std::vector<pss::Password> &passwordsArr, std::string category);

std::string generatePasswordForDocument(std::string FileName);

int findByCategory(std::vector<pss::Password>& passwordsArr, std::string category);


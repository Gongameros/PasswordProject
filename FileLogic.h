#pragma once
#include "PasswordClass.h"
#include "PasswordAlgorithms.h"
#include <vector>
#include <fstream>

void ReadClearFile(std::vector<pss::Password>& passwordsArr, std::string filename);


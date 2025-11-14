#pragma once
#include <stdexcept>
#include <string>
#include "InputOutOfRangeException.h"


int inputInt(const std::string &pt);
int inputPosInt(const std::string &pt);
float inputFloat(const std::string &pt);
float inputPosFloat(const std::string &pt);

std::string inputStr(const std::string &pt);
std::string inputWord(const std::string &pt);
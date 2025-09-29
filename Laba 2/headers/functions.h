#pragma once 

#include "string.h"
#include <iostream>
#include <limits>

void clearInputBuffer();
int menu();
String concatenateStringMultipleTimes(const String &original, int count);
void inputString(String& str1, String& str2);
void concatenateString(const String& str1, const String& str2);
void multiplyString(const String& str1,const String& str2);
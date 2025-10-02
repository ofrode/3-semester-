#pragma once 

#include <iostream>
#include <string>
#include <span>
#include "check.h"
#include "Person.h"
#include "Tourist.h"
#include "Entrepreneur.h"
#include "Chelnok.h"

Person* createPerson();
void addPerson(Person**& people, int& count);
void createList(Person**& people, int& count);
void printAll(std::span<Person*> people);



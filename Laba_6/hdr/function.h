#pragma once

#include "Person.h"
#include "Entrepreneur.h"
#include "Tourist.h"
#include "Chelnok.h"
#include "input.h"
#include <iostream>

void showMainMenu();
void handleChoice(int choice, Person*& current);
void menuPerson(Person*& current);
void menuEntrepreneur(Person*& current);
void menuTourist(Person*& current);
void menuShuttler(Person*& current);
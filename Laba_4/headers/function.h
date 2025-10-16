#ifndef FUNCTION_H
#define FUNCTION_H

#include "Worker.h"
#include "Commission.h"
#include "Staff.h"
#include "Hourly.h"

void addWorker(Worker ***workers, int &count);
void showWorkers(Worker **workers, int count);
void deleteAll(Worker **workers, int count);

#endif
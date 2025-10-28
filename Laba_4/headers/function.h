#ifndef FUNCTION_H
#define FUNCTION_H

#include "Worker.h"
#include "Commission.h"
#include "Staff.h"
#include "Hourly.h"
#include <span>

void addWorker(Worker ***workers, size_t &count);
void showWorkers(std::span<Worker *> workers);
void deleteAll(Worker **workers, size_t count);

#endif
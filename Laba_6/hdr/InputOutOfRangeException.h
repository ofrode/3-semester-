#pragma once
#include "InputException.h"

class InputOutOfRange : public InputError {
public:
    explicit InputOutOfRange(const std::string& what_arg)
        : InputError(what_arg) {}
    
    explicit InputOutOfRange(const char* what_arg)
        : InputError(what_arg) {}
};
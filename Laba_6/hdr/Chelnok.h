#pragma once
#include "Entrepreneur.h"
#include "Tourist.h"
#include <string>
#include <string_view>

class Chelnok : public Entrepreneur, public Tourist {
private:
    std::string* shoppingAddresses{nullptr};
    std::string inputShoppingAddress(int index) const;
    int shopCount{0};
    int shopCapacity{0};

    void ensureCapacity();

public:
    Chelnok();
    ~Chelnok() override;

    Chelnok(const Chelnok& other);
    Chelnok& operator=(const Chelnok& other);
    Chelnok(Chelnok&& other) noexcept;
    Chelnok& operator=(Chelnok&& other) noexcept;

    void addShoppingAddress(std::string_view address);
    void printShoppingAddresses() const;

    void inputData() override;
    void printInfo() const override;
};
//
// Created by illya on 11/15/2018.
//

#ifndef OOP_LAB4_FOODSupplier_H
#define OOP_LAB4_FOODSupplier_H

#include "List.h"

#include <vector>

class FoodSupplier {
private:
    std::vector<priceList> availableFood;
public:
    FoodSupplier();
    ~FoodSupplier() = default;
    const std::vector<priceList> &getAvailableFood() const;
};


#endif //OOP_LAB4_FOODSupplier_H

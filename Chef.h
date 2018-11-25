//
// Created by illya on 11/14/2018.
//

#ifndef OOP_LAB4_CHEF_H
#define OOP_LAB4_CHEF_H

#pragma once

#include "Human.h"
#include "List.h"

#include <vector>

class Chef: public Human {
private:

public:
    Chef();
    ~Chef() = default;
    priceList generateDish(std::vector<amountList> availableIngredients, std::vector<priceList> orderableIngredients);
    std::vector<priceList> generateMenu(std::vector<amountList> availableIngredients, std::vector<priceList> orderableIngredients);
    std::vector<amountList> orderIngredients(std::vector<amountList>& chefDesiredIngredients, const std::vector<priceList> orderableIngredients);//TODO what does that warning mean
    void prepareOrder(std::vector<selectionList> clientsOrder, std::vector<amountList>& availableIngredients, std::vector<priceList> menu);
    std::vector<amountList> checkForIngredientShortage(std::vector<amountList>& availableIngredients, std::vector<amountList> &chefDesiredIngredients);
};


#endif //OOP_LAB4_CHEF_H

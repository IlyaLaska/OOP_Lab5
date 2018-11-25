//
// Created by illya on 11/14/2018.
//

#ifndef OOP_LAB4_RESTAURANT_H
#define OOP_LAB4_RESTAURANT_H

#pragma once

#include "List.h"
#include "Headwaiter.h"
#include "Waiter.h"
#include "Chef.h"
#include "Administrator.h"
#include "FoodSupplier.h"
#include "Client.h"

#include <vector>


class Restaurant {
private:
//    int clientCounter;
    int tablesAmount = 20;
    int balance = 0;

    std::vector<priceList> menu;
    std::vector<priceList> orderableIngredients;

    std::vector<amountList> availableIngredients;
    std::vector<amountList> chefDesiredIngredients;//filled by chef at the end of the day. Administrator copies it to availableIngredients

    std::vector<selectionList> reservedTables;
    std::vector<selectionList> occupiedTables;

    std::vector<amountList> orders;//copy menu here increment amount on order
    std::vector<selectionList> clientsOrder;

    Headwaiter headwaiter;
    Waiter waiter;
    Chef chef;
    Administrator administrator;
    FoodSupplier foodSupplier;
public:
    Restaurant();
    ~Restaurant() = default;
    const std::vector<priceList> &getOrderableIngredients() const;
    void workOneDay();
//    List<amountList> orderIngredients();
};


#endif //OOP_LAB4_RESTAURANT_H

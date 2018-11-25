//
// Created by illya on 11/14/2018.
//

#ifndef OOP_LAB4_ADMINISTRATOR_H
#define OOP_LAB4_ADMINISTRATOR_H

#pragma once

#include "Human.h"
#include "List.h"
#include "Client.h"

#include <vector>

class Administrator: public Human {
public:
    Administrator();
    ~Administrator() = default;
    std::vector<selectionList> formReservedTablesList(std::vector<selectionList>& reservedTables);
    std::vector<amountList> orderIngredients(std::vector<amountList> &chefDesiredIngredients, std::vector<amountList> &availableIngredients, const std::vector<priceList> &orderableIngredients, int &balance);
    void updateBalance(Client* client, int& dailyProfit, int& balance);
    void coutProfits(int& yesterdaysBalance, int& dailyProfit, int& balance, int& dailyExpenses) const;
    void coutOrders(const std::vector<amountList>& orders) const;
    void updateOrderLogs(const std::vector<priceList>& menu, std::vector<amountList>& orders, std::vector<selectionList>& clientsOrder);
};


#endif //OOP_LAB4_ADMINISTRATOR_H

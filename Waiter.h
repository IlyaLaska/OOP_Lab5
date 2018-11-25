//
// Created by illya on 11/14/2018.
//

#ifndef OOP_LAB4_WAITER_H
#define OOP_LAB4_WAITER_H

#pragma once

#include "Human.h"
#include "Client.h"

#include <vector>

class Waiter: public Human {
public:
    Waiter();
    ~Waiter() = default;
    std::vector<int> takeOrder(const Client* client, const std::vector<priceList> menu);//why do i need 1st const, not second
    std::vector<selectionList> takeOrder(const Client* client, std::vector<selectionList>& clientsOrder, const std::vector<priceList> menu);//why do i need 1st const, not second
    std::vector<amountList> fillOrders(std::vector<selectionList>& clientsOrder, std::vector<amountList>& orders);
    void bringOrder(Client* client);
    int bringCheque(std::vector<selectionList> clientsOrder, std::vector<priceList> menu);
    void clearTable(Client* client, std::vector<selectionList>& clientsOrder, std::vector<selectionList>& occupiedTables);
};


#endif //OOP_LAB4_WAITER_H

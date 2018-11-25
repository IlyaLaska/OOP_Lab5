//
// Created by illya on 11/14/2018.
//

#include "Waiter.h"
#include <iostream>

#include "macros.h"

using namespace std;

Waiter::Waiter() : Human() {
    this->name = "Waiter";

}

std::vector<int> Waiter::takeOrder(const Client *client, const std::vector<priceList> menu) {
    int dishesAmount = (rand()%3) + 1;//can order 1-3 dishes
    std::vector<int> orderCodes(dishesAmount);
    for (int i = 0; i < dishesAmount; ++i) {
        int dish = rand()%menu.size();//choose one from menu
        orderCodes[i] = dish;
    }
    return orderCodes;
}

std::vector<selectionList> Waiter::takeOrder(const Client *client, std::vector<selectionList>& clientsOrder, const std::vector<priceList> menu) {
    int dishesAmount = (rand()%menu.size()) + 1;//can order 1 - menu.size() dishes
//    std::vector<int> orderCodes(dishesAmount);
//    cout  << "menu.size(): " << menu.size() << endl;
    for (int i = 0; i < dishesAmount; ++i) {
        int dish = rand()%menu.size();//choose one from menu
//        cout << "DISH: " << dish << " || flag: " << clientsOrder[dish].flag << " || i: " << i << endl;
        if(clientsOrder[dish].flag) {
            i--;
            continue;
        }
        clientsOrder[dish].flag = true;
    }
    return clientsOrder;
}

std::vector<amountList> Waiter::fillOrders(std::vector<selectionList> &clientsOrder, std::vector<amountList> &orders) {
    for (int i = 0; i < clientsOrder.size(); ++i) {
        if(clientsOrder[i].flag) orders[i].amount++;
    }
    return orders;
}

void Waiter::bringOrder(Client *client) {
    RL std::cout << "The waiter brings " << client->getName() << " his order!" << std::endl;
}

int Waiter::bringCheque(std::vector<selectionList> clientsOrder, std::vector<priceList> menu) {
    int total = 0;
    for (int i = 0; i < menu.size(); ++i) {
        if(clientsOrder[i].flag) total += menu[i].price;
    }
    int compulsory20PercentTipBecauseWeAreDicks = static_cast<int>(total * 0.2);
    return total+compulsory20PercentTipBecauseWeAreDicks;
}

void Waiter::clearTable(Client* client, std::vector<selectionList>& clientsOrder, std::vector<selectionList>& occupiedTables) {
    for (int i = 0; i < clientsOrder.size(); ++i) {
        clientsOrder[i].flag = false;
    }
    occupiedTables[client->getTableNo()].flag = false;
}

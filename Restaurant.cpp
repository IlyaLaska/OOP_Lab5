//
// Created by illya on 11/14/2018.
//

#include "Restaurant.h"
#include <ctime>
#include <cstdlib>
#include <cstring>
#include <memory>

#include "macros.h"

#include <iostream>
using namespace std;

Restaurant::Restaurant() {
    srand(static_cast<unsigned int>(time(NULL)));
            //forming reservedTables here since it only has to be done once and only updated every day by administrator
    reservedTables = vector<selectionList>(tablesAmount);
    occupiedTables = vector<selectionList>(tablesAmount);
    //filling reservedTables & occupiedTables
    char buffer[6];
    for (int j = 0; j < tablesAmount; ++j) {
        reservedTables[j].flag = false;
        occupiedTables[j].flag = false;
        sprintf(buffer, "%i", j+1);
        if(j == 0) strcat(buffer, "st");
        if(j == 1) strcat(buffer, "nd");
        if(j == 2) strcat(buffer, "rd");
        if(j > 2) strcat(buffer, "th");
        reservedTables[j].name = strdup(buffer);
        occupiedTables[j].name = strdup(buffer);
    }

    headwaiter = Headwaiter();
    waiter = Waiter();
    chef = Chef();
    administrator = Administrator();
    foodSupplier = FoodSupplier();

    orderableIngredients = foodSupplier.getAvailableFood();

    availableIngredients = vector<amountList>(orderableIngredients.size());
    chefDesiredIngredients = vector<amountList>(orderableIngredients.size());
    for (int l = 0; l < orderableIngredients.size(); ++l) {
        availableIngredients[l].name = orderableIngredients[l].name;
        chefDesiredIngredients[l].name = orderableIngredients[l].name;
        availableIngredients[l].amount = 0;
        chefDesiredIngredients[l].amount = 0;
    }

    chefDesiredIngredients = chef.orderIngredients(chefDesiredIngredients, orderableIngredients);

//    availableIngredients = List<amountList>(orderableIngredients.length);
//    for (int m = 0; m < availableIngredients.length; ++m) {
//        availableIngredients[m].amount = 0;
//        availableIngredients[m].name = strdup(orderableIngredients[m].name);
//    }

    availableIngredients = administrator.orderIngredients(chefDesiredIngredients, availableIngredients, orderableIngredients, balance);
    menu = chef.generateMenu(availableIngredients, orderableIngredients);
    reservedTables = administrator.formReservedTablesList(reservedTables);

    orders = vector<amountList>(menu.size());
    clientsOrder = vector<selectionList>(menu.size());
    //filling orders & clientsOrder(template)
    for (int k = 0; k < menu.size(); ++k) {
        orders[k].amount = 0;
        clientsOrder[k].flag = false;
        orders[k].name = menu[k].name;
        clientsOrder[k].name = menu[k].name;
    }

    RL std::cout << "MENU:" << endl;
    for (int i = 0; i < menu.size(); ++i) {
        RL std::cout << menu[i].name << ": " << menu[i].price << endl;
    }
    RL std::cout << "Balance: " << balance << endl;
}

const vector<priceList> &Restaurant::getOrderableIngredients() const {
    return orderableIngredients;
}

void Restaurant::workOneDay() {
    int yesterdaysBalance = balance;
    int dailyProfit = 0;
    int dailyExpenses = 0;
    int balanceChange = 0;
    //roll d20, if > 10 new Client arrives
    int roll;
    int clientPossibilities = 15 * 6; //15 working hours * 6 customers per hour max
    int clearTable;//var to simulate the probability of one client leaving
    Client* client;// = new Client();
    for (int i = 0; i < clientPossibilities; ++i) {
        roll = rand()%20;
        if(roll >= 10) {
            client = new Client();
            client->leaveCoat();
            bool freeTable = headwaiter.findTable(client, reservedTables, occupiedTables);
//            RL std::cout << "WAS THERE A TABLE: " << freeTable << std::endl;
            if(!freeTable) {
                RL std::cout << "There was no table for " << client->getName() << ", we are very sorry." << std::endl;
                goto noFreeTables;
            }
            headwaiter.callWaiter(client);
            clientsOrder = waiter.takeOrder(client, clientsOrder, menu);
            orders = waiter.fillOrders(clientsOrder, orders);
            chef.prepareOrder(clientsOrder, availableIngredients, menu);
            chefDesiredIngredients = chef.checkForIngredientShortage(availableIngredients, chefDesiredIngredients);
            balanceChange = balance;
            availableIngredients = administrator.orderIngredients(chefDesiredIngredients, availableIngredients, orderableIngredients, balance);
            balanceChange -= balance;
            dailyExpenses += balanceChange;
            waiter.bringOrder(client);
            client->setCheque(waiter.bringCheque(clientsOrder, menu));
            administrator.updateBalance(client, dailyProfit, balance);
            waiter.clearTable(client, clientsOrder, occupiedTables);

            //if there were no free tables or after meal
            noFreeTables:
            client->takeCoat();
            headwaiter.bidFarewell(client);
            delete client;
        }//END: roll >= 10 a.k.a. client arrived
    }//END: for i < clientPossibilities - end of the working hours
    administrator.coutOrders(orders);
    administrator.coutProfits(yesterdaysBalance, dailyProfit, balance, dailyExpenses);
    administrator.formReservedTablesList(reservedTables);

    //TODO understand if this part is stupid or not (memory leaks - wise)
    menu = chef.generateMenu(availableIngredients, orderableIngredients);
    administrator.updateOrderLogs(menu, orders, clientsOrder);
}











//List<amountList> Restaurant::orderIngredients() {
////    srand(static_cast<unsigned int>(time(NULL)));
//    int availableIngredientsAmount = (rand()%10) + 25;
//    List<amountList> availableIngredients(15);
//    for (int j = 0; j < 15; ++j) {
//        availableIngredients.list[j].name = strdup(orderableIngredients.list[j].name);
//    }
//    int ingredientPos = 0;//what position to get from supplier (orderableIngredients)
//    int totalPrice = 0;
//    for (int i = 0; i < availableIngredientsAmount*6; ++i) {
//        ingredientPos = rand()%15;//get value 0-14
//        totalPrice += orderableIngredients.list[ingredientPos].price;
//        availableIngredients.list[ingredientPos].amount++;
//    }
//    balance -= totalPrice;
//    return availableIngredients;
//}



/*/
int usedPos[availableIngredientsAmount];//creating array to store all names to weed out duplicates
for (int k = 0; k < availableIngredientsAmount; ++k) {//filling it with -1 to not get false positives on check
usedPos[k] = -1;
}

for (int j = 0; j < availableIngredientsAmount; ++j) {//go through usedPos, if found same value reroll loop iteration
            if(usedPos[j] == ingredientPos) {
                i--;
                continue;
            }
        }
        usedPos[i] = ingredientPos;
//*/
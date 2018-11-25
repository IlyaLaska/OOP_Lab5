//
// Created by illya on 11/14/2018.
//

#include "Chef.h"

#include <cstdlib>
#include <ctime>
#include <cstring>

#include <iostream>
using namespace std;


Chef::Chef(): Human() {
    this->name = "Chef";
}


priceList Chef::generateDish(std::vector<amountList> availableIngredients, std::vector<priceList> orderableIngredients) {//TODO look into this buffer
    priceList dish = {new char[100], 0};
    int ingredientsAmount = (rand()%5) + 2;
    int ingredientPos;
    std::string buffer;
    for (int i = 0; i < ingredientsAmount; ++i) {
        ingredientPos = (rand()%15);
        buffer.append(availableIngredients[ingredientPos].name);
        if(i < ingredientsAmount-1) buffer.append(" and ");
        dish.price += orderableIngredients[ingredientPos].price;
    }
    dish.price += ingredientsAmount*10;//random price increase specifier
    dish.name = buffer;
    return dish;
}

std::vector<priceList> Chef::generateMenu(std::vector<amountList> availableIngredients, std::vector<priceList> orderableIngredients) {
    int dishesAmount = (rand()%14) + 2;
    std::vector<priceList> menu(dishesAmount);
    for (int i = 0; i < dishesAmount; ++i) {
        menu[i] = generateDish(availableIngredients, orderableIngredients);
    }
    return menu;
}

std::vector<amountList> Chef::orderIngredients(std::vector<amountList>& chefDesiredIngredients, const std::vector<priceList> orderableIngredients) {
    int availableIngredientsAmount = (rand()%10) + 25;
    int ingredientPos = 0;//what position to get from supplier (orderableIngredients)
    for (int i = 0; i < availableIngredientsAmount*6; ++i) {
        ingredientPos = rand()%chefDesiredIngredients.size();//get value 0-14
        chefDesiredIngredients[ingredientPos].amount++;
    }
    return chefDesiredIngredients;
}

void Chef::prepareOrder(std::vector<selectionList> clientsOrder, std::vector<amountList> &availableIngredients, std::vector<priceList> menu) {
    char delim[2] = " ";
    char* token;
    char buffer[200];
//    RL std::cout << &menu[0].name[0] << std::endl;
    for (int i = 0; i < clientsOrder.size(); ++i) {
        strcpy(buffer, &menu[i].name[0]);
        token = strtok(buffer, delim);
        while (token != nullptr) {
            if(strcmp(token, "and") != 0) {//token is an ingredient name
                for (int j = 0; j < availableIngredients.size(); ++j) {
                    if(availableIngredients[j].name.compare(token) == 0) {//token is THE ingredient
                        availableIngredients[j].amount--;
                        break;
                    }
                }
            }
            token = strtok(nullptr, delim);
        }
    }
//    for (int i = 0; i < menu.size(); ++i) {
//        for (int j = 0; j < availableIngredients.size(); ++j) {
//            if(menu[i].name.find(availableIngredients[j].name) != std::string::npos) {//go through all ingredients for each menu item
//                availableIngredients[j].amount--;
//                break;
//            }
//        }
//    }
}

std::vector<amountList> Chef::checkForIngredientShortage(std::vector<amountList> &availableIngredients, std::vector<amountList> &chefDesiredIngredients) {
    for (int i = 0; i < availableIngredients.size(); ++i) {
        if(availableIngredients[i].amount < 5) {//need to order more
            chefDesiredIngredients[i].amount += 10;
        }
    }
    return chefDesiredIngredients;
}


#include <iostream>

#include "Restaurant.h"

#define workdays 5
#define week 7

int main() {
    Restaurant rest = Restaurant();
    for (int i = 0; i < workdays; ++i) {
        rest.workOneDay();
    }
    return 0;
}
#include <iostream>
#include "Food.h"

int main()
{
    // Test member functions for Food class
    Food apple { "apple", 2, 7, false };
    std::string_view const name{ apple.getName() };
    int const Food_food_group{ apple.getFoodGroup() };
    int const Food_shelf_life{ apple.getShelfLife() };
    bool const Food_refrigerated{ apple.isRefrigerated() };
    apple.printName();
    
    // Test member functions for X class

    return 0;
}
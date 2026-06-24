#include <algorithm>
#include <array>
#include <iostream>
#include <vector>
#include "Food.h"
#include "Ingredient.h"
#include "Recipe.h"
#include "Meal.h"
#include "MealPlan.h"

// Define Recipe class member functions (normally located in Recipe.cpp)
void Recipe::addIngredient(Ingredient ingredient)
{
    m_ingredients.push_back(ingredient);
};
void Recipe::removeIngredient(Ingredient ingredient)
{
    auto it = std::find(m_ingredients.begin(), m_ingredients.end(), ingredient);
    int index = std::distance(m_ingredients.begin(), it);
    if (std::distance(m_ingredients.end(),it) != 0)  
        m_ingredients.erase(m_ingredients.begin() + index);
    else
        std::cout << "Recipe::removeIngredient(): The " << m_name << " recipe does not contiain ingredient: " << ingredient.getName() << ".\n";
};

int main()
{
    // Testing Ingredient class
    Ingredient bread {"Bread", 2, "slice(s)", ""};
    Ingredient peanutButter {"Peanut Butter", 1.5, "tbsp", ""};
    Ingredient grapeJelly {"Grape Jelly", 1, "tbsp", ""};
    Ingredient strawberryJelly {"Strawberry Jelly", 1, "tbsp", ""};

    // Testing Recipe class

    Recipe pbj {"Peanut Butter & Jelly", 5, 0, 0, 1};
    pbj.addIngredient(bread);
    pbj.addIngredient(peanutButter);
    pbj.addIngredient(grapeJelly);

    pbj.printName();
    pbj.printPrepTime();
    pbj.printCookTime();
    pbj.printAdditionalTime();
    pbj.printTotalTime();
    pbj.printServings();
    pbj.printNumIngredients();
    pbj.printIngredients();

    pbj.removeIngredient(strawberryJelly);
    pbj.removeIngredient(grapeJelly);

    pbj.printNumIngredients();
    pbj.printIngredients();

    pbj.addIngredient(strawberryJelly);
    
    pbj.printNumIngredients();
    pbj.printIngredients();

    // Testing Meal class

    Meal mon_breakfast{ pbj, 0.5 };
    std::vector<Ingredient> mon_breakfast_ingredients { mon_breakfast.getScaledIngredients() };
    Meal mon_lunch{ pbj, 1 };
    Meal mon_dinner{ pbj, 2 };
    Meal empty_meal{};

    // Testing MealPlan class
    // MealPlan empty_meal_plan{};
    // MealPlan sun_meal_plan{.sun_meals = {mon_breakfast, mon_lunch, mon_dinner}};

    return 0;
}
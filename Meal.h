#ifndef MEAL_H
#define MEAL_H
#include <array>
#include <iostream>
#include <string>
#include <vector>
#include "Ingredient.h"
#include "Recipe.h"

class Meal
{
private:
    const Recipe* m_recipe {};
    double m_desired_servings {};
public:
    // Constructor declaration
    Meal(const Recipe& recipe, double num_servings);

    // Member function declarations
    std::vector<Ingredient> getScaledIngredients() const;

};

// Constructor definition
Meal::Meal(const Recipe& recipe = {}, double desired_servings = 0)
    : m_recipe { &recipe }
    , m_desired_servings { desired_servings }
{
    // Copy and scale ingredients
    // m_ingredients = recipe.m_ingredients;
    // double scale = m_desired_servings / recipe.getServings();
    // for (size_t i = 0; i < recipe.getNumIngredients(); i++)
    // {
    //     m_ingredients[i].m_qty = recipe.getIngredients()[i].getQty() * scale;
    // }
    
}
std::vector<Ingredient> Meal::getScaledIngredients() const
{
    auto ingredients = m_recipe->getIngredients();

    double scale = m_desired_servings / m_recipe->getServings();

    for (auto& ingredient : ingredients)
    {
        ingredient.m_qty *= scale;
    }

    return ingredients;
}

#endif
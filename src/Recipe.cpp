#include <algorithm>
#include <string>
#include <vector>
#include "../include/Ingredient.h"
#include "../include/Recipe.h"
// Define non-trivial member functions for Food class

// Add an ingredient to a recipe
void Recipe::addIngredient(Ingredient ingredient)
{
    m_ingredients.push_back(ingredient);
};

// Remove an ingredient from a recipe
void Recipe::removeIngredient(Ingredient ingredient)
{
    auto it = std::find(m_ingredients.begin(), m_ingredients.end(), ingredient);
    int index = std::distance(m_ingredients.begin(), it);
    if (std::distance(m_ingredients.end(),it) != 0)  
        m_ingredients.erase(m_ingredients.begin() + index);
    else
        std::cout << "Recipe::removeIngredient(): The " << m_name << " recipe does not contiain ingredient: " << ingredient.getName() << ".\n";
};
// Add recipe to grocery list
// Add recipe to cook book

#ifndef RECIPE_H
#define RECIPE_H
#include <array>
#include <iostream>
#include <string>
#include <vector>
#include "Ingredient.h"

class Recipe
{
private:
    std::string m_name {};
    double m_prep_time {};
    double m_cook_time {};
    double m_additional_time {};
    double m_total_time {};
    double m_servings {};
    std::vector<Ingredient> m_ingredients;
public:
    // Constructor
    Recipe(std::string name, double prep_time, double cook_time, double additional_time, double servings);

    // Friends
    friend class Meal;

    // Overloaded operators
    Recipe& operator= (const Recipe& recipe);
    friend bool operator== (const Recipe& r1, const Recipe& r2);

    // Declare get member functions
    std::string_view getName() const { return m_name; }
    double getPrepTime() const { return m_prep_time; }
    double getCookTime() const { return m_cook_time; }
    double getAdditionalTime() const { return m_additional_time; }
    double getTotalTime() const { return m_total_time; }
    double getServings() const { return m_servings; }
    std::vector<Ingredient> getIngredients() const { return m_ingredients; };
    std::size_t getNumIngredients() const { return std::size(m_ingredients); };

    // Declare print member functions
    void printName() const;
    void printPrepTime() const;
    void printCookTime() const;
    void printAdditionalTime() const;
    void printTotalTime() const;
    void printServings() const;
    void printNumIngredients() const;
    void printIngredients() const;

    // Declare non-trivial member functions
    void addIngredient(Ingredient ingredient);
    void removeIngredient(Ingredient ingredient);
};

// Define constructor
Recipe::Recipe(std::string name = "", double prep_time = 0, double cook_time = 0, double additional_time = 0, double servings = 0)
    : m_name { name }
    , m_prep_time { prep_time }
    , m_cook_time { cook_time }
    , m_additional_time { additional_time }
    , m_servings { servings }
{
    m_total_time = prep_time + cook_time + additional_time;
}

// Define trivial member functions
Recipe& Recipe::operator= (const Recipe& recipe)
{
    m_name = recipe.m_name;
    m_prep_time = recipe.m_prep_time;
    m_cook_time = recipe.m_cook_time;
    m_additional_time = recipe.m_additional_time;
    m_total_time = recipe.m_total_time;
    m_servings = recipe.m_servings;
    m_ingredients = recipe.m_ingredients;

    return *this;
}

bool operator== (const Recipe& r1, const Recipe& r2)
{
    return {
        (r1.m_name == r2.m_name) &&
        (r1.m_prep_time == r2.m_prep_time) &&
        (r1.m_cook_time == r2.m_cook_time) &&
        (r1.m_additional_time == r2.m_additional_time) &&
        (r1.m_total_time == r2.m_total_time) &&
        (r1.m_servings == r2.m_servings) &&
        (r1.m_ingredients == r2.m_ingredients)
    };
}

inline void Recipe::printName() const
{
    std::cout << "Recipe Name: " << m_name << ".\n";
}
inline void Recipe::printPrepTime() const
{
    std::cout << "Prep Time: " << m_prep_time << " min.\n";
}
inline void Recipe::printCookTime() const
{
    std::cout << "Cook Time: " << m_cook_time << " min.\n";
}
inline void Recipe::printAdditionalTime() const
{
    std::cout << "Additioanl Time: " << m_additional_time << " min.\n";
}
inline void Recipe::printTotalTime() const
{
    std::cout << "Total Time: " << m_total_time << " min.\n";
}
inline void Recipe::printServings() const
{
    std::cout << "Prep Time: " << m_servings << " min.\n";
}
inline void Recipe::printNumIngredients() const
{
    std::cout << "Number of ingredients: " << Recipe::getNumIngredients() << "\n";
}
inline void Recipe::printIngredients() const
{
    std::cout << "Ingredients:\n";
    for (size_t i = 0; i < Recipe::getNumIngredients(); i++)
    {
        // std::cout << "\t" << i+1 << ") " 
        // << Recipe::getIngredients()[i].getQty() << " " 
        // << Recipe::getIngredients()[i].getUOM() << " of "
        // << Recipe::getIngredients()[i].getName() << "\n";

        std::cout << "\t" << i+1 << ") " << Recipe::getIngredients()[i] << "\n";
    }
}
#endif
#ifndef MEALPLAN_H
#define MEALPLAN_H

#include "Ingredient.h"
#include "Recipe.h"
#include "Meal.h"

#include <array>
#include <ctime>
#include <iostream>
#include <string>
#include <vector>

using Breakfast = Meal;
using Lunch = Meal;
using Dinner = Meal;
struct DailyMeals
{
    Breakfast breakfast {};
    Lunch lunch {};
    Dinner dinenr {};
};
class MealPlan 
{
private:
    struct tm m_week {};
    DailyMeals m_sun_meals{};
    DailyMeals m_mon_meals{};
    DailyMeals m_tue_meals{};
    DailyMeals m_wed_meals{};
    DailyMeals m_thu_meals{};
    DailyMeals m_fri_meals{};
    DailyMeals m_sat_meals{};
public:
    // Constructor declaration
    MealPlan(
        struct tm week, DailyMeals sun_meals, 
        DailyMeals mon_meals, DailyMeals tue_meals, 
        DailyMeals wed_meals, DailyMeals thu_meals,
        DailyMeals fri_meals, DailyMeals sat_meals
    );

};


MealPlan::MealPlan(
    struct tm week = {}, DailyMeals sun_meals = {}, 
    DailyMeals mon_meals = {}, DailyMeals tue_meals = {}, 
    DailyMeals wed_meals = {}, DailyMeals thu_meals = {},
    DailyMeals fri_meals = {}, DailyMeals sat_meals = {}
)
    : m_week { week }
    , m_sun_meals { sun_meals }
    , m_mon_meals { mon_meals }
    , m_tue_meals { tue_meals }
    , m_wed_meals { wed_meals }
    , m_thu_meals { thu_meals }
    , m_fri_meals { fri_meals }
    , m_sat_meals { sat_meals }
{
};

#endif
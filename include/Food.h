#ifndef FOOD_H
#define FOOD_H

#include <string>
#include <iostream>

// Class definition
class Food
{
public:
    // Enumerations
    enum FoodGroup
    {
        dairy,
        fruit,
        grain,
        meat,
        fat,
        vegetable,
    };
    constexpr std::string_view getFoodGroupName(FoodGroup const food_group)
    {
        switch (food_group)
        {
        case dairy:      return "dairy";
        case fruit:      return "fruit";
        case grain:      return "grain";
        case meat:       return "meat";
        case fat:        return "fat";
        case vegetable:  return "vegetable";
        default:         return "undefined";
        }
    }
private:
    std::string m_name {};
    FoodGroup m_food_group {};
    int m_shelf_life {}; // in days
public:
    // Constructor
    Food(std::string name, FoodGroup food_group, int shelf_life);

    // Access member functions
    std::string_view getName() const { return m_name; }
    FoodGroup getFoodGroup() const { return m_food_group; }
    int getShelfLife() const { return m_shelf_life; }

    // Print member functions
    void printName() const;
    void printFoodGroup() const;
    void printShelfLife() const;
};

// Define trivial member functions
inline Food::Food(std::string name, FoodGroup food_group, int shelf_life)
    : m_name { name }
    , m_food_group{ food_group }
    , m_shelf_life { shelf_life }
{
}

inline void Food::printName() const
{
    std::cout << "Name: " << m_name << ".\n";
}

// inline void Food::printFoodGroup() const
// {
//     std::cout << "Food Group: " << Food::getFoodGroupName(m_food_group) << ".\n";
// }

inline void Food::printShelfLife() const
{
    std::cout << "Shelf Life: " << m_shelf_life << " days.\n";
}
#endif
#ifndef FOOD_H
#define FOOD_H
#include <string>
#include <iostream>

class Food
{
private:
    std::string m_name {};
    int m_food_group {};
        // 1 = "Dairy"
        // 2 = "Fruit"
        // 3 = "Grain"
        // 4 = "Meat"
        // 5 = "Fat"
        // 6 = "Vegetable"
    int m_shelf_life {}; // in days
    bool m_refrigerated {};
public:
    // Constructor
    Food(std::string name, int food_group, int shelf_life, bool refrigerated);

    // Access member functions
    std::string_view getName() const { return m_name; }
    int getFoodGroup() const { return m_food_group; }
    int getShelfLife() const { return m_shelf_life; }
    bool isRefrigerated() const { return m_refrigerated; }

    // Print member functions
    void printName() const;
};

// Define trivial member functions

inline Food::Food(std::string name, int food_group, int shelf_life, bool refrigerated)
    : m_name { name }
    , m_food_group{ food_group }
    , m_shelf_life { shelf_life }
    , m_refrigerated { refrigerated }
{
}

inline void Food::printName() const
{
    std::cout << "Food Name: " << m_name << "\n";
}

#endif
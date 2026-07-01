#ifndef INGREDIENT_H
#define INGREDIENT_H

#include <string>
#include <string_view>
#include <iostream>

class Ingredient
{
private:
    std::string m_name{};
    std::string m_uom{};
    std::string m_modifiers{""};
public:
    double m_qty{};
    // Constructor
    Ingredient(std::string name, double qty, std::string uom, std::string modifiers)
        : m_name{ name }
        , m_qty{ qty }
        , m_uom{ uom }
        , m_modifiers{ modifiers }
    {
    }

    // Friend classes
    friend class Meal;

    // Overloaded operators
    Ingredient& operator= (const Ingredient& ingredient);
    friend bool operator== (const Ingredient& i1, const Ingredient& i2);
    friend std::ostream& operator<< (std::ostream& out, const Ingredient& ingredient);

    // Access member functions
    std::string_view getName() const { return m_name; }
    double getQty() const { return m_qty; }
    std::string_view getUOM() const { return m_uom; }
    std::string_view getModifiers() const { return m_modifiers; }

    
    // Print member functions
    void print() const;
    void printName() const;
};

// Member function definitions
inline void Ingredient::print() const
{
    std::cout << m_qty << " " << m_uom << " of " << m_name << m_modifiers << "\n";  
}
inline void Ingredient::printName() const
{
    std::cout << "Ingredient name: " << m_name << ".\n";
}


// Overloaded operator definitions
Ingredient& Ingredient::operator= (const Ingredient& ingredient)
{
    m_name = ingredient.m_name;
    m_qty = ingredient.m_qty;
    m_uom = ingredient.m_uom;
    m_modifiers = ingredient.m_modifiers;
    
    return *this;
}
bool operator== (const Ingredient& i1, const Ingredient& i2)
{
    return {
        (i1.m_name == i2.m_name) &&
        (i1.m_qty == i2.m_qty) &&
        (i1.m_uom == i2.m_uom) &&
        (i1.m_modifiers == i2.m_modifiers)
    };
}
std::ostream& operator<< (std::ostream& out, const Ingredient& ingredient)
{
    out << ingredient.m_qty << " " << ingredient.m_uom << " of " << ingredient.m_name << ingredient.m_modifiers; 

    return out; // return std::ostream so we can chain calls to operator<<
}
#endif
cmake_minimum_required(VERSION 3.10.0)
project(RecipeManager)

set(CMAKE_RUNTIME_OUTPUT_DIRECTORY ${CMAKE_BINARY_DIR}/bin)

add_executable(RecipeManager)

target_sources(RecipeManager
    PRIVATE
        src/main.cpp
        src/Food.cpp
        src/Recipe.cpp
        include/Food.h
        include/Ingredient.h
        include/Meal.h
        include/MealPlan.h
        include/Recipe.h
        )

include(CTest)
enable_testing()


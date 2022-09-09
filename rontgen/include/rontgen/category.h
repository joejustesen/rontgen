#ifndef RONTGEN_CATEGORY_H
#define RONTGEN_CATEGORY_H

#include "colors.h"
#include <array>
#include <atomic>
#include <cstdint>

namespace rontgen {

/****************************************************************************
****************************************************************************/
class Category {
public:
    Category() = default;
    Category(const char * name, Color color) :
        name_{name},
        color_{color} {}
    Category(const char * name, std::uint32_t color) :
        name_{name},
        color_{static_cast<Color>(color)} {}

    const char * getName() const {
        return name_;
    }
    Color getColor() const {
        return color_;
    }

private:
    const char * name_{};
    Color color_{};
};

/****************************************************************************
****************************************************************************/
class Categories {
public:
    static void clear();
    static std::uint32_t Register(const char * name, Color color);
    static std::uint32_t Register(const char * name, std::uint32_t color);
    static const Category * GetCategory(std::uint32_t categoryIndex);

private:
    inline static const std::size_t NumberOfCategorySlots = 64;
    inline static std::atomic<int> nextUnusedSlot_{};
    inline static std::array<Category, NumberOfCategorySlots> categoryPool_;
};
}

#endif
#include <fmt/color.h>
#include <fmt/core.h>
#include <rontgen/category.h>
#include <stdexcept>

namespace rontgen {
/****************************************************************************
****************************************************************************/
void Categories::clear() {
    categoryPool_.fill({});
    nextUnusedSlot_ = 0;
}
/****************************************************************************
****************************************************************************/
std::uint32_t Categories::Register(const char * name, std::uint32_t color) {
    if (nextUnusedSlot_ == NumberOfCategorySlots)
        throw std::runtime_error{"all category slots are reserved"};

    categoryPool_[nextUnusedSlot_] = Category{name, color};
    return nextUnusedSlot_++;
}
/****************************************************************************
****************************************************************************/
const Category * Categories::GetCategory(std::uint32_t categoryIndex) {
    if (categoryIndex >= nextUnusedSlot_)
        throw std::out_of_range{fmt::format("category index {} is creater than categories in pool of {}", categoryIndex, nextUnusedSlot_)};

    return &categoryPool_[categoryIndex];
}
}
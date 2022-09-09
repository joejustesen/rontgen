#include <gtest/gtest.h>
#include <rontgen/category.h>

namespace {
TEST(Categories, Register) {
    rontgen::Categories::clear();
    EXPECT_EQ(0, rontgen::Categories::Register("IO", 0));
}

TEST(Categories, GetWithColorEnum) {
    rontgen::Categories::clear();
    EXPECT_EQ(0, rontgen::Categories::Register("CPU", 0xFF00FF));

    auto sut = rontgen::Categories::GetCategory(0);
    EXPECT_NE(sut, nullptr);
    EXPECT_STREQ(sut->getName(), "CPU");
    EXPECT_EQ(sut->getColor(), rontgen::Color::Snow);
}

TEST(Categories, GetWithHexColor) {
    rontgen::Categories::clear();
    EXPECT_EQ(0, rontgen::Categories::Register("CPU", 0xFF00FF));

    auto sut = rontgen::Categories::GetCategory(0);
    EXPECT_NE(sut, nullptr);
    EXPECT_STREQ(sut->getName(), "CPU");
    EXPECT_EQ(static_cast<std::uint32_t>(sut->getColor()), 0xFF00FF);
}

TEST(Categories, GetThrowOutOfRange) {
    rontgen::Categories::clear();
    EXPECT_EQ(0, rontgen::Categories::Register("GENERIC", 0xAABBCC));
    EXPECT_THROW({ rontgen::Categories::GetCategory(1); }, std::out_of_range);
}
}
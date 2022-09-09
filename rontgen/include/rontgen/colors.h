#ifndef RONTGEN_COLORS_H
#define RONTGEN_COLORS_H

#include <cstdint>

namespace rontgen {

constexpr std::uint32_t RGB(std::uint8_t r, std::uint8_t g, std::uint8_t b) {
    return r << 16 | g << 8 | b;
}

enum class Color { Snow = RGB(255, 250, 250), GhostWhite = RGB(248, 248, 255) };
}
#endif

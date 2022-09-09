add_executable(rontgen_tests
    category_tests.cpp
)

target_link_libraries(rontgen_tests PUBLIC rontgen gtest gtest_main fmt)
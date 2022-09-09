add_library(rontgen STATIC
    src/category.cpp
)

# target_link_libraries(rontgen)
target_include_directories(rontgen
    PUBLIC ${CMAKE_CURRENT_SOURCE_DIR}/include
    PRIVATE ${CMAKE_CURRENT_SOURCE_DIR}/src
)

target_link_libraries(rontgen PUBLIC fmt::fmt)

if(ENABLE_TESTING)
    enable_testing()
    add_subdirectory(tests/unit_tests)
endif()

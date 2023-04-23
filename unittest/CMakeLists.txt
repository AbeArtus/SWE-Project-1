cmake_minimum_required(VERSION 3.26)

set(This UnitTest)

set(Sources
    UnitTest.cpp
)

add_executable(${This} ${Sources})

target_link_libraries(${This} public
    gtest_main
    SWE-PROJECT-1
)

add_test(
    NAME ${This}
    COMMAND ${This}
)
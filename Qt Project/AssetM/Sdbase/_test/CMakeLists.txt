cmake_minimum_required(VERSION 3.5)

project(Sdbase)

add_executable(AssetMDbTest main.cpp AssetMDbTest.cpp )

include_directories("${CMAKE_SOURCE_DIR}/googletest/googletest/include")
include_directories("${CMAKE_SOURCE_DIR}/googletest/googlemock/include")
include_directories("${CMAKE_SOURCE_DIR}/Sdbase")
target_link_libraries(AssetMDbTest PRIVATE Qt6::Sql)

target_link_directories(AssetMDbTest PUBLIC googletest)
target_link_libraries(AssetMDbTest PUBLIC
    Sdbase
    gtest
    gmock)
#add_subdirectory(_test)

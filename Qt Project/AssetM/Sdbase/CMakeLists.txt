cmake_minimum_required(VERSION 3.5)

project(Sdbase)
add_library(Sdbase STATIC AssetMdbmanagerserviceinterface.h AssetMdbmanagerservice.cpp AssetMdbmanagerservice.h )
find_package(Qt6 REQUIRED COMPONENTS Sql)
target_link_libraries(Sdbase PRIVATE Qt6::Sql)
add_subdirectory(_test)

cmake_minimum_required(VERSION 3.22)

project(oop_project VERSION 1.0)

set(CMAKE_CXX_STANDARD 17)

set(-DCMAKE_EXPORT_COMPILE_COMMANDS=ON)

set(CMAKE_CXX_CLANG_TIDY 
clang-tidy;   

-header-filter=.;
-checks='-*,cppcoreguidelines-*,google-*,modernize-*,readability-*,-modernize-use-trailing-return-type,bugprone-*,clang-analyzer-*;
#-warnings-as-errors=*;
-p=./build;
)

add_subdirectory(source_code)

add_executable(oop_project main.cpp)
target_link_libraries(oop_project PRIVATE Date)
target_link_libraries(oop_project PRIVATE Student)
target_link_libraries(oop_project PRIVATE Research)



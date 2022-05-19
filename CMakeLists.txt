cmake_minimum_required(VERSION 3.1...3.21)

set(CMAKE_C_COMPILER "gcc-11")
set(CMAKE_CXX_COMPILER "g++-11")

project(libxbitset VERSION 0.0.1 LANGUAGES CXX)
add_library(${PROJECT_NAME} INTERFACE)
target_include_directories(${PROJECT_NAME} INTERFACE include)
target_compile_features(${PROJECT_NAME} INTERFACE cxx_std_20)

install(TARGETS ${PROJECT_NAME}
  EXPORT ${PROJECT_NAME}
  LIBRARY DESTINATION lib
  ARCHIVE DESTINATION lib
  RUNTIME DESTINATION bin
  PUBLIC_HEADER DESTINATION include)

find_package(ut)
find_package(libxbitset)

set(TEST_NAME unit_test)
set(CMAKE_BUILD_TYPE Debug)

add_executable(${TEST_NAME} 
  tests/main.test.cpp
  tests/bitset.test.cpp
  tests/bitreset.test.cpp
  tests/bitflip.test.cpp)
enable_testing()
add_test(NAME ${TEST_NAME} WORKING_DIRECTORY ${CMAKE_BINARY_DIR}
  COMMAND ${TEST_NAME})

target_include_directories(${TEST_NAME} PUBLIC tests)
target_compile_options(${TEST_NAME} PRIVATE -Werror -Wall -Wextra
  -Wno-unused-function -Wconversion -g)
set_target_properties(${TEST_NAME} PROPERTIES CXX_VISIBILITY_PRESET default)
target_compile_features(${TEST_NAME} PRIVATE cxx_std_20)
set_target_properties(${TEST_NAME} PROPERTIES CXX_EXTENSIONS OFF)
target_link_libraries(${TEST_NAME} PRIVATE boost::ut ${PROJECT_NAME})

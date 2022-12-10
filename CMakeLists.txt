cmake_minimum_required(VERSION 3.0.0)
project(template_cmake_cross_platform)

set(CMAKE_EXPORT_COMPILE_COMMANDS ON)

set(PROJECT_VERSION_MAJOR 0)
set(PROJECT_VERSION_MINOR 0)
set(PROJECT_VERSION_PATCH 0)
set(PROJECT_VERSION v${PROJECT_VERSION_MAJOR}.${PROJECT_VERSION_MINOR}.${PROJECT_VERSION_PATCH})
message("project name: ${PROJECT_NAME}, version: ${PROJECT_VERSION}")

include(${CMAKE_BINARY_DIR}/conanbuildinfo.cmake)
conan_basic_setup()

include(CTest)
enable_testing()

add_executable(${PROJECT_NAME} 
  src/main.cpp
)
target_include_directories(${PROJECT_NAME} PUBLIC
  ${CONAN_INCLUDE_DIRS}
)

target_link_libraries(${PROJECT_NAME} PUBLIC
  ${CONAN_LIBS}
)

target_compile_features(${PROJECT_NAME} 
    PRIVATE cxx_std_17
)

set(CPACK_PROJECT_NAME ${PROJECT_NAME})
set(CPACK_PROJECT_VERSION ${PROJECT_VERSION})
include(CPack)

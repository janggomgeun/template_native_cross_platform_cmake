cmake_minimum_required(VERSION 3.0.0)

# toolchain information
message(STATUS "compiler flags:" ${CMAKE_CXX_COMPILE_FLAGS})
message(STATUS "compiler cxx debug flags:" ${CMAKE_CXX_FLAGS_DEBUG})
message(STATUS "compiler cxx release flags:" ${CMAKE_CXX_FLAGS_RELEASE})
message(STATUS "compiler cxx min size flags:" ${CMAKE_CXX_FLAGS_MINSIZEREL})
message(STATUS "compiler cxx flags:" ${CMAKE_CXX_FLAGS})

# cmake settings
set(CMAKE_EXPORT_COMPILE_COMMANDS ON)

# project description
project(template_cmake_cross_platform)

# options which are configurable by developers
option(WITH_CXX_STD_17 "CXX STD 17" ON)
option(WITH_UNIT_TESTS "Unit tests" ON)

# project versioning
set(PROJECT_VERSION_MAJOR 0)
set(PROJECT_VERSION_MINOR 0)
set(PROJECT_VERSION_PATCH 0)
set(PROJECT_VERSION v${PROJECT_VERSION_MAJOR}.${PROJECT_VERSION_MINOR}.${PROJECT_VERSION_PATCH})

message(STATUS "project name: ${PROJECT_NAME}, ${PROJECT_VERSION}")

# cmake module resolutions
list(APPEND CMAKE_MODULE_PATH "${CMAKE_CURRENT_SOURCE_DIR}/cmake")
list(APPEND CMAKE_MODULE_PATH "${CMAKE_BINARY_DIR}")

find_package(spdlog REQUIRED)
find_package(doctest REQUIRED)

# add executable for the project
add_executable(${PROJECT_NAME} 
  src/main.cpp
  src/factorial/factorial.cpp
)

target_include_directories(${PROJECT_NAME} PUBLIC
  ${CONAN_INCLUDE_DIRS}
)

target_link_libraries(${PROJECT_NAME} PUBLIC
  ${CONAN_LIBS}
  spdlog::spdlog
  doctest::doctest 
)

target_compile_definitions(${PROJECT_NAME} PUBLIC
  $<$<NOT:$<BOOL:${WITH_UNIT_TESTS}>>:DOCTEST_CONFIG_DISABLE=1>
)

target_compile_features(${PROJECT_NAME} 
    PRIVATE 
    cxx_std_17
)

include(ClangFormat)
target_clangformat_setup(${PROJECT_NAME})

# package
set(CPACK_PROJECT_NAME ${PROJECT_NAME})
set(CPACK_PROJECT_VERSION ${PROJECT_VERSION})
include(CPack)
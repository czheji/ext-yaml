# Minimal CMake project for building a static library under Windows.

cmake_minimum_required (VERSION 3.6)
project (yaml C)

set (YAML_VERSION_MAJOR 0)
set (YAML_VERSION_MINOR 1)
set (YAML_VERSION_PATCH 7)
set (YAML_VERSION_STRING "${YAML_VERSION_MAJOR}.${YAML_VERSION_MINOR}.${YAML_VERSION_PATCH}")

file (GLOB SRC src/*.c)

add_library (yaml STATIC ${SRC})
target_include_directories(yaml
        PUBLIC inc)
target_compile_definitions(yaml
        PUBLIC HAVE_CONFIG_H
        PUBLIC YAML_DECLARE_STATIC)

add_executable(yaml-run-loader tests/run-loader.c)
target_link_libraries(yaml-run-loader yaml)

add_executable(yaml-run-dumper tests/run-dumper.c)
target_link_libraries(yaml-run-dumper yaml)

add_executable(yaml-run-parser tests/run-parser.c)
target_link_libraries(yaml-run-parser yaml)
add_executable(yaml-run-scanner tests/run-scanner.c)
target_link_libraries(yaml-run-scanner yaml)
add_executable(yaml-test-reader tests/test-reader.c)
target_link_libraries(yaml-test-reader yaml)
add_executable(yaml-test-version tests/test-version.c)
target_link_libraries(yaml-test-version yaml)

#domain tests
add_executable(yaml-test-domain tests/test-domain.c)
target_link_libraries(yaml-test-domain yaml)
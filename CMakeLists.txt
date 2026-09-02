cmake_minimum_required(VERSION 4.4.3)

project(octo LANGUAGES CXX)

option(OCTO_COVERAGE "Enable LLVM coverage" OFF)

set(CMAKE_CXX_STANDARD 26)
set(CMAKE_CXX_STANDARD_REQUIRED ON)
set(CMAKE_EXPORT_COMPILE_COMMANDS ON)

include(FetchContent)

FetchContent_Declare(
    CLI11
    GIT_REPOSITORY https://github.com/CLIUtils/CLI11.git
    GIT_TAG v2.7.2
)

FetchContent_MakeAvailable(CLI11)

FetchContent_Declare(
    googletest
    GIT_REPOSITORY https://github.com/google/googletest.git
    GIT_TAG v1.18.0
)

FetchContent_MakeAvailable(googletest)

FetchContent_Declare(
    Corrosion
    GIT_REPOSITORY https://github.com/corrosion-rs/corrosion.git
    GIT_TAG v0.6.1
)

FetchContent_MakeAvailable(Corrosion)

corrosion_import_crate(
    MANIFEST_PATH ${CMAKE_CURRENT_SOURCE_DIR}/octo-log/Cargo.toml
)


add_subdirectory(cpu)

enable_testing()

add_executable(octo_tests
    tests/register_test.cpp
    tests/cpu_test.cpp
    tests/step_test.cpp
    tests/memory_test.cpp
)

target_link_libraries(octo_tests
    PRIVATE
        octo_log
        octo_cpu
        GTest::gtest_main
)

include(GoogleTest)

gtest_discover_tests(octo_tests)

if(OCTO_COVERAGE)
    add_custom_target(coverage
        COMMAND ${CMAKE_COMMAND} -E rm -f
            ${CMAKE_BINARY_DIR}/default.profraw

        COMMAND ${CMAKE_COMMAND} -E env
            LLVM_PROFILE_FILE=${CMAKE_BINARY_DIR}/octo-%p.profraw
            $<TARGET_FILE:octo_tests>

        COMMAND llvm-profdata merge
            -sparse
            ${CMAKE_BINARY_DIR}/octo-*.profraw
            -o ${CMAKE_BINARY_DIR}/octo.profdata

        COMMAND llvm-cov report
            $<TARGET_FILE:octo_tests>
            -instr-profile=${CMAKE_BINARY_DIR}/octo.profdata

        COMMAND llvm-cov show
            $<TARGET_FILE:octo_tests>
            -instr-profile=${CMAKE_BINARY_DIR}/octo.profdata
            -format=html
            -output-dir=${CMAKE_BINARY_DIR}/coverage

        DEPENDS octo_tests
        WORKING_DIRECTORY ${CMAKE_BINARY_DIR}
    )
endif()

add_executable(octo
    src/main.cpp
)

target_link_libraries(octo
    PRIVATE
        CLI11::CLI11
        octo_cpu
        octo_log
)


target_include_directories(octo
    PRIVATE
        ${CMAKE_CURRENT_SOURCE_DIR}/octo-log/include
)

if(OCTO_COVERAGE)
    target_compile_options(octo_cpu PRIVATE
        -fprofile-instr-generate
        -fcoverage-mapping
    )

    target_link_options(octo_tests PRIVATE
        -fprofile-instr-generate
    )
endif()

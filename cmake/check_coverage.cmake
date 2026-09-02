execute_process(
    COMMAND llvm-cov report
        "${BINARY}"
        "-instr-profile=${PROFDATA}"
        "--ignore-filename-regex=.*_deps/.*"
    OUTPUT_VARIABLE OUTPUT
    RESULT_VARIABLE RESULT
)

if(NOT RESULT EQUAL 0)
    message(FATAL_ERROR "llvm-cov report failed")
endif()

message("${OUTPUT}")

string(REGEX MATCH "TOTAL[^\\n]*" TOTAL_LINE "${OUTPUT}")

if(NOT TOTAL_LINE)
    message(FATAL_ERROR "Could not find TOTAL coverage")
endif()

string(REGEX MATCH "([0-9]+(\\.[0-9]+)?)%" COVERAGE "${TOTAL_LINE}")

if(NOT COVERAGE)
    message(FATAL_ERROR "Could not determine coverage percentage")
endif()

set(COVERAGE_VALUE "${CMAKE_MATCH_1}")

message(STATUS "Total coverage: ${COVERAGE_VALUE}%")

if(COVERAGE_VALUE LESS 80)
    message(FATAL_ERROR
        "Coverage is below 80%: ${COVERAGE_VALUE}%"
    )
endif()

message(STATUS "Coverage requirement passed: ${COVERAGE_VALUE}% >= 80%")
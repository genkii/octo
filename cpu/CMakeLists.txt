add_library(octo_cpu
    src/register.cpp
    include/octo/cpu/cpu.hpp
    include/octo/opc/op_code.hpp
    include/octo/cpu/register.hpp
    src/step.cpp
    src/fetch_byte.cpp
    src/fetch_word.cpp
    src/cpu.cpp
    include/octo/memory/memory.hpp
    src/memory/write.cpp
    src/memory/read.cpp
    src/memory/memory.cpp
)

target_include_directories(octo_cpu
    PUBLIC
        ${CMAKE_CURRENT_SOURCE_DIR}/include
)

target_link_libraries(octo_cpu
    PRIVATE
        octo_log
)

target_include_directories(octo_cpu
    PRIVATE
        ${CMAKE_SOURCE_DIR}/octo-log/include
)
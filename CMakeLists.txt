# Author: Sebastian Zanker

cmake_minimum_required(VERSION 3.10)

# set the project name
project(RiscvDisassembly VERSION 1.0)

# set include directory
include_directories(        ${PROJECT_SOURCE_DIR}/inc)

# source files for the RISCV compiliation
set (SOURCE_FILES           ${PROJECT_SOURCE_DIR}/src/RiscvDisassembly.cpp
                            ${PROJECT_SOURCE_DIR}/src/riscv_register.cpp
                            ${PROJECT_SOURCE_DIR}/src/riscv_instruction.cpp
                            ${PROJECT_SOURCE_DIR}/src/riscv_instruction_reg.cpp
                            ${PROJECT_SOURCE_DIR}/src/riscv_instruction_reg.cpp
                            ${PROJECT_SOURCE_DIR}/src/riscv_instruction_load.cpp
                            ${PROJECT_SOURCE_DIR}/src/riscv_instruction_save.cpp
                            )

#target_include_directories(RiscvDisassembly PUBLIC "${PROJECT_BINARY_DIR}")

configure_file(inc/VersionInfo.h.in VersionInfo.h)

# specify the C++ standard
set(CMAKE_CXX_STANDARD 11)
set(CMAKE_CXX_STANDARD_REQUIRED True)

# add the executable
add_executable(RiscvDisassembly ${SOURCE_FILES})

set_target_properties(RiscvDisassembly PROPERTIES 
    VS_DEBUGGER_COMMAND "$(TargetPath)"
    VS_DEBUGGER_COMMAND_ARGUMENTS "../../../example/exfile.hex")
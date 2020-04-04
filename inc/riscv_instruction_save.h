#pragma once

// Author: Sebastian Zanker

#include "riscv_instruction.h"

class riscv_instruction_save : public riscv_instruction
{

public:
	riscv_instruction_save(std::vector<riscv_register*>& regs);
	void decode(unsigned int inst);
};

#pragma once

// Author: Sebastian Zanker

#include "riscv_instruction.h"

class riscv_instruction_reg : public riscv_instruction
{

public:
	riscv_instruction_reg(std::vector<riscv_register*>& regs);
	void decode(unsigned int inst);
};
#pragma once

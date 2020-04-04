#pragma once

// Author: Sebastian Zanker
// Description: decodes a load instruction
// Load is also an immediate type

#include "riscv_instruction.h"


class riscv_instruction_load : public riscv_instruction
{

public:
	riscv_instruction_load(std::vector<riscv_register*>& regs);
	void decode(unsigned int inst);
};

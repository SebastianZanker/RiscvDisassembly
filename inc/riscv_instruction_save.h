#pragma once

// Author: Sebastian Zanker

#include "riscv_instruction.h"

class riscv_instruction_save : public riscv_instruction
{

public:
	riscv_instruction_save();
	void decode(unsigned int inst);
};

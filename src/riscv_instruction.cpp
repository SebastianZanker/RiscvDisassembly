// Author: Sebastian Zanker

#include "riscv_instruction.h"

// Constructor
riscv_instruction::riscv_instruction(std::vector<riscv_register*> &regs) :
	inst_occurrence(0), registers(regs)
{
}


// keep track of all occurrences
void riscv_instruction::inc_inst_occurrence()
{
	inst_occurrence++;
}

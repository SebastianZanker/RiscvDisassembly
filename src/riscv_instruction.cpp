// Author: Sebastian Zanker

#include "riscv_instruction.h"

// Constructor
riscv_instruction::riscv_instruction() :
	inst_occurrence(0)
{
	// initialize the vector
	registers.reserve(10); // Reserve memory not to allocate it 10 times...
	for (int i = 0; i < 10; ++i)
	{
		registers.push_back(riscv_register());
	}
}


// keep track of all occurrences
void riscv_instruction::inc_inst_occurrence()
{
	inst_occurrence++;
}

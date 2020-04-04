// Author: Sebastian Zanker

#include <iostream>
#include "riscv_instruction_save.h"

// Constructor
riscv_instruction_save::riscv_instruction_save(std::vector<riscv_register*>& regs) :
	riscv_instruction{ regs }
{

}


void riscv_instruction_save::decode(unsigned int inst)
{
	// base memory address
	unsigned char rs1;
	// data to be stored
	unsigned char rs2;
	// 12 bit immediate value
	unsigned int immediate;
	// func3 (0: Save byte; 1: save halfword; 2: save word)
	unsigned char funct3;

	// assign values
	funct3 = (inst >> inst_fields_e::e_funct3) & 0x07;
	rs1 = (inst >> inst_fields_e::e_rs1) & 0x1F;
	rs2 = (inst >> inst_fields_e::e_rs2) & 0x1F;
	immediate = (inst >> 7) & 0x1F;
	immediate |= ((inst >> 25) & 0x7F);

	// print all values
	if (funct3 == 0) {
		printf("Opcode: save byte\n");
	}
	else if (funct3 == 1) {
		printf("Opcode: save half word\n");
	}
	else if (funct3 == 2) {
		printf("Opcode: save word\n");
	}
	// registers:
	printf("Base Memory Address: x%d, Offset: 0x%04X\n", rs1, immediate);
	printf("Date to be stored: x%d\n", rs2);
	// increase the occurrence for save instructions
	inc_inst_occurrence();
}

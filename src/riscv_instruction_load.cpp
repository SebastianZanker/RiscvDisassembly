// Author: Sebastian Zanker

#include <iostream>
#include "riscv_instruction_load.h"

// Constructor
riscv_instruction_load::riscv_instruction_load(std::vector<riscv_register*>& regs) :
	riscv_instruction{ regs }
{

}


void riscv_instruction_load::decode(unsigned int inst)
{
	// base memory address
	unsigned char rs1;
	// data to be stored
	unsigned char rd;
	// 12 bit immediate value
	int16_t immediate;
	// func3 (0: Save byte; 1: save halfword; 2: save word)
	unsigned char func3;

	// assign values
	func3 = (inst >> inst_fields_e::e_funct3) & 0x07;
	rs1 = (inst >> inst_fields_e::e_rs1) & 0x1F;
	rd = (inst >> inst_fields_e::e_rd) & 0x1F;
	immediate = (inst >> 20) & 0xFFF;
	// immediate is signed
	if ((immediate >> 11) & 0x01)
	{
		immediate |= 0xF << 12;
	}
	
	switch (func3) {
	case funct3_load_e::e_LB:
		printf("Opcode: load byte\n");
		break;
	case funct3_load_e::e_LH:
		printf("Opcode: load half word\n");
		break;
	case funct3_load_e::e_LW:
		printf("Opcode: load word\n");
		break;
	case funct3_load_e::e_LBU:
		printf("Opcode: load byte (unsigned)\n");
		break;
	case funct3_load_e::e_LHU:
		printf("Opcode: load half word (unsigned)\n");
		break;
	}

	// registers:
	printf("Base Memory Address: x%d, Offset: 0x%04X\n", rs1, immediate);
	printf("Destination register: x%d\n", rd);

	// calculate statistics
	registers[rs1]->inc_src();
	registers[rd]->inc_dest();
}

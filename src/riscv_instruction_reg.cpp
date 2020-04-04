// Author: Sebastian Zanker

#include <iostream>
#include "riscv_instruction_reg.h"


// Constructor
riscv_instruction_reg::riscv_instruction_reg(std::vector<riscv_register*>& regs) :
	riscv_instruction{ regs }
{

}


void riscv_instruction_reg::decode(unsigned int inst)
{
	// base memory address
	unsigned char rs1;
	unsigned char rs2;
	// data to be stored
	unsigned char rd;
	// 12 bit immediate value
	int16_t immediate;
	// func3 (0: Save byte; 1: save halfword; 2: save word)
	unsigned char func3;
	unsigned char func7;

	// assign values
	func3 = (inst >> inst_fields_e::e_funct3) & 0x07;
	func7 = (inst >> inst_fields_e::e_funct3) & 0x07;
	rs1 = (inst >> inst_fields_e::e_rs1) & 0x1F;
	rs2 = (inst >> inst_fields_e::e_rs2) & 0x1F;
	rd = (inst >> inst_fields_e::e_rd) & 0x1F;

	switch (func3) {
	case funct3_reg_e::e_ADD_SUB_e:
		printf("Opcode(R): ADD/SUB\n");
		break;
	case funct3_reg_e::e_SLL:
		printf("Opcode(R): SLL\n");
		break;
	case funct3_reg_e::e_SLT:
		printf("Opcode(R): SLT\n");
		break;
	case funct3_reg_e::e_SLTU:
		printf("Opcode(R): SLTU\n");
		break;
	case funct3_reg_e::e_XOR:
		printf("Opcode(R): XOR\n");
		break;
	case funct3_reg_e::e_SRL_SRA:
		printf("Opcode(R): SRL/SRA\n");
		break;
	case funct3_reg_e::e_OR:
		printf("Opcode(R): OR\n");
		break;
	case funct3_reg_e::e_AND:
		printf("Opcode(R): AND\n");
		break;
	default:
		printf("Register format: Error decoding");
	}

	// registers:
	printf("Source register 1: %d, source register 2: %d\n", rs1, rs2);
	printf("Destination register: x%d\n", rd);

	// calculate statistics
	registers[rs1]->inc_src();
	registers[rs2]->inc_src();
	registers[rd]->inc_dest();
}

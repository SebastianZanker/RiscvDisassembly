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
	rs1 = (inst >> inst_fields_e::e_rs2) & 0x1F;
	rd = (inst >> inst_fields_e::e_rd) & 0x1F;
	immediate = (inst >> 20) & 0xFFF;
	// immediate is signed
	if ((immediate >> 11) & 0x01)
	{
		immediate |= 0xF << 12;
	}

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
	printf("Base Memory Address: x%d, Offset: 0x%04X\n", rs1, immediate);
	printf("Destination register: x%d\n", rd);
	// increase the occurrence for save instructions
	inc_inst_occurrence();
}

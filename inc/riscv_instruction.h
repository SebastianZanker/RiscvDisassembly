#pragma once

#include "riscv_register.h"
#include <vector>

// Author: Sebastian Zanker
// Description:
// Base class for all instruction decodings

// enum for the start of bitfields in instruction
// immediate bitfiels occure on various bit positions => skipped
enum inst_fields_e
{
	e_opcode = 0,
	e_rd = 7,
	e_funct3 = 12,
	e_rs1 = 15,
	e_rs2 = 20,
	e_funct7 = 25
};


enum funct3_load_e
{
	e_LB = 0,
	e_LH = 1,
	e_LW = 2,
	e_LBU = 4,
	e_LHU = 5
};


enum funct3_reg_e
{
	e_ADD_SUB_e = 0,
	e_SLL = 1,
	e_SLT = 2,
	e_SLTU = 3,
	e_XOR = 4,
	e_SRL_SRA = 5,
	e_OR = 6,
	e_AND = 7
};


class riscv_instruction
{

public:
	riscv_instruction(std::vector<riscv_register*> &regs);
	virtual void decode(unsigned int inst) = 0;

protected:

	// keep track of all registers
	std::vector<riscv_register*> &registers;
	
};
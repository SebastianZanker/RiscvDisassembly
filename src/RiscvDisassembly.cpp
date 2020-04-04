// Author: Sebastian Zanker

#include <iostream>
#include <vector>
#include "riscv_instruction_save.h"
#include "riscv_instruction_load.h"
#include "riscv_instruction_reg.h"

using namespace std;

const unsigned char OPCODE_L = 0x03;
const unsigned char OPCODE_I = 0x13;
const unsigned char OPCODE_S = 0x23;
const unsigned char OPCODE_R = 0x33;
const unsigned char OPCODE_B = 0x63;

const unsigned char OPCODE_LUI = 0x37;
const unsigned char OPCODE_AUIPC = 0x17;
const unsigned char OPCODE_JAL = 0x6F;
const unsigned char OPCODE_JALR = 0x67;

const unsigned int NUM_REGISTERS = 32;

const unsigned char INDEX_SAVE = 0;
const unsigned char INDEX_LOAD = 1;
const unsigned char INDEX_REG = 2;


vector<unsigned int> riscv_assembly = {
    0x00000093,
    0x00000113,
    0x00000193,
    0x00700793,
    0xFEF42623,
    0x001007B7,
    0xFEF42223,
    0x00200793
};


void decode_r(unsigned int inst)
{

}

void decode_i(unsigned int inst)
{
    printf("Found Immediate instruction\n");
}

void decode_l(unsigned int inst)
{
    printf("Found Load instruction\n");
}


void decode_s(unsigned int inst)
{
    printf("Found Save instruction\n");
}


void decode_b(unsigned int inst)
{
    printf("Found Branch instruction\n");
}

void decode_lui(unsigned int inst)
{
    printf("Found LUI instruction\n");
}

void decode_auipc(unsigned int inst)
{
    printf("Found AUIPC instruction\n");
}

void decode_jal(unsigned int inst)
{
    printf("Found JAL instruction\n");
}

void decode_jalr(unsigned int inst)
{
    printf("Found JALR instruction\n");
}


// step function for every single instruction
void step(vector<riscv_instruction*> &ri, unsigned int current_inst)
{
    printf("Instruction: 0x%08X\n", current_inst);
    // getting the opcode
    unsigned char opcode = current_inst & 0x7F;
    switch (opcode) {
    case OPCODE_I:
        decode_i(current_inst);
        break;
    case OPCODE_L:
        decode_l(current_inst);
        ri[INDEX_LOAD]->decode(current_inst);
        break;
    case OPCODE_S:
        decode_s(current_inst);
        ri[INDEX_SAVE]->decode(current_inst);
        break;
    case OPCODE_R:
        decode_r(current_inst);
        ri[INDEX_REG]->decode(current_inst);
        break;
    case OPCODE_B:
        decode_b(current_inst);
        break;
    case OPCODE_LUI:
        decode_lui(current_inst);
        break;
    case OPCODE_AUIPC:
        decode_auipc(current_inst);
        break;
    case OPCODE_JAL:
        decode_jal(current_inst);
        break;
    case OPCODE_JALR:
        decode_jalr(current_inst);
        break;
    default:
        printf("Unknown instruction\n");
    }
    printf("\n");
}


int main()
{
    // vector for the RISCV registers
    vector<riscv_register*> reg_table(NUM_REGISTERS);
    for (unsigned int i = 0; i < NUM_REGISTERS; i++) {
        reg_table[i] = new riscv_register();
    }

    // classes for decoding
    vector<riscv_instruction*> ri(3);

    // classes for the different sets of instructions
    ri[INDEX_SAVE] = new riscv_instruction_save(reg_table);
    ri[INDEX_LOAD] = new riscv_instruction_load(reg_table);
    ri[INDEX_REG] = new riscv_instruction_reg(reg_table);

    for (unsigned int i = 0; i < riscv_assembly.size(); i++) {
        step(ri, riscv_assembly[i]);
    }
}


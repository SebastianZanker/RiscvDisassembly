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

int main()
{
    unsigned int current_inst = 0;
    unsigned char opcode = 0;

    // classes for the different sets of instructions
    riscv_instruction_save* ri_save = new riscv_instruction_save();
    riscv_instruction_load* ri_load = new riscv_instruction_load();
    riscv_instruction_reg* ri_reg = new riscv_instruction_reg();

    for (unsigned int i = 0; i < riscv_assembly.size(); i++) {
        printf("Instruction: 0x%08X\n", riscv_assembly[i]);
        current_inst = riscv_assembly[i];
        // get the opcode
        opcode = current_inst & 0x7F;
        switch (opcode){
            case OPCODE_I:
                decode_i(current_inst);
                break;
            case OPCODE_L:
                decode_l(current_inst);
                ri_load->decode(current_inst);
                break;
            case OPCODE_S:
                decode_s(current_inst);
                ri_save->decode(current_inst);
                break;
            case OPCODE_R:
                decode_r(current_inst);
                ri_reg->decode(current_inst);
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
}

// Programm ausführen: STRG+F5 oder Menüeintrag "Debuggen" > "Starten ohne Debuggen starten"
// Programm debuggen: F5 oder "Debuggen" > Menü "Debuggen starten"

// Tipps für den Einstieg: 
//   1. Verwenden Sie das Projektmappen-Explorer-Fenster zum Hinzufügen/Verwalten von Dateien.
//   2. Verwenden Sie das Team Explorer-Fenster zum Herstellen einer Verbindung mit der Quellcodeverwaltung.
//   3. Verwenden Sie das Ausgabefenster, um die Buildausgabe und andere Nachrichten anzuzeigen.
//   4. Verwenden Sie das Fenster "Fehlerliste", um Fehler anzuzeigen.
//   5. Wechseln Sie zu "Projekt" > "Neues Element hinzufügen", um neue Codedateien zu erstellen, bzw. zu "Projekt" > "Vorhandenes Element hinzufügen", um dem Projekt vorhandene Codedateien hinzuzufügen.
//   6. Um dieses Projekt später erneut zu öffnen, wechseln Sie zu "Datei" > "Öffnen" > "Projekt", und wählen Sie die SLN-Datei aus.

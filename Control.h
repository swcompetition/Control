#pragma once
#include <iostream>

using namespace std;

#define OPCODE_BITS_CTR 6
#define ALU_OP_BITS 2

#define RTYPE_OP "000000"
#define LW_OP "100011"
#define SW_OP "101011"
#define BEQ_OP "000100"

class Control {
private:
    bool opcode_bits[OPCODE_BITS_CTR];
    bool is_branch;
    bool reg_dest;
    bool reg_write;
    bool alu_src;
    bool alu_op[ALU_OP_BITS];
    bool mem_write;
    bool mem_read;
    bool mem_to_reg;
    string bool_to_str(bool* array, int size);
    void initSignal();

public:
    Control(string opcode);
    bool getBranch();
    bool getRegDest();
    bool getRegWrite();
    bool getAluSrc();
    bool* getAluOP();
    bool getMemWrite();
    bool getMemRead();
    bool getMemToReg();
};
#include "Control.h"

Control::Control(string opcode) {
    if (opcode.length() != 6) {
        cout << "OPCode its length should be 6." << endl;
    }

    for (int i = 0; i < OPCODE_BITS_CTR; i++) {
        opcode_bits[i] = opcode.at(i) - '0';
    }
    initSignal();
}

void Control::initSignal() {
    string opcode_str = bool_to_str(opcode_bits, OPCODE_BITS_CTR);
    if (opcode_str == RTYPE_OP) {
        cout << "RType detected" << endl;
        reg_dest = true;
        alu_src = false;
        mem_to_reg = false;
        reg_write = true;
        mem_read = false;
        mem_write = false;
        is_branch = false;
        alu_op[0] = 1;
        alu_op[1] = 0;
    }
}

string Control::bool_to_str(bool* array, int size) {
    string tmp = "";
    for (int i = 0; i < size; i++) {
        tmp += (array[i] + '0');
    }
    return tmp;
}

bool Control::getBranch() {
    return this->is_branch;
}

bool Control::getRegDest() {
    return this->reg_dest;
}

bool Control::getRegWrite() {
    return this->reg_write;
}

bool Control::getAluSrc() {
    return this->alu_src;
}

bool* Control::getAluOP() {
    return this->alu_op;
}

bool Control::getMemWrite() {
    return this->mem_write;
}

bool Control::getMemRead() {
    return this->mem_read;
}

bool Control::getMemToReg() {
    return this->mem_to_reg;
}
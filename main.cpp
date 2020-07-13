#include "Control.h"

class test {
public:
    string opcode = "000000";
    Control ctr;
    test() : ctr(opcode) {
    }
};

int main(void) {
    string opcode = "000000";
    Control ctr(opcode);
}
//SINTAXIS
//
// ORD REG VALUE OUTREG
// MOV A 1 B the one says if you are going to put a number or the register but i can change this by T or F, R or N etc
// MOV A 0 9 numbers from 0 to 9
//
// MOV copy data
// ADD add numbers
// SUB substract
// MUL multiplicate
// DIV division
// JMP jump and the others JGT JNT JQT JLT......
// LOAD load anything from the ram
// STORE store anything in the ram
//
//END of sintaxis explaining

#define INS_SIZE 5

typedef struct {
	char inst[INS_SIZE];
	int fpos;
} Ins;

int vasm_len(const char *str) {
	int len = 0;
	while (str[len] != '\0') {
		len++;
	}
	return len;
}

char vasm_strcmp(const char *str1, const char *str2, int len) {
	for (int ch = 0; ch < len; ch++) {
		if (str1[ch] != str2[ch]) {
			return 0;
		}
	}
	return 1;
}

Ins first(const char *str, int pos) {
	Ins ins_ret;
	ins_ret.fpos = pos;
	for (int i = pos; str[i] != ' ' && i < INS_SIZE; i++) {
		ins_ret.inst[i] = str[i];
		ins_ret.fpos++;
	}
	return ins_ret;
}

Ins split(const char *str, int who) {
	Ins ret;
	int pos = 0;
	for (int a = 0; a < who; a++) {
		ret = first(str, pos);
		pos = ret.fpos + 2;
	}
	return ret;
}

int asemble(const char *line) {
	int opcode = -1;
	int reg_idx = -1;
	int value = -1;
	int in = -1;
	Ins pt;
	pt = split(line, 0);
	if (vasm_strcmp(pt.inst, "MOV", 3)) {
		opcode = 1;
	} else if (vasm_strcmp(pt.inst, "ADD", 3)) {
		opcode = 2;
        } else if (vasm_strcmp(pt.inst, "SUB", 3)) {
		opcode = 3;
        } else if (vasm_strcmp(pt.inst, "MUL", 3)) {
		opcode = 4;
        } else if (vasm_strcmp(pt.inst, "DIV", 3)) {
		opcode = 5;
        } else if (vasm_strcmp(pt.inst, "JNQ", 3)) {
		opcode = 7;
		value = 4;
        } else if (vasm_strcmp(pt.inst, "LOAD", 4)) {
		opcode = 8;
        } else if (vasm_strcmp(pt.inst, "STORE", 5)) {
		opcode = 6;
        } else if (vasm_strcmp(pt.inst, "JLT", 3)) {
		opcode = 7;
		value = 1;
        } else if (vasm_strcmp(pt.inst, "JGT", 3)) {
		opcode = 7;
		value = 3;
        } else if (vasm_strcmp(pt.inst, "JQT", 3)) {
		opcode = 7;
		value = 2;
        } else if (vasm_strcmp(pt.inst, "JMP", 3)) {
		opcode = 7;
		value = 5;
	}
	if (opcode < 0) {
		return -1;
	}
	pt = split(line, 1);
        if (vasm_strcmp(pt.inst, "AX", 2)) {
		reg_idx = 0;
        } else if (vasm_strcmp(pt.inst, "BX", 2)) {
		reg_idx = 1;
        } else if (vasm_strcmp(pt.inst, "CX", 2)) {
		reg_idx = 2;
        } else if (vasm_strcmp(pt.inst, "DX", 2)) {
		reg_idx = 3;
        } else if (vasm_strcmp(pt.inst, "EX", 2)) {
		reg_idx = 4;
        } else if (vasm_strcmp(pt.inst, "FX", 2)) {
		reg_idx = 5;
        } else if (vasm_strcmp(pt.inst, "GX", 2)) {
		reg_idx = 6;
        } else if (vasm_strcmp(pt.inst, "HX", 2)) {
		reg_idx = 7;
        } else if (vasm_strcmp(pt.inst, "IX", 2)) {
		reg_idx = 8;
	} if (reg_idx < 0) {
		return -1;
	}
	pt = split(line, 2);
	if (value < 0) {
	        if (vasm_strcmp(pt.inst, "NUM", 3)) {
			value = 0;
	        } else if (vasm_strcmp(pt.inst, "REG", 3)) {
			value = 1;
		}
	} if (value < 0) {
		return -1;
	pt = split(line, 3);
	} if (opcode == 7 || value == 1) {
	        if (vasm_strcmp(pt.inst, "AX", 2)) {
        	        in = 0;
	        } else if (vasm_strcmp(pt.inst, "BX", 2)) {
        	        in = 1;
	        } else if (vasm_strcmp(pt.inst, "CX", 2)) {
        	        in = 2;
	        } else if (vasm_strcmp(pt.inst, "DX", 2)) {
        	        in = 3;
	        } else if (vasm_strcmp(pt.inst, "EX", 2)) {
        	        in = 4;
	        } else if (vasm_strcmp(pt.inst, "FX", 2)) {
	                in = 5;
	        } else if (vasm_strcmp(pt.inst, "GX", 2)) {
        	        in = 6;
	        } else if (vasm_strcmp(pt.inst, "HX", 2)) {
	                in = 7;
	        } else if (vasm_strcmp(pt.inst, "IX", 2)) {
	                in = 8;
	        }
	} else {
		in = pt.inst[0] - '0';
	}
	int bytecode = 10000;
	int bytecode = 10000 + in * 1000 + value * 100 + reg_idx * 10 + opcode;
	return bytecode;
}



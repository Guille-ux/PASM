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

char vasm_strcmp(const char *str1, const char *str2, int len, int b) {
	for (int ch = 0; ch < len); ch++) {
		if (str1[ch+b] != str2[ch]) {
			return 0;
		}
	}
	return 1;
}



int asemble(const char *line) {
	int opcode = -1;
	int reg_idx = -1;
	int value = -1;
	int in = -1;
	if (vasm_strcmp(line, "MOV", 3, 0)) {
		opcode = 1;
	} else if (vasm_strcmp(line, "ADD", 3, 0)) {
		opcode = 2;
        } else if (vasm_strcmp(line, "SUB", 3, 0)) {
		opcode = 3;
        } else if (vasm_strcmp(line, "MUL", 3, 0)) {
		opcode = 4;
        } else if (vasm_strcmp(line, "DIV", 3, 0)) {
		opcode = 5;
        } else if (vasm_strcmp(line, "JNQ", 3, 0)) {
		opcode = 7;
		value = 4;
        } else if (vasm_strcmp(line, "LOA", 3, 0)) {
		opcode = 8;
        } else if (vasm_strcmp(line, "STR", 3, 0)) {
		opcode = 6;
        } else if (vasm_strcmp(line, "JLT", 3, 0)) {
		opcode = 7;
		value = 1;
        } else if (vasm_strcmp(line, "JGT", 3, 0)) {
		opcode = 7;
		value = 3;
        } else if (vasm_strcmp(line, "JQT", 3, 0)) {
		opcode = 7;
		value = 2;
        } else if (vasm_strcmp(line, "JMP", 3, 0)) {
		opcode = 7;
		value = 5;
	}
	if (opcode < 0) { // MOV AX NUM 5
		return -1;
	}
        if (vasm_strcmp(line, "AX", 2, 4)) {
		reg_idx = 0;
        } else if (vasm_strcmp(line, "BX", 2, 4)) {
		reg_idx = 1;
        } else if (vasm_strcmp(line, "CX", 2, 4)) {
		reg_idx = 2;
        } else if (vasm_strcmp(line, "DX", 2, 4)) {
		reg_idx = 3;
        } else if (vasm_strcmp(line, "EX", 2, 4)) {
		reg_idx = 4;
        } else if (vasm_strcmp(line, "FX", 2, 4)) {
		reg_idx = 5;
        } else if (vasm_strcmp(line, "GX", 2, 4)) {
		reg_idx = 6;
        } else if (vasm_strcmp(line, "HX", 2, 4)) {
		reg_idx = 7;
        } else if (vasm_strcmp(line, "IX", 2, 4)) {
		reg_idx = 8;
	} if (reg_idx < 0) {
		return -2;
	}
	if (value < 0) {
	        if (vasm_strcmp(line, "NUM", 3, 7)) {
			value = 0;
	        } else if (vasm_strcmp(line, "REG", 3, 7)) {
			value = 1;
		}
	} if (value < 0) {
		return -3;
	} if (opcode == 7 || value == 1) {
	        if (vasm_strcmp(line, "AX", 2, 11)) {
        	        in = 0;
	        } else if (vasm_strcmp(line, "BX", 2, 11)) {
        	        in = 1;
	        } else if (vasm_strcmp(line, "CX", 2, 11)) {
        	        in = 2;
	        } else if (vasm_strcmp(line, "DX", 2, 11)) {
        	        in = 3;
	        } else if (vasm_strcmp(line, "EX", 2, 11)) {
        	        in = 4;
	        } else if (vasm_strcmp(line, "FX", 2, 11)) {
	                in = 5;
	        } else if (vasm_strcmp(line, "GX", 2, 11)) {
        	        in = 6;
	        } else if (vasm_strcmp(line, "HX", 2, 11)) {
	                in = 7;
	        } else if (vasm_strcmp(line, "IX", 2, 11)) {
	                in = 8;
	        }
	} else if (value == 0){
		in = line[11] - '0';
	}
	int bytecode = 10000 + in * 1000 + value * 100 + reg_idx * 10 + opcode;
	return bytecode;
}



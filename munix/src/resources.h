int reg_a = 0; //reg 0
int reg_b = 0; //reg 1
int reg_c = 0; //reg 2
int reg_d = 0; //reg 3

int read_reg(int n_reg) {
	if (n_reg == 0) {
		return reg_a;
	} else if (n_reg == 1) {
		return reg_b;
	} else if (n_reg == 2) {
		return reg_c;
	} else if (n_reg == 3) {
		return reg_d;
	} else {
		return 0;
	}
}

void write_reg(int n_reg, int dat) {
        if (n_reg == 0) {
		reg_a = dat;
        } else if (n_reg == 1) {
		reg_b = dat;
        } else if (n_reg == 2) {
		reg_c = dat;
        } else if (n_reg == 3) {
		reg_d = dat;
        }
}

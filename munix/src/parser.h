char single_parse(const char *ord) {
	char inter1;
	char inter2;
	if (ccmp(ord, "mov", 3) == 1) {
		if (sccmp(ord, "a", 4, 1) == 1) {
			inter1 = 0;
		}
                else if (sccmp(ord, "b", 4, 1) == 1) {
                        inter1 = 1;
                }
                else if (sccmp(ord, "c", 4, 1) == 1) {
                        inter1 = 2;
                }
                else if (sccmp(ord, "d", 4, 1) == 1) {
                        inter1 = 3;
                }
		write_reg(inter1, cinter(ord, 100, 6)); //max 100 digits on the number
	}
}

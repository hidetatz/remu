#include "remu.h"

int load_elf(char *buf) {
	FILE *f;
	
	f = fopen("./remu_bin","r");
	
	if (f == NULL)
		return -1;

	Elf64_Ehdr header;
	fread(&header, 1, sizeof(header), f);
	
	if(header.e_type == 0x7f &&
		header.e_ident[1] == 'E' &&
		header.e_ident[2] == 'L' &&
		header.e_ident[3] == 'F') {
		printf("ok\n");
	}
	
	fclose(f);
	
	return 0;
}

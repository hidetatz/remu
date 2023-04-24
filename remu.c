#include "remu.h"
#include <stdlib.h>

int main(int argc, char* argv[]) {
	char *ptr;
	ptr = malloc(100);
	load_elf(ptr);
	free(ptr);
}

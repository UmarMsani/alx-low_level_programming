#include <stdio.h>
#include <stdlib.h>
#include <sys/types.h>
#include <fcntl.h>
#include <string.h>
#include <unistd.h>
#include <stdint.h>

/*
 * ELF header structure
 */
typedef struct
{
	unsigned char e_ident[16];
	uint16_t e_type;
	uint16_t e_shstrndx;
	uint64_t e_entry;
	uint16_t e_machine;
	uint32_t e_version;
	uint64_t e_phoff;
	uint64_t e_shoff;
	uint16_t e_phentsize;
	uint32_t e_flags;
	uint16_t e_ehsize;
	uint16_t e_phnum;
	uint16_t e_shentsize;
	uint16_t e_shnum;
} Elf64_Ehdr;

/*
 * Function to display the ELF header information
 */
void display_elf_header(const Elf64_Ehdr *header)
{
	printf("Magic: %02x %02x %02x %02x\n",
			header->e_ident[0], header->e_ident[1],
			header->e_ident[2], header->e_ident[3]);

	printf("Class: %d-bit\n", header->e_ident[4] == 1 ? 32 : 64);

	printf("Data: %s\n", header->e_ident[5] == 1 ? "little-endian" : "big-endian");

	printf("Version: %d\n", header->e_ident[6]);

	printf("OS/ABI: %d\n", header->e_ident[7]);

	printf("ABI Version: %d\n", header->e_ident[8]);

	printf("Type: 0x%x\n", header->e_type);

	printf("Entry point address: 0x%lx\n", header->e_entry);
}

/*
 * Function to read and display the ELF header
 */
void read_elf_header(const char *file)
{
	int i;
	Elf64_Ehdr header;
	ssize_t bytes_read;

	i = open(file, O_RDONLY);
	if (i == -1)
	{
		fprintf(stderr, "Error opening file: %s\n", file);
		exit(98);
	}

	bytes_read = read(i, &header, sizeof(Elf64_Ehdr));
	if (bytes_read != sizeof(Elf64_Ehdr)) {
		fprintf(stderr, "Error reading ELF header\n");
		exit(98);
	}

	display_elf_header(&header);

	close(i);
}

int main(int argc, char *argv[])
{
	if (argc != 2)
	{
		fprintf(stderr, "Usage: %s elf_filename\n", argv[0]);
		return (1);
	}

	read_elf_header(argv[1]);

	return (0);
}

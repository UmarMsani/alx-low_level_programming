#include <stdio.h>
#include <stdlib.h>
#include <fcntl.h>
#include <unistd.h>
#include <elf.h>
#include <string.h>

void print_error(const char *message)
{
	fprintf(stderr, "Error: %s\n", message);
	exit(98);
}

void display_elf_header(const char *filename)
{
	Elf64_Ehdr header;
	int i;

	int fd = open(filename, O_RDONLY);
	if (fd == -1)
	{
		print_error("Could not open the file");
	}

	if (read(fd, &header, sizeof(header)) != sizeof(header))
	{
		close(fd);
		print_error("Could not read ELF header");
	}

	if (memcmp(header.e_ident, ELFMAG, SELFMAG) != 0)
	{
		close(fd);
		print_error("Not an ELF file");
	}

	printf("ELF Header:\n");
	printf("  Magic:   ");
	for (i = 0; i < SELFMAG; i++)
	{
		printf("%02x ", (unsigned char)header.e_ident[i]);
	}
	printf("\n");
	printf("  Class:                             %s\n", header.e_ident[EI_CLASS] == ELFCLASS64 ? "ELF64" : "ELF32");
	printf("  Data:                              %s\n", header.e_ident[EI_DATA] == ELFDATA2LSB ? "2's complement, little endian" : "Unknown");
	printf("  Version:                           %d (current)\n", header.e_ident[EI_VERSION]);
	printf("  OS/ABI:                            %s\n", header.e_ident[EI_OSABI] == ELFOSABI_SYSV ? "UNIX - System V" : "Unknown");
	printf("  ABI Version:                       %d\n", header.e_ident[EI_ABIVERSION]);
	printf("  Type:                              %d\n", header.e_type);
	printf("  Entry point address:               0x%lx\n", (unsigned long)header.e_entry);

	close(fd);
}

int main(int argc, char *argv[])
{
	if (argc != 2)
	{
		print_error("Usage: elf_header elf_filename");
	}

	display_elf_header(argv[1]);

	return (0);
}

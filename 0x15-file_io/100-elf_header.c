#include <stdio.h>
#include <stdlib.h>
#include <fcntl.h>
#include <unistd.h>
#include <elf.h>
#include <string.h>
#include <errno.h>

void print_error(const char *error_msg) {
	fprintf(stderr, "%s\n", error_msg);
	exit(98);
}

void display_elf_header(const Elf64_Ehdr *elf_header)
{
	int i;

	printf("ELF Header:\n");
	/* Magic */
	printf("  Magic:   ");
	for (i = 0; i < EI_NIDENT; i++)
		printf("%02x ", elf_header->e_ident[i]);
	printf("\n");

	/* Class */
	printf("  Class:                             ");
	switch (elf_header->e_ident[EI_CLASS])
	{
		case ELFCLASS32:
			printf("ELF32\n");
			break;
		case ELFCLASS64:
			printf("ELF64\n");
			break;
		default:
			printf("Invalid class\n");
			break;
	}

	/* Data */
	printf("  Data:                              ");
	switch (elf_header->e_ident[EI_DATA])
	{
		case ELFDATA2LSB:
			printf("2's complement, little endian\n");
			break;
		case ELFDATA2MSB:
			printf("2's complement, big endian\n");
			break;
		default:
			printf("Invalid data encoding\n");
			break;
	}

	/*  Version */
	printf("  Version:                           %d (current)\n", elf_header->e_ident[EI_VERSION]);

	/* OS/ABI */
	printf("  OS/ABI:                            ");
	switch (elf_header->e_ident[EI_OSABI])
	{
		case ELFOSABI_SYSV:
			printf("UNIX - System V\n");
			break;
		case ELFOSABI_HPUX:
			printf("HP-UX\n");
			break;
		case ELFOSABI_NETBSD:
			printf("NetBSD\n");
			break;
		case ELFOSABI_LINUX:
			printf("Linux\n");
			break;
		case ELFOSABI_SOLARIS:
			printf("Sun Solaris\n");
			break;
		case ELFOSABI_IRIX:
			printf("SGI Irix\n");
			break;
		case ELFOSABI_FREEBSD:
			printf("FreeBSD\n");
			break;
		case ELFOSABI_TRU64:
			printf("Compaq TRU64 UNIX\n");
			break;
		case ELFOSABI_ARM:
			printf("ARM architecture\n");
			break;
		case ELFOSABI_STANDALONE:
			printf("Standalone (embedded) application\n");
			break;
		default:
			printf("Unknown OS/ABI\n");
			break;
	}

	/* ABI Version */
	printf("  ABI Version:                       %d\n", elf_header->e_ident[EI_ABIVERSION]);

	/* Type */
	printf("  Type:                              ");
	switch (elf_header->e_type)
	{
		case ET_NONE:
			printf("NONE (No file type)\n");
			break;
		case ET_REL:
			printf("REL (Relocatable file)\n");
			break;
		case ET_EXEC:
			printf("EXEC (Executable file)\n");
			break;
		case ET_DYN:
			printf("DYN (Shared object file)\n");
			break;
		case ET_CORE:
			printf("CORE (Core file)\n");
			break;
		default:
			printf("Unknown type\n");
			break;
	}

	/* Entry point address */
	printf("  Entry point address:               0x%lx\n", (unsigned long)elf_header->e_entry);
}

int main(int argc, char *argv[])
{
	const char *filenames = argv[1];
	int fil;
	Elf64_Ehdr elf_header;
	ssize_t bytes_read;

	if (argc != 2)
	{
		print_error("Usage: elf_header elf_filename");
	}

	fil = open(filenames, O_RDONLY);
	if (fil == -1)
	{
		print_error("Error opening file");
	}
		
	bytes_read = read(fil, &elf_header, sizeof(Elf64_Ehdr));

	if (bytes_read == -1)
	{
		print_error("Error reading file");
	}

	if ((size_t)bytes_read < sizeof(Elf64_Ehdr))
	{
		print_error("Invalid ELF file");
	}

	if (memcmp(elf_header.e_ident, ELFMAG, SELFMAG) != 0)
	{
		print_error("Not an ELF file");
	}

	display_elf_header(&elf_header);

	close(fil);
	return 0;
}

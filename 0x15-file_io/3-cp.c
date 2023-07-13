#include <elf.h>
#include <sys/types.h>
#include <sys/stat.h>
#include <fcntl.h>
#include <unistd.h>
#include <stdio.h>
#include <stdlib.h>

void search_elf(unsigned char *e_pointer);
void write_magic(unsigned char *e_pointer);
void write_class(unsigned char *e_pointer);
void write_data(unsigned char *e_pointer);
void write_version(unsigned char *e_pointer);
void write_abi(unsigned char *e_pointer);
void write_osabi(unsigned char *e_pointer);
void write_type(unsigned int e_type, unsigned char *e_pointer);
void write_entry(unsigned long int e_entry, unsigned char *e_pointer);
void shut_elf(int elf);

/**
 * * search_elf - search for an ELF file.
 * * @e_pointer: A pointer to an array containing the ELF magic numbers.
 * *
 * * Description: If the file is not an ELF file - exit code 98.
 */
void search_elf(unsigned char *e_pointer)
{
	int index;

	for (index = 0; index < 4; index++)
	{
		if (e_pointer[index] != 127 &&
				e_pointer[index] != 'E' &&
				e_pointer[index] != 'L' &&
				e_pointer[index] != 'F')
		{
			dprintf(STDERR_FILENO, "Error: Not an ELF file\n");
			exit(98);
		}
	}
}

/**
 * * write_magic - write the magic numbers of an ELF header.
 * * @e_pointer: A pointer to an array containing the ELF magic numbers.
 * *
 * * Description: Magic numbers are separated by spaces.
 */
void write_magic(unsigned char *e_pointer)
{
	int index;

	printf(" Magic: ");

	for (index = 0; index < EI_NIDENT; index++)
	{
		printf("%02x", e_pointer[index]);

		if (index == EI_NIDENT - 1)
			printf("\n");
		else
			printf(" ");
	}
}

/**
 * * write_class - write the class of an ELF header.
 * * @e_pointer: A pointer to an array containing the ELF class.
 */
void write_class(unsigned char *e_pointer)
{
	printf(" Class: ");

	switch (e_pointer[EI_CLASS])
	{
		case ELFCLASSNONE:
			printf("none\n");
			break;
		case ELFCLASS32:
			printf("ELF32\n");
			break;
		case ELFCLASS64:
			printf("ELF64\n");
			break;
		default:
			printf("<unknown: %x>\n", e_pointer[EI_CLASS]);
	}
}

/**
 * * write_data - write the data of an ELF header.
 * * @e_pointer: A pointer to an array containing the ELF class.
 */
void write_data(unsigned char *e_pointer)
{
	printf(" Data: ");

	switch (e_pointer[EI_DATA])
	{
		case ELFDATANONE:
			printf("none\n");
			break;
		case ELFDATA2LSB:
			printf("2's complement, little endian\n");
			break;
		case ELFDATA2MSB:
			printf("2's complement, big endian\n");
			break;
		default:
			printf("<unknown: %x>\n", e_pointer[EI_CLASS]);
	}
}

/**
 * * write_version - write the version of an ELF header.
 * * @e_pointer: A pointer to an array containing the ELF version.
 */
void write_version(unsigned char *e_pointer)
{
	printf(" Version: %d",
			e_pointer[EI_VERSION]);

	switch (e_pointer[EI_VERSION])
	{
		case EV_CURRENT:
			printf(" (current)\n");
			break;
		default:
			printf("\n");
			break;
	}
}

/**
 * * write_osabi - write the OS/ABI of an ELF header.
 * * @e_pointer: A pointer to an array containing the ELF version.
 */
void write_osabi(unsigned char *e_pointer)
{
	printf(" OS/ABI: ");

	switch (e_pointer[EI_OSABI])
	{
		case ELFOSABI_NONE:
			printf("UNIX - System V\n");
			break;
		case ELFOSABI_HPUX:
			printf("UNIX - HP-UX\n");
			break;
		case ELFOSABI_NETBSD:
			printf("UNIX - NetBSD\n");
			break;
		case ELFOSABI_LINUX:
			printf("UNIX - Linux\n");
			break;
		case ELFOSABI_SOLARIS:
			printf("UNIX - Solaris\n");
			break;
		case ELFOSABI_IRIX:
			printf("UNIX - IRIX\n");
			break;
		case ELFOSABI_FREEBSD:
			printf("UNIX - FreeBSD\n");
			break;
		case ELFOSABI_TRU64:
			printf("UNIX - TRU64\n");
			break;
		case ELFOSABI_ARM:
			printf("ARM\n");
			break;
		case ELFOSABI_STANDALONE:
			printf("Standalone App\n");
			break;
		default:
			printf("<unknown: %x>\n", e_pointer[EI_OSABI]);
	}
}

/**
 * * write_abi - write the ABI version of an ELF header.
 * * @e_pointer: A pointer to an array containing the ELF ABI version.
 */
void write_abi(unsigned char *e_pointer)
{
	printf(" ABI Version: %d\n",
			e_pointer[EI_ABIVERSION]);
}

/**
 * * write_type - write the type of an ELF header.
 * * @e_type: The ELF type.
 * * @e_pointer: A pointer to an array containing the ELF class.
 */
void write_type(unsigned int e_type, unsigned char *e_pointer)
{
	if (e_pointer[EI_DATA] == ELFDATA2MSB)
		e_type >>= 8;

	printf(" Type: ");

	switch (e_type)
	{
		case ET_NONE:
			printf("NONE (None)\n");
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
			printf("<unknown: %x>\n", e_type);
	}
}

/**
 * * write_entry - write the entry point of an ELF header.
 * * @e_entry: The address of the ELF entry point.
 * * @e_pointer: A pointer to an array containing the ELF class.
 */
void write_entry(unsigned long int e_entry, unsigned char *e_pointer)
{
	printf(" Entry point address: ");

	if (e_pointer[EI_DATA] == ELFDATA2MSB)
	{
		e_entry = ((e_entry << 8) & 0xFF00FF00) |
			((e_entry >> 8) & 0xFF00FF);
		e_entry = (e_entry << 16) | (e_entry >> 16);
	}

	if (e_pointer[EI_CLASS] == ELFCLASS32)
		printf("%#x\n", (unsigned int)e_entry);

	else
		printf("%#lx\n", e_entry);
}

/**
 * * shut_elf - Closes an ELF file.
 * * @elf: The file descriptor of the ELF file.
 * *
 * * Description: If the file cannot be closed - exit code 98.
 */
void shut_elf(int elf)
{
	if (close(elf) == -1)
	{
		dprintf(STDERR_FILENO,
				"Error: Can't close fd %d\n", elf);
		exit(98);
	}
}

/**
 * * main - Displays the information contained in the
 * * ELF header at the start of an ELF file.
 * * @argc: The number of arguments supplied to the program.
 * * @argv: An array of pointers to the arguments.
 * *
 * * Return: 0 on success.
 */
int main(int __attribute__((__unused__)) argc, char *argv[])
{
	Elf64_Ehdr *header;
	int opn, wrt;

	opn = open(argv[1], O_RDONLY);
	if (opn == -1)
	{
		dprintf(STDERR_FILENO, "Error: Can't read file %s\n", argv[1]);
		exit(98);
	}
	header = malloc(sizeof(Elf64_Ehdr));
	if (header == NULL)
	{
		shut_elf(opn);
		dprintf(STDERR_FILENO, "Error: Can't read file %s\n", argv[1]);
		exit(98);
	}
	wrt = read(opn, header, sizeof(Elf64_Ehdr));
	if (wrt == -1)
	{
		free(header);
		shut_elf(opn);
		dprintf(STDERR_FILENO, "Error: `%s`: No such file\n", argv[1]);
		exit(98);
	}

	search_elf(header->e_pointer);
	printf("ELF Header:\n");
	write_magic(header->e_pointer);
	write_class(header->e_pointer);
	write_data(header->e_pointer);
	write_version(header->e_pointer);
	write_osabi(header->e_pointer);
	write_abi(header->e_pointer);
	write_type(header->e_type, header->e_pointer);
	write_entry(header->e_entry, header->e_pointer);

	free(header);
	shut_elf(opn);
	return (0);
}

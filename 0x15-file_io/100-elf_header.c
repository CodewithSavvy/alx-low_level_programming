#include <stdio.h>
#include <stdlib.h>
#include <sys/types.h>
#include <sys/stat.h>
#include <fcntl.h>
#include <unistd.h>
#include <elf.h>

/**
 * * write_addr - writes address
 * * @ptr: Pointer.
 */
void write_addr(char *ptr)
{
	int index;
	int start;
	char sys;

	printf("  Entry point address:               0x");

	sys = ptr[4] + '0';
	if (sys == '1')
	{
		start = 26;
		printf("80");
		for (index = start; index >= 22; index--)
		{
			if (ptr[index] > 0)
				printf("%x", ptr[index]);
			else if (ptr[index] < 0)
				printf("%x", 256 + ptr[index]);
		}
		if (ptr[7] == 6)
			printf("00");
	}

	if (sys == '2')
	{
		start = 26;
		for (index = start; index > 23; index--)
		{
			if (ptr[index] >= 0)
				printf("%02x", ptr[index]);

			else if (ptr[index] < 0)
				printf("%02x", 256 + ptr[index]);

		}
	}
	printf("\n");
}

/**
 * * write_type - writes type
 * * @ptr: Pointer
 */
void write_type(char *ptr)
{
	char buffer = ptr[16];

	if (ptr[5] == 1)
		buffer = ptr[16];
	else
		buffer = ptr[17];

	printf("  Type:                              ");
	if (buffer == 0)
		printf("NONE (No file type)\n");
	else if (buffer == 1)
		printf("REL (Relocatable file)\n");
	else if (buffer == 2)
		printf("EXEC (Executable file)\n");
	else if (buffer == 3)
		printf("DYN (Shared object file)\n");
	else if (buffer == 4)
		printf("CORE (Core file)\n");
	else
		printf("<unknown: %x>\n", buffer);
}

/**
 * * write_osabi - prints osabi
 * * @ptr: Pointer
 */
void write_osabi(char *ptr)
{
	char os = ptr[7];

	printf("  OS/ABI:                            ");
	if (os == 0)
		printf("UNIX - System V\n");
	else if (os == 2)
		printf("UNIX - NetBSD\n");
	else if (os == 6)
		printf("UNIX - Solaris\n");
	else
		printf("<unknown: %x>\n", os);

	printf("  ABI Version:                       %d\n", ptr[8]);
}


/**
 * * write_version - writes version
 * * @ptr: Pointer
 */
void write_version(char *ptr)
{
	int version = ptr[6];

	printf("  Version:                           %d", version);

	if (version == EV_CURRENT)
		printf(" (current)");

	printf("\n");
}
/**
 * * write_data - prints data
 * * @ptr: Pointer
 */
void write_data(char *ptr)
{
	char data = ptr[5];

	printf("  Data:                              2's complement");
	if (data == 1)
		printf(", little endian\n");

	if (data == 2)
		printf(", big endian\n");
}

/**
 * * write_magic - prints magic info.
 * * @ptr: Pointer
 */
void write_magic(char *ptr)
{
	int buffer;

	printf("  Magic:  ");

	for (buf = 0; buf < 16; buffer++)
		printf(" %02x", ptr[buffer]);

	printf("\n");

}

/**
 * * search_sys - search the version system.
 * * @ptr: magic.
 * * Return: no return.
 */
void search_sys(char *ptr)
{
	char sys = ptr[4] + '0';

	if (sys == '0')
		exit(98);

	printf("ELF Header:\n");
	write_magic(ptr);

	if (sys == '1')
		printf("  Class:                             ELF32\n");

	if (sys == '2')
		printf("  Class:                             ELF64\n");

	write_data(ptr);
	write_version(ptr);
	write_osabi(ptr);
	write_type(ptr);
	write_addr(ptr);
}

/**
 * * search_elf - check if it is an elf file.
 * * @ptr: magic.
 * * Return: 1 if it is an elf file. 0 if not.
 */
int search_elf(char *ptr)
{
	int addr = (int)ptr[0];
	char E = ptr[1];
	char L = ptr[2];
	char F = ptr[3];

	if (addr == 127 && E == 'E' && L == 'L' && F == 'F')
		return (1);

	return (0);
}

/**
 * * main - Displays the information contained
 * * @argc: number of arguments.
 * * @argv: arguments array.
 * * Return: Always 0.
 */
int main(int argc, char *argv[])
{
	int fd, ret_read;
	char ptr[27];

	if (argc != 2)
	{
		dprintf(STDERR_FILENO, "Usage: elf_header elf_filename\n");
		exit(98);
	}

	fd = open(argv[1], O_RDONLY);

	if (fd < 0)
	{
		dprintf(STDERR_FILENO, "Err: file can not be open\n");
		exit(98);
	}

	lseek(fd, 0, SEEK_SET);
	ret_read = read(fd, pointer, 27);

	if (ret_read == -1)
	{
		dprintf(STDERR_FILENO, "Err: The file can not be read\n");
		exit(98);
	}

	if (!search_elf(pointer))
	{
		dprintf(STDERR_FILENO, "Err: It is not an ELF\n");
		exit(98);
	}

	search_sys(pointer);
	close(fd);

	return (0);
}

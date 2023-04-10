#include "main.h"
/**
 * * get_endianness - checks if a machine is little endian or big endian
 * *
 * * Return: 0 for big, 1 for little
 */
int get_endianness(void)
{
	unsigned int end = 1;

	/*asigning the pointer to the address of end*/
	char *ptrc = (char *) &end;

	return (*ptrc);
}

#include "main.h"
/**
 * * binary_to_uint -function that converts a binary number
 * * to an unsigned int.
 * * @b: string containing the binary number to be converted
 * *
 * * Return: the converted number or 0
 * * if b is pointing to NULL;
 */

unsigned int binary_to_uint(const char *b)
{
	unsigned int count, decimal = 0;

	/**checking if b is empty or NULL*/
	if (!b)
		return (0);
	/*looping through the lenght of the string*/
	for (count = 0; b[count]; count++)
	{
		/*checking if there is a character in the string*/
		if (b[count] < '0' || b[count] > '1')
			return (0);
		decimal = 2 * decimal + (b[count] - '0');
	}
	return (decimal);
}


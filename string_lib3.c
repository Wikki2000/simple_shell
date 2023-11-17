#include "shell.h"

/**
 * buf_overflow - check if buffer has overflowed
 * @d: data position
 * @b: byte size
 * @bf: buffer
 * @f: file descriptor
 * @l: line buffer
 * @lp: line position
 * @s: line buffer size
 * Return: integer
 */

int buf_overflow(int *d, int *b, char *bf, int *f, char *l, int *lp, size_t *s)
{
	if (*d >= *b)
	{
		*b = read(*f, bf, 1023);
		if (*b <= 0)
		{
			l[*lp] = '\0';
			*s = *lp;
			return (*s);
		}
		*d = 0;
	}

	/* just a random number */
	return (-100);
}


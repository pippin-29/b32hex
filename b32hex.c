/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   b32hex.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dhadding <daniel42.c@engineer.com>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/07/23 05:22:58 by dhadding          #+#    #+#             */
/*   Updated: 2023/07/23 08:46:57 by dhadding         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdlib.h>
#include <stdio.h>

typedef unsigned int u32;

void print_bits(u32 bin)
{
	u32	i = 32;
	u32 bit;

	while (i--)
	{
		bit = (bin >> i & 1);
		printf("%u", bit);
	}
}

u32 isNum(char *in)
{
	u32 i = 0;
	while (in[i])
	{
		if (in[i] < '0' || in[i] > '9')
			return (0);
		i++;
	}
	return (1);
}

void err_dup(int size, u32 *bits)
{
	int	i;
	int	j;

	i = 0;
	while (i < size - 1)
	{
		j = i + 1;
		while (j < size)
		{
			if (bits[i] == bits[j])
			{
				printf("Please Remove duplicates;\n");
				exit(1);
			}
			j++;
		}
		i++;
	}
}

u32 *sort2max(u32 size, char **argv)
{
	u32 *out = calloc(size, sizeof(u32));
	u32 i = 1;

	while (argv[i])
	{
		if ((out[i - 1] = atoi(argv[i])) < 0)
		{
			printf("Please do not enter negative numbers;\n");
			exit(1);
		}
		i++;
	}
	u32 ii = 0;
	u32 cc = 0;
	while (ii < size)
	{
		cc = 0;
		while (cc < (size - ii - 1))
		{
			if (out[cc] > out[cc + 1])
			{
				u32 temp = out[cc];
				out[cc] = out[cc + 1];
				out[cc + 1] = temp;
			}
			cc++;
		}
		ii++;
	}
	return (out);
}

u32	con2bin(u32 size, u32 *bits)
{
	u32 bin = 0b0;
	u32 d = 0;

	while (d < size)
	{
		if (bits[d] > 31)
		{
			printf("Please Enter a bit position below 32;\n");
			exit(1);
		}
		u32 shift = 0b1 << bits[d];
		bin |= shift;
		d++;
	}
	print_bits(bin);
	printf("\n");
	return (bin);
}

int main (int argc, char **argv)
{
	if (argc > 1 && argc < 34)
	{
		u32 *bits;
		u32 bin = 0b0;
		u32 i = 1;

		while (argv[i])
		{
			
			if (!isNum(argv[i]))
			{
				printf("Please Enter Numbers Only;\n");
				exit(1);
			
			}
			i++;
		}
		bits = sort2max(argc - 1, argv);
		err_dup(argc - 1, bits);
		i = 0;
		printf("Setting Bits: ");
		while (i < argc - 1)
		{
			printf("%d", bits[i]);
			if (i != argc - 2)
				printf(", ");
			i++;
		}
		printf("\n");
		bin = con2bin(argc - 1, bits);
		printf("Hexadecimal Representation = %X\n", bin);
		free(bits);
	} else {	printf("Please Enter each bit position that is set... \n Usage: bhex 15 31 0 1 \n");	}
	return (0);
}
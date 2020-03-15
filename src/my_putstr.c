/*
** EPITECH PROJECT, 2017
** my_put_str.c
** File description:
** task02
*/

#include "my.h"

int my_putstr(char const *str)
{
	int i = 0;

	for (i = 0; str[i] != '\0'; i++)
		my_putchar(str[i]);
	return (0);
}

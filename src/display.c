/*
** EPITECH PROJECT, 2017
** display.c
** File description:
** display
*/

#include "main.h"

void display_screen(instruct_t sf)
{
	sfRenderWindow_clear(sf.win, sfBlack);
	for (int i = 0; i < 3; i++)
		sfRenderWindow_drawSprite(sf.win, sf.sprite[i], NULL);
	sfRenderWindow_display(sf.win);
}

instruct_t game_over(instruct_t sf)
{
	sf.vector_duck.x = 260;
	sf.vector_duck.y = 250;
	sf.texture[1] = sfTexture_createFromFile("img/game_over.png", NULL);
	sfSprite_setTexture(sf.sprite[1], sf.texture[1], sfTrue);
	sfSprite_setPosition(sf.sprite[1], sf.vector_duck);
	return (sf);
}

int error(int ac, char **av)
{
	if (ac > 1 && av[1][0] != '-' && av[1][1] != 'h')
		return (0);
	else if (ac > 1 && av[1][0] == '-' && av[1][1] == 'h') {
		my_putstr("USAGE\n");
		my_putstr("       ./my_hunter\n\n");
		my_putstr("DESCRIPTION\n");
		my_putstr("       You have to shoot the ducks\n");
		return (0);
	} else
		return (1);
}

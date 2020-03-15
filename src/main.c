/*
** EPITECH PROJECT, 2017
** main.c
** File description:
** main
*/

#include "main.h"

instruct_t init_window(instruct_t sf)
{
	sfVideoMode mode = {900, 700, 32};

	sf.win = sfRenderWindow_create(
		mode, "My_Hunter", sfResize | sfClose, NULL);
	sfRenderWindow_setMouseCursorVisible(sf.win, 0);
	return (sf);
}

instruct_t init_params_struct(instruct_t sf)
{
	sf.texture = malloc(3);
	sf.sprite = malloc(3);
	sf.music = malloc(3);
	sf.clock = malloc(2);
	sf.time = malloc(1);
	sf.seconds = malloc(1);
	sf = init_window(sf);
	sf = create_sprite(sf, 1);
	sf = create_music(sf);
	sf = create_clock(sf);
	return (sf);
}

instruct_t destroy_params_struct(instruct_t sf)
{
	int i;

	for (i = 0; i < 3; i++) {
		sfSprite_destroy(sf.sprite[i]);
		sfTexture_destroy(sf.texture[i]);
		sfMusic_destroy(sf.music[i]);
	}
	for (i = 0; i < 2; i++)
		sfClock_destroy(sf.clock[i]);
	sfRenderWindow_destroy(sf.win);
	return (sf);
}

instruct_t all_action(instruct_t sf)
{
	if (sfMouse_isButtonPressed(sfMouseLeft) != 0) {
		if (sf.pos_click.x <= sf.vector_duck.x + 110
		    && sf.pos_click.x >= sf.vector_duck.x &&
		    sf.pos_click.y <= sf.vector_duck.y + 110
		    && sf.pos_click.y >= sf.vector_duck.y)
			sf = touch_duck(sf);
		else
			sf = touch_fail(sf);
	}
	sf = time_up(sf);
	sf = move_cross(sf);
	sf = move_sprite(sf);
	sf = fly(sf);
	sf = fail_time(sf);
	sf = change_background(sf);
	return (sf);
}

int main(int ac, char **av)
{
	instruct_t sf;

	if (error(ac, av) == 0)
		return (84);
	sf = init_params_struct(sf);
	sf.vitesse = 0.1;
	sf.nbr = 1;
	sf.fail = 1;
	sf.img = 0;
	while (sfRenderWindow_isOpen(sf.win)) {
		event_key(sf);
		display_screen(sf);
		if (sf.fail <= 1)
			sf = all_action(sf);
		else
			game_over(sf);
	}
	sf = destroy_params_struct(sf);
	return (0);
}

/*
** EPITECH PROJECT, 2017
** clock.c
** File description:
** clock
*/

#include "main.h"

instruct_t create_clock(instruct_t sf)
{
	sf.clock[0] = sfClock_create();
	sf.clock[1] = sfClock_create();
	return (sf);
}

instruct_t time_up(instruct_t sf)
{
	for (int i = 0; i < 2; i++) {
		sf.time[i] = sfClock_getElapsedTime(sf.clock[i]);
		sf.seconds[i] = sf.time[i].microseconds / 1000000.0;
	}
	return (sf);
}

instruct_t change_background(instruct_t sf)
{
	if (sf.seconds[1] > 7) {
		if (sf.img == 0) {
			sf.texture[0] = sfTexture_createFromFile(
				"img/background.png", NULL);
			sf.img = 1;
		}
		else if (sf.img == 1) {
			sf.texture[0] = sfTexture_createFromFile(
				"img/background_night.png", NULL);
			sf.img = 2;
		} else {
			sf.texture[0] = sfTexture_createFromFile(
				"img/background_morning.png", NULL);
			sf.img = 0;
		}
		sfSprite_setTexture(sf.sprite[0], sf.texture[0], sfTrue);
		sfClock_restart(sf.clock[1]);
	}
	return (sf);
}

instruct_t params_maj(instruct_t sf)
{
	sf.vitesse = -sf.vitesse;
	sf.rect.left = 0;
	sfSprite_setTextureRect(sf.sprite[1], sf.rect);
	sf.time_fail += 1;
	return (sf);
}

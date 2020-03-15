/*
** EPITECH PROJECT, 2017
** sprite.c
** File description:
** sprite
*/

#include "main.h"

instruct_t init_rect_duck(instruct_t sf)
{
	sf.rect.top = 0;
	sf.rect.left = 0;
	sf.rect.width = 110;
	sf.rect.height = 110;
	return (sf);
}

instruct_t create_sprite(instruct_t sf, int nb)
{
	sf = init_rect_duck(sf);
	sf.texture[0] = sfTexture_createFromFile(
		"img/background_morning.png", NULL);
	sf.sprite[0] = sfSprite_create();
	sfSprite_setTexture(sf.sprite[0], sf.texture[0], sfTrue);
	for (int i = 1; i <= nb; i++) {
		sf.texture[i] = sfTexture_createFromFile(
			"img/spritesheet.png", NULL);
		sf.sprite[i] = sfSprite_create();
		sfSprite_setTexture(sf.sprite[i], sf.texture[i], sfTrue);
		sfSprite_setTextureRect(sf.sprite[i], sf.rect);
		sf.vector_duck.x = 0;
		sf.vector_duck.y = 0;
		sfSprite_setPosition(sf.sprite[i], sf.vector_duck);
	}
	sf.texture[nb + 1] = sfTexture_createFromFile("img/cross2.png", NULL);
	sf.sprite[nb + 1] = sfSprite_create();
	sfSprite_setTexture(sf.sprite[nb + 1], sf.texture[nb + 1], sfTrue);
	return (sf);
}

instruct_t fly(instruct_t sf)
{
	if (sf.seconds[0] > 0.2) {
		if (sf.rect.left == 220)
			sf.rect.left = 0;
		else
			sf.rect.left = sf.rect.left + 110;
		sfSprite_setTextureRect(sf.sprite[1], sf.rect);
		sfClock_restart(sf.clock[0]);
	}
	return (sf);
}

instruct_t move_sprite(instruct_t sf)
{
	sf.vector_duck.x += sf.vitesse;
	sfSprite_setPosition(sf.sprite[1], sf.vector_duck);
	sf = border_duck(sf);
	return (sf);
}

instruct_t move_cross(instruct_t sf)
{
	sf.pos_click = sfMouse_getPositionRenderWindow(sf.win);
	sf.pos_cross.x = sf.pos_click.x - 75;
	sf.pos_cross.y = sf.pos_click.y - 75;
	sfSprite_setPosition(sf.sprite[2], sf.pos_cross);
	sfSprite_setTexture(sf.sprite[2], sf.texture[2], sfTrue);
	return (sf);
}

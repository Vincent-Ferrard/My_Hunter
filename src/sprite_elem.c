/*
** EPITECH PROJECT, 2017
** sprite_elem.c
** File description:
** sprite elem
*/

#include "main.h"

instruct_t border_duck(instruct_t sf)
{
	if (sf.vector_duck.x > 905) {
		sf.texture[1] = sfTexture_createFromFile(
			"img/spritesheet2.png", NULL);
		sfSprite_setTexture(sf.sprite[1], sf.texture[1], sfTrue);
		sf.vector_duck.x = 900;
		sf = params_maj(sf);
	}
	else if (sf.vector_duck.x + 130 < 0) {
		sf.texture[1] = sfTexture_createFromFile(
			"img/spritesheet.png", NULL);
		sfSprite_setTexture(sf.sprite[1], sf.texture[1], sfTrue);
		sf.vector_duck.x = 0;
		sf = params_maj(sf);
	}
	return (sf);
}

instruct_t touch_duck(instruct_t sf)
{
	int i = 0;

	sfMusic_play(sf.music[1]);
	sfMusic_play(sf.music[2]);
	sf.texture[1] = sfTexture_createFromFile("img/explose.png", NULL);
	sfSprite_setTexture(sf.sprite[1], sf.texture[1], sfTrue);
	while (i <= 100) {
		display_screen(sf);
		i++;
	}
	sf.texture[1] = sfTexture_createFromFile("img/dead.png", NULL);
	while (sf.vector_duck.y < 700) {
		sf.vector_duck.y++;
		sfSprite_setPosition(sf.sprite[1], sf.vector_duck);
		sfSprite_setTexture(sf.sprite[1], sf.texture[1], sfTrue);
		sf = move_cross(sf);
		display_screen(sf);
	}
	sf = touch_duck2(sf);
	return (sf);
}

instruct_t touch_duck2(instruct_t sf)
{
	my_putstr("Well done !\nScore : ");
	my_put_nbr(sf.nbr);
	my_putchar('\n');
	sf.nbr += 1;
	if (sf.vitesse < 0)
		sf.vitesse = -sf.vitesse;
	sf.texture[1] = sfTexture_createFromFile("img/spritesheet.png", NULL);
	sfSprite_setTexture(sf.sprite[1], sf.texture[1], sfTrue);
	sfSprite_setTextureRect(sf.sprite[1], sf.rect);
	srand(time(NULL));
	sf.vector_duck.y = rand() % (480 + 1);
	sf.vector_duck.x = -130;
	sf.vitesse += 0.1;
	sf.time_fail = 0;
	return (sf);
}

instruct_t touch_fail(instruct_t sf)
{
	my_putstr("Too bad ! You loose !\n");
	my_putstr("Your score : ");
	my_put_nbr(sf.nbr - 1);
	my_putchar('\n');
	sf.fail += 1;
	for (int i = 0; i < 3; i++)
		sfMusic_stop(sf.music[i]);
	return (sf);
}

instruct_t fail_time(instruct_t sf)
{
	if (sf.time_fail > 2) {
		if (sf.vector_duck.y < 0) {
			sf = touch_fail(sf);
			sf.time_fail = 0;
			if (sf.vitesse < 0)
				sf.vitesse = -sf.vitesse;
			sf.texture[1] = sfTexture_createFromFile(
				"img/spritesheet.png", NULL);
			sfSprite_setTexture(sf.sprite[1],
					    sf.texture[1], sfTrue);
			sfSprite_setTextureRect(sf.sprite[1], sf.rect);
			sf.vector_duck.y = rand() % (480 + 1);
			sf.vector_duck.x = -130;
			sf.vitesse += 0.1;
		} else
			sf.vector_duck.y -= 0.2;
	}
	return (sf);
}

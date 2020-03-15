/*
** EPITECH PROJECT, 2017
** struct.h
** File description:
** struct header
*/

#ifndef STRUCT_H_
#define STRUCT_H_

#include "main.h"

struct instruct {
	sfRenderWindow *win;
	sfEvent event;
	sfTexture **texture;
	sfSprite **sprite;
	sfIntRect rect;
	sfMusic **music;
	sfClock **clock;
	sfTime *time;
	float *seconds;
	sfVector2f vector_duck;
	sfVector2f pos_cross;
	sfVector2i pos_click;
	float vitesse;
	int img;
	int nbr;
	int fail;
	int time_fail;
};

typedef struct instruct instruct_t;

#endif

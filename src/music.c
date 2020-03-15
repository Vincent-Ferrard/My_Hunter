/*
** EPITECH PROJECT, 2017
** music.c
** File description:
** music
*/

#include "main.h"

instruct_t create_music(instruct_t sf)
{
	sf.music[0] = sfMusic_createFromFile("music/one-piece-ost.ogg");
	sf.music[1] = sfMusic_createFromFile("music/gun_shot.ogg");
	sf.music[2] = sfMusic_createFromFile("music/Explosion_3.ogg");
	sfMusic_play(sf.music[0]);
	sfMusic_setLoop(sf.music[0], 1);
	return (sf);
}

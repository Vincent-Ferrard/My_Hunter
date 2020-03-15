/*
** EPITECH PROJECT, 2017
** event.c
** File description:
** event
*/

#include "main.h"

void event_key(instruct_t sf)
{
	while (sfRenderWindow_pollEvent(sf.win, &sf.event)) {
		if (sf.event.type == sfEvtKeyPressed) {
			switch (sf.event.key.code) {
			case sfKeyEscape:
				sfRenderWindow_close(sf.win);
				break;
			case sfKeyReturn:
				if (sf.fail > 1)
					sfRenderWindow_close(sf.win);
				break;
			default:
				break;
			}
		}
	}
}

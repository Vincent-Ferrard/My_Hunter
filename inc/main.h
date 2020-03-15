/*
** EPITECH PROJECT, 2017
** main.h
** File description:
** main header
*/

#ifndef MAIN_H_
#define MAIN_H_

#include <stdlib.h>
#include <time.h>
#include <unistd.h>
#include <SFML/Graphics.h>
#include <SFML/Audio.h>

#include "struct.h"

#include "clock.h"
#include "display.h"
#include "event.h"
#include "music.h"
#include "my.h"
#include "sprite.h"
#include "sprite_elem.h"

instruct_t init_window(instruct_t sf);
instruct_t init_params_struct(instruct_t sf);
instruct_t destroy_params_struct(instruct_t sf);
instruct_t all_action(instruct_t sf);

#endif

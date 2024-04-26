/*
** EPITECH PROJECT, 2023
** Init window, rectangle and clock
** File description:
** Functions for the my_hunter project
*/

#include <SFML/Graphics.h>
#include <SFML/System.h>
#include "my.h"

sfIntRect set_rect(void)
{
    sfIntRect rect;

    rect.left = 0;
    rect.top = 0;
    rect.height = 110;
    rect.width = 110;
    return rect;
}

void animduck(sfIntRect *rect, int offset, int maxvalue)
{
    rect->left += offset;
    if (rect->left == maxvalue) {
        rect->left = 0;
    }
}

int initclock(sfIntRect* rect)
{
    sfRenderWindow* window;
    sfEvent event;
    sfClock *clock;
    sfTime time;
    float sec;

    clock = sfClock_create();
    time = sfClock_getElapsedTime(clock);
    sec = time.microseconds / 180000.0;
    while (sec < 1) {
        time = sfClock_getElapsedTime(clock);
        sec = time.microseconds / 180000.0;
    }
    sfClock_destroy(clock);
    animduck(rect, 110, 330);
    return 0;
}

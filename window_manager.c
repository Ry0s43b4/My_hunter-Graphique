/*
** EPITECH PROJECT, 2023
** Rectangle and window manager
** File description:
** Functions for the my_hunter project
*/

#include <SFML/Graphics.h>
#include <SFML/System.h>
#include <time.h>
#include "my.h"

int rectmanage(void)
{
    sfVideoMode mode = {1500, 1000, 32};
    sfVector2i windowpos = {200, 100};
    sfRenderWindow* window;
    sfTexture* texture;
    sfSprite* sprite;
    sfClock *clock;

    window = sfRenderWindow_create(mode, "SFML window", sfClose, NULL);
    if (!window)
        return 84;
    sfRenderWindow_setPosition(window, windowpos);
    texture = sfTexture_createFromFile("duck.png", NULL);
    if (!texture)
        return 84;
    sprite = sfSprite_create();
    sfSprite_setTexture(sprite, texture, sfTrue);
    windisplay(window, texture, sprite);
    return 0;
}

int windisplay(sfRenderWindow* window, sfTexture* texture, sfSprite* sprite)
{
    sfEvent event;
    sfIntRect rect = set_rect();

    while (sfRenderWindow_isOpen(window)) {
        initclock(&rect);
        winmanage(window, sprite, event, rect);
    }
    sfSprite_destroy(sprite);
    sfTexture_destroy(texture);
    sfRenderWindow_destroy(window);
    return 0;
}

int winmanage(sfRenderWindow* window, sfSprite* sprite,
    sfEvent event, sfIntRect rect)
{
    while (sfRenderWindow_pollEvent(window, &event)) {
        if (event.type == sfEvtClosed)
            sfRenderWindow_close(window);
    }
    sfRenderWindow_clear(window, sfBlack);
    sfSprite_setTextureRect(sprite, rect);
    sfRenderWindow_drawSprite(window, sprite, NULL);
    sfRenderWindow_display(window);
    return 0;
}

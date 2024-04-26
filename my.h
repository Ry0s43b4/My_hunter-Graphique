/*
** EPITECH PROJECT, 2023
** My h
** File description:
** Header for the functions
*/

#ifndef MY_H_
    #define MY_H_
    #include <SFML/Graphics.h>
    #include <SFML/System.h>

sfIntRect set_rect(void);
void animduck(sfIntRect *rect, int offset, int maxvalue);
int initclock(sfIntRect* rect);
int rectmanage(void);
int windisplay(sfRenderWindow* window, sfTexture* texture, sfSprite* sprite);
int winmanage(sfRenderWindow* window, sfSprite* sprite,
    sfEvent event, sfIntRect rect);

#endif

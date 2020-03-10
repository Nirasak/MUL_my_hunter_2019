/*
** EPITECH PROJECT, 2019
** bonus.h
** File description:
** bonus.h
*/

#ifndef MY_H_
#define MY_H_

#include <SFML/Graphics.h>
#include <SFML/Audio.h>
#include <SFML/Window.h>
#include <SFML/System.h>
#include <SFML/Window/Keyboard.h>
#include <SFML/Window/Mouse.h>
#include <stdbool.h>

#define MAX(x) ((x < 20) ? (x) : (19))
#define ABS(value) (((value) > 0) ? (value) : (-value))

#define MENU 0
#define GAME 1
#define OPTIONS 2
#define LDB 3
#define END 4

typedef struct ldb
{
    sfTexture *t_ldb;
    sfSprite *s_ldb;
    sfIntRect r_ldb;
    sfVector2f p_ldb;
    char **value_ldb;
    sfFont *font_ldb;
    sfText **txt_ldb;
    sfVector2f p_value_ldb;
} ldb_t;

typedef struct opt
{
    sfTexture *t_opt;
    sfTexture *t_vol;
    sfSprite *s_opt;
    sfSprite *s_vol;
    sfSprite *s_change_vol;
    sfSprite *s_return;
    sfIntRect r_opt;
    sfIntRect r_vol;
    sfIntRect r_change_vol;
    sfIntRect r_return;
    sfVector2f p_opt;
    sfVector2f p_vol;
    sfVector2f p_change_vol;
    sfVector2f p_return;
    int status_vol;
} opt_t;

typedef struct menu
{
    sfTexture *t_menu;
    sfTexture *t_butt;
    sfSprite *s_menu;
    sfSprite **s_butt;
    sfIntRect r_menu;
    sfIntRect *r_butt;
    sfVector2f p_menu;
    sfVector2f *p_butt;
} menu_t;

typedef struct back
{
    sfTexture *t_back;
    sfTexture *t_back2;
    sfTexture *t_back3;
    sfTexture *t_end;
    sfSprite *s_back;
    sfSprite *s_end;
    sfVector2f p_back;
    sfVector2f p_end;
    sfIntRect r_end;
    sfIntRect r_back;
    sfClock *c_back;
    sfTime time_back;
    float sec_back;
    float *cond_back2;
    int i_back;
} back_t;

typedef struct enm
{
    sfTexture *t_enm;
    sfSprite **s_enm;
    sfVector2f *p_enm;
    sfIntRect *r_enm;
    sfClock **c_enm;
    sfTime *time_enm;
    float *sec_enm;
    sfClock **c_move;
    sfTime *time_move;
    float *sec_move;
    sfVector2f *mv_enm;
    int enm_dead;
    sfFont *font;
    sfText *txt_score;
    sfVector2f p_score;
    int score;
    char *pseudo;
} enm_t;

typedef struct game
{
    sfRenderWindow *wdw;
    sfMusic *music;
    menu_t menu;
    enm_t enm;
    back_t back;
    opt_t opt;
    ldb_t ldb;
    int status;
    int life;
} game_t;

int my_hunter(game_t *game);
int my_strcmp(char const *s1, char const *s2);
bool init_struct(game_t *game);
bool clock_back(game_t *game);
void clock_enm(game_t *game);
void init_new_enm(game_t *game, int i);
void loop_game(game_t *game);
bool create_enm(enm_t *enm);
bool create_back(back_t *back);
void loop_menu(game_t *game);
bool create_menu(menu_t *menu);
void anim_enm(game_t *game, int i);
void my_events_menu(game_t *game, sfEvent event);
void move_enm(game_t *game, int i);
void destroy_struct(game_t *game);
void create_opt(opt_t *opt);
void loop_opt(game_t *game);
void my_events_opt(game_t *game, sfEvent event);
int print_descr(char *exe);
void loop_ldb(game_t *game);
bool create_ldb(ldb_t *ldb);
void my_events_opt3(game_t *game, sfEvent event, sfVector2i p_mouse);
char **get_from_file(char *file);
char *my_strdup(char const *str);
void loop_end(game_t *game);
char *get_score(char *str);
char *my_itoa(int nb);
int my_atoi(char *str);
void my_putstr(char *str);
void check_score(game_t *game);
char *my_strcpy(char const *src, char *dest);
int my_strlen(char const *str);
void get_name(char *str, sfText *text);
void put_in_file(char *file, char **tab);

#endif

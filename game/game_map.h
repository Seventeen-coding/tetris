#ifndef GAME_MAP_H
#define GAME_MAP_H

//这里只是作为一种操作流程的设计
//例如进入一个画面先 init 然后show 然后select等等
//具体是看游戏的操作模式

typedef  int (*m_handle)(void);
typedef  int (* m_init_handle)(void);
typedef  int (*m_show_handle)(void);
typedef  int (*m_select_handle)(char );

typedef struct game_map_t{
    m_handle                map_handle;
    m_init_handle       _init;
    m_show_handle   _show;
    m_select_handle  _select;


    struct game_map_t *callback_map;
    struct game_map_t *next_map;
}game_map_t;

int game_map_begin(game_map_t *map);
int game_map_end(game_map_t *map);
int game_map_run(game_map_t *map);

///int game_map_result();


#endif // GAME_MAP_H


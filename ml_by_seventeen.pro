TEMPLATE = app
CONFIG += console
CONFIG -= app_bundle
CONFIG -= qt

SOURCES += main.c \
    story/story.c \
    map/map.c \
    window/window.c \
    list/list.c \
    init_game.c \
    window/fight_window.c \
    data/fight_data.c \
    data/item_data.c \
    game/game.c \
    game/game_key.c \
    game/game_story.c \
    game/game_test.c \
    game/game_node.c \
    game/game_map.c \
    map/game_map_init.c \
    node/game_node_init.c \
    list/game_story_list_init.c \
    story/welcome/welcome_story.c \
    map/welcome/welcome_map.c \
    node/welcome/welcome_node.c \
    game/game_window.c \
    game/game_window_type.c \
    window/basic/select_list.c \
    window/basic/w_text.c \
    story/game_story_init.c


include(deployment.pri)
qtcAddDeployment()

HEADERS += \
    main.h \
    story/include/story.h \
    data/include/base_data.h \
    map/include/map.h \
    window/window.h \
    data/include/data.h \
    list/list.h \
    window/include/fight_window.h \
    data/include/fight_data.h \
    game/game.h \
    game/game_map.h \
    game/game_key.h \
    game/game_node.h \
    game/game_story.h \
    game/game_debug.h \
    game/game_test.h \
    game/game_test_module.h \
    test/game_test_demo_map.h \
    game/game_goble.h \
    node/welcome/map/welcome_map.h \
    node/welcome/welcome_private.h \
    node/welcome/welcome.h \
    node/welcome/map/welcome_movie_map.h \
    map/welcome/map/welcome_map.h \
    map/welcome/map/welcome_movie_map.h \
    map/game_map_config.h \
    map/game_map_init.h \
    story/include/game_story_config.h \
    story/include/game_story_init.h \
    node/game_node_config.h \
    node/game_node_init.h \
    list/game_story_list_init.h \
    list/game_story_list_config.h \
    story/welcome/welcome_story.h \
    story/game_story_config.h \
    story/game_story_init.h \
    game/game_list.h \
    node/welcome/welcome_node.h \
    map/welcome/welcome_map.h \
    game/game_window.h \
    window/welcome/welcome_window.h \
    game/game_window_type.h \
    window/basic/select_list.h \
    window/basic/w_list.h \
    window/basic/w_text.h

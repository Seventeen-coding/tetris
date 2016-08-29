TEMPLATE = app
CONFIG += console
CONFIG -= app_bundle
CONFIG -= qt

SOURCES += main.c \
    game/game.c \
    game/game_key.c \
    game/game_map.c \
    game/game_node.c \
    game/game_story.c \
    game/game_test.c \
    game/game_window.c \
    game/game_window_type.c \
    list/game_story_list_init.c \
    list/list.c \
    map/game_map_init.c \
    node/game_node_init.c \
    story/game_story_init.c \
    story/story.c \
    window/basic/select_list.c \
    window/basic/w_text.c \
    window/window.c \
    init_game.c \
    window/background.c \
    window/basic/w_item.c \
    window/basic/w_list.c \
    window/basic/w_map.c \
    window/template_window.c

include(deployment.pri)
qtcAddDeployment()

HEADERS += \
    game/game.h \
    game/game_debug.h \
    game/game_goble.h \
    game/game_key.h \
    game/game_list.h \
    game/game_map.h \
    game/game_node.h \
    game/game_story.h \
    game/game_test.h \
    game/game_test_module.h \
    game/game_window.h \
    game/game_window_type.h \
    list/game_story_list_config.h \
    list/game_story_list_init.h \
    list/list.h \
    map/game_map_config.h \
    map/game_map_init.h \
    node/game_node_config.h \
    node/game_node_init.h \
    story/include/story.h \
    story/game_story_config.h \
    story/game_story_init.h \
    test/game_test_demo_map.h \
    window/basic/select_list.h \
    window/basic/w_list.h \
    window/basic/w_text.h \
    window/window.h \
    main.h \
    window/background.h \
    window/basic/w_item.h \
    window/basic/w_map.h \
    window/template.h \
    window/template_window.h


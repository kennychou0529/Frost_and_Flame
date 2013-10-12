/**
 * Copyright (C) 2011-2013 Paul Wortmann, PhysHex Games, www.physhexgames.co.nr
 * This file is part of "Frost And Flame"
 *
 * "Frost And Flame" is free software: you can redistribute it and/or modify
 * it under the terms of the GNU General Public License as published by
 * the Free Software Foundation, either version 3 of the License, or
 * (at your option) any later version.
 *
 * "Frost And Flame" is distributed in the hope that it will be useful,
 * but WITHOUT ANY WARRANTY; without even the implied warranty of
 * MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the
 * GNU General Public License for more details.
 *
 * You should have received a copy of the GNU General Public License
 * along with "Frost And Flame" If not, see <http://www.gnu.org/licenses/>.
 *
 * @author  Paul Wortmann
 * @email   physhex@gmail.com
 * @website www.physhexgames.co.nr
 * @license GPL V3
 * @date 2011-11-11
 */

#include "../core/map_2D.hpp"
#include "game.hpp"

game_class        game;
tmx_map_type      tmx_map;

game_class::game_class(void)
{
    game_class::event = 0;
    game_class::state = STATE_MENU;
};

void game_class::init(void)
{
    game.loading_screen.display("data/loading_screen.png");
    game_class::debug = false;
    glDisable(GL_DEPTH_TEST);
    //--- initial state of the background ---
    game.core.background.set_data ( 1, 1, 0, 0.0f, 0.0f, 0.0000f, 0.00000f, "data/textures/UI/backgrounds/background_01.png");
    game.core.background.set_data ( 2, 1, 0, 0.0f, 0.0f, 0.0000f, 0.00000f, "data/textures/UI/backgrounds/background_01.png");
    game.core.background.set_data ( 3, 1, 0, 0.0f, 0.0f, 0.0010f, 0.00065f, "data/textures/UI/backgrounds/background_03.png");
    game.core.background.set_data ( 4, 1, 0, 4.0f, 0.0f, 0.0010f, 0.00065f, "data/textures/UI/backgrounds/background_03.png");
    game.core.background.set_data ( 5, 1, 0, 0.0f, 0.0f, 0.0040f, 0.00075f, "data/textures/UI/backgrounds/background_03.png");
    game.core.background.set_data ( 6, 1, 0, 4.0f, 0.0f, 0.0040f, 0.00075f, "data/textures/UI/backgrounds/background_03.png");
    game.core.background.set_movement_type(FRONT_SCROLL);
    //--- other ---

    //game.model_3D.tree_palm.save("test_palm.obj");
    game.global_ambient.intensity_R               = 8.0f;
    game.global_ambient.intensity_G               = 8.0f;
    game.global_ambient.intensity_B               = 8.0f;
    game.global_ambient.intensity_A               = 8.0f;
    game.world_ambient.intensity_R                = 2.0f;
    game.world_ambient.intensity_G                = 2.0f;
    game.world_ambient.intensity_B                = 2.0f;
    game.world_ambient.intensity_A                = 2.0f;
    game.world_ambient.increase                   = true;
    game.world_ambient.speed                      = 0.0125f;
    game.zoom.current                             = TILE_SCALE_DEFAULT;
    game.zoom.min                                 = 80.0f;
    game.zoom.max                                 = 400.0f;
    game.zoom.speed                               = 200.5f;

    game.core.game_paused                         = false;
    game.core.game_active                         = false;
    game.core.game_resume                         = false;
    game.core.quest_log_active                    = false;
    game.core.character_active                    = false;
    game.core.skillbook_active                    = false;
    game.core.inventory_active                    = false;
    game.core.npcvendor_active                    = false;

    game.player.name                              =  "Kanchi";
    game.player.level.current                     =  0;
    game.player.level.base                        =  2;
    game.player.level.multiplier                  =  1.52f;
    game.player.level.init();
    game.player.level.current_experience          =  2; // 0 for norm
    game.player.health.current                    =  000.0f;
    game.player.health.maximum                    =  100.0f;
    game.player.health.regeneration               =  000.015f;
    game.player.mana.current                      =  000.0f;
    game.player.mana.maximum                      =  100.0f;
    game.player.mana.regeneration                 =  000.025f;

    game.player.destination_tile                  =  0;
    game.player.destination_set                   =  false;
    game.player.path_set                          =  false;
    game.player.movement_type                     =  MOVE_TO_TILE_NONE;

    //--- other ---
    game.music_manager.next_track = true;
    game.effect.init_effects();
    game.item.init_items();
    init_spells();


    //zoom out for testing
    game.zoom.current = game.zoom.max;
    tmx_load(&tmx_map,"data/maps/town.tmx");
    game.map_2D.calculate_tile_positions(&tmx_map,DEFAULT_FRAME_WIDTH/game.zoom.current/2.0f,DEFAULT_FRAME_HEIGHT/game.zoom.current/2.0f);
    game.map_2D.center_on_tile(&tmx_map,(tmx_map.data.number_of_tiles/2)+(tmx_map.data.map_width/2));

    // Add default items to the inventory
    UI_form_struct* UI_form_pointer;
    item_type*      temp_item_pointer;// = new item_type;
    int             element_number    = 1;
    UI_form_pointer   = game.UI_manager.UI_form_get(UID_INVENTORY);
    temp_item_pointer = game.item_manager.add_item(ITEM_HEALTH_POTION);
    UI_form_pointer->data.element[element_number].value          = temp_item_pointer->data.UID;
    UI_form_pointer->data.element[element_number].quantity       = 4;
    UI_form_pointer->data.element[element_number].texture.normal = temp_item_pointer->data.image;
    element_number    = 2;
    temp_item_pointer = game.item_manager.add_item(ITEM_MANA_POTION);
    UI_form_pointer->data.element[element_number].value          = temp_item_pointer->data.UID;
    UI_form_pointer->data.element[element_number].quantity       = 3;
    UI_form_pointer->data.element[element_number].texture.normal = temp_item_pointer->data.image;
    element_number    = 3;
    temp_item_pointer = game.item_manager.add_item(ITEM_REJUVENATION_POTION);
    UI_form_pointer->data.element[element_number].value          = temp_item_pointer->data.UID;
    UI_form_pointer->data.element[element_number].quantity       = 2;
    UI_form_pointer->data.element[element_number].texture.normal = temp_item_pointer->data.image;
    element_number    = 4;
    temp_item_pointer = game.item_manager.add_item(101);
    UI_form_pointer->data.element[element_number].value          = temp_item_pointer->data.UID;
    UI_form_pointer->data.element[element_number].quantity       = 2;
    UI_form_pointer->data.element[element_number].texture.normal = temp_item_pointer->data.image;
    element_number    = 5;
    temp_item_pointer = game.item_manager.add_item(game.item_manager.gen_item(ITEM_RING,ITEM_RING,100));
    UI_form_pointer->data.element[element_number].value          = temp_item_pointer->data.UID;
    UI_form_pointer->data.element[element_number].quantity       = 1;
    UI_form_pointer->data.element[element_number].texture.normal = temp_item_pointer->data.image;


    /*

    element_number = 2;
    item_ID = game.item_manager.get_item_ID(MANA_POTION); // Mana Potion
    UI_form_pointer->data.element[element_number].value = item_ID;
    UI_form_pointer->data.element[element_number].quantity = 4;
    UI_form_pointer->data.element[element_number].texture.normal = game.item_manager.item[item_ID].image;

    // Add default items to the action bar
    UI_form_pointer = game.UI_manager.UI_form_get(UID_ACTIONBAR);
    element_number = 16;
    item_ID = game.item_manager.get_item_ID(ITEM_SPELL); // ----
    UI_form_pointer->data.element[element_number].value    = item_ID;
    UI_form_pointer->data.element[element_number].quantity = 1;
    UI_form_pointer->data.element[element_number].texture.normal = game.item_manager.item[item_ID].image;
    element_number = 17;
    item_ID = game.item_manager.get_item_ID(ITEM_SPELL); // ----
    UI_form_pointer->data.element[element_number].value    = item_ID;
    UI_form_pointer->data.element[element_number].quantity = 1;
    UI_form_pointer->data.element[element_number].texture.normal = game.item_manager.item[item_ID].image;

    // Add default items to the equipment menu
    UI_form_pointer = game.UI_manager.UI_form_get(UID_EQUIPMENT);
    element_number = 13;
    item_ID = 0;
    item_ID = game.item_manager.get_item_ID(ITEM_SPELL); // ----
    UI_form_pointer->data.element[element_number].value    = item_ID;
    UI_form_pointer->data.element[element_number].quantity = 1;
    UI_form_pointer->data.element[element_number].texture.normal = game.item_manager.item[item_ID].image;
    */
};

void game_class::process(void)
{
    path_type* path;
    /*
    game.test_1 = game.UI_manager.mouse_over_window();
    if (game.test_1 != MOUSE_OVER_MAP)
    {
        game.test_2 = game.UI_manager.mouse_over_element(game.test_1);
    }
    else game.test_2 = 0;
        */
    game.player.process();
    game.npc.process();
    game.map_2D.process(&tmx_map);
    game.core.game_resume = true;
    if (game.music_manager.next_track)
    {
        game.music_manager.next_track = false;
        //if (game.core.music_track ==  0) game.resource.music.menu_00.play();
    }
    /*
    if (game.core.io.mouse_wheel != 0)
    {
        if (game.core.io.mouse_wheel < 0)
        {
            while (game.core.io.mouse_wheel < 0)
            {
                game.core.io.mouse_wheel++;
                game.zoom.current += game.zoom.speed;
            }
            if (game.zoom.current > game.zoom.max) game.zoom.current = game.zoom.max;
            else
            {
                //game.resource.map_2D.tile[0].pos_y -= (DEFAULT_FRAME_HEIGHT/game.zoom.current/2.0f);
                //game.resource.map_2D.calculate_tile_positions(DEFAULT_FRAME_WIDTH/game.zoom.current/2.0f,DEFAULT_FRAME_HEIGHT/game.zoom.current/2.0f);
            }
        }
        if (game.core.io.mouse_wheel > 0)
        {
            while (game.core.io.mouse_wheel > 0)
            {
                game.core.io.mouse_wheel--;
                game.zoom.current -= game.zoom.speed;
            }
            if (game.zoom.current < game.zoom.min) game.zoom.current = game.zoom.min;
            else
            {
                //game.resource.map_2D.tile[0].pos_y += (DEFAULT_FRAME_HEIGHT/game.zoom.current/2.0f);
                //game.resource.map_2D.calculate_tile_positions(DEFAULT_FRAME_WIDTH/game.zoom.current/2.0f,DEFAULT_FRAME_HEIGHT/game.zoom.current/2.0f);
            }
        }
    }
    */
    if (game.core.io.keyboard_ready)
    {
        if (game.core.io.key_escape) // Main menu
        {
            game.UI_manager.UI_form_disable(UID_MENU_GAME_LOAD);
            game.UI_manager.UI_form_disable(UID_MENU_GAME_NEW);
            game.UI_manager.UI_form_disable(UID_MENU_GAME_SAVE);
            game.UI_manager.UI_form_disable(UID_MENU_OPTIONS);
            if (!game.core.game_menu_active)
            {
                game.UI_manager.UI_form_enable(UID_MENU_MAIN);
                game.UI_manager.data.event.id    = EVENT_UI_LIST_SORT;
                game.UI_manager.data.event.value = UID_MENU_MAIN;
                game.core.game_menu_active                   = true;
            }
            else
            {
                game.UI_manager.UI_form_disable(UID_MENU_MAIN);
                game.core.game_menu_active                   = false;
            }
            game.core.io.key_escape                = false;
            game.core.io.keyboard_delay_count      = 0;
        }
        if (game.core.io.key_c) // Character menu
        {
            if (!game.core.character_active)
            {
                game.UI_manager.UI_form_enable(UID_CHARACTER);
                game.UI_manager.data.event.id    = EVENT_UI_LIST_SORT;
                game.UI_manager.data.event.value = UID_CHARACTER;
                game.core.character_active                   = true;
            }
            else
            {
                game.UI_manager.UI_form_disable(UID_CHARACTER);
                game.core.character_active                   = false;
            }
            game.core.io.key_c                     = false;
            game.core.io.keyboard_delay_count      = 0;
        }
        if (game.core.io.key_e) // Equipment menu
        {
            if (!game.core.equipment_active)
            {
                game.UI_manager.UI_form_enable(UID_EQUIPMENT);
                game.UI_manager.data.event.id    = EVENT_UI_LIST_SORT;
                game.UI_manager.data.event.value = UID_EQUIPMENT;
                game.core.equipment_active                   = true;
            }
            else
            {
                game.UI_manager.UI_form_disable(UID_EQUIPMENT);
                game.core.equipment_active                   = false;
            }
            game.core.io.key_e                     = false;
            game.core.io.keyboard_delay_count      = 0;
        }
        if (game.core.io.key_q) // Quest log menu
        {
            if (!game.core.quest_log_active)
            {
                game.UI_manager.UI_form_enable(UID_QUEST_LOG);
                game.UI_manager.data.event.id    = EVENT_UI_LIST_SORT;
                game.UI_manager.data.event.value = UID_QUEST_LOG;
                game.core.quest_log_active                   = true;
            }
            else
            {
                game.UI_manager.UI_form_disable(UID_QUEST_LOG);
                game.core.quest_log_active                   = false;
            }
            game.core.io.key_q                     = false;
            game.core.io.keyboard_delay_count      = 0;
        }
        if (game.core.io.key_i) // Inventory menu
        {
            if (!game.core.inventory_active)
            {
                game.UI_manager.UI_form_enable(UID_INVENTORY);
                game.UI_manager.data.event.id    = EVENT_UI_LIST_SORT;
                game.UI_manager.data.event.value = UID_INVENTORY;
                game.core.inventory_active                   = true;
            }
            else
            {
                game.UI_manager.UI_form_disable(UID_INVENTORY);
                game.core.inventory_active                   = false;
            }
            game.core.io.key_i                     = false;
            game.core.io.keyboard_delay_count      = 0;
        }
        if (game.core.io.key_b) // Skill book menu
        {
            if (!game.core.skillbook_active)
            {
                game.UI_manager.UI_form_enable(UID_SKILLBOOK);
                game.UI_manager.data.event.id    = EVENT_UI_LIST_SORT;
                game.UI_manager.data.event.value = UID_SKILLBOOK;
                game.core.skillbook_active                   = true;
            }
            else
            {
                game.UI_manager.UI_form_disable(UID_SKILLBOOK);
                game.core.skillbook_active                   = false;
            }
            game.core.io.key_b                     = false;
            game.core.io.keyboard_delay_count      = 0;
        }
        if (game.core.io.key_space) // close all open windows
        {
            if (game.core.game_menu_active)
            {
                game.UI_manager.UI_form_disable(UID_MENU_MAIN);
                game.UI_manager.UI_form_disable(UID_MENU_GAME_LOAD);
                game.UI_manager.UI_form_disable(UID_MENU_GAME_NEW);
                game.UI_manager.UI_form_disable(UID_MENU_GAME_SAVE);
                game.UI_manager.UI_form_disable(UID_MENU_OPTIONS);
                game.core.game_menu_active                   = false;
            }
            if (game.core.equipment_active)
            {
                game.UI_manager.UI_form_disable(UID_EQUIPMENT);
                game.core.equipment_active                   = false;
            }
            if (game.core.quest_log_active)
            {
                game.UI_manager.UI_form_disable(UID_QUEST_LOG);
                game.core.quest_log_active                   = false;
            }
            if (game.core.character_active)
            {
                game.UI_manager.UI_form_disable(UID_CHARACTER);
                game.core.character_active                   = false;
            }
            if (game.core.inventory_active)
            {
                game.UI_manager.UI_form_disable(UID_INVENTORY);
                game.core.inventory_active                   = false;
            }
            if (game.core.skillbook_active)
            {
                game.UI_manager.UI_form_disable(UID_SKILLBOOK);
                game.core.skillbook_active                   = false;
            }
            if (game.core.npcvendor_active)
            {
                game.UI_manager.UI_form_disable(UID_NPCVENDOR);
                game.core.npcvendor_active                   = false;
            }
            game.core.io.key_space                 = false;
            game.core.io.keyboard_delay_count      = 0;
        }
        if (game.core.io.key_alt) // display item names on map (loot / click-able items)
        {
            game.core.io.key_alt                   = false;
            game.core.io.keyboard_delay_count      = 0;
        }
///------------------------------------------------------------------------------------------
        if (game.core.io.key_d) // toggle debug.
        {
            game.debug = !game.debug;
            game.core.io.key_d                     = false;
            game.core.io.keyboard_delay_count      = 0;
        }
        if (game.core.io.key_t) // test exp++
        {
            game.player.level.current_experience++;
            game.core.io.key_t                     = false;
            game.core.io.keyboard_delay_count      = 0;
        }
        if (game.core.io.key_1) // generate a random BSP dungeon
        {
            game.loading_screen.display("data/loading_screen.png");
            map_gen_BSP(&tmx_map);
            game.map_2D.smooth_map(&tmx_map);
            game.map_2D.apply_tileset(&tmx_map,DUNGEON);
            game.map_2D.calculate_tile_positions(&tmx_map,DEFAULT_FRAME_WIDTH/game.zoom.current/2.0f,DEFAULT_FRAME_HEIGHT/game.zoom.current/2.0f);
            game.map_2D.center_on_tile(&tmx_map,(tmx_map.data.number_of_tiles/2)+(tmx_map.data.map_width/2));
            game.core.io.key_1                     = false;
            game.core.io.keyboard_delay_count      = 0;
            path = map_path_find(&tmx_map,2,2,10,10);
        }
        if (game.core.io.key_2) // generate a random BSP dungeon
        {
            game.loading_screen.display("data/loading_screen.png");
            map_gen_BSP(&tmx_map);
            game.map_2D.smooth_map(&tmx_map);
            game.map_2D.apply_tileset(&tmx_map,CAVE);
            game.map_2D.calculate_tile_positions(&tmx_map,DEFAULT_FRAME_WIDTH/game.zoom.current/2.0f,DEFAULT_FRAME_HEIGHT/game.zoom.current/2.0f);
            game.map_2D.center_on_tile(&tmx_map,(tmx_map.data.number_of_tiles/2)+(tmx_map.data.map_width/2));
            game.core.io.key_2                     = false;
            game.core.io.keyboard_delay_count      = 0;
            path = map_path_find(&tmx_map,2,2,10,10);
        }
        if (game.core.io.key_3) // generate a random CA cave
        {
            game.loading_screen.display("data/loading_screen.png");
            map_gen_CA(&tmx_map);
            game.map_2D.smooth_map(&tmx_map);
            game.map_2D.apply_tileset(&tmx_map,CAVE);
            game.map_2D.calculate_tile_positions(&tmx_map,DEFAULT_FRAME_WIDTH/game.zoom.current/2.0f,DEFAULT_FRAME_HEIGHT/game.zoom.current/2.0f);
            game.map_2D.center_on_tile(&tmx_map,(tmx_map.data.number_of_tiles/2)+(tmx_map.data.map_width/2));
            game.core.io.key_3                     = false;
            game.core.io.keyboard_delay_count      = 0;
        }
        if (game.core.io.key_4) // generate a random CA grassland
        {
            game.loading_screen.display("data/loading_screen.png");
            map_gen_CA(&tmx_map);
            game.map_2D.smooth_map(&tmx_map);
            game.map_2D.apply_tileset(&tmx_map,GRASSLAND);
            game.map_2D.calculate_tile_positions(&tmx_map,DEFAULT_FRAME_WIDTH/game.zoom.current/2.0f,DEFAULT_FRAME_HEIGHT/game.zoom.current/2.0f);
            game.map_2D.center_on_tile(&tmx_map,(tmx_map.data.number_of_tiles/2)+(tmx_map.data.map_width/2));
            game.core.io.key_4                     = false;
            game.core.io.keyboard_delay_count      = 0;
        }
        if (game.core.io.key_5) // generate a random CA dungeon
        {
            game.loading_screen.display("data/loading_screen.png");
            map_gen_CA(&tmx_map);
            game.map_2D.smooth_map(&tmx_map);
            game.map_2D.apply_tileset(&tmx_map,DUNGEON);
            game.map_2D.calculate_tile_positions(&tmx_map,DEFAULT_FRAME_WIDTH/game.zoom.current/2.0f,DEFAULT_FRAME_HEIGHT/game.zoom.current/2.0f);
            game.map_2D.center_on_tile(&tmx_map,(tmx_map.data.number_of_tiles/2)+(tmx_map.data.map_width/2));
            game.core.io.key_4                     = false;
            game.core.io.keyboard_delay_count      = 0;
        }
    }
///------------------------------------------------------------------------------------------
};

void game_class::render(void)
{
    /*
    if (game.world_ambient.increase) // day / night lighting
    {
        game.world_ambient.intensity_R += game.world_ambient.speed;
        game.world_ambient.intensity_G += game.world_ambient.speed;
        game.world_ambient.intensity_B += game.world_ambient.speed;
        if (game.world_ambient.intensity_R > game.global_ambient.intensity_R) game.world_ambient.increase = false;
    }
    if (!game.world_ambient.increase)
    {
        game.world_ambient.intensity_R -= game.world_ambient.speed;
        game.world_ambient.intensity_G -= game.world_ambient.speed;
        game.world_ambient.intensity_B -= game.world_ambient.speed;
        if (game.world_ambient.intensity_R < -0.5f) game.world_ambient.increase = true;
    }
    */
    float  global_ambient_light[] = {game.global_ambient.intensity_R,game.global_ambient.intensity_G,game.global_ambient.intensity_B,game.global_ambient.intensity_A};
    float  world_ambient_light[]  = {game.world_ambient.intensity_R,game.world_ambient.intensity_G,game.world_ambient.intensity_B,game.world_ambient.intensity_A};
    glLightModelfv(GL_LIGHT_MODEL_AMBIENT,world_ambient_light);

    game.map_2D.render(&tmx_map);
    game.player.render();
    game.npc.render();

    glLightModelfv(GL_LIGHT_MODEL_AMBIENT,global_ambient_light);
    game.UI_manager.render();
};

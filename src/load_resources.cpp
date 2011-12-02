/**
 * Copyright (C) 2011 Paul Wortmann, PhysHex Games, www.physhexgames.co.nr
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

#include <SDL/SDL.h>
#include "load_resources.hpp"
#include "game.hpp"

extern game_type         game;

bool load_resources(void)
{
    load_sounds();
    load_music();
    load_textures();
    load_fonts();
    load_maps();
    return(true);
};

bool load_maps(void)
{
    int map_count = 0;
    game.map.town.load      ("data/maps/town.tmx")   ;map_count++;

    game.core.log.File_Write("Map files loaded -> ",map_count);
    return(true);
};

bool load_sounds(void)
{
    int sfx_count = 0;
    game.sound.menu_move_00.load    ("data/sound/menu_move_00.wav",sfx_count)    ;sfx_count++;
    game.sound.menu_select_00.load  ("data/sound/menu_select_00.wav",sfx_count)  ;sfx_count++;

    game.core.log.File_Write("Sound files loaded -> ",sfx_count);
    return(true);
};

bool load_music(void)
{
    int music_count = 0;
    game.music.menu_00.load("data/music/menu_00.s3m",music_count);music_count++;

    game.core.log.File_Write("Music files loaded -> ",music_count);
    return(true);
};

bool load_textures(void)
{
    int texture_count = 0;
    game.texture.background_00.load_image("data/textures/menu/background_00.png",texture_count);texture_count++;
    game.texture.background_01.load_image("data/textures/menu/background_01.png",texture_count);texture_count++;
    game.texture.background_02.load_image("data/textures/menu/background_02.png",texture_count);texture_count++;
    game.texture.background_03.load_image("data/textures/menu/background_03.png",texture_count);texture_count++;

    game.texture.logo.load_image                     ("data/textures/menu/logo.png"                     ,texture_count);texture_count++;
    game.texture.button_normal.load_image            ("data/textures/menu/button_normal.png"            ,texture_count);texture_count++;
    game.texture.button_highlighted.load_image       ("data/textures/menu/button_highlighted.png"       ,texture_count);texture_count++;
    game.texture.button_disabled.load_image          ("data/textures/menu/button_disabled.png"          ,texture_count);texture_count++;
    game.texture.close_button.load_image             ("data/textures/menu/close_button.png"             ,texture_count);texture_count++;
    game.texture.close_button_highlighted.load_image ("data/textures/menu/close_button_highlighted.png" ,texture_count);texture_count++;
    game.texture.selection_box.load_image            ("data/textures/menu/selection_box.png"            ,texture_count);texture_count++;
    game.texture.arrow_button_normal.load_image      ("data/textures/menu/arrow_normal.png"             ,texture_count);texture_count++;
    game.texture.arrow_button_highlighted.load_image ("data/textures/menu/arrow_highlighted.png"        ,texture_count);texture_count++;
    game.texture.arrow_button_disabled.load_image    ("data/textures/menu/arrow_disabled.png"           ,texture_count);texture_count++;
    game.texture.slider_button_normal.load_image     ("data/textures/menu/slider_normal.png"            ,texture_count);texture_count++;
    game.texture.slider_button_highlighted.load_image("data/textures/menu/slider_highlighted.png"       ,texture_count);texture_count++;
    game.texture.red_button.load_image               ("data/textures/menu/red_button.png"               ,texture_count);texture_count++;
    game.texture.red_button_highlighted.load_image   ("data/textures/menu/red_button_highlighted.png"   ,texture_count);texture_count++;
    game.texture.green_button.load_image             ("data/textures/menu/green_button.png"             ,texture_count);texture_count++;
    game.texture.green_button_highlighted.load_image ("data/textures/menu/green_button_highlighted.png" ,texture_count);texture_count++;
    game.texture.blue_button.load_image              ("data/textures/menu/blue_button.png"              ,texture_count);texture_count++;
    game.texture.blue_button_highlighted.load_image  ("data/textures/menu/blue_button_highlighted.png"  ,texture_count);texture_count++;
    game.texture.resolution_icon.load_image          ("data/textures/menu/resolution_icon.png"          ,texture_count);texture_count++;

    game.texture.cursor.load_image              ("data/textures/UI/cursor.png"                          ,texture_count);texture_count++;
    game.texture.action_bar.load_image          ("data/textures/UI/action_bar/action_bar.png"           ,texture_count);texture_count++;
    game.texture.action_bar_front.load_image    ("data/textures/UI/action_bar/action_bar_front.png"     ,texture_count);texture_count++;
    game.texture.glass_cover_01.load_image      ("data/textures/UI/action_bar/glass_cover_01.png"       ,texture_count);texture_count++;
    game.texture.glass_cover_02.load_image      ("data/textures/UI/action_bar/glass_cover_02.png"       ,texture_count);texture_count++;
    game.texture.icon_01.load_image             ("data/textures/UI/action_bar/icon_01.png"              ,texture_count);texture_count++;
    game.texture.icon_02.load_image             ("data/textures/UI/action_bar/icon_02.png"              ,texture_count);texture_count++;
    game.texture.icon_03.load_image             ("data/textures/UI/action_bar/icon_03.png"              ,texture_count);texture_count++;
    game.texture.icon_04.load_image             ("data/textures/UI/action_bar/icon_04.png"              ,texture_count);texture_count++;
    game.texture.icon_05.load_image             ("data/textures/UI/action_bar/icon_05.png"              ,texture_count);texture_count++;
    game.texture.icon_06.load_image             ("data/textures/UI/action_bar/icon_06.png"              ,texture_count);texture_count++;
    game.texture.icon_melee.load_image          ("data/textures/UI/action_bar/icon_melee.png"           ,texture_count);texture_count++;

    game.texture.health_bar.load_image              ("data/textures/UI/portrait/health_bar.png"               ,texture_count);texture_count++;
    game.texture.mana_bar.load_image                ("data/textures/UI/portrait/mana_bar.png"                 ,texture_count);texture_count++;
    game.texture.profile_background.load_image      ("data/textures/UI/portrait/profile_background.png"       ,texture_count);texture_count++;
    game.texture.profile_main.load_image            ("data/textures/UI/portrait/profile_main.png"             ,texture_count);texture_count++;
    game.texture.profile_main_background.load_image ("data/textures/UI/portrait/profile_main_background.png"  ,texture_count);texture_count++;

    game.texture.spell_book.load_image              ("data/textures/UI/spell_book/spell_book.png"             ,texture_count);texture_count++;
    game.texture.spell_book_spell_cover.load_image  ("data/textures/UI/spell_book/spell_book_spell_cover.png" ,texture_count);texture_count++;
    game.texture.spell_book_background.load_image   ("data/textures/UI/spell_book/spell_book_background.png"  ,texture_count);texture_count++;
    game.texture.inventory.load_image               ("data/textures/UI/inventory/inventory.png"               ,texture_count);texture_count++;
    game.texture.character_background.load_image    ("data/textures/UI/character/character_background.png"    ,texture_count);texture_count++;
    game.texture.quest_log_background.load_image    ("data/textures/UI/quest_log/quest_log_background.png"    ,texture_count);texture_count++;

    game.texture.particle_000.load_image("data/textures/particles/particle_000.png",texture_count);texture_count++;
    game.texture.particle_001.load_image("data/textures/particles/particle_001.png",texture_count);texture_count++;
    game.texture.particle_002.load_image("data/textures/particles/particle_002.png",texture_count);texture_count++;
    game.texture.particle_003.load_image("data/textures/particles/particle_003.png",texture_count);texture_count++;
    game.texture.particle_004.load_image("data/textures/particles/particle_004.png",texture_count);texture_count++;
    game.texture.particle_005.load_image("data/textures/particles/particle_005.png",texture_count);texture_count++;
    game.texture.particle_006.load_image("data/textures/particles/particle_006.png",texture_count);texture_count++;
    game.texture.particle_007.load_image("data/textures/particles/particle_007.png",texture_count);texture_count++;
    game.texture.particle_008.load_image("data/textures/particles/particle_008.png",texture_count);texture_count++;
    game.texture.particle_009.load_image("data/textures/particles/particle_009.png",texture_count);texture_count++;
    game.texture.particle_010.load_image("data/textures/particles/particle_010.png",texture_count);texture_count++;
    game.texture.particle_011.load_image("data/textures/particles/particle_011.png",texture_count);texture_count++;
    game.texture.particle_012.load_image("data/textures/particles/particle_012.png",texture_count);texture_count++;
    game.texture.particle_013.load_image("data/textures/particles/particle_013.png",texture_count);texture_count++;
    game.texture.particle_014.load_image("data/textures/particles/particle_014.png",texture_count);texture_count++;
    game.texture.particle_015.load_image("data/textures/particles/particle_015.png",texture_count);texture_count++;

    game.texture.spell_01_level_01.load_image("data/textures/UI/icons/spells/ice-blue-1.png",texture_count);texture_count++;
    game.texture.spell_01_level_02.load_image("data/textures/UI/icons/spells/ice-blue-2.png",texture_count);texture_count++;
    game.texture.spell_01_level_03.load_image("data/textures/UI/icons/spells/ice-blue-3.png",texture_count);texture_count++;
    game.texture.spell_02_level_01.load_image("data/textures/UI/icons/spells/air-burst-sky-1.png",texture_count);texture_count++;
    game.texture.spell_02_level_02.load_image("data/textures/UI/icons/spells/air-burst-sky-2.png",texture_count);texture_count++;
    game.texture.spell_02_level_03.load_image("data/textures/UI/icons/spells/air-burst-sky-3.png",texture_count);texture_count++;
    game.texture.spell_03_level_01.load_image("data/textures/UI/icons/spells/beam-red-1.png",texture_count);texture_count++;
    game.texture.spell_03_level_02.load_image("data/textures/UI/icons/spells/beam-red-2.png",texture_count);texture_count++;
    game.texture.spell_03_level_03.load_image("data/textures/UI/icons/spells/beam-red-3.png",texture_count);texture_count++;
    game.texture.spell_04_level_01.load_image("data/textures/UI/icons/spells/fire-arrows-1.png",texture_count);texture_count++;
    game.texture.spell_04_level_02.load_image("data/textures/UI/icons/spells/fire-arrows-2.png",texture_count);texture_count++;
    game.texture.spell_04_level_03.load_image("data/textures/UI/icons/spells/fire-arrows-3.png",texture_count);texture_count++;
    game.texture.spell_05_level_01.load_image("data/textures/UI/icons/spells/fireball-red-1.png",texture_count);texture_count++;
    game.texture.spell_05_level_02.load_image("data/textures/UI/icons/spells/fireball-red-2.png",texture_count);texture_count++;
    game.texture.spell_05_level_03.load_image("data/textures/UI/icons/spells/fireball-red-3.png",texture_count);texture_count++;
    game.texture.spell_06_level_01.load_image("data/textures/UI/icons/spells/haste-royal-1.png",texture_count);texture_count++;
    game.texture.spell_06_level_02.load_image("data/textures/UI/icons/spells/haste-royal-2.png",texture_count);texture_count++;
    game.texture.spell_06_level_03.load_image("data/textures/UI/icons/spells/haste-royal-3.png",texture_count);texture_count++;
    game.texture.spell_07_level_01.load_image("data/textures/UI/icons/spells/heal-royal-1.png",texture_count);texture_count++;
    game.texture.spell_07_level_02.load_image("data/textures/UI/icons/spells/heal-royal-2.png",texture_count);texture_count++;
    game.texture.spell_07_level_03.load_image("data/textures/UI/icons/spells/heal-royal-3.png",texture_count);texture_count++;
    game.texture.spell_08_level_01.load_image("data/textures/UI/icons/spells/horror-acid-1.png",texture_count);texture_count++;
    game.texture.spell_08_level_02.load_image("data/textures/UI/icons/spells/horror-acid-2.png",texture_count);texture_count++;
    game.texture.spell_08_level_03.load_image("data/textures/UI/icons/spells/horror-acid-3.png",texture_count);texture_count++;
    game.texture.spell_09_level_01.load_image("data/textures/UI/icons/spells/lightning-blue-1.png",texture_count);texture_count++;
    game.texture.spell_09_level_02.load_image("data/textures/UI/icons/spells/lightning-blue-2.png",texture_count);texture_count++;
    game.texture.spell_09_level_03.load_image("data/textures/UI/icons/spells/lightning-blue-3.png",texture_count);texture_count++;
    game.texture.spell_10_level_01.load_image("data/textures/UI/icons/spells/needles-fire-1.png",texture_count);texture_count++;
    game.texture.spell_10_level_02.load_image("data/textures/UI/icons/spells/needles-fire-2.png",texture_count);texture_count++;
    game.texture.spell_10_level_03.load_image("data/textures/UI/icons/spells/needles-fire-3.png",texture_count);texture_count++;
    game.texture.spell_11_level_01.load_image("data/textures/UI/icons/spells/protect-orange-1.png",texture_count);texture_count++;
    game.texture.spell_11_level_02.load_image("data/textures/UI/icons/spells/protect-orange-2.png",texture_count);texture_count++;
    game.texture.spell_11_level_03.load_image("data/textures/UI/icons/spells/protect-orange-3.png",texture_count);texture_count++;
    game.texture.spell_12_level_01.load_image("data/textures/UI/icons/spells/rock-orange-1.png",texture_count);texture_count++;
    game.texture.spell_12_level_02.load_image("data/textures/UI/icons/spells/rock-orange-2.png",texture_count);texture_count++;
    game.texture.spell_12_level_03.load_image("data/textures/UI/icons/spells/rock-orange-3.png",texture_count);texture_count++;
    game.texture.spell_13_level_01.load_image("data/textures/UI/icons/spells/runes-magenta-1.png",texture_count);texture_count++;
    game.texture.spell_13_level_02.load_image("data/textures/UI/icons/spells/runes-magenta-2.png",texture_count);texture_count++;
    game.texture.spell_13_level_03.load_image("data/textures/UI/icons/spells/runes-magenta-3.png",texture_count);texture_count++;
    game.texture.spell_14_level_01.load_image("data/textures/UI/icons/spells/wind-blue-1.png",texture_count);texture_count++;
    game.texture.spell_14_level_02.load_image("data/textures/UI/icons/spells/wind-blue-2.png",texture_count);texture_count++;
    game.texture.spell_14_level_03.load_image("data/textures/UI/icons/spells/wind-blue-3.png",texture_count);texture_count++;
    game.texture.spell_15_level_01.load_image("data/textures/UI/icons/spells/beam-blue-1.png",texture_count);texture_count++;
    game.texture.spell_15_level_02.load_image("data/textures/UI/icons/spells/beam-blue-2.png",texture_count);texture_count++;
    game.texture.spell_15_level_03.load_image("data/textures/UI/icons/spells/beam-blue-3.png",texture_count);texture_count++;

    game.texture.grass_and_water_tileset.load_spritesheet        ("data/tilesets/grass_and_water.png"     ,texture_count, 64, 64);texture_count++;
    game.texture.bridge_tileset.load_spritesheet                 ("data/tilesets/bridge.png"              ,texture_count, 64,148);texture_count++;
    game.texture.grassland_tileset.load_spritesheet              ("data/tilesets/grassland.png"           ,texture_count, 64,128);texture_count++;
    game.texture.grassland_water_tileset.load_spritesheet        ("data/tilesets/grassland_water.png"     ,texture_count, 64, 64);texture_count++;
    game.texture.grassland_trees_tileset.load_spritesheet        ("data/tilesets/grassland_trees.png"     ,texture_count,128,128);texture_count++;
    game.texture.grassland_structures_tileset.load_spritesheet   ("data/tilesets/grassland_structures.png",texture_count, 64,148);texture_count++;
    game.texture.broken_tower_tileset.load_spritesheet           ("data/tilesets/broken_tower.png"        ,texture_count, 64, 64);texture_count++;
    game.texture.fence_tileset.load_spritesheet                  ("data/tilesets/fence.png"               ,texture_count, 64, 64);texture_count++;
    game.texture.medieval_building_tileset.load_spritesheet      ("data/tilesets/medieval_building.png"   ,texture_count, 64,192);texture_count++;
    game.texture.cave_floor_tileset.load_spritesheet             ("data/tilesets/cave_floor.png"          ,texture_count, 64, 32);texture_count++;
    game.texture.cave_wall_tileset.load_spritesheet              ("data/tilesets/cave_wall.png"           ,texture_count, 64,128);texture_count++;
    game.texture.cave_object_tileset.load_spritesheet            ("data/tilesets/cave_object.png"         ,texture_count, 64,128);texture_count++;
    game.texture.dungeon_tileset.load_spritesheet                ("data/tilesets/dungeon.png"             ,texture_count, 64, 64);texture_count++;

    game.texture.spell_book_00.load_image("data/textures/UI/icons/books/book_00.png",texture_count);texture_count++;
    game.texture.spell_book_01.load_image("data/textures/UI/icons/books/book_01.png",texture_count);texture_count++;
    game.texture.spell_book_02.load_image("data/textures/UI/icons/books/book_02.png",texture_count);texture_count++;
    game.texture.spell_book_03.load_image("data/textures/UI/icons/books/book_03.png",texture_count);texture_count++;
    game.texture.spell_book_04.load_image("data/textures/UI/icons/books/book_04.png",texture_count);texture_count++;
    game.texture.spell_book_05.load_image("data/textures/UI/icons/books/book_05.png",texture_count);texture_count++;
    game.texture.spell_book_06.load_image("data/textures/UI/icons/books/book_06.png",texture_count);texture_count++;
    game.texture.spell_book_07.load_image("data/textures/UI/icons/books/book_07.png",texture_count);texture_count++;
    game.texture.spell_book_08.load_image("data/textures/UI/icons/books/book_08.png",texture_count);texture_count++;
    game.texture.spell_book_09.load_image("data/textures/UI/icons/books/book_09.png",texture_count);texture_count++;
    game.texture.spell_book_10.load_image("data/textures/UI/icons/books/book_10.png",texture_count);texture_count++;
    game.texture.spell_book_11.load_image("data/textures/UI/icons/books/book_11.png",texture_count);texture_count++;
    game.texture.spell_book_12.load_image("data/textures/UI/icons/books/book_12.png",texture_count);texture_count++;
    game.texture.spell_book_13.load_image("data/textures/UI/icons/books/book_13.png",texture_count);texture_count++;
    game.texture.spell_book_14.load_image("data/textures/UI/icons/books/book_14.png",texture_count);texture_count++;
    game.texture.spell_book_15.load_image("data/textures/UI/icons/books/book_15.png",texture_count);texture_count++;
    game.texture.spell_book_16.load_image("data/textures/UI/icons/books/book_16.png",texture_count);texture_count++;
    game.texture.spell_book_17.load_image("data/textures/UI/icons/books/book_17.png",texture_count);texture_count++;
    game.texture.spell_book_18.load_image("data/textures/UI/icons/books/book_18.png",texture_count);texture_count++;
    game.texture.spell_book_19.load_image("data/textures/UI/icons/books/book_19.png",texture_count);texture_count++;

    game.core.log.File_Write("Texture files loaded -> ",texture_count);
    return(true);
};

bool proc_textures(void)
{
    //used for sprite sheets
};

bool load_fonts(void)
{
    int font_count = 0;
    game.font.font_1.Set_File("data/fonts/font_001.ttf");font_count++;
    game.core.log.File_Write("Font files loaded -> ",font_count);
    return(true);
};

bool loading_screen_display(std::string file_name)
{
    glClear(GL_COLOR_BUFFER_BIT | GL_DEPTH_BUFFER_BIT);
    SDL_GL_SwapBuffers();
    texture_class loading_screen;
    loading_screen.load_image(file_name,0);
    loading_screen.draw(false,0.0f,0.0f,0.9f,2.0f,2.0f);
    SDL_GL_SwapBuffers();
    return(true);
};

bool draw_texture(bool r, int texture_number, float x, float y, float z, float w, float h)
{
    draw_texture(r,texture_number,x,y,z,w,h,0.0f,0);
};

bool draw_texture(bool r, int texture_number, float x, float y, float z, float w, float h, float angle)
{
    draw_texture(r,texture_number,x,y,z,w,h,angle,0);
};

bool draw_texture(bool r, int texture_number, float x, float y, float z, float w, float h, float angle, int frame)
{
    if (texture_number == game.texture.background_00.ref_number) game.texture.background_00.draw(r,x,y,z,w,h,angle,frame);
    if (texture_number == game.texture.background_01.ref_number) game.texture.background_01.draw(r,x,y,z,w,h,angle,frame);
    if (texture_number == game.texture.background_02.ref_number) game.texture.background_02.draw(r,x,y,z,w,h,angle,frame);
    if (texture_number == game.texture.background_03.ref_number) game.texture.background_03.draw(r,x,y,z,w,h,angle,frame);

    if (texture_number == game.texture.logo.ref_number)                      game.texture.logo.draw                     (r,x,y,z,w,h,angle,frame);
    if (texture_number == game.texture.button_normal.ref_number)             game.texture.button_normal.draw            (r,x,y,z,w,h,angle,frame);
    if (texture_number == game.texture.button_highlighted.ref_number)        game.texture.button_highlighted.draw       (r,x,y,z,w,h,angle,frame);
    if (texture_number == game.texture.button_disabled.ref_number)           game.texture.button_disabled.draw          (r,x,y,z,w,h,angle,frame);
    if (texture_number == game.texture.close_button.ref_number)              game.texture.close_button.draw             (r,x,y,z,w,h,angle,frame);
    if (texture_number == game.texture.close_button_highlighted.ref_number)  game.texture.close_button_highlighted.draw (r,x,y,z,w,h,angle,frame);
    if (texture_number == game.texture.selection_box.ref_number)             game.texture.selection_box.draw            (r,x,y,z,w,h,angle,frame);
    if (texture_number == game.texture.arrow_button_normal.ref_number)       game.texture.arrow_button_normal.draw      (r,x,y,z,w,h,angle,frame);
    if (texture_number == game.texture.arrow_button_highlighted.ref_number)  game.texture.arrow_button_highlighted.draw (r,x,y,z,w,h,angle,frame);
    if (texture_number == game.texture.arrow_button_disabled.ref_number)     game.texture.arrow_button_disabled.draw    (r,x,y,z,w,h,angle,frame);
    if (texture_number == game.texture.slider_button_normal.ref_number)      game.texture.slider_button_normal.draw     (r,x,y,z,w,h,angle,frame);
    if (texture_number == game.texture.slider_button_highlighted.ref_number) game.texture.slider_button_highlighted.draw(r,x,y,z,w,h,angle,frame);
    if (texture_number == game.texture.red_button.ref_number)                game.texture.red_button.draw               (r,x,y,z,w,h,angle,frame);
    if (texture_number == game.texture.red_button_highlighted.ref_number)    game.texture.red_button_highlighted.draw   (r,x,y,z,w,h,angle,frame);
    if (texture_number == game.texture.green_button.ref_number)              game.texture.green_button.draw             (r,x,y,z,w,h,angle,frame);
    if (texture_number == game.texture.green_button_highlighted.ref_number)  game.texture.green_button_highlighted.draw (r,x,y,z,w,h,angle,frame);
    if (texture_number == game.texture.blue_button.ref_number)               game.texture.blue_button.draw              (r,x,y,z,w,h,angle,frame);
    if (texture_number == game.texture.blue_button_highlighted.ref_number)   game.texture.blue_button_highlighted.draw  (r,x,y,z,w,h,angle,frame);
    if (texture_number == game.texture.resolution_icon.ref_number)           game.texture.resolution_icon.draw          (r,x,y,z,w,h,angle,frame);

    if (texture_number == game.texture.cursor.ref_number)                    game.texture.cursor.draw                   (r,x,y,z,w,h,angle,frame);
    if (texture_number == game.texture.action_bar.ref_number)                game.texture.action_bar.draw               (r,x,y,z,w,h,angle,frame);
    if (texture_number == game.texture.action_bar_front.ref_number)          game.texture.action_bar_front.draw         (r,x,y,z,w,h,angle,frame);
    if (texture_number == game.texture.glass_cover_01.ref_number)            game.texture.glass_cover_01.draw           (r,x,y,z,w,h,angle,frame);
    if (texture_number == game.texture.glass_cover_02.ref_number)            game.texture.glass_cover_02.draw           (r,x,y,z,w,h,angle,frame);
    if (texture_number == game.texture.icon_01.ref_number)                   game.texture.icon_01.draw                  (r,x,y,z,w,h,angle,frame);
    if (texture_number == game.texture.icon_02.ref_number)                   game.texture.icon_02.draw                  (r,x,y,z,w,h,angle,frame);
    if (texture_number == game.texture.icon_03.ref_number)                   game.texture.icon_03.draw                  (r,x,y,z,w,h,angle,frame);
    if (texture_number == game.texture.icon_04.ref_number)                   game.texture.icon_04.draw                  (r,x,y,z,w,h,angle,frame);
    if (texture_number == game.texture.icon_05.ref_number)                   game.texture.icon_05.draw                  (r,x,y,z,w,h,angle,frame);
    if (texture_number == game.texture.icon_06.ref_number)                   game.texture.icon_06.draw                  (r,x,y,z,w,h,angle,frame);
    if (texture_number == game.texture.icon_melee.ref_number)                game.texture.icon_melee.draw               (r,x,y,z,w,h,angle,frame);

    if (texture_number == game.texture.health_bar.ref_number)                game.texture.health_bar.draw               (r,x,y,z,w,h,angle,frame);
    if (texture_number == game.texture.mana_bar.ref_number)                  game.texture.mana_bar.draw                 (r,x,y,z,w,h,angle,frame);
    if (texture_number == game.texture.profile_background.ref_number)        game.texture.profile_background.draw       (r,x,y,z,w,h,angle,frame);
    if (texture_number == game.texture.profile_main.ref_number)              game.texture.profile_main.draw             (r,x,y,z,w,h,angle,frame);
    if (texture_number == game.texture.profile_main_background.ref_number)   game.texture.profile_main_background.draw  (r,x,y,z,w,h,angle,frame);

    if (texture_number == game.texture.spell_book.ref_number)                game.texture.spell_book.draw               (r,x,y,z,w,h,angle,frame);
    if (texture_number == game.texture.spell_book_spell_cover.ref_number)    game.texture.spell_book_spell_cover.draw   (r,x,y,z,w,h,angle,frame);
    if (texture_number == game.texture.spell_book_background.ref_number)     game.texture.spell_book_background.draw    (r,x,y,z,w,h,angle,frame);
    if (texture_number == game.texture.inventory.ref_number)                 game.texture.inventory.draw                (r,x,y,z,w,h,angle,frame);
    if (texture_number == game.texture.character_background.ref_number)      game.texture.character_background.draw     (r,x,y,z,w,h,angle,frame);
    if (texture_number == game.texture.quest_log_background.ref_number)      game.texture.quest_log_background.draw     (r,x,y,z,w,h,angle,frame);

    if (texture_number == game.texture.particle_000.ref_number) game.texture.particle_000.draw(r,x,y,z,w,h,angle,frame);
    if (texture_number == game.texture.particle_001.ref_number) game.texture.particle_001.draw(r,x,y,z,w,h,angle,frame);
    if (texture_number == game.texture.particle_002.ref_number) game.texture.particle_002.draw(r,x,y,z,w,h,angle,frame);
    if (texture_number == game.texture.particle_003.ref_number) game.texture.particle_003.draw(r,x,y,z,w,h,angle,frame);
    if (texture_number == game.texture.particle_004.ref_number) game.texture.particle_004.draw(r,x,y,z,w,h,angle,frame);
    if (texture_number == game.texture.particle_005.ref_number) game.texture.particle_005.draw(r,x,y,z,w,h,angle,frame);
    if (texture_number == game.texture.particle_006.ref_number) game.texture.particle_006.draw(r,x,y,z,w,h,angle,frame);
    if (texture_number == game.texture.particle_007.ref_number) game.texture.particle_007.draw(r,x,y,z,w,h,angle,frame);
    if (texture_number == game.texture.particle_008.ref_number) game.texture.particle_008.draw(r,x,y,z,w,h,angle,frame);
    if (texture_number == game.texture.particle_009.ref_number) game.texture.particle_009.draw(r,x,y,z,w,h,angle,frame);
    if (texture_number == game.texture.particle_010.ref_number) game.texture.particle_010.draw(r,x,y,z,w,h,angle,frame);
    if (texture_number == game.texture.particle_011.ref_number) game.texture.particle_011.draw(r,x,y,z,w,h,angle,frame);
    if (texture_number == game.texture.particle_012.ref_number) game.texture.particle_012.draw(r,x,y,z,w,h,angle,frame);
    if (texture_number == game.texture.particle_013.ref_number) game.texture.particle_013.draw(r,x,y,z,w,h,angle,frame);
    if (texture_number == game.texture.particle_014.ref_number) game.texture.particle_014.draw(r,x,y,z,w,h,angle,frame);
    if (texture_number == game.texture.particle_015.ref_number) game.texture.particle_015.draw(r,x,y,z,w,h,angle,frame);

    if (texture_number == game.texture.spell_01_level_01.ref_number) game.texture.spell_01_level_01.draw(r,x,y,z,w,h,angle,frame);
    if (texture_number == game.texture.spell_01_level_02.ref_number) game.texture.spell_01_level_02.draw(r,x,y,z,w,h,angle,frame);
    if (texture_number == game.texture.spell_01_level_03.ref_number) game.texture.spell_01_level_03.draw(r,x,y,z,w,h,angle,frame);
    if (texture_number == game.texture.spell_02_level_01.ref_number) game.texture.spell_02_level_01.draw(r,x,y,z,w,h,angle,frame);
    if (texture_number == game.texture.spell_02_level_02.ref_number) game.texture.spell_02_level_02.draw(r,x,y,z,w,h,angle,frame);
    if (texture_number == game.texture.spell_02_level_03.ref_number) game.texture.spell_02_level_03.draw(r,x,y,z,w,h,angle,frame);
    if (texture_number == game.texture.spell_03_level_01.ref_number) game.texture.spell_03_level_01.draw(r,x,y,z,w,h,angle,frame);
    if (texture_number == game.texture.spell_03_level_02.ref_number) game.texture.spell_03_level_02.draw(r,x,y,z,w,h,angle,frame);
    if (texture_number == game.texture.spell_03_level_03.ref_number) game.texture.spell_03_level_03.draw(r,x,y,z,w,h,angle,frame);
    if (texture_number == game.texture.spell_04_level_01.ref_number) game.texture.spell_04_level_01.draw(r,x,y,z,w,h,angle,frame);
    if (texture_number == game.texture.spell_04_level_02.ref_number) game.texture.spell_04_level_02.draw(r,x,y,z,w,h,angle,frame);
    if (texture_number == game.texture.spell_04_level_03.ref_number) game.texture.spell_04_level_03.draw(r,x,y,z,w,h,angle,frame);
    if (texture_number == game.texture.spell_05_level_01.ref_number) game.texture.spell_05_level_01.draw(r,x,y,z,w,h,angle,frame);
    if (texture_number == game.texture.spell_05_level_02.ref_number) game.texture.spell_05_level_02.draw(r,x,y,z,w,h,angle,frame);
    if (texture_number == game.texture.spell_05_level_03.ref_number) game.texture.spell_05_level_03.draw(r,x,y,z,w,h,angle,frame);
    if (texture_number == game.texture.spell_06_level_01.ref_number) game.texture.spell_06_level_01.draw(r,x,y,z,w,h,angle,frame);
    if (texture_number == game.texture.spell_06_level_02.ref_number) game.texture.spell_06_level_02.draw(r,x,y,z,w,h,angle,frame);
    if (texture_number == game.texture.spell_06_level_03.ref_number) game.texture.spell_06_level_03.draw(r,x,y,z,w,h,angle,frame);
    if (texture_number == game.texture.spell_07_level_01.ref_number) game.texture.spell_07_level_01.draw(r,x,y,z,w,h,angle,frame);
    if (texture_number == game.texture.spell_07_level_02.ref_number) game.texture.spell_07_level_02.draw(r,x,y,z,w,h,angle,frame);
    if (texture_number == game.texture.spell_07_level_03.ref_number) game.texture.spell_07_level_03.draw(r,x,y,z,w,h,angle,frame);
    if (texture_number == game.texture.spell_08_level_01.ref_number) game.texture.spell_08_level_01.draw(r,x,y,z,w,h,angle,frame);
    if (texture_number == game.texture.spell_08_level_02.ref_number) game.texture.spell_08_level_02.draw(r,x,y,z,w,h,angle,frame);
    if (texture_number == game.texture.spell_08_level_03.ref_number) game.texture.spell_08_level_03.draw(r,x,y,z,w,h,angle,frame);
    if (texture_number == game.texture.spell_09_level_01.ref_number) game.texture.spell_09_level_01.draw(r,x,y,z,w,h,angle,frame);
    if (texture_number == game.texture.spell_09_level_02.ref_number) game.texture.spell_09_level_02.draw(r,x,y,z,w,h,angle,frame);
    if (texture_number == game.texture.spell_09_level_03.ref_number) game.texture.spell_09_level_03.draw(r,x,y,z,w,h,angle,frame);
    if (texture_number == game.texture.spell_10_level_01.ref_number) game.texture.spell_10_level_01.draw(r,x,y,z,w,h,angle,frame);
    if (texture_number == game.texture.spell_10_level_02.ref_number) game.texture.spell_10_level_02.draw(r,x,y,z,w,h,angle,frame);
    if (texture_number == game.texture.spell_10_level_03.ref_number) game.texture.spell_10_level_03.draw(r,x,y,z,w,h,angle,frame);
    if (texture_number == game.texture.spell_11_level_01.ref_number) game.texture.spell_11_level_01.draw(r,x,y,z,w,h,angle,frame);
    if (texture_number == game.texture.spell_11_level_02.ref_number) game.texture.spell_11_level_02.draw(r,x,y,z,w,h,angle,frame);
    if (texture_number == game.texture.spell_11_level_03.ref_number) game.texture.spell_11_level_03.draw(r,x,y,z,w,h,angle,frame);
    if (texture_number == game.texture.spell_12_level_01.ref_number) game.texture.spell_12_level_01.draw(r,x,y,z,w,h,angle,frame);
    if (texture_number == game.texture.spell_12_level_02.ref_number) game.texture.spell_12_level_02.draw(r,x,y,z,w,h,angle,frame);
    if (texture_number == game.texture.spell_12_level_03.ref_number) game.texture.spell_12_level_03.draw(r,x,y,z,w,h,angle,frame);
    if (texture_number == game.texture.spell_13_level_01.ref_number) game.texture.spell_13_level_01.draw(r,x,y,z,w,h,angle,frame);
    if (texture_number == game.texture.spell_13_level_02.ref_number) game.texture.spell_13_level_02.draw(r,x,y,z,w,h,angle,frame);
    if (texture_number == game.texture.spell_13_level_03.ref_number) game.texture.spell_13_level_03.draw(r,x,y,z,w,h,angle,frame);
    if (texture_number == game.texture.spell_14_level_01.ref_number) game.texture.spell_14_level_01.draw(r,x,y,z,w,h,angle,frame);
    if (texture_number == game.texture.spell_14_level_02.ref_number) game.texture.spell_14_level_02.draw(r,x,y,z,w,h,angle,frame);
    if (texture_number == game.texture.spell_14_level_03.ref_number) game.texture.spell_14_level_03.draw(r,x,y,z,w,h,angle,frame);
    if (texture_number == game.texture.spell_15_level_01.ref_number) game.texture.spell_15_level_01.draw(r,x,y,z,w,h,angle,frame);
    if (texture_number == game.texture.spell_15_level_02.ref_number) game.texture.spell_15_level_02.draw(r,x,y,z,w,h,angle,frame);
    if (texture_number == game.texture.spell_15_level_03.ref_number) game.texture.spell_15_level_03.draw(r,x,y,z,w,h,angle,frame);

    if (texture_number == game.texture.grass_and_water_tileset.ref_number)         game.texture.grass_and_water_tileset.draw        (r,x,y,z,w,h,angle,frame);
    if (texture_number == game.texture.bridge_tileset.ref_number)                  game.texture.bridge_tileset.draw                 (r,x,y,z,w,h,angle,frame);
    if (texture_number == game.texture.grassland_tileset.ref_number)               game.texture.grassland_tileset.draw              (r,x,y,z,w,h,angle,frame);
    if (texture_number == game.texture.grassland_water_tileset.ref_number)         game.texture.grassland_water_tileset.draw        (r,x,y,z,w,h,angle,frame);
    if (texture_number == game.texture.grassland_trees_tileset.ref_number)         game.texture.grassland_trees_tileset.draw        (r,x,y,z,w,h,angle,frame);
    if (texture_number == game.texture.grassland_structures_tileset.ref_number)    game.texture.grassland_structures_tileset.draw   (r,x,y,z,w,h,angle,frame);
    if (texture_number == game.texture.broken_tower_tileset.ref_number)            game.texture.broken_tower_tileset.draw           (r,x,y,z,w,h,angle,frame);
    if (texture_number == game.texture.fence_tileset.ref_number)                   game.texture.fence_tileset.draw                  (r,x,y,z,w,h,angle,frame);
    if (texture_number == game.texture.medieval_building_tileset.ref_number)       game.texture.medieval_building_tileset.draw      (r,x,y,z,w,h,angle,frame);
    if (texture_number == game.texture.cave_floor_tileset.ref_number)              game.texture.cave_floor_tileset.draw             (r,x,y,z,w,h,angle,frame);
    if (texture_number == game.texture.cave_wall_tileset.ref_number)               game.texture.cave_wall_tileset.draw              (r,x,y,z,w,h,angle,frame);
    if (texture_number == game.texture.cave_object_tileset.ref_number)             game.texture.cave_object_tileset.draw            (r,x,y,z,w,h,angle,frame);
    if (texture_number == game.texture.dungeon_tileset.ref_number)                 game.texture.dungeon_tileset.draw                (r,x,y,z,w,h,angle,frame);

    if (texture_number == game.texture.spell_book_00.ref_number) game.texture.spell_book_00.draw(r,x,y,z,w,h,angle,frame);
    if (texture_number == game.texture.spell_book_01.ref_number) game.texture.spell_book_01.draw(r,x,y,z,w,h,angle,frame);
    if (texture_number == game.texture.spell_book_02.ref_number) game.texture.spell_book_02.draw(r,x,y,z,w,h,angle,frame);
    if (texture_number == game.texture.spell_book_03.ref_number) game.texture.spell_book_03.draw(r,x,y,z,w,h,angle,frame);
    if (texture_number == game.texture.spell_book_04.ref_number) game.texture.spell_book_04.draw(r,x,y,z,w,h,angle,frame);
    if (texture_number == game.texture.spell_book_05.ref_number) game.texture.spell_book_05.draw(r,x,y,z,w,h,angle,frame);
    if (texture_number == game.texture.spell_book_06.ref_number) game.texture.spell_book_06.draw(r,x,y,z,w,h,angle,frame);
    if (texture_number == game.texture.spell_book_07.ref_number) game.texture.spell_book_07.draw(r,x,y,z,w,h,angle,frame);
    if (texture_number == game.texture.spell_book_08.ref_number) game.texture.spell_book_08.draw(r,x,y,z,w,h,angle,frame);
    if (texture_number == game.texture.spell_book_09.ref_number) game.texture.spell_book_09.draw(r,x,y,z,w,h,angle,frame);
    if (texture_number == game.texture.spell_book_10.ref_number) game.texture.spell_book_10.draw(r,x,y,z,w,h,angle,frame);
    if (texture_number == game.texture.spell_book_11.ref_number) game.texture.spell_book_11.draw(r,x,y,z,w,h,angle,frame);
    if (texture_number == game.texture.spell_book_12.ref_number) game.texture.spell_book_12.draw(r,x,y,z,w,h,angle,frame);
    if (texture_number == game.texture.spell_book_13.ref_number) game.texture.spell_book_13.draw(r,x,y,z,w,h,angle,frame);
    if (texture_number == game.texture.spell_book_14.ref_number) game.texture.spell_book_14.draw(r,x,y,z,w,h,angle,frame);
    if (texture_number == game.texture.spell_book_15.ref_number) game.texture.spell_book_15.draw(r,x,y,z,w,h,angle,frame);
    if (texture_number == game.texture.spell_book_16.ref_number) game.texture.spell_book_16.draw(r,x,y,z,w,h,angle,frame);
    if (texture_number == game.texture.spell_book_17.ref_number) game.texture.spell_book_17.draw(r,x,y,z,w,h,angle,frame);
    if (texture_number == game.texture.spell_book_18.ref_number) game.texture.spell_book_18.draw(r,x,y,z,w,h,angle,frame);
    if (texture_number == game.texture.spell_book_19.ref_number) game.texture.spell_book_19.draw(r,x,y,z,w,h,angle,frame);

    return(true);
};





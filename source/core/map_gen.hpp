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

#ifndef MAP_GEN_HPP
#define MAP_GEN_HPP

#include <string>
#include "loader_fmx.hpp"
#include "types.hpp"

#define MAP_GEN_BSP                1
#define MAP_GEN_CA                 2
#define MAP_GEN_RC                 3
#define MAP_GEN_M1                 4

#define MAP_TILESET_DUNGEON        1
#define MAP_TILESET_CAVE           2
#define MAP_TILESET_GRASSLAND      3

#define MAX_ROOMS                  0 // 0 for unlimited number possible, should be an even number!
#define MAX_NODES                  8

#define LAYER_FLOOR                0
#define LAYER_OBJECT               1
#define LAYER_WALL                 2

#define TILE_NONE                 -1
#define TILE_FLOOR                 1
#define TILE_WALL                  2
#define TILE_EXIT                  3
#define TILE_DOOR                  4
#define TILE_PATH                  5
#define TILE_PATH_NO               6
#define TILE_ATTRIBUTE_HIDDEN_WALL 7
#define TILE_ATTRIBUTE_EXIT        8
#define TILE_ATTRIBUTE_DOOR        9
#define TILE_ATTRIBUTE_NONE        10
#define TILE_ATTRIBUTE_PROCESSED   11

#define ROOM_PATH                  2
#define ROOM_MIN_X                 7
#define ROOM_MIN_Y                 7
#define ROOM_MAX_X                 9
#define ROOM_MAX_Y                 9
#define ROOM_MAX_R                 (int)(sqrt(((ROOM_MAX_X/2) * (ROOM_MAX_X/2)) + ((ROOM_MAX_Y/2) * (ROOM_MAX_Y/2))) + ROOM_PATH)

struct flood_fill_type
{
    int  tile_data;
    bool processed;
    bool adjoining_tile;
};

struct room_data_type
{
    i2_type    size;
    i2_type    position;
};

struct map_type
{
    int            number_of_tiles;
    i2_type        size;
    fmx_tile_type *tile;
};

struct map_node_type
{
    bool           leaf;
    room_data_type room;
    map_type       data;
    map_node_type *left;
    map_node_type *right;
};

void           map_gen_base            (fmx_map_type *fmx_map_pointer);
void           map_gen                 (fmx_map_type *fmx_map_pointer, int generator_algorithm);
void           map_gen                 (fmx_map_type *fmx_map_pointer, int generator_algorithm, int tileset_type);
void           map_gen_BSP_split       (fmx_map_type *fmx_map_pointer, map_node_type *map_node);
void           map_gen_BSP             (fmx_map_type *fmx_map_pointer);
void           map_gen_BSP_internal    (fmx_map_type *fmx_map_pointer);
void           map_gen_BSP             (fmx_map_type *fmx_map_pointer, int seed);
void           map_gen_CA              (fmx_map_type *fmx_map_pointer);
void           map_gen_CA              (fmx_map_type *fmx_map_pointer, int seed);
void           map_gen_RC_internal     (fmx_map_type *fmx_map_pointer);
void           map_gen_RC              (fmx_map_type *fmx_map_pointer, int seed);
void           map_gen_RC              (fmx_map_type *fmx_map_pointer);
void           map_gen_M1              (fmx_map_type *fmx_map_pointer, int seed);
void           map_gen_M1              (fmx_map_type *fmx_map_pointer);
bool           map_gen_room            (fmx_map_type *fmx_map_pointer, room_data_type room, int number_of_exits);
int            map_gen_flood_fill_tile (fmx_map_type *fmx_map_pointer, flood_fill_type *fill_data, int tile_number);
bool           map_gen_room_flood_fill (fmx_map_type *fmx_map_pointer);
int            map_gen_room_check_path (fmx_map_type *fmx_map_pointer, int room_1, int room_2, bool x_then_y);
void           map_gen_room_path       (fmx_map_type *fmx_map_pointer, int room_1, int room_2, bool x_then_y);
void           map_gen_room_connect    (fmx_map_type *fmx_map_pointer);
room_data_type map_gen_room_find_stats (fmx_map_type *fmx_map_pointer, flood_fill_type *fill_data, int tile_number);
void           map_gen_room_find       (fmx_map_type *fmx_map_pointer);
int            map_gen_room_add        (fmx_map_type *fmx_map_pointer);
void           map_gen_room_collision  (fmx_map_type *fmx_map_pointer);
void           map_gen_check_tiles     (fmx_map_type *fmx_map_pointer);
void           map_gen_room_add_exits  (fmx_map_type *fmx_map_pointer);

#endif //MAP_GEN_HPP


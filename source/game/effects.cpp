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

#include "effects.hpp"
#include "game.hpp"

extern game_class game;

//----------------------------------------------------------------------------------------------------------------------------------------------------------
void  effect_class::init_effects(void) // Initialize hard-coded default effects, such as mod health etc...
{
    effect_type* effect_health_mod   = new effect_type;
    effect_health_mod                = game.effect_manager.add_effect(EFFECT_MOD_HEALTH);
    effect_health_mod->data.active   = true;
    effect_health_mod->data.name     = "Mod Player Health";
    effect_health_mod->data.passive  = false;
    effect_health_mod->data.value    = 10.0f;
    effect_health_mod->data.type     = ITEM_POTION;
    effect_health_mod->data.sub_type = ITEM_POTION_SMALL;
}

void  effect_class::use_effect(int effect_UID, float value)
{
    switch (effect_UID)
    {
        case EFFECT_NONE:
        break;
        case EFFECT_MOD_HEALTH:
            game.player.health.current += value;
        break;
        case EFFECT_MOD_MANA:
            game.player.mana.current   += value;
        break;
        default:
        break;
    }
};

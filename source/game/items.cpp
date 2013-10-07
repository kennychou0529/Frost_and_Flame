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

#include "items.hpp"
#include "game.hpp"

extern game_class game;

//----------------------------------------------------------------------------------------------------------------

void  item_class::init_items(void) // Initialize hard-coded default items, such as health potions etc...
{
    item_type*      temp_item_pointer;
    //------------------------- Health Potion --------------------------------------------------------------------------
    temp_item_pointer = game.item_manager.add_item(ITEM_HEALTH_POTION);
    temp_item_pointer->data.active                 = true;
    temp_item_pointer->data.consumable             = true;
    temp_item_pointer->data.name                   = "Health Potion";
    temp_item_pointer->data.number_of_item_effects = 1;
    temp_item_pointer->data.image                  = game.texture_manager.add_texture("data/textures/UI/icons/potions/potion_23.png");
    temp_item_pointer->data.sound_move             = game.sound_manager.add_sound("data/sound/inventory/bottle_01.wav");
    temp_item_pointer->data.sound_use              = game.sound_manager.add_sound("data/sound/inventory/bubble_01.wav");
    temp_item_pointer->data.type                   = EFFECT_MOD_HEALTH;
    temp_item_pointer->data.sub_type               = ITEM_POTION_LARGE;
    temp_item_pointer->data.effect[0]              = new effect_type;
    temp_item_pointer->data.effect[0]              = game.effect_manager.add_effect(EFFECT_MOD_HEALTH);
    //------------------------- Mana Potion --------------------------------------------------------------------------
    temp_item_pointer = game.item_manager.add_item(ITEM_MANA_POTION);
    temp_item_pointer->data.active                 = true;
    temp_item_pointer->data.consumable             = true;
    temp_item_pointer->data.name                   = "Mana Potion";
    temp_item_pointer->data.number_of_item_effects = 1;
    temp_item_pointer->data.image                  = game.texture_manager.add_texture("data/textures/UI/icons/potions/potion_22.png");
    temp_item_pointer->data.sound_move             = game.sound_manager.add_sound("data/sound/inventory/bottle_01.wav");
    temp_item_pointer->data.sound_use              = game.sound_manager.add_sound("data/sound/inventory/bubble_01.wav");
    temp_item_pointer->data.type                   = EFFECT_MOD_MANA;
    temp_item_pointer->data.sub_type               = ITEM_POTION_LARGE;
    temp_item_pointer->data.effect[0]              = new effect_type;
    temp_item_pointer->data.effect[0]              = game.effect_manager.add_effect(EFFECT_MOD_MANA);
    //------------------------- Rejuvination Potion --------------------------------------------------------------------------
    temp_item_pointer = game.item_manager.add_item(ITEM_REJUVINATION_POTION);
    temp_item_pointer->data.active                 = true;
    temp_item_pointer->data.consumable             = true;
    temp_item_pointer->data.name                   = "Mana Potion";
    temp_item_pointer->data.number_of_item_effects = 1;
    temp_item_pointer->data.image                  = game.texture_manager.add_texture("data/textures/UI/icons/potions/potion_24.png");
    temp_item_pointer->data.sound_move             = game.sound_manager.add_sound("data/sound/inventory/bottle_01.wav");
    temp_item_pointer->data.sound_use              = game.sound_manager.add_sound("data/sound/inventory/bubble_01.wav");
    temp_item_pointer->data.type                   = EFFECT_MOD_MANA_HEALTH;
    temp_item_pointer->data.sub_type               = ITEM_POTION_LARGE;
    temp_item_pointer->data.effect[0]              = new effect_type;
    temp_item_pointer->data.effect[0]              = game.effect_manager.add_effect(EFFECT_MOD_MANA_HEALTH);
    //------------------------------------------------------------------------------------------------------------
};

void item_class::use_item(UI_form_struct *UI_form_pointer, int element_number)
{
    if (UI_form_pointer->data.element[element_number].active)
    {
        item_type* temp_item_pointer;
        temp_item_pointer = game.item_manager.add_item(UI_form_pointer->data.element[element_number].value);
        if (temp_item_pointer->data.consumable)
        {
            for (int effect_count = 0; effect_count < temp_item_pointer->data.number_of_item_effects; effect_count++)
            {
                switch (temp_item_pointer->data.effect[effect_count]->data.type)
                {
                    case EFFECT_MOD_HEALTH:
                        game.player.health.current += temp_item_pointer->data.effect[effect_count]->data.value;
                    break;
                    case EFFECT_MOD_MANA:
                        game.player.mana.current += temp_item_pointer->data.effect[effect_count]->data.value;
                    break;
                    case EFFECT_MOD_MANA_HEALTH:
                        game.player.health.current += temp_item_pointer->data.effect[effect_count]->data.value;
                        game.player.mana.current   += temp_item_pointer->data.effect[effect_count]->data.value;
                    break;
                    default:
                    break;
                }
            }
            UI_form_pointer->data.element[element_number].quantity--;
            if (UI_form_pointer->data.element[element_number].quantity <= 0)
            {
                UI_form_pointer->data.element[element_number].active   = false;
                UI_form_pointer->data.element[element_number].value    = -1;
                UI_form_pointer->data.element[element_number].quantity = 0;
            }
            game.sound_manager.play(temp_item_pointer->data.sound_use);
        }
    }
};

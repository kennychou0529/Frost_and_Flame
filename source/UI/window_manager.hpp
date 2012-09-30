/**
 * Copyright (C) 2011-2012 Paul Wortmann, PhysHex Games, www.physhexgames.co.nr
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

#ifndef WINDOW_MANAGER_H
#define WINDOW_MANAGER_H

#include "window.hpp"

class window_manager_class
{
    protected:
    private:
    public:
        float mouse_x;
        float mouse_y;
        int   number_of_windows;
        window_class *window;
        window_manager_class(void);
       ~window_manager_class(void);
        void set_active_window(int UID);
        int  get_active_window(void);
        int  register_window(int UID);
        int  register_window(int UID_minimum, int UID_maximum);
        void de_register_window(int UID);
        bool mouse_over_window(float wx, float wy, float ww, float wh);
        void process(void);
        void render(void);
};

#endif // WINDOW_MANAGER_H

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

#include <GL/gl.h>
#include "core.hpp"
#include "graphics.hpp"

graphics_class::graphics_class(void)
{
    graphics_class::resolution_x = 0;
    graphics_class::resolution_y = 0;
};

void  graphics_class::set_resolution(int x_res, int y_res)
{
    graphics_class::resolution_x = x_res;
    graphics_class::resolution_y = y_res;
};

int   graphics_class::get_resolution_x(void)
{
    return(graphics_class::resolution_x);
};

int   graphics_class::get_resolution_y(void)
{
    return(graphics_class::resolution_y);
};

int   graphics_class::gl_to_res(float gl_coord, int max_res)
{
   return((gl_coord+1)*(max_res / 2));
}

float graphics_class::res_to_gl(int  res_coord, int max_res)
{
   return((((float) res_coord / (float) max_res) *2) -1);
}

int   graphics_class::init_gl(int x_res, int y_res)
{
    float color_black[]        = {0.0f,0.0f,0.0f,1.0f};
    float color_white[]        = {1.0f,1.0f,1.0f,1.0f};
    float color_gray[]         = {0.6f,0.6f,0.6f,1.0f};
    float color_red[]          = {1.0f,0.0f,0.0f,1.0f};
    float color_blue[]         = {0.0f,0.0f,0.1f,1.0f};
    float color_yellow[]       = {1.0f,1.0f,0.0f,1.0f};
    float color_light_yellow[] = {0.5f,0.5f,0.0f,1.0f};
    glViewport(0, 0,x_res,y_res);
    glClearColor(0.0f, 0.0f, 0.0f, 0.0f);
    glClearDepth(1.0);
    glMatrixMode(GL_PROJECTION);
    glLoadIdentity();
    glMatrixMode(GL_MODELVIEW);
    glLoadIdentity();
    glEnable(GL_TEXTURE_2D);
    glEnable(GL_DEPTH_TEST);
    glDepthFunc(GL_LESS);
    glHint(GL_PERSPECTIVE_CORRECTION_HINT, GL_NICEST);
    glEnable(GL_BLEND);
    glBlendFunc(GL_SRC_ALPHA,GL_ONE_MINUS_SRC_ALPHA);
    glShadeModel(GL_SMOOTH);
	glHint(GL_PERSPECTIVE_CORRECTION_HINT, GL_FASTEST);
    //--------------------------------------------------------------------------------------------------------------------
	// OpenGL Lighting Setup
	glEnable(GL_LIGHTING);
    float global_ambient[] = { 1.0f, 1.0f, 1.0f, 1.0f };
    glLightModelfv(GL_LIGHT_MODEL_AMBIENT, global_ambient);

	glEnable(GL_LIGHT0);
	float ambientLight0[]  = { 1.0f, 1.0f, 1.0f, 1.0f };
	float diffuseLight0[]  = { 1.0f, 1.0f, 1.0f, 1.0f };
	float specularLight0[] = { 1.0f, 1.0f, 1.0f, 1.0f };
	float position0[]      = { 0.0f, 0.0f, 0.0f, 1.0f };
	glLightfv(GL_LIGHT0, GL_AMBIENT,  ambientLight0);
	glLightfv(GL_LIGHT0, GL_DIFFUSE,  diffuseLight0);
	glLightfv(GL_LIGHT0, GL_SPECULAR, specularLight0);
	glLightfv(GL_LIGHT0, GL_POSITION, position0);
    // Position and direction (spotlight)
	//glEnable(GL_LIGHT1);
    float posLight1[]     = {  0.0f,  0.0f, -1.0f,  1.0f };
    float spotDirection[] = {  0.0f,  0.0f, 1.0f };
	float ambientLight1[]  = { 1.0f, 0.5f, 0.5f, 1.0f };
	float diffuseLight1[]  = { 1.0f, 0.5f, 0.5f, 1.0f };
	float specularLight1[] = { 1.0f, 0.5f, 0.5f, 1.0f };
    glLightfv( GL_LIGHT1, GL_POSITION, posLight1 );
    glLightf ( GL_LIGHT1, GL_SPOT_CUTOFF, 60.0F );
    glLightfv( GL_LIGHT1, GL_SPOT_DIRECTION, spotDirection );
	glLightfv( GL_LIGHT1, GL_AMBIENT,  ambientLight1);
	glLightfv( GL_LIGHT1, GL_DIFFUSE,  diffuseLight1);
	glLightfv( GL_LIGHT1, GL_SPECULAR, specularLight1);
    glLightf ( GL_LIGHT1, GL_CONSTANT_ATTENUATION, 1.0f );
    /*
	glEnable(GL_LIGHT1);
	float ambientLight1[]  = { 1.0f, 0.5f, 0.5f, 1.0f };
	float diffuseLight1[]  = { 1.0f, 0.5f, 0.5f, 1.0f };
	float specularLight1[] = { 1.0f, 0.5f, 0.5f, 1.0f };
	float position1[]      = { 1.5f, 1.0f, 2.0f, 1.0f };
	glLightfv(GL_LIGHT1, GL_AMBIENT,  ambientLight1);
	glLightfv(GL_LIGHT1, GL_DIFFUSE,  diffuseLight1);
	glLightfv(GL_LIGHT1, GL_SPECULAR, specularLight1);
	glLightfv(GL_LIGHT1, GL_POSITION, position1);
    */
    return(0);
}


/**
 * Copyright (C) Paul Wortmann, PhysHex Games, www.physhexgames.com
 * This file is part of "Frost And Flame"
 *
 * "Frost And Flame" is free software: you can redistribute it and/or modify
 * it under the terms of the GNU General Public License as published by
 * the Free Software Foundation, version 2 only.
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
 * @website www.physhexgames.com
 * @license GPL V2
 * @date 2011-11-11
 */

#include "re_graphics_engine.hpp"
#include "../system/re_log.hpp"
#include "../wrappers/re_glew.hpp"
#include "../wrappers/re_opengl.hpp"
#include "../wrappers/re_sdl.hpp"
#include "../wrappers/re_sdl_graphics.hpp"

namespace RoboEngine
{

   void re_cGraphicsEngine::initialize(void)
   {
      RE_GL_SetAttribute(RE_GL_CONTEXT_MAJOR_VERSION, RE_RENDERER_CONTEXT_MAJOR);
      RE_GL_SetAttribute(RE_GL_CONTEXT_MINOR_VERSION, RE_RENDERER_CONTEXT_MINOR);
      RE_GL_SetAttribute(RE_GL_CONTEXT_PROFILE_MASK, RE_GL_CONTEXT_PROFILE_CORE);
      RE_GL_SetAttribute(RE_GL_DOUBLEBUFFER, 1);
      RE_GL_SetAttribute(RE_GL_DEPTH_SIZE, 24);
      RE_GL_SetSwapInterval(1);
      m_currentDisplay = 0;
      m_currentDisplayMode = 0;
      m_numberDisplays = RE_GetNumVideoDisplays();
      m_numberDisplayModes = RE_GetNumDisplayModes(m_currentDisplay);
      // todo: create list of available display modes, if full screen flag, set to optimal full screen resolution.

      if (m_displayFullscreen)
         m_displayFlags |= RE_WINDOW_FULLSCREEN_DESKTOP;
      m_window = RE_CreateWindow("Frost and Flame", m_displayX, m_displayY, m_displayFlags);
      if (m_window == nullptr)
         RoboEngine::log_write(ROBOENGINELOG, __FILE__, __FUNCTION__, __LINE__, "Non fatal warning - Unable to create a window.");
      else
      {
         m_glcontext = RE_GL_CreateContext(m_window);
         RE_glewExperimental(true);
         RE_GLenum glewStatus =RE_glewInit();
         if (glewStatus != RE_GLEW_OK)
            RoboEngine::log_write(ROBOENGINELOG, __FILE__, __FUNCTION__, __LINE__, "Fatal error - Unable to initialize GLEW.");
         else
         {
            int32_t GL_MajorVersion = 0;
            int32_t GL_MinorVersion = 0;
            RE_GL_GetAttribute(RE_GL_CONTEXT_MAJOR_VERSION, &GL_MajorVersion);
            RE_GL_GetAttribute(RE_GL_CONTEXT_MINOR_VERSION, &GL_MinorVersion);
            RoboEngine::log_write(ROBOENGINELOG, __FILE__, __FUNCTION__, __LINE__, "OpenGL Context Version: " + std::to_string(GL_MajorVersion) +  "." + std::to_string(GL_MinorVersion));
            RoboEngine::log_write(ROBOENGINELOG, __FILE__, __FUNCTION__, __LINE__, reinterpret_cast<const char*>(RE_glGetString(RE_GL_VERSION)));
            RoboEngine::log_write(ROBOENGINELOG, __FILE__, __FUNCTION__, __LINE__, reinterpret_cast<const char*>(RE_glGetString(RE_GL_VENDOR)));
            RoboEngine::log_write(ROBOENGINELOG, __FILE__, __FUNCTION__, __LINE__, reinterpret_cast<const char*>(RE_glGetString(RE_GL_RENDERER)));
            RoboEngine::log_write(ROBOENGINELOG, __FILE__, __FUNCTION__, __LINE__, reinterpret_cast<const char*>(RE_glGetString(RE_GL_SHADING_LANGUAGE_VERSION)));


            RE_glClearColor(0.1f,0.1f,0.4f,1);
            RE_glClearDepth(1.0);

         }
      }
   }

   void re_cGraphicsEngine::deinitialize(void)
   {
      RE_DestroyWindow(m_window);
      RE_GL_DeleteContext(m_glcontext);
   }

   void re_cGraphicsEngine::render(void)
   {
      RE_glClear(RE_GL_COLOR_BUFFER_BIT | RE_GL_DEPTH_BUFFER_BIT);
      m_entity = m_entityHead;
      if (m_entity != nullptr)
      {
         while (m_entity  != nullptr)
         {
            if ((m_entity->enabled) && (m_entity->render != nullptr))
            {
               //shader
               if ((m_entity->render->shader != nullptr) && (m_entity->render->shader->ID != 0) && (m_currentShader != m_entity->render->shader->ID))
               {
                  if (m_currentShader != m_entity->render->shader->ID)
                  {
                     RE_glUseProgram(0);
                     for (uint16_t i = 0; i < m_entity->render->shader->numAttributes; i++)
                        RE_glDisableVertexAttribArray(i);
                     m_currentShader = 0;
                  }
                  if (m_currentShader == 0)
                  {
                     m_currentShader = m_entity->render->shader->ID;
                     RE_glUseProgram(m_entity->render->shader->ID);
                     for (uint16_t i = 0; i < m_entity->render->shader->numAttributes; i++)
                        RE_glEnableVertexAttribArray(i);
                  }
                  // initialize mesh
                  if (m_entity->render->shader->ID == 0)
                  {

                  }
                  // render mesh
                  if (m_entity->render->shader->ID != 0)
                  {

                  }
               }

            }
            m_entity = m_entity->next;
         }
      }
      RE_GL_SwapWindow(m_window);
   }

}

/*
void glGenBuffers(GLsizei n, GLuint * buffers);


Sprite::~Sprite()
{
    if (m_vboID != 0)
        glDeleteBuffers(1, &m_vboID);
}

void Sprite::init(float x, float y, float w, float h)
{
    m_x = x;
    m_y = y;
    m_w = w;
    m_h = h;
    float h_h = h / 2.0f;
    float h_w = w / 2.0f;
    const uint32_t numVertex = 6;
    if (m_vboID == 0)
        glGenBuffers(1, &m_vboID);

    s_vertex vertexData[numVertex];

    vertexData[0].position.x = x + h_w;
    vertexData[0].position.y = y + h_h;
    vertexData[1].position.x = x - h_w;
    vertexData[1].position.y = y + h_h;
    vertexData[2].position.x = x - h_w;
    vertexData[2].position.y = y - h_h;

    vertexData[3].position.x = x - h_w;
    vertexData[3].position.y = y - h_h;
    vertexData[4].position.x = x + h_w;
    vertexData[4].position.y = y - h_h;
    vertexData[5].position.x = x + h_w;
    vertexData[5].position.y = y + h_h;

    for (uint32_t i = 0; i < numVertex; i++)
    {
        vertexData[i].color.r = 255;
        vertexData[i].color.g = 0;
        vertexData[i].color.b = 255;
        vertexData[i].color.a = 255;
    }
    vertexData[1].color.r = 0;
    vertexData[1].color.g = 0;
    vertexData[1].color.b = 255;
    vertexData[1].color.a = 255;
    vertexData[4].color.r = 0;
    vertexData[4].color.g = 255;
    vertexData[4].color.b = 0;
    vertexData[4].color.a = 255;

    glBindBuffer(GL_ARRAY_BUFFER, m_vboID);
    glBufferData(GL_ARRAY_BUFFER, sizeof(vertexData), vertexData, GL_STATIC_DRAW);
    glBindBuffer(GL_ARRAY_BUFFER, 0);

}

void Sprite::draw()
{
    glBindBuffer(GL_ARRAY_BUFFER, m_vboID);

    glEnableVertexAttribArray(0);

    glVertexAttribPointer(0, 2, GL_FLOAT, GL_FALSE, sizeof(s_vertex), (void*)offsetof(s_vertex, position));
    glVertexAttribPointer(1, 4, GL_UNSIGNED_BYTE, GL_TRUE, sizeof(s_vertex), (void*)offsetof(s_vertex, color));

    glDrawArrays(GL_TRIANGLES, 0, 6);

    glEnableVertexAttribArray(0);

    glBindBuffer(GL_ARRAY_BUFFER, 0);
}

*/

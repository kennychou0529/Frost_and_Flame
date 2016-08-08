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

#include "re_entity.hpp"

namespace RoboEngine
{

    void re_cEntityManager::freeAll(void)
    {
        m_textureManager.freeAll();
        m_entityRenderManager.freeAll();
        m_entityPhysicsManager.freeAll();
        freeEntities(); // make sure freeEntities() is called last!
    }

    void re_cEntityManager::freeEntities(void)
    {
        re_sEntity* t_entity = m_head;
        while (t_entity != nullptr)
        {
            m_head = m_head->next;
            delete  t_entity;
            t_entity = nullptr;
            t_entity = m_head;
        }
        m_head = nullptr;
        m_tail = nullptr;
    }

    re_sEntity *re_cEntityManager::getNew(void)
    {
        if (m_head == nullptr)
        {
            m_head = new re_sEntity;
            m_tail = m_head;
            return m_head;
        }
        else
        {
            m_tail->next = new re_sEntity;
            m_tail = m_tail->next;
            return m_tail;
        }
        return nullptr;
    }

    void re_cEntityManager::addTexture(re_sEntity *_entity, std::string _fileName)
    {
        if (_entity != nullptr)
            if (_entity->render != nullptr)
                _entity->render->texture = m_textureManager.getNew(_fileName);
    }

}


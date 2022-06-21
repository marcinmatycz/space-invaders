/**
 * @file spaceship.h
 * @author your name (you@domain.com)
 * @brief 
 * @version 0.1
 * @date 2022-06-21
 * 
 * @copyright Copyright (c) 2022
 * 
 */

#pragma once 

#include "raylib.h"

class Bullet
{
    private:
        int m_width; 
        int m_height; 
        int m_speed; 
        int m_xPos; 
        int m_yPos; 
        bool m_bulletActive; 

        void ChangePosition(void)
        {
            m_yPos -= m_speed; 

            if(m_yPos < 0)
            {
                m_bulletActive = false; 
                m_yPos = 400; // start position for every bullet which is down of the screen 
            }
        }

    public:

        Bullet()
        {
            m_width = 1; 
            m_height = 4; 
            m_speed = 50; 
            m_xPos = 0; 
            m_yPos = 400; 
            m_bulletActive = false; 
        }

        Bullet(int width, int height, int speed, int xPos, int yPos)
        {
            m_width = width; 
            m_height = height; 
            m_speed = speed; 
            m_xPos = xPos; 
            m_yPos = yPos; 
            m_bulletActive = false; 
        }
    
        void Draw(void)
        {
            if(m_bulletActive)
            {
                ChangePosition(); 

                DrawRectangle(m_xPos, m_yPos, m_width, m_height, WHITE); 
            }
        }

        void Shoot(void)
        {
            m_bulletActive = true; 
        }

        int get_xPos(void)
        {
            return m_xPos; 
        }

        int get_yPos(void)
        {
            return m_yPos;
        }

        void set_xPos(int xPos)
        {
            m_xPos = xPos; 
        }

};

class SpaceShip
{
    private:    
        int m_width; 
        int m_height; 
        int m_speed; 
        int m_xPos; 
        Bullet m_bullet; 

    public:
        SpaceShip()
        {
            m_width = 100; 
            m_height= 10;
            m_speed = 5; 
            m_xPos = 200; 
            m_bullet = Bullet(1, 4, 50, m_xPos, 0);  
        }

        SpaceShip(int xWidth, int yHeight, int spaceShipSpeed)
        {
            m_width = xWidth; 
            m_width = yHeight; 
            m_speed = spaceShipSpeed; 
            m_bullet = Bullet(1, 4, 50, m_xPos, 0); 
        }

        void Draw(void)
        {
            DrawRectangle(m_xPos, 400, m_width, m_height, WHITE); 
            m_bullet.Draw();
        }

        void ChangePosition(int xPos)
        {
            m_xPos += xPos; 
        }

        void Shoot(void)
        {
            m_bullet.set_xPos(m_xPos); 
            m_bullet.Shoot(); 
        }

};

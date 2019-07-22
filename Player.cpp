#include "Player.hpp"
#include <iostream>
#include <cmath>
#include <array>
#include <fstream>
#include <string>

Player::Player()
{
    x = 1;
    y = 1;
}

int Player::GetLastPositionX() 
{
    return lastX;
}
void Player::SetLastPositionX(int newX) 
{
    lastX = newX;
}

int Player::GetLastPositionY() 
{
    return lastY;
}

void Player::SetLastPositionY(int newY) 
{
    lastY = newY;
}

int Player::GetPositionX()
{
    return x;
}

int Player::GetPositionY()
{
    return y;
}
void Player::ResetToSafePosition()
{
    x = lastX;
    y = lastY; 
}

void Player::CallInput()
{
    char input = ' ';
    std::cin >> input;

    switch (input)
    {
    case 'd':
        lastX = x;
        x++;
        //std::cout << "Derecha" << std::endl;
        break;
    case 'a':
        lastX = x;
        x--;
        //std::cout << "Izquierda" << std::endl;
        break;
    case 's':
        lastY = y;
        y++;
        //std::cout << "Abajo" << std::endl;
        break;
    case 'w':
        lastY = y;
        y--;
        //std::cout << "Arriba" << std::endl;
        break;
    case 'p':
        //std::cout << "Pausa" << std::endl;
        break;
    default:
        std::cout << "El caracter " << input << " no es admitido para esta opcion" << std::endl;
        break;
    }
    //std::cout << "X: " << x << " Y: " << y << std::endl;
}

Player::~Player()
{
}

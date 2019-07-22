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

int Player::GetPositionX()
{
    return x;
}

int Player::GetPositionY()
{
    return y;
}

void Player::CallInput()
{
    char input = ' ';
    std::cin >> input;

    switch (input)
    {
    case 'd':
        x++;
        //std::cout << "Derecha" << std::endl;
        break;
    case 'a':
        x--;
        //std::cout << "Izquierda" << std::endl;
        break;
    case 's':
        y++;
        //std::cout << "Abajo" << std::endl;
        break;
    case 'w':
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

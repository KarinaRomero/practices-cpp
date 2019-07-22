#include "MapCell.hpp"
#include <iostream>
#include <cmath>
#include <array>
#include <fstream>
#include <string>

MapCell::MapCell(/* args */)
{
    id = 0;
}

void MapCell::SetId(int newId)
{
    id = newId;
}

int MapCell::GetId()
{
    return id;
}

MapCell::~MapCell()
{
}

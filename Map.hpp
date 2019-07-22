#include "MapCell.hpp"
#include <iostream>
#include <cmath>
#include <array>
#include <fstream>
#include <string>

class Map
{
private:
    int const static cols = 10;
    int const static rows = 15;
    MapCell cells[rows][cols];
    MapCell* playerCell;

protected:
    void WriteMap(std::string fileUrl);
    void ReadMap(std::string fileUrl);

public:
    Map();
    void Draw();
    void SetPayerCell(int playerX, int playerY);
    void CreateMap(std::string fileUrl);
    ~Map();


};

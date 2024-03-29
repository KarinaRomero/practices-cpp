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
    bool isGameOver;

protected:
    void WriteData(std::string fileUrl, int type);
    void ReadData(std::string fileUrl, int type);
    void LoadGameOver(std::string fileUrl);
    void LoadVictory(std::string fileUrl);

public:
    Map();
    void Draw();
    bool IsGameOver();
    bool SetPayerCell(int playerX, int playerY);
    void LoadMap(std::string fileUrl);
    void LoadIntro(std::string fileUrl);
    void DrawIntro(std::string fileUrl);
    ~Map();


};

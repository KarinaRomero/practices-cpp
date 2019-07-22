#include "Map.hpp"

Map::Map(/* args */)
{
    playerCell = NULL;
}

void Map::Draw()
{
    for (int row = 0; row < rows; row++)
    {
        for (int col = 0; col < cols; col++)
        {
            if (cells[row][col].GetId() == 1 || cells[row][col].GetId() == 5)
            {
                std::cout << cells[row][col].GetId();
            }
            else if (cells[row][col].GetId() == 0)
            {
                std::cout << ' ';
            }
        }
        std::cout << std::endl;
    }
}
void Map::SetPayerCell(int playerX, int playerY)
{
    if (playerCell != NULL)
    {
        playerCell->SetId(0);
    }
    playerCell = &cells[playerY][playerX];
    playerCell->SetId(5);
}

void Map::WriteMap(std::string fileUrl)
{
    char const static level[rows][cols] = {
        {'1', '1', '1', '1', '1', '1', '1', '1', '1', '1'},
        {'1', '0', '0', '0', '0', '0', '0', '0', '0', '1'},
        {'1', '0', '0', '0', '0', '0', '0', '0', '0', '1'},
        {'1', '0', '0', '0', '0', '0', '0', '0', '0', '1'},
        {'1', '0', '0', '0', '0', '0', '0', '0', '0', '1'},
        {'1', '1', '1', '1', '1', '0', '0', '0', '0', '1'},
        {'1', '0', '0', '0', '0', '0', '0', '0', '0', '1'},
        {'1', '0', '0', '0', '0', '0', '0', '0', '0', '1'},
        {'1', '0', '0', '0', '0', '1', '1', '1', '1', '1'},
        {'1', '0', '0', '0', '0', '0', '0', '0', '0', '1'},
        {'1', '0', '0', '0', '0', '0', '0', '0', '0', '1'},
        {'1', '0', '0', '0', '0', '0', '0', '0', '0', '1'},
        {'1', '1', '1', '1', '1', '0', '0', '0', '0', '1'},
        {'1', '0', '0', '0', '0', '0', '0', '0', '0', '1'},
        {'1', '1', '1', '1', '1', '1', '1', '1', '1', '1'},
    };
    std::ofstream fileToWrite(fileUrl);
    std::string line = "";
    if (fileToWrite.is_open())
    {
        for (int row = 0; row < rows; row++)
        {
            for (int col = 0; col < cols; col++)
            {
                line += level[row][col];
                line += ' ';
            }
            fileToWrite << line;
            fileToWrite << "\n";
            line = "";
        }
    }
}

void Map::ReadMap(std::string fileUrl)
{
    std::ifstream fileToRead(fileUrl);
    std::string line = "";
    int rowCount = 0;
    char *character;
    char *end;
    if (fileToRead.is_open())
    {
        while (getline(fileToRead, line))
        {
            character = new char[line.size() + 1];
            copy(line.begin(), line.end(), character);
            character[line.size()] = '\0';
            int colCount = 0;

            for (long long col = std::strtol(character, &end, 10);
                 character != end;
                 col = std::strtol(character, &end, 10))
            {
                cells[rowCount][colCount].SetId(col);
                colCount++;
                character = end;
            }
            rowCount++;
        }
    }
    else
    {
        WriteMap(fileUrl);
        ReadMap(fileUrl);
    }
}

void Map::CreateMap(std::string fileUrl)
{
    ReadMap(fileUrl);
}

Map::~Map()
{
}

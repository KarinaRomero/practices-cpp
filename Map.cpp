#include "Map.hpp"

Map::Map()
{
    playerCell = NULL;
    isGameOver = false;
}

void Map::Draw()
{
    for (int row = 0; row < rows; row++)
    {
        for (int col = 0; col < cols; col++)
        {
            if (cells[row][col].GetId() == 1 || cells[row][col].GetId() == 5 || cells[row][col].GetId() == 8 || cells[row][col].GetId() == 4)
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
bool Map::SetPayerCell(int playerX, int playerY)
{
    bool success = true;
    if (!cells[playerY][playerX].IsBlocked())
    {
        if (cells[playerY][playerX].GetId() == 8)
        {
            LoadVictory("data/VictoryData.txt");
            std::cout << "VICTORY!!!" << std::endl;
            isGameOver = true;
        }
        if (cells[playerY][playerX].GetId() == 4)
        {
            LoadVictory("data/GameOverData.txt");
            std::cout << "GAME OVER!!!" << std::endl;
            isGameOver = true;
        }
        else
        {
            if (playerCell != NULL)
            {
                playerCell->SetId(0);
            }
            playerCell = &cells[playerY][playerX];
            playerCell->SetId(5);
        }
    }
    else
    {
        success = false;
    }
    return success;
}

void Map::WriteData(std::string fileUrl, int type)
{
    std::array<std::array<char, cols>, rows> dataArray;
    std::array<std::array<char, cols>, rows> mapData =
        {{{'1', '1', '1', '1', '1', '1', '1', '1', '1', '1'},
          {'1', '0', '0', '0', '0', '0', '0', '0', '0', '1'},
          {'1', '0', '0', '0', '0', '0', '0', '0', '0', '1'},
          {'1', '0', '0', '0', '0', '0', '0', '0', '0', '1'},
          {'1', '0', '0', '0', '0', '0', '0', '0', '0', '1'},
          {'1', '1', '1', '1', '1', '0', '0', '0', '4', '1'},
          {'1', '0', '0', '0', '0', '0', '0', '0', '0', '1'},
          {'1', '0', '0', '0', '0', '0', '0', '0', '0', '1'},
          {'1', '0', '0', '0', '0', '1', '1', '1', '1', '1'},
          {'1', '0', '4', '0', '0', '0', '0', '0', '0', '1'},
          {'1', '0', '0', '0', '0', '0', '0', '0', '0', '1'},
          {'1', '0', '0', '0', '0', '0', '0', '0', '4', '1'},
          {'1', '1', '1', '1', '1', '0', '0', '0', '0', '1'},
          {'1', '0', '0', '0', '8', '0', '0', '0', '0', '1'},
          {'1', '1', '1', '1', '1', '1', '1', '1', '1', '1'}}};
    std::array<std::array<char, cols>, rows> introData =
        {{{'1', '0', '0', '1', '0', '1', '1', '1', '1', '1'},
          {'1', '0', '0', '1', '0', '0', '0', '1', '0', '0'},
          {'1', '1', '1', '1', '0', '0', '0', '1', '0', '0'},
          {'1', '0', '0', '1', '0', '0', '0', '1', '0', '0'},
          {'1', '0', '0', '1', '0', '1', '1', '1', '1', '1'},
          {'0', '0', '0', '0', '0', '0', '0', '0', '0', '0'},
          {'0', '0', '0', '0', '0', '0', '0', '0', '0', '0'},
          {'1', '1', '1', '1', '1', '1', '1', '1', '1', '1'},
          {'1', '1', '1', '0', '0', '1', '0', '0', '1', '1'},
          {'1', '1', '1', '0', '0', '1', '0', '0', '1', '1'},
          {'1', '1', '1', '1', '1', '1', '1', '1', '1', '1'},
          {'1', '1', '1', '0', '0', '0', '0', '0', '1', '1'},
          {'1', '1', '1', '1', '0', '0', '0', '1', '1', '1'},
          {'1', '1', '1', '1', '1', '1', '1', '1', '1', '1'},
          {'1', '1', '1', '1', '1', '1', '1', '1', '1', '1'}}};

    std::array<std::array<char, cols>, rows> victoryData =
        {{{'1', '0', '0', '1', '0', '1', '1', '1', '1', '1'},
          {'1', '0', '0', '1', '0', '0', '0', '1', '0', '0'},
          {'1', '0', '0', '1', '0', '0', '0', '1', '0', '0'},
          {'1', '0', '0', '1', '0', '0', '0', '1', '0', '0'},
          {'1', '1', '1', '1', '0', '1', '1', '1', '0', '0'},
          {'0', '0', '0', '0', '0', '0', '0', '0', '0', '0'},
          {'0', '0', '0', '0', '0', '0', '0', '0', '0', '0'},
          {'1', '1', '1', '1', '1', '1', '1', '1', '1', '1'},
          {'1', '1', '1', '0', '0', '1', '0', '0', '1', '1'},
          {'1', '1', '1', '0', '0', '1', '0', '0', '1', '1'},
          {'1', '1', '1', '1', '1', '1', '1', '1', '1', '1'},
          {'1', '1', '1', '0', '0', '0', '0', '0', '1', '1'},
          {'1', '1', '1', '1', '0', '0', '0', '1', '1', '1'},
          {'1', '1', '1', '1', '1', '1', '1', '1', '1', '1'},
          {'1', '1', '1', '1', '1', '1', '1', '1', '1', '1'}}};
    std::array<std::array<char, cols>, rows> gameOverData =
        {{{'1', '0', '0', '1', '0', '0', '1', '1', '1', '0'},
          {'1', '0', '0', '1', '0', '1', '0', '0', '0', '1'},
          {'1', '1', '1', '1', '0', '1', '0', '0', '0', '1'},
          {'1', '0', '0', '1', '0', '1', '0', '0', '0', '1'},
          {'1', '0', '0', '1', '0', '0', '1', '1', '1', '0'},
          {'0', '0', '0', '0', '0', '0', '0', '0', '0', '0'},
          {'0', '0', '0', '0', '0', '0', '0', '0', '0', '0'},
          {'1', '1', '1', '1', '1', '1', '1', '1', '1', '1'},
          {'1', '1', '1', '0', '0', '1', '0', '0', '1', '1'},
          {'1', '1', '1', '0', '0', '1', '0', '0', '1', '1'},
          {'1', '1', '1', '1', '1', '1', '1', '1', '1', '1'},
          {'1', '1', '1', '1', '0', '0', '0', '1', '1', '1'},
          {'1', '1', '1', '0', '0', '0', '0', '0', '1', '1'},
          {'1', '1', '1', '1', '1', '1', '1', '1', '1', '1'},
          {'1', '1', '1', '1', '1', '1', '1', '1', '1', '1'}}};
    // 1 to write intro, 2 for write map
    switch (type)
    {
    case 1:
        dataArray = introData;
        break;
    case 2:
        dataArray = mapData;
        break;
    case 3:
        dataArray = victoryData;
        break;
    case 4:
        dataArray = gameOverData;
        break;
    default:
        break;
    }

    std::ofstream fileToWrite(fileUrl);
    std::string line = "";
    if (fileToWrite.is_open())
    {
        for (int row = 0; row < rows; row++)
        {
            for (int col = 0; col < cols; col++)
            {
                line += dataArray[row][col];
                line += ' ';
            }
            fileToWrite << line;
            fileToWrite << "\n";
            line = "";
        }
    }
}

void Map::ReadData(std::string fileUrl, int type)
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
        WriteData(fileUrl, type);
        ReadData(fileUrl, type);
    }
}

void Map::LoadIntro(std::string fileUrl)
{
    ReadData(fileUrl, 1);
}

void Map::LoadMap(std::string fileUrl)
{
    ReadData(fileUrl, 2);
}

void Map::LoadGameOver(std::string fileUrl)
{
    ReadData(fileUrl, 4);
}
void Map::LoadVictory(std::string fileUrl)
{
    ReadData(fileUrl, 3);
}

bool Map::IsGameOver()
{
    return isGameOver;
}

Map::~Map()
{
}

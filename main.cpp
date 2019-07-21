#include <iostream>
#include <cmath>
#include <array>
#include <fstream>
#include <string>

using namespace std;

void DrawMap(int heroPositionR, int heroPositionC, char playerCharacter, char gameMap[5][5])
{
    for (int row = 0; row < 5; row++)
    {
        for (int col = 0; col < 5; col++)
        {
            if (row != heroPositionC)
            {
                cout << gameMap[row][col] << " ";
            }
            else
            {
                if (col != heroPositionR)
                {
                    cout << gameMap[row][col] << " ";
                }
                else
                {
                    cout << playerCharacter << " ";
                }
            }
        }
        cout << endl;
    }
};

void ReadMap(string fileUrl, char gameMap[5][5])
{
    ifstream fileToRead(fileUrl);
    string line = "";
    int rowCount = 0;
    char *character;
    if (fileToRead.is_open())
    {
        while (getline(fileToRead, line))
        {
            character = new char[line.size() + 1];
            copy(line.begin(), line.end(), character);
            character[line.size()] = '\0';
            for (int col = 0; col < 5; col++)
            {
                gameMap[rowCount][col] = character[col];
                //cout << "Row: " << rowCount << " Col: " << col << endl;
            }
            rowCount++;
        }
    }
}

void WriteMap(string fileUrl, char mapToDraw[5][5])
{
    ofstream fileToWrite(fileUrl);
    string line = "";
    if (fileToWrite.is_open())
    {
        for (int row = 0; row < 5; row++)
        {
            for (int col = 0; col < 5; col++)
            {
                line += mapToDraw[row][col];
            }
            fileToWrite << line;
            fileToWrite << "\n";
            line = "";
        }
    }
}

void GetHeroPosition(int playerPosition[2], char playerCharacter, char mapToFind[5][5])
{
    for (int row = 0; row < 5; row++)
    {
        for (int col = 0; col < 5; col++)
        {
            if (mapToFind[row][col] == playerCharacter)
            {
                playerPosition[0] = col;
                playerPosition[1] = row;
                cout << "Col: " << col << " Row: " << row << endl;
            }
        }
    }
}

int main()
{
    string const k_FileUrl = "data/GameData.txt";
    char const playerCharacter = 'P';
    // Col 0, Row 1
    int heroPosition[2];
    bool isGameOver = false;
    char input = ' ';

    char map[5][5] = {
        {'1', '1', '1', '1', '1'},
        {'1', '1', '1', '1', '1'},
        {'1', '1', '1', '1', '1'},
        {'1', '1', '1', '1', '1'},
        {'1', 'P', '1', '1', '1'}};
    char mapR[5][5];

    WriteMap(k_FileUrl, map);
    ReadMap(k_FileUrl, mapR);
    WriteMap("data/cpyGameData.txt", mapR);

    GetHeroPosition(heroPosition, playerCharacter, mapR);

    DrawMap(heroPosition[0], heroPosition[1], playerCharacter, mapR);
    while (!isGameOver)
    {
        cin >> input;

        switch (input)
        {
        case 'd':
            heroPosition[0]++;
            break;
        case 'a':
            heroPosition[0]--;
            break;
        case 's':
            heroPosition[1]++;
            break;
        case 'w':
            heroPosition[1]--;
            break;
        case 'p':
            isGameOver = true;
            break;

        default:
            break;
        }
        DrawMap(heroPosition[0], heroPosition[1], playerCharacter, mapR);
    }
}

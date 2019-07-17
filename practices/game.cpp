#include <iostream>
#include <cmath>
#include <array>
#include <fstream>

using namespace std;

void DrawMap(int heroPositionR, int heroPositionC, char gameMap[5][5])
{
    for (int r = 0; r < 5; r++)
    {
        for (int c = 0; c < 5; c++)
        {
            if (r != heroPositionC)
            {
                cout << gameMap[c][r] << " ";
            }
            else
            {
                if (c != heroPositionR)
                {
                    cout << gameMap[c][r] << " ";
                }
                else
                {
                    cout << 'H'<< " ";
                }
            }
        }
        cout << endl;
    }
};

int main()
{
    int heroPositionR = 0;
    int heroPositionC = 0;
    bool isGameOver = false;
    char input = ' ';
    char map[5][5] = {
        {'1', '1', '1', '1', '1'},
        {'1', '1', '1', '1', '1'},
        {'1', '1', '1', '1', '1'},
        {'1', '1', '1', '1', '1'},
        {'1', '1', '1', '1', '1'}};

    DrawMap(heroPositionR, heroPositionC, map);
    while (!isGameOver)
    {
        cin >> input;

        switch (input)
        {
        case 'd':
            heroPositionR++;
            break;
        case 'a':
            heroPositionR--;
            break;
        case 's':
            heroPositionC++;
            break;
        case 'w':
            heroPositionC--;
            break;
        case 'p':
            isGameOver = true;
            break;

        default:
            break;
        }
        DrawMap(heroPositionR, heroPositionC, map);
    }
}

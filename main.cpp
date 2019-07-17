#include <iostream>
#include <cmath>

using namespace std;

void DrawMap(int heroPosition, char gameMap[5])
{
    for (int i = 0; i < 5; i++)
    {
        if(i != heroPosition)
        {
            cout << gameMap[i];

        }
        else
        {
            cout << 'H';
        }
        
    }
};

int main()
{
    int heroPosition = 2;
    char map[5] = {'1','1','1','1','1'};
    DrawMap(heroPosition, map);
    
    
}
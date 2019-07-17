#include <iostream>
#include <cmath>
#include <array>
#include <fstream>
#include <string>

using namespace std;

int main()
{
    ofstream MyFile("data/GameData.txt");
    string playerName = "";

    if(MyFile.is_open())
    {
        MyFile << "Hello ";
        MyFile << "jajajaja" << endl;
        cout << "What's your name? " << endl;
        cin >> playerName;
        MyFile << playerName << endl;
        MyFile << "jajajaja" << endl;
        MyFile << "other words" << endl;

        
    }
    MyFile.close();

    ifstream OtherFile("data/GameData.txt");
    string line;
    string name;
    int lineName = 0;

    if (OtherFile.is_open())
    {
        while (getline(OtherFile, line))
        {
            lineName++;
            if(lineName == 2)
            {
                name = line;
            }
        }
        
    }
    else
    {
        cout << "error to open file"<< endl;
    }
    
     cout << "Welcome " << name << "!" << endl;
}

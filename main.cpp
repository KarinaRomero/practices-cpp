
#include <iostream>
#include <cmath>
#include <array>
#include <fstream>
#include <string>
#include "Player.hpp"
#include "Map.hpp"


int main()
{
   std::string const static url = "data/GameData.txt";
   bool isGameOver = false;
   int *arrar= NULL;
   Map map;
   Player player;

   map.CreateMap(url);

   while (!isGameOver)
   {
      player.CallInput();
      map.SetPayerCell(player.GetPositionX(), player.GetPositionY());
      map.Draw();
   }
   
   return 0;
}
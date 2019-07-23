
#include <iostream>
#include <cmath>
#include <array>
#include <fstream>
#include <string>
#include "Player.hpp"
#include "Map.hpp"


int main()
{
   std::string const static mapUrl = "data/GameData.txt";
   std::string const introUrl = "data/GameIntro.txt";
   bool isGameOver = false;
   int *arrar= NULL;
   Map map;
   Player player;

   map.LoadIntro(introUrl);
   map.Draw();

   map.LoadMap(mapUrl);
   std::cout << std::endl;
   std::cout << "You must reach the 8 number and skip 4 numbers on the map" << std::endl;
   std::cout << "Press D to start, after Enter! " << std::endl;
   map.Draw();
   

   while (!isGameOver)
   {
      player.CallInput();
      if(!map.SetPayerCell(player.GetPositionX(), player.GetPositionY()))
      {
         player.ResetToSafePosition();
      }
      map.Draw();
      std::cout << "To move you should press |  A ←  |  D →  |  W ↑  |  S ↓  |, after Enter " << std::endl;
   }
   
   return 0;
}
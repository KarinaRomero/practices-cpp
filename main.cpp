
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

   map.LoadMap(mapUrl);
   //map.LoadIntro(introUrl);

   while (!isGameOver)
   {
      player.CallInput();
      if(!map.SetPayerCell(player.GetPositionX(), player.GetPositionY()))
      {
         player.ResetToSafePosition();
      }
      map.Draw();
      
   }
   
   return 0;
}
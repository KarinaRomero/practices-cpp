
#include <iostream>
#include <cmath>
#include <array>
#include <fstream>
#include <string>

using namespace std;

class Animal {
  public:
   Animal(string iName, int iHp) : name(iName), hp(iHp){ 
      cout << "Constructor de Animal" << endl; 
   }
   string GetName() const { return name; }
   int GetHp() const { return hp; }
   void Attack(int iAttack) { hp-=iAttack; }
   void PrintValues()
   {
      cout << "---------------------------------------------------------" << endl;
      cout << "Name = " << name << ", Hp = " << hp<< endl;
   }
   
  protected:
   string name;
   int hp;
};

class Cat : public Animal {
  public:
   Cat(string iName, int iHp, int iSound) : Animal(iName, iHp+10), sound(iSound) { // (1)
      cout << "Constructor de Cat" << endl; 
   }
   int GetSound() const { return sound; }

  protected:
   int sound;
};
class Dog : public Animal {
  public:
   Dog(string iName, int iHp, int iSound) : Animal(iName, iHp+100), sound(iSound) { // (1)
      cout << "Constructor de Dog" << endl; 
   }
   int GetSound() const { return sound; }

  protected:
   int sound;
};

int main() {
   Animal* current;

   Cat cat("gonzalo", 10,3);
   Dog dog("brol", 6, 5);

   current = &cat;
   current->Attack(2);
   current->PrintValues();
   
   current = &dog;
   current->Attack(20);
   current->PrintValues();
   
   return 0;
}
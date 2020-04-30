// Final-Boss Fight.cpp : This file contains the 'main' function. Program execution begins and ends there.
//

// I tried to include as many headers as i just in case
#include <cstdlib>
#include <ctime>
#include <iostream>
#include <cmath>
#include <string>
#include <vector>
#include <random>
#include <array>
#include <chrono>
//#include <bits/stdc++.h> - doesnt want to work
#include <memory>

using std::cin;
using std::cout;
using std::endl;


int main()
{
    // Here's all my values. Couldn't figure out how to get a randomized string
    int pHealth = 100;
    int eHealth = 150;
    int pAttack = 0;
    int eAttack = 0;
    int Defend = 0;
    int Heal = 0;
    int HealAmt = 3;
    int Magic = 0;
    int Action = 0;
    int counter = 0;
    int MagicAmt = 3;
    int eMagic = 0;
    //const string Spells[5] = { "fire a firebolt at", "summon barbed thorns from the ground, piercing into", "shoot a focused magic missile at", "summon insects, that swarm", "summon lightning at"};

   cout << "Hello and welcome to the quick boss battle made by Drake!\n\n You are a wild magic spellsword sent here to defeat the dragon with promise of a grand reward.\n\n";
   cout << "The available commands you have is 1. Attack, 2. Heal, 3. Defend, 4. Magic!\n\n";
   cout << "1. Attack does a dice roll of 1 to 25 damage!\n";
   cout << "2. Defend will halve the damage of the enemy attack!\n";
   cout << "3. Heal will heal you a total of 3 times for 20 to 50 health!\n";
   cout << "4. Magic will perform a random magic spell with random damage, usually 1 to 50! You can do this 3 times! \n\n";
   cout << pHealth <<"               "<< eHealth << endl;
   cout << endl;
   cout << "1. Attack" << endl;
   cout << "2. Defend" << endl;
   cout << "3. Heal" << endl;
   cout << "4. Magic" << endl;
   cout << "5. Quit" << endl;

   do {
        cout << "Choose an action #:  ";
        cin >> Action;
        srand(static_cast<int>(time(0))); //found this code, it supposedly initiates all random functions, so i used it just in case so it all works.

        switch (Action)
        {
            //Attack! for all the attacks, i used this random function i found that seems to works
            case 1:
                pAttack = 1 + rand() % (25 - 1 + 1);
                eAttack = 1 + rand() % (35 - 1 + 1);
                eHealth = eHealth - pAttack;
                pHealth = pHealth - eAttack;
                cout << "You slash at the Golden Dragon, bringing down their Hp to " << eHealth;
                cout << "!\n\n";
                cout << "The Golden Dragon slashes you with it's claws, bringing down your Hp to " << pHealth;
                cout << "!\n\n";
                cout << "player HP: " << pHealth << "               " << "Golden Dragon HP: " << eHealth << endl;
                cout << endl;
                cout << "1. Attack" << endl;
                cout << "2. Defend" << endl;
                cout << "3. Heal" << endl;
                cout << "4. Magic" << endl;
                cout << "5. Quit" << endl;
                break;
                //Defense! just divides enemy combat damage by 2
            case 2:
                eAttack = 1 + rand() % (35 - 1 + 1);
                Defend = eAttack / 2;
                pHealth = pHealth - Defend;
                cout << "You hold up an enchanted shield and cast a protective barrier, making your HP only go down to " << pHealth;
                cout << "!\n\n";
                cout << "player HP: " << pHealth << "               " << "Golden Dragon HP: " << eHealth << endl;
                cout << endl;
                cout << "1. Attack" << endl;
                cout << "2. Defend" << endl;
                cout << "3. Heal" << endl;
                cout << "4. Magic" << endl;
                cout << "5. Quit" << endl;
                break;
                //The heal, unsure of how to cap the health but didn't want to kill myself over it
            case 3:
                if (HealAmt > 0) 
                {
                    HealAmt = HealAmt - 1;
                    Heal = 1 + rand() % (50 - 20 + 20);
                    pHealth = pHealth + Heal;
                    cout << "You drink a health potion quickly, restoring hp up to " << pHealth;
                    cout << "!\n\n";
                    cout << "player HP: " << pHealth << "               " << "Golden Dragon HP: " << eHealth << endl;
                    cout << endl;
                    cout << "1. Attack" << endl;
                    cout << "2. Defend" << endl;
                    cout << "3. Heal" << endl;
                    cout << "4. Magic" << endl;
                    cout << "5. Quit" << endl;
                    break;
                }
                //The Magic attack, where i wanted my randomized strings to be for random magic attacks. Currently, it ends the program like Quit
            case 4:
                if (MagicAmt > 0) 
                {
                    MagicAmt = MagicAmt - 1;
                    Magic = 1 + rand() % (50 - 1 + 1);
                    eMagic = 1 + rand() % (40 - 1 + 1);
                    eHealth = eHealth - Magic;
                    pHealth = pHealth - eMagic;
                    cout << "You summon a magic bolt at the golden dragon, bringing their hp to " << eHealth;
                    cout << "!\n\n";
                    cout << "The Golden Dragon breathes fire upon you, bringing down your Hp to " << pHealth;
                    cout << "!\n\n";
                    cout << "player HP: " << pHealth << "               " << "Golden Dragon HP: " << eHealth << endl;
                    cout << endl;
                    cout << "1. Attack" << endl;
                    cout << "2. Defend" << endl;
                    cout << "3. Heal" << endl;
                    cout << "4. Magic" << endl;
                    cout << "5. Quit" << endl;
                    break;
                }
                //to quit the game, it sets your hp to 0
            case 5:
                pHealth = 0;
                break;

           
                break;
        }

        //Once HP hit's 0, the program ends
       
   }
       while (eHealth > 1 && pHealth > 1);
   return 0;
}

// Run program: Ctrl + F5 or Debug > Start Without Debugging menu
// Debug program: F5 or Debug > Start Debugging menu

// Tips for Getting Started: 
//   1. Use the Solution Explorer window to add/manage files
//   2. Use the Team Explorer window to connect to source control
//   3. Use the Output window to see build output and other messages
//   4. Use the Error List window to view errors
//   5. Go to Project > Add New Item to create new code files, or Project > Add Existing Item to add existing code files to the project
//   6. In the future, to open this project again, go to File > Open > Project and select the .sln file

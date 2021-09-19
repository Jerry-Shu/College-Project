#include <iostream>
#include <vector>
#include <cstdlib>
using namespace std;

//define Character struct
struct Character
{
    string name;
    int hp;
    int attackPower;
    int armor;


};
//Prompt the user for "Name: ", "HP: ", "Attack power: ", and "Armor: ", input them into a local Character struct, and return it.
Character inputCharacter();

//return a random int in the range [1:20].  Don't forget to seed with 1337 in main.
int d20();

//a attacks b, according to the rules stated in the instructions
//output the name of the attacker and defender, whether or not there was a hit, and how much damage was done
//see the sample output for how to format the text
//if b's hp drops to 0 or below, output b.name is out of the battle
void aAttacksb(const Character& a, Character& b);

//return false if any Character in group has hp > 0, true otherwise
bool defeated(const vector<Character>& group);

//Battle the hero vs monsters as stated in the instructions
//When the loop ends, output either "Monsters win" or "Hero wins"
//Do not allow monsters to continue to attack the hero if hero hp <= 0
//Do not allow monsters whose hp <= 0 to attack the hero
//Do not allow the hero to attack monsters whose hp <= 0
void battle(Character& hero, vector<Character>& monsters);

int main()
{
    srand(1337);  //don't change this when testing on the server
    int numMonsters;

    cout << "Define your hero" << endl;
    Character hero = inputCharacter();

    cout << "Input number of monsters: ";
    cin >> numMonsters;

    //declare a vector of Characters of size numMonsters
    vector<Character>monsters(numMonsters);
    for(int i = 0; i < numMonsters; i++)
    {
        cout << "Monster " << i+1 << endl;
        monsters.at(i) = inputCharacter();
        //assign the return from inputCharacter into the ith element of your vector
    }

    battle(hero, monsters);

    return 0;
}

Character inputCharacter()
{
    Character character_info;
    cout << "Name: ";
    cin >> character_info.name;
    cout << "HP: ";
    cin >> character_info.hp;
    cout << "Attack power: ";
    cin >> character_info.attackPower;
    cout << "Armor: ";
    cin >> character_info.armor;

    return character_info;





}
int d20()
{
    int num;
    num = rand() % 20 + 1;

    return num;



}
void aAttacksb(const Character& a, Character& b)
{
    if(a.hp > 0 && b.hp > 0)
    {

        int roll;
        cout << a.name << " attacks " << b.name << endl;
        roll = d20();

        if(roll > b.armor)
        {
            cout << "Hit for "<< a.attackPower << " damage" << endl;
            b.hp -= a.attackPower;

        }
        else
        {
            cout << "Miss" << endl;
        }
        if(b.hp <= 0)
        {

            cout << b.name << " is out of the battle"<< endl;
        }




    }



}
bool defeated(const vector<Character>& group)
{
    bool win_lose = true;
    for(int i = 0; i < group.size(); i++)
    {

        if(group.at(i).hp > 0)
        {
            win_lose = false;
            break;
        }

    }

    return win_lose;





}
void battle(Character& hero, vector<Character>& monsters)
{
    int i;
    if(!defeated(monsters) && hero.hp > 0)
    {
        while(!defeated(monsters) && hero.hp > 0)
        {
            for(i = 0; i < monsters.size(); i++)
            {
                aAttacksb(hero, monsters.at(i));
            }
            for(i = 0; i < monsters.size(); i++)
            {

                aAttacksb(monsters.at(i), hero);

            }


        }
        if(!defeated(monsters) && hero.hp <= 0)
        {
            cout << "Monsters win" << endl;
        }
        else if(defeated(monsters) && hero.hp > 0)
        {
            cout << "Hero wins" << endl;

        }



    }





}

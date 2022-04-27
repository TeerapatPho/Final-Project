#include <string>
#include <vector>

using namespace std;

#ifndef CARD_H
#define CARD_H

class card
{
private:
    string name;
    string desc;

    int health;
    int happiness;
    int energy;
    int money;

public:
    card(string = "", string = "", int = 0, int = 0, int = 0, int = 0);
    // ~card();
    string get_card_name() { return name; }
    string get_card_desc() { return desc; }
    vector<int> get_value()
    { // get every value from each
        vector<int> v = {health, happiness, energy, money};
        return v;
    }
};

card::card(string name, string desc, int hea, int hap, int en, int mon)
{
    this->name = name;
    this->desc = desc;
    this->health = hea;
    this->happiness = hap;
    this->energy = en;
    this->money = mon;
}

#endif
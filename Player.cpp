#include <iostream>
#include <string>
#include <map>

using namespace std;

#ifndef asd

#include "Player.h"
#include "Card.h"

player::player(string name_input)
{
    name = name_input;
    metier = "None";
    work_place = "None";
    current_place = "None";
    car_type = "Walk";
    education = 0; // max = 700;
    work_EXP = 0;  // max = {0, 100, 200, 400, 800, 1600, 3200, 6400}; -> 10 energy/ 1 tap/ 12 exp
    health = 200;  // max = 2000
    money = 200;
    debt = 0;
    happiness = 200;
    fullness = false;
    energy = 200;
    salary = 0;
    account_balance = 0;
    food_reserve = 0; //ไม่มีละ555555
    vector<string> key = {"lottery","newspaper","refridge",}; //มีระบบสัตวเลี้ยงมั้ย รึทำเปนตุ๊กตานะ
    for(auto &itr:key) bag[key] = false;
  
}

string player::get_and_change_metier(string metier_input)
{
    if (metier_input != "")
        metier = metier_input;
    return metier;
}
string player::get_and_change_work_place(string work_place_input)
{
    if (work_place_input != "")
        work_place = work_place_input;
    return work_place;
}
string player::get_and_change_current_place(string current_place_input)
{
    if (current_place_input != "")
        current_place = current_place_input;
    return current_place;
}
string player::get_and_change_home(string home_input)
{
    if (home_input != "")
        home = home_input;
    return home;
}
string player::get_and_change_car_type(string car_input)
{
    if (car_input != "")
        car_type = car_input;
    return car_type;
}
int player::get_and_change_education(int education_input)
{
    education += education_input;
    if (education < 0)
        education = 0;
    return education;
}
int player::get_and_change_workEXP(int work_EXP_input)
{
    work_EXP += work_EXP_input;
    if (work_EXP < 0)
        work_EXP = 0;
    return work_EXP;
}
int player::get_and_change_debt(int debt_input)
{
    debt += debt_input;
    if (debt < 0)
        debt = 0;
    return debt;
}
int player::get_and_change_money(int money_input)
{
    money += money_input;
    if (money < 0)
        money = 0;
    return money;
}
int player::get_and_change_health(int health_input)
{
    health += health_input;
    if (health < 0)
        health = 0;
    return health;
}
int player::get_and_change_happiness(int happiness_input)
{
    happiness += happiness_input;
    if (happiness < 0)
        happiness = 0;
    return happiness;
}
int player::get_and_change_fullness(int fullness_input)
{
    fullness += fullness_input;
    if (fullness < 0)
        fullness = 0;
    return fullness;
}
int player::get_and_change_energy(int energy_input)
{
    energy += energy_input;
    if (energy < 0)
        energy = 0;
    return energy;
}
int player::get_and_change_salary(int salary_input)
{
    salary += salary_input;
    if (salary < 0)
        salary = 0;
    return salary;
}
int player::get_and_change_account_balance(int account_balance_input)
{
    account_balance += account_balance_input;
    if (account_balance < 0)
        account_balance = 0;
    return account_balance;
}
int player::get_and_change_food_reserve(int food_reserve_input)
{
    food_reserve += food_reserve_input;
    if (food_reserve < 0)
        food_reserve = 0;
    return food_reserve;
}
map<string, bool> player::get_bag()
{
    return bag;
}

void player::display()
{
    cout << "Name : " << name << endl;
    cout << "Meiter : " << metier << endl;
    cout << "Work Place : " << work_place << endl;
    cout << "Current Place : " << current_place << endl;
    cout << "Edcutaion : " << education << endl;
    cout << "Work Experience : " << work_EXP << endl;
    cout << "Health : " << health << endl;
    cout << "Balance : " << money << endl;
    cout << "Debt : " << debt << endl;
    cout << "Happiness : " << happiness << endl;
    cout << "Fullness : " << fullness << endl;
    cout << "Energy : " << energy << endl;
    cout << "Salary : " << salary << endl;
    cout << "Account Balance : " << account_balance << endl;
}

void player::get_card(card card_input)
{
    vector<int> status = card_input.get_value();
    cout << card_input.get_card_name() << endl;
    cout << card_input.get_card_desc() << endl;
    get_and_change_energy(status[2]);
    get_and_change_health(status[0]);
    get_and_change_money(status[3]);
    get_and_change_happiness(status[1]);
    cout << "================================" << endl;
}
void player::calculation_card_by_stat()
{
    vector<card> situation_card_deck = generate_situation_card();
    if (!fullness)
        get_card(situation_card_deck[0]);
    if (happiness < 100)
        get_card(situation_card_deck[1]);
    if (health < 100)
        get_card(situation_card_deck[2]);
}
/*int player::bag_check(string check_obj){
    return bag.find(check_obj);
}*/
bool player::buying(int cost) // แก้ check ว่ามี VexPhone หรือไม่
{
    
    try
    {
        if (account_balance + money < cost)
            throw cost - money - account_balance;
        if (money > cost)
            money -= cost;
        else
        {
            money = 0;
            account_balance -= cost - money;
        }
        cout << "Payment successful :)" << endl;
    }
    catch (int money_need)
    {
        cout << "You need " << money_need << " dollar more!" << endl;
    }
}
void print_card(vector<card> temp){ // แยก desc เป็น 2 arr ด้วย
  int spaces = 6;
  for(int i=0;i<temp.size();i++){
    cout << "=========================\n";
    for(int j=0;j<15;j++){
    if(j==1)  cout << "|" << string( spaces, ' ' ) <<  "Hello world!" << string( spaces-1, ' ' ) << "|" << temp[i].get_card_desc();
    else if(j==6) cout << "|" << string(14/2,' ') << "Money : -10"  << string(14/2 - 2,' ') << "|";
    else if(j==7) cout << "|" << string(13/2,' ') << "Health : -10"  << string(13/2 - 1,' ') << "|";
    else if(j==8) cout << "|" << string(10/2,' ') << "Happiness : -10"  << string(10/2 - 2,' ') << "|";
    else if(j==9) cout << "|" << string(13/2,' ') << "Energy : -10"  << string(13/2 - 1,' ') << "|";
    else cout << "|                       |";
    cout << "\n";
    }
    cout << "=========================\n";
    
  }
}

void player::do_work()
{
    // (20 energy/ 1 tap/ 12 exp)
    try
    {
        if (energy <= 0)
            throw;

        money += (energy >= 20) ? (salary * 8) : (static_cast<int>(floor(salary * 8 * static_cast<float>(energy) / 20)));
        work_EXP += (energy >= 20) ? (12) : (static_cast<int>(floor(12 * static_cast<float>(energy) / 20)));
        energy -= (energy >= 20) ? (20) : (energy);
        if (bag["Notebook"])money += 4;
        cout << "Work work work!" << endl;
    }
    catch (...)
    {
        cout << "You not have energy! go home and recharge your energy." << endl;
    }
}
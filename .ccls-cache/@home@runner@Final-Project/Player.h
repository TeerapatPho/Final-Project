#include <string>
#include <map>
#include <queue>
#include <vector>

using namespace std;

#include "Card.h"

#ifndef PLAYER_H
#define PLAYER_H

vector<card> generate_situation_card()
{
    vector<card> situation_card_deck;
    situation_card_deck.push_back(card("Hungry!", "You forgot to eat meal, Your energy have been decrease.", 0, 0, -15, 0));
    situation_card_deck.push_back(card("Are you serious?", "You are stressfull, Your health and energy have been decrease.", -10, 0, -5, 0));
    situation_card_deck.push_back(card("Sick Stomach", "You have an upset stomach, you must go to the hospital.", 0, 0, -10, -45));
    // situation_card.push_back(card("","You have an upset stomach, you must go to the hospital.",0,0,0,-40));

    return situation_card_deck;
}

class player
{ // พวกล็อตเตอรี่กับตู้เย็นและผักแช่แข็งทั้งหลายกับพวกสัตว์เลี้ยง และอื่นๆ ถ้ามีก็ต้องมีกระเป๋าเก็บของพวกนี้ด้ว
private:
    string name;           //ชื่อ
    string metier;         //อาชีพ
    string work_place;     //สถานที่ทำงาน
    string current_place;  //สถานที่ปัจจุบัน
    string home;           //ที่พัก
    string car_type;       //ประเภทยานพหานะ
    int education;         //การศึกษา
    int work_EXP;          //ประสบการณ์ทำงาน
    int health;            //สุขภาพ
    int money;             //เงิน
    int debt;              //หนี้
    int happiness;         //ความสุข
    bool fullness;         //ความอิ่ม
    int energy;            //พลังงานจัย
    int salary;            //เงินเดือน
    int account_balance;   //เงินในบัญชี
    int food_reserve;      //เช็คอาหารในตู้เย็น
    map<string, bool> bag; //ตรงกระเป๋าทำเป็น dict มั้ยแล้วเก็บเป็นชื่อคู่กับ bool(0,1) เช็คว่ามีหรือไม่มี
    queue<card> pl_card;
    
public:
    player(string = ""); //รับชื่อผู้เล่น
    // ~player();
    // get and change ถ้าไม่ได้ส่งค่าเข้ามาจะเป็นการ return ค่าปัจจุบันกลับไป แต่ถ้าส่งค่าเข้ามาจะเป็นการเปลี่ยน/บวกข้อมูลแล้ว return กลับไป
    string get_and_change_metier(string = "");
    string get_and_change_work_place(string = "");
    string get_and_change_current_place(string = "");
    string get_and_change_home(string = "");
    string get_and_change_car_type(string = "");
    int get_and_change_education(int = 0);
    int get_and_change_workEXP(int = 0);
    int get_and_change_debt(int = 0);
    int get_and_change_money(int = 0);
    int get_and_change_health(int = 0);
    int get_and_change_happiness(int = 0);
    int get_and_change_fullness(int = 0);
    int get_and_change_energy(int = 0);
    int get_and_change_salary(int = 0);
    int get_and_change_account_balance(int = 0);
    int get_and_change_food_reserve(int = 0);
    map<string, bool> get_bag();
    bool buying(int); // สำหรับ player ที่มีโทรศัพท์มือถือ ส่งราคาสินค้า(แบบไม่ติดลบ)

    void display();
    void get_card(card);
    void add_plcard(card temp){pl_card.push(temp);}
    queue<card> get_plcard(){return pl_card;}
    void calculation_card_by_stat();

    void do_work();
};

#endif
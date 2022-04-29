#include <iostream>
#include <iomanip>
#include <utility>
#include <string>
#include <vector>
#include <queue>
#include <map>
#include <random>
#include <exception>
#include <time.h>
#include <limits>
// #include <conio.h>
#include <functional>
#include "conio.h"

using namespace std;

/* function prototype */
void setup();
template <typename ClassObj>
ClassObj gen_tempObj(); // maybe delete
template <typename T>
int checkIndex_vector(T, vector<T>);
template <typename T>
T selection_menu(string, vector<T>, vector<T>, function<void(void)>);

/* class prototype */
class option;
class card;
class player;
class place;
class sell_object;
class board;
class game;

class restaurant;
class gym;
class home;
class market;
class apartment;
class bank;
class tech_coop;
class job_office;
class art;
class school;
class it_store;
class mall;

place *name2placePtr(string plName);

vector<place *> plList;

#include "Exception.h"
map<string, game_exception *> myex;
#include "Color.h"
#include "Card.h"
#include "Player.h"
#include "Place.h"
#include "Board.h"
#include "Option.h"
#include "Game.h"

int main()
{
    setup();
    option opt;

    // splash page?
    system("clear");
    cout << MAG << "=v=.=v=.=v=.=v=.=v=.=v=.=v=.=v=.=v=.=v=.=v=.=v=.=v=.=v=.=v=.=v=.=v=.=v=.=v=.=v=.=v=.=v=.=v=.=v=.=v=.=v=.=v=.=v=.=\n"
         << reset;
    cout << CYN << "=================================================================================================================\n\n\n"
         << reset;
    cout << WHT << "                                        " << YEL << ">>>" << reset << "   Work-Life Balance Game!  " << YEL << "<<<    \n\n"
         << reset;
    cout << "                  Use Key " << RED << "(W)" << reset << " to move Up, " << RED << "(S)" << reset " to move Down, " << RED << "(A)" << reset << " to move Left and " << RED << "(D)" << reset << " to move Right\n";
    cout << "                                            Use Space Bar to select choice\n";
  cout << " URL for reading instruction : https://drive.google.com/file/d/1qE31XvNP4qTzdbXpGW8roignbis41ZUT/view?usp=sharing\n\n\n";
    cout << CYN << "=================================================================================================================\n"
         << reset;
    cout << MAG << "=v=.=v=.=v=.=v=.=v=.=v=.=v=.=v=.=v=.=v=.=v=.=v=.=v=.=v=.=v=.=v=.=v=.=v=.=v=.=v=.=v=.=v=.=v=.=v=.=v=.=v=.=v=.=v=.=\n\n\n"
         << reset << endl;
    getch();
  
  system("clear");
 cout << BLK << WHTB << "                                       " << endl;
 cout << " █▀▀▀▀▀█ ▄ █ ▀███▄ ▀▀█▀█   ▀▄▄ █▀▀▀▀▀█ " << endl;
 cout << " █ ███ █ ▄▄▄ █▀▄█ ▄ ▄ ▀▀▀▄▄█ ▀ █ ███ █ " << endl; 
 cout << " █ ▀▀▀ █ ▄█ ▄▄  ▀▀▄ ▀▀▄▀ ▄ ▀▄  █ ▀▀▀ █ " << endl;
 cout << " ▀▀▀▀▀▀▀ ▀▄█▄▀ █ █ ▀▄█▄▀ █ █▄█ ▀▀▀▀▀▀▀ " << endl;
 cout << " ▀▀██▀▄▀█▀▀▄▀▄▄▄▄▀█▀▄█▄█▄  ▀▀▄▀ █ █▄█  " << endl;
 cout << " █▀▄▀█▄▀ █ █ ▄█▀█▀▀ ▄█▄  █ █▀█▀▄█▀█▀▄▀ " << endl;
 cout << " ▀▄▀███▀██▄  ▀ ▀█▄▀ █  ▀▀ ▀▄  ▀▀▄▀▀█▄▀ " << endl;
 cout << " ▄▀▀▀  ▀▀▀▄██▀ ▄ ▄   ▄▄█▄█▀▄██████▄▀▀█ " << endl;
 cout << " ▀ ▀▄▀▀ █▄▄▀▄▄▄▄ ▀  █ ▀▄▀▀▄▀▄ ▀▄▀▀█▄▀  " << endl; 
 cout << " ▄▄▄▀▀▀██▄█ ▄█▀▀█▀▀ ██▄ ▀ ▄█▄▀ ██ ▀▀█  " << endl;
 cout << " ▀▀█▄▀▀▀ ▄ ▀ ▀ ▀▀▄▀  █▄▀▄▀▄█ ▄▀▀▄▀▀▀█▀ " << endl;
 cout << " ▀▀▄▀▄▀▀████▀ ▄▀▄ █▄ ▄█▄█  █▀▄▀█▀▀ ▀█  " << endl; 
 cout << " █▀ █▀▀▀▄▀ ▄▀▄▄▄ ▄█▀▀█ ▀█ ▀█ ▄▀▀▄▀▄▀█▀ " << endl; 
 cout << " █ ▀█▄ ▀▄▀ ▄ ▄█▀█▀   ▀▄▀ ▀▀▀▀▄█ ▄█▀▀▀█ " << endl; 
 cout << " ▀ ▀ ▀▀▀ ███ ▀ ▀ ▄▀ ▄▀▄▀  ▄▀██▀▀▀███   " << endl;
 cout << " █▀▀▀▀▀█ ▀▄ █▀ ▄▀ ▀▀ ▄▄  ▄▀▀ █ ▀ █  ▀▀ " << endl;
 cout << " █ ███ █ █▀▄▀▄▄▄▀██▄▄▀ ▀▄  █▀███▀█ ▀▄█ " << endl;
 cout << " █ ▀▀▀ █ █▄▀ ▄█▀█▀ █▄▀█▄ ▀  ▄█▄ ▄ ▀▀▀█ " << endl;
 cout << " ▀▀▀▀▀▀▀ ▀ ▀ ▀ ▀▀ ▀  ▀ ▀  ▀ ▀ ▀▀▀ ▀▀▀▀ " << endl;
 cout << "                                       " << reset << endl;
 getch();
    // main menu
    do
    {
        string main_choice = selection_menu<string>("Work-Life Balance", {}, {"Option", "Play", "Exit"}, [&]() -> void {});

        if (main_choice == "Exit")
        {
            cout << MAG << "=v=.=v=.=v=.=v=.=v=.=v=.=v=.=v=.=v=.=v=.=v=.=v=.=v=.=v=.=v=.=v=.=v=.=v=.=v=.=v=.=v=.=v=.=v=.=v=.=v=.=v=.=v=.=v=.=\n"
                 << reset;
            cout << CYN << "=================================================================================================================\n\n\n";
            cout << RED << "                                        " << "Hasta luego! come for fun next time ;)\n\n\n\n";
            cout << CYN << "=================================================================================================================\n"
                 << reset;
            cout << MAG << "=v=.=v=.=v=.=v=.=v=.=v=.=v=.=v=.=v=.=v=.=v=.=v=.=v=.=v=.=v=.=v=.=v=.=v=.=v=.=v=.=v=.=v=.=v=.=v=.=v=.=v=.=v=.=v=.=\n\n\n"
                 << reset << endl;
            getch();
            return 0;
        }
        else if (main_choice == "Option")
        {
            do
            {
                string opt_choice = selection_menu<string>("Option", {"Select Map Number", "Set Max Round", "Set Player Number"}, {" ", "Return", " "}, [&]() -> void
                                                           {
                cout << "Current map number: " << opt.get_mapNo();
                cout << " Max Play round: " << opt.get_maxRound();
                cout << " Player Number: " << opt.get_nPlayer() << endl;
                opt.display_map(); });
                if (opt_choice == "Return")
                    break;
                int x;
                cout << opt_choice << ": ";
                try {
                    cin >> x;
                    if (cin.fail()) throw *myex["expect_int"];
                }
                catch (exception& e) {
                    cerr << e.what() << endl;
                    getch();

                    cin.clear(); // error
			        cin.ignore(10, '\n');
                }
                if (opt_choice == "Select Map Number")
                {
                    if(x < 1 || x > 4) {
                        cout << "Please Select From 1-4" << endl;
                        continue; 
                    }
                    opt.set_mapNo(x);
                }
                else if (opt_choice == "Set Max Round")
                {
                    if(x < 1) {
                        cout << "Please don't select number lower than 1" << endl;
                        continue; 
                    }
                    opt.set_maxRound(x);
                }
                else if (opt_choice == "Set Player Number")
                {
                    if(x < 1) {
                        cout << "Please don't select number lower than 1" << endl;
                        continue; 
                    }
                    opt.set_nPlayer(x);
                }
            } while (true);
        }
        else if (main_choice == "Play")
        {
            game game_(opt);
            for (int round = 1; round <= opt.get_maxRound(); round++)
            {
                game_.change_round();
                for (int i = 0; i < opt.get_nPlayer(); i++)
                {
                    game_.next_player_turn();
                }
            }
            game_.score_cal();
        }
    } while (true);
}

void setup()
{
    myex = my_ex();

    srand(time(0));

    plList.push_back(new restaurant);
    plList.push_back(new gym);
    plList.push_back(new home);
    plList.push_back(new market);
    plList.push_back(new apartment);
    plList.push_back(new bank);
    plList.push_back(new tech_coop);
    plList.push_back(new job_office);
    plList.push_back(new art);
    plList.push_back(new school);
    plList.push_back(new it_store);
    plList.push_back(new mall);
}

template <typename ClassObj>
ClassObj gen_tempObj()
{
    ClassObj temp;
    return temp;
}

template <typename T>
int checkIndex_vector(T value, vector<T> vec)
{
    for (int i = 0; i < vec.size(); i++)
    {
        if (vec[i] == value)
            return i;
    }
    return -1;
}

template <typename T>
T selection_menu(string header, vector<T> choices, vector<T> addition, function<void(void)> print)
{
    // choices คือช้อยหลักที่จะให้แสดงผลได้เยอะๆ และแสดงด้านบน
    // addition จะแสดงด้านล่างและ มีแค่ 3 อันเท่านัน ห้ามขาดห้ามเกินถ้ามไม่มีใหแทนเป็น " " เช่ร {" ", "return", "work"}
    vector<vector<string>> s_board;
    int height = ceil(static_cast<float>(choices.size()) / 3) + 1;
    s_board.resize(height);
    for (auto &i : s_board)
        i.resize(3);

    // set data to s_board
    for (int i = 0; i < choices.size(); i++)
        s_board[i / 3][i % 3] = choices[i];
    if (choices.size() % 3 != 0)
    {
        for (int i = choices.size() % 3; i < 3; i++)
            s_board[height - 2][i] = " ";
    }
    for (int i = 0; i < 3; i++)
        s_board[height - 1][i] = addition[i];

    // move

    int x = 0, y = 0;
    char c;
    do
    {
        system("clear");
        cout << BRED << header << reset << endl;
        cout << CYN << "==============================================================" << reset << endl;
        for (int i = 0; i < s_board.size(); i++)
        {
            for (int j = 0; j < s_board[0].size(); j++)
            {
                // if(s_board[x][y] == " ") y--;
                if (x != i || y != j)
                    cout << GRN << reset << left << setw(20) << " " + s_board[i][j] + " " << reset;
                else
                    cout << GRN << left << setw(20) << "[" + s_board[i][j] + "]" << reset;
            }

            cout << endl;
        }
        cout << CYN << "==============================================================" << reset << endl;
        print();
        c = getch();
        if (c == 'w' && x != 0)
            x--;
        else if (c == 's' && x != s_board.size() - 1)
            x++;

        else if (c == 'a' && y != 0)
            y--;

        else if (c == 'd' && y != s_board[0].size() - 1)
            y++;
        // cout << x << y << endl;
        if (c == ' ')
        {
            try
            {
                if (s_board[x][y] == " ")
                {
                    x = 0, y = 0;
                    throw *myex["choice_err"];
                }
                return s_board[x][y];
            }
            catch (exception &e)
            {
                cerr << e.what() << endl;
                getch();
            }
        }

    } while (true);
}

place *name2placePtr(string plName)
{
    for (auto &itr : plList)
    {
        if (itr->get_name() == plName)
            return itr;
    }
    return nullptr;
}

/*
    ใช้ wasd เลื่อน
    [a]  b   c
     d   e   f
     g   h

     x   y   z
    ----------------------------
     a  [b]  c
     d   e   f
     g   h

     x   y
    ----------------------------
     a   b   c
    [d]  e   f
     g   h

     x   y
    ----------------------------
     a   b   c
     d   e   f
     g

    [x]  y

    คือ addition ส่วนมากจะใช้วางพวก "work", "return" และอื่นๆ มันจะแยกกับกลุ่มตัวเลือกด้านบน และจะอยู่ row สุดท้ายของ s_board เสมอ




*/
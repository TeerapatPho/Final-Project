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

#include "Color.h"
#include "conio.h"

using namespace std;

/* function prototype */
void setup();
template <typename ClassObj>
ClassObj gen_tempObj(); // maybe delete
template <typename T>
int checkIndex_vector(T, vector<T>);
template <typename T>
T selection_menu(vector<T>, vector<T>);

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

#include "Card.h"
#include "Player.h"
#include "Place.h"
#include "Board.h"
#include "Exception.h"
#include "Option.h"
#include "Game.h"
#include "Color.h"

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
    cout << "                  Use Key " << RED << "(W)" << reset << " to move Up, " << RED << "(S)" << reset " to move Down, " << RED << "(A)" << reset << " to move Left and " << RED << "(D)" << reset << " to move Right\n\n\n";
    cout << CYN "=================================================================================================================\n"
         << reset;
    cout << MAG "=v=.=v=.=v=.=v=.=v=.=v=.=v=.=v=.=v=.=v=.=v=.=v=.=v=.=v=.=v=.=v=.=v=.=v=.=v=.=v=.=v=.=v=.=v=.=v=.=v=.=v=.=v=.=v=.=\n\n\n"
         << reset << endl;
    getch();

    // main menu
    do
    {
        string main_choice = selection_menu<string>({}, {"Option", "Play", "Exit"});

        if (main_choice == "Exit")
            return 0; // or make ending page
        else if (main_choice == "Option")
        {
            cout << "Current map number: " << opt.get_mapNo();
            cout << " Max Play round: " << opt.get_maxRound();
            cout << " Player Number: " << opt.get_nPlayer() << endl;
            opt.display_map();
            string opt_choice = selection_menu<string>({"Select Map Number", "Set Max Round", "Set Player Number"}, {" ", "Return", " "});
            if (opt_choice == "Return")
                continue;
            int x;
            cout << opt_choice << ": ";
            cin >> x;
            if (opt_choice == "Select Map Number")
            {
                opt.set_mapNo(x);
            }
            else if (opt_choice == "Set Max Round")
            {
                opt.set_maxRound(x);
            }
            else if (opt_choice == "Set Player Number")
            {
                opt.set_nPlayer(x);
            }
        }
        else if (main_choice == "Play")
        {
            game game_(opt);
        }
    } while (true);
}

void setup()
{
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
T selection_menu(vector<T> choices, vector<T> addition)
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

    int x = 0, y = 0;
    char c;
    do
    {
        system("clear");
        for (int i = 0; i < s_board.size(); i++)
        {
            for (int j = 0; j < s_board[0].size(); j++)
            {
                // if(s_board[x][y] == " ") y--;
                if (x != i || y != j)
                    cout << " " << s_board[i][j] << " ";
                else
                    cout << "[" << s_board[i][j] << "]";
            }

            cout << endl;
        }
        c = getch();
        if (c == 'w' && x != 0)
        {
            if (s_board[x][y] == " ")
            {
                if (s_board[x - 1][y] == " ")
                    x++;
                else if (s_board[x - 1][y] != " ")
                    x--;
            }
        }
        else if (c == 's' && x != s_board.size() - 1)
        {
            if (s_board[x][y] == " ")
            {
                if (s_board[x + 1][y] == " ")
                    x--;
                else if (s_board[x + 1][y] != " ")
                    x++;
            }
        }
        else if (c == 'a' && y != 0)
        {
            if (s_board[x][y] == " ")
            {
                if (s_board[x][y - 1] == " ")
                    y++;
                else if (s_board[x][y - 1] != " ")
                    y--;
            }
        }
        else if (c == 'd' && y != s_board[0].size() - 1)
        {
            if (s_board[x][y] == " ")
            {
                if (s_board[x][y + 1] == " ")
                    y--;
                else if (s_board[x][y + 1] != " ")
                    y++;
            }
        }
        cout << x << y << endl;

    } while (true);
}

place *name2placePtr(string plName)
{ // <<---- sad
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
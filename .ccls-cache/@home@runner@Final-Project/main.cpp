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

using namespace std;

/* class prototype */
class card;
class player;
class place;
class sell_object;
class board;
class game;

/* function prototype */
template<typename ClassObj>
ClassObj gen_tempObj();
template<typename T>
int checkIndex_vector(T, vector<T>);
template<typename T>
T selection_menu(vector<T>, vector<T>);

#include "Card.h"
#include "Player.h"
#include "Place.h"
#include "Board.h"
#include "Game.h"

int main() {
    std::cout << "Hello World!\n";

    // player test("test");
    // test.get_and_change_education(100);
    // test.get_and_change_workEXP(100);
    // gym a;
    // job_office b;
    // cout << b.req_route(test, &a, "Janitor") << endl;;

    board b;
    // b.print_board("Culture Center", 500);
    

    // vector<string> plName = {"Cluckers", "Gym", "Lousy Housing", "Market", "Fancy Housing", "Bank", "VexCorp", "Job Office", "Culture Center", "University", "Appliance Store"};
    // vector<string> sub = {" ", "return", "work"};
    // selection_menu<string>(plName, sub);

    // option -> game //map(1,2,3,4,5)
    

    game game_(10);
    game_.place_gui("Cluckers");
}

template<typename ClassObj>
ClassObj gen_tempObj() {
    ClassObj temp;
    return temp;
}

template<typename T>
int checkIndex_vector(T value, vector<T> vec) {
    for(int i = 0; i < vec.size(); i++) {
        if (vec[i] == value)
            return i;
    }
    return -1;
}

template<typename T>
T selection_menu(vector<T> choices, vector<T> addition) {
    //choices คือช้อยหลักที่จะให้แสดงผลได้เยอะๆ และแสดงด้านบน
    //addition จะแสดงด้านล่างและ มีแค่ 3 อันเท่านัน ห้ามขาดห้ามเกินถ้ามไม่มีใหแทนเป็น " " เช่ร {" ", "return", "work"}
    vector<vector<string>> s_board;
    int height = ceil(static_cast<float>(choices.size())/3) + 1;
    s_board.resize( height );
    for( auto &i : s_board )
        i.resize(3);

    // set data to s_board
    for(int i = 0; i < choices.size(); i++)
        s_board[i/3][i%3] = choices[i];
    if(choices.size() % 3 != 0) {
        for(int i = choices.size() % 3; i < 3; i++) 
            s_board[height-2][i] = " ";
    }
    for(int i = 0; i < 3; i++)
        s_board[height-1][i] = addition[i];


    // print board
    for(int i = 0; i < s_board.size(); i++) {
        if(i == s_board.size() - 1) cout << endl;
        for(int j = 0; j < 3; j++)
            cout << setw(25) << s_board[i][j];
        cout << endl;
    }
    // เหลือให้เลือกได้ด้วย w,a,s,d
    // กับรีเทิร์นค่าตัวเลือกกลับมา
    return "Work";
}
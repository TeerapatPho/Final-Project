#include <iostream>
#include <iomanip>
#include <string>
#include <vector>
#include <cmath>

using namespace std;

#include "Place.h"

#ifndef FUNCTION_H
#define FUNCTION_H

vector<place*> plList;

/* function prototype */
void setup();
template<typename ClassObj> ClassObj gen_tempObj(); // maybe delete
template<typename T> int checkIndex_vector(T, vector<T>);
template<typename T> T selection_menu(vector<T>, vector<T>);
place* name2placePtr(string plName);

void setup() {
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

template<typename ClassObj>
ClassObj gen_tempObj() {
    ClassObj temp;
    return temp;
}

template<typename T>
int checkIndex_vector(T value, vector<T> vec) {
    for(int i = 0; i < vec.size(); i++) {
        if (vec[i] == value) return i;
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


    // print board // อันนี้ลบก็ได้นะ แค่ให้แสดงหน้าตาเฉยๆว่าตัวเมนูจะมีหน้าตาเป็นไง
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

place* name2placePtr(string plName) { // <<---- sad
    for(auto &itr: plList) {
        if (itr->get_name() == plName) 
            return itr;
    }
    return nullptr;
}

#endif
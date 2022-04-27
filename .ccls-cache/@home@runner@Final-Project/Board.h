#ifndef BOARD_H
#define BOARD_H

#include <vector>
#include <string>

using namespace std;



class board
{
    int distance;
    vector<pair<int, int>> graph[12];
    int type;

public:
    board(int);
    ~board(); // destructor ประกาศว่าบอร์ดถูกลบแล้ว

    /* graph method (undirectional weight graph) */
    void addEdge(string, string, int);
    int **graph2matrix(vector<pair<int, int>> graph[]);
    int get_plIndex(string);
    int cal_distance(int **G, string, string);
    int cal_distance_template(string, string);

    void print_board(string, int); //ส่งสถานที่ปัจจุบันเข้ามา และพลังงานที่เหลือ
};

#endif
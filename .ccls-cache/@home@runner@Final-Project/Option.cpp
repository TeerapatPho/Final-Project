#include <iostream>
#include <string>
#include <vector>

using namespace std;

#ifndef OPTION_CPP
#define OPTION_CPP

#include "Option.h"
#include "Board.h"

option::option(int map, int round, int n) {
    map_no = map;
    max_round = round;
    n_player = n;
}

void option::set_maxRound(int n) {
    max_round = n;
}
void option::set_mapNo(int n) {
    map_no = n;
}
void option::set_nPlayer(int n) {
    n_player = n;
}

int option::get_maxRound() { return max_round; }
int option::get_mapNo() { return map_no; }
int option::get_nPlayer() { return n_player; }

void option::display_map() {
    board b(map_no);
    b.print_board("none", 0);
}

#endif
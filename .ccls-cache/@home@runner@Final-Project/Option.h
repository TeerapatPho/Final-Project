#ifndef OPTION_H
#define OPTION_H

class option {
    int map_no;
    int max_round;
    int n_player;
public:
    option(int = 1, int = 10, int = 1);

    void set_maxRound(int);
    void set_mapNo(int);
    void set_nPlayer(int);

    int get_maxRound();
    int get_mapNo();
    int get_nPlayer();

    void display_map();
};

#endif
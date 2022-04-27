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
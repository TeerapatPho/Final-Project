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

    vector<place*> x;
    if (map_no == 1 || map_no == 2 || map_no == 3) 
    {   
        x.push_back(new restaurant);
        x.push_back(new gym);
        x.push_back(new home);
        x.push_back(new market);
        x.push_back(new apartment);
        x.push_back(new bank);
        x.push_back(new tech_coop);
        x.push_back(new job_office);
        x.push_back(new art);
        x.push_back(new school);
        x.push_back(new it_store);
        x.push_back(new mall);
    }
    else if (map_no == 4)
    {  
        x.push_back(new tech_coop);
        x.push_back(new mall);
        x.push_back(new gym);
        x.push_back(new market);
        x.push_back(new home);
        x.push_back(new bank);
        x.push_back(new restaurant);
        x.push_back(new job_office);
        x.push_back(new apartment);
        x.push_back(new school);
        x.push_back(new it_store);
        x.push_back(new art);
    }
    plList = x;
}
void option::set_nPlayer(int n) {
    n_player = n;
}

int option::get_maxRound() { return max_round; }
int option::get_mapNo() { return map_no; }
int option::get_nPlayer() { return n_player; }

void option::display_map() {
    board b(map_no);
    cout << "Map No." << map_no << ": ";
    if(map_no == 1) cout << "Default";
    else if(map_no == 2) cout << "Leg Breaker";
    else if(map_no == 3) cout << "The Nano Tiny Town";
    else if(map_no == 4) cout << "Train is going to Korat";
    cout << endl;
    
    b.print_board("none", 0);
}
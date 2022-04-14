vector<card> gen_pEventCard() {
    vector<card> deck;
    deck.push_back(card("Traffic jamms","You have been stuck on the road for a long time. That's made you late for work."),0,0,0,-29);
    deck.push_back(card("Online gambling","Macau Macau Macau888 (>~<)!"),0,-1,0,-51);
    deck.push_back(card("How you doing?","This weekend you chatted up the wrong person at the bar.",-13,0,0,0));
    deck.push_back(card("Can I have some money, please?","I gave money for a lamp beggar that can ran after I walk away.",0,0,0,-20));
    deck.push_back(card("Fox stole a bag","The bag was stolen by D*r* Sw*p*r!",0,0,0,-38));
    deck.push_back(card("Enemies is coming","This weekend your toilet was broken and you had to buy a new one.",0,0,0,-65));
    deck.push_back(card("Too many development project","The government wants your money for a new road and some submarine.",0,0,0,-26));
    deck.push_back(card("Catch that Jerry","You found a Jerry under your bed this weekend. So, you decided to borrow Tom to help you.",0,0,0,-17));
    deck.push_back(card("I'd rather play game","Go study they said, it will make you more clever they said.",0,0,0,-27));
    deck.push_back(card("I'd rather go study","Play game they said, it will be relaxing they said.",0,0,0,-30));
    deck.push_back(card("One bite too many","You ate only MAMA in an eating competition this weekend before vomiting all over the place.",-13,0,0,0));
    deck.push_back(card("Under the ocean","You went to the aquarium to see the giant shark but it was already dead.",0,-5,0,-21));
    deck.push_back(card("Beach boy blues","You spent a nice relaxing dat at the beach eating ice-cream and reading some books. You didn't want to go back to the city.",0,14,0,-16));
    deck.push_back(card("Hike-ahoy!","This weekend you climbed the 5th lowest mountain in the world.",135,59,0,0));
    deck.push_back(card("Where's my bag?","You went to a grocery store and realize that you didn't take the bag with you. The store didn't give you a bag to you too!",30,-25,0,0));
    deck.push_back(card("","",0,0,0,0));
    deck.push_back(card("","",0,0,0,0));
    deck.push_back(card("Afforestation with friends","You spent the weekend participating in a Forest Garden Programs in Kenya."),0,6,0,24);
    deck.push_back(card("Oh! that's SOMCHAI","You met Somchai in your dream. Take all my luck and be wealthy he said",0,10,0,101));
    
    return deck;
}

vector<card> gen_rEventCard() {
    vector<card> deck;
    // event ของแต่ละรอบ
    // การ์ดที่โดนเหมือนกันทุกคน สร้างในนี้


    return deck
}

class game {
private:
    int max_round;
    int curr_round;
    queue<player *> player_q;
    board *play_board;
    vector<card> deck_p;
    vector<card> deck_r;
public:
    game(int);
    ~game();
    void change_round();
    void next_player_turn();
    void score_cal();
};

game::game(int max_round) {
    this->max_round = max_round;
    this->curr_round = 0;

    do {
        string name;
        getline(cin, name);
        if(name.compare("exit") == 0) break;
        player_q.push(new player(name));
    } while(true);

    play_board = new board;

    deck_p = gen_pEventCard();
    deck_r = gen_rEventCard();
}



game::~game() {
    cout << "-- destructer --" << endl;
    
    delete play_board;

    for(int i = 0; i < player_q.size(); i++) {
        player* temp = player_q.front();
        delete temp;
        player_q.pop();
    }
}

void game::change_round() {
    if (++curr_round == max_round+1) return;
    for(int i = 0; i < player_q.size(); i++) {
        // player_q.front()-> method โดนการ์ด event
        
        player* temp = player_q.front();
        player_q.pop();
        player_q.push(temp);
    }
}

void game::next_player_turn() {
    player* temp = player_q.front();
    player_q.pop();
    player_q.push(temp);

    // player_q.front()-> method โดนการ์ด event + situation //ตรงนี้คืองานของ Player.h
    

    // set player back to their home //ตรงนี้คืองานของ Board.h

    do {
        // select where to go and decrease energy //ตรงนี้คืองานของ Board.h
        // check energy >= 0

        // buy something or doing job or do transaction or exit buy interface or anything else
        // if buy check energy >= need and check money
    } while (player_q.front()->get_and_change_energy() >= 0);
}

void game::score_cal() {
    for(int i = 0; i < player_q.size(); i++) {
        player* temp = player_q.front();
        int score = temp->get_and_change_education() + temp->get_and_change_health() + temp->get_and_change_happiness() + temp->get_and_change_money();

        temp->display();
        cout << "------------------------------------" << endl;
        cout << "Score summary : " << score;
        
        player_q.pop();
        player_q.push(temp);
    }
}
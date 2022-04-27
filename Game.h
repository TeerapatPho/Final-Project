#ifndef GAME_H
#define GAME_H

vector<card> gen_pEventCard()
{ // generate personal card
    vector<card> deck;

    deck.push_back(card("Traffic jamms", "You have been stuck on the road for a long time. That's made you late for work. If only you have a elgooG Map", 0, 0, 0, -29));          // linked with elgooG Map
    deck.push_back(card("You is on fire", "Literally a fire on you!!, If only you have a Smoke Detector to protect you and Fire extinguisher to decrease damage.", 0, 0, 0, -29)); // linked with smoke and fire ext.
    deck.push_back(card("Fox stole a bag", "The bag was stolen by D*r* Sw*p*r! If only you have a CCTV.", 0, 0, 0, -38));                                                          // liked with CCTV
    deck.push_back(card("Online gambling", "Macau Macau Macau888 (>~<)!", 0, -1, 0, -51));
    deck.push_back(card("How you doing?", "This weekend you chatted up the wrong person at the bar.", -13, 0, 0, 0));
    deck.push_back(card("Can I have some money, please?", "I gave money for a lamp beggar that can ran after I walk away.", 0, 0, 0, -20));
    deck.push_back(card("Enemies is coming", "This weekend your toilet was broken and you had to buy a new one.", 0, 0, 0, -65));
    deck.push_back(card("Too many development project", "The government wants your money for a new road and some submarine.", 0, 0, 0, -25));
    deck.push_back(card("Catch that Jerry", "You found a Jerry under your bed this weekend. So, you decided to borrow Tom to help you.", 0, 0, 0, -17));
    deck.push_back(card("I'd rather play game", "Go study they said, it will make you more clever they said.", 0, 0, 0, -27));
    deck.push_back(card("I'd rather go study", "Play game they said, it will be relaxing they said.", 0, 0, 0, -30));
    deck.push_back(card("One bite too many", "You ate only MAMA in an eating competition this weekend before vomiting all over the place.", -13, 0, 0, 0));
    deck.push_back(card("Under the ocean", "You went to the aquarium to see the giant shark but it was already dead.", 0, -5, 0, -21));
    deck.push_back(card("Paper cut", "You ran into some paper trouble this weekend. The doctors at the ER said they had never seen such a deep paper cut.", 0, 0, 0, -23));
    deck.push_back(card("Say hi to old owner", "This weekend you met the gost who owns the room. He ask you to make merit for him.", 0, 0, 0, -13));
    deck.push_back(card("Beach boy blues", "You spent a nice relaxing dat at the beach eating ice-cream and reading some books. You didn't want to go back to the city.", 0, 14, 0, -16));
    deck.push_back(card("Hike-ahoy!", "This weekend you climbed the 5th lowest mountain in the world.", 135, 59, 0, 0));
    deck.push_back(card("Where's my bag?", "You went to a grocery store and realize that you didn't take the bag with you. The store didn't give you a bag to you too!", 30, -25, 0, 0));
    deck.push_back(card("Kids will be kids", "You were greatly entertained by a bus full of kidergareners this weekend.", 0, 33, 0, -39));
    deck.push_back(card("Online gambling", "Wow, you so lucky!", 0, 0, 0, 12));
    deck.push_back(card("Afforestation with friends", "You spent the weekend participating in a Forest Garden Programs in Kenya.", 0, 6, 0, 24));
    deck.push_back(card("Oh! that's SOMCHAI", "You met Somchai in your dream. Take all my luck and be wealthy he said", 0, 10, 0, 188));

    return deck;
}

vector<card> gen_rEventCard()
{ // round card
    vector<card> deck;

    // notification
    deck.push_back(card("! Crime alert !", "Now a pickpocket has escaped from the jail! Please beware your money and move it to the bank. Moreover, you can buy ... to protect yourself to!", 0, 0, 0, 0));
    // during crime
    deck.push_back(card("You were robbed", "The famous pickpocket has stolen your wallet (T^T).", 0, -100, 0, 0)); //ค่อยไปตั้งค่าเงินที่ขโมยใน player ทับไปอีกทีนึง
    // end
    deck.push_back(card("Crime end", "The polices have been able to catch the pickpocket, you can safly walk the streets agian.", 0, 0, 0, 0));

    deck.push_back(card("Time to pay rent!", "Do not forget or got debt ~", 0, 0, 0, 0));

    return deck;
}

class game
{
private:
    int max_round;
    int curr_round;
    queue<player *> player_q;
    board *play_board;

    vector<card> deck_p;
    vector<card> deck_r;

public:
    game(option);
    ~game();
    void change_round();
    void next_player_turn();
    void score_cal();
    void place_ui(string);
};

#endif
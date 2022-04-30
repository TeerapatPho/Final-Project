vector<card> gen_pEventCard()
{ // generate personal card
    vector<card> deck;

    deck.push_back(card("Traffic jamms", "You have been stuck on the road for a long time. That's made you late for work. If only you have a elgooG Map", 0, 0, 0, -29));          // linked with elgooG Map
    deck.push_back(card("You is on fire", "Literally a fire on you!!, If only you have a Smoke Detector to protect you and Fire extinguisher to decrease damage.", 0, 0, 0, -29)); // linked with smoke and fire ext.
    deck.push_back(card("Fox stole a bag", "The bag was stolen by D*r* Sw*p*r! If only you have a CCTV.", 0, 0, 0, -38));                                                          // liked with CCTV
    deck.push_back(card("Online gambling", "Macau Macau Macau888 (>~<)!", 0, -1, 0, -51));
    deck.push_back(card("How you doing?", "This weekend you chatted up the wrong person at the bar.", -13, 0, 0, 0));
    deck.push_back(card("Can I have some money", "I gave money for a lamp beggar that can ran after I walk away.", 0, 0, 0, -20));
    deck.push_back(card("Enemies is coming", "This weekend your toilet was broken and you had to buy a new one.", 0, 0, 0, -65));
    deck.push_back(card("Too many project", "The government wants your money for a new road and some submarine.", 0, 0, 0, -25));
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
    deck.push_back(card("Afforestation w/ frends", "You spent the weekend participating in a Forest Garden Programs in Kenya.", 0, 6, 0, 24));
    deck.push_back(card("Oh! that's SOMCHAI", "You met Somchai in your dream. Take all my luck and be wealthy he said", 0, 10, 0, 188));

    return deck;
}

vector<card> gen_rEventCard()
{ // round card
    vector<card> deck;

    // notification
    deck.push_back(card("! Crime alert !", "Now a burglar has escaped from the jail! Please beware your money and move it to the bank. Moreover, you can buy ... to protect yourself to!", 0, 0, 0, 0));
    // during crime
    deck.push_back(card("You were robbed", "The famous burglar has stolen your wallet (T^T).", 0, -100, 0, 0)); //ค่อยไปตั้งค่าเงินที่ขโมยใน player ทับไปอีกทีนึง
    // end
    deck.push_back(card("Crime end", "The polices have been able to catch the burglar, you can safly walk the streets agian.", 0, 0, 0, 0));

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

game::game(option opt)
{
    this->max_round = opt.get_maxRound();
    this->curr_round = 0;

    cout << "Enter Player's Name: " << endl;
    for(int i = 1; i <= opt.get_nPlayer(); i++) //expect for try catch;
    {
        string name;
        cout << "Player " << i << "'s name -> ";
        fflush(stdin);
        getline(cin, name); 
        player_q.push(new player(name));
    }

    play_board = new board(opt.get_mapNo());

    deck_p = gen_pEventCard();
    deck_r = gen_rEventCard();
}

game::~game()
{
    cout << "-- destructer --" << endl;

    delete play_board;

    for (int i = 0; i < player_q.size(); i++)
    {
        player *temp = player_q.front();
        delete temp;
        player_q.pop();
    }
}

void game::change_round()
{
    static int start = rand() % max_round + 2;
    static int stop = rand() % ((max_round < 5) ? (1) : (max_round / 5)) + start + 3;

    // cout << start << " " << stop << endl;

    if (++curr_round == max_round + 1)
        return;
    for (int i = 0; i < player_q.size(); i++)
    {
        if (curr_round - 1 == start)
            player_q.front()->get_card(deck_r[0]);
        else if (curr_round <= stop && curr_round >= start)
        {
            double rate; // rate โดน
            if (player_q.front()->get_and_change_home() == "Fancy Housing")
                rate = 1 / 3;
            else
                rate = 2 / 3;
            //ปืนช้อชไฟฟ้า
            if ((player_q.front()->get_bag())["Stun Gun"])
                rate -= 10 / 100;
            if (rand() % 100 + 1 < rate * 100)
                player_q.front()->get_card(deck_r[1]);
        }
        else if (curr_round + 1 == stop)
            player_q.front()->get_card(deck_r[2]);

        if (curr_round % 4 == 0)
        {
            player_q.front()->get_card(deck_r[3]);
            player_q.front()->get_and_change_debt((player_q.front()->get_and_change_home() == "Fancy Housing") ? (400) : (200));
        }
        else if (player_q.front()->get_and_change_debt() != 0) {
            player_q.front()->get_and_change_debt(
                static_cast<int>(
                    floor(player_q.front()->get_and_change_debt() * 0.03 )
                )
            );
        }
        if(player_q.front()->get_and_change_account_balance()!=0){
             player_q.front()->get_and_change_account_balance(
                static_cast<int>(
                    floor(player_q.front()->get_and_change_account_balance() * 0.05 )
                )
            );
        }

        // change to next
        player *temp = player_q.front();
        player_q.pop();
        player_q.push(temp);
    }
}

void game::next_player_turn()
{
    // reset player property
    player_q.front()->get_and_change_energy(-player_q.front()->get_and_change_energy() + 200);
    player_q.front()->get_and_change_current_place(player_q.front()->get_and_change_home());

    player *p = player_q.front();
    map<string, bool> bag = p->get_bag();

    if(bag["Loterry"]) {
        int chance = rand() % 10;
        if(chance == 1) {
            int win_lot = 500 + rand() % 300;
            p->get_card(card("You win the lottery!", "Congratulation ,you are the luckly one!", 0, 0, 0, win_lot));
        }
    }
    player_q.front()->set_bag("Lottery", false);
    
    if (curr_round > 1)
    {
        p->calculation_card_by_stat();
        int num = rand() % deck_p.size();
        p->get_card(deck_p[num]);
    }

    player_q.front()->change_fullness(false);
    
    system("clear");
    cout << "Current Player: " << p->get_name() << endl;
    p->print_card();

    do
    {

        string plname;
        do
        { // get where to go
            vector<string> plnames;
            for(auto &itr: plList)
                plnames.push_back(itr->get_name());
            plname = selection_menu<string>("Place", plnames, {" ", "Player Stat", " "}, [&]()->void{
                cout << "Current Player: " << p->get_name() << " | Current Round: " << curr_round << endl;
                play_board->print_board(p->get_and_change_current_place(), p->get_and_change_energy());
            });
            if (plname == "Player Stat") {
                system("clear");
                p->display();
                getch();
                continue;
            }
            if (play_board->get_plIndex(plname) == -1)
                continue;
            int distance = play_board->cal_distance_template(p->get_and_change_current_place(), plname); // get distance and do decrease energy
            // way to travel 
            if(play_board->get_board() != 3) { 
                if (player_q.front()->get_and_change_car_type() == "Walk")
                    p->get_and_change_energy(-distance * 10);
                else if (player_q.front()->get_and_change_car_type() == "Vexportation Pass")
                    p->get_and_change_energy(-distance * 8);
                else if (player_q.front()->get_and_change_car_type() == "Electric Scooter")
                    p->get_and_change_energy(-distance * 6);
                else if (player_q.front()->get_and_change_car_type() == "Nikola Electric")
                    p->get_and_change_energy(-distance * 3);
            }
            p->get_and_change_current_place(plname);

            break;
        } while (true);

        try {
            if (p->get_and_change_energy() <= 0) { // if energy is not enough
                throw *myex["lag_energy"];
            }
        }
        catch(exception& e) {
            cerr << e.what() << endl; 
            getch();
            break;
        } 

        // do thing in place;
        place_ui(plname); 
        // buy something or doing job or do transaction or exit buy interface or anything else
        // if buy check energy >= need and check money

    } while (player_q.front()->get_and_change_energy() >= 0);

    if(p->get_and_change_food_reserve() > 0 && p->get_fullness() == false) {
        p->change_fullness(true);
        p->get_and_change_food_reserve(-1);
    }

    if(bag["Football match"] || bag["Baseball game"] || bag["Mini concert"] || bag["Opera House"] || bag["Rocket to the Moon"] || bag["Picnic"]) {
        player_q.front()->set_bag("Football match", false);
        player_q.front()->set_bag("Baseball game", false);
        player_q.front()->set_bag("Mini concert", false);
        player_q.front()->set_bag("Opera House", false);
        player_q.front()->set_bag("Rocket to the Moon", false);
        player_q.front()->set_bag("Picnic", false);
    }

    player_q.pop();
    player_q.push(p);
}

void game::score_cal()
{
    vector<player*> highest_score; 
    int max_edu = 0, max_health = 0, max_happ = 0, max_mon = 0, max_item = 0, max_score = 0;
    string winner;
    for(int i = 0; i < 5; i++)
        highest_score.push_back(nullptr);

    for (int i = 0; i < player_q.size() ; i++) 
    {
        player *temp = player_q.front();
        map<string, bool> bag = temp->get_bag();
        int item = 0;
        for(auto &itr : bag) {
            if(itr.second) item++;
        }

        if(temp->get_and_change_education() > max_edu)
            highest_score[0] = temp;
        else if(temp->get_and_change_education() == max_edu)
            highest_score[0] = nullptr;
        if(temp->get_and_change_health() > max_health)
            highest_score[1] = temp;
        else if(temp->get_and_change_health() == max_health)
            highest_score[0] = nullptr;
        if(temp->get_and_change_happiness() > max_happ)
            highest_score[2] = temp;
        else if(temp->get_and_change_happiness() == max_happ)
            highest_score[0] = nullptr;
        if(temp->get_and_change_money() + temp->get_and_change_account_balance() > max_mon)
            highest_score[3] = temp;
        else if(temp->get_and_change_money() + temp->get_and_change_account_balance() == max_mon)
            highest_score[0] = nullptr;
        if(item >= max_item)
            highest_score[4] = temp;
        else if(item == max_item)
            highest_score[0] = nullptr;

        player_q.pop();
        player_q.push(temp);
    }
    
    for (int i = 0; i < player_q.size(); i++)
    {
        player *temp = player_q.front();
        int score = temp->get_and_change_education() + temp->get_and_change_health() + temp->get_and_change_happiness() + temp->get_and_change_money() + temp->get_and_change_account_balance() - 2*(temp->get_and_change_debt());

        map<string, bool> bag = temp->get_bag();
        for(auto &itr : bag) {
            if(itr.second) score += 100;
        }

        for (int i = 0; i < 5 ; i++) 
        {
            player *tmp = player_q.front();  
            if(tmp == highest_score[i]) score += 500;
        }

        if(score > max_score) {
            max_score = score;
            winner = temp->get_name();
        }
        
        system("clear");
        temp->display();
        cout << "------------------------------------" << endl;
        cout << "Score summary : " << score << endl;
        cout << "------------------------------------" << endl;
        getch();
        player_q.pop();
        player_q.push(temp);
    }
    system("clear");
    cout << MAG << "=v=.=v=.=v=.=v=.=v=.=v=.=v=.=v=.=v=.=v=.=v=.=v=.=v=.=v=.=v=.=v=.=v=.=v=.=v=.=v=.=v=.=v=.=v=.=v=.=v=.=v=.=v=.=v=.=\n"
         << reset;
    cout << CYN << "=================================================================================================================\n\n\n";
    cout << YEL << "!!! (> W <) " << reset << "The winner is " << RED << left << setw(10) << winner << reset << YEL << " (> v <)!!!\n\n\n" << reset << endl;
    cout << CYN << "=================================================================================================================\n"
         << reset;
    cout << MAG << "=v=.=v=.=v=.=v=.=v=.=v=.=v=.=v=.=v=.=v=.=v=.=v=.=v=.=v=.=v=.=v=.=v=.=v=.=v=.=v=.=v=.=v=.=v=.=v=.=v=.=v=.=v=.=v=.=\n\n\n"
         << reset << endl;
    getch();
}

void game::place_ui(string curr)
{
    if (curr == "Bank")
    {
        dynamic_cast<bank*>(name2placePtr(curr))->ui(player_q.front());
    }
    else if (curr == "University")
    {
        dynamic_cast<school*>(name2placePtr(curr))->ui(player_q.front());
    }
    else if (curr == "Job Office")
    {
        dynamic_cast<job_office*>(name2placePtr(curr))->ui(player_q.front());
    }
    else if (curr == "Lousy Housing")
    {
        dynamic_cast<home*>(name2placePtr(curr))->ui(player_q.front());
    }
    else if (curr == "Fancy Housing")
    {
        dynamic_cast<apartment*>(name2placePtr(curr))->ui(player_q.front());
    }
    else
    {   
        name2placePtr(curr)->ui(player_q.front(), curr);
    }
}
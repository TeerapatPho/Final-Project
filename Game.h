vector<card> gen_pEventCard() { // generate personal card
    vector<card> deck;
    deck.push_back(card("Traffic jamms","You have been stuck on the road for a long time. That's made you late for work.",0,0,0,-29));
    deck.push_back(card("Online gambling","Macau Macau Macau888 (>~<)!",0,-1,0,-51));
    deck.push_back(card("How you doing?","This weekend you chatted up the wrong person at the bar.",-13,0,0,0));
    deck.push_back(card("Can I have some money, please?","I gave money for a lamp beggar that can ran after I walk away.",0,0,0,-20));
    deck.push_back(card("Fox stole a bag","The bag was stolen by D*r* Sw*p*r!",0,0,0,-38));
    deck.push_back(card("Enemies is coming","This weekend your toilet was broken and you had to buy a new one.",0,0,0,-65));
    deck.push_back(card("Too many development project","The government wants your money for a new road and some submarine.",0,0,0,-25));
    deck.push_back(card("Catch that Jerry","You found a Jerry under your bed this weekend. So, you decided to borrow Tom to help you.",0,0,0,-17));
    deck.push_back(card("I'd rather play game","Go study they said, it will make you more clever they said.",0,0,0,-27));
    deck.push_back(card("I'd rather go study","Play game they said, it will be relaxing they said.",0,0,0,-30));
    deck.push_back(card("One bite too many","You ate only MAMA in an eating competition this weekend before vomiting all over the place.",-13,0,0,0));
    deck.push_back(card("Under the ocean","You went to the aquarium to see the giant shark but it was already dead.",0,-5,0,-21));
    deck.push_back(card("Paper cut","You ran into some paper trouble this weekend. The doctors at the ER said they had never seen such a deep paper cut.",0,0,0,-23));
    deck.push_back(card("Say hi to old owner","This weekend you met the gost who owns the room. He ask you to make merit for him.",0,0,0,-13)); 
    deck.push_back(card("Beach boy blues","You spent a nice relaxing dat at the beach eating ice-cream and reading some books. You didn't want to go back to the city.",0,14,0,-16));
    deck.push_back(card("Hike-ahoy!","This weekend you climbed the 5th lowest mountain in the world.",135,59,0,0));
    deck.push_back(card("Where's my bag?","You went to a grocery store and realize that you didn't take the bag with you. The store didn't give you a bag to you too!",30,-25,0,0));
    deck.push_back(card("Kids will be kids","You were greatly entertained by a bus full of kidergareners this weekend.",0,33,0,-39));
    deck.push_back(card("Online gambling","Wow, you so lucky!",0,0,0,12));
    deck.push_back(card("Afforestation with friends","You spent the weekend participating in a Forest Garden Programs in Kenya.",0,6,0,24));
    deck.push_back(card("Oh! that's SOMCHAI","You met Somchai in your dream. Take all my luck and be wealthy he said",0,10,0,101));
    
    return deck;
}

vector<card> gen_rEventCard() {
    vector<card> deck;
    
    // event ของแต่ละรอบ
    // การ์ดที่โดนเหมือนกันทุกคน สร้างในนี้

    // notification
    deck.push_back(c_card("! Crime alert !","Now a pickpocket has escaped from the jail! Please beware your money and move it to the bank.",0,0));
    // during crime
    deck.push_back(c_card("You were robbed","The famous pickpocket has stolen your wallet. (T^T)",-100,0)); //ค่อยไปตั้งค่าเงินที่ขโมยใน player ทับไปอีกทีนึง
    // end
    deck.push_back(c_card("Crime end","The polices have been able to catch the pickpocket, you can safly walk the streets agian.",0,0));
    
    return deck;
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
    void place_gui(string);
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
        //reset player property
        player_q.front()->get_and_change_energy(-player_q.front()->get_and_change_energy() + 200);
        player_q.front()->get_and_change_current_place(player_q.front()->get_and_change_home());
        
        // player_q.front()->get_card();
        /* crime event ภาเอง */
        
        // change to next player
        player* temp = player_q.front();
        player_q.pop();
        player_q.push(temp);
    }
}

void game::next_player_turn() {
    player* p = player_q.front();

    //อย่าลืมกันว่า round แรกห้ามหิว
    p->calculation_card_by_stat();
    srand(time(0)); // rand() /*ย้ายไปเมนหรือคอนตั๊ก*/
    int num = rand() % deck_p.size();
    p->get_card(deck_p[num]);
    
    do {

        string plname;
        do { // get where to go
            cout << "อยากไปไหนจ้ะน้องสาว : ";
            fflush(stdin);
            getline(cin, plname);
            if (play_board->get_plIndex(plname) == -1) continue;
            //play_board->cal_distance_template(p->get_and_change_current_place(), plname); //get distance and do decrease energy
            //above line just return distance // do something else
            p->get_and_change_current_place(plname);
            break;
        } while (true);
        if (p->get_and_change_energy() == 0) break; // check energy >= 0

        //do thing in place;
        place_gui();
        // buy something or doing job or do transaction or exit buy interface or anything else
        // if buy check energy >= need and check money
        
    } while (player_q.front()->get_and_change_energy() >= 0);

    player_q.pop();
    player_q.push(p);
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

void game::place_gui(string curr) {
    // หรือทำเป็น if else ดีหว่า ได้นะ5555
    // จะผ่าน *player ใน lambda ยังไงนะ;-;
    // https://www.geeksforgeeks.org/lambda-expression-in-c/ จะได้เขียนฟังก์ชันในฟังก์ชันได้ ไม่ต้องแยกเพิ่มอีกตัว ประมาณว่างั้นแหละ 
    if (curr == "Bank") {
         
    } else if (curr == "University") {
        
    } else if (curr == "Job Office") {
        vector<string> plName = {"Cluckers", "Gym", "Market", "Bank", "VexCorp", "University", "Appliance Store", "Mall"};
        string choice = selection_menu<string>(plName, {" ", "Return", " "});
        if (choice == "Return") return;

        vector<string> job_name;
        for(auto &itr : gen_tempObj<place>().get_jobs())
            job_name.push_back(itr.get_name());
        string jb_choice = selection_menu<string>(job_name, {" ", "Return", " "});
        int salary = gen_tempObj<job_office>().req_route(*(player_q.front()), choice, jb_choice);
        if(salary != -1) {
            player_q.front()->get_and_change_metier(jb_choice);
            player_q.front()->get_and_change_work_place(choice);
            player_q.front()->get_and_change_salary(salary);
        } else {
            // didnt meet requirement
        }
    } else if (curr == "Lousy Housing" || curr == "Fancy Housing") {
        if(player_q->get_and_change_home() == curr) {
            // relax btn //อันนี้ไม่ต้องใช้ lambda ก็ได้นะ มันทำงานแค่จุดเดียวอ่ะ
            // okkk
            if(player_q.front()->get_and_change_energy()>0){
                vector<int> stat = (curr == "Lousy Housing") ? (gen_tempObj<home>().get_relax_stat()) : (gen_tempObj<apartment>().get_relax_stat());
                player_q.front()->get_and_change_energy(); //เท่าไหร่ดีน้า ใช้จาก stat ได้ลเย
                player_q.front()->get_and_change_happiness(); //เท่าไหร่ดีน้า
            }
        } else {
            if (curr == "Lousy Housing") {/* do somthing*/}
            else {/* do somthing*/}
            // rent btn
        }
    } else {
        vector<sell_object> product = gen_tempObj<place>().get_sellObj(curr); // ตรงนี้ทำไว้แล้วสำหรับรับค่า product ช่าย
        vector<string> product_name(product.size());
        for(int i = 0; i < product.size(); i++) {
            product_name[i] = product[i].get_name();
            // cout << product_name[i] <<endl;
        }
        /*
            รับ product แล้ว เหลือทำหน้าร้านค้า 
        */
        string choice = selection_menu<string>(product_name, {
            " ",
            "Return",
            (curr != player_q.front()->get_and_change_work_place()) ? (" ") : ("Work")
        });
        if(choice == "Return") return;
        else if(choice == "Work") { player_q.front()->do_work(); }
    }
    
}
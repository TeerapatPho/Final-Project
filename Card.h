class card {
private : 
    string name;
    string desc;
    //int status;
    int health;
    int happiness;
    int energy;
    int money;
    //int round;
public :
    card(string="",string="",int=0,int=0,int=0,int=0);
    // ~card();
    string get_card_name() { return name; }
    // void set_card_name(string n) { this->name = n; }
    string get_card_desc() { return desc; }
    // void set_card_desc(string d) { this->desc = d; }
    vector<int> get_value() {    //get every value from each
        vector<int> v = {health, happiness, energy, money}; 
        return v;
    }
    // int ran_card() {
    //     int num;
    //     srand(time(0));
    //     num = rand() % 21; // 21 is cards number
    //     return num;
    // }
};

card::card(string name, string desc, int hea, int hap, int en, int mon) {
    this->name = name;
    this->desc = desc;
    this->health = hea;
    this->happiness = hap;
    this->energy = en;
    this->money = mon;
}

class c_card : public card{ // crime card
private :
    int period;
public :
    c_card(string="",string="",int=0,int=0);
    // ~c_card(); // ถ้ายังไม่ได้สร้างตัว method จริงของมัน หรือคิดไม่ออกก็คอมเม้นปิดเอาไว้นะฮะ มัน compile มิได้ ;-;
    void att_curr_player();
};

c_card::c_card(string n,string d,int hp,int sm) : card(n,d,0,hp,0,sm) {
    srand(time(0));
    int pr = (rand() % 3) + 1;
    this->period = pr;
}
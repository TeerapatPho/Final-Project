class card {
private : 
    //string category;
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
    int ran_card() {    //random card number for each play in each round
        int num;
        srand(time(0));
        num = rand() % num_card;
        return num;
    }
    //string get_card_cat() { return category; }
    string get_card_name() { return name; }
    string get_card_desc() { return desc; }
    vector<int> get_value() {    //get every value from each card เย้ ค้ายผมม
        vector<int> v = {health, happiness, energy, money}; //ขอบคุณคับบบ
        return v;
    }
};

//แล้ว status คือไรอ่ะ น่าจะไม่ได้ใช้หรือเปล่าหว่า ctrl+/
//ดูว่าเป็นการ์ดที่ต้องสุ่มทุกตามั้ยย แบบที่มันหักเงินเรามั่วๆอะ ถ้าจะไม่ใช่จะเรียกให้ออกจาสถานการณ์เอาไม่รวมอยู่ในตัวสุ่มอะ หรือคสรทำแยกกันไปเลย
// คิดว่างั้น ต้องกลับไปใช้ ป่ะ หรือว่าเอาออกไปหมดเลย omg รส.ทรงพลัง 5555555555
card::card(string name, string desc, int hea, int hap, int en, int mon) {
    this->name = name;
    this->desc = desc;
    this->health = hea;
    this->happiness = hap;
    this->energy = en;
    this->money = mon;
}

class situation_card : card { //อันนี้อ่อที่หมายถึง ถ้าไม่ใช่การ์ดอีเวนท์น่ะ อืมมม.... คิดมะออก เก็บไว้ก่อน 55555
public :
    situation_card(); //จัดไป 555555555
    ~situation_card();
};
//ซํมมอนน้องกลับมา 55555555555 ลืมม 55555555555 เราไปประกาศอาเรย์ในเมนเลยได้มั้ยนะ โอเคคับบ อ๋าาาา โอเคคค
//แแต่เราจะประกาศเป็น vector แทนนะ เหมือน Array ที่ปรับขนาดได้มากกว่า ถ้า singly ll จะใช้ forward_list 
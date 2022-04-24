vector<card> generate_situation_card(){
    vector<card> situation_card_deck;
    situation_card_deck.push_back(card("Hungry!","You forgot to eat meal, Your energy have been decrease.",0,0,-15,0)); 
    situation_card_deck.push_back(card("Are you serious?","You are stressfull, Your health and energy have been decrease.",-10,0,-5,0)); 
    situation_card_deck.push_back(card("Sick Stomach","You have an upset stomach, you must go to the hospital.",0,0,-10,-45));
    //situation_card.push_back(card("","You have an upset stomach, you must go to the hospital.",0,0,0,-40));
//
    return situation_card_deck;
} 

class player { // พวกล็อตเตอรี่กับตู้เย็นและผักแช่แข็งทั้งหลายกับพวกสัตว์เลี้ยง และอื่นๆ ถ้ามีก็ต้องมีกระเป๋าเก็บของพวกนี้ด้ว
private:
    string name;//ชื่อ
    string metier; //อาชีพ
    string work_place; //สถานที่ทำงาน
    string current_place;//สถานที่ปัจจุบัน
    string home; //ที่พัก
    string car_type;
    int education; //การศึกษา
    int work_EXP; //ประสบการณ์ทำงาน
    int health; //สุขภาพ
    int money; //เงิน
    int debt; //หนี้
    int happiness; // ความสุข
    bool fullness; //ความอิ่ม
    int energy; //พลังงานจัย
    int salary; //เงินเดือน
    int account_balance;//เงินในบัญชี
    map<string,bool> bag; //ตรงกระเป๋าทำเป็น dict มั้ยแล้วเก็บเป็นชื่อคู่กับ bool(0,1) เช็คว่ามีหรือไม่มี  
public:
    player(string=""); //รับชื่อผู้เล่น
    // ~player();
    //get and change ถ้าไม่ได้ส่งค่าเข้ามาจะเป็นการ return ค่าปัจจุบันกลับไป แต่ถ้าส่งค่าเข้ามาจะเป็นการเปลี่ยน/บวกข้อมูลแล้ว return กลับไป
    string get_and_change_metier(string="");
    string get_and_change_work_place(string="");
    string get_and_change_current_place(string="");
    string get_and_change_home(string="");
    string get_and_change_car_type(string="");
    int get_and_change_education(int=0);  
    int get_and_change_workEXP(int=0);
    int get_and_change_debt(int=0);
    int get_and_change_money(int=0);
    int get_and_change_health(int=0);
    int get_and_change_happiness(int=0);
    int get_and_change_fullness(int=0);
    int get_and_change_energy(int=0);
    int get_and_change_salary(int=0);
    int get_and_change_account_balance(int=0);
    map<string, bool> get_bag();
    void phone_buying(int); // สำหรับ player ที่มีโทรศัพท์มือถือ ส่งราคาสินค้า(แบบไม่ติดลบ) 
    //int bag_check(string);
    void display();
    void get_card(card);
    void calculation_card_by_stat();
    void add_item(string);

    void do_work();
}; 
player::player(string name_input){ 
  name = name_input; 
  metier = "None"; 
  work_place = "None";
  current_place = "None";
  car_type = "Walk";
  education = 0; // max = 700;
  work_EXP =  0; // max = {0, 100, 200, 400, 800, 1600, 3200, 6400}; -> 10 energy/ 1 tap/ 12 exp
  health = 200; // max = 2000
  money = 200; 
  debt = 0;
  happiness = 200;
  fullness = false;
  energy = 200;
  salary = 0;
  account_balance = 0;
  //set default bag ในนี้ -> all 0 (false)
}

string player::get_and_change_metier(string metier_input){
  if(metier_input != "") metier = metier_input; 
  return metier;
}
string player::get_and_change_work_place(string work_place_input){
  if(work_place_input != "") work_place = work_place_input;
  return work_place;
}
string player::get_and_change_current_place(string current_place_input){
  if(current_place_input != "") current_place = current_place_input;
  return current_place;
}
string player::get_and_change_home(string home_input) {
    if(home_input != "") home = home_input;
    return home;
}
string player::get_and_change_car_type(string car_input) {
    if(car_input != "") car_type = car_input;
    return car_type;
}
int player::get_and_change_education(int education_input){
  education += education_input;
  if(education<0) education=0;
  return education;
}
int player::get_and_change_workEXP(int work_EXP_input){
  work_EXP += work_EXP_input; 
  return work_EXP;
}
int player::get_and_change_debt(int debt_input){
  debt += debt_input; 
  if(debt<0) debt = 0;
  return debt;
}
int player::get_and_change_money(int money_input){
  money += money_input; 
  if(money<0) money = 0;
  return money;
}
int player::get_and_change_health(int health_input){
  health += health_input;
  if(health<0) health = 0;
  return health;
}
int player::get_and_change_happiness(int happiness_input){
  happiness += happiness_input; 
  if(happiness<0) happiness = 0;
  return happiness;
}
int player::get_and_change_fullness(int fullness_input){
  fullness += fullness_input;
  if(fullness<0) fullness = 0;
  return fullness;
}
int player::get_and_change_energy(int energy_input){
  energy += energy_input;
  if(energy<0) energy = 0;
  return energy;
}
int player::get_and_change_salary(int salary_input){
  salary = salary_input; 
  if(salary<0) salary = 0;
  return salary;
}
int player::get_and_change_account_balance(int account_balance_input){
  account_balance += account_balance_input;
  return account_balance;
}
map<string, bool> player::get_bag() {
    return bag;
}

void player::display(){
  cout<<"Name : "<<name<<endl;
  cout<<"Meiter : "<<metier<<endl;
  cout<<"Work Place : "<<work_place<<endl;
  cout<<"Current Place : "<<current_place<<endl;
  cout<<"Edcutaion : "<<education<<endl;
  cout<<"Work Experience : "<<work_EXP<<endl;
  cout<<"Health : "<<health<<endl;
  cout<<"Balance : "<<money<<endl;
  cout<<"Debt : "<<debt<<endl;
  cout<<"Happiness : "<<happiness<<endl;
  cout<<"Fullness : "<<fullness<<endl;
  cout<<"Energy : "<<energy<<endl;
  cout<<"Salary : "<<salary<<endl;
  cout<<"Account Balance : "<<account_balance<<endl;
}

void player::get_card(card card_input){ 
  vector<int> status = card_input.get_value();
  cout << card_input.get_card_name() << endl;
  cout << card_input.get_card_desc() << endl;
  get_and_change_energy(status[2]);
  get_and_change_health(status[0]);
  get_and_change_money(status[3]);
  get_and_change_happiness(status[1]);
  cout << "================================" << endl;
}
void player::calculation_card_by_stat(){
  vector<card> situation_card_deck = generate_situation_card();
  if(!fullness) get_card(situation_card_deck[0]);
  if(happiness < 100) get_card(situation_card_deck[1]);
  if(health < 100) get_card(situation_card_deck[2]);
}
/*int player::bag_check(string check_obj){
    return bag.find(check_obj);
}*/
void player::phone_buying(int cost){ 
    //ถ้าเป็น try จะ return bool กลับมาไม่ได้นะ ถ้าจะเอาผลการชำระเงินไปใช้ต่อต้องกลับไปใช้แบบเดิม
   try{
      if(account_balance + money < cost) throw cost - money - account_balance;
      if(money > cost) money -= cost;
      else{
        money = 0;
        account_balance -= cost-money;
      }
      cout << "Payment successful :)" << endl;
    }
   catch (int money_need){
      cout << "You need " << money_need << " dollar more!"<<endl;
   }
}
void player::add_item(string item_name){ 
  bag.at(item_name) = true; //https://stackoverflow.com/questions/4527686/how-to-update-stdmap-after-using-the-find-method
}

void player::do_work() {
    // (20 energy/ 1 tap/ 12 exp)
  try{
    if(energy<=0) throw;
    if(energy>=20){
        energy -= 20;
        money += salary*8;
        work_EXP += 12;
     }
     else { 
        money += static_cast<int>(floor(salary*8*static_cast<float>(energy/20)));
        work_EXP += static_cast<int>(floor(12*static_cast<float>(energy/20)));
        if (bag["Notebook"]) money += 4; 
        energy = 0;
     } 
     cout << "Work work work!" << endl;
  }
  catch (...){
    cout << "You not have energy! go home and recharge your energy."<< endl;
  }
   
}
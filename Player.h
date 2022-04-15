vector<card> some_func() {
    vector<card> situation_card_deck;

    situation_card_deck.push_back(card("Hungry!","You forgot to eat meal, Your energy have been decrease.",0,0,-15,0)); //0 fullness
    situation_card_deck.push_back(card("Are you serious?","You are stressfull, Your health and energy have been decrease.",-10,0,-5,0)); 
    situation_card_deck.push_back(card("Sick Stomach","You have an upset stomach, you must go to the hospital.",0,0,0,-45)); //2 health
    //situation_card.push_back(card("","You have an upset stomach, you must go to the hospital.",0,0,0,-40));

    return situation_card_deck;
}

class player { // พวกล็อตเตอรี่กับตู้เย็นและผักแช่แข็งทั้งหลายกับพวกสัตว์เลี้ยง และอื่นๆ ถ้ามีก็ต้องมีกระเป๋าเก็บของพวกนี้ด้วย
private:
    string name;//ชื่อ
    string metier; //อาชีพ
    string work_place; //สถานที่ทำงาน
    string current_place;//สถานที่ปัจจุบัน
    int education; //การศึกษา
    int work_EXP; //ประสบการณ์ทำงาน
    int health; //สุขภาพ
    int money; //เงิน
    int debt; //หนี้
    int happiness; // ความสุข
    int fullness; //ความอิ่ม
    int energy; //พลังงานจัย
    int salary; //เงินเดือน
    int account_balance;//เงินในบัญชี
    int stress; //ความเครียด
    
public:
    player(string=""); //รับชื่อผู้เล่น
    ~player();
    //get and change ถ้าไม่ได้ส่งค่าเข้ามาจะเป็นการ return ค่าปัจจุบันกลับไป แต่ถ้าส่งค่าเข้ามาจะเป็นการเปลี่ยน/บวกข้อมูลแล้ว return กลับไป
    string get_and_change_metier(string="");
    string get_and_change_work_place(string="");
    string get_and_change_current_place(string="");
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
    int get_and_change_stress(int=0);
    void display(); //สำหรับแสดงผลเพื่อดูว่าค่าที่บันทึกถูกมั้ย
    void get_card(card);
    void calculation_card_by_stat();
};

player::player(string name_input){ 
  name = name_input; 
  metier = "None"; 
  work_place = "None";
  current_place = "None";
  education = 0;
  work_EXP =  0;
  health = 0;
  money = 200;
  debt = 0;
  happiness = 100;
  fullness = 100;
  energy = 100;
  salary = 0;
  account_balance = 0;
}
player::~player(){
  cout << "Player " << name << "has been deleted" << endl;
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
int player::get_and_change_education(int education_input){
  education += education_input;
  if(education<0) education=0;
  return education;
}
int player::get_and_change_workEXP(int work_EXP_input){\
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
int player::get_and_change_stress(int stress_input){
  stress += stress_input;
  if(stress<0) stress=0;
  return stress;
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
  vector<card> situation_card_deck = some_func();
  if(fullness<80) get_card(situation_card_deck[0]);
  if(happiness<70) get_card(situation_card_deck[1]);
  if(health<70) get_card(situation_card_deck[2]);
}

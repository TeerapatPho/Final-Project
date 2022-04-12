class player {
private:
    string name;//ชื่อ
    string metier; //อาชีพ
    string work_place; //สถานที่ทำงาน
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
    
public:
    player(string=""); //เรียงตามข้อมูลใน private
    ~player();
    //get and change ถ้าไม่ได้ส่งค่าเข้ามาจะเป็นการ return ค่าปัจจุบันกลับไป แต่ถ้าส่งค่าเข้ามาจะเป็นการเปลี่ยน/บวกข้อมูลแล้ว return กลับไป
    string get_and_change_metier(string="");
    string get_and_change_work_place(string="");
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
    void display(); //สำหรับแสดงผลเพื่อดูว่าค่าที่บันทึกถูกมั้ย
};
player::player(string name_input){ //prototype กับ ฟงัก์ชันจริงพารามิเตอร์ไม่ตรงกัน
  name = name_input; // แล้วตรง prototype เอ่อออ แต่เรากำหนดค่า defualt ไว้แล้วไม่ได้หรอ;-; โอเคค
  metier = "None"; //<--- กำหนดอย่างงี้เลยก็ได้ ก็รับแค่ตัวเดียวพอ กำหนดได้แต่สุดท้ายก็ต้องมากำหนดค่าลงตัวแปรอีกทีนึง
  work_place = "None";
  education = 0;
  work_EXP =  0;
  health = 0;
  money = 200;
  debt = 0;
  happiness = 0;
  fullness = 100;
  energy = 100;
  salary = 0;
  account_balance = 0;
    //มันเป็นค่าที่ส่งเข้ามาแหละ แต่ถ้าดูจากโปรโตไทป์มันรับมา 10 กว่าค่า แต่พอดูโปรโทไทป์เสร็จ มันจะมาตรงนี้ พอเห็นแค่ค่าเดียวก็ error มั้งนะ
} // อันนี้ไม่ใช่ค่าที่แบบส่งเข้ามาหรอ อ่ออออออออ ก็คือต้องรับมาทุกตัวเลยใช่มะ ไม่จำเป็นฮะ
player::~player(){
  
}
string player::get_and_change_metier(string metier_input){
  if(metier_input != "") metier = metier_input; //พวกนี้อย่าลืมกันค่าติดลบด้วยนะ
  return metier; //โอเคค
}
string player::get_and_change_work_place(string work_place_input){
  if(work_place_input != "") work_place = work_place_input;
  return work_place;
}
int player::get_and_change_education(int education_input){
  education += education_input;
  return education;
}
int player::get_and_change_workEXP(int work_EXP_input){
  work_EXP += work_EXP_input;
  return work_EXP;
}
int player::get_and_change_debt(int debt_input){
  debt += debt_input;
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
  return salary;
}
int player::get_and_change_account_balance(int account_balance_input){
  account_balance += account_balance_input;
  return account_balance;
}
void player::display(){
  cout<<"Name : "<<name<<endl;
  cout<<"Meiter : "<<metier<<endl;
  cout<<"Work Place : "<<work_place<<endl;
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

// ได้ๆ ตรง constructer แบบเราอยากให้ส่งชื่อเข้ามาละบันทึกชื่ออย่างเดียวแบบนี้เราเขียนถูกมั้ยนะ
//ทำให้เก็บเงินเดือนได้หน่อย น่าจะต้องเก็บสถานที่ทำงานด้วย
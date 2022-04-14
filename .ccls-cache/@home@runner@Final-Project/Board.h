#define size 18
class board { 
//board เพิ่ม method รับค่าตำแหน่งเริ่มต้น และตำแหน่งสุดท้ายมาคำนวณพลังงานที่ใช้
//เก็บข้อมูลของระยะทางระหว่างแต่ละสถานที่ลงใน class board ด้วย
//เก็บ obj ของแต่ละที่ไว้ในรูปแบบ map <string, place> โดยที่ string เป็นชื่อสถานที่ .get_name() และ place เป็น class place
//https://www.cplusplus.com/reference/map/map/ อันนี้เว็บสำหรับดูวิธีใช้ map
    int distance;
public:
    board();
    ~board(); // destructor ประกาศว่าบอร์ดถูกลบแล้ว
    int table_lenght=110;
    void print_board(string="home");//ส่งสถานที่ปัจจุบันเข้ามา
    int cal_distance(string,string);
};

board::board() {
    cout<<"Board Constructor"<<endl;
}

board::~board(){
    cout<<"Destructed Board"<<endl;
}

/*int board::cal_distance(string,string){
  
}*/

void board::print_board(string present_place){  
  switch(present_place){ 
    
    case "restaurant":
      for(int i=0; i<table_lenght;i++) cout << "=";
      cout<<endl;
      cout<<"|    restaurant    |          |       gym        |          |       home       |          |      market      |"<<endl;
      cout<<"|        x         |          |                  |          |                  |          |                  |"<<endl;
      for(int i=0; i<table_lenght;i++) cout << "=";
      cout<<endl;
      cout<<"|       mall       |                         Energy :"<<this->get_and_change_energy();
      cout<<"                                     |     apartment    |"<<endl;
      cout<<"|                  |                                                                      |                  |"<<endl;
      cout<<"====================                                                                      ===================="<<endl;
      cout<<"|     it store     |                  Now you are at "<<present_place;
      cout<<"                                     |       bank       |"<<endl;
      cout<<"|                  |                                                                      |                  |"<<endl;
      for(int i=0; i<table_lenght;i++) cout << "=";
      cout<<endl;
       cout<<"|      school      |          |       art        |          |    job office    |          |     tech coop    |"<<endl;
      cout<<"|                  |          |                  |          |                  |          |                  |"<<endl;
      for(int i=0; i<table_lenght;i++) cout << "=";
      cout<<endl;
      break;

    case "gym" :
      for(int i=0; i<table_lenght;i++) cout << "=";
      cout<<endl;
      cout<<"|    restaurant    |          |       gym        |          |       home       |          |      market      |"<<endl;
      cout<<"|                  |          |        x         |          |                  |          |                  |"<<endl;
      for(int i=0; i<table_lenght;i++) cout << "=";
      cout<<endl;
      cout<<"|       mall       |                         Energy :"<<this->get_and_change_energy();
      cout<<"                                     |     apartment    |"<<endl;
      cout<<"|                  |                                                                      |                  |"<<endl;
      cout<<"====================                                                                      ===================="<<endl;
      cout<<"|     it store     |                  Now you are at "<<present_place;
      cout<<"                                     |       bank       |"<<endl;
      cout<<"|                  |                                                                      |                  |"<<endl;
      for(int i=0; i<table_lenght;i++) cout << "=";
      cout<<endl;
       cout<<"|      school      |          |       art        |          |    job office    |          |     tech coop    |"<<endl;
      cout<<"|                  |          |                  |          |                  |          |                  |"<<endl;
      for(int i=0; i<table_lenght;i++) cout << "=";
      cout<<endl;
      break;
    
    case "home":
      for(int i=0; i<table_lenght;i++) cout << "=";
      cout<<endl;
      cout<<"|    restaurant    |          |       gym        |          |       home       |          |      market      |"<<endl;
      cout<<"|                  |          |                  |          |            x     |          |                  |"<<endl;
      for(int i=0; i<table_lenght;i++) cout << "=";
      cout<<endl;
      cout<<"|       mall       |                         Energy :"<<this->get_and_change_energy();
      cout<<"                                     |     apartment    |"<<endl;
      cout<<"|                  |                                                                      |                  |"<<endl;
      cout<<"====================                                                                      ===================="<<endl;
      cout<<"|     it store     |                  Now you are at "<<present_place;
      cout<<"                                     |       bank       |"<<endl;
      cout<<"|                  |                                                                      |                  |"<<endl;
      for(int i=0; i<table_lenght;i++) cout << "=";
      cout<<endl;
       cout<<"|      school      |          |       art        |          |    job office    |          |     tech coop    |"<<endl;
      cout<<"|                  |          |                  |          |                  |          |                  |"<<endl;
      for(int i=0; i<table_lenght;i++) cout << "=";
      cout<<endl;
      break;
    
    case "market":
      for(int i=0; i<table_lenght;i++) cout << "=";
      cout<<endl;
      cout<<"|    restaurant    |          |       gym        |          |       home       |          |      market      |"<<endl;
      cout<<"|                  |          |                  |          |                  |          |        x         |"<<endl;
      for(int i=0; i<table_lenght;i++) cout << "=";
      cout<<endl;
      cout<<"|       mall       |                         Energy :"<<this->get_and_change_energy();
      cout<<"                                     |     apartment    |"<<endl;
      cout<<"|                  |                                                                      |                  |"<<endl;
      cout<<"====================                                                                      ===================="<<endl;
      cout<<"|     it store     |                  Now you are at "<<present_place;
      cout<<"                                     |       bank       |"<<endl;
      cout<<"|                  |                                                                      |                  |"<<endl;
      for(int i=0; i<table_lenght;i++) cout << "=";
      cout<<endl;
       cout<<"|      school      |          |       art        |          |    job office    |          |     tech coop    |"<<endl;
      cout<<"|                  |          |                  |          |                  |          |                  |"<<endl;
      for(int i=0; i<table_lenght;i++) cout << "=";
      cout<<endl;
      break;
    
    case "apartment":
      for(int i=0; i<table_lenght;i++) cout << "=";
      cout<<endl;
      cout<<"|    restaurant    |          |       gym        |          |       home       |          |      market      |"<<endl;
      cout<<"|                  |          |                  |          |                  |          |                  |"<<endl;
      for(int i=0; i<table_lenght;i++) cout << "=";
      cout<<endl;
      cout<<"|       mall       |                         Energy :"<<this->get_and_change_energy();
      cout<<"                                     |     apartment    |"<<endl;
      cout<<"|                  |                                                                      |         x        |"<<endl;
      cout<<"====================                                                                      ===================="<<endl;
      cout<<"|     it store     |                  Now you are at "<<present_place;
      cout<<"                                     |       bank       |"<<endl;
      cout<<"|                  |                                                                      |                  |"<<endl;
      for(int i=0; i<table_lenght;i++) cout << "=";
      cout<<endl;
       cout<<"|      school      |          |       art        |          |    job office    |          |     tech coop    |"<<endl;
      cout<<"|                  |          |                  |          |                  |          |                  |"<<endl;
      for(int i=0; i<table_lenght;i++) cout << "=";
      cout<<endl;
      break;
    
    case "bank":
      for(int i=0; i<table_lenght;i++) cout << "=";
      cout<<endl;
      cout<<"|    restaurant    |          |       gym        |          |       home       |          |      market      |"<<endl;
      cout<<"|                  |          |                  |          |                  |          |                  |"<<endl;
      for(int i=0; i<table_lenght;i++) cout << "=";
      cout<<endl;
      cout<<"|       mall       |                         Energy :"<<this->get_and_change_energy();
      cout<<"                                     |     apartment    |"<<endl;
      cout<<"|                  |                                                                      |                  |"<<endl;
      cout<<"====================                                                                      ===================="<<endl;
      cout<<"|     it store     |                  Now you are at "<<present_place;
      cout<<"                                     |       bank       |"<<endl;
      cout<<"|                  |                                                                      |         x        |"<<endl;
      for(int i=0; i<table_lenght;i++) cout << "=";
      cout<<endl;
       cout<<"|      school      |          |       art        |          |    job office    |          |     tech coop    |"<<endl;
      cout<<"|                  |          |                  |          |                  |          |                  |"<<endl;
      for(int i=0; i<table_lenght;i++) cout << "=";
      cout<<endl;
      break;
    
    case "tech_coop":
      for(int i=0; i<table_lenght;i++) cout << "=";
      cout<<endl;
      cout<<"|    restaurant    |          |       gym        |          |       home       |          |      market      |"<<endl;
      cout<<"|                  |          |                  |          |                  |          |                  |"<<endl;
      for(int i=0; i<table_lenght;i++) cout << "=";
      cout<<endl;
      cout<<"|       mall       |                         Energy :"<<this->get_and_change_energy();
      cout<<"                                     |     apartment    |"<<endl;
      cout<<"|                  |                                                                      |                  |"<<endl;
      cout<<"====================                                                                      ===================="<<endl;
      cout<<"|     it store     |                  Now you are at "<<present_place;
      cout<<"                                     |       bank       |"<<endl;
      cout<<"|                  |                                                                      |                  |"<<endl;
      for(int i=0; i<table_lenght;i++) cout << "=";
      cout<<endl;
       cout<<"|      school      |          |       art        |          |    job office    |          |     tech coop    |"<<endl;
      cout<<"|                  |          |                  |          |                  |          |         x        |"<<endl;
      for(int i=0; i<table_lenght;i++) cout << "=";
      cout<<endl;
      break;
    
    case "job_office":
      for(int i=0; i<table_lenght;i++) cout << "=";
      cout<<endl;
      cout<<"|    restaurant    |          |       gym        |          |       home       |          |      market      |"<<endl;
      cout<<"|                  |          |                  |          |                  |          |                  |"<<endl;
      for(int i=0; i<table_lenght;i++) cout << "=";
      cout<<endl;
      cout<<"|       mall       |                         Energy :"<<this->get_and_change_energy();
      cout<<"                                     |     apartment    |"<<endl;
      cout<<"|                  |                                                                      |                  |"<<endl;
      cout<<"====================                                                                      ===================="<<endl;
      cout<<"|     it store     |                  Now you are at "<<present_place;
      cout<<"                                     |       bank       |"<<endl;
      cout<<"|                  |                                                                      |                  |"<<endl;
      for(int i=0; i<table_lenght;i++) cout << "=";
      cout<<endl;
       cout<<"|      school      |          |       art        |          |    job office    |          |     tech coop    |"<<endl;
      cout<<"|                  |          |                  |          |        x         |          |                  |"<<endl;
      for(int i=0; i<table_lenght;i++) cout << "=";
      cout<<endl;
      break;
    
    case "art":
      for(int i=0; i<table_lenght;i++) cout << "=";
      cout<<endl;
      cout<<"|    restaurant    |          |       gym        |          |       home       |          |      market      |"<<endl;
      cout<<"|                  |          |                  |          |                  |          |                  |"<<endl;
      for(int i=0; i<table_lenght;i++) cout << "=";
      cout<<endl;
      cout<<"|       mall       |                         Energy :"<<this->get_and_change_energy();
      cout<<"                                     |     apartment    |"<<endl;
      cout<<"|                  |                                                                      |                  |"<<endl;
      cout<<"====================                                                                      ===================="<<endl;
      cout<<"|     it store     |                  Now you are at "<<present_place;
      cout<<"                                     |       bank       |"<<endl;
      cout<<"|                  |                                                                      |                  |"<<endl;
      for(int i=0; i<table_lenght;i++) cout << "=";
      cout<<endl;
       cout<<"|      school      |          |       art        |          |    job office    |          |     tech coop    |"<<endl;
      cout<<"|                  |          |         x        |          |                  |          |                  |"<<endl;
      for(int i=0; i<table_lenght;i++) cout << "=";
      cout<<endl;
      break;
    
    case "school":
      for(int i=0; i<table_lenght;i++) cout << "=";
      cout<<endl;
      cout<<"|    restaurant    |          |       gym        |          |       home       |          |      market      |"<<endl;
      cout<<"|                  |          |                  |          |                  |          |                  |"<<endl;
      for(int i=0; i<table_lenght;i++) cout << "=";
      cout<<endl;
      cout<<"|       mall       |                         Energy :"<<this->get_and_change_energy();
      cout<<"                                     |     apartment    |"<<endl;
      cout<<"|                  |                                                                      |                  |"<<endl;
      cout<<"====================                                                                      ===================="<<endl;
      cout<<"|     it store     |                  Now you are at "<<present_place;
      cout<<"                                     |       bank       |"<<endl;
      cout<<"|                  |                                                                      |                  |"<<endl;
      for(int i=0; i<table_lenght;i++) cout << "=";
      cout<<endl;
       cout<<"|      school      |          |       art        |          |    job office    |          |     tech coop    |"<<endl;
      cout<<"|         x        |          |                  |          |                  |          |                  |"<<endl;
      for(int i=0; i<table_lenght;i++) cout << "=";
      cout<<endl;
      break;
    
    case "it_store":
      for(int i=0; i<table_lenght;i++) cout << "=";
      cout<<endl;
      cout<<"|    restaurant    |          |       gym        |          |       home       |          |      market      |"<<endl;
      cout<<"|                  |          |                  |          |                  |          |                  |"<<endl;
      for(int i=0; i<table_lenght;i++) cout << "=";
      cout<<endl;
      cout<<"|       mall       |                         Energy :"<<this->get_and_change_energy();
      cout<<"                                     |     apartment    |"<<endl;
      cout<<"|                  |                                                                      |                  |"<<endl;
      cout<<"====================                                                                      ===================="<<endl;
      cout<<"|     it store     |                  Now you are at "<<present_place;
      cout<<"                                     |       bank       |"<<endl;
      cout<<"|         x        |                                                                      |                  |"<<endl;
      for(int i=0; i<table_lenght;i++) cout << "=";
      cout<<endl;
       cout<<"|      school      |          |       art        |          |    job office    |          |     tech coop    |"<<endl;
      cout<<"|                  |          |                  |          |                  |          |                  |"<<endl;
      for(int i=0; i<table_lenght;i++) cout << "=";
      cout<<endl;
      break;
    
    case "mall":
      for(int i=0; i<table_lenght;i++) cout << "=";
      cout<<endl;
      cout<<"|    restaurant    |          |       gym        |          |       home       |          |      market      |"<<endl;
      cout<<"|                  |          |                  |          |                  |          |                  |"<<endl;
      for(int i=0; i<table_lenght;i++) cout << "=";
      cout<<endl;
      cout<<"|       mall       |                         Energy :"<<this->get_and_change_energy();
      cout<<"                                     |     apartment    |"<<endl;
      cout<<"|         x        |                                                                      |                  |"<<endl;
      cout<<"====================                                                                      ===================="<<endl;
      cout<<"|     it store     |                  Now you are at "<<present_place;
      cout<<"                                     |       bank       |"<<endl;
      cout<<"|                  |                                                                      |                  |"<<endl;
      for(int i=0; i<table_lenght;i++) cout << "=";
      cout<<endl;
       cout<<"|      school      |          |       art        |          |    job office    |          |     tech coop    |"<<endl;
      cout<<"|                  |          |                  |          |                  |          |                  |"<<endl;
      for(int i=0; i<table_lenght;i++) cout << "=";
      cout<<endl;
      break;
      
  }
}
vector<place*> plList;

/* function prototype */
void setup();
template<typename ClassObj> ClassObj gen_tempObj(); // maybe delete
template<typename T> int checkIndex_vector(T, vector<T>);
template<typename T> T selection_menu(vector<T>, vector<T>);
place* name2placePtr(string plName);

void setup() {
    srand(time(0));

    plList.push_back(new restaurant);
    plList.push_back(new gym);
    plList.push_back(new home);
    plList.push_back(new market);
    plList.push_back(new apartment);
    plList.push_back(new bank);
    plList.push_back(new tech_coop);
    plList.push_back(new job_office);
    plList.push_back(new art);
    plList.push_back(new school);
    plList.push_back(new it_store);
    plList.push_back(new mall);
}

template<typename ClassObj>
ClassObj gen_tempObj() {
    ClassObj temp;
    return temp;
}

template<typename T>
int checkIndex_vector(T value, vector<T> vec) {
    for(int i = 0; i < vec.size(); i++) {
        if (vec[i] == value) return i;
    }
    return -1;
}

template<typename T>
T selection_menu(vector<T> choices, vector<T> addition) {
    //choices คือช้อยหลักที่จะให้แสดงผลได้เยอะๆ และแสดงด้านบน
    //addition จะแสดงด้านล่างและ มีแค่ 3 อันเท่านัน ห้ามขาดห้ามเกินถ้ามไม่มีใหแทนเป็น " " เช่ร {" ", "return", "work"}
    vector<vector<string>> s_board;
    int height = ceil(static_cast<float>(choices.size())/3) + 1;
    s_board.resize( height );
    for( auto &i : s_board )
        i.resize(3);

    // set data to s_board
    for(int i = 0; i < choices.size(); i++)
        s_board[i/3][i%3] = choices[i];
    if(choices.size() % 3 != 0) {
        for(int i = choices.size() % 3; i < 3; i++) 
            s_board[height-2][i] = " ";
    }
    for(int i = 0; i < 3; i++)
        s_board[height-1][i] = addition[i];


    // print board // อันนี้ลบก็ได้นะ แค่ให้แสดงหน้าตาเฉยๆว่าตัวเมนูจะมีหน้าตาเป็นไง
    for(int i = 0; i < s_board.size(); i++) { 
        if(i == s_board.size() - 1) cout << endl;
        for(int j = 0; j < 3; j++)
            cout << setw(25) << s_board[i][j];
        cout << endl;
    }
    // เหลือให้เลือกได้ด้วย w,a,s,d  
    // กับรีเทิร์นค่าตัวเลือกกลับมา
    return "Work";

}

place* name2placePtr(string plName) { // <<---- sad
    for(auto &itr: plList) {
        if (itr->get_name() == plName) 
            return itr;
    }
    return nullptr;
}

/*
    ใช้ wasd เลื่อน
    [a]  b   c
     d   e   f
     g   h 

     x   y   z
    ----------------------------
     a  [b]  c
     d   e   f
     g   h 

     x   y 
    ----------------------------
     a   b   c
    [d]  e   f
     g   h 

     x   y 
    ----------------------------
     a   b   c
     d   e   f
     g    

    [x]  y   

    คือ addition ส่วนมากจะใช้วางพวก "work", "return" และอื่นๆ มันจะแยกกับกลุ่มตัวเลือกด้านบน และจะอยู่ row สุดท้ายของ s_board เสมอ


	int x = 0, y = 0;
	char c;
	do {
		system("clear");
		for (int i = 0; i < s_board.size(); i++) {
			for(int j = 0; j < s_board[0].size(); j++) {
        //if(s_board[x][y] == " ") y--;
        if (x != i || y != j) cout << " " << s_board[i][j] << " ";
				else cout << "[" << s_board[i][j] << "]";

      }
      
			cout << endl; 
		}
		c = getch();
		if (c == 'w' && x != 0) 
    { 
      if(s_board[x][y]==" "){
              if(s_board[x-1][y]==" ") x++;
              else if(s_board[x-1][y]!=" ") x--;
          } 
    }
		else if (c == 's' && x != s_board.size() - 1) 
    { 
      if(s_board[x][y]==" "){
              if(s_board[x+1][y]==" ") x--;
              else if(s_board[x+1][y]!=" ") x++;
          } 
    }
		else if (c == 'a' && y != 0) 
    { 
      if(s_board[x][y]==" "){
              if(s_board[x][y-1]==" ") y++;
              else if(s_board[x][y-1]!=" ") y--;
          }
    }
		else if (c == 'd' && y != s_board[0].size()-1)      { 
      if(s_board[x][y]==" "){
              if(s_board[x][y+1]==" ") y--;
              else if(s_board[x][y+1]!=" ") y++;
          }  
    }  
		cout << x << y << endl;
		
	} while(true);

*/
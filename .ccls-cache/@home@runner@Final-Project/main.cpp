#include <iostream>
#include <iomanip>
#include <utility>
#include <string>
#include <vector>
#include <queue>
#include <map>
#include <random>
#include <exception>
#include <time.h>
#include <limits>

using namespace std;

/* class prototype */
class card;
class player;
class place;
class sell_object;
class board;
class game;

#include "Function.h"
#include "Card.h"
#include "Player.h"
#include "Place.h"
#include "Board.h"
#include "Game.h"
#include "Option.h"

int main() {
    setup();
    option opt;
    
    // splash page?

    // main menu
    do {
        string main_choice = selection_menu<string>({},{"Option", "Play", "Exit"});

        if (main_choice == "Exit") return 0; // or make ending page
        else if (main_choice == "Option") {
            string opt_choice = selection_menu<string>({"Select Map Number", "Set Max Round", "Set Player Number"},{" ", "Return", " "});
            cout << "Current map number: " << opt.get_mapNo();
            cout << " Max Play round: " << opt.get_maxRound();
            cout << " Player Number: " << opt.get_nPlayer() << endl;
            opt.display_map();
            if(opt_choice == "Return") continue;
            int x;
            cout << opt_choice << ": ";
            cin >> x;
            else if(opt_choice == "Select Map Number") {
                opt.set_mapNo(x);
            }
            else if(opt_choice == "Set Max Round") {
                opt.set_maxRound(x);
            }
            else if(opt_choice == "Set Player Number") {
                opt.set_nPlayer(x);
            }
        }
        else if (main_choice == "Play") {
            game game_(opt);
        }
    } while (true);
    
    
    game game_(10); // name + exit
    // game_.change_round();
    // game_.next_player_turn();

    game_.place_ui("Bank");

    // dynamic_cast<home*>(name2placePtr("Lousy Housing"))->ui(&test);
    // name2placePtr("Cluckers")->ui(&test, "Cluckers");
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
     g   h 

    [x]  y  //x y คืออะไรอะ

    คือ addition ส่วนมากจะใช้วางพวก "work", "return" และอื่นๆ มันจะแยกกับกลุ่มตัวเลือกด้านบน และจะอยู่ row สุดท้ายของ s_board เสมอ


	int x = 0, y = 0;
	char c;
	do {
		system("clear");
		for (int i = 0; i < s_board.size(); i++) {
			for(int j = 0; j < s_board[0].size(); j++) {
				if (x != i || y != j) cout << " " << choices[i][j] << " ";
				else cout << "[" << choices[i][j] << "]";
			}
			cout << endl;
		}
		c = getch();
		if (c == 'w' && x != 0) { x--; }
		else if (c == 's' && x != s_board.size() - 1) { x++; }
		else if (c == 'a' && y != 0) { y--; }
		else if (c == 'd' && y != s_board[0].size()-1) { y++; }
		cout << x << y << endl;
		
	} while(true);

*/
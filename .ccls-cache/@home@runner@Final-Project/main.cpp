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

#include "conio.h"
#include "Function.h"
#include "Game.h"
#include "Option.h"
#include "Color.h"

int main() {
    setup();
    option opt;
    
    // splash page?
    system("clear");       cout<<MAG<<"=v=.=v=.=v=.=v=.=v=.=v=.=v=.=v=.=v=.=v=.=v=.=v=.=v=.=v=.=v=.=v=.=v=.=v=.=v=.=v=.=v=.=v=.=v=.=v=.=v=.=v=.=v=.=v=.=\n"<<reset;  cout<<CYN<<"=================================================================================================================\n\n\n"<<reset;
        cout<<WHT<<"                                        "<<YEL<<">>>"<<reset<<"   Work-Life Balance Game!  "<<YEL<<"<<<    \n\n"<<reset;
cout<<"                  Use Key"<<RED<<"(W)"<<reset<<" to move Up, "<<RED<<"(S)"<<reset" to move Down, "<<RED<<"(A)"<<reset<<" to move Left and "<<RED<<"(D)"<<reset<<" to move Right\n\n\n";  cout<<CYN"=================================================================================================================\n"<<reset;
  cout<<MAG"=v=.=v=.=v=.=v=.=v=.=v=.=v=.=v=.=v=.=v=.=v=.=v=.=v=.=v=.=v=.=v=.=v=.=v=.=v=.=v=.=v=.=v=.=v=.=v=.=v=.=v=.=v=.=v=.=\n\n\n"<<reset<<endl;
    getch();
  
    // main menu
    do {
        string main_choice = selection_menu<string>({},{"Option", "Play", "Exit"});

        if (main_choice == "Exit") return 0; // or make ending page
        else if (main_choice == "Option") {
            cout << "Current map number: " << opt.get_mapNo();
            cout << " Max Play round: " << opt.get_maxRound();
            cout << " Player Number: " << opt.get_nPlayer() << endl;
            opt.display_map();
            string opt_choice = selection_menu<string>({"Select Map Number", "Set Max Round", "Set Player Number"},{" ", "Return", " "});
            if(opt_choice == "Return") continue;
            int x;
            cout << opt_choice << ": ";
            cin >> x;
            if(opt_choice == "Select Map Number") {
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
    
}
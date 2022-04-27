#include <iostream>
#include <queue>
#include <random>
#include <map>
#include <vector>

using namespace std;

// #ifndef GAME_CPP
// #define GAME_CPP

#include "Function.h"
#include "Board.h"
#include "Place.h"
#include "Card.h"
#include "Option.h"
#include "Player.h"
#include "Game.h"

game::game(option opt)
{
    this->max_round = opt.get_maxRound();
    this->curr_round = 0;

    cout << "type 'exit' to end typing player name." << endl;
    for(int i = 1; i <= opt.get_nPlayer(); i++) //expect for try catch;
    {
        string name;
        cout << "Player " << i << "'s name -> ";
        getline(cin, name);
        if (name.compare("exit") == 0) break;
        player_q.push(new player(name));
    }

    play_board = new board(opt.get_mapNo());

    deck_p = gen_pEventCard();
    deck_r = gen_rEventCard();
}

game::~game()
{
    cout << "-- destructer --" << endl;

    delete play_board;

    for (int i = 0; i < player_q.size(); i++)
    {
        player *temp = player_q.front();
        delete temp;
        player_q.pop();
    }
}

void game::change_round()
{
    static int start = rand() % max_round;
    static int stop = rand() % (max_round / 5) + start;

    if (++curr_round == max_round + 1)
        return;
    for (int i = 0; i < player_q.size(); i++)
    {
        // reset player property
        player_q.front()->get_and_change_energy(-player_q.front()->get_and_change_energy() + 200);
        player_q.front()->get_and_change_current_place(player_q.front()->get_and_change_home());

        if (curr_round - 1 == start)
            player_q.front()->get_card(deck_r[0]);
        else if (curr_round <= stop && curr_round >= start)
        {
            double rate; // rate โดน
            if (player_q.front()->get_and_change_home() == "Fancy Housing")
                rate = 1 / 3;
            else
                rate = 2 / 3;
            //ปืนช้อชไฟฟ้า
            if ((player_q.front()->get_bag())["Stun Gun"])
                rate -= 10 / 100;
            if (rand() % 100 + 1 < rate * 100)
                player_q.front()->get_card(deck_r[1]);
        }
        else if (curr_round + 1 == stop)
            player_q.front()->get_card(deck_r[2]);

        if (curr_round % 4 == 0)
        {
            player_q.front()->get_card(deck_r[3]);
            player_q.front()->get_and_change_debt((player_q.front()->get_and_change_home() == "Fancy Housing") ? (400) : (200));
        }
        if (player_q.front()->get_and_change_debt() != 0) {
            player_q.front()->get_and_change_debt(
                static_cast<int>(
                    floor(player_q.front()->get_and_change_debt() * 0.03 + player_q.front()->get_and_change_debt())
                )
            );
        }

        // change to next
        player *temp = player_q.front();
        player_q.pop();
        player_q.push(temp);
    }
}

void game::next_player_turn()
{
    player *p = player_q.front();
    map<string, bool> bag = p->get_bag();

    if(bag["Loterry"]) {
        int chance = rand() % 10;
        if(chance == 1) {
            int win_lot = 500 + rand() % 300;
            p->get_card(card("You win the lottery!", "Congratulation ,you are the luckly one!", 0, 0, 0, win_lot));
        }
    }
    
    if (curr_round > 1)
    {
        p->calculation_card_by_stat();
        int num = rand() % deck_p.size();
        p->get_card(deck_p[num]);
    }

    p->change_fullness(false);

    do
    {

        string plname;
        do
        { // get where to go
            cout << "อยากไปไหนจ้ะน้องสาว : ";
            fflush(stdin);
            getline(cin, plname);
            if (play_board->get_plIndex(plname) == -1)
                continue;
            int distance = play_board->cal_distance_template(p->get_and_change_current_place(), plname); // get distance and do decrease energy
            // way to travel
            if (player_q.front()->get_and_change_car_type() == "Walk")
                p->get_and_change_energy(-distance * 10);
            else if (player_q.front()->get_and_change_car_type() == "Vexportation Pass")
                p->get_and_change_energy(-distance * 8);
            else if (player_q.front()->get_and_change_car_type() == "Electric Scooter")
                p->get_and_change_energy(-distance * 6);
            else if (player_q.front()->get_and_change_car_type() == "Nikola Electric")
                p->get_and_change_energy(-distance * 3);

            p->get_and_change_current_place(plname);

            break;
        } while (true);
        if (p->get_and_change_energy() <= 0)
            break; // check energy >= 0

        // do thing in place;
        place_ui(plname); 
        // buy something or doing job or do transaction or exit buy interface or anything else
        // if buy check energy >= need and check money

    } while (player_q.front()->get_and_change_energy() >= 0);

    if(p->get_and_change_food_reserve() > 0 && p->get_fullness() == false) {
        p->change_fullness(true);
        p->get_and_change_food_reserve(-1);
    }

    player_q.pop();
    player_q.push(p);
}

void game::score_cal()
{
    for (int i = 0; i < player_q.size(); i++)
    {
        player *temp = player_q.front();
        int score = temp->get_and_change_education() + temp->get_and_change_health() + temp->get_and_change_happiness() + temp->get_and_change_money();

        map<string, bool> bag = temp->get_bag();
        /* ให้คะแนนชิ้นละ 100 
        for(auto ipr : bag) {
            
        }
*/

        temp->display();
        cout << "------------------------------------" << endl;
        cout << "Score summary : " << score;

        player_q.pop();
        player_q.push(temp);
    }
}

void game::place_ui(string curr)
{
    if (curr == "Bank")
    {
        dynamic_cast<bank*>(name2placePtr(curr))->ui(player_q.front());
    }
    else if (curr == "University")
    {
        dynamic_cast<school*>(name2placePtr(curr))->ui(player_q.front());
    }
    else if (curr == "Job Office")
    {
        dynamic_cast<job_office*>(name2placePtr(curr))->ui(player_q.front());
    }
    else if (curr == "Lousy Housing")
    {
        dynamic_cast<home*>(name2placePtr(curr))->ui(player_q.front());
    }
    else if (curr == "Fancy Housing")
    {
        dynamic_cast<apartment*>(name2placePtr(curr))->ui(player_q.front());
    }
    else
    {   
        name2placePtr(curr)->ui(player_q.front(), curr);
    }
}

// #endif
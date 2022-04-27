#include <iostream>
#include <string>
#include <vector>
#include <map>

using namespace std;

#include "Place.h"
#include "Player.h"

int job_office::check_requirement(player *p, string job_name, place *pl)
{
    vector<struct JOB> temp = pl->get_allJob();
    for (auto &itr : temp)
        if (itr.name == job_name)
            if (itr.req.workEXP <= p->get_and_change_workEXP() && itr.req.education <= p->get_and_change_education())
                return itr.salary;
    return -1;
}

void place::ui(player *p, string curr)
{
    do {
        vector<sell_object> product = name2placePtr(curr)->get_product(); // ตรงนี้ทำไว้แล้วสำหรับรับค่า product ช่าย
        vector<string> product_name;
        for (auto &itr: product)
            product_name.push_back(itr.get_name());

        map<string, bool> bag = p->get_bag();
    
        string choice = selection_menu<string>(product_name, {
            " ",
            "Return",
            (curr != p->get_and_change_work_place()) ? (" ") : ("Work")
        });
        if (choice == "Return")
            return;
        else if (choice == "Work")
            p->do_work();
        else {
            for(auto &itr : product) {
                if(itr.get_name() == choice) {
                    if(!p->buying(itr.get_cost())) break;
                    
                    bool check_item = false;
                    if(curr == "Appliance Store" || curr == "Mall") {
                        if(choice == "Salty Bag") {
                            int salty = rand() % 250;
                            salty *= (salty % 8 == 0) ? (-1) : (1);
                            p->get_and_change_money(salty);
                            cout << "You " << ((salty >= 0) ? ("got ") : ("loose ")) << salty << " from Salty Bag" << endl;
                        }
                        else check_item = bag[choice];
                    }
                    else if(curr == "Market") {
                        if(bag["Refrigerator"] == true) {
                            if(choice == "Food for 1 week" || choice == "Cleansing food for 1 week") {
                                if(p->get_and_change_food_reserve() + 1 <= 4) 
                                    p->get_and_change_food_reserve(1);
                                else {/* throw "Your Refrigerator is full!!"; */ check_item = true; }
                            }
                            else if(choice == "Food for 2 weeks") {
                                if(p->get_and_change_food_reserve() + 2 <= 4)
                                    p->get_and_change_food_reserve(2);
                                else {/* throw "Your Refrigerator is full!!"; */ check_item = true; }
                            }
                            else if(choice == "Food for 4 weeks") {
                                if(p->get_and_change_food_reserve() == 0)
                                    p->get_and_change_food_reserve(4);
                                else {/* throw "Your Refrigerator is full!!"; */ check_item = true; }
                            }
                        }
                        else if(bag["Refrigerator"] == false) { /* throw "Must bu Refrigerator first!!"; */ break; }
                    } 
                    else if(curr == "Culture Center")
                        
                    if(check_item == false) {// ต้องใส่ p->buying(itr.get_cost()) ด้วยป่ะ
                        vector<int> x = itr.get_return();
                        p->get_and_change_health(x[0]);
                        p->get_and_change_happiness(x[1]);
                        p->get_and_change_education(x[2]);
                        if(itr.get_eatable()) p->get_and_change_fullness(true);
                        p->get_and_change_energy(-itr.get_energyAmount());
                    }
                    break;
                }
            }
        }
    } while(true);
    
}

void home::ui(player* p) {
    do {
        if (p->get_and_change_home() == get_name())
        {
            string choice = selection_menu<string>({}, {
                "Relax",
                "Return",
                " "
            });
            if (choice == "Return") return;
            if (p->get_and_change_energy() > 0)
            {
                vector<int> stat = get_relax_stat();
                vector<string> furniture = {"Sofa, So good!", "Curtain", "Carpet", "Movie Poster", "Lemon Tree"};
                int n_item = 0;
                map<string, bool> bag = p->get_bag();
                for (auto &itr : furniture)
                {
                    if (bag[itr])
                        n_item++;
                }
                p->get_and_change_energy(-stat[0]);
                p->get_and_change_happiness(stat[1] + n_item * 2); // 2 happiness/item
            }
        }
        else
        {
            // rent btn
            cout << "Rent Cost: " << cost << endl;
            string choice = selection_menu<string>({}, {
                "Rent",
                "Return",
                " "
            });
            if (choice == "Return") return;
            else if(choice == "Rent") {
                if(!p->buying(cost)) continue;
                p->get_and_change_home(get_name());
            }
        }
    } while (true);
    
}

void apartment::ui(player* p) {
    do {
        if (p->get_and_change_home() == get_name())
        {
            string choice = selection_menu<string>({}, {
                "Relax",
                "Return",
                " "
            });
            if (choice == "Return") return;
            if (p->get_and_change_energy() > 0)
            {
                vector<int> stat = get_relax_stat();
                vector<string> furniture = {"Sofa, So good!", "Curtain", "Carpet", "Movie Poster", "Lemon Tree"};
                int n_item = 0;
                map<string, bool> bag = p->get_bag();
                for (auto &itr : furniture)
                {
                    if (bag[itr])
                        n_item++;
                }
                p->get_and_change_energy(-stat[0]);
                p->get_and_change_happiness(stat[1] + n_item * 2); // 2 happiness/item
            }
        }
        else
        {
            // rent btn
            cout << "Rent Cost: " << cost << endl;
            string choice = selection_menu<string>({}, {
                "Rent",
                "Return",
                " "
            });
            if (choice == "Return") return;
            else if(choice == "Rent") {
                if(!p->buying(cost)) continue;
                p->get_and_change_home(get_name());
            }
        }
    } while (true);
}

void bank::ui(player* p) {
    // work, deposit-withdraw
    do {
        int mon = p->get_and_change_money();
        int acc_mon = p->get_and_change_account_balance();
        
        vector<string> action = {"Deposit", "-100", "-All",
                                "Withdraw", "+100", "+All"};
        cout << "Money: " << p->get_and_change_money() << endl;
        cout << "Account Balance: " << p->get_and_change_account_balance() << endl;
        cout << "Debt Left: " << p->get_and_change_debt() << endl;
        
        string choice = selection_menu<string>(action, {
            (p->get_and_change_debt() != 0) ? ("Paid Debt") : (" "), 
            "Return", 
            (get_name() != p->get_and_change_work_place()) ? (" ") : ("Work")
        });
        if(choice == "Return") 
            return;
        else if (choice == "Work")
            p->do_work();
        else if (choice == "Deposit" || choice == "-100") {
            p->get_and_change_account_balance((mon >= 100) ? (100) : (mon));
            p->get_and_change_money((mon >= 100) ? (-100) : (-mon));
        }
        else if (choice == "-All") {
            p->get_and_change_account_balance(mon);
            p->get_and_change_money(-mon);
        }
        else if (choice == "Withdraw" || choice == "+100"){
            p->get_and_change_money((acc_mon >= 100) ? (100) : (acc_mon));
            p->get_and_change_account_balance((acc_mon >= 100) ? (-100) : (-acc_mon));
        }
        else if (choice == "+All") {
            p->get_and_change_money(acc_mon);
            p->get_and_change_account_balance(-acc_mon);
        }
        else if (choice == "Paid Debt") {
            p->buying(p->get_and_change_debt());
        }
        
    } while (true);
}

void job_office::ui(player *p) {
    do {
        vector<string> plName = {"Cluckers", "Gym", "Market", "Bank", "VexCorp", "University", "Appliance Store", "Mall"};
        string choice = selection_menu<string>(plName, {" ", "Return", " "});
        if (choice == "Return")
            return;
    
        vector<string> job_name;
        for (auto &itr : get_allJob())
            job_name.push_back(itr.name);
        string jb_choice = selection_menu<string>(job_name, {" ", "Return", " "});
        int salary = check_requirement(p, jb_choice, name2placePtr(choice));
        if (salary != -1) // try catch?
        {
            p->get_and_change_metier(jb_choice);
            p->get_and_change_work_place(choice);
            p->get_and_change_salary(salary);
        }
        else
        {
            // didnt meet requirement
        }
    } while (true);
    
}

void school::ui(player* p) {
    // work and learn
    do {
        string choice = selection_menu<string>({}, {
            (p->get_and_change_education()%100 == 0 && p->get_and_change_education() < 700) ? ("Paid Tuition Fee") : ("Learn"),
            "Return",
            (get_name() != p->get_and_change_work_place()) ? (" ") : ("Work")
        });
        if (choice == "Return")
            return;
        else if (choice == "Work")
            p->do_work();
        else if (choice == "Paid Tuition Fee") {
            int fee;
            int edu = p->get_and_change_education();
            if (edu == 100) {
                fee = 50;
            } else if (edu == 200) {
                fee = 100;
            } else if (edu == 300) {
                fee = 150;
            } else if (edu == 400) {
                fee = 200;
            } else if (edu == 500) {
                fee = 250;
            } else if (edu == 600) {
                fee = 250;
            }
            p->buying(fee);
        }
        else if (choice == "Learn") {
            p->get_and_change_education(20);
            p->get_and_change_energy(-30);
        }
    } while (true);
}
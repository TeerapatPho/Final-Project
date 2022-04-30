class sell_object
{
private:
    string name;
    int cost; // set to positive integer only
    int health;
    int happiness;
    int education;
    bool eatable;
    int energy; // set to positive integer only
public:
    sell_object(string name, int cost, int health, int happiness, int education, bool eatable, int energy)
    {
        this->name = name;
        this->cost = (cost >= 0) ? cost : -cost;
        this->health = health;
        this->happiness = happiness;
        this->education = education;
        this->eatable = eatable;
        this->energy = (energy >= 0) ? energy : -energy;
    }
    string get_name() { return name; }
    int get_cost() { return cost; }
    vector<int> get_return()
    {
        vector<int> v = {health, happiness, education};
        return v;
    }
    bool get_eatable() { return eatable; }
    int get_energyAmount() { return energy; }
};

struct JOB
{
    string name;
    int salary;
    struct requirement
    {
        int workEXP;
        int education;
    } req;
};

class place
{
private:
    string name;
    string desc;
    vector<string> available_workplace;

    // template<typename Place>
    // vector<sell_object> get_product_template();

public:
    place(string name = "none", string desc = "none")
    {
        this->name = name;
        this->desc = desc;
    }
    string get_name() { return name; }
    string get_desc() { return desc; }

    virtual vector<struct JOB> get_allJob()
    {
        vector<struct JOB> v = {};
        return v;
    }
    virtual vector<sell_object> get_product()
    {
        vector<sell_object> v = {};
        return v;
    }
    virtual void ui(player *, string);

    virtual void foo() {}
};

class restaurant : public place
{
private:
    vector<sell_object> product;
    vector<struct JOB> job;

public:
    restaurant() : place("Cluckers", "The best fast food in town, soooo gooood!")
    {
        product.insert(product.end(), sell_object("Clucker Burger", 95, -10, 10, 0, true, 1));
        product.insert(product.end(), sell_object("Clucker Bucket", 120, -10, 20, 0, true, 1));
        product.insert(product.end(), sell_object("Fries", 75, -10, -10, 0, true, 1));
        product.insert(product.end(), sell_object("Soda", 25, -10, 10, 0, false, 1)); 
        product.insert(product.end(), sell_object("Shake", 50, -10, 10, 0, false, 1));
        product.insert(product.end(), sell_object("Bear Combo", 150, 0, 20, 0, true, 1));

        vector<int> req;
        job.push_back({"Fry Cook", 4, {0, 0}});
        job.push_back({"Clerk", 5, {100, 0}});
        job.push_back({"Assistant Manager", 6, {200, 100}});
        job.push_back({"Manager", 7, {200, 200}});
    }
    vector<struct JOB> get_allJob()
    {
        return job;
    }
    vector<sell_object> get_product()
    {
        return product;
    }
};

class gym : public place
{
private:
    vector<sell_object> product;
    vector<struct JOB> job;

public:
    gym() : place("Gym", "Get in shape and get healthy by coming here! NPNG!")
    {
        product.insert(product.end(), sell_object("Work Out", 25, 10, 10, 0, false, 1));
        product.insert(product.end(), sell_object("Let it burn", 100, 20, 20, 0, false, 1));
        product.insert(product.end(), sell_object("Yoga", 250, 50, 20, 0, false, 1));
        product.insert(product.end(), sell_object("Protein Shake", 90, 20, 0, 0, false, 1));

        vector<int> req;
        job.push_back({"Janitor", 4, {0, 0}});
        job.push_back({"Exercise Physiologist", 5, {100, 100}});
        job.push_back({"Personal Trainer", 7, {200, 100}});
        job.push_back({"Assistant Manager", 9, {400, 200}});
        job.push_back({"Manager", 11, {800, 300}});
    }
    vector<struct JOB> get_allJob()
    {
        return job;
    }
    vector<sell_object> get_product()
    {
        return product;
    }
};

class home : public place
{
private:
    int cost; // set to positive integer only
public:
    home(int value = 200) : place("Lousy Housing", "Your first apartment! Come here to relax.")
    {
        this->cost = (value >= 0) ? value : -value;
    }
    vector<int> get_relax_stat()
    { // furby boi
        int energy_loose = 7;
        int return_hapiness = 1;
        vector<int> v = {energy_loose, return_hapiness};
        return v;
    }
    int get_cost() { return cost; }
    void ui(player *);
};

class market : public place
{
private:
    vector<sell_object> product;
    vector<struct JOB> job;

public:
    market() : place("Market", "Lottery tickets and food for your fridge (if you have one!).")
    {
        product.insert(product.end(), sell_object("Food for 1 week", 64, 0, 0, 0, false, 1));
        product.insert(product.end(), sell_object("Food for 2 weeks", 120, 0, 0, 0, false, 1));
        product.insert(product.end(), sell_object("Food for 4 weeks", 227, 0, 0, 0, false, 1));
        product.insert(product.end(), sell_object("Cleansing food for 1 week", 120, 20, 0, 0, false, 1));
        product.insert(product.end(), sell_object("Lottery", 35, 0, 0, 0, false, 1));
        product.insert(product.end(), sell_object("Newspaper", 5, 0, 1, 0, false, 1));

        vector<int> req;
        job.push_back({"Janitor", 4, {0, 0}});
        job.push_back({"Checker", 6, {100, 0}});
        job.push_back({"Butcher", 7, {200, 100}});
        job.push_back({"Assistant Manager", 9, {400, 200}});
        job.push_back({"Manager", 14, {800, 300}});
    }
    vector<struct JOB> get_allJob()
    {
        return job;
    }
    vector<sell_object> get_product()
    {
        return product;
    }
};

class apartment : public place
{
private:
    int cost;

public:
    apartment(int cost = 400) : place("Fancy Housing", "Much nicer apartment. Super secure, blocks all burglars!")
    {
        this->cost = (cost >= 0) ? cost : -cost;
    }
    vector<int> get_relax_stat()
    {
        int energy_loose = 7;
        int return_hapiness = 5;
        vector<int> v = {energy_loose, return_hapiness};
        return v;
    }
    int get_cost() { return cost; }
    void ui(player *);
};

class bank : public place
{
private:
    float interest;
    vector<struct JOB> job;

public:
    bank(float interest = 3) : place("Bank", "Here you van pay the rent, deposit and withdraw money, get loan or meet the investment Broker if you're feeling lucky.")
    {
        this->interest = interest;

        vector<int> req;
        job.push_back({"Janitor", 4, {0, 0}});
        job.push_back({"Teller", 6, {100, 0}});
        job.push_back({"Manager", 10, {400, 300}});
        job.push_back({"Risk Manager", 13, {800, 400}});
        job.push_back({"Broker", 15, {1600, 400}});
        job.push_back({"Compliance Officer", 17, {3200, 500}});
    }
    int cal_interest(int value)
    {
        return static_cast<int>(value + value * (interest / 100));
    }
    vector<struct JOB> get_allJob()
    {
        return job;
    }
    void ui(player *);
};

class tech_coop : public place
{
private:
    vector<sell_object> product;
    vector<struct JOB> job;

public:
    tech_coop() : place("VexCorp", "The salary is really good.")
    {
        product.insert(product.end(), sell_object("Vexportation Pass", 199, 0, 0, 0, false, 1));
        product.insert(product.end(), sell_object("Electric Scooter", 499, 0, 0, 0, false, 1));
        product.insert(product.end(), sell_object("Nikola Electric", 999, 0, 0, 0, false, 1));
        product.insert(product.end(), sell_object("VexPhone", 399, 0, 0, 0, false, 1));

        vector<int> req;
        job.push_back({"Secretary", 7, {100, 100}});
        job.push_back({"Quality Assurance", 9, {150, 300}});
        job.push_back({"Developer", 14, {200, 300}});
        job.push_back({"Senior Developer", 17, {300, 400}});
        job.push_back({"CTO", 19, {500, 400}});
        job.push_back({"CEO", 23, {700, 700}});
    }
    vector<struct JOB> get_allJob()
    {
        return job;
    }
    vector<sell_object> get_product()
    {
        return product;
    }
};

class job_office : public place
{
public:
    job_office() : place("Job Office", "Apply for jobs here!") {}
    int check_requirement(player *, string, place *);
    void ui(player *);
};

class art : public place
{
private:
    vector<sell_object> product;

public:
    art() : place("Culture Center", "Buy tickets to events or trips.")
    {
        product.insert(product.end(), sell_object("Football match", 250, 0, 60, 0, false, 15));
        product.insert(product.end(), sell_object("Baseball game", 250, 0, 60, 0, false, 15));
        product.insert(product.end(), sell_object("Mini concert", 300, 0, 85, 0, false, 20));
        product.insert(product.end(), sell_object("Opera House", 450, 0, 100, 0, false, 20));
        product.insert(product.end(), sell_object("Rocket to the Moon", 800, 0, 200, 0, false, 30));
        product.insert(product.end(), sell_object("Picnic", 250, 20, 40, 0, false, 15));
    }
    vector<sell_object> get_product()
    {
        return product;
    }
};

class school : public place
{
private:
    vector<struct JOB> job;

public:
    school() : place("University", "Come here to get educated and get a better jobs")
    {
        vector<int> req;
        job.push_back({"Janitor", 4, {0, 0}});
        job.push_back({"Clerk", 6, {100, 100}});
        job.push_back({"Administrator", 7, {200, 200}});
        job.push_back({"Adjunct", 9, {400, 200}});
        job.push_back({"Assistant Professor", 11, {800, 300}});
        job.push_back({"Professor", 14, {1600, 500}});
    }
    vector<struct JOB> get_allJob()
    {
        return job;
    }
    void ui(player *);
};

class it_store : public place
{
private:
    vector<sell_object> product;
    vector<struct JOB> job;

public:
    it_store() : place("Appliance Store", "Fancy Fridge or a new TV? Get it here!")
    {
        product.insert(product.end(), sell_object("Refrigerator", 850, 0, 85, 0, false, 1));      // อาหารบูด
        product.insert(product.end(), sell_object("Smoke Detector", 400, 0, 15, 0, false, 1));    // ลดโอกาสไฟไหม้
        product.insert(product.end(), sell_object("Fire extinguisher", 150, 0, 10, 0, false, 1)); // ลดเงินที่จะลด -,- -> +
        product.insert(product.end(), sell_object("elgooG Maps", 250, 0, 12, 0, false, 1));    // กันรถติด
        product.insert(product.end(), sell_object("CCTV", 400, 0, 47, 0, false, 1));           // ลดโอกาสไวท์ขโมย +10% (บวกเข้าไปเลย)
        product.insert(product.end(), sell_object("Notebook", 350, 0, 12, 0, false, 1));       // + ตังจากการทำงาน 4
        product.insert(product.end(), sell_object("Stun Gun", 499, 0, 15, 0, false, 1));       // ป้องกันโจรใหญ้ +10%

        vector<int> req;
        job.push_back({"Clerk", 4, {0, 0}});
        job.push_back({"Salesperson", 6, {100, 0}});
        job.push_back({"Repairman", 7, {200, 100}});
        job.push_back({"Software Servitor", 9, {400, 200}});
        job.push_back({"Manager", 11, {800, 300}});
        job.push_back({"Senior Manager", 13, {1600, 400}});
    }
    vector<struct JOB> get_allJob()
    {
        return job;
    }
    vector<sell_object> get_product()
    {
        return product;
    }
};

class mall : public place
{
private:
    vector<sell_object> product;
    vector<struct JOB> job;

public:
    mall() : place("Mall", "Buy new clothes or furniture for you home. Happiest place on earth.")
    {
        product.insert(product.end(), sell_object("Salty Bag", 199, 0, 0, 0, false, 1));
        product.insert(product.end(), sell_object("Sofa, So good!", 800, 0, 130, 0, false, 1));
        product.insert(product.end(), sell_object("Curtain", 400, 0, 65, 0, false, 1));
        product.insert(product.end(), sell_object("Carpet", 400, 0, 65, 0, false, 1));
        product.insert(product.end(), sell_object("Movie Poster", 150, 0, 30, 0, false, 1));
        product.insert(product.end(), sell_object("Lemon Tree", 100, 0, -10, 0, false, 1));

        vector<int> req;
        job.push_back({"Janitor", 6, {0, 0}});
        job.push_back({"Mall Security", 6, {100, 0}});
        job.push_back({"Salesperson", 6, {200, 100}});
        job.push_back({"Store Manager", 6, {400, 200}});
        job.push_back({"Assistant Manager", 6, {800, 300}});
        job.push_back({"Manager", 6, {800, 400}});
    }
    vector<struct JOB> get_allJob()
    {
        return job;
    }
    vector<sell_object> get_product()
    {
        return product;
    }
};

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
    do
    {
        vector<sell_object> product = name2placePtr(curr)->get_product(); // ตรงนี้ทำไว้แล้วสำหรับรับค่า product ช่าย
        vector<string> product_name;
        for (auto &itr : product)
            product_name.push_back(itr.get_name());

        map<string, bool> bag = p->get_bag();

        string choice = selection_menu<string>(curr, product_name, {" ", "Return", (curr != p->get_and_change_work_place()) ? (" ") : ("Work")}, [&]() -> void
                        { 
                            cout << "Money Left: " << p->get_and_change_money() << endl;
                            cout << "Energy Left: " << p->get_and_change_energy() << endl;
                            cout << "=================================\n";
                            for(auto &itr: product) {
                                cout << itr.get_name() << " : " << itr.get_cost() << endl;
                            }
                                
                        });
        if (choice == "Return")
            return;
        else if (choice == "Work")
            p->do_work();
        else
        {
            for (auto &itr : product)
            {
                if (itr.get_name() == choice)
                {
                    try
                    {
                        if (!p->buying(itr.get_cost()))
                            throw *myex["lag_money"];
                    }
                    catch (exception &e)
                    {
                        cerr << e.what() << endl;
                        getch();
                        break;
                    }

                    bool check_item = false;
                    if (curr == "Appliance Store" || curr == "Mall")
                    {
                        if (choice == "Salty Bag")
                        {
                            int salty = rand() % 450;
                            salty *= (salty % 3 == 0) ? (-1) : (1);
                            salty += (salty % 3 == 0) ? (199) : (0);
                            p->get_and_change_money(salty);
                            cout << "You " << ((salty >= 0) ? ("got ") : ("loose ")) << salty << " from Salty Bag" << endl;
                        }
                        else
                            check_item = bag[choice];
                    }
                    else if (curr == "Market")
                    {
                        if (bag["Refrigerator"] == true)
                        {
                            if (choice == "Food for 1 week" || choice == "Cleansing food for 1 week")
                            {
                                if (p->get_and_change_food_reserve() + 1 <= 4)
                                    p->get_and_change_food_reserve(1);
                                else
                                {
                                    cout << "Your Refrigerator is full!!" << endl;
                                    check_item = true;
                                }
                            }
                            else if (choice == "Food for 2 weeks")
                            {
                                if (p->get_and_change_food_reserve() + 2 <= 4)
                                    p->get_and_change_food_reserve(2);
                                else
                                {
                                    cout << "Your Refrigerator is full!!" << endl;
                                    check_item = true;
                                }
                            }
                            else if (choice == "Food for 4 weeks")
                            {
                                if (p->get_and_change_food_reserve() == 0)
                                    p->get_and_change_food_reserve(4);
                                else
                                {
                                    cout << "Your Refrigerator is full!!" << endl;
                                    check_item = true;
                                }
                            }
                        }
                        else if (bag["Refrigerator"] == false)
                        {
                            cout << "You must buy a refrigerator first. (T^T)" << endl;
                            break;
                        }
                    }
                    else if (curr == "Culture Center")
                    {
                        if (bag["Football match"] || bag["Baseball game"] || bag["Mini concert"] || bag["Opera House"] || bag["Rocket to the Moon"] || bag["Picnic"])
                        {
                            check_item = true;
                        }
                    }
                    else if (curr == "VexCorp")
                    {
                        string curr_car = p->get_and_change_car_type();
                        if (choice == "Vexportation Pass" && curr_car == "Walk")
                        {
                            p->get_and_change_car_type("Vexportation Pass");
                        }
                        else if (choice == "Electric Scooter" && (curr_car == "Walk" || curr_car == "Vexportation Pass"))
                        {
                            p->get_and_change_car_type("Electric Scooter");
                        }
                        else if (choice == "Nikola Electric" && curr_car != "Nikola Electric")
                        {
                            p->get_and_change_car_type("Nikola Electric");
                        }
                        else
                            check_item = true;
                    }

                    if (check_item == false)
                    {
                        vector<int> x = itr.get_return();
                        p->get_and_change_health(x[0]);
                        p->get_and_change_happiness(x[1]);
                        p->get_and_change_education(x[2]);
                        if (itr.get_eatable())
                            p->change_fullness(true);
                        p->get_and_change_energy(-itr.get_energyAmount());
                        p->set_bag(choice, true);
                    }
                    break;
                }
            }
        }
    } while (true);
}

void home::ui(player *p)
{
    map<string, bool> bag = p->get_bag();
    do
    {
        if (p->get_and_change_home() == get_name())
        {
            if (bag["Refrigerator"])
                cout << "Food Reserve remain : " << p->get_and_change_food_reserve() << " week(s)" << endl;
            string choice = selection_menu<string>(get_name(), {}, {"Relax", "Return", " "}, [&]() -> void
                                                   { cout << "Remaining Energy : " << p->get_and_change_energy() << endl; });
            if (choice == "Return")
                return;
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
            string choice = selection_menu<string>(get_name(), {}, {"Rent", "Return", " "}, [&]() -> void {});
            if (choice == "Return") 
                return;
            else if (choice == "Rent")
            {
                if (!p->buying(cost))
                    continue;
                p->get_and_change_home(get_name());
            }
        }
    } while (true);
}

void apartment::ui(player *p)
{
    map<string, bool> bag = p->get_bag();
    do
    {
        if (p->get_and_change_home() == get_name())
        {
            if (bag["Refrigerator"])
                cout << "Food Reserve remain : " << p->get_and_change_food_reserve() << " week(s)" << endl;
            string choice = selection_menu<string>(get_name(), {}, {"Relax", "Return", " "}, [&]() -> void
                                                   { cout << "Remaining Energy : " << p->get_and_change_energy() << endl; });
            if (choice == "Return")
                return;
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
            string choice = selection_menu<string>(get_name(), {}, {"Rent", "Return", " "}, [&]() -> void
                                                   { cout << "Money Left: " << p->get_and_change_money() << endl; });
            if (choice == "Return")
                return;
            else if (choice == "Rent")
            {
                if (!p->buying(cost))
                    continue;
                p->get_and_change_home(get_name());
            }
        }
    } while (true);
}

void bank::ui(player *p)
{
    // work, deposit-withdraw
    do
    {
        int mon = p->get_and_change_money();
        int acc_mon = p->get_and_change_account_balance();

        vector<string> action = {"Deposit", "-100", "-All",
                                 "Withdraw", "+100", "+All"};

        string choice = selection_menu<string>(get_name(), action, {(p->get_and_change_debt() != 0) ? ("Paid Debt") : (" "), "Return", (get_name() != p->get_and_change_work_place()) ? (" ") : ("Work")}, [&]() -> void {
            cout << "Money: " << p->get_and_change_money() << endl;
            cout << "Account Balance: " << p->get_and_change_account_balance() << endl;
            cout << "Debt Left: " << p->get_and_change_debt() << endl;
        });
        if (choice == "Return")
            return;
        else if (choice == "Work")
            p->do_work();
        else if (choice == "Deposit" || choice == "-100")
        {
            p->get_and_change_account_balance((mon >= 100) ? (100) : (mon));
            p->get_and_change_money((mon >= 100) ? (-100) : (-mon));
        }
        else if (choice == "-All")
        {
            p->get_and_change_account_balance(mon);
            p->get_and_change_money(-mon);
        }
        else if (choice == "Withdraw" || choice == "+100")
        {
            p->get_and_change_money((acc_mon >= 100) ? (100) : (acc_mon));
            p->get_and_change_account_balance((acc_mon >= 100) ? (-100) : (-acc_mon));
        }
        else if (choice == "+All")
        {
            p->get_and_change_money(acc_mon);
            p->get_and_change_account_balance(-acc_mon);
        }
        else if (choice == "Paid Debt")
        {
            p->buying(p->get_and_change_debt());
        }

    } while (true);
}

void job_office::ui(player *p)
{
    do
    {
        vector<string> plName = {"Cluckers", "Gym", "Market", "Bank", "VexCorp", "University", "Appliance Store", "Mall"};
        string choice = selection_menu<string>(get_name(), plName, {" ", "Return", " "}, [&]() -> void {});
        if (choice == "Return")
            return;

        vector<string> job_name;
        for (auto &itr : name2placePtr(choice)->get_allJob())
            job_name.push_back(itr.name);
        string jb_choice = selection_menu<string>(get_name(), job_name, {" ", "Return", " "}, [&]() -> void {
            cout << "Metier : "<< p->get_and_change_metier() << endl;
            cout << "Education: " << p->get_and_change_education() << endl;
            cout << "Work Experience: " <<p->get_and_change_workEXP() << endl;

            cout << "==============================" << endl;
            for(auto &itr: name2placePtr(choice)->get_allJob())
                cout << itr.name << " : " << itr.salary << "x8 $/ 20 Energy" << endl;
        });
        int salary = check_requirement(p, jb_choice, name2placePtr(choice));
        try  {
            if (salary != -1) 
            {
                p->get_and_change_metier(jb_choice);
                p->get_and_change_work_place(choice);
                p->get_and_change_salary(salary);

                cout << "Yay! You can work in this Metier." << endl;
                getch();
            }
            else throw *myex["lag_req"];
        } 
        catch (exception &e) {
            cerr << e.what() << endl;
            getch();
        }

    } while (true);
}

void school::ui(player *p)
{
    // work and learn
    do
    {
        string choice = selection_menu<string>(get_name(), {}, {(p->get_and_change_education() % 100 == 0 && p->get_and_change_education() < 700) ? ("Paid Tuition Fee") : ("Learn"), "Return", (get_name() != p->get_and_change_work_place()) ? (" ") : ("Work")}, [&]() -> void
                                               {
                                                   cout << "Education: " << p->get_and_change_education() << endl;
                                                   cout << "Energy Left: " << p->get_and_change_energy() << endl;
                                                   cout << "Money Left: " << p->get_and_change_money() << endl; });
        if (choice == "Return")
            return;
        else if (choice == "Work")
            p->do_work();
        else if (choice == "Paid Tuition Fee")
        {
            int fee;
            int edu = p->get_and_change_education();
            if (edu == 100)
            {
                fee = 50;
            }
            else if (edu == 200)
            {
                fee = 100;
            }
            else if (edu == 300)
            {
                fee = 150;
            }
            else if (edu == 400)
            {
                fee = 200;
            }
            else if (edu == 500)
            {
                fee = 250;
            }
            else if (edu == 600)
            {
                fee = 250;
            }
            try {
                if(!p->buying(fee)) throw *myex["lag_money"];
                p->get_and_change_education(10);
            }
            catch (exception &e) {
                cout << e.what() << endl;
                getch();
            }
        }
        else if (choice == "Learn")
        {
            p->get_and_change_education(10);
            p->get_and_change_energy(-20);
        }
    } while (true);
}
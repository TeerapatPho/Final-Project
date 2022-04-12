struct JOB {
    string name;
    int salary;
    vector<int> requirement;
};

class place {
private:
    string name;
    string desc;

public:
    place(string, string);
    string get_name();
    string get_desc();
    virtual vector<struct JOB> get_allJob() {}
};

place::place(string name, string desc) { 
    this->name = name;
    this->desc = desc;
}
string place::get_name() { return name; }
string place::get_desc() { return name; }

class sell_object {
private:
    string name;
    int cost; //set to positive integer only
    int health;
    int hapiness;
    int education;
    bool eatable;
    int energy; //set to positive integer only
public:
    sell_object(string name, int cost, int health, int hapiness, int education, bool eatable, int energy) {
        this->name = name;
        this->cost = (cost >= 0) ? cost : -cost;
        this->health = health;
        this->hapiness = hapiness;
        this->education = education;
        this->eatable = eatable;
        this->energy = (energy >= 0) ? energy : -energy;
    }
    string get_name() { return name; }
    int get_cost() { return cost; }
    vector<int> get_return() {
        vector<int> v = {health, hapiness, education};
        return v;
    }
    bool get_eatable() { return eatable; }
    int get_energyAmount() { return energy; }
};

class restaurant : public place {
private:
    vector<sell_object> product;
    vector<struct JOB> job; 
public:
    restaurant() : place("Cluckers", "The best fast food in town, soooo gooood!") {
        product.insert(product.end(), sell_object("Clucker Burger", 95, -10, 10, 0, true, 1));
        product.insert(product.end(), sell_object("Clucker Bucket", 120, -10, -10, 0, true, 1));
        product.insert(product.end(), sell_object("Fries", 95, -10, -10, 0, true, 1));
        product.insert(product.end(), sell_object("Soda", 95, -10, 10, 0, false, 1));
        product.insert(product.end(), sell_object("Shake", 95, -10, 10, 0, false, 1));
        product.insert(product.end(), sell_object("Bear Combo", 95, -10, 10, 0, true, 1));

        vector<int> req;
        req.assign({100, 100});
        job.push_back({"Janister1", 6, req});
        req.assign({100, 100});
        job.push_back({"Janister2", 6, req});
        req.assign({100, 100});
        job.push_back({"Janister3", 6, req});
        req.assign({100, 100});
        job.push_back({"Janister4", 6, req});
        req.assign({100, 100});
        job.push_back({"Janister5", 6, req});
        req.assign({100, 100});
        job.push_back({"Janister6", 6, req});

    }
    // bool check_requirement(player p){
    //     vector<int> stat = {p.get_workEXP(), p.get_education()}
    //     return stat == work_requirement;
    // }
    
};

class gym : public place {
private:
    vector<sell_object> product;
    vector<struct JOB> job; 
public:
    gym() : place("Gym", "Get in shape and get healthy by coming here! NPNG!") {
        product.insert(product.end(), sell_object("Something1", 25, 10, 10, 0, false, 1));
        product.insert(product.end(), sell_object("Something2", 150, 20, -10, 0, false, 2));
        product.insert(product.end(), sell_object("Yoga", 250, 100, -10, 0, false, 3));
        product.insert(product.end(), sell_object("Protein Powder", 75, -10, 10, 0, false, 1));
    
        vector<int> req;
        req.assign({100, 100});
        job.push_back({"Janister1", 6, req});
        req.assign({100, 100});
        job.push_back({"Janister2", 6, req});
        req.assign({100, 100});
        job.push_back({"Janister3", 6, req});
        req.assign({100, 100});
        job.push_back({"Janister4", 6, req});
        req.assign({100, 100});
        job.push_back({"Janister5", 6, req});
        req.assign({100, 100});
        job.push_back({"Janister6", 6, req});
    }
    // bool check_requirement(player p){
    //     vector<int> stat = {p.get_workEXP(), p.get_education()}
    //     return stat == work_requirement;
    // }
};

class home : public place {
private:
    int debt; //set to positive integer only
public:
    home(int value) : place("Lousy Housing", "Your first apartment! Come here to relax.") {
        this->debt = (value >= 0) ? value : -value;
    }
    vector<int> get_relax_stat() {
        int energy_loose = 1;
        int return_hapiness = 1;
        vector<int> v = {energy_loose, return_hapiness};
        return v;
    }
    int get_debt() { return debt; }
};

class market : public place {
private:
    vector<sell_object> product;
    vector<struct JOB> job; 
public:
    market() : place("Market", "Lottery tickets and food for your fridge (if you have one!).") {
        product.insert(product.end(), sell_object("Something1", 25, 10, 10, 0, false, 1));
        product.insert(product.end(), sell_object("Something2", 150, 20, -10, 0, false, 1));
        product.insert(product.end(), sell_object("Lottery", 250, 100, -10, 0, false, 1));
    
        vector<int> req;
        req.assign({100, 100});
        job.push_back({"Janister1", 6, req});
        req.assign({100, 100});
        job.push_back({"Janister2", 6, req});
        req.assign({100, 100});
        job.push_back({"Janister3", 6, req});
        req.assign({100, 100});
        job.push_back({"Janister4", 6, req});
        req.assign({100, 100});
        job.push_back({"Janister5", 6, req});
        req.assign({100, 100});
        job.push_back({"Janister6", 6, req});
    }
    // bool check_requirement(player p) {
    //     vector<int> stat = {p.get_workEXP(), p.get_education()}
    //     return stat == work_requirement;
    // }
};

class apartment : public place {
private:
    int house_value;
    int debt;
public:
    apartment(int value=2000, int debt=500) : place("Fancy Housing", "Much nicer apartment. Super secure, blocks all burglars!") {
        this->house_value = (value >= 0) ? value : -value;
        this->debt = (debt >= 0) ? debt : -debt;
    }
    vector<int> get_relax_stat() {
        int energy_loose = 1;
        int return_hapiness = 5;
        vector<int> v = {energy_loose, return_hapiness};
        return v;
    }
    int get_value() { return house_value; }
    int get_debt() { return debt; }
};

class bank : public place {
private:
    float interest;
    vector<struct JOB> job; 
public:
    bank(float interest) : place("Bank", "Here you van pay the rent, deposit and withdraw money, get loan or meet the investment Broker if you're feeling lucky.") {
        this->interest = interest;

        vector<int> req;
        req.assign({100, 100});
        job.push_back({"Janister1", 6, req});
        req.assign({100, 100});
        job.push_back({"Janister2", 6, req});
        req.assign({100, 100});
        job.push_back({"Janister3", 6, req});
        req.assign({100, 100});
        job.push_back({"Janister4", 6, req});
        req.assign({100, 100});
        job.push_back({"Janister5", 6, req});
        req.assign({100, 100});
        job.push_back({"Janister6", 6, req});
    }
    int cal_interest(int value) {
        return static_cast<int>(value + value * (interest/100));
    }
    // bool check_requirement(player p) {
    //     vector<int> stat = {p.get_and_change_workEXP(), p.get_and_change_education()};
    //     return stat == work_requirement;
    // }
};

class tech_coop : public place {
private:
    vector<sell_object> product;
    vector<struct JOB> job; 
public:
    tech_coop() : place("VexCorp", "The salary is really good.") {
        product.insert(product.end(), sell_object("Scooter", 25, 10, 10, 0, false, 1));
        product.insert(product.end(), sell_object("Car", 150, 20, -10, 0, false, 1));
        product.insert(product.end(), sell_object("Rocket", 250, 100, -10, 0, false, 1));

        vector<int> req;
        req.assign({100, 100});
        job.push_back({"Janister1", 6, req});
        req.assign({100, 100});
        job.push_back({"Janister2", 6, req});
        req.assign({100, 100});
        job.push_back({"Janister3", 6, req});
        req.assign({100, 100});
        job.push_back({"Janister4", 6, req});
        req.assign({100, 100});
        job.push_back({"Janister5", 6, req});
        req.assign({100, 100});
        job.push_back({"Janister6", 6, req});

        cout << job[2].name;

    }
    vector<struct JOB> get_allJob() override {
        return job;
    }
};

class job_office : public place {
public:
    job_office() : place("Job office", "Apply for jobs here!") {}
    int check_haveJob(place pl, string name) {
        // bool check = false;
        // vector<struct JOB> temp = pl.get_allJob();
        cout << "hello";
        return 1;
        // try {
        //     for(int i = 0; i < temp.size(); i++) {
        //         check = temp[i].name.compare(name) == 0;
        //         // cout << pl.get_allJob()[i].name;
        //         if(check) return i;
        //     }
        // } catch(...) {
        //     return -1;
        // }
    }
    int check_requirement(player p, place pl, string name) {
        try {
            vector<int> stat = {p.get_and_change_workEXP(), p.get_and_change_education()};
            
            int index = check_haveJob(pl,name);
            if(index == -1) throw 505;

            bool check = false;
            int i;
            for (i = 0; i < pl.get_allJob()[index].requirement.size(); i++)
                if(pl.get_allJob()[index].requirement[i] > stat[i])
                    check = false;
            if(!check) throw 505;
            return pl.get_allJob()[i].salary;
        } 
        catch(...) {
            cout << "you cannot apply the job in this place" << endl;
            return 0;
        }
    }

};
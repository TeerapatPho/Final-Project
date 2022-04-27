#ifndef PLACE_H
#define PLACE_H

#include <string>
#include <vector>

using namespace std;



#include "Player.h"

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
        product.insert(product.end(), sell_object("Clucker Burger", 95, -10, 10, 0, true, 1)); //ฟามจิงใช้ push_back ก็ได้แหละ ใช้ insert ทำไมวะ???? ดึงๆ
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
        int energy_loose = 1;
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
        product.insert(product.end(), sell_object("Newspaper", 5, 0, 0, 0, false, 1));

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
        int energy_loose = 1;
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
        job.push_back({"Quality Assuarance", 9, {150, 300}});
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
        product.insert(product.end(), sell_object("Football match", 250, 0, 10, 0, false, 1));
        product.insert(product.end(), sell_object("Baseball game", 250, 0, 10, 0, false, 1));
        product.insert(product.end(), sell_object("Mini concert", 300, 0, 10, 0, false, 1));
        product.insert(product.end(), sell_object("Opera House", 450, 0, 10, 0, false, 1));
        product.insert(product.end(), sell_object("Rocket to the Moon", 800, 0, 10, 0, false, 1));
        product.insert(product.end(), sell_object("Picnic", 250, 10, 10, 0, false, 1));
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
        product.insert(product.end(), sell_object("Refrigerator", 850, 0, 10, 0, false, 1));      // อาหารบูด
        product.insert(product.end(), sell_object("Smoke Detector", 400, 0, 10, 0, false, 1));    // ลดโอกาสไฟไหม้
        product.insert(product.end(), sell_object("Fire extinguisher", 150, 0, 10, 0, false, 1)); // ลดเงินที่จะลด -,- -> +
        product.insert(product.end(), sell_object("elgooG Maps", 250, 100, -10, 0, false, 1));    // กันรถติด
        product.insert(product.end(), sell_object("CCTV", 400, 100, -10, 0, false, 1));           // ลดโอกาสไวท์ขโมย +10% (บวกเข้าไปเลย)
        product.insert(product.end(), sell_object("Notebook", 350, 100, -10, 0, false, 1));       // + ตังจากการทำงาน 4
        product.insert(product.end(), sell_object("Stun Gun", 499, 100, -10, 0, false, 1));       // ป้องกันโจรใหญ้ +10%

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
        product.insert(product.end(), sell_object("Sofa, So good!", 800, 0, 0, 0, false, 1));
        product.insert(product.end(), sell_object("Curtain", 400, 0, 0, 0, false, 1));
        product.insert(product.end(), sell_object("Carpet", 400, 0, 0, 0, false, 1));
        product.insert(product.end(), sell_object("Movie Poster", 150, 0, 0, 0, false, 1));
        product.insert(product.end(), sell_object("Lemon Tree", 100, 0, -10, 0, false, 1));
        // i wonder how, i wonder why. yesterday you told me bout the blue blue sky. At all that I can see it's just another lemon tree~ -> ร้องเพลงแหละะ

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

#endif
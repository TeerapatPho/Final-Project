#include <exception> // อย่าลืมลบ
#include <string>
#include <map>

using namespace std;

#ifndef EXCEPTION_H
#define EXCEPTION_H

class game_exception : public exception{
    const char* err_msg; // char* a= "asdasd"; func("xxxxxxx"); 
public :
    game_exception(const char* msg){err_msg=msg;}
    virtual const char* what() const throw(){
        return err_msg;
    }
};

map<string,game_exception> gen_exception(){
  map<string,game_exception> myex;
  myex["lag_energy"] = game_exception("You not have energy to do that! go home and rest to recharge your energy."); //1.no energy
  myex["lag_money"] = game_exception("You have not enough money. Maybe bank can help you."); //no money
  myex["expect_int"] = game_exception("Please input in integer only."); //type error
  myex["expect_float"] = game_exception("Please input in float only."); //type error
  myex["expect_string"] = game_exception("Please input only word."); //type error
  myex["choice_err"] = game_exception("Don't select a blank space."); //selection 
  myex["lag_req"] = game_exception("You not have property that company want."); //rejected work request
  return myex;
}

#endif
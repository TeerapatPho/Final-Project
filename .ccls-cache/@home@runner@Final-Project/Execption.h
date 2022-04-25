#include <exception>
using namespace std;
class not_enough_energy: public exception{
public :
   const char* what(){
      return "You not have energy to do anything ;-;\n";
    }
}
class not_enough_money: public exception{
 int need;
 public :    
   const char* what(){
      return "\n";
    }
    void calculate_money_need(int cost , int have){
        need = cost - have;
    }
    void notification(){
      cout << ""
    }
}
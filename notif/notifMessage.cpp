#include "notifMessage.hpp"
#include <iostream>

using namespace std;


void notifMessage::getMessage(){
  cout<<"id: "<<id<<"\n";
  cout<<"Current price: "<<current_price<<"\n";
  cout<<"Market volume: "<<market_volume<<"\n";
  cout<<"High price: "<<high<<"\n";
  cout<<"Market cap: "<<market_cap<<"\n";
}

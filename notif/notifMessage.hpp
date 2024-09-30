#pragma once
#include <string>

using namespace std;
class notifMessage {
  int current_price;
  int market_volume;
  int high;
  int market_cap;
  string notif_id;

public:
  notifMessage(int cp, int mv, int _high, int mc, int id){
    current_price = cp;
    market_volume = mv;
    high = _high;
    market_cap = mc;
    notif_id = id;
  }

  void getMessage();

  //setters and getters
}

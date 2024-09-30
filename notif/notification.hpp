#pragma once
#include <string>

using namespace std;

enum NOTIF_STATUS{
  SENT,
  OUTSTANDING,
  FAILED
};

class notification{
  string email;
  string messageId;
  NOTIF_STATUS status;
public:
  notification(string mail,string mid){
    email = mail;
    messageId = mid;
    status = NOTIF_STATUS.OUTSTANDING;
  }

  void setStatus(NOTIF_STATUS s);

  NOTIF_STATUS getStatus();
}

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
  string templateId;
  string notifId;
  NOTIF_STATUS status;
public:
  notification(string mail,string tid,string nid){
    email = mail;
    templateId = tid;
    notifId = nid;
    status = OUTSTANDING;
  }

  string getEmail();
  string gettemplateID();
  string getID();

  void setStatus(NOTIF_STATUS s);

  NOTIF_STATUS getStatus();
};

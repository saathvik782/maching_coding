#include "notification.hpp"

void notification::setStatus(NOTIF_STATUS s){
  status = s;
}

NOTIF_STATUS notification::getStatus(){
  return status;
}

string notification::getEmail(){
  return email;
}

string notification::gettemplateID(){
  return templateId;
}

string notification::getID(){
  return notifId;
}

#include "notification.hpp"
#include <iostream>


void notification::setStatus(NOTIF_STATUS s){
  status = s;
}

NOTIF_STATUS notification::getStatus(){
  return status;
}

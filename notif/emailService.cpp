#include "emailService.hpp"
#include "notification.hpp"
#include <cstdlib>
#include <iostream>
using namespace std;

emailService* emailService::ptr = nullptr;
mutex emailService::mtx;

int emailService::sendEmail(notification *n){
  //randomly generate sent or not send
  //fail prob 0.2
  if((rand()%10) < 2){
    cout<<"notif. ["<<n->getID()<<"] "<<n->getEmail()<<" FAILED\n";
    n->setStatus(FAILED);
    return -1;
  }
  cout<<"notif. ["<<n->getID()<<"] "<<n->getEmail()<<" SENT\n";
  n->setStatus(SENT);
  return 1;
}

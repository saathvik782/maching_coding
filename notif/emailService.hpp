#pragma once
#include <mutex>
#include "notification.hpp"
using namespace std;

class emailService{
  static emailService* ptr;
  static mutex mtx;
  emailService() {}
public:

  static emailService* getInstance() {
    if(ptr == nullptr){
      mtx.lock();
      if(ptr == nullptr){
        ptr = new emailService();
      }
      mtx.unlock();
    }
    return ptr;
  }
  
  int sendEmail(notification *n);
};

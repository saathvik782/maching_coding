#pragma once
#include <mutex>
#include <string>
#include "notification.hpp"

class notificationService{
  static notificationService* ptr;
  static mutex mtx;

  map<string,notifMessage> messageStore;
  map<string,notification> notifStore;

  int message_id;
  int notif_id;
  
  notificationService(){
    message_id = 0;
  }

public:
  static notificationService* getNotificationService(){
    if(ptr == NULL){ 
      mtx.lock();
      if(ptr == NULL){
        ptr = new notificationService();
      }
      mtx.unlock();
    }
    return ptr;
  }
  
  string createTemplate();

  vector<string> listTemplates();
  
  void sendNotification(string notificationId,string emailid);    

  void deleteTemplate(string notificationId);
}


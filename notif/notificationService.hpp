#pragma once
#include <mutex>
#include <string>
#include <map>
#include "notifTemplate.hpp"
#include "notification.hpp"

class notificationService{
  static notificationService* ptr;
  static mutex mtx;

  map<string,notifTemplate*> templateStore;
  map<string,notification*> notifStore;

  int message_id;
  int notif_id;
  
  notificationService(){
    message_id = 0;
    notif_id = 0;
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
  
  string createTemplate(
  int current_price,
  int market_volume,
  int high,
  int market_cap);


  vector<string> listTemplates();
  
  void sendNotification(string templateId,string emailid);    

  void deleteTemplate(string templateId);

  notifTemplate* getTemplate(string templateId);

  vector<string> listAllSent();
};


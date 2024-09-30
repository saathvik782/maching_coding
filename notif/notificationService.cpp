#include "notificationService.hpp"
#include "notifTemplate.hpp"
#include "notification.hpp"
#include "emailService.hpp"
#include <csignal>
#include <string>
#include <iostream>
using namespace std;

notificationService* notificationService::ptr = nullptr;
mutex notificationService::mtx; 

//string notificationService

string notificationService::createTemplate(
  int current_price,
  int market_volume,
  int high,
  int market_cap
  ){

  message_id++;
  string template_id = to_string(message_id);
  templateStore[template_id] = new notifTemplate(current_price, market_volume, high, market_cap, message_id);
  return template_id;
}

vector<string> notificationService::listTemplates(){
  vector<string> k;
  for(auto pr : templateStore){
    k.push_back(pr.first);
  }
  return k;
}


void notificationService::sendNotification(string templateId,string emailid){
  //create a notification and 
  notif_id++;
  string id = to_string(notif_id);
  notifStore[id] = new notification(emailid,templateId,id);

  //pass on this notification to emailService
  emailService::getInstance()->sendEmail(notifStore[id]);
}

void notificationService::deleteTemplate(string templateId){
  templateStore.erase(templateId);
}

notifTemplate* notificationService::getTemplate(string templateId){
  if(templateStore.find(templateId) == templateStore.end()){
    cout<<"Template not found\n";
  }

  return templateStore[templateId];
}

vector<string> notificationService::listAllSent(){
  vector<string> k;
  for(auto pr : notifStore){
    if(pr.second->getStatus() == SENT){
      k.push_back(pr.first);
    }
  }
  return k;
}

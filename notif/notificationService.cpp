#include "notificationService.hpp"
#include <string>
using namespace std;

static notificationService* notificationService::ptr = nullptr;
static mutex notificationService::mtx; 

//string notificationService

string notificationService::createNofification(){
  message_id++;
  string notif_id = itoa(message_id);
  messageStore[notif_id] = nullptr;
  return notif_id;
}

vector<string> notificationService::listNotifications(){
  vector<string> k;
  for(auto pr : messageStore){
    k.push_back(pr.first);
  }
  return k;
}


void notificationService::sendNotification(string notificationId,string emailid){

}

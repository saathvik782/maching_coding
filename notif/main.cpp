#include "notificationService.hpp"
#include <iostream>

using namespace std;
int main(){
  notificationService* ns = notificationService::getNotificationService();

  string template_id = ns->createTemplate(100, 1024, 102, 98765);
  template_id = ns->createTemplate(95, 2048, 95, 200000);

  cout<<"Listing templates\n";
  for(auto s:ns->listTemplates()){
    cout<<s<<"\n";
  }
  cout<<"=========\n";

  ns->sendNotification("1", "test1@gmail.com");
  ns->sendNotification("2", "test2@gmail.com");
  ns->sendNotification("1", "test3@gmail.com");
  ns->sendNotification("2", "test4@gmail.com");
  ns->sendNotification("1", "test5@gmail.com");
  ns->sendNotification("2", "test6@gmail.com");
  ns->sendNotification("1", "test7@gmail.com");
  ns->sendNotification("2", "test8@gmail.com");
  ns->sendNotification("1", "test9@gmail.com");
  ns->sendNotification("2", "test10@gmail.com");

  cout<<"\nList notif id's sent \n";
  for(auto s:ns->listAllSent()){
    cout<<s<<"\n";
  }
  cout<<"=========\n";

  cout<<"delete template 1"<<"\n";
  ns->deleteTemplate("1");

  cout<<"Listing templates\n";
  for(auto s:ns->listTemplates()){
    cout<<s<<"\n";
  }
  cout<<"=========\n";

  return 0;
}

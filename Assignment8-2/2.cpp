#include <iostream>
#include <map>
using namespace std;

class DeliveryFood{
protected:
  int totalPrice;
  string sideMenu;

public:
  DeliveryFood():totalPrice(0){}
  int getTotalPrice(){return totalPrice;}
  string getSideMenu(){return sideMenu;}

  virtual void sideMenuAdd(string _sideName)=0;
  virtual void showSideMenu()=0;
  virtual void addFood()=0;
};

class Pizza : public DeliveryFood{
private:
  map<string,int>pizzaSide;
  int price;

public:
  Pizza(int p):price(p){
    pizzaSide = {{"cola",2000},{"fried potato", 3000}, {"sprite", 2000}};
  }
  void addFood()override{
    totalPrice+=price;
  }

  void sideMenuAdd(string _sideName)override{
    auto it = pizzaSide.find(_sideName);
    if(it != pizzaSide.end()){
      totalPrice += it->second;
      sideMenu+=(sideMenu.empty() ? "" : ", ") + _sideName;
    }
  }

  void showSideMenu()override{
    int index = 1;
    for(const auto& item : pizzaSide){
      cout<<index++<<". "<<item.first<<" "<<item.second<<"\n";
    }
  }

  virtual ~Pizza(){}
};

class Chicken : public DeliveryFood{
private:
  map<string, int>chickenSide;
  int price;

public:
  Chicken(int p): price(p){
    chickenSide = {{"cheese ball", 4000}, {"cola", 2000}, {"fried potato", 3000}, {"sprite", 2000}};
  }
  
  void addFood()override{
    totalPrice+=price;
  }
  void sideMenuAdd(string _sideName)override{
    auto it = chickenSide.find(_sideName);
    if(it != chickenSide.end()){
      totalPrice += it->second;
      sideMenu += (sideMenu.empty() ? "" : ", ") + _sideName;
    }
  }

  void showSideMenu()override{
    int index = 1;
    for(const auto& item : chickenSide){
      cout<<index++<<". "<<item.first<<" "<<item.second<<"\n";
    }
  }

  virtual ~Chicken(){}
};

void chooseSideMenu(DeliveryFood* food){
  food->showSideMenu();
  int choice;
  cout<<"select side menu: ";
  cin>>choice;

  string sideMenuItem;
  if(dynamic_cast<Pizza*>(food)){
    switch(choice){
      case 1: sideMenuItem = "cola"; break;
      case 2: sideMenuItem = "fried potato"; break;
      case 3: sideMenuItem = "sprite"; break;
    }
  }
  else if(dynamic_cast<Chicken*>(food)){
    switch(choice){
      case 1: sideMenuItem = "cheese ball"; break;
      case 2: sideMenuItem = "cola"; break;
      case 3: sideMenuItem = "fried potato"; break;
      case 4: sideMenuItem = "sprite"; break;
    }
  }
  food->sideMenuAdd(sideMenuItem);
  food->addFood();
  cout<<food->getSideMenu()<<" total price: "<<food->getTotalPrice()<<"\n";
}

int main(){
  DeliveryFood* margheritaPizza = new Pizza(12000);
  DeliveryFood* gorgonzolaPizza = new Pizza(15000);
  DeliveryFood* friedChicken = new Chicken(17000);
  DeliveryFood* spicyChicken = new Chicken(19000);

  int chooseFoodNum = 0;
  cout<<"1. margherita pizza"<<"\n";
  cout<<"2. gorgonzola pizza"<<"\n";
  cout<<"3. fried chicken"<<"\n";
  cout<<"4. spicy chicken"<<"\n";
  cout<<"choose food: ";
  cin>>chooseFoodNum;

  switch(chooseFoodNum){
    case 1: chooseSideMenu(margheritaPizza); break;
    case 2: chooseSideMenu(gorgonzolaPizza); break;
    case 3: chooseSideMenu(friedChicken); break;
    case 4: chooseSideMenu(spicyChicken); break;
  }

  delete margheritaPizza;
  delete gorgonzolaPizza;
  delete friedChicken;
  delete spicyChicken;

  return 0;
}
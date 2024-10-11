#include <iostream>
using namespace std;

class Printer{
private:
  int availableCount;
  int availablePage;
public:
  Printer(int ac, int ap): availableCount(ac), availablePage(ap){}
  void print(int usedPage){
    availableCount -= usedPage;
    availablePage -= usedPage;
  }
  int getAvailableCount(){
    return availableCount;
  }
  int getAvailablePage(){
    return availablePage;
  }
};

class InkjetP : public Printer{
private:
  string model;
  string manufacturer;
public:
  InkjetP(int ac, int ap, string model, string manufacturer): Printer(ac,ap), model(model), manufacturer(manufacturer) {}
  void print(int usedPage){
    if(usedPage > getAvailableCount()){
      cout<<"Cannot print because of not enough ink.\n";
    }
    else if(usedPage > getAvailablePage()){
      cout<<"Connot print because of not enough pages.\n";
    }
    else{
      Printer::print(usedPage);
      cout<<"Printed.\n";
    }
  }
  void showInfo(){
    cout<<"InkJet: "<<model<<", "<<manufacturer<<", "<<getAvailablePage()<<" available paged, "<<getAvailableCount()<<" available Ink\n";
  }
};

class LaserP : public Printer{
private:
  string model;
  string manufacturer;
public:
  LaserP(int ac, int ap, const string &model, const string &manufacturer): Printer(ac, ap),model(model), manufacturer(manufacturer){}
  void print(int usedPage){
    if(usedPage > getAvailableCount())cout<<"Cannot print because of not enough toner.\n";
    else if(usedPage > getAvailablePage())cout<<"Cannot print because of not enough pages.\n";
    else{
      Printer::print(usedPage);
      cout<<"Printed.\n";
    }
  }
  void showInfo(){
    cout<<"Laser: "<<model<<", "<<manufacturer<<", "<<getAvailablePage()<<" available pages, "<<getAvailableCount()<<" available toner\n";
  }
};

int main(){
  cout<<"Currently operating 2 printers are follow\n";
  int ac, ap;
  cin>>ap>>ac;
  InkjetP ink(ac, ap, "Officejet V30", "HP");
  ink.showInfo();
  cin>>ap>>ac;
  LaserP toner(ac,ap,"SCX-x47", "Samsung");
  toner.showInfo();

  while(true){
    int command, pages;
    string con;
    cout<<"\n";
    cout<<"Insert printer(1:InkJet, 2:Laser) and pages: ";
    cin>>command>>pages;

    if(command == 1){
      ink.print(pages);
      ink.showInfo();
      toner.showInfo();
    }
    else if(command == 2){
      toner.print(pages);
      ink.showInfo();
      toner.showInfo();
    }
    cout<<"Do you want keep printing?(y/n)>>";
    cin>>con;
    if(con == "y" || con == "Y") continue;
    else return 0;
  }
}
#include <iostream>
using namespace std;

class Printer{
private:
  int availableCount; //ink or toner capacity
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

class InkjetP : public Printer{//ac == ink
private:
  const string model = "Officejet V30";
  const string manufacturer = "HP";
public:
  InkjetP(int ac, int ap): Printer(ac,ap){}
  void print(int usedPage){
    if(usedPage > getAvailableCount())cout<<"Cannot print because of not enough ink.\n";
    else if(usedPage > getAvailablePage())cout<<"Cannot print because of not enough page.\n";
    else{
      cout<<"Printed.\n";
      Printer::print(usedPage);
    }
  }
  void showInfo(){
    cout<<"InkJet: "<<model<<", "<<manufacturer<<", "<<Printer::getAvailablePage()<<" available pages, "<<Printer::getAvailableCount()<<" available Ink\n";
  }
};

class Laser : public Printer{
private:
  const string model = "SCX-6x47";
  const string manufacturer = "Samsung";
public:
  Laser(int ac, int ap): Printer(ac,ap){}
  void print(int usedPage){
    if(usedPage > getAvailableCount())cout<<"Cannot print because of not enought toner.\n";
    else if(usedPage > getAvailablePage())cout<<"Cannot print because of not enough page.\n";
    else{
      cout<<"Printed.\n";
      Printer::print(usedPage);
    }
  }
  void showInfo(){
    cout<<"Laser: "<<model<<", "<<manufacturer<<", "<<Printer::getAvailablePage()<<" available pages, "<<Printer::getAvailableCount()<<" available Toner\n";
  }
};

int main(){
  cout<<"Currently operating 2 printers are follow\n";
  int ac, ap;
  cin>>ap>>ac;
  InkjetP inkPrinter(ac,ap);
  inkPrinter.showInfo();
  cin>>ap>>ac;
  Laser tonerPrinter(ac,ap);
  tonerPrinter.showInfo();
  cout<<"\n";

  while(true){
    int command, pages;
    string continous;
    cout<<"Insert printer(1:InkJet, 2:Laser) and pages: ";
    cin>>command>>pages;
    if(command == 1){
      inkPrinter.print(pages);
      inkPrinter.showInfo();
      tonerPrinter.showInfo();
      cout<<"Do you want keep printing?(y/n)>>";
      cin>>continous;
      if(continous == "y" || continous == "Y"){
        cout<<"\n";
        continue;
      }
      else return 0;
    }
    else if(command == 2){
      tonerPrinter.print(pages);
      inkPrinter.showInfo();
      tonerPrinter.showInfo();
      cout<<"Do you want keep printing?(y/n)>>";
      cin>>continous;
      if(continous == "y"||continous=="Y"){
        cout<<"\n";
        continue;
      }
      else return 0;
    }
  }
}
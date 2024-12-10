#include <iostream>
using namespace std;

class Book{
  string title;
  int price, pages;

public:
  Book(string title = "", int price=0, int pages=0){
    this->title = title;
    this->pages = pages;
    this->price=price;
  }
  void show(){
    cout<<"Book: "<<title<<" "<<price<<" won "<<pages<<" pages\n";
  }
  friend bool operator==(const Book& a, const string& s);
  friend bool operator==(const Book& a, const int& p);
  friend bool operator==(const Book& a, const Book& b);
};

bool operator==(const Book& a, const string&s){
  return a.title == s;
}

bool operator==(const Book& a, const int& p){
  return a.pages == p;
}

bool operator==(const Book& a, const Book& b){
  return((a.pages==b.pages) && (a.price==b.price) && (a.title==b.title));
}

int main(){
  Book a("Dune1", 30000, 500), b("Dune2", 30000,500);
  a.show();

  if(a == "Dune1")cout<<"Dune1"<<'\n';
  if(a == 500)cout<<30000<<'\n';
  if(a == b)cout<<"same";
}
#include <iostream>
#include <string>
using namespace std;

class Book{
  string title;
  int price, pages;

public:
  Book(string title = "", int price = 0, int pages = 0){
    this->title = title;
    this->price = price;
    this->pages = pages;
  }

  void show(){
    cout<<"Book: "<<title<<" "<<price<<" won "<<pages<<" pages"<<endl;
  }

  friend bool operator == (const Book& book, const string& t){
    return book.title == t;
  }
  friend bool operator == (const Book& book, int p){
    return book.price == p;
  }
  friend bool operator == (const Book& book1, const Book& book2){
    return book1.title == book2.title && book1.price == book2.price && book1.pages == book2.pages;
  }
};

int main(){
  Book a("Dune1", 30000, 500), b("Dune2", 30000, 500);
  a.show();
  if(a=="Dune1")cout<<"This book is Dune1"<<endl;
  if(a==30000)cout<<"Original price is 30000 won"<<endl;
  if(a==b)cout<<"They are the same book"<<endl;
}
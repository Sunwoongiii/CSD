#include <iostream>
using namespace std;
int n;

class Library{
  private:
    string* _title;
    string* _author;
    int *_price;

  public:
    Library(int num){
      _title = new string[num];
      _author = new string[num];
      _price = new int[num];
    }
    void setBookInfo(int index, string title, string author, int price){
      _title[index] = title;
      _author[index] = author;
      _price[index] = price;
    }

    void showBookList(){
      for(int i = 0; i < n; i++){
        cout<<"Book "<<i+1<<": "<<_title[i]<<"\n";
        cout<<_author[i]<<" / "<<_price[i]<<"\n";
      }
    }

    ~Library(){
      delete[] _title;
      delete[] _author;
      delete[] _price;
    }
};

int main(){
  int bookPrice;
  cout<<"How many register book: ";
  cin>>n;
  cin.ignore();
  string bookName, bookAurthor;
  Library bookList(n);

  for(int i = 0; i < n; i++){
    cout<<"Book title: ";
    getline(cin, bookName);
    cout<<"Book author: ";
    getline(cin, bookAurthor);
    cout<<"Book price: ";
    cin>>bookPrice;
    cin.ignore();

    bookList.setBookInfo(i, bookName, bookAurthor, bookPrice);
  }
  bookList.showBookList();
}
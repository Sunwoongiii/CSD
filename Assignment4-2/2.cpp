#include <iostream>
using namespace std;

class Time{
  private:
    int _hour, _minute, _second;
  
  public:
    Time(){
      _hour = 0;
      _minute = 0;
      _second = 0;
    }

    void setTime(int hour, int minute, int second){
      this->_hour = hour;
      this->_minute = minute;
      this->_second = second;
    }

    void addTime(Time T1, Time T2){
      this->_second = T1._second + T2._second;
      this->_minute = T1._minute + T2._minute + this->_second/60;
      this->_second %= 60;

      this->_hour = T1._hour + T2._hour + this->_minute/60;
      this->_minute %= 60;
    }

    void showTime(){
      cout<<"Total time: ";
      if(_hour < 10) cout<<0<<_hour<<":";
      else cout<<_hour<<":";

      if(_minute<10)cout<<0<<_minute<<":";
      else cout<<_minute<<":";

      if(_second < 10)cout<<"0"<<":";
      else cout<<_second;
      // cout<<_hour<<" : "<<_minute<<" : "<<_second;
    }
};

int main(){
  Time T1;
  Time T2;
  Time T3;
  int h,m,s;

  cout<<"Hours: ";
  cin>>h;
  cout<<"Minutes: ";
  cin>>m;
  cout<<"Seconds: ";
  cin>>s;
  cout<<"\n";
  T1.setTime(h,m,s);

  cout<<"Hours: ";
  cin>>h;
  cout<<"Minutes: ";
  cin>>m;
  cout<<"Seconds: ";
  cin>>s;
  cout<<"\n";
  T2.setTime(h,m,s);
  
  T3.addTime(T1, T2);
  T3.showTime();
}
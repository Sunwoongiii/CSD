#include <iostream>
#include <string>

using namespace std;

class Flight{
  private:
    string flightNum;
    string flightDep;
    string flightDes;
    float dis;
    float fuel;
    float calFuel(){
      if(dis <= 1000) return 500;
      else if(dis <= 2000) return 1500;
      else return 3000;
    }

  public:
    void flightInfo(){
    cout<<"Flight number: ";
    cin>>flightNum;
    cout<<"Departure: ";
    cin>>flightDep;
    cout<<"Destination: ";
    cin>>flightDes;
    cout<<"Distance: ";
    cin>>dis;

    while(dis <= 100){
      cout<<"Distance should be longer than 100\n";
      cout<<"Distance: ";
      cin>>dis;
    }
    fuel = calFuel();
    }
    
    void showFlightInfo(){
      cout<<"\n**Flight Information**";
      cout<<"\nFlight Number: "<<flightNum<<"\n";
      cout<<"Departure / Distinagion: "<<flightDep<<" / "<<flightDes<<"\n";
      cout<<"Distance: "<<dis<<" Km\n";
      cout<<"Fuel: "<<fuel;
    }
};

int main(){
  Flight flight;
  flight.flightInfo();
  flight.showFlightInfo();
  return 0;
}
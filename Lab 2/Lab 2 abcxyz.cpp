#include <iostream>
#include <stdlib.h>
#include <string>
#include <ctime>
using namespace std;

class meeting {
  private:                  
    int date;               // Private attribute
    int time;               // Private attribute
    int duration;           // Private attribute
    string list[20];        // Private attribute
    
  public:                   
    string subject;         // Public attributes        
    string organizer;       // Public attributes      
            
    void setDuration(int d) {               // Setter for duration attribute
      duration = d;
    }
    
    int getDuration() {                     // Getter for duration attribute
      return duration;
    }
    void setTime(int t) {                   // Setter for time attribute
      time = t;
    }
    
    int getTime() {                         // Getter for time attribute
      return time;
    }
    
    void setList(string p, int i) {         // Setter for list attribute
      list[i] = p;
    }
    
    void getList() {                        // Getter for list attribute
      for (int i = 0; i < 20; i++) {
        cout << list[i] << "  ";
      }
      cout << endl;
    }
    
};

int yearnow(){
  time_t t = time(0);   // get time now
  tm* now = localtime(&t);   
  return now->tm_year + 1900;
}

int monthnow(){
  time_t t = time(0);   // get time now
  tm* now = localtime(&t);  
  return now->tm_mon + 1;
}

int daynow(){
  time_t t = time(0);   // get time now
  tm* now = localtime(&t);  
  return now->tm_mday;
}

int main (){
  int x, f, a, b, c, dt, mth, yr ;  // a,b,c is year, month, day at the moment                                
  char p;
  string n, s, o;
  meeting myObj;


  while (f != 9){
    cout << "Press 1 to set meeting subject." << endl;
    cout << "Press 2 to set meeting organizer." << endl;
    cout << "Press 3 to set meeting duration." << endl;
    cout << "Press 4 to set meeting time." << endl;
    cout << "Press 5 to set meeting date." << endl;
    cout << "Press 6 to add a participant to the meeting." << endl;
    cout << "Press 7 to clear participant list." << endl;
    cout << "Press 8 to get meeting reminder." << endl;
    cout << "Press 9 to exit." << endl;
    cin >> f;
    switch (f) {
      case 1:
        cout << "Please enter meeting subject: ";     // Set Subject
        cin >> s;
        myObj.subject = s;
        break;
      case 2:
        cout << "Please enter your name: ";     // Set Organizer
        cin >> o;
        myObj.organizer = o; 
        break;
      case 3:
        cout << "Please set meeting duration (minutes): ";
        cin >> x;
        while (x <= 0) {
          cout << "Invalid value, please re-enter: ";
          cin >> x;
        }
        myObj.setDuration(x);
        break;
      case 4:
        cout << "Thursday";
        break;
      
      case 5:
        cout << "Input day, month, and year"<<endl;
        cin >> dt >> mth >> yr; // dt, mth,yr is day input
        a = yearnow();
        b = monthnow();
        c = daynow();
        while (a > yr ){
          if (a > yr){
            cout << "Please submit the year again: ";
            cin >> yr;

          }
        }
        while (b > mth){
          if (a == yr){
            if(b > mth){
            cout << "Please submit the month again: ";
            cin >> mth;
            }
          }
        }
        break;


        while (c > dt ){
          if (a == yr && b == mth ){
            if (c> dt){
            cout << "Please submit the day again: ";
            cin >> dt;
            }
          }
        }
        
      case 6:
        for (int y = 0; y < 20; y++){
          cout << "Would you like to add a participant to the meeting? (Y/N)"; 
          cout << endl;
          cin >> p;
        if (p == 'Y'){
          cout << "Please enter participant's name: ";
          cout << endl;
          cin.ignore();
          getline(cin, n);
          myObj.setList(n,y);
        }
        else if(p == 'N'){
          break;
        }
        }  ;
        break;
      case 8:
        cout << "Meeting subject: "<< myObj.subject;
        cout << endl;
        cout << "Meeting organizer: "<< myObj.organizer;
        cout << endl;
        cout << "Participant(s): "; 
        myObj.getList();
        cout << "The meeting duration is: " << myObj.getDuration() << " minutes" << endl;
        break;
      }
    }
    return 0;
}

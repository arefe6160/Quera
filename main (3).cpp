#include <iostream>
#include <vector>
#include <string>
#include <regex>
using namespace std;
class Time{
public:
    int hour;
    int minute;
    int second;
    Time(int h,int m,int s) {
        hour = h;
        minute=m;
        second = s;
    }
    Time(){
        hour=0;
        minute=0;
        second=0;
    }
};
class Date{
public:
    int year;
    int month;
    int day;
    Date(int y, int m, int d) {
        year=y;
        month =m;
        day = d;
    }
     Date(){
        year = 0;
        month = 0;
        day = 0;
    }
};
class Penalty{
public:
    static int counter;
    int num;
    string plaque;
    int amountPenalty;
    Date date;
    Time time;

    Penalty(string pl,int amount,Date d,Time t) {
        plaque = pl;
        amountPenalty=amount;
        date=d;
        time=t;
        num=++counter;
    }
};
int Penalty::counter = 0;
bool isValidPlaque(string plaque){
    regex pattern("^\\d{2}-[A-Za-z]-\\d{3}$");
    return regex_match(plaque, pattern);
}

class Police{
public:
    vector<Penalty> penalties;
void SavePenalty(string plaque,int amount,Date date,Time time){
    if (!isValidPlaque(plaque)){
        cout<<"Invalid plaque format! Example: 12-A-358\n";
        return;
    }
    penalties.push_back(Penalty(plaque, amount, date, time));
    cout<<"Penalty successfully recorded.\n";
}
    void ShowPenalty(string plaque) {
        for(int i = 0; i < penalties.size(); i++){
            if(penalties[i].plaque == plaque){
                cout<<"Num: "<<penalties[i].num<<"\n";
                cout<<"Date: "<<penalties[i].date.year <<"/"<<penalties[i].date.month << "/" << penalties[i].date.day << "\n";
                cout<<"Time: "<<penalties[i].time.hour <<":"<<penalties[i].time.minute << ":" << penalties[i].time.second << "\n";
                cout<<"Amount: "<<penalties[i].amountPenalty<<"\n\n";
            }
        }
    }
void PaymentPenalty(int num){
    vector<Penalty> newPenalties;
    bool found=false;

    for(int i=0;i<penalties.size();i++){
        if(penalties[i].num==num){
            found = true;
        }else{
            newPenalties.push_back(penalties[i]);
        }
    }

    if(found){
        penalties = newPenalties;
        cout<<"Penalty "<<num<<" paid and removed.\n";
    } else{
        cout<<"Penalty not found.\n";
    }
}
};
int main()
{
    Police police;
    string cmd;
    cout<<"Enter commands (type 'exit' to quit):\n";

    while(true) {
        cout<<"\n> ";
        cin>>cmd;

        if(cmd=="exit")break;

        if(cmd=="savepenalty"){
            string plaque;
            int amount;
            int y,m,d,h,mi,s;

            cin >> plaque>>amount>>y>>m>>d>>h>>mi>>s;

            Date date(y, m, d);
            Time time(h, mi, s);

            police.SavePenalty(plaque,amount,date,time);
        }

        else if(cmd=="paypenalty"){
            int num;
            cin>>num;
            police.PaymentPenalty(num);
        }

        else if(cmd =="showpenalty"){
            string plaque;
            cin>>plaque;
            police.ShowPenalty(plaque);
        }
    }
    return 0;
}

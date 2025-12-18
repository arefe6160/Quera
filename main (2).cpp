#include <iostream>

using namespace std;

int main()
{
    long long unsigned int boodje;
    cin>>boodje;
    unsigned int x,y,z;
    cin>>x;
    cin>>y;
    cin>>z;

if(boodje>=x) {
        cout<<"Watermelon"<<endl;
    }else if(boodje>=y){
        cout<<"Pomegranates"<<endl;
    }else if(boodje>=z) {
        cout<<"Nuts"<<endl;
    }else{
        cout<<"Nothing"<<endl;
    }
}

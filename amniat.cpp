#include <iostream>

using namespace std;
bool finder (string&url,string&kalame);
int leng(string a);
void ignorenter();
int main()
{
    int x;
    string a[50];

    cin>>x;
    ignorenter();
    for(int i=0;i<x;i++){
        cin>>a[i];

    }
    string url;

    cin>>url;

    for(int i=0;i<x;i++){
        if (finder(url,a[i])){
            cout<<"BLOCKED"<<endl;
            return 0;
        }
    }cout<<"ALLOWED"<<endl;
    return 0;
}
int leng(string a){
    int length=0;
    while (a[length] != '\0') {
        length++;
    }
    return length;
}

bool finder (string&url,string&kalame){
    for(int i=0;i<leng(url)-leng(kalame);i++){
            bool found = true;
            for(int j=0;j<leng(kalame);j++){
                if (url[i+j]!=kalame[j]){
                    found = false;
                    break;
                }
            }if (found) {
            return true;
        }
    }return false;
}
void ignorenter(){
    char ch;
    while (cin.get(ch)) {
        if (ch=='\n'){
            break;
            }
    }
}


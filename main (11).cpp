#include <iostream>

using namespace std;

int main()
{
  string a="";
  int b=0;
  int c=0;
  int length = 0;
  cin>>a;
    while (a[length]!='\0') {
        length++;
} for (int i=0;i<length;i++){
    int x=a[i];
    if(x>96&&x<123){
        c++;
    }else{
        b++;
    }
}switch(b>c){
    case true:
       for(int i=0;i<length;i++){
          if(a[i]>96&&a[i]<123){
            a[i]=char(a[i]-32);
          }
       }
        break;
    case false:
        for (int i=0;i<length;i++) {
            if (a[i]>64&&a[i]<91) {
              a[i]=char(a[i]+32);
            }
        }
        break;
        }
  cout<<a;
}

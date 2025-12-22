#include <iostream>
#include <string>
using namespace std;

int leng(string a){
    int length=0;
    while (a[length] != '\0') {
        length++;
    }
    return length;
}

string maratab(string x){
    string numbers = "";

    for(int i= 0;i<leng(x);i++){
        if (x[i]>='0'&&x[i]<='9'){
            numbers+=x[i];
        }
    }
    for(int i=0;i<leng(numbers)-1;i++){
        for(int j=i+1;j<leng(numbers);j++){
            if(numbers[i]>numbers[j]){
                char temp=numbers[i];
                numbers[i]=numbers[j];
                numbers[j]=temp;
}
}
}int idx=0;
    string result="";
    for(int i=0;i<leng(x);i++){
        if(x[i]>='0'&&x[i]<='9'){
            result+=numbers[idx++];
        }else{
            result+=x[i];
}
}
return result;
}
int main(){
    int d;
    cin>>d;
    string x;
    cin>>x;
    string moratab_x=maratab(x);
    cout<<moratab_x<<endl;

    return 0;
}


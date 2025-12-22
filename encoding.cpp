#include <iostream>

using namespace std;
string coadgozari(char a[],int length);
string ramsgoshaii(string a,int length);
int main()
{
    int n;
    cin>>n;
    char a[n][100]={0};
    for (int i=0;i<n;i++){
       cin>>a[i];
}
    for (int i=0;i<n;i++){

        int length=0;
        while(a[i][length]!='\0'){
            length++;
    }
    string z=coadgozari(a[i],length);
    string z2=ramsgoshaii(z,length);
    cout <<z<<endl;
    cout <<z2<<endl;
}}
string coadgozari(char a[],int length){
    string x="";
    int j=(length+1)/2;
    for(int i=0,k=j;i<j||k<length;i++,k++) {
    if(i<j) {
        x+=a[i];
    }
    if(k<length) {
        x+=a[k];
    }}


    return x;
}
string ramsgoshaii(string a,int length){
    string x="";
     for(int i=0;i<length;i+=2){
        x+=a[i];
    }
    for(int j=1;j<length;j+=2){
        x+=a[j];
    }
    return x;
}




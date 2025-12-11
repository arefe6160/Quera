#include <iostream>

using namespace std;

int main()
{
    int x;
    cin>>x;
    int a[x];
    for(int i=0;i<x;i++){
        cin>>a[i];
    }
    int s=0;

    for(int i=1;i<x;i+=2){
        s+=a[i];
    }

    cout<<s<<endl;
    return 0;
}

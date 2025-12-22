#include <iostream>

using namespace std;
bool aval(int a){
    if (a<2) return false;

    for(int i=2;i<a;i++){
        if (a%i==0){
            return false;
        }
}return true;

}
int main()
{int a,b;
    cin>>a>>b;
    for(int i=a;i<=b;i++){
        if (aval(i)==true){
            cout<<i<<" ";
        }
    }cout<<endl;
}


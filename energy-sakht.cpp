#include <iostream>

using namespace std;
int main()
{
   int a,b;
   cin>>a>>b;
   int m[a][b];

   for(int i=0;i<a;i++){
    for(int j=0;j<b;j++){
        cin>>m[i][j];
    }
   }
   int energy=0;

    for(int i=0;i<a;++i){
        for(int j=0;j<b;++j){
            if(j<b-1) {
                int k=m[i][j]-m[i][j+1];
                energy+=(k<0) ? -k : k;
            }
            if(i<a-1) {
                int k= m[i][j]-m[i+1][j];
                energy+=(k<0) ? -k: k;
            }
        }
    }
    cout<<energy<<endl;

}


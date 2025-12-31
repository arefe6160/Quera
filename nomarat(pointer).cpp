#include <iostream>

using namespace std;
void bishine_kamine(int *arr,int sizeofarry){

    int *max1=arr;//arr[0]
    int *min1=arr;

    for(int i=1;i<sizeofarry;i++){
        if(*(arr+i)>*max1){
            max1=arr+i;
        }
        if(*(arr+i)<*min1){
        min1=arr+i;
    }
    }
    cout<< "max:" <<*max1<<endl;
    cout<< "min:" <<*min1<<endl;

}
void majmo(int *arr,int sizeofarry){
    int majmo=*(arr);
    for(int i=1;i<sizeofarry;i++){
        majmo+=*(arr+i);
    }
    cout<< "majmo:" <<majmo<<endl;

}
void miangin(int *arr,int sizeofarry){
    double miangin=0;
    int majmo=0;
    for(int i=0;i<sizeofarry;i++){
       majmo+=*(arr+i);
    }
    miangin+=(double)majmo/sizeofarry;
    cout<< "miangin:" <<miangin<<endl;
}
void baraks(int *arr,int sizeofarry){
    int *right=arr+sizeofarry-1;
    int *left=arr;

    while (left < right) {
       int temp=*left;
        *left=*right;
        *right=temp;
        left++;
        right--;
    }
    for (int i=0;i<sizeofarry;++i) {
        cout <<*(arr+i)<<" ";
    }
    cout << endl;
}

int main(){
    int n;
    cin>>n;
    int *arr=new int[n];//dynamic

    for(int i=0;i<n;++i){
        cin >> *(arr+i);//arr[i]
    }
     bishine_kamine(arr,n);
     majmo(arr,n);
     miangin(arr,n);
     baraks(arr,n);
    delete[] arr;

}


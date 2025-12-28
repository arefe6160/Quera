#include <iostream>

using namespace std;

void my_strlen(char *s){
    int x=0;
    while(*s != '\0'){
        x++;
        s++;
    }
    cout<<"len:"<<x<<endl;

}
void to_uppercase(const char* s){
    int len = 0;
    while (s[len] != '\0'){
         len++;
    }

    char *s2=new char[len+1];

    for (int i = 0; i <= len; ++i) {
        s2[i] = s[i];
    }

    for (int i=0;s2[i] !='\0';i++){
        if(s2[i]>='a'&&s2[i]<='z') {
            s2[i]-=32;
        }
    }
    cout <<"uppercase:"<<s2<< endl;
    delete[] s2;
}
void reverse_string(char* s){
    int x=0;

    while(s[x] != '\0'){
        x++;
    }

    char *right=s+x-1;
    char *left=s;
 while (left < right) {
        char temp1 = *left;
        *left = *right;
        *right = temp1;

        left++;
        right--;
    }
    cout <<"revers:"<<s<<endl;


}
void count_substring(char *s,char *sub){
    int count1 = 0;
    int len = 0;

    while(*(sub+len)!='\0') {
        len++;
    }

    while(*s != '\0') {
        char *p = s;
        int i = 0;
        while(*(p+i)!='\0'&&*(sub+i)!='\0'&&*(p+i)==*(sub+i)){
            i++;
        }
        if(i==len){
            count1++;
        }
        s++;
    }

    cout<<"Tedad tekrar: "<< count1<<endl;
}

int main()
{   int n,i;
    cin >>n;

    cin.ignore();

    char ch;

    char *buffer =new char [n+1];
    for(i=0;i<n;i++){
        cin.get(ch);
        if (ch == '\n') {
            break;
        }
        buffer[i] = ch;
    }
    buffer[i]='\0';

    my_strlen(buffer);

    char *buffer_copy = new char[n + 1];
    for(int i=0; buffer[i]!='\0'; ++i) {
        buffer_copy[i]=buffer[i];
    }
    buffer_copy[i]='\0';


    to_uppercase(buffer_copy);
    reverse_string(buffer_copy);

    delete[] buffer_copy;


    int m;//طول زیررشته
    cout << "enter tool zirreshte:"<<endl;
    cin>>m;

    cin.ignore();
    char *sub=new char[m+1];
    char cha;
    cout << "enter the zirreshte:"<<endl;
    for(i=0;i<m;i++){
        cin.get(cha);
        if(cha=='\n') {
            break;
        }
        sub[i]=cha;
    }
    sub[i]='\0';

    count_substring(buffer,sub);
    delete[] sub;
    delete[] buffer;
}


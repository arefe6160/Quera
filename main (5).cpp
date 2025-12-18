#include <iostream>
#include <vector>
using namespace std;

bool compare(const pair<string,string>&a,const pair<string,string>&b)
{
    if(a.second==b.second)
        return a.first<b.first;
    return a.second<b.second;
}

int main()
{
    string x;
    getline(cin,x);

    int c=1;
    for(int i=0;i<x.length();i++)
    {
        if(x[i]==','&&x[i+1]==' ')
        {
            c++;
        }
    }

    vector<string>esm(c);
    string name;
    int z=0;
    for(int i=0;i<x.length();i++)
    {
        if(x[i]!=','&&x[i+1]!=' ')
        {
            if(x[i]==' ')
            {
                continue;
            }
            esm[z]+=x[i];
        }
        else
        {
            z++;
        }
    }

    vector<pair<string,string>>rozane(c);
    vector<pair<string,string>>shabanehList(c);

    int rozaneCount=0,shabanehCount=0;

    for(int i=0;i<c;i++)
    {
        string esm_str="",famili_str = "";
        bool shabanehh=false;

        int ma=-1;
        int upperCaseCount=0;

        for(int j=0;j<esm[i].length();j++)
        {
            if(esm[i][j]>='A'&&esm[i][j]<='Z')
            {
                upperCaseCount++;
                if(upperCaseCount==2)
                {
                    ma=j;
                    break;
                }
            }
        }
        if(ma!=-1) {
            string esme_a="",famili_a="";

            for(int j=0;j<ma;j++)
            {
                esme_a+=esm[i][j];
            }
            for(int j=ma;j<esm[i].length();j++)
            {
                famili_a+=esm[i][j];
            }

            if(famili_a[famili_a.length()-1]==')')
            {
                shabanehh=true;
                famili_a=famili_a.substr(0,famili_a.length()-3);
            }

            if(shabanehh)
            {
                shabanehList[shabanehCount++]= {esme_a,famili_a};
            }
            else
            {
                rozane[rozaneCount++]={esme_a,famili_a};
            }
        }
    }
    for(int i=0;i<rozaneCount-1;i++)
    {
        for(int j=0;j<rozaneCount-i-1;j++)
        {
            if(compare(rozane[j+1],rozane[j]))
            {
                pair<string,string>temp=rozane[j];
                rozane[j]=rozane[j+1];
                rozane[j+1]=temp;
            }
        }
    }

    for(int i=0;i<shabanehCount-1;i++)
    {
        for(int j=0;j<shabanehCount-i-1;j++)
        {
            if(compare(shabanehList[j+1],shabanehList[j]))
            {
                pair<string,string>temp=shabanehList[j];
                shabanehList[j]=shabanehList[j+1];
                shabanehList[j+1]=temp;
            }
        }
    }
    for(int i=0;i<rozaneCount;i++)
    {
        cout<<rozane[i].first<<rozane[i].second<<" 403111260";
        if(i+1<10)
        {
            cout<<'0';
        }
        cout<<i + 1<<endl;
    }
    for(int i=0; i<shabanehCount; i++)
    {
        cout<<shabanehList[i].first<<shabanehList[i].second<<" 403121260";
        if(i+1<10)
        {
            cout<<'0';
        }
        cout<<i+1<<endl;
    }

    return 0;
}

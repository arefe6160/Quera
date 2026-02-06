
#include <iostream>
#include <regex>

using namespace std;
class namotabar{
public:
    bool emailcheck(string&email) {
        regex x(R"(^[A-Za-z0-9.-]+@[A-Za-z0-9]+\.[A-Za-z]{2,}(\.[A-Za-z]{2,})?$)");
        return regex_match(email,x);
        }

    bool ipcheck(string&ip) {
    string x=R"(^)";
    x += R"((25[0-5]|2[0-4][0-9]|1[0-9]{2}|[1-9]?[0-9])\.)";
    x += R"((25[0-5]|2[0-4][0-9]|1[0-9]{2}|[1-9]?[0-9])\.)";
    x += R"((25[0-5]|2[0-4][0-9]|1[0-9]{2}|[1-9]?[0-9])\.)";
    x += R"((25[0-5]|2[0-4][0-9]|1[0-9]{2}|[1-9]?[0-9]))";
    x += R"((:(6553[0-5]|655[0-2][0-9]|65[0-4][0-9]{2}|6[0-4][0-9]{3}|[1-5]?[0-9]{1,4}))?$)";

    regex y(x);
    return regex_match(ip,y);
    }
    bool colorcheck(string&color) {
        regex x(R"(^#[0-9A-Fa-f]{6}$)");
        return regex_match(color,x);
    }

    bool URLcheck(string&url) {
        regex x(R"(^(https:\/\/)(www\.)?[A-Za-z0-9-]+\.[A-Za-z]{2,}(\.[A-Za-z]{2,})?$)");
        return regex_match(url,x);
    }
};


int main()
{
    namotabar check;


    string email1 = "user.name@example.com";
    string email2 = "user@@example";
    cout <<email1<<" : "<<(check.emailcheck(email1) ? "dorost":"ghalat")<<endl;
    cout <<email2<<" : "<<(check.emailcheck(email2) ? "dorost":"ghalat")<<endl;

    string ip1="192.168.1.1";
    string ip2="256.300.1.1:99999";
    cout<<ip1<<" : "<<(check.ipcheck(ip1) ? "dorost":"ghalat")<<endl;
    cout<< ip2<<" : "<<(check.ipcheck(ip2) ? "dorost":"ghalat")<<endl;

    string color1="#FFA621";
    string color2="#ZZZZZZ";
    cout <<color1<<" : "<<(check.colorcheck(color1) ? "dorost":"ghalat")<<endl;
    cout <<color2<<" : "<<(check.colorcheck(color2) ? "dorost":"ghalat")<<endl;

    string url1="https://my-dev.co.ir";
    string url2="http://site..com";
    cout<<url1 <<" : "<<(check.URLcheck(url1) ? "dorost":"ghalat")<<endl;
    cout<<url2<<" : " <<(check.URLcheck(url2) ? "dorost":"ghalat")<<endl;

}

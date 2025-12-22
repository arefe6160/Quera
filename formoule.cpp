#include <iostream>
using namespace std;

int main() {
    long long int x;
    long long int f = 0;
    cin >> x;
    long long int fard_t=(x+1)/2;
    long long int fard_sum=fard_t*fard_t;

    long long int zoj_t=x/2;
    long long int zoj_sum=zoj_t*(zoj_t+1);

    f=zoj_sum-fard_sum;
    cout << f;

    return 0;
}

#include <iostream>
#include <math.h>
using namespace std;

int breakEvenPoint(int exp,int S,int M)
{
    float earn = S - M ;

    int res = ceil(exp /earn);

    return res;
}

int main()
{
    int exp = 3550, S = 90 , M = 65;
    cout << breakEvenPoint(exp,S,M);
    return 0;

}
/*Find the power received from a base station antenna at distance d,
where power received at d0 is given from keyboard.
If minimum acceptable power is also given,
then find the maximum cell radius if the BS is in the center of cell.
Set path loss exponent, n = 4. */

#include<bits/stdc++.h>
using namespace std;

int main()
{
    float Pt, Pr, Pmin, n, d, d0, PT, R;

    cout<<"Power received at d0 is (dBm): "; cin>>Pt;
    cout<<"Value of d0 is (m): "; cin>>d0;
    cout<<"Input path loss exponent, n = "; cin>>n;
    cout<<"Input distance from base station(m): "; cin>>d;

    Pr = Pt - 10.0*n*log10(d/d0);

    printf("Power received at %f is: %f\n", d, Pr);

    cout<<"part 2"<<endl;

    cout<<"Minimum acceptable power is(dBm): "; cin>>Pmin;
    PT = Pt - Pmin;
    R = d0*pow(10, 0.1*(PT/n));
    printf("The maximum cell radius is: %f m", R);

    return 0;
}

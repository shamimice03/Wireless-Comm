#include <bits/stdc++.h>
#define DB double
#define C 300000000.0
using namespace std;
DB getLemda(DB f)
{
    return C/(f*1000000.0);
}
DB getFresnelZoneCircleRadius(DB n,DB lemda,DB d1,DB d2)
{
    DB hi = n*lemda*d1*d2;
    DB lo = d1+d2;
    return sqrt(hi/lo);
}
DB getDiffractionParameter(DB h,DB lemda,DB d1,DB d2)
{
    DB hi = 2*(d1+d2);
    DB lo = lemda*d1*d2;
    return h*sqrt(hi/lo);
}
DB getDiffractionGain(DB v)
{
    if(v<=-1) return 0;
    else if(v>=-1 && v<=0) return 20.0*log10(0.5-0.62*v);
    else if(v>=0 && v<=1) return 20.0*log10(0.5*exp(-0.95*v));
    else if(v>=1 && v<=2.4) return 20.0*log10(0.4-sqrt(0.1184-pow((0.38-0.1*v),2)));
    else return 20.0*log10(0.225/v);
}
int main()
{
    DB h,d1,d2,n,f;
    cout<<"Height of obstruct (in meter) : "; cin>>h;
    cout<<"Distance from transmitter to obstruct (in meter) : "; cin>>d1;
    cout<<"Distance from receiver to obstruct (in meter) : "; cin>>d2;
    cout<<"Frequency (in MHz) : "; cin>>f;
    cout<<"Value of n : "; cin>>n;
    DB lemda = getLemda(f);
    DB circleRadius = getFresnelZoneCircleRadius(n,lemda,d1,d2);
    DB v = getDiffractionParameter(h,lemda,d1,d2);
    DB Gd = getDiffractionGain(v);
    cout<<"Radius of "<<n<<"'th fresnel zone circle is : "<<circleRadius<<endl;
    if(Gd<0){
        Gd*=(-1.0); cout<<"Diffraction loss is : "<<Gd<<" dB"<<endl;
    }
    else cout<<"Diffraction gain is : "<<Gd<<" dB"<<endl;
    return 0;
}

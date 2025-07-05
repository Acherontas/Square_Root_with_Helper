#include <iostream>
#include <math.h>
#include <iomanip>
#include <sstream>
#include <thread>
using namespace std;

int l=0,tsfh=0,sxo=0;
long double fractpart,intpart,yl,y,k,kres,rkres,xl=81,mdst=6561,x;
long double ar[1000];
int xar=0;
long double kar[1000];
int kxar=0;
int modeset=0;
long double dotko,dotxl,ddxl;
int xty=0;
int fores_mperdematos=1;
long double k_of_times(int lx,int lly){
   l=0;tsfh=0;
   for(;;){
     tsfh+=1;
     cout<<" | current state of y " << std::setprecision(20) << y <<" of k " << k << " dotxl " << dotxl << " of dotko " << dotko <<"\n";
     fractpart=modf(y,&intpart);
     cout<<" | breaking up the y " <<std::setprecision(20) << y << " = " << intpart << " + " << fractpart <<"\n";
     if(intpart<=10 || intpart==0){
        cout<<" | calculating small square of y "<<std::setprecision(20) << y <<"\n";
        k=sqrtl(y);
        if(modeset==0){kres=k*81;
            cout<<"\n";
            cout<<"  ------> returning @0 with values: \n";
            cout<<"  ------------> y " <<std::setprecision(20) << y <<"\n";
            cout<<"  ------------> sqrtl of k " << k <<" of above y \n";
            cout<<"  ------------> dotxl as xl  " << xl <<"\n";
            cout<<"  ------------> result= " << k <<" * " << xl << " = " << kres <<"\n";
        }
        if(modeset==1){kres=k*dotxl;
            cout<<"\n";
            cout<<"  ------> returning @1 with values: \n";
            cout<<"  ------------> y " <<std::setprecision(20) << y <<"\n";
            cout<<"  ------------> sqrtl of k " << k <<" of above y \n";
            cout<<"  ------------> dotxl " << dotxl <<"\n";
            cout<<"  ------------> result= " << k <<" * " << dotxl << " = " << kres <<"\n";
        }
        l=1;
     }
     if(intpart>10){
        if(modeset==0){cout<<"from y0 " <<std::setprecision(20) << y << " --> ";
                       y=(long double)y/(long double)6561; //removing intpart
                       cout<<"new y0 " <<std::setprecision(20) << y <<" from " << intpart << " / 6561 \n";
                       if(xty==5){ar[xar]=y;xar+=1;}
                       }
        if(modeset==1){cout<<"from y1 " <<std::setprecision(20) << y << " --> ";
                       y=(long double)y/(long double)dotko;
                       cout<<"new y1 " <<std::setprecision(20) << y <<" from " << intpart << " / " << dotko <<"\n";
                       if(xty==5){ar[xar]=y;xar+=1;}
                       }
     }
     if(l==1){break;}
    }
    cout<<"  //------> result of sqrtl  " << k << " of number y " <<std::setprecision(20) << y  << " ==:: " << kres <<" //\n";
    cout<<"\n";
    return kres; //its the times;
}

long double pwr(int tmsi){
  long double ktm;long double mrkr;
  mrkr=rkres;ddxl=dotxl;
  cout<<"mrkr " << mrkr << " dotxl " << dotxl <<"\n";
  cout<<"need @ ext "<< tsfh <<" times with mode " << modeset <<" and xty " << xty <<"\n";
  if(tsfh>1){
    cout<<"need @ ext "<< tsfh <<" times\n";
      //cout<<"same as tsfh-1==[81]! or 81*81*81 numbers of tsfh-1 * kres \n";
      // for(int i=0;i<=5;i++){
      //    kres=kres*81;
      //    cout<<" -------> @ " << i << " with value " << kres<<"\n";
      // }
      //we dont the 81 value @ this point
       for(int i=1;i<=tsfh-1;i++){
          if(modeset==0){xl=xl*81;cout<<" --------------> @i xl " << i << " default * value of " <<std::setprecision(20) << xl <<"\n";
                         if(xty==5){kar[kxar]=xl;kxar+=1;}
                        }
          if(modeset==1){ddxl=ddxl*dotxl;cout<<" --------------> @i ddxl " << i << " value of " <<std::setprecision(20)<< ddxl <<"\n";
                         if(xty==5){kar[kxar]=ddxl;kxar+=1;}
                        }
       }
       if(modeset==0){xl=xl/81;mrkr=mrkr*xl;cout<<"kres with xl "<< xl << " " << mrkr <<"\n";}
       if(modeset==1){ddxl=ddxl/dotxl;mrkr=ddxl*mrkr;cout<<"final ddxl " << ddxl <<" with mrkr " << mrkr <<"\n";}
    }
    if(tsfh>1){
    if(modeset==0){cout<<"final xl " << xl <<"\n";
                   cout<<"as of " << rkres << " * " << xl << " = " << mrkr <<"\n";}
    if(modeset==1){cout<<"final ddxl " << ddxl <<" with mrkr " << mrkr <<"\n";
                   cout<<"as of " << rkres << " * " << ddxl << " = " << mrkr <<"\n";}
             }
    if(tsfh==1){cout<<"its 1 moving without calculations\n";}
    return mrkr;
}

int mna(long double nma){
   long double sgt=nma;
   int sgni=0;
   nma=nma*nma;
   fractpart=modf(nma,&intpart);
   if(sxo==1){
   cout<<"\n";
   cout<<"mna function of  " << nma << " ---> ";}
   if(intpart==x){if(sxo==1){cout<<"the result square root number is : "<< sgt <<"\n";}
                    sgni=0;}
   if(intpart>x){if(sxo==1){cout<<"the result square root number is bigger\n";}
                    sgni=1;}
   if(intpart<x){if(sxo==1){cout<<"the result square root number is smaller\n";}
                    sgni=2;}
   if(sxo==1){cout<<"returning from mna with signal level of " << sgni <<"\n";}
   return sgni;
}

string sl;
int xcti=-1;
int stb_pos=-1;
int cti=-1;
int sttp=-1;
int cxti=-1;
long double arfoz;
long double ar_of_zeros[50];long double ar_of_zn[50];long double ar_ofzs[50];
int arofz=0;
int dot_ch_f(long double dfk){
    sl.clear();
    stringstream ss ;
    ss<< std::setprecision(15) << dfk;
    sl+=ss.str();
    cout<<"testing with " << dfk  <<" and " << sl <<" " << sl.size() <<"\n";
    fractpart=modf(dfk,&intpart);
    for(int i=0;i<=sl.size()-1;i++){
          if(sl.at(i)!='.' && sttp==-1){cti+=1;}
          if(sl.at(i)=='.' && sttp==-1){stb_pos=i; sttp=1;}
          if(sl.at(i)!='.' && sttp==1 && sl.at(i)=='0'){xcti+=1;}
          if(sl.at(i)!='.' && sttp==1){cxti+=1;}
    }
    cti+=1;
    stb_pos+=1;
    cxti+=1;
    cout<<"the lenght before dot is " << cti <<"\n";
    cout<<"the position of dot is @ " << stb_pos <<"\n";
    cout<<"the lenght of zeros is " << xcti <<"\n";
    cout<<"the lenght of other numbers is " << cxti <<"\n";

    for(int i=cxti-1;i>=i;i--){
            arfoz=pow(10,i);
            arfoz=1/arfoz;
            ar_of_zeros[arofz]=arfoz;
            ar_of_zn[arofz]=intpart + (1-arfoz);
            ar_ofzs[arofz]=intpart+arfoz;
            cout<<"@ i " << i <<  "inserting value " << ar_of_zeros[arofz] <<" --> ";
            cout<<"starting of " << ar_ofzs[arofz] << " ending at " << ar_of_zn[arofz] <<"\n";
            arofz+=1;
            if(i==0){break;}

    }
    return 0;
}

long double findd(long double pw,long double dkd){
    //dot_ch_f(pw);
    int lct=cxti-1;
    long double rstp; int xr;int stp=-1;
    //dkd=ar_of_zeros[lct];
    long double kdk=dkd;
    int cntt=1;
    for(;;){
          if(sxo==1){cout<<"calculate with " << pw <<" ---> ";}
          rstp=pw*pw;
          xr=mna(pw);
          if(xr==0){stp=1;break;}
          if(xr==1){stp=1;break;}
          if(xr==2){pw=pw+dkd;cntt+=1;}
          //if(cntt==9){dkd=ar_of_zeros[lct];lct-=1;cntt=1;}

          if(stp==1){break;}
    }
    cout<<" |------------------------------------------------------------------------------------------------------\n";
    cout<<" | ----> for main number " << x <<"\n";
    long double pwone=pw-dkd;
    long double ptwo=pw;
    long double pthr=pw+dkd;
    cout<<" | ----> almost presice pwr values are from " << pwone << ", " << ptwo << " or " << pthr <<"\n";
    if(sxo==1){cout<<"almost presice pwr value is " << pw << " with result " << std::setprecision(20) << rstp <<"\n";}
    cout<<" | ----> for " << pwone << " value is  -----------> " << std::setprecision(20) << pwone*pwone <<"\n";
    cout<<" | ----> for " << ptwo << " value is   -----------> " << std::setprecision(20) <<  ptwo*ptwo <<"\n";
    cout<<" | ----> for " << pthr << " value is   -----------> " << std::setprecision(20) <<  pthr*pthr <<"\n";
    cout<<" | ----> stp " << stp <<" xr " << xr <<"\n";
    cout<<" |------------------------------------------------------------------------------------------------------\n";
    return pw;
}

long double xty_per(int xar_cnt){
  cout<<"entered xty with " << xar_cnt <<"\n";
  long double xli,rsi;
  long double rsit;
  long double xsit;
  cout<<" |---------------------------------------------------------------------------------------------------------\n";
  for(int i=0;i<=xar_cnt;i++){
     xli=sqrtl(ar[i]);
     rsi=xli*kar[i];
     rsit=rsi*rsi;
     cout<<" | for " << ar[i] << " with sqr " << xli << " and times of " << kar[i] ;
     cout<<" | --->  " << xli << " * " << kar[i] << " ::== " <<std::setprecision(20) <<  rsi <<"\n";
     cout<<" | --->  " << rsi << " ^2 ::== " << std::setprecision(20) << rsit <<"\n";
     if(fores_mperdematos>1){
        if(modeset==1){
        xsit=rsi*kar[i];
        cout<<" | --->  " << rsi << " * " << kar[i] << " ::== " << std::setprecision(20) << xsit <<"\n";}
        }
     }
  cout<<" |---------------------------------------------------------------------------------------------------------\n";
  cout<<"\n";
    return 0;
}

long double sqr( long double mnb){long double lk;lk=sqrtl(mnb);cout<<"the tradition square result is  : "<<std::setprecision(20)<< lk <<" with 15 precision \n";cout<<"without 15 " << lk <<"\n";}
long double diar(long double on,long double tw){long double xot;xot=on/tw;cout<<"the tradition diairesi is : "<< xot <<"\n";}

int main(int argc,char** argv)
{
    cout<<"voyeristic behaviours have fun xD\n";
    cout<<"thelame hack pirame hack perimenoume lefta  vrika tin tetragoniki riza apla tin meiono stis protes rizes xD\n";
    cout<<"enter modeset if modeset is 0 the default values will be applied in order to find the result pwr or press 1\n";
    cout<<"if modeset is 2 to do the tradition square calculation\n";
    cout<<"if modeset is 3 to do the tradition diairesi calculation\n";
    cout<<"if modeset 1 enter a number oxi ton zitoumeno gia euresi \n";
    cout<<"gia sxolia pata 0 i 1\n";
    cout<<"gia apotelesma per y diairesis pata 5\n";
    cout<<"mporeis na mperdeuteis ama theleis vazontas tis fores den in kako xD \n";
    cout<<"i mi mperdemeni timi einai pantote 1 alla grafe to \n";
    cout<<"\n";
    modeset=stoi(argv[1]);
    xty=stoi(argv[4]);
    fores_mperdematos=stoi(argv[5]);
    if(modeset==3){cout<<"enter numbers " ; long double xon;cin>>xon;long double ton;cin>>ton;long double xton;xton=diar(xon,ton);return 0;}
    if(modeset==2){cout<<"enter ur number @trd : \n";long double xn;long double mn;cin>>xn;mn=sqr(xn);return 0;}
    if(modeset==0){xl=81;mdst=6561;}
    if(modeset==1){
       cout<<"enter a value for the calculations \n";
       dotko=stold(argv[2]);
       dotxl=sqrtl(dotko);
       xl=dotxl;
       mdst=dotko;
       cout<<"the calculation will be done with : \n";
       cout<<"modeset number : " << mdst << " with sqrtl of " << dotxl << " and xl of " << xl <<"\n";
       cout<<"we will be late \n";
    }
    cout<<"enter ur number : \n";
    cin>>x;
    sxo=stold(argv[3]);
    if(fores_mperdematos>1){for(int i=1;i<=fores_mperdematos-1;i++){mdst=mdst*mdst;}}
    if(fores_mperdematos>1){dotko=mdst;cout<<"tha sinexiso me ena mperdema " << mdst <<"\n";}
    y=(long double)x/(long double)mdst;
    cout<<"using y=x/mdst " << y << " = " << x << " / " << mdst << "\n";
    cout<<"passing values @ k_of_times function " << x << " and " << y <<"\n";
    ar[xar]=y;
    kar[kxar]=dotxl;
    cout<<"passing also values " << ar[xar] << " with " << kar[kxar] <<"\n";
    xar+=1;kxar+=1;
    rkres=k_of_times(x,y);
    long double prw;
    cout<<"passing @ pwr function " << rkres <<"\n";
    prw=pwr(rkres);
    if(rkres==prw){rkres=1;}
    cout<<"MAIN times "<< rkres << " and " << prw <<"\n";
    int sgn=mna(prw);
    int cnt=-1;
    if(fores_mperdematos==1){
        cout<<"enter 1 to fix or 0 to leave. current cnt value " << cnt <<"\n";
        cin>>cnt;}
    if(cnt==0 && xty==0){return 0;}
    if(cnt==0 && xty==5){goto R;}
    if(cnt==1 && fores_mperdematos==1){
      long double dekadikon;
      cout<<"enter dekadiko eg 0.01 gia pivot \n";
      cin>>dekadikon;
      cout<<"passing @ findd function " << prw << " " << dekadikon <<"\n";
      fractpart=modf(prw,&intpart);
      if(prw==x){cout<<"the result is " << 1 <<" with  " << rkres <<"\n";}
      if(prw!=x){findd(prw,dekadikon);}
    }
    cout<<"Limitation exists on the length of the number the user gives\n";
    cout<<"\n";
    R:if(xty==5){
            cout<<"xty is " << xty <<"\n";;
            xty_per(xar-1);
            }
    if(xty==0){
            cout<<"xty is not 5 i am leaving\n";
            return 0;
            }
    return 0;
}

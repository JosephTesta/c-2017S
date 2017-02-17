#include <iostream>
#include <iomanip>
#include <cmath>
using namespace std;

    double JD(int year, int month, int day, int hour, int min, int sec) {
        int I = year;
        int  J = month;
        double K = day + - 0.5 + hour/24.0 + min/(24.0*60.0) + sec/(24.0*60.0*60.0);
        double Julian = K-32075+1461*(I+4800+(J-14)/12)/4+367*(J-2-(J-14)/12*12)/12-3*((I+4900+(J-14)/12)/100)/4;
        Julian -= 2451544.5;
        cout << setprecision(15) << Julian << endl;
        return Julian;
    }

/*
    INTEGER JD,YEAR,MONTH,DAY,I,J,K

    L= JD+68569
    N= 4*L/146097
    L= L-(146097*N+3)/4
    I= 4000*(L+1)/1461001
    L= L-1461*I/4+31
    J= 80*L/2447
    K= L-2447*J/80
    L= J/11
    J= J+2-12*L
    I= 100*(N-49)+I+L

    YEAR= I
    MONTH= J
    DAY= K

    RETURN
    END
    */

    void GDATE(double JD) {
        JD += 2451544;
        int JDint = JD;

        double JDdecimals = JD - JDint;
        //cout << JDdecimals << endl;
        JD += 1;
        int L = JD+68569;
        int N = 4*L/146097;
        L= L-(146097*N+3)/4;
        int I= 4000*(L+1)/1461001;
        L= L-1461*I/4+31;
        int J= 80*L/2447;
        int K= L-2447*J/80;
        L = J/11;
        J = J+2-12*L;
        I = 100*(N-49)+I+L; 
        int Year = I;
        int Month = J;
        int Day = K;

        int JDdecimals2 = round(JDdecimals*24*60*60);
        //cout << JDdecimals2 << endl;
        int Hour = JDdecimals2/3600;
        int Min = (JDdecimals2%3600)/60;
        //cout << (JDdecimals2%3600) << endl;
        int Sec = (JDdecimals2%3600)%60;
        cout << Year << ' ' << Month << ' ' << Day << ' ' << Hour << ' ' << Min << ' ' << Sec << endl;
    }

int main() {
    GDATE(JD(2000,1,1,0,0,0));
    GDATE(JD(1877,8,11,19,30,45));
    GDATE(JD(1970,1,1,0,0,0));
    GDATE(JD(2012,1,1,0,0,2));
    



    return 0;
}
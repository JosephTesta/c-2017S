#include <iostream>
#include <iomanip>
using namespace std;

    double JD(double year, double month, double day, double hour) {
        int I = year;
        int  J = month;
        double K = day + hour/24.0;
        double Julian = K-32075+1461*(I+4800+(J-14)/12)/4+367*(J-2-(J-14)/12*12)/12-3*((I+4900+(J-14)/12)/100)/4;
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

    int GDATE(double JD) {
        int JDint = JD;

        double JDdecimals = JD - JDint;
        //cout << JDdecimals << endl;
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

        cout << Year << ' ' << Month << ' ' << Day << ' ' << endl;
    }

int main() {
    GDATE(JD(1877,8,11,7.5));
    GDATE(2440589.5);
    GDATE(JD(1970,1,1,0));



    return 0;
}
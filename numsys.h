#include <cmath>
#ifndef EPS
	#define EPS 0.0001
#endif
using namespace std;


double convert_to_R(double num,double R)
{
	int num_int = (int)floor(num);
	double num_flo = num - num_int;
	double ans;
	for(int j = 0;num_int != 0;++j)
	{
		ans = ans + pow(10,j) * floor(fmod(num_int,R));
		num_int = (int) (num_int / R);
		//if (num_int == 0) break;
	}
	double num_flo_flo;
	for(int j = 1;num_flo_flo < EPS;++j)
	{
		ans += pow(10,-j)*(floor(num_flo*R));
		num_flo *= R;
		num_flo_flo = num_flo - floor(num_flo);
		//if (num_int == 0) break;;
	}
	return ans;

}

double numconvert(double num,double R1,double R2)
{
	if (R1 == 10)  return convert_to_R(num,R2);
	return 0;    //Coding

}

void Numsys()
{
    double former,later,r1,r2;
    do
    {
        cout << "Input number and R1:" ;
        cin >> former;
        if (former == 0) break;
        cin >> r1;
        cout << "To R2:";
        cin >> r2;
        later = numconvert(former,r1,r2);
        cout << "The anwser is:" << later << "(" << r2 << ")" << endl;
        cout << "0 to quit." << endl;
    }while (former != 0);
}

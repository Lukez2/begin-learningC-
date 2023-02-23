#include<iostream>
#include<cmath>
using namespace std;
void quadratic (int a,int b,int c,double& roota,double& rootb){       
roota=( - b + sqrt(b * b - 4 * a * c)) / 2 * a;
rootb =( - b - sqrt(b * b - 4 * a * c)) / 2 * a;
}
int main() {
	double roota, rootb;
	quadratic(1, -3,-4, roota, rootb);
	cout << "The roots are " <<  roota  << " and " <<  rootb  << endl;
}
#include<iostream>
#include<vector>
#include<algorithm>
#include<fstream>

using namespace std;

int main()
{
	int imax =11;
	float dx = 1.0 /(float)(imax-1);
	float dt = 0.01*dx*dx;
	float kappa = dt/(dx*dx);
	
	//1D
	vector<float> T, Tnew;
	
	//2D
	vector< vector<float> > T2D, Tnew2D;
	
	T.resize(imax);
	Tnew.resize(imax);
	
	T[0] = 1.0; Tnew[0] = 1.0;
	T[imax] =0.0; Tnew[imax] = 0.0;
	
	for(int i=1; i<imax; ++i){
		T[i] = 0.0;
		Tnew[i] = 0.0;
	}
	
	int itermax = 100;
	int iter =0;
	
	do{
	for(int i=1; i<imax; ++i){
	Tnew[i] = T[i] + kappa*(T[i+1] -2.0*T[i] + T[i-1]);
	}
	
	swap(T, Tnew);
	
	iter +=1;
	}while(iter < itermax+1);
	
	ofstream data1D;
	data1D.open("heat1D.csv");
	data1D <<"x, T \n";
	for(int i=0; i<imax; ++i){
		data1D<<i<<","
		<<T[i]<<endl;
	}
	data1D.close();
	
	
}
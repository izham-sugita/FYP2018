#include<iostream>
#include<cmath>

using namespace std;

double colebrook(double var)
{
  return 1.0/sqrt(var) + 2.0*log10( (0.000042/3.7)
			    + (2.51/(126400*sqrt(var))) );
}

int main()
{

  double xold, xnew;
  double xold1;

  //initiate xold and xold1
  xold = 0.01;
  xold1 = 0.015;

  double test;
  test = colebrook(xold);
  cout<<"Test value:"<<test<<endl;
  test = colebrook(xold1);
  cout<<"Test value:"<<test<<endl;

  xnew = (xold1*colebrook(xold) - xold*colebrook(xold1)  )
    /(colebrook(xold) - colebrook(xold1) );

  cout<<"Xnew:"<<xnew<<endl;

  double temp = xold;
  xold = xnew;
  xold1 = temp;

  cout<<xold<<" "<<xold1<<endl;
  
  int iter=0;
  int itermax = 10;

  double err;
  
  do{

    xnew = (xold1*colebrook(xold) - xold*colebrook(xold1)  )
    /(colebrook(xold) - colebrook(xold1) );

    err = abs(xnew - xold);
    if(err < 10.0e-7)
      {
	cout<<"Converged solution: "<<xnew<<endl;
	break;
      }
    
    cout<<"Error : "<<err<<endl;
    //cout<<"Xnew : "<<xnew<<endl;

    temp = xold;
    xold = xnew;
    xold1 = temp;
    
    iter +=1;
  }while(iter<itermax);

  cout<<"Solution obtained!"<<endl;
  
}

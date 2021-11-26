#include <iostream>
using namespace std;

int my_divide(int dividend, int divisor);

int main(){
	int a, b;

	cin >>a >>b;
	cout<<my_divide(a, b)<<endl;

	return 0;
}

int my_divide(int dividend, int divisor){
	int res = 0;
	int label = 1;

	if(dividend >= 0 && divisor < 0){
		divisor = -divisor;
		label = -label;
	}
	else if(dividend < 0 && divisor > 0){
		dividend = -dividend;
		label = -label;
	}
	else if(dividend < 0 && divisor < 0){
		dividend = -dividend;
		divisor = -divisor;
	}

	while(dividend >= divisor){
		dividend = dividend - divisor;
		res++;
	}
	
	if(label == -1)
		res = -res;

	return res;
}

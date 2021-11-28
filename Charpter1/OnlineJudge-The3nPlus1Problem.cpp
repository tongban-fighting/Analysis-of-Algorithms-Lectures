#include <iostream>
using namespace std;

int maxCycleLength(int i, int j);
int cycleLength(int i);

int main(){
	int i, j;

	while(cin >> i >> j)
		cout << i <<' '<< j <<' '<< maxCycleLength(i, j) <<endl;

	return 0;
}

int maxCycleLength(int i, int j){
	int maxLength = 0,length,temp;
	
	if(i > j){
		temp = i;
		i = j;
		j = temp;
	}

	for(int k = i; k <= j; k++){
		length = cycleLength(k);
		maxLength = max(maxLength, length);
	}

	return maxLength;
}

int cycleLength(int i){
	int length = 1;
	while(i != 1){
		if(i % 2 != 0)
			i = 3 * i + 1;
		else
			i = i / 2;
		length++;
	}
	return length;
}

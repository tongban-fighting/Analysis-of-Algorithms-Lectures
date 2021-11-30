#include <iostream>
#include <vector>
using namespace std;

int selection_sort(vector<int>& num_set);

int main(){
	vector<int> num_set;
	int x;
	while(cin >> x){
		num_set.push_back(x);

		if(cin.peek() == '\n')
			break;
	}
	cout<< "original sequence:"<<endl;
	for(int i = 0; i < num_set.size(); i++)
		cout << num_set[i] << ' ';
	cout <<endl;

	selection_sort(num_set);

	cout<< "sorted sequence:" <<endl;
	for(int i = 0; i < num_set.size(); i++)
		cout << num_set[i] <<' ';
	cout << endl;

	return 0;
}

int selection_sort(vector<int>& num_set){
	int n = num_set.size();
	if(n == 0)
		return 0;

	int min; //record the min number's index
	int temp;

	for(int i = 0; i < n; i++){
		min = i;
		for(int j = i; j < n; j++)
			if(num_set[j] < num_set[min])
				min = j;
		temp = num_set[i];
		num_set[i] = num_set[min];
		num_set[min] = temp;	
	}

	return 1;
}

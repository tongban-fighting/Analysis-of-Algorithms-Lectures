#include <iostream>
#include <string>
#include <vector>
using namespace std;

void my_insertion_sort(vector<char> &res){
	int j;
	
	for(int i = 0; i < res.size(); i++){
		j = i;
		while(j > 0 && res[j] < res[j-1]){//compare back from i to 0, if find disorder, then swap; if not, the order is right.
			swap(res[j],res[j-1]);
			j--;
		}
	}

}

int main(){
	vector<char> my_inp = {'I','N','S','E','R','T','I','O','N','S','O','R','T'};
	
	my_insertion_sort(my_inp);
	
	vector<char>::iterator it;
	for(it = my_inp.begin(); it != my_inp.end(); it++)
		cout<< *it <<' ';
	 
	return 0;
}



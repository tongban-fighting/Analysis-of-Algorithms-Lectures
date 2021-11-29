#include <iostream>
#include <string>
#include <vector>
#include <climits>
using namespace std;

vector<int> select(int num_candi, vector<vector<int> > votes);

int main(){
	int n;//number of cases
	cin >> n;
	cin.get();
	
	for(int i = 0; i < n; i++){
		cin.get();
		int num_candi;
		cin >> num_candi;
		
		cin.get();
		vector<string> name_candi(num_candi + 1);
		for(int j = 1; j <= num_candi; j++)
			getline(cin,name_candi[j]);

		vector<vector<int> > votes;
		vector<int> single_votes;
		int x;
		while(cin >> x){
			single_votes.push_back(x);
			if(cin.get() == '\n'){
				votes.push_back(single_votes);
				single_votes.clear();
			}
			if(cin.peek() == '\n') //two '\n' means end of the input
				break;
		}
		vector<int> selected;
	       	selected = select(num_candi, votes);
		for(int j=0; j < selected.size(); j++)
			cout << name_candi[selected[j]] <<endl; 
	}
	return 0;
}

vector<int> select(int num_candi, vector<vector<int> > votes){
	vector<int> res;
	int criterion = votes.size() / 2;
	bool first_through = true;
	vector<int> erased_candi;

	while(1){
		vector<int> num_ticketsofCandi(num_candi + 1, 0);
		for(int m = 0; m < votes.size(); m++)
			num_ticketsofCandi[votes[m][0]]++;
		int minTickets = INT_MAX;
		bool erased = false;
		vector<int> minCandi;
			
		for(int n = 1; n <= num_candi; n++){
			if(num_ticketsofCandi[n] > criterion){
				res.push_back(n);
				return res;
			}
			if(first_through){
				if(num_ticketsofCandi[n] < minTickets){
					minTickets = num_ticketsofCandi[n];
					minCandi.clear();
					minCandi.push_back(n);
				}
				else if(num_ticketsofCandi[n] == minTickets)
					minCandi.push_back(n);
			}
			else
			{
				if(num_ticketsofCandi[n] && num_ticketsofCandi[n] < minTickets){
					minTickets = num_ticketsofCandi[n];
					minCandi.clear();
					minCandi.push_back(n);
				}
				else if(num_ticketsofCandi[n] == minTickets)
					minCandi.push_back(n);
			}
		}
		first_through = false;
		for(int i = 0; i < minCandi.size(); i++)
			erased_candi.push_back(minCandi[i]);

		for(int m = 0; m < votes.size(); m++){
			for(int k = 0; k < erased_candi.size(); k++){
				if(votes[m][0] == erased_candi[k]){
					votes.at(m).erase(votes.at(m).begin());
					erased = true;
					m--;
					break;
				}
			}
		}

		if(!erased){
			for(int i = 0; i < votes.size(); i++)
				res.push_back(votes[i][0]);
			return res;
		}
	}
}

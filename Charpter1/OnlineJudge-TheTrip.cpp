#include <iostream>
#include <vector>
#include <iomanip>

using namespace std;

int main(){
	int n;
	vector<double> costs;
	double avg, resH, resL;
	
	while((cin >> n) && n){
		costs.clear();
		avg = resH = resL = 0.0;
		costs.resize(n);

		for(int i = 0; i < n; i++){
			cin >> costs[i];
			avg += costs[i];
		}
		avg = (int)(avg * 100 / n) / 100.00;

		for(int i = 0; i < n; i++){
			if(costs[i] > avg)
				resH += costs[i] - avg;
			else
				resL += avg - costs[i];
		}
		
		cout.setf(ios::fixed);
		cout <<'$' << fixed << setprecision(2) << (resH < resL ? resH : resL) <<endl;
	}

	return 0;
}

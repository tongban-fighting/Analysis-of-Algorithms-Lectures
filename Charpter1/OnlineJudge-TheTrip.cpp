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
		avg /= n;

		for(int i = 0; i < n; i++){
			if(costs[i] > avg)
				resH +=(int)((costs[i] - avg) * 100) / 100.00;
			else
				resL +=(int)((avg - costs[i]) * 100) / 100.00;
		}
		
		cout.setf(ios::fixed);
		cout <<'$' << fixed << setprecision(2) << (resH < resL ? resH : resL) <<endl;
	}

	return 0;
}

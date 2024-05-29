#include <iostream>
#include <set>
#include <map>
using namespace std;

int main(){
	int m, n; //m jobs, n statement
	map<int, set<int> > jobs; // < key, set b> -> { key = job type, b stored which job has the type }

	cin >> m >> n;

	for(int i = 1; i <= m; i++){
		int k;
		cin >> k;

		while(k--){
			int type;
			cin >> type; // t is job type of ith job
			if(jobs.find(type) == jobs.end()){ //if key type doesn't exist 
				set<int> tmp;
				tmp.insert(i);
				jobs.insert({type, tmp});
			} else{
				auto it = jobs.find(type);
				it->second.insert(i);
			}	
		}
	}

	while(n--){
		int type;
		cin >> type;
		
		if(jobs.find(type) == jobs.end()) cout << 0 << "\n";
		else {
			auto it = jobs.find(type);
			int tmp_type = *(it->second.begin());
			cout << tmp_type << "\n";

			it->second.erase(tmp_type);
			if(it->second.empty()){
				int key = it->first;
				jobs.erase(key);
			}
		}
	}

	return 0;
}
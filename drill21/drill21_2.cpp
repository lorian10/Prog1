#include <iostream>
#include <stdexcept>
#include <string>
#include <map>
#include <numeric>

using namespace std;

template<typename K, typename V>
void print(const map<K, V>& m){
	for(pair<K, V> i : m){  
		cout << i.first << " " << i.second << endl;
	}
}

void read_map(map<string, int>& m){
	string s;
	int i = 0;
	while(m.size() < 10){
		cin >> s >> i;
		m[s] = i;
	}
}

int main(){
try{
	map<string, int> msi;  
	msi["a"] = 2;
	msi["b"] = 3;
	msi["abc"] = 4;
	msi["cd"] = 5;
	msi["qwert"] = 2;
	msi["po"] = 32;
	msi["xy"] = 4;
	msi["zs"] = 91;
	msi["ac"] = 79;
	msi["ax"] = 81;
	
	print(msi); 
	
	msi.erase("a");	
	cout << "Egy elem törlése után: " << endl;
	print(msi);
	
	msi.erase(msi.begin(), msi.end());	
	cout << "Teljes törlés után: " << endl;
	print(msi);
	
	cout << "Adjon meg 10 kulcs-érték párt: " << endl;
	read_map(msi);
	print(msi);
	
	int sum = 0;
	for(pair<string, int> i : msi){
		sum += i.second;
	}
	cout << "Map értékeinek összege: " << sum << endl;
	
	map<int, string> mis;
	for(pair<string, int> a : msi){
		mis[a.second] = a.first;
	}
	cout << "mis map: " << endl;
	print(mis);
}
catch(exception& e){
	cerr << e.what() << '\n';
	return 1;
}
catch(...){
	cerr << "Unknown exception!" << '\n';
	return 2;
}
}

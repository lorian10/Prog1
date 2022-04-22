#include <iostream>
#include <stdexcept>
#include <vector>
#include <fstream>
#include <numeric>
#include <algorithm>

using namespace std;

template<typename C>
void print(const C& c){
	cout << "Container elements:" << endl;
	for(const auto elem : c){
		cout << elem << endl;
	}
	cout << endl;
}

int main(){
try{
	const string iname{"floats.txt"};
	ifstream ifs{iname};
	if(!ifs) throw runtime_error("Could not read file: " + iname);
	
	vector<double> vd;
	for(double d; ifs >> d;){
		vd.push_back(d);
	}
	
	print(vd);
	
	vector<int> vi(vd.size()); 
	copy(vd.begin(), vd.end(), vi.begin());
	print(vi);
	
	for(int i = 0; i < vd.size(); ++i){
		cout << vd[i] << '\t' << vi[i] << endl;
	}
	cout << endl;
	
	cout.precision(10); 
	
	cout << "Sum of elements in vd: " << accumulate(vd.begin(), vd.end(), 0.0) << endl;
	
	cout << "Sum of elements in vi: " << accumulate(vi.begin(), vi.end(), 0.0) << endl;
	cout << "Difference of vd and vi: " << accumulate(vd.begin(), vd.end(), 0.0)-accumulate(vi.begin(), vi.end(), 0.0) << endl;
	
	reverse(vd.begin(), vd.end());

	print(vd);
	
	double vd_mean = accumulate(vd.begin(), vd.end(), 0.0) / vd.size();
	cout << "Mean value of vd is: " << vd_mean << endl;
	
	vector<double> vd2;
	for(double i : vd){
		if(i < vd_mean) {vd2.push_back(i);}
	}
	print(vd2);
	
	sort(vd.begin(), vd.end());
	
	print(vd);
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

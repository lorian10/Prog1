#include <iostream>
#include <string>
#include <vector>

using namespace std;

template<typename T>
struct S{
	S(T vv = 0) : val{vv}{}
	T& get(); 
	void set(T new_t) {val = new_t;} 
	void operator=(const T& s);
	const T& get() const;
private:
	T val;
};

template<typename T>
T& S<T>::get() {return val;}

template<typename T>
const T& S<T>::get() const {return val;}

template<typename T>
void S<T>::operator=(const T& s){  
	val = s;
}

template<typename T>
void read_val(T& v){	
	cin >> v;
}

template<typename T>
ostream& operator<<(ostream& os, vector<T>& v){
	os << "{ ";
	for(int i = 0; i < v.size(); ++i){
		os << v[i] << (i < v.size()-1 ? ", " : " ");
	}
	os << "}\n";
	return os;
}

template<typename T>
istream& operator>>(istream& is, vector<T>& v){
	char ch = 0;
	is >> ch;
	if(ch != '{'){
		is.unget();
		return is;
	}
	for(T val; is >> val;){
		v.push_back(val);
		is >> ch;
		if(ch != ',') break;
	}
	return is;
}

int main(){
	//3
	S<int> s_int(5);
    	S<char> s_char('x');
    	S<double> s_double(3.14);
    	S<string> s_string("String1");
	S<vector<int>> svi {vector<int> {1, 2, 3}};
	
	//4
	//cout << "S<int> :" << s_int.val << endl;
	//cout << "S<char> : "<< s_char.val << endl;
	//cout << "S<double> : " << s_double.val << endl;
	//cout << "S<string> : " << s_string.val << endl;
	//for (int i = 0; i<svi.val.size(); ++i)
	//	cout << "svi[" << i << "]: " << svi.val[i] << "\n";
	
	//8
	cout << "S<int> : " << s_int.get() << endl;
	cout << "S<char> : " << s_char.get() << endl;
	cout << "S<double> : " << s_double.get() << endl;
	cout << "S<string> : " << s_string.get() << endl;
	cout << "S<vector<int>> : " << svi.get() << endl;
	
	cout << "S<vector<int>> : ";
	for(auto& a : svi.get()){ 
		cout << a << ' ';
	}
	cout << endl;
	
	
	cout << "s_int: ";
	int ii;
        read_val(ii);
        S<int> s_int2 {ii};
        cout << "s_char: ";
        char ch;
        read_val(ch);
        S<char> s_char2(ch);
        cout << "s_double: ";
        double dd;
        read_val(dd);
        S<double> s_double2(dd);
        cout << "s_string: ";
        string ss;
        read_val(ss);
        S<string> s_string2(ss);
        cout << "\nS<int> : " << s_int2.get() << "\n";
        cout << "S<char> :" << s_char2.get() << "\n";
        cout << "S<double> " << s_double2.get() << "\n";
        cout << "S<string>  " << s_string2.get() << "\n\n";
	
	cout << "S<vector<int>> : (format: {val, val, val})  ";
	vector<int> vint;
	read_val(vint);
	S<vector<int>> svi2 {vint};
	cout << "S<vector<int>> : " << svi2.get();
}

#include <iostream>
#include <fstream>

struct Data {
	int mn;
	int mx;
	char c;
	std::string s;
};

// Variadic template for printing variables.
// https://stackoverflow.com/questions/47941837/c-variadic-template-sum
template <typename T>
void print(T t) {
	std:: cout << t << " \n";
}

template <typename T, typename ... Args>
void print(T t, Args... args) {
	std::cout << t << " ";
	print(args...);
}

struct Data parseInput(std::string input) {
	struct Data data;
	int pos1 = input.find('-', 0);
	int pos2 = input.find(' ', 0);
	int pos3 = input.find(':', 0);
	data.mn = std::stoi(input.substr(0, pos1));
	data.mx = std::stoi(input.substr(pos1 + 1, pos2 - pos1 - 1));
	data.c  = input[pos2 + 1];
	data.s  = input.substr(pos3 + 2, input.size() - pos3 - 2);
	// print(data.mn, data.mx, data.c, data.s);
	return data;
}

bool checkValidity(struct Data data) {
	int count = std::count(data.s.begin(), data.s.end(), data.c);
	if (count>=data.mn and count<=data.mx) 
		return true;
	return false;
}
		
int main() {
	freopen("2.txt", "r", stdin);
	std::string input;
	int valid = 0;
	while(getline(std::cin, input)) {
		struct Data data = parseInput(input); 
		valid += checkValidity(data);
	}
	std::cout << valid << std::endl;
}

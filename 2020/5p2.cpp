#include <iostream>
#include <vector>
#include <algorithm>

int sum(int n) {
	return n*(n+1)/2;
}

int main() {
	// 'B' > 'F' > 'R' > 'L'
	freopen("5.txt", "r", stdin);
	std::vector <std::string> seats;

	std::string seat;
	while(getline(std::cin, seat)) {
		std::replace(seat.begin(), seat.end(), 'B', '1');
		std::replace(seat.begin(), seat.end(), 'F', '0');
		std::replace(seat.begin(), seat.end(), 'R', '1');
		std::replace(seat.begin(), seat.end(), 'L', '0');
		std::cout << seat << std::endl;
		seats.push_back(seat);
	}
	std::sort(seats.begin(), seats.end());
	int mn = std::stoi(seats[0], nullptr, 2);
 	int mx = std::stoi(seats[seats.size()-1], nullptr, 2);
	int sum_of_elems = 0;
	for (auto x:seats)
		sum_of_elems += std::stoi(x, nullptr, 2);
	std::cout << sum(mx) - sum(mn-1) - sum_of_elems << std::endl;
	return 0;
}

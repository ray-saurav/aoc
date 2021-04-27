#include <iostream>
#include <vector>
#include <algorithm>

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
	std::cout << std::stoi(seats[seats.size()-1], nullptr, 2) << std::endl;
	return 0;
}

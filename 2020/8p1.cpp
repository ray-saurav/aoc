#include <iostream>
#include <numeric>
#include <vector>

int main() {
	freopen("8.txt", "r", stdin);
	std::vector <std::pair <std::string, int> > instructions;
	std::string line;
	while(std::getline(std::cin, line)) {
		char* type;
		int value;
		std::sscanf(line.c_str(), "%s %d", type, &value);
		instructions.push_back({type, value});
	}

	std::vector <int> count(instructions.size(), 0);
	int cur = 0, sum = 0;
	while (true) {
		std::string type = instructions[cur].first;
		int value = instructions[cur].second;
		count[cur]++;
		if (count[cur] > 1) {
			std::cout << sum << std::endl;
			break;
		}
		if (type.compare("jmp") == 0) {
			cur += value;
		}
		else {
			if (type.compare("acc") == 0)
				sum += value;
			cur++;
		}
	}
	return 0;
}

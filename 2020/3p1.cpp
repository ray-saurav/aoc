#include <iostream>
#include <vector>

int main(int argc, char* argv[]) {
	freopen("3.txt", "r", stdin);
	std::vector <std::vector<char> > forest;
	std::string input;
	int rows, cols;
	while(getline(std::cin, input)) {
		std::vector <char> road(input.begin(), input.end());
		cols = road.size();
		forest.push_back(road);
	}
	rows = forest.size();
	int cur_row = 0;
	int collisions = 0;
	int right = std::atoi(argv[1]), down = std::atoi(argv[2]);
	while (cur_row < rows) {
		int cur_col = (right*1.0/down)*cur_row;
		collisions += (forest[cur_row][cur_col%cols] == '#');
		cur_row += down;
	}
	std::cout << collisions << std::endl;
}

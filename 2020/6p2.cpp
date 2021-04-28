#include <iostream>
#include <numeric>
#include <vector>

int main() {
	freopen("6.txt", "r", stdin);
	std::string line;
	int ans = 26;
	std::vector <int> v(26, 1);
	while (std::getline(std::cin, line)) {
		if(line.size() == 0) { 
			std::for_each(v.begin(), v.end(), [](int &a) { a = 1; });
			ans += 26;
		}
		else {
			for (int i = 0; i < 26 ; i++) {
				if ( line.find('a' + i, 0) == std::string::npos and v[i] == 1) {
					v[i] = 0;
					ans--;
				}
			}
		}
	}
	std::cout << ans << std::endl;
	return 0;
}


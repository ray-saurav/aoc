#include <iostream>
#include <numeric>
#include <vector>

int main() {
	freopen("6.txt", "r", stdin);
	std::string line;
	int ans = 0;
	std::vector <int> v(26, 0);
	while (std::getline(std::cin, line)) {
		if(line.size() == 0) 
			std::for_each(v.begin(), v.end(), [](int &a) { a = 0; });
		else {
			for (const auto &c: line) 
				if (v[c-'a'] == 0) {
					ans++;
					v[c-'a']++;
				}
		}
	}
	std::cout << ans << std::endl;
	return 0;
}


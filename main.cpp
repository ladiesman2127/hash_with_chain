#include <iostream>
#include <deque>
#include <vector>
#include <cmath>


const int p = 1000000007;
const int X = 263;


int hash(const std::string& s)
{
	long long result = 0;
	long long pow = 1;
	for (const auto& ch : s)
	{
		result = ((result % p) + (ch * pow % p)) % p;
		pow = (pow * X) % p;
	}
	return result % p % m;

}

bool is_contained(const std::vector<std::deque<std::string>>& hash_map, const std::string& word)
{

	for (auto& i : hash_map)
	{
		for(const auto& el : i)
		{
			if (el == word)
				return true;
		}
	}
	return false;
}

int main()
{
	int m, n;
	std::cin >> m >> n;
	std::vector<std::string> ans;
	std::vector<std::deque<std::string>> hash_map(m);
	std::string command, word;
	int index;
	for (int i = 0; i < n; ++i)
	{
		std::cin >> command;

		if (command == "check") {
			std::cin >> index;
			for (const auto& el : hash_map[index])
			{
				std::cout << el << " ";
			}
			std::cout << '\n';
		}

		else
		{
			std::cin >> word;

			if (command == "add")
			{
				if(!is_contained(hash_map,word))
					hash_map[hash(word, m)].push_front(word);
			}
			else if (command == "find")
			{
				if (std::find(hash_map[hash(word, m)].begin(), hash_map[hash(word, m)].end(), word) != hash_map[hash(word, m)].end())
					std::cout << "yes\n";
				else
					std::cout << "no\n";
			}
			else if (command == "del")
			{
				if (!hash_map[hash(word, m)].empty())
				{
						const auto& del_it = std::find(hash_map[hash(word, m)].begin(),
							hash_map[hash(word, m)].end(), word);
						if (del_it == hash_map[hash(word, m)].end())
							break;
						hash_map[hash(word, m)].erase(del_it);
				}
			}
		}
	}

	return 0;
}


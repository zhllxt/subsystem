#pragma once

#include <vector>
#include <queue>
#include <unordered_map>
#include <unordered_set>
#include <stdexcept>
#include <algorithm>

// 有向无环图，拓扑排序实现
class module_dependencies
{
protected:
	std::unordered_map<std::string, std::vector<std::string>> adjacency;
	std::unordered_map<std::string, int> indegree;

public:
	static module_dependencies& instance()
	{
		static module_dependencies inst;
		return inst;
	};

public:
	template<typename T>
	void add_dependency([[maybe_unused]] T* me, const std::string& dependency_who)
	{
		std::string from{ typeid(T).name() };
		if (from.find("struct ") == 0)
			from.erase(0, std::strlen("struct "));

		adjacency[from].emplace_back(dependency_who);
		indegree[dependency_who]++;
		if (indegree.find(from) == indegree.end())
		{
			indegree[from] = 0;
		}
	}

	std::vector<std::string> sort()
	{
		std::queue<std::string> zero_indegree;
		std::vector<std::string> result;

		std::unordered_map<std::string, int> indegree_copy = indegree;

		for (const auto& pair : indegree_copy)
		{
			if (pair.second == 0)
			{
				zero_indegree.push(pair.first);
			}
		}

		while (!zero_indegree.empty())
		{
			std::string node = zero_indegree.front();
			zero_indegree.pop();
			result.push_back(node);

			for (const std::string& neighbor : adjacency[node])
			{
				indegree_copy[neighbor]--;
				if (indegree_copy[neighbor] == 0)
				{
					zero_indegree.push(neighbor);
				}
			}
		}

		std::reverse(result.begin(), result.end());

		if (result.size() == indegree_copy.size())
		{
			return result;
		}
		else
		{
			throw std::runtime_error("infinite loop");
		}
	}
};

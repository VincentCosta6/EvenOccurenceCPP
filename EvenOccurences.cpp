#include <iostream>
#include <vector>
#include <queue>
#include <unordered_map>

using std::vector;
using std::queue;
using std::unordered_map;
using std::make_pair;

using std::endl;
using std::cout;

int evenOccurrence(const vector<int>& arr) {
	queue<int> queue;
	unordered_map<int, int> hashmap;

	const int size = arr.size();

	if (size == 0) return -999999;

	for (int i = 0; i < size; i++) {
		const int val = arr[i];

		if (hashmap.find(val) == hashmap.end()) {
			queue.push(val);
			hashmap.insert(make_pair(val, 1));
		}
		else {
			hashmap[val]++;
		}
	}

	while (!queue.empty()) {
		int val = queue.front();
		queue.pop();

		if (hashmap[val] % 2 == 0) return val;
	}

	return -999999;
}

int main()
{
	vector<int> arr1 = { 1, 7, 2, 4, 5, 6, 8, 9, 6, 4 };

	cout << evenOccurrence(arr1) << endl;
}
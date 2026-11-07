#include <bits/stdc++.h>
using namespace std;

int main() {
	int t;
	cin >> t; // Read the number of test cases
	while (t--) {
		int n, x, y;
		cin >> n >> x >> y; // Read the size of the array and Polycarp's favorite integers
		vector<int> a(n, 0); // Initialize the array of size n
		map<int, vector<int>> mp; // Map to store elements based on their remainder when divided by y

		// Read the array elements and categorize them based on remainder with y
		for (int i = 0; i < n; i++) { // O(nLogn)
			cin >> a[i];
			mp[a[i] % y].push_back(a[i]); // O(logn)
		}

		long long int ans = 0; // Initialize the count of beautiful pairs
		// Iterate over each group of elements with the same remainder when divided by y
		for (auto it : mp) {
			vector<int> v = it.second; // Get the vector of elements
			map<int, long long int> mp1; // Map to store counts of remainders when divided by x
			// Count occurrences of each remainder when elements are divided by x
			for (int i = 0; i < v.size(); i++) { // O(nlogn)
				mp1[v[i] % x]++;
			}

			// Calculate the number of beautiful pairs
			for (auto it : mp1) { // O(nlogn)
				if (it.first == 0 || (it.first == x / 2 && x % 2 == 0)) {
					long long int cnt = it.second;
					ans += (cnt * (cnt - 1)) / 2; // Combination of pairs from the same remainder
					it.second = 0;
				} else {
					long long int cnt1 = it.second;
					long long int cnt2 = mp1[x - it.first];
					ans += cnt1 * cnt2; // Pairs from different remainders
					mp1[x - it.first] = 0; // Avoid double counting
				}
			}
		}
		cout << ans << endl; // Output the number of beautiful pairs for the test case
	}
}

// Time Complexity (TC): O(nlogn)
// Space Complexity (SC): O(n)

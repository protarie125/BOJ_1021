#include <iostream>
#include <deque>

using namespace std;

int main() {
	ios::sync_with_stdio(false);
	std::cin.tie(nullptr);

	int n;
	cin >> n;

	auto dq = deque<int>();
	for (int i = 1; i <= n; ++i) {
		dq.push_back(i);
	}

	int m;
	cin >> m;

	auto ct = int{ 0 };
	while (0 < (m--)) {
		int x;
		cin >> x;

		if (dq[0] == x) {
			dq.pop_front();
			continue;
		}

		const auto& sz = dq.size();

		auto l = int{ 0 };
		for (int i = 0; i < sz; ++i) {
			if (dq[i] == x) {
				l = i;
				break;
			}
		}

		auto r = int{ 0 };
		for (int i = 1; i <= sz; ++i) {
			if (dq[sz - i] == x) {
				r = i;
				break;
			}
		}

		if (l <= r) {
			ct += l;
			while (0 < (l--)) {
				auto f = dq[0];
				dq.pop_front();
				dq.push_back(f);
			}
		}
		else {
			ct += r;
			while (0 < (r--)) {
				auto b = dq[sz - 1];
				dq.pop_back();
				dq.push_front(b);
			}
		}

		dq.pop_front();
	}

	cout << ct;

	return 0;
}
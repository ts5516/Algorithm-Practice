#include <iostream>

using namespace std;

int main() {
	ios::sync_with_stdio(false);
	cin.tie(nullptr);

	long long x, y, w, s;
	cin >> x >> y >> w >> s;

	long long minxy = min(x, y);
	long long maxxy = max(x, y);

	long long result = 0;
	if (w >= s) {
		result += s * minxy;
		if ((maxxy - minxy) % 2 == 0) {
			result += s * (maxxy - minxy);
		}
		else {
			result += s * (maxxy - minxy-1);
			result += w;
		}
	}
	else if (w + w > s) {
		result += s * minxy;
		result += w * (maxxy - minxy);
	}
	else {
		result += w * x;
		result += w * y;
	}

	cout << result;

	return 0;
} 
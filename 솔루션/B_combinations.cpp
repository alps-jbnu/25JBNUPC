#include<iostream>
#define ll long long int
using namespace std;
int main() {
	ll arr[10][10] = { 0 };
	ll f[20] = { 1, 1 };
	for (int i = 0; i < 8; i++) {
		for (int j = 0; j < 8; j++) {
			cin >> arr[i][j];
		}
	}
	for (int i = 2; i <= 16; i++) {
		f[i] = f[i - 1] * i;
	}
	ll ans = 0;
	for (int i = 0; i < 8; i++) {
		for (int j = 0; j < 8; j++) {
			ans += arr[i][j] * (f[i + j] / f[i] / f[j]) * (f[14 - i - j] / f[7 - i] / f[7 - j]);
		}
	}
	cout << ans;
	return 0;
}
#include <bits/stdc++.h>
using namespace std;

/*

4 8 2 6 2
4 5 4 1 3

4 + 8 > 4 + 5
4 + 6 > 4 + 1

8 + 2 > 5 + 4
8 + 6 > 5 + 1
8 + 2 > 5 + 3

2 + 6 > 4 + 1
6 + 2 > 1 + 3

ans: 7

a[i] + a[j] > b[i] + b[j]
a[i] + a[j] - b[i] - b[j] > 0
a[i] - b[i] + a[j] - b[j] > 0

let c[i] = a[i] - b[i]

0 3 -2 5 -1
-2 -1 0 3 5

c[i] + c[j] > 0
c[i] + c[j] >= 1
c[j] >= -c[i] + 1

find c[j]

*/

void test_case() {
    int n;
    cin >> n;
    int a[n], b[n];
    for (int i = 0; i < n; i++)
        cin >> a[i];
    for (int i = 0; i < n; i++)
        cin >> b[i];
    int c[n];
    for (int i = 0; i < n; i++)
        c[i] = a[i] - b[i];
    sort(c, c + n);
    long long ans = 0;
    for (int i = 0; i < n; i++) {
        if (c[i] <= 0)
            continue;
        int pos = lower_bound(c, c + n, -c[i] + 1) - c;
        ans += i - pos;
    }
    cout << ans << "\n";
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(0);

    int T = 1;
    // cin >> T;
    for (int tc = 1; tc <= T; tc++)
        test_case();
}

#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

typedef long long ll;
vector<int> a;
ll cnt = 0;
// main vector of elements

void clear() {
    cnt = 0;
}

void merge(int l, int r, int m) {
    vector<int> t1(a.begin() + l, a.begin() + m + 1);
    vector<int> t2(a.begin() + m + 1, a.begin() + r + 1);

    int ind1 = 0;
    int ind2 = 0;
    int start = l;

    while (ind1 < t1.size() && ind2 < t2.size()) {
        if (t1[ind1] < t2[ind2]) {
            cnt += ind2;
            a[start] = t1[ind1];
            ind1++;
        } else {
            a[start] = t2[ind2];
            ind2++;
        }
        start++;
    }

    while (ind1 < t1.size()) {
        a[start] = t1[ind1];
        ind1++;
        cnt += ind2;
        start++;
    }

    while (ind2 < t2.size()) {
        a[start] = t2[ind2];
        ind2++;
        start++;
    }
}

// [l, r]
void merge_sort(int l, int r) {
    if (r > l) {
        int m = (l + r) / 2;

        merge_sort(l, m);
        merge_sort(m + 1, r);
        merge(l, r, m);
    }
}

int main() {
    ios_base::sync_with_stdio(false);
    cout.tie(0);
    cin.tie(0);
    int n;
    cin >> n;

    a.resize(n);
    for (int i = 0; i < n; i++) {
        cin >> a[i];
    }

    merge_sort(0, n - 1);

    cout << cnt << '\n';
}

#include <bits/stdc++.h>

using namespace std;

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr); cout.tie(nullptr);

    long long num;
    map<long long, int> res;

    ifstream in;
    in.open("DATA.in");

    while (in >> num) {
        if (num < 1000) res[num]++;
    }

    sort(res.begin(), res.end());

    for (auto index : res) cout << index.first << " " << index.second;

    in.close();
    return 0;
}
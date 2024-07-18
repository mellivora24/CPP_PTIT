#include <bits/stdc++.h>

using namespace std;

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr); cout.tie(nullptr);

    ifstream in;
    in.open("DATA.in");

    int num;
    int res[1005];
    while (in >> num) {
        res[num]++;
    }

    for (int i=0; i<=1000; i++)
        if (res[i]!=0) cout << i << " " << res[i];

    in.close();

    return 0;
}

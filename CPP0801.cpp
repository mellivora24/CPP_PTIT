#include <bits/stdc++.h>

using namespace  std;


int main() {
    // ios_base::sync_with_stdio(false);
    // cin.tie(nullptr); cout.tie(nullptr);

    fstream in("PTIT.in", ios::in);
    fstream out("PTIT.out", ios::out);

    string res;
    getline(in, res);
    cout << res;
    out << res;

    in.close(); out.close();

    return 0;
}
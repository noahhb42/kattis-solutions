#include "bits/stdc++.h"
using namespace std;

//PRECOMPUTING SOLUTIONS

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    const int NMAX = 1000000;
    const int LMAX = NMAX / 2;

    vector<int> g(LMAX + 1, 0);

    const int GMAX_EST = 4096;
    vector<unsigned char> seen(GMAX_EST, 0);
    vector<int> used;
    used.reserve(GMAX_EST);

    int maxG = 0;

    for (int L = 3; L <= LMAX; ++L) {
        if(L%1000 == 0)cout<<L<<"\n";
        for (int i = 0, j = L - 3; i <= j; ++i, --j) {
            int v = g[i] ^ g[j];
            if (v >= GMAX_EST) {
                cerr << "GMAX_EST too small, increase and recompile.\n";
                return 1;
            }
            if (!seen[v]) {
                seen[v] = 1;
                used.push_back(v);
            }
        }

        int mex = 0;
        while (mex < GMAX_EST && seen[mex]) ++mex;
        if (mex >= GMAX_EST) {
            cerr << "mex reached GMAX_EST, increase and recompile.\n";
            return 1;
        }
        g[L] = mex;
        if (mex > maxG) maxG = mex;

        for (int v : used) seen[v] = 0;
        used.clear();
    }

    ofstream out("appelspelet.txt");
    if (!out) {
        cerr << "Failed to open a.txt for writing.\n";
        return 1;
    }

    for (int n = 1; n <= NMAX; ++n) {
        if (n % 2 == 0) {
            continue;
        } else {
            int A = (n + 1) / 2;
            int B = n / 2;
            int nim = g[A] ^ g[B];
            if(!nim)out << n <<"\n";
        }
    }

    cerr << "Done. Max Grundy value encountered: " << maxG << "\n";

    return 0;
}

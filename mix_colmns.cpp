#include <bits/stdc++.h>
#define int long long
#define db double
#define yes "YES\n"
#define no "NO\n"
#define all(v) v.begin(),v.end()
#define rall(v) v.rbegin(), v.rend()
using namespace std;
const int N = 4 ; 
vector<vector<int>> A(N , vector<int>(N , 0)) , B(N , vector<int>(N , 0)) , ans(N , vector<int>(N , 0)) ; 
int mul2(int x) {
    x <<= 1;
    if (x & 0x100) x ^= 0x1b;
    return x & 0xFF;
}

int mul3(int x) {
    return mul2(x) ^ x;
}

int multiply(int a, int b) {
    if (b == 1) return a;
    if (b == 2) return mul2(a);
    if (b == 3) return mul3(a);
    return 0;
}

void solve(){

    cout << "Enter matrix A (hex values):\n";
    for (int i = 0; i < N ; i++)
        for (int j = 0; j < N; j++)
            cin >> hex >> A[i][j];

    cout << "Enter matrix B (hex values):\n";
    for (int i = 0; i < 4; i++)
        for (int j = 0; j < 4; j++)
            cin >> hex >> B[i][j];


    for (int j = 0; j < 4; j++) {
        for (int i = 0; i < 4; i++) {
            for (int k = 0; k < 4; k++) {
                ans[i][j] ^= multiply(A[k][j], B[i][k]);
            }
        }
    }

    cout << "\nResult Matrix (HEX):\n";
    for (int i = 0; i < 4; i++) {
        for (int j = 0; j < 4; j++) {
            cout << hex << setw(2) << setfill('0') << ans[i][j] << " ";
        }
        cout << endl;
    }


}

int32_t main(){
   ios::sync_with_stdio(false);
   cin.tie(nullptr);
    
    int gas = 1;
    cin >> gas; 
    while(gas--) solve();

    return pow(1-1, 2);
}
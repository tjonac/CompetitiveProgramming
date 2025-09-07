#include <bits/stdc++.h>


#define lli long long
#define ld long double
#define pp pair<lli,lli>
#define mp make_pair
#define INF 1e9
#define MOD int(1e9 + 7)
#define IOI ios_base::sync_with_stdio(false),cin.tie(0),cout.tie(0)
#define ALL(array) (array.begin(),array.end())
#define ENDL '\n' 
#define forn(i, n) for(int i = 0; i < n; i++)
#define fore(i, s, n) for(int i = s; i < n;i++)
#define mod(a,b) ( ( a % b ) + b ) % b
using namespace std;

const int MXN = 2501;
int h, w, sum;
vector<vector<bool> > vec(MXN, vector<bool>(MXN, false));
char d;

int compute(int k){
    vector<vector<bool> > aux = vec;

    forn(i, h){
        forn(j, w){
            if(!aux[i][j]) continue;
            if(i + k > h || j + k > w) return 0;
            forn(r, k){
                forn(l, k){
                    if(!aux[r + i][l + j]) return 0;
                    aux[r + i][l + j] = false;
                }
            }
        }
    }

    return k;
}

int main(){
    IOI;

    cin >> h >> w;

    forn(i, h){
        forn(j, w){
            cin >> d;
            vec[i][j] = (d=='#'? true:false);

            sum+=vec[i][j];
        }
    }
    int maxim = 1, sz = h * w, sq;
    for(int j = 1; j * j <= sum; j++){
        int sq = sqrt(j);
        
        if(sum % j) continue;

        if(sq * sq == j && j>1){
            maxim = max(maxim, compute(sq));
        }

        sq = sqrt(sum / j);

        if(sq * sq == sum / j){
            maxim = max(maxim, compute(sq));
        } 
    }

    cout << maxim << ENDL;
    return 0;
}
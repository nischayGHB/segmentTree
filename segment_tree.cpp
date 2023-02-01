#include<bits/stdc++.h> 
using namespace std; 
typedef long long ll; 
typedef pair<int,int> ii;
typedef vector<int> vi; 
typedef vector<ii> vii; 
typedef vector<pair<int,ii>> viii; 
typedef set<int> si;
typedef set<ii> sii; 
typedef map<int,int> mii;

#define F first 
#define S second 
#define pb push_back 
#define loop(i,a,b) \
     for(int i=a;i<b;i++)
#define dloop(i,a,b) \
     for(int i=a; i>=b;i--)

const int N = 1e5 + 10 ;
int a[N]; 
int segment_tree[4*N];

// O(N)
void build_segment_tree(int idx,int lo,int hi){
     if(lo==hi){segment_tree[idx]=a[lo];return;}
     int mid = (lo+hi)/2; 
     build_segment_tree(2*idx+1,lo,mid); 
     build_segment_tree(2*idx+2,mid+1,hi);
     segment_tree[idx] = max(segment_tree[2*idx+1],segment_tree[2*idx+2]);
}

// O(logN)

int search_in_intervals(int idx,int lo,int hi,int l,int r){
     if(lo>=l&&hi<=r){return segment_tree[idx];}
    // if(lo<l || hi > r){return INT_MIN;}
     int mid = (lo+hi)/2; 
     int left = (lo<l)?INT_MIN:search_in_intervals(2*idx+1,lo,mid,l,r); 
     int right= (hi>r)?INT_MIN:search_in_intervals(2*idx+2,mid+1,hi,l,r);
     return max(left,right);
}

int main(){
    int n; cin >> n; 
    loop(i,0,n) cin >> a[i]; 
    build_segment_tree(0,0,n-1); 
    cout << search_in_intervals(0,0,9,0,5) << endl;
    return 0;
}


// int main(){
//     int t; cin >> t; 
//     while(t--){
//         int n,q; cin >> n >> q; 
//         memset(a,0,sizeof(a));
//         loop(i,0,n) cin >> a[i]; 
//         build_segment_tree(0,0,n-1);
//         while(q--){
//             int l,r; cin >> l >> r; 
//             int ans = search_in_intervals(0,0,n-1,l,r);
//             cout << ans << endl;
//         }
//     }
//     return 0;
// }

// int main(){
//     int t; cin >> t; 
//     while(t--){
//         int n,q; cin >> n >> q;
//         int b[n]; loop(i,0,n) cin >> b[i]; 
//         int pre[n]; pre[0] = b[0]; loop(i,1,n){pre[i]=max(b[i],b[i-1]);}
//         while(q--){
//             int l,r; cin >> l >> r; 

//         }
//     }
//     return 0;
// }



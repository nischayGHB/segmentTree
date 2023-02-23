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

/*  building memory efficent segment tree  */
vi build(vi &a){
     int n = a.size(); vi seg((n<<1)+1,0); 
     loop(i,n,n<<1){seg[i] = a[i-n];}
     dloop(i,n-1,1){seg[i] = max(seg[i<<1],seg[(i<<1)|1]);}
     return seg;
}
int search_max(vi &tree,int l,int r){
     int n = (tree.size())>>1; int res = -1e9; 
     for(l+=n,r+=n;l<=r;l>>=1,r>>=1){
          if(l&1) res = max(res,tree[l++]); 
          if(!(r&1)) res = max(res,tree[r--]);
     }
     return res;
}

int main(){
    int m; cin >> m;
    build_segment_tree(0,0,m-1); 
    cout << search_in_intervals(0,0,m-1,0,5) << endl;
    int t; cin >> t; 
    while(t--){
          int n,q; cin >> n >> q; 
          vi b,seg_tree; 
          loop(i,0,n){int in; cin >> in; b.pb(in);}
          seg_tree = build(b); 
          while(q--){
               int l,r; cin >> l >> r; 
               cout << search(seg_tree,l,r) << endl;
          }
    }
    return 0;
}

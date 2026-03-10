/**
 * Solution by Charles Ran (polarity.sh)
 * Date: 2026-03-08
 * Contest: 
 * Problem: G
**/

#include <bits/stdc++.h>
using namespace std;

using ull = unsigned long long;
using ll = long long;
using vi = vector<int>;
using vl = vector<ll>;
using pii = pair<int, int>;
#define pb push_back
#define rep(i, a, b) for(int i = (a); i < (b); ++i)
#define all(x) begin(x), end(x)
#define sz(x) (int)(x).size()

const int MAX_N = 1e5 + 1;
const ll MOD = 1e9 + 7;

/**
 * DATASTRUCTURE: Rooted Link Cut Tree
 * PURPOSE: LCT but rooted, no-rerooting, good for storing per-component info through root keys
 * TIME: Amortized O(log n)
 * SOURCE: ChatGPT-written template, but stress-tested for correctness
 */
namespace rlct {
    struct SNode {
        SNode *ch[2], *p, *pp;

        int siz;    // aux subtree size
        int vsiz;   // virtual contribution size
        int subsz;  // total contribution of aux subtree + virtuals

        ll val;
        ll sum; // aux subtree sum
        ll vir; // virtual contribution sum
        ll sub; // total contribution of aux subtree + virtuals

        SNode(long long _val = 0)
            : ch{nullptr, nullptr}, p(nullptr), pp(nullptr),
              siz(1), vsiz(0), subsz(1),
              val(_val), sum(_val), vir(0), sub(_val) {}
    };

    int gs(SNode* x) { return x ? x->siz : 0; }
    int gsubsz(SNode* x) { return x ? x->subsz : 0; }
    ll gsum(SNode* x) { return x ? x->sum : 0; }
    ll gsub(SNode* x) { return x ? x->sub : 0; }

    void pull(SNode* x) {
        if (!x) return;
        x->siz = 1 + gs(x->ch[0]) + gs(x->ch[1]);
        x->sum = x->val + gsum(x->ch[0]) + gsum(x->ch[1]);

        // total contribution of the whole auxiliary subtree segment
        x->subsz = 1 + gsubsz(x->ch[0]) + gsubsz(x->ch[1]) + x->vsiz;
        x->sub   = x->val + gsub(x->ch[0]) + gsub(x->ch[1]) + x->vir;
    }

    bool is_aux_root(SNode* x) {
        return !x->p || (x->p->ch[0] != x && x->p->ch[1] != x);
    }

    bool side(SNode* x) {
        return x->p->ch[1] == x;
    }

    void attach(SNode* p, SNode* c, int d) {
        if (p) p->ch[d] = c;
        if (c) c->p = p;
    }

    void rotate(SNode* x) {
        SNode* p = x->p;
        SNode* g = p->p;
        int dx = side(x);

        if (!is_aux_root(p)) {
            attach(g, x, side(p));
        } else {
            x->p = nullptr;
        }

        attach(p, x->ch[dx ^ 1], dx);
        attach(x, p, dx ^ 1);

        x->pp = p->pp;
        p->pp = nullptr;

        pull(p);
        pull(x);
    }

    void splay(SNode* x) {
        while (!is_aux_root(x)) {
            SNode* p = x->p;
            if (!is_aux_root(p)) {
                if (side(x) == side(p)) rotate(p);
                else rotate(x);
            }
            rotate(x);
        }
        pull(x);
    }

    void detach_right(SNode* x) {
        if (x->ch[1]) {
            SNode* r = x->ch[1];
            r->pp = x;
            r->p = nullptr;

            x->vsiz += r->subsz;
            x->vir += r->sub;

            x->ch[1] = nullptr;
            pull(x);
        }
    }

    void attach_right_preferred(SNode* x, SNode* c) {
        if (c) {
            x->vsiz -= c->subsz;
            x->vir -= c->sub;
            attach(x, c, 1);
        } else {
            x->ch[1] = nullptr;
        }
        pull(x);
    }

    SNode* access(SNode* x) {
        splay(x);
        detach_right(x);

        SNode* last = x;
        while (x->pp) {
            SNode* w = x->pp;
            last = w;
            splay(w);
            detach_right(w);

            x->pp = nullptr;
            attach_right_preferred(w, x);

            splay(x);
        }
        return last;
    }

    SNode* make_node(long long val = 0) {
        return new SNode(val);
    }

    SNode* find_root(SNode* x) {
        access(x);
        while (x->ch[0]) x = x->ch[0];
        access(x);
        return x;
    }

    bool connected(SNode* u, SNode* v) {
        return find_root(u) == find_root(v);
    }

    void cut(SNode* x) {
        access(x);
        assert(x->ch[0] != nullptr);
        x->ch[0]->p = nullptr;
        x->ch[0] = nullptr;
        pull(x);
    }

    void link(SNode* child, SNode* par) {
        assert(!connected(par, child));
        access(child);
        assert(child->ch[0] == nullptr); // child must be represented-tree root
        access(par);
        attach(child, par, 0);
        pull(child);
    }

    SNode* lca(SNode* u, SNode* v) {
        if (!connected(u, v)) return nullptr;
        access(u);
        return access(v);
    }

    int dist_root(SNode* x) {
        access(x);
        return x->siz - 1;
    }

    int dist(SNode* u, SNode* v) {
        SNode* a = lca(u, v);
        if (!a) return -1;
        return dist_root(u) + dist_root(v) - 2 * dist_root(a);
    }

    void add_val(SNode* x, long long delta) {
        access(x);
        x->val += delta;
        pull(x);
    }

    void set_val(SNode* x, long long v) {
        access(x);
        x->val = v;
        pull(x);
    }

    // root -> x path sum
    long long path_sum_root(SNode* x) {
        access(x);
        return x->sum;
    }

    // u -> v path sum
    long long path_sum(SNode* u, SNode* v) {
        SNode* a = lca(u, v);
        if (!a) return 0;
        return path_sum_root(u) + path_sum_root(v) - 2 * path_sum_root(a) + a->val;
    }

    // represented subtree of x
    int subtree_size(SNode* x) {
        access(x);
        return 1 + x->vsiz;
    }

    long long subtree_sum(SNode* x) {
        access(x);
        return x->val + x->vir;
    }
} using namespace rlct;

void solve(){
    int n, q; cin >> n >> q;

    vector<SNode*> nodes(n);
    rep(i, 0, n) {
        nodes[i] = make_node(i);
    }

    vi cycleNode(n, -1);
    vector<bool> cycle(n, false);

    int bipartite = 0;

    vi to(n);
    rep(i, 0, n) {
        cin >> to[i];
        --to[i];

        if (connected(nodes[i], nodes[to[i]])) {
            int root = find_root(nodes[i])->val;
            cycle[i] = true;
            cycleNode[root] = i;

            if (dist(nodes[i], nodes[to[i]]) % 2 == 1) {
                bipartite++;
            }
            continue;
        }

        link(nodes[i], nodes[to[i]]);
    }

    rep(qq, 0, q) {
        int x, y, k; cin >> x >> y >> k;
        --x; --y;
        k %= 3;

        bool onCycle = false;

        int root = find_root(nodes[x])->val;
        int a = cycleNode[root], b = to[a];
        int bi = dist(nodes[a], nodes[b]) % 2;

        if (cycle[x]) {
            onCycle = true;
            cycle[x] = false;
        } else {
            int len = dist(nodes[a], nodes[b]);
            onCycle |= (dist(nodes[a], nodes[x]) + dist(nodes[to[x]], nodes[b]) + 1 == len) || (dist(nodes[b], nodes[x]) + dist(nodes[to[x]], nodes[a]) + 1 == len);
            cut(nodes[x]);

            if (onCycle) {
                link(nodes[a], nodes[b]);
                cycle[a] = false;
            }
        }

        if (onCycle) {
            cycleNode[root] = -1;
            bipartite -= bi;
        }

        to[x] = y;
        if (connected(nodes[x], nodes[to[x]])) {
            int root = find_root(nodes[x])->val;
            cycle[x] = true;
            cycleNode[root] = x;
            
            if (dist(nodes[x], nodes[to[x]]) % 2 == 1) {
                bipartite++;
            }
        } else {
            link(nodes[x], nodes[to[x]]);
        }

        if (k == 0) cout << 0 << '\n';
        else if (k == 1) cout << 1 << '\n';
        else cout << 1 + (n + bipartite) % 2 << '\n';
    }
}

int main(){
    ios_base::sync_with_stdio(0);
    cin.tie(0); cout.tie(0);
    int tc = 1;
    // cin >> tc;
    for (int t = 1; t <= tc; ++t){
        // cout << "Case #" << t << ": ";
        solve();
    }
    return 0;
}
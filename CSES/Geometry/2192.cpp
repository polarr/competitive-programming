/**
 * Solution by Charles Ran (polarity.sh)
 * Date: 2026-01-06
 * Contest: CSES Problemset
 * Problem: 2192
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
 * DATASTRUCTURE: 2D Point
 * PURPOSE: Represents a point on the euclidian plane
*/
template <class T>
struct Point {
    T x, y;
    Point(T a = T(), T b = T()) : x(a), y(b) {}

    Point& operator+=(const Point& other) {
        x += other.x;
        y += other.y;
        return *this;
    }

    Point& operator-=(const Point& other) {
        x -= other.x;
        y -= other.y;
        return *this;
    }

    friend istream& operator>>(istream& in, Point& p) {
        in >> p.x >> p.y;
        return in;
    }

    friend ostream& operator<<(ostream& out, const Point& p) {
        out << p.x << " " << p.y;
        return out;
    }
};
template <class T>
Point<T> operator+(Point<T> a, const Point<T>& b) {
    a += b;
    return a;
}
template <class T>
Point<T> operator-(Point<T> a, const Point<T>& b) {
    a -= b;
    return a;
}
template<class T>
T dot(Point<T> p1, Point<T> p2) {
    return p1.x * p2.x + p1.y * p2.y;
}

/** 
 * ALGORITHM: Collinearity
 * PURPOSE: Checks if p lies on the line between p1 and p2.
 * If 0 it does. If 1 it is on the right (from p1 to p2), if -1 on the left.
 * CONSTRAINT: p1 != p2
*/
template<class T>
T collinear(Point<T> p1, Point<T> p2, Point<T> p) {
    p2 -= p1;
    p -= p1;

    T tmp = p2.x;
    p2.x = p2.y;
    p2.y = -tmp;

    ll a = p2.x * p.x;
    ll b = p2.y * p.y;

    if (a == -b) {
        return 0;
    }

    return a > -b ? 1 : -1;
}

bool intersect(Point<ll> p1, Point<ll> p2, Point<ll> p3, Point<ll> p4) {
    ll a = collinear(p1, p2, p3);
    ll b = collinear(p1, p2, p4);
    ll c = collinear(p3, p4, p1);
    ll d = collinear(p3, p4, p2);

    if (a == 0 && b == 0 && c == 0 && d == 0) {
        if (max(p1.x, p2.x) >= min(p3.x, p4.x) && max(p3.x, p4.x) >= min(p1.x, p2.x) && max(p1.y, p2.y) >= min(p3.y, p4.y) && max(p3.y, p4.y) >= min(p1.y, p2.y)) {
            return true;
        }
        else {
            return false;
        }
    }

    if (a * b <= 0 && c * d <= 0) {
        return true;
    }

    return false;
}

void solve(){
    // clever
    int n, m; cin >> n >> m;

    vector<Point<ll>> p(n);
    rep(i, 0, n) cin >> p[i];

    rep(q, 0, m) {
        Point<ll> pt; cin >> pt;

        bool on = false;
        int hit = 0;

        rep(i, 0, n) {
            Point<ll> p1 = p[i], p2 = p[(i + 1) % n];

            if (p1.y > pt.y && p2.y <= pt.y && collinear(p1, p2, pt) > 0) {
                hit++;
            }

            if (p2.y > pt.y && p1.y <= pt.y && collinear(p1, p2, pt) < 0) {
                hit++;
            }

            if (collinear(p1, p2, pt) == 0 && max(p1.x, p2.x) >= pt.x && pt.x >= min(p1.x, p2.x) && max(p1.y, p2.y) >= pt.y && pt.y >= min(p1.y, p2.y)) {
                on = true;
                break;
            }
        }

        if (on) {
            cout << "BOUNDARY\n";
            continue;
        }

        if (hit % 2 == 0) {
            cout << "OUTSIDE\n";
        } else {
            cout << "INSIDE\n";
        }
    }
}

int main(){
    ios_base::sync_with_stdio(0);
    cin.tie(0); cout.tie(0);
    solve();
    return 0;
}
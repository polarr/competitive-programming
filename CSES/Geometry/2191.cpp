/**
 * Solution by Charles Ran (polarity.sh)
 * Date: 2026-01-06
 * Contest: CSES Problemset
 * Problem: 2191
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
 * If zero it does. If positive it is on the right when looking from p1 to p2, negative on the left.
 * CONSTRAINT: p1 != p2
*/
template<class T>
T collinear(Point<T> p1, Point<T> p2, Point<T> p) {
    p2 -= p1;
    p -= p1;

    T tmp = p2.x;
    p2.x = p2.y;
    p2.y = -tmp;

    return dot(p2, p);
}

void solve(){
    int n; cin >> n;

    vector<Point<ll>> points(n);

    rep(i, 0, n) {
        cin >> points[i];
    }

    ll ans = 0;
    rep(i, 0, n) {
        int pv = (i + n - 1) % n;
        int nx = (i + 1) % n;
        ans += (points[nx].y - points[pv].y) * points[i].x;
    }

    cout << abs(ans) << endl;
}

int main(){
    ios_base::sync_with_stdio(0);
    cin.tie(0); cout.tie(0);
    solve();
    return 0;
}
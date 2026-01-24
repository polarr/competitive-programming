/**
 * Template by 1egend (polarity.sh)
 * Template: geometry
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
const ll INF = LLONG_MAX;

/** 
 * DATASTRUCTURE: Point (2D)
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
 * REQUIRE: Point
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

/** 
 * ALGORITHM: Line Segment Intersection
 * PURPOSE: Check if segment p1, p2 intersects with p3, p4
 * CONSTRAINT: p1 != p2, p3 != p4
 * REQUIRE: Collinear
*/
bool segmentIntersect(Point<ll> p1, Point<ll> p2, Point<ll> p3, Point<ll> p4) {
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

/** 
 * ALGORITHM: Polygon area
 * PURPOSE: Uses shoelace theorem to calculate TWICE the polygon area. Remove abs for signed area.
 * CONSTRAINT: Point locations <= 1e9 to avoid overflow
 * REQUIRE: Point
*/
ll polygonArea(const vector<Point<ll>> &points) {
    int n = sz(points);
    ll ans = 0;
    rep(i, 0, n) {
        int pv = (i + n - 1) % n;
        int nx = (i + 1) % n;
        ans += (points[nx].y - points[pv].y) * points[i].x;
    }

    return abs(ans);
}

int main(){
    ios_base::sync_with_stdio(0);
    cin.tie(0); cout.tie(0);
    
    return 0;
}
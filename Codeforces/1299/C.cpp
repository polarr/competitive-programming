/**
 * Solution by Charles Ran (polarity.sh)
 * Date: 2026-01-26
 * Contest: Codeforces 1299
 * Problem: C
**/

#include <bits/stdc++.h>
using namespace std;

using ull = unsigned long long;
using ll = long long;
using ld = long double;
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
 * DATASTRUCTURE: Point (2D)
 * PURPOSE: Represents a point on the euclidian plane
*/
template <class T> int sgn(T x) { return (x > 0) - (x < 0); }
template<class T>
struct Point {
	typedef Point P;
	T x, y;
	explicit Point(T x=0, T y=0) : x(x), y(y) {}
	bool operator<(P p) const { return tie(x,y) < tie(p.x,p.y); }
	bool operator==(P p) const { return tie(x,y)==tie(p.x,p.y); }
	P operator+(P p) const { return P(x+p.x, y+p.y); }
	P operator-(P p) const { return P(x-p.x, y-p.y); }
	P operator*(T d) const { return P(x*d, y*d); }
	P operator/(T d) const { return P(x/d, y/d); }
	T dot(P p) const { return x*p.x + y*p.y; }
	T cross(P p) const { return x*p.y - y*p.x; }
	T cross(P a, P b) const { return (a-*this).cross(b-*this); }
	T dist2() const { return x*x + y*y; }
	double dist() const { return sqrt((double)dist2()); }
	// angle to x-axis in interval [-pi, pi]
	double angle() const { return atan2(y, x); }
	P unit() const { return *this/dist(); } // makes dist()=1
	P perp() const { return P(-y, x); } // rotates +90 degrees
	P normal() const { return perp().unit(); }
	// returns point rotated 'a' radians ccw around the origin
	P rotate(double a) const {
		return P(x*cos(a)-y*sin(a),x*sin(a)+y*cos(a)); }
    friend istream& operator>>(istream& in, P& p) {
        return in >> p.x >> p.y;
    }
	friend ostream& operator<<(ostream& os, P p) {
		return os << p.x << " " << p.y; }
};

/** 
 * ALGORITHM: Convex Hull
 * PURPOSE: Returns the convex hull of a set of points in counter-clockwise order. Points on the edges are not considered on the hull.
 * TIME: O(n log n)
 * REQUIRE: Point
*/
typedef Point<ll> P;
vector<P> convexHull(vector<P> pts) {
	if (sz(pts) <= 1) return pts;
	sort(all(pts));
	vector<P> h(sz(pts)+1); // 2 * sz(pts) + 1 if you want to keep edge points
	int s = 0, t = 0;
	for (int it = 2; it--; s = --t, reverse(all(pts)))
		for (P p : pts) {
            // < 0 if want to keep edge points
			while (t >= s + 2 && h[t-2].cross(h[t-1], p) <= 0) t--;
			h[t++] = p;
		}
	return {h.begin(), h.begin() + t - (t == 2 && h[0] == h[1])};
}

void solve(){
    int n; cin >> n;
    ll sum = 0;
    vector<P> points(n + 1);
    points[0] = P();
    rep(i, 0, n) {
        ll a; cin >> a;
        sum += a;
        points[i + 1] = P(i + 1, sum);
    }

    cout << fixed << setprecision(10);

    vector<P> hull = convexHull(points);
    P lastPoint = P();
    rep(i, 1, sz(hull)) {
        P point = hull[i];
        // cout << point << endl;
        if (point < lastPoint) break;

        ll tot = point.y - lastPoint.y;
        ll num = point.x - lastPoint.x;
        ld val = (ld) tot / num;
        rep(j, 0, num) {
            cout << val << "\n";
        }

        lastPoint = point;
    }
}

int main(){
    ios_base::sync_with_stdio(0);
    cin.tie(0); cout.tie(0);
    solve();
    return 0;
}
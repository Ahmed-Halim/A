#include <bits/stdc++.h>
using namespace std;

#define PI acos(-1)
#define EPS 1e-9
#define MOD 1e9+7
#define SET(a , x) memset(a , x , sizeof(a))
#define Fast ios_base::sync_with_stdio(false) , cin.tie(0) , cout.tie(0)

struct point {
    double x , y;
    point () { x = y = 0; }
    point (double _x, double _y) {
        x = _x , y = _y;
    }
    bool operator < (point right) const {
        if (fabs(x - right.x) > EPS) {
            return x < right.x;
        }
        return y < right.y;
    }
    
    bool operator == (point right) const {
        return (fabs(x - right.x) < EPS && (fabs(y - right.y) < EPS));
    }
    
};

double Distance (point p1, point p2) {
    return sqrt(((p1.x - p2.x) * (p1.x - p2.x)) + ((p1.y - p2.y) * (p1.y - p2.y)));
}

double DTR (double theta) {
    return theta * PI / 180.0;
}

double RTD (double theta) {
    return theta * 180.0 / PI;
}

point Rotate(point p, double theta) {
    double rad = DTR(theta);
    return point((p.x * cos(rad)) - (p.y * sin(rad)) , (p.x * sin(rad)) + (p.y * cos(rad)));
}

struct line {
    double a , b , c;
};

void PointsToLine(point p1, point p2, line &l) {
    if (fabs(p1.x - p2.x) < EPS) {
        l.a = 1.0; l.b = 0.0; l.c = -p1.x; }
    else {
        l.a = -(double)(p1.y - p2.y) / (p1.x - p2.x);
        l.b = 1.0;
        l.c = -(double)(l.a * p1.x) - p1.y;
    }
}

bool areParallel (line l1, line l2) {
    return (fabs(l1.a-l2.a) < EPS) && (fabs(l1.b-l2.b) < EPS);
}

bool areSame (line l1, line l2) {
    return areParallel(l1 ,l2) && (fabs(l1.c - l2.c) < EPS);
}

bool areIntersect(line l1, line l2, point &p) {
    if (areParallel(l1, l2)) {
        return false;
    } else {
        p.x = (l2.b * l1.c - l1.b * l2.c) / (l2.a * l1.b - l1.a * l2.b);
        
        if (fabs(l1.b) > EPS)
            p.y = -(l1.a * p.x + l1.c);
        else
            p.y = -(l2.a * p.x + l2.c);
        
        return true;
    }
}

struct vec {
    double x , y;
    vec (double _x, double _y) {
        x = _x , y = _y;
    }
};

vec toVec (point a, point b) {
    return vec(b.x - a.x, b.y - a.y);
}

vec scale (vec v, double s) {
    return vec(v.x * s, v.y * s);
}

point translate (point p , vec v) {
    return point(p.x + v.x , p.y + v.y);
}


double dot(vec a, vec b) {
    return (a.x * b.x + a.y * b.y);
}

double norm_sq(vec v) {
    return v.x * v.x + v.y * v.y;
}

double cross(vec a, vec b) {
    return a.x * b.y - a.y * b.x;
}


void pointSlopeToLine(point p, double m, line &l) {
    l.a = -m;
    l.b = 1;
    l.c = -((l.a * p.x) + (l.b * p.y));
}

void closestPoint(line l, point p, point &ans) {
    line perpendicular;
    if (fabs(l.b) < EPS) {
        ans.x = -(l.c);   ans.y = p.y;
        return;
    }
    
    if (fabs(l.a) < EPS) {
        ans.x = p.x;      ans.y = -(l.c);
        return;
    }
    
    pointSlopeToLine(p , 1 / l.a , perpendicular);
    areIntersect(l , perpendicular , ans);
}

void reflectionPoint(line l, point p, point &ans) {
    point b;
    closestPoint(l, p, b);
    vec v = toVec(p, b);
    ans = translate(translate(p, v), v);
}

double distToLine(point p, point a, point b, point &c) {
    vec ap = toVec(a, p), ab = toVec(a, b);
    double u = dot(ap, ab) / norm_sq(ab);
    c = translate(a, scale(ab, u));
    return Distance(p, c);
}

double distToLineSegment(point p, point a, point b, point &c) {
    vec ap = toVec(a, p), ab = toVec(a, b);
    double u = dot(ap, ab) / norm_sq(ab);
    if (u < 0.0) {
        c = point(a.x, a.y);
        return Distance(p, a);
    }
    if (u > 1.0) {
        c = point(b.x, b.y);
        return Distance(p, b);
    }
    return distToLine(p, a, b, c);
}

double angle(point a, point o, point b) {
    vec oa = toVec(o, a), ob = toVec(o, b);
    return acos(dot(oa, ob) / sqrt(norm_sq(oa) * norm_sq(ob)));
}

bool ccw(point p, point q, point r) {
    return cross(toVec(p, q), toVec(p, r)) > 0;
}

bool collinear(point p, point q, point r) {
    return fabs(cross(toVec(p, q), toVec(p, r))) < EPS;
}

int main(){
    Fast;
    
    return 0;
}

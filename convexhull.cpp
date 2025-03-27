#include <iostream>
#include <vector>
#include <cmath>
using namespace std;

struct Point {
    int x, y;
};

// Find the cross-product (determines which side a point is on)
int crossProduct(Point A, Point B, Point P) {
    return (B.x - A.x) * (P.y - A.y) - (B.y - A.y) * (P.x - A.x);
}

// Find the farthest point from line (A, B)
int farthestPoint(Point A, Point B, const vector<Point>& points) {
    int maxDist = -1, index = -1;
    for (int i = 0; i < points.size(); i++) {
        int dist = abs(crossProduct(A, B, points[i]));
        if (dist > maxDist) {
            maxDist = dist;
            index = i;
        }
    }
    return index;
}

// QuickHull recursive function
void quickHull(Point A, Point B, vector<Point>& points, vector<Point>& hull) {
    int index = farthestPoint(A, B, points);
    if (index == -1) { // No more points to add
        hull.push_back(A);
        return;
    }

    Point C = points[index];
    vector<Point> left1, left2;
    for (Point p : points) {
        if (crossProduct(A, C, p) > 0) left1.push_back(p);
        if (crossProduct(C, B, p) > 0) left2.push_back(p);
    }

    quickHull(A, C, left1, hull);
    quickHull(C, B, left2, hull);
}

// Main function to compute Convex Hull
vector<Point> findConvexHull(vector<Point>& points) {
    if (points.size() < 3) return {}; 

    // Find leftmost and rightmost points
    Point A = points[0], B = points[0];
    for (Point p : points) {
        if (p.x < A.x) A = p;
        if (p.x > B.x) B = p;
    }

    vector<Point> hull, left, right;
    for (Point p : points) {
        int s = crossProduct(A, B, p);
        if (s > 0) left.push_back(p);
        else if (s < 0) right.push_back(p);
    }

    quickHull(A, B, left, hull);
    quickHull(B, A, right, hull);

    hull.push_back(A); // Ensure we close the hull correctly
    return hull;
}
int main() {
    vector<Point> points = {{0, 3}, {2, 2}, {1, 1}, {2, 1}, {3, 0}, {0, 0}, {3, 3}};
    vector<Point> hull = findConvexHull(points);
    cout << "Convex Hull Points:\n";
    for (Point p : hull)
        cout << "(" << p.x << ", " << p.y << ")\n";
    return 0;
}

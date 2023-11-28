#include <iostream>
#include <cmath>
using namespace std;

class point {
private:
    int x;
    int y;

public:
    point();
    point(int x, int y);
    void setX(int x);
    void setY(int y);
    int getX();
    int getY();
};

point::point() {
    x = 0;
    y = 0;
}

point::point(int _x, int _y) {
    x = _x;
    y = _y;
}

void point::setX(int _x) {
    cout << "Value of X: ";
    cin >> _x;
    x = _x;
}

void point::setY(int _y) {
    cout << "Value of Y: ";
    cin >> _y;
    cout << endl;
    y = _y;
}

int point::getX() {
    return x;
}

int point::getY() {
    return y;
}

class Triangle {
private:
    point vertex1;
    point vertex2;
    point vertex3;
    double dist1;
    double dist2;
    double dist3;

public:
    Triangle();
    Triangle(point vertex1, point vertex2, point vertex3);
    double perimeter();
    double area();
    void showVertex();
};

Triangle::Triangle() {
    vertex1.setX(0);
    vertex1.setY(0);
    vertex2.setX(50);
    vertex2.setY(30);
    vertex3.setX(25);
    vertex3.setY(10);

    dist1 = sqrt((vertex2.getX() - vertex1.getX()^2) + (vertex2.getY() - vertex1.getY()^2));
    dist2 = sqrt((vertex3.getX() - vertex2.getX()^2) + (vertex3.getY() - vertex2.getY()^2));
    dist3 = sqrt((vertex1.getX() - vertex3.getX()^2) + (vertex1.getY() - vertex3.getY()^2));
}

Triangle::Triangle(point _vertex1, point _vertex2, point _vertex3) {
    vertex1 = _vertex1;
    vertex2 = _vertex2;
    vertex3 = _vertex3;

    dist1 = sqrt(pow(vertex2.getX() - vertex1.getX(), 2) + pow(vertex2.getY() - vertex1.getY(), 2));
    dist2 = sqrt(pow(vertex3.getX() - vertex2.getX(), 2) + pow(vertex3.getY() - vertex2.getY(), 2));
    dist3 = sqrt(pow(vertex1.getX() - vertex3.getX(), 2) + pow(vertex1.getY() - vertex3.getY(), 2));
}

double Triangle::perimeter() {
    return dist1 + dist2 + dist3;
}

double Triangle::area() {
    double s = perimeter() / 2;
    return sqrt(s * (s - dist1) * (s - dist2) * (s - dist3));
}

void Triangle::showVertex() {
    cout << "Vertex 1: " << vertex1.getX() << ", " << vertex1.getY() << endl;
    cout << "Vertex 2: " << vertex2.getX() << ", " << vertex2.getY() << endl;
    cout << "Vertex 3: " << vertex3.getX() << ", " << vertex3.getY() << endl;
}

int main() {
    point p1(0, 0);
    point p2(50, 30);
    point p3(25, 10);
    cout << "Vertex 1" << endl;
    p1.setX(0); p1.setY(0);
    cout << "Vertex 2" << endl;
    p2.setX(50); p2.setY(30);
    cout << "Vertex 3" << endl;
    p3.setX(25); p3.setY(10);
    Triangle t1(p1, p2, p3);
    t1.showVertex();
    cout << endl << "Perimeter: " << t1.perimeter() << endl;
    cout << "Area: " << t1.area() << endl;

    return 0;
}
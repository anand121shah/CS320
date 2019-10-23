#include <iostream>
#include <cmath> //for area and perimeter calculation
#include <sstream>
#include "Shapes.h"
#include <cassert>

using namespace std;

//A color called INVALID is added to this array beacause Color at a point methods is added.
string ColorArr[9] = { "BLACK", "RED", "GREEN", "YELLOW", "BLUE", "MAGENTA", "CYAN", "WHITE", "INVALID" };
Color Shape::color() const {
	return _c;
}

//It uses inside function of the respective shape to check where the point is and returns the color
Color Shape::colorAtPoint(Shape* list[], int n, double x, double y) {
	for (int i = 0; i < n; i++) {
		if (list[i]->inside(x, y))
			return list[i]->color();
	}
	return (INVALID);
}

//Methods Implementations for Box Class
Box::Box(Color c, double left, double top, double right, double bottom):Shape(c){
	//constructor 
	_left = left;
	_top = top;
	_right = right;
	_bottom = bottom;
}
double Box::area() const {
	return ((_right-_left)*(_top-_bottom));
}
double Box::perimeter() const {
	return (2*((_right-_left)+(_top-_bottom)));
}
void Box::move(double x, double y){
	_left += x;
	_right += x;
	_top += y;
	_bottom += y;
}
void Box::render(ostream& out) const {
	out << "Box(" << ColorArr[color()] << "," << _left << "," << _top << "," << _right << "," << _bottom << ")";
}
bool Box::inside(double x, double y) const {
	return (x > _left && x < _right && y > _bottom && y < _top);
}

//Methods Implementations for Circle Class
Circle::Circle(Color c, double centerX, double centerY, double radius):Shape(c){
	_x = centerX;
	_y = centerY;
	_radius = radius;
}
double Circle::area() const {
	return (M_PI*_radius*_radius);
}
double Circle::perimeter() const {
	return (2*M_PI*_radius);
}
void Circle::move(double x, double y){
	_x += x;
	_y += y;
}
void Circle::render(ostream& out) const {
	out << "Circle(" << ColorArr[color()] << "," << _x << "," << _y << "," << _radius << ")";
}
//finds the distance between the new point and center and sees if it is smaller than radius
bool Circle::inside(double x, double y) const {
	double a = (x - _x);
	double b = (y - _y);
	double s = sqrt(a*a + b*b);
	return (s < _radius);
}

//Methods Implementations for Triangle Class
Triangle::Triangle(Color c, double x1, double y1, double x2, double y2, double x3, double y3):Shape(c){
	x[0] = x1;
	y[0] = y1;
	x[1] = x2;
	y[1] = y2;
	x[2] = x3;
	y[2] = y3;
}
double Triangle::area() const {
	double s1 = sqrt( (x[2]-x[1])*(x[2]-x[1]) + (y[2]-y[1])*(y[2]-y[1]) );
	double s2 = sqrt( (x[1]-x[0])*(x[1]-x[0]) + (y[1]-y[0])*(y[1]-y[0]) );
	double s3 = sqrt( (x[2]-x[0])*(x[2]-x[0]) + (y[2]-y[0])*(y[2]-y[0]) );
	double s = (s1+s2+s3)/2;
	return (sqrt(s*(s-s1)*(s-s2)*(s-s3)));
}
double Triangle::perimeter() const {
	double s1 = sqrt( (x[2]-x[1])*(x[2]-x[1]) + (y[2]-y[1])*(y[2]-y[1]) );
	double s2 = sqrt( (x[1]-x[0])*(x[1]-x[0]) + (y[1]-y[0])*(y[1]-y[0]) );
	double s3 = sqrt( (x[2]-x[0])*(x[2]-x[0]) + (y[2]-y[0])*(y[2]-y[0]) );
	return (s1+s2+s3);
}
void Triangle::move(double m, double n){
	x[0] += m;
	x[1] += m;
	x[2] += m;
	y[0] += n;
	y[1] += n;
	y[2] += n;
}
void Triangle::render(ostream& out) const {
	out << "Triangle(" << ColorArr[color()] << "," << x[0] << "," << y[0] << "," << x[1] << "," << y[1]  << "," << x[2] << "," << y[2] << ")";
}
//Theory: If a point is inside the triangle then the area of the three sub triangles formed by 4 points should be equal to the area of triangles formed by the outermost points
bool Triangle::inside(double a, double b) const {
	Triangle t1(BLUE, a, b, x[1], y[1], x[2], y[2]);
	Triangle t2(BLUE, x[0], y[0], a, b, x[2], y[2]);
	Triangle t3(BLUE, x[0], y[0], x[1], y[1], a, b);
	return (abs(area() - (t1.area() + t2.area() + t3.area())) < 0.0000001);
}

//Methods Implementations for Polygon Class
Polygon::Polygon(Color c, double pts[], int corners):Shape(c){
	vertices = corners;
	int k = 0;
	x = new double[corners];
	y = new double[corners];
	for (int i = 0; i < corners; i++){
		x[i] = pts[k++];
		y[i] = pts[k++];
	}
}
Polygon::~Polygon(){
	delete[] x;
	delete[] y;
}
double Polygon::area() const {
	double k = 0;
	for (int i = 0; i < (vertices-1); i++){
		k += (x[i]*y[i+1] - y[i]*x[i+1]);
	}
	k += (- x[0]*y[vertices-1] + y[0]*x[vertices-1]);
	return (k/2);
}
double Polygon::perimeter() const {
	double pm = 0;
	for (int i = 0; i < (vertices-1); i++)
		pm += sqrt( (x[i+1]-x[i])*(x[i+1]-x[i]) + (y[i+1]-y[i])*(y[i+1]-y[i]) );
	pm += sqrt( (x[0]-x[vertices-1])*(x[0]-x[vertices-1]) + (y[0]-y[vertices-1])*(y[0]-y[vertices-1]) );
	return pm;
}
void Polygon::move(double m, double n){
	for (int i = 0; i < vertices; i++){
		x[i] += m;
		y[i] += n;
	}
}
void Polygon::render(ostream& out) const {
	out << "Polygon(" << ColorArr[color()] << "," << vertices;
	for (int i = 0; i < vertices; i++){
		out << "," << x[i] << "," << y[i];
	}
	out << ")";
}
//the reference for algo for this method is https://wrf.ecse.rpi.edu/Research/Short_Notes/pnpoly.html
bool Polygon::inside(double a, double b) const{
	int i, j; 
	bool c = 0;
	for (i = 0, j = vertices-1; i < vertices; j = i++) {
		if ( ((y[i]>b) != (y[j]>b)) && (a < (x[j]-x[i]) * (b-y[i]) / (y[j]-y[i]) + x[i]) )
		   c = !c;
	}
	return c;
}

//Method implementation for Line class
Line::Line(Color c, double a1, double b1, double a2, double b2):Shape(c){
	x1 = a1;
	y1 = b1;
	x2 = a2;
	y2 = b2;
}
//Line is one dimensional, hence, area = 0
double Line::area() const {
	return 0;
}
double Line::perimeter() const {
	return (sqrt((x2-x1)*(x2-x1) + (y2-y1)*(y2-y1)));
}
void Line::move(double m, double n){
	x1 += m;
	x2 += m;
	y1 += n;
	y2 += n;
}
void Line::render(ostream& out) const {
	out << "Line(" << ColorArr[color()] << "," << x1 << "," << y1 << "," << x2 << "," << y2 << ")";
}
//Theory: if the point lies on the line, then the slope formed by, the line formed by that point and anypoint on line, should be equal.
bool Line::inside(double a, double b) const {
	return ((y2-y2)/(x2-x2) == (y2-b)/(x2-a));
}
RoundBox::RoundBox(Color c, double left, double top, double right, double bottom, double radius):Box(c, left, top, right, bottom){
	_radius = radius;
}
double RoundBox::area() const {
	return (Box::area() + M_PI*_radius*_radius - (_radius*2)*(_radius*2));
}
double RoundBox::perimeter() const {
	return (Box::perimeter() - 8*_radius + 2*M_PI*_radius);
}
void RoundBox::render(ostream& out) const {
	out << "RoundBox(" << ColorArr[color()] << "," << left() << "," << top() << "," << right() << "," << bottom() << "," << _radius <<")";
}
//Step 1: Checks if it is inside the regular box first (because roundedbox is technically inside the regular box)
	//The point lies in the intersection of box and cicle, hence, the insideness in both circle and box is checked
//Step 2: 4 square boxes with the length of radius are formed
//Step 3: In each box, the respective circle with radius is formed
//Step 4: If it is not in outside, or in the corner areas, it is definitely inside the box hence returned true at the end
bool RoundBox::inside(double x, double y) const {
	if(!(Box::inside(x, y)))
		return false;
	Box b1(BLUE, left(), top(), left()+_radius, top()-_radius);
	if(b1.inside(x, y)){
		Circle c1(BLUE, left()+_radius, top()-_radius, _radius);
		return c1.inside(x, y);
	}
	Box b2(BLUE, right()-_radius, top(), right(), top()-_radius);
	if(b2.inside(x, y)){
		Circle c2(BLUE, right()-_radius, top()-_radius, _radius);
		return c2.inside(x, y);
	}
	Box b3(BLUE, left(), bottom()+_radius, left()+_radius, bottom());
	if(b3.inside(x, y)){
		Circle c3(BLUE, left()+_radius, bottom()+_radius, _radius);
		return c3.inside(x, y);
	}
	Box b4(BLUE, right()-_radius, bottom()+_radius, right(), bottom());
	if(b4.inside(x, y)){
		Circle c4(BLUE, right()-_radius, bottom()+_radius, _radius);
		return c4.inside(x, y);
	}
	return true;
}






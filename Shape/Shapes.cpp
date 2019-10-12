#include <iostream>
#include <cmath> //for area and perimeter calculation
#include <sstream>
#include "Shapes.h"
#include <cassert>

using namespace std;

string ColorArr[8] = { "BLACK", "RED", "GREEN", "YELLOW", "BLUE", "MAGENTA", "CYAN", "WHITE" };
Color Shape::color() const {
	return _c;
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







// int main(){
// 	double pts[] = {1,1,7,2,3,5,6,8,4,3};
//     Shape * list[100];
//     int count = 0;
//     list[count++] = new Box(BLUE,0,1,1,0);
//     list[count++] = new Box(CYAN,2,9,4,3);
//     list[count++] = new Circle(WHITE,5,5,3);
//     list[count++] = new Triangle(BLACK,1,1,5,1,3,3);
//     list[count++] = new Polygon(GREEN,pts,5);

//     double distance = 0;
//     double area = 0;
//     stringstream ss;

//     for (int i=0; i<count; i++) {
//         distance += list[i]->perimeter();
//         area += list[i]->area();
//         list[i]->render(ss);
//         ss << "\n";
//     }

//     for (int i=0; i<count; i++) {
//         list[i]->move(10,10);
//         list[i]->render(ss);
//         ss << "\n";
//     }

//     cout << "distance: " << distance << " area: " << area << "\n";
//     cout << "drawing: " << ss.str();
//     for (int i=0; i<count; i++)
//         delete list[i];
// }


// int main()
// {
// 	Box b(BLUE,1,4,3,2);
// 	Circle c(BLUE,1,2,3);
// 	Triangle t(BLUE,1,2,3,4,3,2);
// 	double pts[] = {1,2,3,4,5,6,7,8,9,10};
// 	Polygon p(BLUE,pts,5);
// 	cout << p.area() <<endl;
//     assert(fabs(p.area()-0)<0.0000001);
// 	return 0;
// }






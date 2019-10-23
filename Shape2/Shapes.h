#include <iostream>

enum Color { BLACK, RED, GREEN, YELLOW, BLUE, MAGENTA, CYAN, WHITE, INVALID };


//PLEASE READ THIS

//destructor is made private in all the classes because it is automatic
//copying constructor method is declared but not used/implemented in this assignment
//getters and setters are one liners, so, implemented inside the class


//Abstract shape
class Shape
{
private:
	Color _c;
	const Shape& operator=(const Shape& q);
	Shape(const Shape& i);
public:
	Shape(Color c){ _c = c; };
	virtual ~Shape(){};
	Color color() const;
	void color(Color c){_c = c;};
	virtual double area() const = 0;
	virtual double perimeter() const = 0;
	virtual void move(double x, double y) = 0;
	virtual void render(std::ostream& out) const = 0;
	virtual bool inside(double x, double y) const = 0;
	double thickness() const {
		return (area()/perimeter());
	}
	static Color colorAtPoint(Shape* list[], int n, double x, double y);
};

//4 member variables added to BOX
class Box : public Shape
{
private:
	double _left, _top, _right, _bottom;
	const Box& operator=(const Box& q);
	Box(const Box& i);
public:
	Box(Color c, double left, double top, double right, double bottom);
	virtual double area() const;
	virtual double perimeter() const;
	void move(double x, double y);
	virtual void render(std::ostream& out) const;
	virtual bool inside(double x, double y) const;
	void left(double x){_left = x;};
	double left() const {return _left;};
	void right(double x){_right = x;};
	double right() const {return _right;};
	void top(double x){_top = x;};
	double top() const {return _top;};
	void bottom(double x){_bottom = x;};
	double bottom() const {return _bottom;};
};

//3 member variables as center point and raidius added to Circle
class Circle : public Shape
{
private:
	double _x, _y, _radius;
	const Circle& operator=(const Circle& q);
	Circle(const Circle& i);
public:
	Circle(Color c, double centerX, double centerY, double radius);
	double area() const;
	double perimeter() const;
	void move(double x, double y);
	void render(std::ostream& out) const;
	bool inside(double x, double y) const;
	void centerX(double x){_x = x;};
	double centerX() const {return _x;};
	void centerY(double x){_y = x;};
	double centerY() const {return _y;};
	void radius(double x){_radius = x;};
	double radius() const {return _radius;};
};

//the three vertices are stored in an arrays x and y as respective coordinate
class Triangle : public Shape
{
private:
	double x[3], y[3];
	const Triangle& operator=(const Triangle& q);
	Triangle(const Triangle& i);
public:
	Triangle(Color c, double x1, double y1, double x2, double y2, double x3, double y3);
	double area() const;
	double perimeter() const;
	void move(double m, double n);
	void render(std::ostream& out) const;
	bool inside(double a, double b) const;
	void cornerX1(double m){x[0] = m;};
	double cornerX1() const {return x[0];};
	void cornerY1(double m){y[0] = m;};
	double cornerY1() const {return y[0];};
	void cornerX2(double m){x[1] = m;};
	double cornerX2() const {return x[1];};
	void cornerY2(double m){y[1] = m;};
	double cornerY2() const {return y[1];};
	void cornerX3(double m){x[2] = m;};
	double cornerX3() const {return x[2];};
	void cornerY3(double m){y[2] = m;};
	double cornerY3() const {return y[2];};
};


//the points are stored in dynamic arrays as their respective coordinate
//and int variables keeps the value of vetices
class Polygon : public Shape
{
private:
	double* x;
	double* y;
	int vertices;
	const Polygon& operator=(const Polygon& q);
	Polygon(const Polygon& i);
public:
	Polygon(Color c, double pts[], int corners);
	~Polygon();
	double area() const;
	double perimeter() const;
	int points() const {return vertices;};
	void move(double m, double n);
	void render(std::ostream& out) const;
	bool inside(double a, double b) const;
	void vertexX(int index, double newX){x[index] = newX;};
	double vertexX(int indx) const {return x[indx];};
	void vertexY(int index, double newY){y[index] = newY;};
	double vertexY(int indx) const {return y[indx];};
};

//The shapes has 4 variables as two set of coordinates. All the var are saved in private.
//All the methods are redefined as usual
class Line : public Shape
{
private:
	double x1, x2, y1, y2;
	const Line& operator=(const Line& l);
	Line(const Line& i);
public:
	Line(Color c, double a1, double b1, double a2, double b2);
	double area() const;
	double perimeter() const;
	void move(double m, double n);
	void render(std::ostream& out) const;
	bool inside(double a, double b) const;
	void end1X(double x) { x1 = x; };
	double end1X() const {return x1;};
	void end1Y(double x) { y1 = x; };
	double end1Y() const {return y1;};
	void end2X(double x) { x2 = x; };
	double end2X() const {return x2;};
	void end2Y(double x) { y2 = x; };
	double end2Y() const {return y2;};
};

//This is a derived class of Box class with added variable Radius of the rounded corners of the box.
//Some methods are redefined
class RoundBox : public Box
{
private:
	double _radius;
public:
	RoundBox(Color c, double left, double top, double right, double bottom, double radius);
	double area() const;
	double perimeter() const;
	void render(std::ostream& out) const;
	bool inside(double x, double y) const;
	void radius(double x){_radius = x;};
	double radius() const {return _radius;};
	
};








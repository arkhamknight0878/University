#include <iostream>

#include <math.h>

using namespace std;

class Vertex
{
private:
	double x;
	double y;
public:
	Vertex()
	{
		x = 0;
		y = 0;
	}
	Vertex(double x_, double y_)
	{
		x = x_;
		y = y_;
	}
	Vertex& operator= (const Vertex& other_)
	{
		if (&other_ == this)
			return *this;

		x = other_.x;
		y = other_.y;

		return *this;
	}

	void Set_Coord(double x_, double y_)
	{
		x = x_;
		y = y_;
	}
	void Set_X(double x_)
	{
		x = x_;
	}
	void Set_Y(double y_)
	{
		y = y_;
	}

	double Get_X()
	{
		return x;
	}
	double Get_Y()
	{
		return y;
	}

	void Print_Coord()
	{
		printf("(%lf, %lf)", x, y);
	}
};

class Triangle
{
private:
	static size_t triangle_counter;
	
	char name[13];

	Vertex vertex1;
	Vertex vertex2;
	Vertex vertex3;

	double edge1;
	double edge2;
	double edge3;

	double Pythagor(Vertex vertex1_, Vertex vertex2_)
	{
		return sqrt(pow((vertex1_.Get_X() - vertex2_.Get_X()), 2) + pow((vertex1_.Get_Y() - vertex2_.Get_Y()), 2));
	}
public:
	Triangle();

	Triangle(Vertex vertex1_, Vertex vertex2_, Vertex vertex3_);

	Triangle& operator= (const Triangle& other_);

	bool operator> (Triangle& other_){	return (Area() > other_.Area());	}

	bool operator< (Triangle& other_){	return (Area() < other_.Area());	}

	bool operator!= (Triangle& other_){	return (Area() != other_.Area());	}

	bool operator== (Triangle& other_){ return (Area() == other_.Area());	}

	/*bool IsInTriangle(Triangle other_)
	{
		double a = 
	}*/

	double Area();

	void Move_Triangle(Vertex coords_);
};

//Реализация - считаются произведения(1, 2, 3 - вершины треугольника, 0 - точка) :
//(x1 - x0) * (y2 - y1) - (x2 - x1) * (y1 - y0)
//(x2 - x0) * (y3 - y2) - (x3 - x2) * (y2 - y0)
//(x3 - x0) * (y1 - y3) - (x1 - x3) * (y3 - y0)
//Если они одинакового знака, то точка внутри треугольника, если что - то из этого - ноль, то точка лежит на стороне, иначе точка вне треугольника.
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
	Triangle()
	{
		vertex1 = Vertex(0, 0);
		vertex2 = Vertex(0, 0);
		vertex3 = Vertex(0, 0);

		edge1 = 0;
		edge2 = 0;
		edge3 = 0;
	}
	Triangle(Vertex vertex1_, Vertex vertex2_, Vertex vertex3_)
	{
		vertex1 = vertex1_;
		vertex2 = vertex2_;
		vertex3 = vertex3_;

		edge1 = Pythagor(vertex1, vertex2);
		edge2 = Pythagor(vertex2, vertex3);
		edge3 = Pythagor(vertex3, vertex1);
	}
	double Area(double edge1_, double edge2_, double edge3_)
	{
		double semiperim = (edge1_ + edge2_ + edge3_) / 2;

		return sqrt(semiperim * (semiperim - edge1) * (semiperim - edge2) * (semiperim - edge3));
	}
	void Move_Triangle()
	{

	}
};
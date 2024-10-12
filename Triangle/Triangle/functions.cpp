#include "functions.h"

Triangle::Triangle()
{
	strcat(name, "Triangle ");
	sprintf(name, "Triangle %Iu", triangle_counter);

	vertex1 = Vertex(0, 0);
	vertex2 = Vertex(0, 0);
	vertex3 = Vertex(0, 0);

	edge1 = 0;
	edge2 = 0;
	edge3 = 0;
}

Triangle::Triangle(Vertex vertex1_, Vertex vertex2_, Vertex vertex3_)
{
	name[0] = '/0';

	vertex1 = vertex1_;
	vertex2 = vertex2_;
	vertex3 = vertex3_;

	edge1 = Pythagor(vertex1, vertex2);
	edge2 = Pythagor(vertex2, vertex3);
	edge3 = Pythagor(vertex3, vertex1);
}

Triangle& Triangle::operator=(const Triangle& other_)
{
	if (&other_ == this)
		return *this;

	vertex1 = other_.vertex1;
	vertex2 = other_.vertex2;
	vertex3 = other_.vertex3;

	edge1 = other_.edge1;
	edge2 = other_.edge2;
	edge3 = other_.edge3;
}

double Triangle::Area()
{
	double semiperim = (edge1 + edge2 + edge3) / 2;

	return sqrt(semiperim * (semiperim - edge1) * (semiperim - edge2) * (semiperim - edge3));
}

void Triangle::Move_Triangle(Vertex coords_)
{
	vertex1.Set_Coord(vertex1.Get_X() + coords_.Get_X(), vertex1.Get_Y() + coords_.Get_Y());
	vertex2.Set_Coord(vertex2.Get_X() + coords_.Get_X(), vertex2.Get_Y() + coords_.Get_Y());
	vertex3.Set_Coord(vertex3.Get_X() + coords_.Get_X(), vertex3.Get_Y() + coords_.Get_Y());
}

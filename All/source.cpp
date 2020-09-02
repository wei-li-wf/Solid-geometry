#include<math.h>
#include<iostream>
#include<algorithm>

using namespace std;

//定义基础数学点类 
class Dot {
public:
	double x, y, z;

};


// 定义包含射线功能参数的物理点
class Point {
public:
	double wave, phase, power;
	Dot dot;
};


//定义向量类 
class Vect {
public:
	double x, y, z;
 


};

//定义立方体定点
class  Rectangle {
public:
	Dot dot_0, dot_1, dot_2, dot_3, dot_4, dot_5, dot_6, dot_7;

};


//定义面类 
class Triangle {
public:
	Dot dot_0, dot_1, dot_2;
};

/*

//定义剖面类
class Cube_profile {
public:
	Triangle trangle_0, trangle_1, trangle_2, trangle_3, trangle_4, trangle_5,
		trangle_6, trangle_7, trangle_8, trangle_9, trangle_10, trangle_11;
};

*/


//定义一个赋值函数给初始化测试点赋值，，，
Dot dot_assign(double x, double y, double z)
{
	Dot dot;
	dot.x = x;
	dot.y = y;
	dot.z = z;
	return dot;
}


double dot_product(Vect p1, Vect p2)//点乘定义 
{
	double mul;
	mul = p1.x*p2.x + p1.y*p2.y + p1.z + p2.z;
	return mul;
}


Vect cross_product(Vect p1, Vect p2)//叉乘定义 
{
	Vect v;
	v.x = p1.y*p2.z - p1.z*p2.y;
	v.y = p1.z*p2.x - p1.x*p2.z;
	v.z = p1.x*p2.y - p1.y*p2.x;

	return v;
}


double mode(Vect p) //向量求模 
{
	double mo;
	mo = sqrt(p.x*p.x + p.y*p.y + p.z*p.z);
	return mo;
}

//定义两点A， B由A指向B的向量
Vect get_vector(Dot A, Dot B)
{
	Vect v;
	v.x = B.x - A.x;
	v.y = B.y - A.y;
	v.z = B.z - A.z;
	return v;

}



//求三角面法向量
Vect  get_vector_normal(Triangle triangle)
{
	Vect vect;
	vect.x = (triangle.dot_1.y - triangle.dot_0.y) * (triangle.dot_2.z - triangle.dot_0.z) -
		(triangle.dot_1.z - triangle.dot_0.z) * (triangle.dot_2.y - triangle.dot_0.y);
	vect.y = (triangle.dot_1.z - triangle.dot_0.z) * (triangle.dot_2.x - triangle.dot_0.x) -
		(triangle.dot_1.x - triangle.dot_0.x) * (triangle.dot_2.z - triangle.dot_0.z);
	vect.z = (triangle.dot_1.x - triangle.dot_0.x) * (triangle.dot_2.y - triangle.dot_0.y) - 
		(triangle.dot_1.y - triangle.dot_0.y) * (triangle.dot_2.x - triangle.dot_0.x);
		
		return vect;
}
	




// 求立方体顶点 
Rectangle get_rectangle(Dot X1, Dot X2)
{
	Dot dot_tem;
	dot_tem = X1;
	Rectangle rectangle;
	rectangle.dot_0 = dot_tem;
	dot_tem.x = X2.x;
	rectangle.dot_1 = dot_tem;
	dot_tem.y = X2.y;
	rectangle.dot_2 = dot_tem;
	dot_tem.x = X1.x;
	rectangle.dot_3 = dot_tem;

	dot_tem.x = X1.x;
	dot_tem.y = X1.y;
	dot_tem.z = X2.z;

	rectangle.dot_4 = dot_tem;
	dot_tem.x = X2.x;
	rectangle.dot_5 = dot_tem;
	dot_tem.y = X2.y;
	rectangle.dot_6 = dot_tem;
	dot_tem.x = X1.x;
	rectangle.dot_7 = dot_tem;

	return rectangle;

}

//根据立方体顶点求得十二个面  
Triangle * get_cube_profile(Rectangle rectangle)
{
	static Triangle  cube_profile[11];
	Triangle *p ;
	
	p = cube_profile;

	Triangle triangle_tem;
	
	triangle_tem.dot_0 = rectangle.dot_0;
	triangle_tem.dot_1 = rectangle.dot_5;
	triangle_tem.dot_2 = rectangle.dot_4;
	cube_profile[0] = triangle_tem;

	triangle_tem.dot_0 = rectangle.dot_0;
	triangle_tem.dot_1 = rectangle.dot_5;
	triangle_tem.dot_2 = rectangle.dot_1;
	cube_profile[1] = triangle_tem;

	triangle_tem.dot_0 = rectangle.dot_1;
	triangle_tem.dot_1 = rectangle.dot_6;
	triangle_tem.dot_2 = rectangle.dot_5;
	cube_profile[2] = triangle_tem;

	triangle_tem.dot_0 = rectangle.dot_1;
	triangle_tem.dot_1 = rectangle.dot_6;
	triangle_tem.dot_2 = rectangle.dot_2;
	cube_profile[3] = triangle_tem;

	triangle_tem.dot_0 = rectangle.dot_7;
	triangle_tem.dot_1 = rectangle.dot_2;
	triangle_tem.dot_2 = rectangle.dot_6;
	cube_profile[4] = triangle_tem;

	triangle_tem.dot_0 = rectangle.dot_7;
	triangle_tem.dot_1 = rectangle.dot_2;
	triangle_tem.dot_2 = rectangle.dot_3;
	cube_profile[5] = triangle_tem;

	triangle_tem.dot_0 = rectangle.dot_3;
	triangle_tem.dot_1 = rectangle.dot_4;
	triangle_tem.dot_2 = rectangle.dot_0;
	cube_profile[6] = triangle_tem;

	triangle_tem.dot_0 = rectangle.dot_3;
	triangle_tem.dot_1 = rectangle.dot_4;
	triangle_tem.dot_2 = rectangle.dot_7;
	cube_profile[7] = triangle_tem;

	triangle_tem.dot_0 = rectangle.dot_4;
	triangle_tem.dot_1 = rectangle.dot_6;
	triangle_tem.dot_2 = rectangle.dot_7;
	cube_profile[8] = triangle_tem;

	triangle_tem.dot_0 = rectangle.dot_4;
	triangle_tem.dot_1 = rectangle.dot_6;
	triangle_tem.dot_2 = rectangle.dot_5;
	cube_profile[9] = triangle_tem; 
	
	triangle_tem.dot_0 = rectangle.dot_0;
	triangle_tem.dot_1 = rectangle.dot_2;
	triangle_tem.dot_2 = rectangle.dot_1;
	cube_profile[10] = triangle_tem; 
	
	triangle_tem.dot_0 = rectangle.dot_0;
	triangle_tem.dot_1 = rectangle.dot_2;
	triangle_tem.dot_2 = rectangle.dot_3;
	cube_profile[11] = triangle_tem; 

	return p;
	
/*
	cube_profile.trangle_0.dot_0 = rectangle.dot_0;
	cube_profile.trangle_0.dot_1 = rectangle.dot_5;
	cube_profile.trangle_0.dot_2 = rectangle.dot_4;

	cube_profile.trangle_1.dot_0 = rectangle.dot_0;
	cube_profile.trangle_1.dot_1 = rectangle.dot_5;
	cube_profile.trangle_1.dot_2 = rectangle.dot_1;

	cube_profile.trangle_2.dot_0 = rectangle.dot_1;
	cube_profile.trangle_2.dot_1 = rectangle.dot_6;
	cube_profile.trangle_2.dot_2 = rectangle.dot_5;

	cube_profile.trangle_3.dot_0 = rectangle.dot_1;
	cube_profile.trangle_3.dot_1 = rectangle.dot_6;
	cube_profile.trangle_3.dot_2 = rectangle.dot_2;

	cube_profile.trangle_4.dot_0 = rectangle.dot_7;
	cube_profile.trangle_4.dot_1 = rectangle.dot_2;
	cube_profile.trangle_4.dot_2 = rectangle.dot_6;

	cube_profile.trangle_5.dot_0 = rectangle.dot_7;
	cube_profile.trangle_5.dot_1 = rectangle.dot_2;
	cube_profile.trangle_5.dot_2 = rectangle.dot_3;

	cube_profile.trangle_6.dot_0 = rectangle.dot_3;
	cube_profile.trangle_6.dot_1 = rectangle.dot_4;
	cube_profile.trangle_6.dot_2 = rectangle.dot_0;

	cube_profile.trangle_7.dot_0 = rectangle.dot_3;
	cube_profile.trangle_7.dot_1 = rectangle.dot_4;
	cube_profile.trangle_7.dot_2 = rectangle.dot_7;

	cube_profile.trangle_8.dot_0 = rectangle.dot_4;
	cube_profile.trangle_8.dot_1 = rectangle.dot_6;
	cube_profile.trangle_8.dot_2 = rectangle.dot_7;

	cube_profile.trangle_9.dot_0 = rectangle.dot_4;
	cube_profile.trangle_9.dot_1 = rectangle.dot_6;
	cube_profile.trangle_9.dot_2 = rectangle.dot_5;

	cube_profile.trangle_10.dot_0 = rectangle.dot_0;
	cube_profile.trangle_10.dot_1 = rectangle.dot_2;
	cube_profile.trangle_10.dot_2 = rectangle.dot_1;

	cube_profile.trangle_11.dot_0 = rectangle.dot_0;
	cube_profile.trangle_11.dot_1 = rectangle.dot_2;
	cube_profile.trangle_11.dot_2 = rectangle.dot_3;
	return cube_profile;
*/


}

//判断一点是否在三角面内
bool get_confirm_information(Dot P, Triangle trangle)
{
	Vect pa, pb, pc, ab, ac;
	Dot p, a, b, c;
	double area_true, area_test;
	Vect s1, s2, s3;
	p = P;
	a = trangle.dot_0;
	b = trangle.dot_1;
	c = trangle.dot_2;
	pa = get_vector(p, a);
	pb = get_vector(p, b);
	pc = get_vector(p, c);
	ab = get_vector(a, b);
	ac = get_vector(a, c);
	area_true = 0.5 * mode(cross_product(ab, ac));
	s1 = cross_product(pa, pb);
	s2 = cross_product(pb, pc);
	s3 = cross_product(pc, pa);
	area_test = 0.5 * (mode(s1) + mode(s2) + mode(s3));
	if (area_true == area_test)
	{
		return true;
	}
	else
	{
		return false;
	}

}

//判断一个点是否在某一面内并输出面类
Triangle get_intersection_plane(Dot P, Triangle cube_profile[11])
{
	if (get_confirm_information(P,cube_profile[0]))
	{
		return cube_profile[0];
	}
	else if (get_confirm_information(P, cube_profile[1]))
	{
		return cube_profile[1];
	}
	else if (get_confirm_information(P,cube_profile[2]))
	{
		return cube_profile[2];
	}
	else if (get_confirm_information(P, cube_profile[3]))
	{
		return cube_profile[3];
	}
	else if (get_confirm_information(P, cube_profile[4]))
	{
		return cube_profile[4];
	}
	else if (get_confirm_information(P, cube_profile[5]))
	{
		return cube_profile[5];
	}
	else if (get_confirm_information(P, cube_profile[6]))
	{
		return cube_profile[6];
	}
	else if (get_confirm_information(P, cube_profile[7]))
	{
		return cube_profile[7];
	}
	else if (get_confirm_information(P, cube_profile[8]))
	{
		return cube_profile[8];
	}
	else if (get_confirm_information(P, cube_profile[9]))
	{
		return cube_profile[9];
	}
	else if (get_confirm_information(P, cube_profile[10]))
	{
		return cube_profile[10];
	}
	else if (get_confirm_information(P, cube_profile[11]))
	{
		return cube_profile[11];
	}
	
}

//根据相交点和三角点计算最近边
Dot * get_distance(Dot P, Triangle triangle)
{
	Dot A, B, C;
	static Dot broder[1];
	Dot *q;
	q = broder;
	Vect ab, bc, ca, pa, pb, pc;
	double distance_ab, distance_bc, distance_ca, distance_min;

	A = triangle.dot_0;
	B = triangle.dot_1;
	C = triangle.dot_2;

	ab = get_vector(A, B);
	bc = get_vector(B, C);
	ca = get_vector(C, A);
	pa = get_vector(P, A);
	pb = get_vector(P, B);
	pc = get_vector(P, C);

	distance_ab = 0.5 * mode(cross_product(pa, pb)) / mode(ab);
	distance_bc = 0.5 * mode(cross_product(pb, pc)) / mode(bc);
	distance_ca = 0.5 * mode(cross_product(pc, pa)) / mode(ca);

	distance_min =min( distance_ab, min(distance_bc, distance_ca));

	if (distance_min == distance_ab)
	{
		broder[0] = A;
		broder[1] = B;
	}
	else if (distance_min == distance_bc)
	{
		broder[0] = B;
		broder[1] = C;
	}
	else if (distance_min == distance_ca)
	{
		broder[0] = C;
		broder[1] = A;
	}
	return q;
}

//判断两个点类Dot的对象是否一致
bool get_equality(Dot A, Dot B)
{
	if (A.x == B.x && A.y == B.y && A.z == B.z)
	{
		return true;
	}
	else
	{
		return false;
	}
}

//重定向get_equality函数判断两面是否一致
bool get_equality(Triangle A, Triangle B)
{
	if (get_equality(A.dot_0,B.dot_0) || get_equality(A.dot_0, B.dot_1)|| get_equality(A.dot_0, B.dot_2))
	{
		if (get_equality(A.dot_1, B.dot_0) || get_equality(A.dot_1, B.dot_1) || get_equality(A.dot_1, B.dot_2))
		{
			if (get_equality(A.dot_2, B.dot_0) || get_equality(A.dot_2, B.dot_1) || get_equality(A.dot_2, B.dot_2))
			{
				return true;
					 
			}
			else
			{
				return false;
			}

		}
		else
		{
			return false;
		}
	}
	else
	{
		return false;
	}
}





//根据最小边找出相邻三角形
Triangle get_adjacency(Dot A, Dot B, Triangle intersection_profile, Triangle cube_profile[11])
{
	for (int i = 0; i < 12; i++)
	{
		if (get_equality(A, cube_profile[i].dot_0) || get_equality(A, cube_profile[i].dot_1)
			|| get_equality(A,cube_profile[i].dot_2))
		{
			if (get_equality(B, cube_profile[i].dot_0) || get_equality(B, cube_profile[i].dot_1)
				|| get_equality(B, cube_profile[i].dot_2))
			{
				if (!get_equality(intersection_profile, cube_profile[i]))
				{
					return cube_profile[i];
				}
			}
		}

	}

}

// 判断两个三角面是否平行
bool get_information_parallel(Triangle intersection_profile, Triangle adjacency)
{
	Vect vector_normal_one, vector_normal_two;
	vector_normal_one = get_vector_normal(intersection_profile);
	vector_normal_two = get_vector_normal(adjacency);
	if (mode(cross_product(vector_normal_one, vector_normal_two)) == 0)
	{
		return true;
	}
	else
	{
		return false;
	}

}

//根据相交点和相临边上两点计算投影点
Dot get_projector_dot(Dot P, Dot A, Dot B)
{
	Dot T;
	Vect ap, ab;
	double projector_distance;
	ap = get_vector(A, P);
	ab = get_vector(A, B);
	projector_distance = dot_product(ap, ab) / mode(ab);
	
	T.x = A.x + projector_distance * ab.x;
	T.y = A.y + projector_distance * ab.y;
	T.z = A.z + projector_distance * ab.z;
	return T;
}







int main()
{
	Dot P, X1, X2;
	P = dot_assign(0.63434, 0, 0.1);
	X1 = dot_assign(0, 0, 0);
	X2 = dot_assign(1, 1, 1);
	Rectangle rectangle;
	rectangle = get_rectangle(X1, X2);
	
	cout << rectangle.dot_0.x;
	cout << rectangle.dot_0.y;
	cout << rectangle.dot_0.z;
	cout << "\n";
	cout << rectangle.dot_1.x;
	cout << rectangle.dot_1.y;
	cout << rectangle.dot_1.z;
	cout << "\n";
	cout << rectangle.dot_2.x;
	cout << rectangle.dot_2.y;
	cout << rectangle.dot_2.z;
	cout << "\n";
	cout << rectangle.dot_3.x;
	cout << rectangle.dot_3.y;
	cout << rectangle.dot_3.z;
	cout << "\n";
	cout << rectangle.dot_4.x;
	cout << rectangle.dot_4.y;
	cout << rectangle.dot_4.z;
	cout << "\n";
	cout << rectangle.dot_5.x;
	cout << rectangle.dot_5.y;
	cout << rectangle.dot_5.z;
	cout << "\n";
	cout << rectangle.dot_6.x;
	cout << rectangle.dot_6.y;
	cout << rectangle.dot_6.z;
	cout << "\n";
	cout << rectangle.dot_7.x;
	cout << rectangle.dot_7.y;
	cout << rectangle.dot_7.z;
	cout << "\n";
	
	Triangle cube_profile[11];
	Triangle * cube_profile_pointer;
	
	cube_profile_pointer = get_cube_profile(rectangle);
	for (int i = 0; i < 12; i++)
	{
		cube_profile[i] = *(cube_profile_pointer + i);
	}
	
	cube_profile[0] = *cube_profile_pointer;

	cout << (*cube_profile_pointer).dot_0.x;
	cout << (*cube_profile_pointer).dot_0.y;
	cout << (*cube_profile_pointer).dot_0.z;
	cout << "\t";
	cout << (*cube_profile_pointer).dot_1.x;
	cout << (*cube_profile_pointer).dot_1.y;
	cout << (*cube_profile_pointer).dot_1.z;
	cout << "\t";
	cout << (*cube_profile_pointer).dot_2.x;
	cout << (*cube_profile_pointer).dot_2.y;
	cout << (*cube_profile_pointer).dot_2.z;
	cout << "\n";

	cout << (*(cube_profile_pointer + 1)).dot_0.x;
	cout << (*(cube_profile_pointer + 1)).dot_0.y;
	cout << (*(cube_profile_pointer + 1)).dot_0.z;
	cout << "\t";
	cout << (*(cube_profile_pointer + 1)).dot_1.x;
	cout << (*(cube_profile_pointer + 1)).dot_1.y;
	cout << (*(cube_profile_pointer + 1)).dot_1.z;
	cout << "\t";
	cout << (*(cube_profile_pointer + 1)).dot_2.x;
	cout << (*(cube_profile_pointer + 1)).dot_2.y;
	cout << (*(cube_profile_pointer + 1)).dot_2.z;
	cout << "\n";

	cout << (*(cube_profile_pointer + 2)).dot_0.x;
	cout << (*(cube_profile_pointer + 2)).dot_0.y;
	cout << (*(cube_profile_pointer + 2)).dot_0.z;
	cout << "\t";
	cout << (*(cube_profile_pointer + 2)).dot_1.x;
	cout << (*(cube_profile_pointer + 2)).dot_1.y;
	cout << (*(cube_profile_pointer + 2)).dot_1.z;
	cout << "\t";
	cout << (*(cube_profile_pointer + 2)).dot_2.x;
	cout << (*(cube_profile_pointer + 2)).dot_2.y;
	cout << (*(cube_profile_pointer + 2)).dot_2.z;
	cout << "\n";

	cout << (*(cube_profile_pointer + 3)).dot_0.x;
	cout << (*(cube_profile_pointer + 3)).dot_0.y;
	cout << (*(cube_profile_pointer + 3)).dot_0.z;
	cout << "\t";
	cout << (*(cube_profile_pointer + 3)).dot_1.x;
	cout << (*(cube_profile_pointer + 3)).dot_1.y;
	cout << (*(cube_profile_pointer + 3)).dot_1.z;
	cout << "\t";
	cout << (*(cube_profile_pointer + 3)).dot_2.x;
	cout << (*(cube_profile_pointer + 3)).dot_2.y;
	cout << (*(cube_profile_pointer + 3)).dot_2.z;
	cout << "\n";

	cout << (*(cube_profile_pointer + 4)).dot_0.x;
	cout << (*(cube_profile_pointer + 4)).dot_0.y;
	cout << (*(cube_profile_pointer + 4)).dot_0.z;
	cout << "\t";
	cout << (*(cube_profile_pointer + 4)).dot_1.x;
	cout << (*(cube_profile_pointer + 4)).dot_1.y;
	cout << (*(cube_profile_pointer + 4)).dot_1.z;
	cout << "\t";
	cout << (*(cube_profile_pointer + 4)).dot_2.x;
	cout << (*(cube_profile_pointer + 4)).dot_2.y;
	cout << (*(cube_profile_pointer + 4)).dot_2.z;
	cout << "\n";

	cout << (*(cube_profile_pointer + 5)).dot_0.x;
	cout << (*(cube_profile_pointer + 5)).dot_0.y;
	cout << (*(cube_profile_pointer + 5)).dot_0.z;
	cout << "\t";
	cout << (*(cube_profile_pointer + 5)).dot_1.x;
	cout << (*(cube_profile_pointer + 5)).dot_1.y;
	cout << (*(cube_profile_pointer + 5)).dot_1.z;
	cout << "\t";
	cout << (*(cube_profile_pointer + 5)).dot_2.x;
	cout << (*(cube_profile_pointer + 5)).dot_2.y;
	cout << (*(cube_profile_pointer + 5)).dot_2.z;
	cout << "\n";

	cout << (*(cube_profile_pointer + 6)).dot_0.x;
	cout << (*(cube_profile_pointer + 6)).dot_0.y;
	cout << (*(cube_profile_pointer + 6)).dot_0.z;
	cout << "\t";
	cout << (*(cube_profile_pointer + 6)).dot_1.x;
	cout << (*(cube_profile_pointer + 6)).dot_1.y;
	cout << (*(cube_profile_pointer + 6)).dot_1.z;
	cout << "\t";
	cout << (*(cube_profile_pointer + 6)).dot_2.x;
	cout << (*(cube_profile_pointer + 6)).dot_2.y;
	cout << (*(cube_profile_pointer + 6)).dot_2.z;
	cout << "\n";
	
	cout << (*(cube_profile_pointer + 7)).dot_0.x;
	cout << (*(cube_profile_pointer + 7)).dot_0.y;
	cout << (*(cube_profile_pointer + 7)).dot_0.z;
	cout << "\t";
	cout << (*(cube_profile_pointer + 7)).dot_1.x;
	cout << (*(cube_profile_pointer + 7)).dot_1.y;
	cout << (*(cube_profile_pointer + 7)).dot_1.z;
	cout << "\t";
	cout << (*(cube_profile_pointer + 7)).dot_2.x;
	cout << (*(cube_profile_pointer + 7)).dot_2.y;
	cout << (*(cube_profile_pointer + 7)).dot_2.z;
	cout << "\n";

	cout << (*(cube_profile_pointer + 8)).dot_0.x;
	cout << (*(cube_profile_pointer + 8)).dot_0.y;
	cout << (*(cube_profile_pointer + 8)).dot_0.z;
	cout << "\t";
	cout << (*(cube_profile_pointer + 8)).dot_1.x;
	cout << (*(cube_profile_pointer + 8)).dot_1.y;
	cout << (*(cube_profile_pointer + 8)).dot_1.z;
	cout << "\t";
	cout << (*(cube_profile_pointer + 8)).dot_2.x;
	cout << (*(cube_profile_pointer + 8)).dot_2.y;
	cout << (*(cube_profile_pointer + 8)).dot_2.z;
	cout << "\n";

	cout << (*(cube_profile_pointer + 9)).dot_0.x;
	cout << (*(cube_profile_pointer + 9)).dot_0.y;
	cout << (*(cube_profile_pointer + 9)).dot_0.z;
	cout << "\t";
	cout << (*(cube_profile_pointer + 9)).dot_1.x;
	cout << (*(cube_profile_pointer + 9)).dot_1.y;
	cout << (*(cube_profile_pointer + 9)).dot_1.z;
	cout << "\t";
	cout << (*(cube_profile_pointer + 9)).dot_2.x;
	cout << (*(cube_profile_pointer + 9)).dot_2.y;
	cout << (*(cube_profile_pointer + 9)).dot_2.z;
	cout << "\n";

	cout << (*(cube_profile_pointer + 10)).dot_0.x;
	cout << (*(cube_profile_pointer + 10)).dot_0.y;
	cout << (*(cube_profile_pointer + 10)).dot_0.z;
	cout << "\t";
	cout << (*(cube_profile_pointer + 10)).dot_1.x;
	cout << (*(cube_profile_pointer + 10)).dot_1.y;
	cout << (*(cube_profile_pointer + 10)).dot_1.z;
	cout << "\t";
	cout << (*(cube_profile_pointer + 10)).dot_2.x;
	cout << (*(cube_profile_pointer + 10)).dot_2.y;
	cout << (*(cube_profile_pointer + 10)).dot_2.z;
	cout << "\n";

	cout << (*(cube_profile_pointer + 11)).dot_0.x;
	cout << (*(cube_profile_pointer + 11)).dot_0.y;
	cout << (*(cube_profile_pointer + 11)).dot_0.z;
	cout << "\t";
	cout << (*(cube_profile_pointer + 11)).dot_1.x;
	cout << (*(cube_profile_pointer + 11)).dot_1.y;
	cout << (*(cube_profile_pointer + 11)).dot_1.z;
	cout << "\t";
	cout << (*(cube_profile_pointer + 11)).dot_2.x;
	cout << (*(cube_profile_pointer + 11)).dot_2.y;
	cout << (*(cube_profile_pointer + 11)).dot_2.z;
	cout << "\n";
	cout << "\n";
	Triangle intersection_plane;
	intersection_plane = get_intersection_plane(P, cube_profile);
	
	cout << intersection_plane.dot_0.x;
	cout << intersection_plane.dot_0.y;
	cout << intersection_plane.dot_0.z;
	cout << "\t";
	cout << intersection_plane.dot_1.x;
	cout << intersection_plane.dot_1.y;
	cout << intersection_plane.dot_1.z;
	cout << "\t";
	cout << intersection_plane.dot_2.x;
	cout << intersection_plane.dot_2.y;
	cout << intersection_plane.dot_2.z;
	cout << "\n";
	
	Dot A, B;
	Dot *q;
	q = get_distance(P, intersection_plane);
	A = *q;
	B = *(q + 1);
	cout << A.x << A.y << A.z;
	cout << "\t";
	cout << B.x << B.y << B.z;
	cout << "\n";
	Triangle adjacency;

	adjacency= get_adjacency(A, B, intersection_plane, cube_profile);
	cout << adjacency.dot_0.x;
	cout << adjacency.dot_0.y;
	cout << adjacency.dot_0.z;
	cout << "\t";
	cout << adjacency.dot_1.x;
	cout << adjacency.dot_1.y;
	cout << adjacency.dot_1.z;
	cout << "\t";
	cout << adjacency.dot_2.x;
	cout << adjacency.dot_2.y;
	cout << adjacency.dot_2.z;
	cout << "\n";
	bool fff;
	fff = get_information_parallel(intersection_plane, adjacency);
	cout << fff;
	Dot T;

	if (!fff)
	{
		T = get_projector_dot(P, A, B);
	
	cout << T.x << "\t";
	cout << T.y << "\t";
	cout << T.z << "\t";
     }
	

	
	
	
	
	
	
	
	getchar();
}
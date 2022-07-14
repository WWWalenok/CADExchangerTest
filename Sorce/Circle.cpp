#include "Curve.h"

#include <cmath>
namespace curv
{
	Circle::Circle()
	{}

	Circle::Circle(double *sp, double _r)
	{
		SetR(_r);
		SetSpace(sp);
	}

	void  Circle::SetSpace(double *sp)
	{
		for(int i = 0, k = 0; i < 3; i++)
			for(int j = 0; j < 4; j++)
			{
				space[i][j] = sp[k];
				k++;
			}

		for(int n = 0; n < 3; n++)
		{

			double l = sqrt(
				+space[0][n] * space[0][n]
				+ space[1][n] * space[1][n]
				+ space[2][n] * space[2][n]
			);

			if(l < 1e-9)
			{
				space[2][n] = space[1][n] = space[0][n] = 0;
			}
			else
			{
				l = 1 / l;
				space[0][n] *= l;
				space[1][n] *= l;
				space[2][n] *= l;
			}

			for(int m = n + 1; m < 3; m++)
			{
				double dot = 0;
				for(int i = 0; i < 3; i++)
					dot += space[i][n] * space[i][m];

				for(int i = 0; i < 3; i++)
					space[i][m] = space[i][m] - space[i][n] * dot;
			}
		}

	}
	double *Circle::GetSpace()
	{
		auto sp = new double[12];
		for(int i = 0, k = 0; i < 3; i++)
			for(int j = 0; j < 4; j++)
			{
				sp[k] = space[i][j];
				k++;
			}
		return sp;
	}
	double *Circle::GetPoint(double t)
	{
		auto p = new double[3];
		GetPoint(t, p);
		return p;
	}
	void Circle::GetPoint(double t, double *p)
	{
		p[0] = space[0][3];
		p[1] = space[1][3];
		p[2] = space[2][3];

		double
			_cos = cos(t),
			_sin = sin(t);

		for(int i = 0; i < 3; i++)
		{
			p[i] += space[i][0] * _cos * r;
			p[i] += space[i][1] * _sin * r;
		}

	}


	void  Circle::SetR(double _r)
	{
		r = _r;
	}
	double  Circle::GetR()
	{
		return r;
	}
}
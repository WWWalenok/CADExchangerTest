#pragma once

#include "ICurve.h"

namespace curv
{
	const double base_space[]
	{
		1, 0, 0, 0,
		0, 1, 0, 0,
		0, 0, 1, 0
	};

	class DLL_EXPORT Circle: public ICurve
	{

		double space[3][4]
		{
			{1, 0, 0, 0},
			{0, 1, 0, 0},
			{0, 0, 1, 0}
		};

		double r = 1;

	public:

		Circle();
		Circle(double *, double);

		void  SetSpace(double *) override;
		double *GetSpace() override;
		double *GetPoint(double) override;
		void GetPoint(double, double *) override;

		void  SetR(double);
		double  GetR();


	};

	class DLL_EXPORT Ellipse:public ICurve
	{

		double space[3][4]
		{
			{1, 0, 0, 0},
			{0, 1, 0, 0},
			{0, 0, 1, 0}
		};

		double
			a = 1,
			b = 1;

	public:

		Ellipse();
		Ellipse(double *, double, double);

		void  SetSpace(double *) override;
		double *GetSpace() override;
		double *GetPoint(double) override;
		void GetPoint(double, double *) override;

		void  SetA(double);
		double  GetA();

		void  SetB(double);
		double  GetB();
	};

	class DLL_EXPORT Helixe:public ICurve
	{

		double space[3][4]
		{
			{1, 0, 0, 0},
			{0, 1, 0, 0},
			{0, 0, 1, 0}
		};

		double
			r = 1,
			h = 1;

	public:

		Helixe();
		Helixe(double *, double, double);

		void  SetSpace(double *) override;
		double *GetSpace() override;
		double *GetPoint(double) override;
		void GetPoint(double, double *) override;

		void  SetR(double);
		double  GetR();

		void  SetH(double);
		double  GetH();
	};
}
#pragma once

#define DLL_EXPORT 


#ifdef _WIN32

#undef DLL_EXPORT
#define DLL_EXPORT __declspec(dllexport)

#endif // _WIN32

#ifdef __linux__

#undef DLL_EXPORT
#define DLL_EXPORT __attribute__((visibility("default")))

#endif // _WIN32



namespace curv
{
	class DLL_EXPORT ICurve
	{
	public:
		virtual void  SetSpace(double *) = 0;
		virtual double *GetSpace() = 0;
		virtual double *GetPoint(double) = 0;
		virtual void GetPoint(double, double*) = 0;
	};
}

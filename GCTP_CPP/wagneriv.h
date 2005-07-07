#ifndef WAGNERIV_H
#define WAGNERIV_H

#include "projection.h"

class WagnerIV : public Projection
{
public:

	WagnerIV();
	WagnerIV(double gctpParams[], ProjUnit units, ProjDatum dat);

protected:

	void _init();

	void _inverse(double x, double y);
	void _forward(double lon, double lat);

};

#endif


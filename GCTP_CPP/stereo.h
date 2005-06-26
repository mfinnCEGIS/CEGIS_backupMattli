
#ifndef STEREO_H
#define STEREO_H

#include "azimuthal.h"

class Stereo : public Azimuthal
{
public:

	Stereo();
	Stereo(double gctpParams[], ProjUnit units, ProjDatum dat);

protected:

	double m_sinCenterLat;
	double m_cosCenterLat;

	void _init();

	void _inverse(double x, double y);
	void _forward(double lon, double lat);
};

#endif

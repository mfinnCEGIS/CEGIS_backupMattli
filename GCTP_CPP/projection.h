#ifndef PROJECTION_H
#define PROJECTION_H

#include <math.h>
#include "cproj.h"


class Projection
{
  // Associations
  // Attributes
  public:
    char* name;
    int number;
    int unitCode;
    int datum;
    int spheroid;
    double longitude;
    double latitude;
    double x_coord;
    double y_coord;
    double gctpParams[15];
  // Operations
  public:
    virtual long forward ( double lon, double lat, double* x = NULL, double* y = NULL ) = 0;
    virtual long inverse ( double x, double y, double* lon = NULL, double* lat = NULL ) = 0;
    virtual long forward_init (  ) = 0;
    virtual long inverse_init (  ) = 0;
    double getX (  );
    double getY (  );
    double getLat (  );
    double getLon (  );
    long getXY ( double* x, double* y );
    long getLatLon ( double* lat, double* lon );
    Projection ( double gctpParameters[15] );
};

#endif

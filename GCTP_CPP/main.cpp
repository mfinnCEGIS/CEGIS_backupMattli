#include <stdio.h>

#include "sinusoidal.h"
#include "equirectangular.h"
#include "albersConEqArea.h"
#include "projexception.h"
#include ".\gctpc\source\proj.h"
int main( int argc, char **argv )
{
  double equirectParams[15] = { 6370997.000000, 0.000000, 0.000000, 0.000000, 0.000000, 
				   			          0.000000,	0.000000, 0.000000, 0.000000, 0.000000, 
								      0.000000,	0.000000, 0.000000, 0.000000, 0.000000  };

  double sinusoidalParams[15] = { 6370997.000000, 0.000000, 0.000000, 0.000000, 0.000000, 
				    		            0.000000, 0.000000, 0.000000, 0.000000, 0.000000, 
								        0.000000, 0.000000, 0.000000, 0.000000, 0.000000  };

  double alberParams[15] = { 6370997.000000, 0, 40000000.000000, 50000000.000000, 0.000000, 
				    		            0.000000, 0.000000, 0.000000, 0.000000, 0.000000, 
								        0.000000, 0.000000, 0.000000, 0.000000, 0.000000  };

  double lat = 110.4;
  double lon = -55.234;
  double latOut = 0;
  double lonOut = 0;
  double x = 0;
  double y = 0;
  
  try {
	 Sinusoidal sinSd(sinusoidalParams, METER, 0, 0);

	 Equirectangular eq(equirectParams, METER, 0, 0);
     AlbersConEqArea albers(alberParams, METER, 0, 0);

	 printf("GCTP-CPP Output\n\n");

	 sinSd.forward(lon, lat, &x, &y);
	 printf("Sinusoidal forward lon: %f lat: %f x: %f y %f\n", lon, lat, x, y);
	 sinSd.inverse(x, y, &latOut, &lonOut);
	 printf("Sinusoidal inverse x: %f y: %f lon: %f lat: %f\n", x, y, lonOut, latOut);

	 eq.forward(lon, lat, &x, &y);
	 printf("Equirectangular lon: %f lat: %f x: %f y %f\n", lon, lat, x, y);
	 eq.inverse(x, y, &lonOut, &latOut);
	 printf("Equirectangular inverse x: %f y: %f lon: %f lat: %f\n", x, y, lonOut, latOut);

	 albers.forward(lon, lat, &x, &y);
	 printf("Albers lon: %f lat: %f x: %f y %f\n", lon, lat, x, y);
     albers.inverse(x, y, &lonOut, &latOut);
     printf("Albers inverse x: %f y: %f lon: %f lat: %f\n", x, y, lonOut, latOut);
  }

  catch (ProjException e) {
	  printf(e.error().c_str());
  }



  return 0;
}

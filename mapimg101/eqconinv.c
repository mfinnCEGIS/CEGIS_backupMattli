//Copyright 1993 United States Geological Survey
//Released under GPL with MapIMG copyright 2003 USGS

/*******************************************************************************
NAME                            EQUIDISTANT CONIC 

PURPOSE:	Transforms input Easting and Northing to longitude and
		latitude for the Equidistant Conic projection.  The
		Easting and Northing must be in meters.  The longitude
		and latitude values will be returned in radians.

PROGRAMMER              DATE
----------              ----
T. Mittan		Mar, 1993

ALGORITHM REFERENCES

1.  Snyder, John P., "Map Projections--A Working Manual", U.S. Geological
    Survey Professional Paper 1395 (Supersedes USGS Bulletin 1532), United
    State Government Printing Office, Washington D.C., 1987.

2.  Snyder, John P. and Voxland, Philip M., "An Album of Map Projections",
    U.S. Geological Survey Professional Paper 1453 , United State Government
    Printing Office, Washington D.C., 1989.
*******************************************************************************/
#include "cproj.h"

/* Variables common to all subroutines in this code file
  -----------------------------------------------------*/
static double r_major;		/* major axis 				*/
static double r_minor;		/* minor axis 				*/
static double lon_center;	/* Center longitude (projection center) */
static double lat_origin;	/* center latitude			*/
static double e0,e1,e2,e3;	/* eccentricity constants		*/
static double e,es,esp;		/* eccentricity constants		*/
static double ml0;		/* small value m			*/
static double false_northing;	/* y offset in meters			*/
static double false_easting;	/* x offset in meters			*/
static double ns;
static double g;
static double rh;


/* Initialize the Equidistant Conic projection
  ------------------------------------------*/
long eqconinvint(r_maj,r_min,lat1,lat2,center_lon,center_lat,false_east,
	false_north, mode)

double r_maj;			/* major axis			*/
double r_min;			/* minor axis			*/
double lat1;			/* latitude of standard parallel*/
double lat2;			/* latitude of standard parallel*/
double center_lon;		/* center longitude		*/
double center_lat;		/* center latitude		*/
double false_east;		/* x offset in meters		*/
double false_north;		/* y offset in meters		*/
long   mode;			/* which format is present A B	*/
{
double temp;			/* temporary variable		*/
double sinphi,cosphi;		/* sin and cos values		*/
double ms1,ms2;
double ml1,ml2;

/* Place parameters in static storage for common use
  -------------------------------------------------*/
r_major = r_maj;
r_minor = r_min;
lon_center = center_lon;
lat_origin = center_lat;
false_northing = false_north;
false_easting = false_east;

temp = r_minor / r_major;
es = 1.0 - SQUARE(temp);
e = sqrt(es);
e0 = e0fn(es);
e1 = e1fn(es);
e2 = e2fn(es);
e3 = e3fn(es);

sincos(lat1,&sinphi,&cosphi);
ms1 = msfnz(e,sinphi,cosphi);
ml1 = mlfn(e0, e1, e2, e3, lat1);

/* format B
---------*/
if (mode != 0)
   {
   if (fabs(lat1 + lat2) < EPSLN)
      {
      p_error("Standard Parallels on opposite sides of equator","eqcon-for");
      return(81);
      }
   sincos(lat2,&sinphi,&cosphi);
   ms2 = msfnz(e,sinphi,cosphi);
   ml2 = mlfn(e0, e1, e2, e3, lat2);
   if (fabs(lat1 - lat2) >= EPSLN)
      ns = (ms1 - ms2) / (ml2 - ml1);
   else
      ns = sinphi;
   }
else
   ns = sinphi;
g = ml1 + ms1/ns;
ml0 = mlfn(e0, e1, e2, e3, center_lat);
rh = r_major * (g - ml0);
   

/* Report parameters to the user
  -----------------------------*/
if (mode != 0)
   {
   ptitle("EQUIDISTANT CONIC"); 
   radius2(r_major, r_minor);
   stanparl(lat1,lat2);
   cenlonmer(lon_center);
   origin(center_lat);
   offsetp(false_easting,false_northing);
   }
else 
   {
   ptitle("EQUIDISTANT CONIC"); 
   radius2(r_major, r_minor);
   stparl1(lat1);
   cenlonmer(lon_center);
   origin(center_lat);
   offsetp(false_easting,false_northing);
   }

return(OK);
}


/* Equidistant Conic inverse equations--mapping x,y to lat/long
  -----------------------------------------------------------*/
long eqconinv(x, y, lon, lat)
double x;			/* (O) X projection coordinate 	*/
double y;			/* (O) Y projection coordinate 	*/
double *lon;			/* (I) Longitude 		*/
double *lat;			/* (I) Latitude 		*/
{

double rh1;
double ml;
double con;
double theta;
long   flag;

/* Inverse equations
  -----------------*/
flag = 0;
x -= false_easting;
y  = rh - y + false_northing;
if (ns >= 0)
   {
   rh1 = sqrt(x * x + y * y); 
   con = 1.0;
   }
else
   {
   rh1 = -sqrt(x * x + y * y); 
   con = -1.0;
   }
theta = 0.0;
if (rh1  != 0.0)
   theta = atan2(con * x, con * y);
ml = g - rh1 / r_major;
*lat = phi3z(ml,e0,e1,e2,e3,&flag);
*lon = adjust_lon(lon_center + theta / ns);

if (flag != 0)
   return(flag);
else
   return(OK);
}

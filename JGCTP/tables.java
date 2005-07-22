package jgctp;


public class Tables
{
	public static final double factors[][] = 
	    {
			{1.0, 0.0, 0.0, 206264.8062470963, 57.29577951308231, 0.0},
			{0.0, 1.0, .3048006096012192, 0.0, 0.0, 1.000002000004},
			{0.0, 3.280833333333333, 1.0, 0.0, 0.0, 3.280839895013124},
			{.484813681109536e-5, 0.0, 0.0, 1.0, .27777777777778e-3, 0.0}, 
			{.0174532925199433, 0.0, 0.0, 3600, 1.0, 0.0},
			{0.0, .999998, .3048, 0.0, 0.0, 1.0}
		};
	
	public static final int NADUT[] = {1, 5, 1, 1, 5, 1, 1, 1, 1, 2, 1, 1, 1, 2, 1, 1, 2, 2,
				  1, 1, 5, 2, 1, 2, 5, 1, 2, 2, 2, 1, 1, 1, 5, 2, 1, 5,
				  2, 2, 5, 2, 1, 1, 5, 2, 2, 1, 2, 1, 2, 2, 1, 2, 2, 2};
	
	/* the Nad 27 State Plane Zones are set in this array
	--------------------------------------------------*/
	public static final int NAD27[] = {101,102,5010,5300,201,202,203,301,302,401,402,403,404,
					405,406,407,501,502,503,600,700,901,902,903,1001,1002,5101,
					5102,5103,5104,5105,1101,1102,1103,1201,1202,1301,1302,1401,
					1402,1501,1502,1601,1602,1701,1702,1703,1801,1802,1900,2001,
					2002,2101,2102,2103,2111,2112,2113,2201,2202,2203,2301,2302,
					2401,2402,2403,2501,2502,2503,2601,2602,2701,2702,2703,2800,
					2900,3001,3002,3003,3101,3102,3103,3104,3200,3301,3302,3401,
					3402,3501,3502,3601,3602,3701,3702,3800,3901,3902,4001,4002, 
					4100,4201,4202,4203,4204,4205,4301,4302,4303,4400,4501,4502,
					4601,4602,4701,4702,4801,4802,4803,4901,4902,4903,4904,5001,
					5002,5003,5004,5005,5006,5007,5008,5009,5201,5202,5400};
	
	/* the Nad 83 State Plane Zones are set in this array
	--------------------------------------------------*/
	
	public static final int NAD83[] = {101,102,5010,5300,201,202,203,301,302,401,402,403,
	              404,405,406,0000,501,502,503,600,700,901,902,903,1001,1002,
	              5101,5102,5103,5104,5105,1101,1102,1103,1201,1202,1301,1302,
	              1401,1402,1501,1502,1601,1602,1701,1702,1703,1801,1802,1900,
	              2001,2002,2101,2102,2103,2111,2112,2113,2201,2202,2203,2301,
	              2302,2401,2402,2403,2500,0000,0000,2600,0000,2701,2702,2703,
	              2800,2900,3001,3002,3003,3101,3102,3103,3104,3200,3301,3302,
	              3401,3402,3501,3502,3601,3602,3701,3702,3800,3900,0000,4001,
	              4002,4100,4201,4202,4203,4204,4205,4301,4302,4303,4400,4501,
	              4502,4601,4602,4701,4702,4801,4802,4803,4901,4902,4903,4904,
	              5001,5002,5003,5004,5005,5006,5007,5008,5009,5200,0000,5400};
	
		/* Semi-Major axis of supported Spheroids */
	public static final  double major[] = {
			6378206.4,		/* 0: Clarke 1866  */
			6378249.145,		/* 1: Clarke 1880 */
			6377397.155,		/* 2: Bessel */
			6378157.5,		/* 3: International 1967 */
			6378388.0,		/* 4: International 1909 */
			6378135.0,		/* 5: WGS 72 */
			6377276.3452,		/* 6: Everest */
			6378145.0,		/* 7: WGS 66 */
	        6378137.0,		/* 8: GRS 1980 */
			6377563.396,		/* 9: Airy */
			6377304.063,		/* 10: Modified Everest */
			6377340.189,		/* 11: Modified Airy */
	        6378137.0,		/* 12: WGS 84 */
			6378155.0,		/* 13: Southeast Asia */
			6378160.0,		/* 14: Australian National */
			6378245.0,		/* 15: Krassovsky */
	        6378270.0,		/* 16: Hough */
			6378166.0,		/* 17: Mercury 1960 */
			6378150.0,		/* 18: Modified Mercury 1968 */
			6370997.0,		/* 19: Sphere of Radius 6370997 meters*/
			6377483.865,		/* 20: Bessel 1841(Namibia) */
			6377298.556,		/* 21: Everest (Sabah & Sarawak) */
			6377301.243,		/* 22: Everest (India 1956) */
			6377295.664,		/* 23: Everest (Malaysia 1969) */
			6377304.063,		/* 24: Everest (Malay & Singapr 1948)*/
			6377309.613,		/* 25: Everest (Pakistan) */
			6378388.0,		/* 26: Hayford */
			6378200.0,		/* 27: Helmert 1906 */
			6378160.000,		/* 28: Indonesian 1974 */
			6378160.0,		/* 29: South American 1969 */
			6378165.0};		/* 30: WGS 60 */
	
		/* Semi-Minor axis of supported Spheroids */
	public static final double minor[] = {
			6356583.8,		/* 0: Clarke 1866 */
			6356514.86955,		/* 1: Clarke 1880 */
			6356078.96284,		/* 2: Bessel */
			6356772.2,		/* 3: International 1967 */
	        6356911.94613,		/* 4: International 1909 */
			6356750.519915,		/* 5: WGS 72 */
			6356075.4133,		/* 6: Everest */
	        6356759.769356,		/* 7: WGS 66 */
			6356752.31414,		/* 8: GRS 1980 */
			6356256.91,		/* 9: Airy */
	        6356103.039,		/* 10: Modified Everest */
			6356034.448,		/* 11: Modified Airy */
			6356752.314245,		/* 12: WGS 84 */
	        6356773.3205,		/* 13: Southeast Asia */
			6356774.719,		/* 14: Australian National */
			6356863.0188,		/* 15: Krassovsky */
	        6356794.343479,		/* 16: Hough */
			6356784.283666,		/* 17: Mercury 1960 */
			6356768.337303,		/* 18: Modified Mercury 1968 */
	        6370997.0,		/* 19: Sphere of Radius 6370997 meters*/
			6356165.382966,		/* 20: Bessel 1841(Namibia) */
			6356097.571445,		/* 21: Everest (Sabah & Sarawak) */
			6356100.228368,		/* 22: Everest (India 1956) */
			6356094.667915,		/* 23: Everest (Malaysia 1969) */
			6356103.038993,		/* 24: Everest (Malay & Singapr 1948)*/
			6356108.570542,		/* 25: Everest (Pakistan) */
			6356911.946128,		/* 26: Hayford */
			6356818.169,		/* 27: Helmert 1906 */
			6356774.504086,		/* 28: Indonesian 1974 */
			6356774.719,		/* 29: South American 1969 */
			6356783.287};
}
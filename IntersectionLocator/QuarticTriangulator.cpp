/*
 * File: QuarticTriangulator.cpp
 * Purpose: This file contains the implementation of a class for
 *          performing a O(n^4) Delauney triangulation.
 *
 * Programmer: Ryan Stelzleni
 * Date: 8-16-04
 *
 * This code was written for the United States Geological Survey.
 */


// Majic numbers for CVS
// $Id: QuarticTriangulator.cpp,v 1.4 2004/11/23 20:50:30 rstelzleni Exp $


#include "QuarticTriangulator.h"

// This is a horrible function but it is intended to be a brute force 
// solution and not efficient or elegant.
void QuarticTriangulator::triangulate( const std::vector<ControlPoint> &points,
                                       Triangulation &result )
{
   bool bGoodTriangle;
   int n = points.size();

   // Just iterate through all possible triangles and keep the good ones.
   for( int i = 0; i < n; ++i )
   {
      Point A( const_cast<OGRPoint&>(points[i].point).getX(), 
               const_cast<OGRPoint&>(points[i].point).getY() );
      for( int j = 0; j < n; ++j )
      {
         if( j != i )
         {
            Point B( const_cast<OGRPoint&>(points[j].point).getX(), 
                     const_cast<OGRPoint&>(points[j].point).getY() );
            for( int k = 0; k < n; ++k )
            {
               if( k != i && k != j )
               {
                  Point C( const_cast<OGRPoint&>(points[k].point).getX(), 
                           const_cast<OGRPoint&>(points[k].point).getY() );

                  Triangle triangle( A, B, C );
                  Circle circumCircle( triangle );
                  bGoodTriangle = true;

                  for( int c = 0; c < n; ++c )
                  {
                     if( c != i && c != j && c != k )
                     {
                        Point D( const_cast<OGRPoint&>(points[c].point).getX(), 
                                 const_cast<OGRPoint&>(points[c].point).getY() );
                        if( circumCircle.encloses( D ) )
                        {
                           bGoodTriangle = false;
                           break;
                        }
                     }
                  } // end for c

                  if( bGoodTriangle )
                  {
                     Tri t;
                     t.a = i;
                     t.b = j;
                     t.c = k;
                     t.triangle = triangle;
                     result.push_back( t );
                  }
               }
            } // end for k
         }
      } // end for j
   } // end for i

   // Do final check and fix any problems.
   // This isn't actually necessary, but I'm leaving it commented in
   // case I want to run tests in the future.
/*   Triangulation old( result );
   bool isAllGood;

   result.clear();
   for( int m = 0; m < old.size(); ++m )
   {
      Circle C( old[m].triangle );
      isAllGood = true;

      for( int n = 0; n < points.size(); ++n )
      {
         Point P( points[n].point.getX(), points[n].point.getY() );
         if(  n != old[m].a && n != old[m].b && n != old[m].c &&
              C.encloses( P ) )
         {
            isAllGood = false;
            break;
         }
      }
      if( isAllGood )
      {
         result.push_back( old[m] );
      }
      else
      {
         printf( "Removed One\n" );
      }
   }
   */
   
   return;
} // end function triangulate

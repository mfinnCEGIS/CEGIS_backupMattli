/*
 * File: DistanceFilter.cpp
 * Purpose: This file contains the implementation of a class
 *          for a control point filter.  This filter uses the
 *          magnitude of each control point's displacement
 *          vector to filter out control points that seem
 *          worse than others.  This class implements the
 *          Filter interface.
 *
 * Programmer: Ryan Stelzleni
 * Date: 8-24-04
 */


// Majic numbers for CVS
// $Id: DistanceFilter.cpp,v 1.2 2004/10/18 22:42:51 rstelzleni Exp $


#include "DistanceFilter.h"

void DistanceFilter::filter( std::vector<ControlPoint> &point, 
                             const double &info )
{
   std::vector<double> length;
   std::vector<double>::iterator iLength, maxLength;
   std::vector<ControlPoint>::iterator maxControl;
   int n = point.size(), numToRemove;

   length.reserve( n );

   for( int i=0; i < n; ++i )
   {
      Point original( point[i].origPoint.getX(),
                      point[i].origPoint.getY() );
      Point control( point[i].point.getX(),
                     point[i].point.getY() );

      length.push_back( original.distanceTo( control ) );
   } // end for i

   
   numToRemove = n * info;

   // Erase all the elements that are furthest away from the original 
   // points.
   for( int j=0; j < numToRemove; ++j )
   {
      maxLength = std::max_element( length.begin(), length.end() );

      // This just syncs up the maxControl and maxLength iterators
      for( iLength = length.begin(), maxControl = point.begin();
           iLength != maxLength; ++iLength, ++maxControl ) ;

      point.erase( maxControl );
      length.erase( maxLength );

   } // end for j
   
   return;
}

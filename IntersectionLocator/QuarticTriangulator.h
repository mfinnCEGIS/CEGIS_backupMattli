/*
 * @file QuarticTriangulator.h
 * Purpose: This file contains the declaration of a class for
 *          performing a O(n^4) Delauney triangulation.
 *
 * @author Ryan Stelzleni
 * @date 8-16-04
 *
 * This code was written for the United States Geological Survey.
 */



// Majic numbers for CVS
// $Id: QuarticTriangulator.h,v 1.3 2004/11/02 01:20:46 rstelzleni Exp $


#ifndef QUARTICTRIANGULATOR_H
#define QUARTICTRIANGULATOR_H

#pragma warning(disable: 4786)

#include "DelauneyTriangulator.h"


/**
 * The QuarticTriangulator class implements the DelauneyTriangulator
 * interface to triangulate a set of ControlPoints.  The triangulation
 * is output through the Triangulation &result.
 */
class QuarticTriangulator : public DelauneyTriangulator
{
public:
   virtual ~QuarticTriangulator() {}

   /**
    * This function performs the triangulation.
    * Pre: points should already contain identified control points.
    * Post: result will contain a Triangulation (defined in 
    *       DelauneyTriangulator.h) of the control points.
    * @param points The ControlPoints to triangulate.
    * @param result The resulting triangulation. 
    */
   virtual void triangulate( const std::vector<ControlPoint> &points, 
                             Triangulation &result );
};


#endif //QUARTICTRIANGULATOR_H

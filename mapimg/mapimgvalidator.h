// $Id: mapimgvalidator.h,v 1.8 2005/02/24 17:59:14 jtrent Exp $

#ifndef MAPIMGVALIDATOR_H
#define MAPIMGVALIDATOR_H

#include <qobject.h>
#include <qvalidator.h>
#include <qglobal.h>

#include "mapimgdatatypes.h"


class QString;


class MapimgValidator : public QValidator
{
   Q_OBJECT
      Q_PROPERTY( double bottom READ bottom WRITE setBottom )
      Q_PROPERTY( double top READ top WRITE setTop )
      Q_PROPERTY( int decimals READ decimals WRITE setDecimals )

public:
   MapimgValidator( QObject* parent, const char* name = 0 );
   MapimgValidator( QString mapimgDataType, QObject* parent, const char* name = 0 );
   MapimgValidator( double bottom, double top, int decimals, QObject* parent, const char* name = 0 );
   ~MapimgValidator();

   QValidator::State validate( QString & input, int & ) const;
   void fixup( QString& input ) const;

   virtual void setRange( double bottom, double top, int decimals = 0 );
   void setDataType( QString mapimgDataType );
   void setBottom( double );
   void setTop( double );
   void setDecimals( int );

   double bottom() const { return b; }
   double top() const { return t; }
   int decimals() const { return d; }

private:
#if defined(Q_DISABLE_COPY)
   MapimgValidator( const MapimgValidator & );
   MapimgValidator& operator=( const MapimgValidator & );
#endif

   double b, t;
   int d;
};


#endif //MAPIMGVALIDATOR_H



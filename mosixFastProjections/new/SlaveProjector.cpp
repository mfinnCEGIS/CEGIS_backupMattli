/*! 
 *
 * \author Mark Schisler
 *
 * \date $Date: 2005/09/08 16:41:22 $
 *
 * \version 0.1
 * 
 * \file SlaveProjector.cpp
 * 
 * \brief Implementation file for SlaveProjector class.
 *
 * \note This library is free software and is distributed under 
 * the MIT open source license.  For more information, consult 
 * the file COPYING.  
 *
 */

#include "Macros.h"
#include "SlaveProjector.h"
#include "GeneralProjector.h"

namespace USGSMosix {

// initialize static members
/******************************************************************************/

long int SlaveProjector::m_id(0);
ProjectorFactory SlaveProjector::m_projFactory;

// member functions
/******************************************************************************/

SlaveProjector::SlaveProjector( 
ProjImageInInterface & inInterface,
ProjImageOutInterface & imgOutInterface,
std::pair<unsigned long, unsigned long> scanlineRange  ) : 

m_projInterface( new GeneralProjector(inInterface, imgOutInterface)),
m_scanlineRange( scanlineRange )
{
    ++m_id;     
}

/******************************************************************************/

SlaveProjector::SlaveProjector( ProjectorInterface & interface,
std::pair<unsigned long, unsigned long> scanlineRange ) :

m_projInterface( &interface ),
m_scanlineRange( scanlineRange )
{
    ++m_id; 
}

/******************************************************************************/

SlaveProjector::~SlaveProjector()
{
    delete m_projInterface;    
}


/******************************************************************************/

const ProjLib::Projection * SlaveProjector::getOutputProjection()const
{
    return m_projInterface->getOutputProjection(); 
}

/******************************************************************************/

bool SlaveProjector::setupOutput()
{
    return m_projInterface->setupOutput();
}

/******************************************************************************/

ProjImageOutPiece SlaveProjector::projectPiece( long unsigned int beginLine,
                                                long unsigned int endLine )
{
    WRITE_DEBUG ("projecting piece" << std::endl );
    if ( setupOutput() ) 
    {
        ProjImageOutPiece p = m_projInterface->projectPiece(beginLine,endLine);
        return p;
    } else
        throw GeneralException("m_imgOut is NULL");
}          

/******************************************************************************/

ProjImageOutPiece SlaveProjector::projectPiece()
{
    if ( setupOutput() ) 
        return m_projInterface->projectPiece();
    else
        throw GeneralException("m_imgOut is NULL");
}


/******************************************************************************/

void SlaveProjector::project()
{
    if ( setupOutput() ) 
    {
        // get scanline data
        m_projInterface->project();
    } else
        throw GeneralException("m_imgOut is NULL");
    return;
}

/******************************************************************************/

void SlaveProjector::exportToSocket( ClientSocket & client ) const
{
    PROJECTORTYPE ty = SLAVEPROJ; /// from Globals.h
    unsigned int i = static_cast<int>(ty); 
    // sync our immediate data members
    client.appendToBuffer(&i, sizeof(i));
    
    client.appendToBuffer( &m_scanlineRange.first,
                           sizeof(m_scanlineRange.first));
    
    client.appendToBuffer( &m_scanlineRange.second,
                           sizeof(m_scanlineRange.second));
    
    client.sendFromBuffer();

    // sync interface members
    m_projInterface->exportToSocket(client); 

    return;
}

/******************************************************************************/

SlaveProjector SlaveProjector::createFromSocket( ClientSocket & client )
{
    PROJECTORTYPE ty = UNKNOWN;
    std::pair<long unsigned int, long unsigned int> range(0,0);
    ProjectorInterface * interface = NULL;
    unsigned int i = 0;
    // sync our immediate data members
    client.receive(&i, sizeof(i));
    ty = static_cast<PROJECTORTYPE>(i);
    
    if ( ty != SLAVEPROJ ) 
    {
        throw 
        GeneralException("SlaveProjector cannot create different projector!");
    }
    
    client.receive(&range.first,sizeof(range.first));
    client.receive(&range.second, sizeof(range.second));
   
    // sync interface members
    interface  = m_projFactory.makeProjector(client);

    if ( interface == NULL )
        throw GeneralException("Creation of projector failed.");
    
    return SlaveProjector(*interface, range );
}

/******************************************************************************/

} // namespace

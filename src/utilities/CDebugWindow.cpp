/***************************************************************************
                          CDebugWindow.cpp  -  description
                             -------------------
    begin                : Sun Feb 05 2012
    copyright            : (C) 2012 by Alexander Theel
    email                : alex.theel@gmx.net
 ***************************************************************************/

/***************************************************************************
 *                                                                         *
 *   This program is free software; you can redistribute it and/or modify  *
 *   it under the terms of the GNU General Public License as published by  *
 *   the Free Software Foundation; either version 2 of the License, or     *
 *   (at your option) any later version.                                   *
 *                                                                         *
 ***************************************************************************/


#include "CDebugWindow.h"
#include "../version.h"

// -------------------------------------------------------------------------------
CDebugWindow::CDebugWindow(QWidget *parent)
// -------------------------------------------------------------------------------
 : QWidget(parent)
{
   #ifdef USE_DEBUG_WINDOW
      ui.setupUi( this );
      show();
   #endif
}


// -------------------------------------------------------------------------------
CDebugWindow& CDebugWindow::getInstance()
// -------------------------------------------------------------------------------
{
   static CDebugWindow instance;
   return instance;
}



// -------------------------------------------------------------------------------
void CDebugWindow::printDebugMessage( const QString& sDebugText, const eDebugLevel& eLevel /* =DEBUG_INFO */ )
// -------------------------------------------------------------------------------
{
   if ( eLevel < CURRENT_DEBUG_LEVEL )
      return;

   if ( !ui.mpTextEdit )
      return;

   // chose a color for the debug output depending on the level
   QString sColor;
   if ( DEBUG_TRACE == eLevel )
      sColor = "<font color=#b0c4de>";
   else if ( DEBUG_WARNING == eLevel )
      sColor = "<font color=#FF7F24>";
   else if ( DEBUG_ERROR == eLevel )
      sColor = "<font color=#FF0000>";

   ui.mpTextEdit->append( sColor + sDebugText );
}

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

#ifndef CDEBUGWINDOW_H
#define CDEBUGWINDOW_H


#include "../version.h"
#ifdef USE_DEBUG_WINDOW
   #define  debugTrace(x) CDebugWindow::getInstance().printDebugMessage(x, DEBUG_TRACE )
   #define  debug(x)      CDebugWindow::getInstance().printDebugMessage(x)
   #define  debugWarn(x)  CDebugWindow::getInstance().printDebugMessage(x, DEBUG_WARNING )
   #define  debugErr(x)   CDebugWindow::getInstance().printDebugMessage(x, DEBUG_ERROR )
#else
   // empty definition of 'debug(x)', etc.
   #define  debugTrace(x) ;
   #define  debug(x) ;
   #define  debugWarn(x) ;
   #define  debugErr(x) ;
#endif


#include <QWidget>
#include "ui_IDebugWindow.h"

enum eDebugLevel {
  DEBUG_TRACE,
  DEBUG_INFO,
  DEBUG_WARNING,
  DEBUG_ERROR
};

#define CURRENT_DEBUG_LEVEL DEBUG_TRACE


class CDebugWindow : public QWidget
{
    Q_OBJECT
public:

   static CDebugWindow&    getInstance();
   void                    printDebugMessage( const QString& sDebugText, const eDebugLevel& eLevel = DEBUG_INFO );


private:
   CDebugWindow( QWidget *parent = 0 );

   Ui::DebugWindow ui;

};

#endif // CDEBUGWINDOW_H

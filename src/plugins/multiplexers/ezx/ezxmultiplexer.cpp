/****************************************************************************
**
** Copyright (C) 2000-2008 TROLLTECH ASA. All rights reserved.
**
** This file is part of the Opensource Edition of the Qtopia Toolkit.
**
** This software is licensed under the terms of the GNU General Public
** License (GPL) version 2.
**
** See http://www.trolltech.com/gpl/ for GPL licensing information.
**
** Contact info@trolltech.com if any conditions of this licensing are
** not clear to you.
**
**
**
** This file is provided AS IS with NO WARRANTY OF ANY KIND, INCLUDING THE
** WARRANTY OF DESIGN, MERCHANTABILITY AND FITNESS FOR A PARTICULAR PURPOSE.
**
****************************************************************************/

#include "ezxmultiplexer.h"
#include "QMultiPortMultiplexer"
#include "QSerialPort"

#include "qdatetime.h"

// dummy multyplexer for tapi bridge

QTOPIA_EXPORT_PLUGIN( EZXMultiplexerPlugin )


EZXMultiplexerPlugin::EZXMultiplexerPlugin( QObject* parent )
    : QSerialIODeviceMultiplexerPlugin( parent )
{
}

EZXMultiplexerPlugin::~EZXMultiplexerPlugin()
{
}


bool EZXMultiplexerPlugin::detect( QSerialIODevice *device )
{
    return true;
}

QSerialIODeviceMultiplexer *EZXMultiplexerPlugin::create
        ( QSerialIODevice *device )
{
//    return new QNullSerialIODeviceMultiplexer( device );

        // in the custom.h file as QTOPIA_PHONE_DEVICE and then passed
        // down to us in the "device" parameter.
        QMultiPortMultiplexer *mux = new QMultiPortMultiplexer( device );

        // Add the secondary channel.
        QSerialPort *secondary = QSerialPort::create( "/dev/mux1" );
        mux->addChannel( "secondary", secondary );

        // FIXME use QList
        // open all ports to pass handshake
        QSerialPort *mux2 = QSerialPort::create( "/dev/mux2" );
        mux->addChannel( "mux2", mux2 );

        QSerialPort *mux3 = QSerialPort::create( "/dev/mux3" );
        mux->addChannel( "mux3", mux3 );

        QSerialPort *mux4 = QSerialPort::create( "/dev/mux4" );
        mux->addChannel( "mux4", mux4 );

        QSerialPort *mux5 = QSerialPort::create( "/dev/mux5" );
        mux->addChannel( "mux5", mux5 );

        QSerialPort *mux6 = QSerialPort::create( "/dev/mux6" );
        mux->addChannel( "mux6", mux6 );

        QSerialPort *mux7 = QSerialPort::create( "/dev/mux7" );
        mux->addChannel( "mux7", mux7 );

        QSerialPort *mux8 = QSerialPort::create( "/dev/mux8" );
        mux->addChannel( "mux8", mux8 );

        // power on bp
        mux->chat(device,"AT+EPOM=1,0");

        // set bp time from ap
        QDateTime now = QDateTime::currentDateTime();

        mux->chat(device,now.toString("AT+CCLK=\"%yy/%MM/%dd,%hh:%mm:%ss\"") );

        // ??
        mux->chat(device,"AT+EAPF=12,1,0" );
        mux->chat(device,"AT");

        // close unused lines
        mux2->close();
        mux3->close();
        mux4->close();

        return mux;
}

/*
   Copyright (C) 2005 Bram Schoenmakers <bramschoenmakers@kde.nl>
   Copyright (C) 2010 Tom Albers <toma@kde.org>
   Copyright (C) 2010 Juan Luis Baptiste <juan.baptiste@gmail.com>

   This program is free software; you can redistribute it and/or
   modify it under the terms of the GNU General Public
   License as published by the Free Software Foundation; either
   version 2 of the License, or (at your option) any later version.

   This program is distributed in the hope that it will be useful,
   but WITHOUT ANY WARRANTY; without even the implied warranty of
   MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the GNU
   General Public License for more details.

   You should have received a copy of the GNU General Public License
   along with this program; if not, write to the Free Software
   Foundation, Inc., 51 Franklin Street, Fifth Floor, Boston, MA 02110-1301, USA.
*/

#ifndef RSIRELAXPOPUP_H
#define RSIRELAXPOPUP_H

#include <passivepopup.h>
#include <QLabel>

class QLabel;
class QPushButton;
class QProgressBar;

/**
 * @class RSIRelaxPopup
 * This is a KPassivePopup which some extra features.
 * It's shown when the user should relax for a couple of seconds.
 * @author Bram Schoenmakers <bramschoenmakers@kde.nl>
 */
class RSIRelaxPopup : public QObject
{
    Q_OBJECT
public:
    /** Constructor */
    explicit RSIRelaxPopup( QWidget *parent );
    /** Destructor */
    ~RSIRelaxPopup();

public slots:
    /**
      Shows this popup with the message that the user should rest @p n seconds.
      @param n Amount of seconds to relax
      @param bigBreakNext If true, it shows a warning that the next break will be
      a big break.
    */
    void relax( int n, bool bigBreakNext );

    /**
      Reread config
    */
    void slotReadConfig();

    /** Hides the skip button **/
    void setSkipButtonHidden( bool );

    /** Hides the lock button **/
    void setLockButtonHidden( bool );
    
    /** Hides the postpone break button **/
    void setPostponeButtonHidden( bool );

    /** Hides/Shows the popup */
    void setSuspended( bool suspended );
    
signals:
    /** Ask the main widget to lock down the desktop. */
    void lock();

    /** Ask the main widget to skip the break. */
    void skip();
    
    /** Ask the main widget to postpone the break. */
    void postpone();

protected:
    /**
      Changes the background color for 0.5 second. The background is restored
      with unflash()
    */
    void flash();

protected slots:
    /** Restores background color after a flash() */
    void unflash();

private:
    void readSettings();
    bool    m_useFlash;
    bool    m_wasShown;
    PassivePopup* m_popup;
    QLabel *m_message;
    QProgressBar *m_progress;
    QPushButton *m_lockbutton;
    QPushButton *m_skipbutton;
    QPushButton* m_postponebutton;
};

#endif /* RSIRELAXPOPUP_H */

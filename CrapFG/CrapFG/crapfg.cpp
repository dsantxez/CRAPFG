#include "crapfg.h"
#include "mysplashscreen.h"

#include <qthread.h>


CrapFG::CrapFG(QWidget *parent)
	: QMainWindow(parent)
{
	ui.setupUi(this);
}

CrapFG::~CrapFG()
{

}

void CrapFG::showWindow(bool result)
{
	if (result == false)
		exit(EXIT_FAILURE);

	setWindowState(Qt::WindowFullScreen);
	show();
}

bool CrapFG::startEverything()
{
	if (startInitialConf() == false)
	{
		emit messageChanged(tr("Could not initialize basic configuration"));
		//m_screen->showMessage(tr("Could not initialize basic configuration"));
		QThread::currentThread()->sleep(10);
		emit initializationFinished(false);
		return false;
	}
	emit messageChanged(tr("Initializing initial Menu..."));
	//qApp->processEvents();
	if (startInitialMenu() == false)
	{
		emit messageChanged(tr("Could not initialize initial Menu"));
		QThread::currentThread()->sleep(10);
		emit initializationFinished(false);
		return false;
	}
	emit messageChanged(tr("Initializing Stage Data..."));
	//qApp->processEvents();
	if (startStageData() == false)
	{
		emit messageChanged(tr("Could not initialize Stage Data"));
		QThread::currentThread()->sleep(10);
		emit initializationFinished(false);
		return false;
	}
	emit messageChanged(tr("Initializing Player Data..."));
	//qApp->processEvents();
	if (startPlayerData() == false)
	{
		emit messageChanged(tr("Could not initialize Player Data"));
		QThread::currentThread()->sleep(10);
		emit initializationFinished(false);
		return false;
	}
	emit messageChanged(tr("Initializing Character Data..."));
	//qApp->processEvents();
	if (startCharacterData() == false)
	{
		emit messageChanged(tr("Could not initialize Character Data"));
		QThread::currentThread()->sleep(10);
		emit initializationFinished(false);
		return false;
	}
	emit messageChanged(tr("Initializing Game Mode Data..."));
	//qApp->processEvents();
	if (startGameModeData() == false)
	{
		emit messageChanged(tr("Could not initialize Game Mode Data"));
		QThread::currentThread()->sleep(10);
		emit initializationFinished(false);
		return false;
	}
	emit messageChanged(tr("Initializing Video Data..."));
	//qApp->processEvents();
	if (startVideoData() == false)
	{
		emit messageChanged(tr("Could not initialize Vide Data"));
		QThread::currentThread()->sleep(10);
		emit initializationFinished(false);
		return false;
	}
	emit messageChanged(tr("Initializing Bonus Stage Data..."));
	//qApp->processEvents();
	if (startBonusStageData() == false)
	{
		emit messageChanged(tr("Could not initialize Bonus Stage Data"));
		QThread::currentThread()->sleep(10);
		emit initializationFinished(false);
		return false;
	}

	emit initializationFinished(true);
	return true;
}



bool CrapFG::startInitialConf()
{
	QThread::currentThread()->sleep(1);
	return true;
}

bool CrapFG::startInitialMenu()
{
	QThread::currentThread()->sleep(1);
	return true;
}

bool CrapFG::startStageData()
{
	QThread::currentThread()->sleep(1);
	return true;
}

bool CrapFG::startPlayerData()
{
	QThread::currentThread()->sleep(1);
	return true;
}

bool CrapFG::startCharacterData()
{
	QThread::currentThread()->sleep(1);
	return true;
}

bool CrapFG::startGameModeData()
{
	QThread::currentThread()->sleep(1);
	return true;
}

bool CrapFG::startVideoData()
{
	QThread::currentThread()->sleep(1);
	return true;
}

bool CrapFG::startBonusStageData()
{
	QThread::currentThread()->sleep(1);
	return true;
}

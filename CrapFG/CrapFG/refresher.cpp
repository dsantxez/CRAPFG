#include "refresher.h"
#include <qapplication.h>

Refresher::Refresher(QObject *parent)
	: QThread(parent)
{
	m_stopped = false;
}

Refresher::~Refresher()
{

}

void Refresher::setStart()
{
	m_stopped = true;
}

void Refresher::setStop()
{
	m_stopped = false;
}

void Refresher::run()
{
	while (m_stopped == false)
	{
		QThread::currentThread()->msleep(33);
		QCoreApplication::processEvents();
	}
}

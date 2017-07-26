#include "crapfg.h"
#include "mysplashscreen.h"
#include <QtWidgets/QApplication>
#include <QtConcurrent/qtconcurrentrun.h>

int main(int argc, char *argv[])
{
	QApplication a(argc, argv);
	//QString pic_path(QApplication::applicationDirPath() + "/Resources/SplashScreen/giphy.gif");
	MySplashScreen initScreen;
	initScreen.show();
	a.processEvents();
	CrapFG w;
	a.connect(&w, SIGNAL(initializationFinished(bool)), &w, SLOT(showWindow(bool)));
	a.connect(&w, SIGNAL(initializationFinished(bool)), &initScreen, SLOT(close()));
	a.connect(&w, SIGNAL(messageChanged(const QString&)), &initScreen, SLOT(showMessageInScreen(const QString&)));
	QtConcurrent::run(&w, &CrapFG::startEverything);
	return a.exec();
}

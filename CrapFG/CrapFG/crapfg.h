#ifndef CRAPFG_H
#define CRAPFG_H

#include <QtWidgets/QMainWindow>
#include "ui_crapfg.h"

class MySplashScreen;

class CrapFG : public QMainWindow
{
	Q_OBJECT

public:
	CrapFG(QWidget *parent = 0);
	~CrapFG();
Q_SIGNALS:
	void initializationFinished(bool withError);
	void messageChanged(const QString& text);
public slots:
	void showWindow(bool result);
public:
	bool startEverything();
protected:
	bool startInitialConf();
	bool startInitialMenu();
	bool startStageData();
	bool startPlayerData();
	bool startCharacterData();
	bool startGameModeData();
	bool startVideoData();
	bool startBonusStageData();

private:
	Ui::CrapFGClass ui;
	MySplashScreen *m_screen;
};

#endif // CRAPFG_H

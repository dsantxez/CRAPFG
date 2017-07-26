#ifndef MYSPLASHSCREEN_H
#define MYSPLASHSCREEN_H

#include <QWidget>
#include "ui_mysplashscreen.h"

#include <qsplashscreen.h>
#include <qmovie.h>
#include <qstring.h>

class MySplashScreen : public QWidget
{
	Q_OBJECT

public:
	explicit MySplashScreen(QWidget *parent = 0);
public slots:
	void showMessageInScreen(const QString& message);
protected:
	//void paintEvent(QPaintEvent* event);

signals:
	void frameChanged();

	private slots:
	void convertFrameChanged(int)
	{
		repaint();
	}

private:
	Ui::MySplashScreen ui;
	QMovie m_movie;
	QString m_message;
};

#endif // MYSPLASHSCREEN_H

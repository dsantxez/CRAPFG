#include "mysplashscreen.h"
#include <qpainter.h>
#include <qmovie.h>
#include <QPaintEvent>
#include <qpixmap.h>
#include <qtimer.h>

#include "pugixml.hpp"

MySplashScreen::MySplashScreen(QWidget *parent)
	: QWidget(parent)
{
	ui.setupUi(this);

	pugi::xml_document doc;
	QString path = QApplication::applicationDirPath() + "/Resources/SplashScreen/config.cfg";
	pugi::xml_parse_result result = doc.load_file(path.toStdString().c_str());

	if (!result)
		return;

	pugi::xml_node initNode = doc.child("SplashScreen");
	QString imageFileName(initNode.child("image").child_value());
	imageFileName = QApplication::applicationDirPath() + "/Resources/SplashScreen/" + imageFileName;
	m_movie.setFileName(imageFileName);
	m_movie.start();

	pugi::xml_node textNode = initNode.child("text");
	QString styleText(textNode.child("style").child_value());
	ui.loadingText->setStyleSheet(styleText);

	QString sizeText(textNode.child("size").child_value());
	int sizePercentage = sizeText.toInt();
	float sizePerc = ((float)sizePercentage) / 100.0;
	QString positionText(textNode.child("position").child_value());
	int positionPercentage = positionText.toInt();
	float positionPerc = ((float)positionPercentage) / 100.0;
	QSize size(m_movie.frameRect().width(), m_movie.frameRect().height());
	this->setFixedSize(size);
	ui.movieLabel->setMovie(&m_movie);
	ui.movieLabel->setFixedSize(size);
	ui.loadingText->setFixedSize(size);
	ui.movieLabel->setGeometry(0, 0, size.width(), size.height());
	int height = size.height() *sizePerc;
	int positionY = size.height()*positionPerc;
	ui.loadingText->setGeometry(0, positionY, size.width(), height);
	ui.loadingText->setFixedHeight(height);

	pugi::xml_node alignNode = textNode.child("alignment");
	QString verticalAlign(alignNode.child("vertical").child_value());
	QString horizontalAlign(alignNode.child("horizontal").child_value());

	if (verticalAlign == "top")
	{
		ui.loadingText->setAlignment(Qt::AlignTop);
	}
	else if (verticalAlign == "middle")
	{
		ui.loadingText->setAlignment(Qt::AlignVCenter);
	}
	else if (verticalAlign == "bottom")
	{
		ui.loadingText->setAlignment(Qt::AlignBottom);
	}
	if (horizontalAlign == "left")
	{
		ui.loadingText->setAlignment(Qt::AlignLeft);
	}
	else if (horizontalAlign == "middle")
	{
		ui.loadingText->setAlignment(Qt::AlignHCenter);
	}
	else if (horizontalAlign == "right")
	{
		ui.loadingText->setAlignment(Qt::AlignRight);
	}

	setWindowFlags(Qt::CustomizeWindowHint);
	setWindowFlags(Qt::FramelessWindowHint);
	//connect(&(movie), SIGNAL(frameChanged(int)), this, SLOT(convertFrameChanged(int)));
}

void MySplashScreen::showMessageInScreen(const QString & message)
{
	ui.loadingText->setText(message);
}

/*void MySplashScreen::paintEvent(QPaintEvent* event)
{
	QPixmap frame = movie.currentPixmap();
	QRect rect = frame.rect();
	rect.moveCenter(this->rect().center());
	if (rect.intersects(event->rect()))
	{
		QPainter painter(this);
		painter.drawPixmap(rect.left(), rect.top(), frame);
	}
}*/

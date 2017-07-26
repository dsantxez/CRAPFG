#ifndef REFRESHER_H
#define REFRESHER_H

#include <QThread>

class Refresher : public QThread
{
	Q_OBJECT

public:
	Refresher(QObject *parent);
	~Refresher();
public:
	void setStart();
	void setStop();
protected:
	virtual void run()override;

private:
	bool m_stopped;
};

#endif // REFRESHER_H

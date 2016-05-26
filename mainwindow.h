#ifndef MAINWINDOW_H
#define MAINWINDOW_H

#include <QMainWindow>
#include <QtWidgets>
#include <QtCore>
#include "com/global.h"
#include "com/network.h"
#include "com/networkcommunication.h"
#include "config.h"
#include "inputhandle.h"
#include "outputhandle.h"

class MainWindow : public QMainWindow
{
	Q_OBJECT

	typedef struct{
		int port;
		QString host;
	}NetworkSettings;

	QTextEdit *output;
	QLineEdit *input;
	QPushButton *send;
	int timerId;
	Network *net;
	NetworkCommunication *netC;
	InputHandle *inputHandle;
	OutputHandle *outputHandle;

	Config *config;

	NetworkSettings ns;
private:
	void keyPressEvent(QKeyEvent *);
	void closeEvent(QCloseEvent *);
	void timerEvent(QTimerEvent *);

public:
	MainWindow(QWidget *parent = 0);
	~MainWindow();
private:
	void startSystem();
private slots:
	void sendClicked();
	void enableInputPanel();
	void disableInputPanel();

public slots:
	void showStdOut(QString msg);
};

#endif // MAINWINDOW_H

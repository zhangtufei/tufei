#ifndef MYCLASS_H
#define MYCLASS_H

#include <QtWidgets/QDialog>
#include "ui_myclass.h"
#include <QVector>
#include <QString>
#include <QKeyEvent>
class MyClass : public QDialog
{
	Q_OBJECT

public:
	MyClass(QWidget *parent = 0);
	~MyClass();

private:
	Ui::MyClassClass ui;
	void initbeforestart();
	void initvector();
	void initbegin();
	void setlabel();
	void randpoint();
	void upkey();
	void downkey();
	void leftkey();
	void rightkey();
	bool domovey(int cur,int step);
	bool domovex(int cur, int step);
	bool noway();
	QVector<QLabel *> vec_label;
	QVector<QPalette> vec_palette;
	QVector<QFont> vec_font;
	QVector<QString> vec_string;
	int maxnum;
	int counts;
	int arr[16];
	int score;
	bool lose;
	bool Isbegin;
	bool up;
	bool left;
	bool right;
	bool down;
	bool ismove = false;
	
protected:
	void keyPressEvent(QKeyEvent *event);
	void keyReleaseEvent(QKeyEvent *event);
};

#endif // MYCLASS_H

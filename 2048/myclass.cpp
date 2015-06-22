#include "myclass.h"
#include <QPushButton>
#include <QTime>
#include <qglobal.h>
#include <math.h>
MyClass::MyClass(QWidget *parent)
	: QDialog(parent)
{
	ui.setupUi(this);
	initbeforestart();
	QObject::connect(ui.beginButton, &QPushButton::clicked, this, &MyClass::initbegin);
}
MyClass::~MyClass()
{

}
void MyClass::initbeforestart()
{
	//设置16个label的背景颜色
	initvector();
	memset(arr, 0, sizeof(arr));
	setlabel();
	//随机数引擎
	qsrand(QTime(0, 0, 0).secsTo(QTime::currentTime()));
	Isbegin = false;
}
void MyClass::setlabel()
{
	for (int i = 0; i < 16;++i)
	{
		vec_label[i]->setAutoFillBackground(true);
		vec_label[i]->setPalette(vec_palette[arr[i]]);
		vec_label[i]->setFont(vec_font[arr[i]]);
		vec_label[i]->setText(vec_string[arr[i]]);
	}
}
void MyClass::initvector()
{
	vec_label.push_back(ui.label1);
	vec_label.push_back(ui.label2);
	vec_label.push_back(ui.label3);
	vec_label.push_back(ui.label4);
	vec_label.push_back(ui.label5);
	vec_label.push_back(ui.label6);
	vec_label.push_back(ui.label7);
	vec_label.push_back(ui.label8);
	vec_label.push_back(ui.label9);
	vec_label.push_back(ui.label10);
	vec_label.push_back(ui.label11);
	vec_label.push_back(ui.label12);
	vec_label.push_back(ui.label13);
	vec_label.push_back(ui.label14);
	vec_label.push_back(ui.label15);
	vec_label.push_back(ui.label16);
	//0
	QFont font;//字体
	QBrush brush(QColor(0, 0, 0, 255));//背景颜色
	QBrush brush1(QColor(0, 0, 0, 255));//字体颜色
	QPalette palette;
	font.setPointSize(21);
	font.setBold(true);
	font.setWeight(75);
	brush.setStyle(Qt::SolidPattern);
	palette.setBrush(QPalette::Active, QPalette::Window, brush);
	palette.setBrush(QPalette::Inactive, QPalette::Window, brush);
	vec_palette.push_back(palette);
	vec_font.push_back(font);
	vec_string.push_back("");
	//2
	brush.setColor(QColor(238,228 , 218, 255));
	palette.setBrush(QPalette::Active, QPalette::Window, brush);
	palette.setBrush(QPalette::Inactive, QPalette::Window, brush);
	palette.setBrush(QPalette::Active, QPalette::WindowText, brush1);
	palette.setBrush(QPalette::Inactive, QPalette::WindowText, brush1);
	vec_palette.push_back(palette);
	vec_font.push_back(font);
	vec_string.push_back("2");
	//vec_string.push_back(QString::fromLocal8Bit(""));
	//4
	brush.setColor(QColor(236,224,202,255));
	palette.setBrush(QPalette::Active, QPalette::Window, brush);
	palette.setBrush(QPalette::Inactive, QPalette::Window, brush);
	vec_palette.push_back(palette);
	vec_font.push_back(font);
	vec_string.push_back("4");
	//vec_string.push_back(QString::fromLocal8Bit("少女"));
	//8
	brush.setColor(QColor(242, 177, 121,255));
	brush1.setColor(QColor(255, 255, 255, 255));
	palette.setBrush(QPalette::Active, QPalette::Window, brush);
	palette.setBrush(QPalette::Inactive, QPalette::Window, brush);
	palette.setBrush(QPalette::Active, QPalette::WindowText, brush1);
	palette.setBrush(QPalette::Inactive, QPalette::WindowText, brush1);
	vec_palette.push_back(palette);
	vec_font.push_back(font);
	vec_string.push_back("8");
	//vec_string.push_back(QString::fromLocal8Bit("学妹"));
	//16
	font.setPointSize(19);
	brush.setColor(QColor(245, 149, 99, 255));
	palette.setBrush(QPalette::Active, QPalette::Window, brush);
	palette.setBrush(QPalette::Inactive, QPalette::Window, brush);
	vec_palette.push_back(palette);
	vec_font.push_back(font);
	vec_string.push_back("16");
	//vec_string.push_back(QString::fromLocal8Bit("学姐"));
	//32
	brush.setColor(QColor(245, 124, 95, 255));
	palette.setBrush(QPalette::Active, QPalette::Window, brush);
	palette.setBrush(QPalette::Inactive, QPalette::Window, brush);
	vec_palette.push_back(palette);
	vec_font.push_back(font);
	vec_string.push_back("32");
	//vec_string.push_back(QString::fromLocal8Bit("御姐"));
	//64
	brush.setColor(QColor(246, 93, 59, 255));
	palette.setBrush(QPalette::Active, QPalette::Window, brush);
	palette.setBrush(QPalette::Inactive, QPalette::Window, brush);
	vec_palette.push_back(palette);
	vec_font.push_back(font);
	vec_string.push_back("64");
	//vec_string.push_back(QString::fromLocal8Bit("学士"));
	//128
	font.setPointSize(17);
	brush.setColor(QColor(237, 206, 113, 255));
	palette.setBrush(QPalette::Active, QPalette::Window, brush);
	palette.setBrush(QPalette::Inactive, QPalette::Window, brush);
	vec_palette.push_back(palette);
	vec_font.push_back(font);
	vec_string.push_back("128");
	//vec_string.push_back(QString::fromLocal8Bit("硕士"));
	//256
	brush.setColor(QColor(237, 204, 141, 255));
	palette.setBrush(QPalette::Active, QPalette::Window, brush);
	palette.setBrush(QPalette::Inactive, QPalette::Window, brush);
	vec_palette.push_back(palette);
	vec_font.push_back(font);
	vec_string.push_back("256");
	//vec_string.push_back(QString::fromLocal8Bit("博士"));
	
	//512
	brush.setColor(QColor(183, 236, 235, 255));
	//font.setPointSize(13);
	palette.setBrush(QPalette::Active, QPalette::Window, brush);
	palette.setBrush(QPalette::Inactive, QPalette::Window, brush);
	vec_palette.push_back(palette);
	vec_font.push_back(font);
	vec_string.push_back("512");
	//vec_string.push_back(QString::fromLocal8Bit("圣斗士"));
	//1024
	font.setPointSize(15);
	brush.setColor(QColor(171, 171, 236, 255));
	palette.setBrush(QPalette::Active, QPalette::Window, brush);
	palette.setBrush(QPalette::Inactive, QPalette::Window, brush);
	vec_palette.push_back(palette);
	vec_font.push_back(font);
	vec_string.push_back("1024");
	//vec_string.push_back(QString::fromLocal8Bit("女王"));
	//2048
	brush.setColor(QColor(237, 197, 0, 255));
	palette.setBrush(QPalette::Active, QPalette::Window, brush);
	palette.setBrush(QPalette::Inactive, QPalette::Window, brush);
	vec_palette.push_back(palette);
	vec_font.push_back(font);
	vec_string.push_back("2048");
	//vec_string.push_back(QString::fromLocal8Bit("人妻"));
}
void MyClass::initbegin()
{
	if (!Isbegin)//开始游戏
	{//设置按钮
		QPalette palette1;
		QBrush brush1(QColor(214, 200, 243, 255));
		brush1.setStyle(Qt::SolidPattern);
		palette1.setBrush(QPalette::Active, QPalette::Button, brush1);
		palette1.setBrush(QPalette::Inactive, QPalette::Button, brush1);
		ui.beginButton->setPalette(palette1);
		ui.beginButton->setFlat(true);
		ui.beginButton->setText(QString::fromLocal8Bit("结束游戏"));
		ui.lineEdit_score->setText("");
		//初始化清零
		//memset(arr, 0, sizeof(arr));
		ismove = false;
		score = 0;
		maxnum = 0;
		ui.lineEdit_score->setText("0");
		Isbegin = true;
		//产生随机坐标
		randpoint();
		randpoint();
		//非零的坐标数
		counts = 2;
		ui.label_display->setText(QString::number(pow(2,maxnum)));

	}
	else//结束游戏
	{
		//设置按钮
		QPalette palette1;
		QBrush brush1(QColor(255, 85, 0, 255));
		brush1.setStyle(Qt::SolidPattern);
		palette1.setBrush(QPalette::Active, QPalette::Button, brush1);
		palette1.setBrush(QPalette::Inactive, QPalette::Button, brush1);
		ui.beginButton->setPalette(palette1);
		ui.beginButton->setFlat(true);
		ui.beginButton->setText(QString::fromLocal8Bit("开始游戏"));
		ui.lineEdit_score->setText("");
		Isbegin = false;
		counts = 0;
		memset(arr, 0, sizeof(arr));
		if (!lose)
			setlabel();
	}
	up = down = left = right = false;
}
void MyClass::randpoint()
{
	int x1, y1, num1;
	x1 = qrand() % 4;
	y1 = qrand() % 4;
	while (arr[x1 * 4 + y1])
	{
		x1 = qrand() % 4;
		y1 = qrand() % 4;
	}
	num1 = qrand() % 10;
	arr[x1 * 4 + y1] = num1 <= 7 ? 1 : 2;
	if (maxnum < arr[x1*4+y1])
		maxnum = arr[x1 * 4 + y1];
	setlabel();
}
void MyClass::keyPressEvent(QKeyEvent *event)
{
	if (!Isbegin)
		return;
	switch (event->key())
	{
	case Qt::Key_Up:
		if (!event->isAutoRepeat())
			up = true;
		break;
	case Qt::Key_Down:
		if (!event->isAutoRepeat())
			down = true;
		break;
	case Qt::Key_Left:
		if (!event->isAutoRepeat())
			left = true;
		break;
	case Qt::Key_Right:
		if (!event->isAutoRepeat())
			right = true;
		break;
	}
}
void MyClass::keyReleaseEvent(QKeyEvent *event)
{
	if (!Isbegin)
		return;
	switch (event->key())
	{
	case Qt::Key_Up:
			upkey();
		break;
	case Qt::Key_Down:
		if (!event->isAutoRepeat())
			downkey();
		break;
	case Qt::Key_Left:
		if (!event->isAutoRepeat())
			leftkey();
		break;
	case Qt::Key_Right:
		if (!event->isAutoRepeat())
			rightkey();
		break;
	}
	if (ismove)
	{
		ui.lineEdit_score->setText(QString::number(score));
		ui.label_display->setText(QString::number(pow(2,maxnum)));
		randpoint();
		ismove = false;
		counts += 1;
		if (counts == 16 && noway())
		{
			ui.label_display->setText(tr("lose"));
			setlabel();
			lose = true;
			initbegin();
		}	
	}
}
void MyClass::upkey()
{
	ismove = false;
	for (int i = 0; i <= 2; ++i)
	{
		for (int j = 0; j <= 3; ++j)
		{
			bool ft=domovey(i*4+j, 4);
			if (!ismove)
				ismove = ft;
			int curline = i * 4 + j;
			int nextline = (i + 1) * 4 + j;
			if (arr[curline] == 0)
				continue;
			if (arr[curline] == arr[nextline])
			{
				arr[curline] += 1;
				arr[nextline] = 0;
				counts -= 1;
				ismove = true;
				//domove(nextline, 4);
				score += pow(2, arr[curline]-1);
				if (arr[curline] > maxnum)
					maxnum = arr[curline];
			}
		}
	}
	if(ismove)
		setlabel();
	//return ismove;
}
void MyClass::downkey()
{
	ismove = false;
	for (int i = 3; i >= 1; --i)
	{
		for (int j = 0; j <= 3; ++j)
		{
			bool ft = domovey( i*4+ j, -4);
			if (!ismove)
				ismove = ft;
			int curline = i * 4 + j;
			int nextline = (i - 1) * 4 + j;
			if (arr[curline] == 0)
				continue;
			if (arr[curline] == arr[nextline])
			{
				arr[curline] += 1;
				arr[nextline] = 0;
				counts -= 1;
				ismove = true;
				//domove(nextline, 4);
				score += pow(2, arr[curline]-1);
				if (arr[curline] > maxnum)
					maxnum = arr[curline];
			}
		}
	}
	if (ismove)
		setlabel();
}
void MyClass::leftkey()
{
	ismove = false;
	for (int i = 0; i <= 2; ++i)
	{
		for (int j = 0; j <= 3; ++j)
		{
			bool ft = domovex(i + j*4, 1);
			if (!ismove)
				ismove = ft;
			int curline = i + j*4;
			int nextline = curline + 1;
			if (arr[curline] == 0)
				continue;
			if (arr[curline] == arr[nextline])
			{
				arr[curline] += 1;
				arr[nextline] = 0;
				counts -= 1;
				ismove = true;
				//domove(nextline, 4);
				score += pow(2, arr[curline]-1);
				if (arr[curline] > maxnum)
					maxnum = arr[curline];
			}
		}
	}
	if (ismove)
		setlabel();
	//return ismove;
}
void MyClass::rightkey()
{
	ismove = false;
	for (int i = 3; i >= 1;--i)
	{
		for (int j = 0; j <= 3; ++j)
		{
			bool ft = domovex(i + j * 4, -1);
			if (!ismove)
				ismove = ft;
			int curline = i + j * 4;
			int nextline = curline - 1;
			if (arr[curline] == 0)
				continue;
			if (arr[curline] == arr[nextline])
			{
				arr[curline] += 1;
				arr[nextline] = 0;
				counts -= 1;
				ismove = true;
				//domove(nextline, 4);
				score += pow(2, arr[curline]-1);
				if (arr[curline] > maxnum)
					maxnum = arr[curline];
			}
		}
	}
	if (ismove)
		setlabel();
	//return ismove;
}
//void MyClass::keyReleaseEvent(QKeyEvent *event)
//{
//
//}
bool MyClass::domovey(int cur, int step)
{
	bool flag = false;
	for (int i = cur; i < 16&&i>=0; i+=step)
	{
		if (arr[i])
			continue;
		for (int j = i+step; j < 16&&j>=0; j+=step)
		{
			if (arr[j] != 0)
			{
				flag = true;
				arr[i] = arr[j];
				arr[j] = 0;
				break;
			}
		}
	}
	return flag;
}
bool MyClass::domovex(int cur, int step)
{
	bool flag = false;
	int temp = (cur+step) / 4;
	for (int i = cur; i / 4 == temp&&i+step>=0&&i+step<16; i += step)
	{
		if (arr[i])
			continue;
		for (int j = i + step;j/4==temp&& j < 16&&j>=0; j += step)
		{
			if (arr[j] != 0)
			{
				flag = true;
				arr[i] = arr[j];
				arr[j] = 0;
				break;
			}
		}
	}
	return flag;
}
bool MyClass::noway()
{
	int dp[16];
	int dir[4] = { 4, -4, 1,-1 };
	memset(dp, 0, sizeof(dp));
	bool flag = true;
	for (int i = 0; i < 16&&flag; ++i)
	{
		dp[i] = 1;
		for (int j = 0; j < 4&&flag; ++j)
		{
			int next = i + dir[j];
			if (next >= 0 && next <= 15 && !dp[next])
			{
				if (arr[i] == arr[next])
					flag = false;
			}
		}
	}
	return flag;
}
#include "QSimZombie.h"
#include <QtWidgets/QApplication>

int main(int argc, char *argv[])
{
	QApplication a(argc, argv);
	QSimZombie w;
	w.resize(800, 600);
	w.showMaximized();
	return a.exec();
}

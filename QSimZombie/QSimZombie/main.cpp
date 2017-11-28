#include "QSimZombie.h"
#include <QtWidgets/QApplication>

int main(int argc, char *argv[])
{
	QApplication a(argc, argv);
	QSimZombie w;
	w.show();
	return a.exec();
}

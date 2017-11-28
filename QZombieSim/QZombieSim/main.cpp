#include "QZombieSim.h"
#include <QtWidgets/QApplication>

int main(int argc, char *argv[])
{
	QApplication a(argc, argv);
	QZombieSim w;
	w.show();
	return a.exec();
}

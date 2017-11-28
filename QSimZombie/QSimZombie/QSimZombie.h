#pragma once

#include <QtWidgets/QMainWindow>
#include "ui_QSimZombie.h"

class QSimZombie : public QMainWindow
{
	Q_OBJECT

public:
	QSimZombie(QWidget *parent = Q_NULLPTR);

private:
	Ui::QSimZombieClass ui;
};

#pragma once

#include <QtWidgets/QMainWindow>
#include "ui_QZombieSim.h"

class QZombieSim : public QMainWindow
{
	Q_OBJECT

public:
	QZombieSim(QWidget *parent = Q_NULLPTR);

private:
	Ui::QZombieSimClass ui;
};

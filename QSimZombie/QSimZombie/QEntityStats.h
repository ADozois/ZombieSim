#ifndef Q_ENTITY_STATS_H
#define Q_ENTITY_STATS_H
#include <QWidget>
#include <QLabel>
#include <QVBoxLayout>
#include <QFormLayout>
#include "QHumanoid.h"


class QEntityStats : public QWidget {

public:

	QEntityStats(QWidget* parent = nullptr);


	QFormLayout *mFormLayout;

	QLabel *mAge;

	QHumanoid *mSelectedHumanoid;

};


#endif //Q_ENTITY_STATS_H
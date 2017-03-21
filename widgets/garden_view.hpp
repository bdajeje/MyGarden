#ifndef GARDENVIEW_H
#define GARDENVIEW_H

#include <QWebEngineView>

class GardenView final : public QWebEngineView
{
	Q_OBJECT

	public:

		GardenView(QWidget* parent = Q_NULLPTR);

		void addPlantation(const QString& text);
};

#endif // GARDENVIEW_H

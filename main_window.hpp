#ifndef MAIN_WINDOW_HPP
#define MAIN_WINDOW_HPP

#include <QMainWindow>
#include <QPointer>
#include <QComboBox>

#include "widgets/plantation_dialog.hpp"
#include "widgets/garden_view.hpp"

class MainWindow final : public QMainWindow
{
	Q_OBJECT

	public:

		MainWindow(QWidget *parent = 0);

	protected:

	  void createMenu();
	  QAction* createQuitAction();
	  QAction* createAddPlantationAction();

	private slots:

	  void showCreatePlantationType();
	  void addNewPlantation();

	protected:

	  QPointer<PlantationDialog> _w_plantation_dialog;
	  QPointer<GardenView> _w_garden_view;
	  QPointer<QComboBox> _w_plantations_list;
};

#endif // MAIN_WINDOW_HPP

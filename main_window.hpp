#ifndef MAIN_WINDOW_HPP
#define MAIN_WINDOW_HPP

#include <QMainWindow>
#include <QPointer>

#include "widgets/plantation_dialog.hpp"

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

	protected:

	  QPointer<PlantationDialog> _w_plantation_dialog;
};

#endif // MAIN_WINDOW_HPP

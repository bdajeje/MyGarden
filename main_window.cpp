#include "main_window.hpp"

#include <QMenuBar>
#include <QVBoxLayout>
#include <QPushButton>

#include "utils/icons_manager.hpp"

MainWindow::MainWindow(QWidget *parent)
	: QMainWindow(parent)
{
	auto central_widget  = new QWidget(this);
	auto main_layout     = new QHBoxLayout();
	auto controls_layout = new QVBoxLayout();

	// Window icon
	const QIcon& icon = utils::IconsManager::get("icon.png");
	setWindowIcon( icon );

	_w_plantations_list = new QComboBox;
	//todo
	_w_plantations_list->addItem("Nani");
	_w_plantations_list->addItem("Nana");

	auto btn_add_plantation = new QPushButton(tr("Add"));
	_w_garden_view = new GardenView;

	controls_layout->addWidget(_w_plantations_list);
	controls_layout->addWidget(btn_add_plantation);
	main_layout->addLayout(controls_layout);
	main_layout->addWidget(_w_garden_view);

	// Menu
	createMenu();

	central_widget->setLayout(main_layout);
	setCentralWidget(central_widget);

	connect(btn_add_plantation, SIGNAL(released()), this, SLOT(addNewPlantation()));
}

void MainWindow::createMenu()
{
  // File
  auto menu_file = menuBar()->addMenu(tr("&File"));
	// Quit
	menu_file->addAction( createQuitAction() );

  // Edit
  auto edit_file = menuBar()->addMenu(tr("&Edit"));
   // Add new plantation
   edit_file->addAction( createAddPlantationAction() );
}

QAction* MainWindow::createQuitAction()
{
  auto action = new QAction(tr("&Quit"), this);
  action->setStatusTip(tr("Quit application"));
  action->setIcon(utils::IconsManager::get("quit.png"));
  connect(action, SIGNAL(triggered()), this, SLOT(close()));
  return action;
}

QAction* MainWindow::createAddPlantationAction()
{
  auto action = new QAction(tr("&Create Plantation Type"), this);
  action->setStatusTip(tr("Add a new plantation type"));
  action->setIcon(utils::IconsManager::get("quit.png"));
  connect(action, SIGNAL(triggered()), this, SLOT(showCreatePlantationType()));
  return action;
}

void MainWindow::showCreatePlantationType()
{
	if(!_w_plantation_dialog)
		_w_plantation_dialog = new PlantationDialog(this);

	_w_plantation_dialog->show();
}

void MainWindow::addNewPlantation()
{
	QString text = _w_plantations_list->currentText();

	// todo: get plantation object from QVariant of _w_plantations_list
	_w_garden_view->addPlantation(text);
}

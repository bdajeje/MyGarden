#include "main_window.hpp"

#include <QMenuBar>
#include <QVBoxLayout>

#include "utils/icons_manager.hpp"

MainWindow::MainWindow(QWidget *parent)
	: QMainWindow(parent)
{
	auto central_widget = new QWidget(this);
	auto main_layout    = new QVBoxLayout();

	// Window icon
	const QIcon& icon = utils::IconsManager::get("icon.png");
	setWindowIcon( icon );

	// Menu
	createMenu();
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

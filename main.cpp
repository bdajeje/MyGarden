#include "main_window.hpp"

#include <QApplication>
#include <QMessageBox>

#include <utils/properties.hpp>

int main(int argc, char *argv[])
{
	QApplication app(argc, argv);

	if( !utils::Properties::isValid() )
	{
	  QMessageBox::warning(nullptr, QObject::tr("Property error"),
									QObject::tr("The application can't load property file: ") + utils::Properties::instance().filepath());
	  return EXIT_FAILURE;
	}

	MainWindow window;
	window.show();

	return app.exec();
}

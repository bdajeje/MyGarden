#include "garden_view.hpp"

#include <QMessageBox>

#include <utils/properties.hpp>
#include <utils/files.hpp>

GardenView::GardenView(QWidget* parent)
	: QWebEngineView(parent)
{
	std::string html_content;
	if(!utils::files::read("./resources/html/garden.html", html_content))
		QMessageBox::critical(this, "Error", "Can't read garden view html");

	connect(this, SIGNAL(loadFinished(bool)), this, SLOT(pageLoaded(bool)));

	setHtml(html_content.c_str());
	page()->setBackgroundColor(QColor{utils::Properties::get(utils::Property::GardenBackgroundColor)});
}

void GardenView::addPlantation(const QString& text)
{
	QColor bg_color = QColor("#123212").toRgb();

	// Calculate text color from background color
	// Try to guess the 'opposite' color
	int red   = 255 - bg_color.red();
	int green = 255 - bg_color.green();
	int blue  = 255 - bg_color.blue();
	QColor text_color(red, green, blue);

	page()->runJavaScript("addPlantation('"+ text +"', '"+bg_color.name()+"', '"+text_color.name()+"');");
}

void GardenView::pageLoaded(bool success)
{
	if(!success)
	{
		QMessageBox::critical(this, "Error", "Can't load garden view");
		return;
	}

	std::array<std::string, 4> resources {
		"./resources/html/js/jquery-1.5.0.min.js",
		"./resources/html/js/jquery-ui-1.9.2.custom.min.js"
	};

	for(const auto& resource : resources)
	{
		std::string content;

		if(!utils::files::read(resource, content))
		{
			QMessageBox::critical(this, "Error", "Can't load jquery");
			return;
		}

		page()->runJavaScript(content.c_str());
	}
}

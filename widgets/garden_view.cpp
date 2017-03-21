#include "garden_view.hpp"

#include <QMessageBox>

#include <utils/files.hpp>

GardenView::GardenView(QWidget* parent)
	: QWebEngineView(parent)
{
	std::string html_content;
	if(!utils::files::read("./resources/html/garden.html", html_content))
		QMessageBox::critical(this, "Error", "Can't load garden view");

	setHtml(html_content.c_str());
//	page()->mainFrame()->addToJavaScriptWindowObject("hostObject", this);
}

void GardenView::addPlantation(const QString& text)
{

}

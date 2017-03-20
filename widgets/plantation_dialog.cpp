#include "plantation_dialog.hpp"

#include <QMessageBox>
#include <QVBoxLayout>
#include <QHBoxLayout>
#include <QPushButton>
#include <QColorDialog>

#include <utils/icons_manager.hpp>

PlantationDialog::PlantationDialog(QWidget* parent, Qt::WindowFlags flags)
	: QDialog {parent, flags}
{
	setWindowTitle(tr("Plantation"));
	setWindowIcon(utils::IconsManager::get("icon.png"));

	auto main_layout = new QVBoxLayout;

	_w_name = new QLineEdit;
	_w_name->setPlaceholderText(tr("Name"));

	_w_weeks_nbr = new QSpinBox;
	_w_weeks_nbr->setMinimum(0);
	_w_weeks_nbr->setMaximum(99);
	_w_weeks_nbr->setPrefix(tr("Grow time: "));
	_w_weeks_nbr->setSuffix(tr(" weeks"));

	_w_color = new JLabel;
	_w_color->setFixedSize(QSize{50, 50});
	setColor("red");// red to test

	auto buttons_layout = new QHBoxLayout;
	auto btn_cancel   = new QPushButton(tr("Cancel"));
	auto btn_validate = new QPushButton(tr("Validate"));
	buttons_layout->addWidget(btn_cancel);
	buttons_layout->addWidget(btn_validate);

	// Adding widget to layout
	main_layout->addWidget(_w_name);
	main_layout->addWidget(_w_weeks_nbr);
	main_layout->addWidget(_w_color);
	main_layout->addLayout(buttons_layout);
	setLayout(main_layout);

	connect(btn_cancel, SIGNAL(pressed()), this, SLOT(close()));
	connect(btn_validate, SIGNAL(pressed()), this, SLOT(validate()));
	connect(_w_color, SIGNAL(clicked()), this, SLOT(selectColor()));
}

void PlantationDialog::validate()
{
	if(!isValid())
	{
		QMessageBox::critical(this, "Error", "Invalid form");
		return;
	}

	if(!_plantation)
		_plantation = std::make_shared<Plantation>();

	_plantation->setName(_w_name->text().toStdString());
	_plantation->setGrowTime(_w_weeks_nbr->value());
	_plantation->setColor(_current_color.toStdString());

	if(!_plantation->save())
	{
		QMessageBox::critical(this, "Error", "Can't save data");
		return;
	}

	close();
}

bool PlantationDialog::isValid() const noexcept
{
	return !_w_name->text().isEmpty() && !_current_color.isEmpty() && _w_weeks_nbr->value() > 0;
}

void PlantationDialog::setPlantation(PlantationSP& plantation)
{
	if(!plantation)
		return;

	_plantation = plantation;
	_w_name->setText(plantation->getName().c_str());
	_w_weeks_nbr->setValue(plantation->getGrowTime());
	setColor(plantation->getColor());
}

void PlantationDialog::selectColor()
{
	QColor color = QColorDialog::getColor(Qt::white, this);

	if(!color.isValid())
		return;

	setColor(color.name().toStdString());
}

void PlantationDialog::setColor(const std::string& color)
{
	_current_color = color.c_str();
	_w_color->setStyleSheet(QString("background-color: ")+ color.c_str() +";");
}

#ifndef PLANTATIONDIALOG_H
#define PLANTATIONDIALOG_H

#include <QDialog>
#include <QLineEdit>
#include <QSpinBox>

#include <models/plantation.hpp>
#include <widgets/jlabel.hpp>

class PlantationDialog : public QDialog
{
	Q_OBJECT

	public:

		PlantationDialog(QWidget *parent = 0, Qt::WindowFlags flags = 0);

		void setPlantation(PlantationSP& plantation);

	protected:

		void setColor(const std::string& color);
		bool isValid() const noexcept;

	protected slots:

		void validate();
		void selectColor();

	protected:

		QLineEdit* _w_name;
		QSpinBox* _w_weeks_nbr;
		JLabel* _w_color;
		QString _current_color;
		PlantationSP _plantation;
};

#endif // PLANTATIONDIALOG_H

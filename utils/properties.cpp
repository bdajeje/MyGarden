#include "properties.hpp"

#include <utils/files.hpp>

#include <iostream>
#include <vector>

#include <QApplication>
#include <QDate>
#include <QStringList>

namespace utils {

Properties::Properties(QString filepath)
  : m_filepath( filepath )
{
  initProperties();

  // Read property files
  std::string content;
  if(!files::read( m_filepath.toStdString(), content) || content.empty())
	return;

  // Split line by line
  QString properties_content(content.c_str());
  QStringList lines = properties_content.split("\n");

  // Iterate over lines to find property pairs
  for( const QString& line : lines )
  {
	QStringList parts = line.split("=");
	if(parts.size() < 2)
	  continue;

	set(parts.at(0), parts.at(1));
  }

  // We are now considered as valid property
  m_valid = true;

  // Put default values for empty fields
  verify( Property::LastSeenYear, QString::number(QDate::currentDate().year()) );
}

void Properties::initProperties()
{
  m_properties_keys[LastSeenYear] = "LastSeenYear";
  m_properties_keys[Undefined]    = "undefined";
}

void Properties::set(QString key, QString value)
{
  auto found = std::find_if(m_properties_keys.begin(), m_properties_keys.end(), [&key](std::pair<Property, QString> iterator){
	return iterator.second == key;
  });

  if( found == m_properties_keys.end() )
	return;

  m_properties_values[found->first] = value;
}

void Properties::verify(Property property, const QString& value)
{
  if( m_properties_values[property].isEmpty() )
	m_properties_values[property] = value;
}

Properties& Properties::instance()
{
  static Properties instance(QApplication::applicationDirPath() + "/" + "resources/properties");
  return instance;
}

bool Properties::save( Property property, const QString& value )
{
  instance().m_properties_values[property] = value;

  return instance().save();
}

bool Properties::save()
{
  QString content;
  for( const auto it : m_properties_values )
	content += m_properties_keys[it.first] + '=' + it.second + '\n';

  return files::create(m_filepath.toStdString(), content.toStdString());
}

} // namespace utils

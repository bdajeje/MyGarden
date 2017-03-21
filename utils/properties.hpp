#ifndef PROPERTIES_HPP
#define PROPERTIES_HPP

#include <map>
#include <string>

#include <QString>

namespace utils {

/*! Existing properties */
enum Property { GardenBackgroundColor, LastSeenYear, Undefined };

class Properties final
{
  public:

	static Properties& instance();
	static const QString& get( Property property ) { return instance().m_properties_values[property]; }
	static bool save( Property property, const QString& value );
	static bool isValid() { return instance().m_valid; }

	const QString& filepath() const { return m_filepath; }

  private:

	Properties(QString filepath);
	bool save() const;
	void verify(Property property, const QString& value);
	void set(QString key, QString value);

  private:

	static const std::map<Property, QString> m_properties_keys;
	std::map<Property, QString> m_properties_values;
	const QString m_filepath;
	bool m_valid {false};
};

} // namespace utils

#endif // PROPERTIES_HPP

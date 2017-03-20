#ifndef PLANTATION_H
#define PLANTATION_H

#include <memory>

#include <utils/json.hpp>

class Plantation final
{
	public:

		Plantation() = default;
		Plantation(unsigned int id, const json& data);

		void setName(const std::string& name) noexcept { _name = name; }
		void setGrowTime(unsigned short time) noexcept { _grow_time = time; }
		void setColor(const std::string& color) noexcept { _color = color; }

		const std::string& getName() const noexcept { return _name; }
		unsigned short getGrowTime() const noexcept { return _grow_time; }
		const std::string& getColor() const noexcept { return _color; }

		bool save();

	protected:

		unsigned int findFreeID() const;
		std::string fileName(unsigned int id) const;

	protected:

		unsigned int _id {0};
		std::string _name;
		std::string _color;
		unsigned short _grow_time {0};

		static const std::string SavePath;
};

using PlantationSP = std::shared_ptr<Plantation>;

#endif // PLANTATION_H

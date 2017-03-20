#include "plantation.hpp"

#include <utils/files.hpp>

const std::string Plantation::SavePath = "./resources/plantations/";

Plantation::Plantation(unsigned int id, const json& data)
{
	_id = id;
	_name = data["name"];
	_color = data["color"];
	_grow_time = data["grow_time"];
}

bool Plantation::save()
{
	json content;
	content["name"] = _name;
	content["color"] = _color;
	content["grow_time"] = _grow_time;

	if(_id == 0)
		_id = findFreeID();

	return utils::files::create(fileName(_id), content.dump());
}

std::string Plantation::fileName(unsigned int id) const
{
	return SavePath + std::to_string(id) + ".json";
}

unsigned int Plantation::findFreeID() const
{
	unsigned int id = 1;
	const unsigned int max = std::numeric_limits<unsigned int>::max();

	while(id < max)
	{
		if(!utils::files::exists(fileName(id)))
			return id;
		else
			++id;
	}

	return 0;
}

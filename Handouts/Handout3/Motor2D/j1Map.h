#ifndef __j1MAP_H__
#define __j1MAP_H__

#include "PugiXml/src/pugixml.hpp"
#include "p2List.h"
#include "p2Point.h"
#include "j1Module.h"

// TODO 2: Create a struct to hold information for a TileSet
// Ignore Terrain Types and Tile Types for now, but we want the image!
// ----------------------------------------------------


struct tileset_info
{
	uint firstgrid = 1;
	char* name = nullptr;
	uint tilewidth = 32;
	uint tileheight = 32;
	uint spacing = 1;
	uint margin = 1;
};

// TODO 1: Create a struct needed to hold the information to Map node
enum class map_renderer
{
	left_down,
	right_down,
	left_up,
	right_up,
	error
};

enum class map_orientation
{
	ortogonal,
	error
};
struct map_info 
{
	map_orientation orientation = map_orientation::ortogonal;
	map_renderer renderorder = map_renderer::right_down;
	uint width = 0;
	uint height = 0;
	uint tilewidth = 0;
	uint tileheight = 0;
	//map_orientation orientation = map_orientation::error;
};

// ----------------------------------------------------
class j1Map : public j1Module
{
public:

	j1Map();

	// Destructor
	virtual ~j1Map();

	// Called before render is available
	bool Awake(pugi::xml_node& conf);

	// Called each loop iteration
	void Draw();

	// Called before quitting
	bool CleanUp();

	// Load new map
	bool Load(const char* path);

private:
	
	bool Load_map();

public:

	// TODO 1: Add your struct for map info as public for now
	map_info* map;
	p2List<tileset_info*> tille_set;
	p2List<j1Map*> map_set;
	

private:

	pugi::xml_document	map_file;
	p2SString			folder;
	bool				map_loaded;

};

#endif // __j1MAP_H__
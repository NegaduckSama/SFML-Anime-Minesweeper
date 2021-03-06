#pragma once
#include "State.h"

class GameState
	:public State
{
private:
	//Variables
	int flag_state;
	int first_ride;
	int games_difficulty;    // 0 - easy || 1 - medium || 2 - hard
	int mouse_position_x;
	int mouse_position_y;
	int timer_seconds;
	int background_number;
	float time;

	Field* field;

	sf::Clock* clock;
	sf::Event* event;
	sf::Vector2i* mouse_position;
	sf::Text* text;

	//SFML Sprite,Texturem Fonts
	std::map<std::string, sf::Sprite>::iterator sprite_iterator;
	std::map<std::string, sf::Font>::iterator font_iterator;

	//Functions 
	void Init() override;
	void UpdateSFMLEvents(sf::RenderWindow* target) override;
	void UpdateSFMLTime();
	void Update(sf::RenderWindow* target, Resources& resources) override;
	void Render( sf::RenderWindow* target, Resources& resources) override;


public:
	//Constructors/Destructor
	GameState(Resources& resources, int games_difficulty,int background_number);
	 ~GameState();

	int Run( sf::RenderWindow* target, Resources& resources) override;
	int Get_lvl() { return background_number; }
};

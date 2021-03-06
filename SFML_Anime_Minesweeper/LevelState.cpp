#include "LevelState.h"
//Constructors/Destructor
LevelState::LevelState(Resources& resources)
{
	this->Init();
	sprite_iterator = resources.LoadSprite("images/bc4.png");
}

LevelState::~LevelState()
{
	delete event;
	delete mouse_position;
	event = nullptr;
	mouse_position = nullptr;
}

//Functions 
void LevelState::Init()
{
	event = new sf::Event;
	mouse_position = new sf::Vector2i;

	this->flag_state = 5;
}

void LevelState::UpdateSFMLEvents(sf::RenderWindow* target)
{
	while (target->pollEvent(*event))
	{
		if ((event->type == sf::Event::KeyPressed) && (event->key.code == sf::Keyboard::Escape))
			flag_state = 0;
		if (event->type == sf::Event::MouseButtonPressed)
			if (event->key.code == sf::Mouse::Left)
			{
				if (mouse_position_x > 2.8 && mouse_position_x < 3.8 && mouse_position_y >7.4 && mouse_position_y < 8.38)
				{
					lvl = 1;
					flag_state = 1;
				}
				else
					if (mouse_position_x > 4.9 && mouse_position_x < 5.8 && mouse_position_y >7.4 && mouse_position_y < 8.38)
					{
						lvl = 2;
						flag_state = 1;
					}
					else
						if (mouse_position_x > 6.9 && mouse_position_x < 7.9 && mouse_position_y >7.4 && mouse_position_y < 8.38)
						{
							lvl = 3;
							flag_state = 1;
						}
						else
							if (mouse_position_x > 2.8 && mouse_position_x < 3.8 && mouse_position_y >8.9 && mouse_position_y < 9.9)
							{
								lvl = 4;
								flag_state = 2;
							}
							else
								if (mouse_position_x > 4.9 && mouse_position_x < 5.8 && mouse_position_y >8.9 && mouse_position_y < 9.9)
								{
									lvl = 5;
									flag_state = 2;
								}
								else
									if (mouse_position_x > 6.9 && mouse_position_x < 7.9 && mouse_position_y >8.9 && mouse_position_y < 9.9)
									{
										lvl = 6;
										flag_state = 2;
									}
									
			}
	}
}

void LevelState::Update(sf::RenderWindow* target, Resources& resources)
{
	*mouse_position = sf::Mouse::getPosition(*target);
	mouse_position_x = ((float)mouse_position->x / 63); //63 - button width
	mouse_position_y = ((float)mouse_position->y / 65);	 //65 - button height

	/*system("cls");
	std::cout << mouse_position_x << "||" << mouse_position_y;*/

	if (mouse_position_x > 2.8 && mouse_position_x < 3.8 && mouse_position_y >7.4 && mouse_position_y < 8.38)
		sprite_iterator = resources.LoadSprite("images/bc5.png");
	else
		if (mouse_position_x > 4.9 && mouse_position_x < 5.8 && mouse_position_y >7.4 && mouse_position_y < 8.38)
			sprite_iterator = resources.LoadSprite("images/bc6.png");
		else
			if (mouse_position_x > 6.9 && mouse_position_x < 7.9 && mouse_position_y >7.4 && mouse_position_y < 8.38)
				sprite_iterator = resources.LoadSprite("images/bc7.png");
			else
				if (mouse_position_x > 2.8 && mouse_position_x < 3.8 && mouse_position_y >8.9 && mouse_position_y < 9.9)
					sprite_iterator = resources.LoadSprite("images/bc8.png");
				else
					if (mouse_position_x > 4.9 && mouse_position_x < 5.8 && mouse_position_y >8.9 && mouse_position_y < 9.9)
						sprite_iterator = resources.LoadSprite("images/bc9.png");
					else
						if (mouse_position_x > 6.9 && mouse_position_x < 7.9 && mouse_position_y >8.9 && mouse_position_y < 9.9)
							sprite_iterator = resources.LoadSprite("images/bc10.png");
						else
							sprite_iterator = resources.LoadSprite("images/bc4.png");

	this->UpdateSFMLEvents(target);
}

void LevelState::Render(sf::RenderWindow* target, Resources& resources)
{
	target->clear();
	target->draw((*sprite_iterator).second);
	target->display();
}


int LevelState::Run(sf::RenderWindow* target, Resources& resources)
{
	while (flag_state==5)
	{
		this->Update(target, resources);
		this->Render(target, resources);
	}
	return flag_state;
}
#pragma once
#include <SFML/Graphics.hpp>
#include "../Entity/Player/Player.h"
#include "../SpriteData/AnimationData.h"
#include "../Entity/Enemy/Enemy.h"
#include "../UI/UIScreen/GUI.h"


class Game
{
public:
	enum GameState
	{
		START,
		GAMEPLAY,
		LOSE,
		WIN
	};

	Game();
	~Game();
	void run();


private:
	void genLevel();
	void isColliding(char);
	void runStartBehavior();
	void runGameplayBehavior(char actionFlags);

	Player* player;
	sf::Texture stage1;
	sf::Texture stage2;
	sf::Texture stage3;
	sf::Texture stage4;
	sf::Texture stage5;
	std::vector<sf::FloatRect> ground;
	std::vector<sf::FloatRect> ground2;

	//doors
	bool wPressed = false;
	int count = 0; //for testing
	//used to delete all entities when game is over
	bool gameOver = false;

	sf::Clock enemySpawnClockTemp;
	sf::Clock* enemySpawnClock = &enemySpawnClockTemp;
	bool allowEnemySpawnTemp = true;
	bool* allowEnemyDoorSpawn = &allowEnemySpawnTemp;

	GameState gameState = GameState::START;
	// if the player is moving right or left
	bool movingLeft = false, movingRight = false;
	//if player is shooting
	bool shooting = false;
	//used to determine if jumping
	bool jumping = false;
	//used to determined if crouching
	bool crouching = false;
	// what tick the game is on.
	unsigned int currentTick = 0, credits = 0;
	// indicates the scale of the window. 1.f = 1920x1080
	const float scale = 0.5f;

	sf::RenderWindow window = sf::RenderWindow(sf::VideoMode({ 1920, 1080 }), "Rolling Thunder");
	sf::View mainView = sf::View(sf::FloatRect({ 0, 0 }, { 1920, 1080 }));
	sf::View guiView = sf::View(sf::FloatRect({ 0,0 }, { 288, 170 }));

	//Sprite for the background
	sf::Sprite stage1Sprite;

	// static references from Entity to be used in Game
	std::vector<Entity*>& bullets = Entity::getBullets();
	std::vector<Entity*>& enemies = Entity::getEnemys();
	std::vector<Entity*>& rails = Entity::getRails();
	std::vector<Entity*>& doors = Entity::getDoors();


	std::vector<sf::RectangleShape> groundDebugSprites;

	GUI gui;
};
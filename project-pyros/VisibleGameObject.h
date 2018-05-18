#pragma once
#include <string>
#include <SFML/System.hpp>
#include <SFML/Graphics.hpp>

class VisibleGameObject
{
public:
	VisibleGameObject();
	virtual ~VisibleGameObject();

	virtual void load(std::string filename);
	virtual void draw(sf::RenderWindow *window);
	virtual void update(float elapsedTime) = 0;

	virtual void setPosition(sf::Vector2f);
	virtual void setPosition(float, float);
	virtual sf::Vector2f getPosition() const;
	virtual bool getIsLoaded() const;

	virtual sf::FloatRect getBoundingRect() const;

	virtual float getWidth();
	virtual float getHeight();

protected:
	sf::Sprite& getSprite();
	sf::FloatRect spriteDimensions;

private:
	sf::Sprite sprite;
	sf::Texture texture;
	std::string filename;
	bool isLoaded;
};


#pragma once
#include <SFML\Graphics.hpp>

using namespace sf;

class GUIElement
{
private:
	bool selected;
public:
	virtual void update(RenderWindow * window) {}
	virtual void draw(RenderWindow * window) {}

	virtual void write(int unicode) {}
};
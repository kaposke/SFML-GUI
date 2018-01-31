#pragma once
#include <GUI\GUIElement.h>

#include <SFML\Graphics.hpp>
#include <SFML\Window\Mouse.hpp>
#include <iostream>

using namespace std;
using namespace sf;

class Textbox : public GUIElement
{
private:
	bool selected;

	Font font;
	Text text;

	string str;
	string defaultString;

	Color textColor;
	Color defaultTextColor;

	Color defaultOutlineColor;
	Color selectedOutlineColor;

	RectangleShape box;
public:
	Textbox(Vector2f position, Vector2f size = Vector2f(300, 30));

	void update(RenderWindow * window);
	void draw(RenderWindow * window);
	void write(int unicode);

	void setText(string text);
	void setTextColor(Color color);

	void setDefaultText(string text);
	void setDefaultTextColor(Color color);

	void setSelectedOutlineColor(Color color);
	void setDefaultOutlineColor(Color color);

	string getString();
};
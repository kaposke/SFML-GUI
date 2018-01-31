#include "GUI\Textbox.h"

Textbox::Textbox(Vector2f position, Vector2f size)
{
	selected = false;
	//Colors
	defaultTextColor = Color(150,150,150);
	defaultOutlineColor = Color(150, 150, 150);
	textColor = Color(51,51,51);
	selectedOutlineColor = Color(118, 190, 223);
	
	//Box
	box.setSize(size);
	box.setPosition(position);
	box.setFillColor(Color::White);
	box.setOutlineColor(Color(150,150,150));
	box.setOutlineThickness(2);

	//Text
	if (!font.loadFromFile("../Debug/Data/Fonts/arial.ttf"))
		cout << "Failed to load font" << endl;

	str = "";
	defaultString = "Insert text";

	text.setFont(font);
	text.setCharacterSize(box.getSize().y - 10);
	text.setFillColor(defaultTextColor);
	text.setPosition(position);

	
	text.setString(defaultString);
}


void Textbox::update(RenderWindow * window)
{
	if (Mouse::isButtonPressed(Mouse::Left))
	{
		Vector2i mousePos = Mouse::getPosition(*window);
		if (mousePos.x > box.getPosition().x && mousePos.x < box.getPosition().x + box.getSize().x &&
			mousePos.y > box.getPosition().y && mousePos.y < box.getPosition().y + box.getSize().y)
		{
			selected = true;
			box.setOutlineColor(selectedOutlineColor);
		}
		else {
			selected = false;
			box.setOutlineColor(defaultOutlineColor);
		}
	}
}

void Textbox::draw(RenderWindow * window)
{
	window->draw(box);
	window->draw(text);
}

void Textbox::write(int unicode)
{
	if (selected)
	{
		if (unicode != 8)
			str += static_cast<char>(unicode);
		else if (str.length() > 0)
			str.pop_back();

		if (str.length() > 0)
		{
			text.setString(str);
			text.setFillColor(textColor);
		}
		else
		{
			text.setFillColor(defaultTextColor);
			text.setString(defaultString);
		}
	}
}

void Textbox::setText(string text)
{
	str = text;
}

void Textbox::setTextColor(Color color)
{
	textColor = color;
}

void Textbox::setDefaultText(string text)
{
	defaultString = text;
}

void Textbox::setDefaultTextColor(Color color)
{
	defaultTextColor = color;
}

void Textbox::setSelectedOutlineColor(Color color)
{
	selectedOutlineColor = color;
}

void Textbox::setDefaultOutlineColor(Color color)
{
	defaultOutlineColor = color;
}

string Textbox::getString()
{
	return str;
}

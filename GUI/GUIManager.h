#pragma once
#include "GUI\GUIElement.h"
#include "GUI\Textbox.h"

#include <SFML\Graphics.hpp>
#include <vector>

using namespace std;
using namespace sf;

class GUIManager
{
private:
	vector<GUIElement*> elements;
public:
	void addElement(GUIElement * element);

	void update(RenderWindow * window);
	void draw(RenderWindow * window);

	void write(int unicode);
};
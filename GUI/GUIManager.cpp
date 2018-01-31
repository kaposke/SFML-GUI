#include "GUIManager.h"

void GUIManager::addElement(GUIElement * element)
{
	elements.push_back(element);
}

void GUIManager::update(RenderWindow * window)
{
	for (int i = 0; i < elements.size(); i++)
	{
		elements[i]->update(window);
	}
}

void GUIManager::draw(RenderWindow * window)
{
	for (int i = 0; i < elements.size(); i++)
	{
		elements[i]->draw(window);
	}
}

void GUIManager::write(int unicode)
{
	for (int i = 0; i < elements.size(); i++)
	{
		elements[i]->write(unicode);
	}
}

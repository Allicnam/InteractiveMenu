#include "Main.hpp"

using namespace std;
using namespace sf;

int main()
{

	RenderWindow window(VideoMode(1000, 1000), "SFML works!");
#ifdef SFML_SYSTEM_WINDOWS
	__windowsHelper.setIcon(window.getSystemHandle());
#endif

	CircleShape shape(window.getSize().x/2);
	shape.setFillColor(Color::White);

	Texture shapeTexture;
	shapeTexture.loadFromFile("content/sfml.png");
	shape.setTexture(&shapeTexture);

	Event event;

	while (window.isOpen())
	{
		while (window.pollEvent(event))
		{
			if (event.type == Event::Closed)
				window.close();
		}

		window.clear();
		window.draw(shape);
		window.display();
	}

	return 0;
}

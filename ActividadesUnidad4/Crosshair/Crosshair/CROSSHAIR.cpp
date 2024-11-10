#include <SFML/Window.hpp>
#include <SFML/Graphics.hpp>
using namespace sf;

Texture texture_crosshair;
Sprite sprite_crosshair;

int main() {
	texture_crosshair.loadFromFile("crosshair.png");

	sprite_crosshair.setTexture(texture_crosshair);

	sprite_crosshair.setPosition(361, 235);

	sf::RenderWindow App(sf::VideoMode(800, 600, 32), "Crosshair ");


	while (App.isOpen())
	{
		sf::Event evt;
		while (App.pollEvent(evt)) {

			if (evt.type == sf::Event::Closed) {
				App.close();
			}
		}
		App.clear();
		App.draw(sprite_crosshair);
		
		
		App.display();
	}
	return 0;
}	

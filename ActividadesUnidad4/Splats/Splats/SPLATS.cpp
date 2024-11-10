#include <SFML/Window.hpp>
#include <SFML/Graphics.hpp>
#include <vector>
using namespace sf;

Texture texture_cr;
Texture texture_cb;
Sprite sprite_cr;
Sprite sprite_cb;

int main() {
	
	texture_cr.loadFromFile("rcircle.png");
	texture_cb.loadFromFile("rcircleb.png");

	sprite_cr.setTexture(texture_cr);
	sprite_cb.setTexture(texture_cb);

	std::vector<sf::Sprite> circulos;

	sf::RenderWindow App(sf::VideoMode(800, 600, 32), "Splats");

	while (App.isOpen()) {
		sf::Event evt;
		while (App.pollEvent(evt)) {
			if (evt.type == sf::Event::Closed) {
				App.close();
			}
			if (evt.type == sf::Event::MouseButtonPressed) {
				sf::Vector2i mousePos = sf::Mouse::getPosition(App);
				sf::Sprite sprite_nc;

				if (evt.mouseButton.button == sf::Mouse::Left) {
					sprite_nc.setTexture(texture_cr);
				}
				else if (evt.mouseButton.button == sf::Mouse::Right) {
					sprite_nc.setTexture(texture_cb);
				}
				sprite_nc.setPosition(static_cast<float>(mousePos.x) - sprite_nc.getGlobalBounds().width / 2, static_cast<float>(mousePos.y) - sprite_nc.getGlobalBounds().height / 2);

				circulos.push_back(sprite_nc);
			}
		}
		App.clear();

		for (const auto& sprite_nc : circulos) {
			App.draw(sprite_nc);
		}
		App.display();
	}
	return 0;
}

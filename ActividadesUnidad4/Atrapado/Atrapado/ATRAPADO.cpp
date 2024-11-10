#include <SFML/Window.hpp>
#include <SFML/Graphics.hpp>
using namespace sf;

Texture texture_cye;
Texture texture_gcir;
Sprite sprite_cye;




int main() {

	texture_cye.loadFromFile("cuad_yellow.png");
	texture_gcir.loadFromFile("rcircleg.png");

	


	sprite_cye.setTexture(texture_cye);
	float size = 50.0f;
	sprite_cye.setScale(size / sprite_cye.getLocalBounds().width, size / sprite_cye.getLocalBounds().height);
	sf::Vector2f position(375.0f, 275.0f);

	sprite_cye.setPosition(position);
	float speed = 200.0f;
	bool isSquare = true;
	sf::Clock clock;

	

	sf::RenderWindow App(sf::VideoMode(800, 600, 32), "Atrapado");

	while (App.isOpen()) {
		sf::Time deltaTime = clock.restart();
		float deltaSeconds = deltaTime.asSeconds();
		sf::Event evt;
		while (App.pollEvent(evt)) {
			if (evt.type == sf::Event::Closed)
				App.close();

			if (evt.type == sf::Event::KeyPressed && evt.key.code == sf::Keyboard::Space) {
				if (isSquare) {
					sprite_cye.setTexture(texture_cye);
					sprite_cye.setScale(size / texture_cye.getSize().x, size / texture_cye.getSize().y);
				}
				else {
					sprite_cye.setTexture(texture_gcir);
					sprite_cye.setScale(size / texture_gcir.getSize().x, size / texture_gcir.getSize().y);
				}
				isSquare = !isSquare;
			}
		}

		if (sf::Keyboard::isKeyPressed(sf::Keyboard::Up)) position.y -= speed * deltaSeconds;
		if (sf::Keyboard::isKeyPressed(sf::Keyboard::Down)) position.y += speed * deltaSeconds;
		if (sf::Keyboard::isKeyPressed(sf::Keyboard::Left)) position.x -= speed * deltaSeconds;
		if (sf::Keyboard::isKeyPressed(sf::Keyboard::Right)) position.x += speed * deltaSeconds;

		if (position.x < 0) position.x = 0;
		if (position.y < 0) position.y = 0;
		if (position.x + size > App.getSize().x) position.x = App.getSize().x - size;
		if (position.y + size > App.getSize().y) position.y = App.getSize().y - size;

		sprite_cye.setPosition(position);

		App.clear();

		App.draw(sprite_cye);

		App.display();
	}
	return 0;
} 

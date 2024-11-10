#include <SFML/Window.hpp>
#include <SFML/Graphics.hpp>
using namespace sf;


int main() {

    sf::RenderWindow App(sf::VideoMode(800, 600, 32), "Adaptacion");

    const int minWidth = 100;
    const int minHeight = 100;
    const int maxWidth = 1000;
    const int maxHeight = 1000;

    while (App.isOpen()) {
        sf::Event evt;
        while (App.pollEvent(evt)) {
            if (evt.type == sf::Event::Closed)
                App.close();

            if (evt.type == sf::Event::Resized) {
                int newWidth = evt.size.width;
                int newHeight = evt.size.height;

                if (newWidth < minWidth) newWidth = minWidth;
                if (newWidth > maxWidth) newWidth = maxWidth;
                if (newHeight < minHeight) newHeight = minHeight;
                if (newHeight > maxHeight) newHeight = maxHeight;

                App.setSize(sf::Vector2u(newWidth, newHeight));
            }
        }

        App.clear();

        App.display();
    }

    return 0;
}

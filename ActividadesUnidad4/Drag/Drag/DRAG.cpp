#include <SFML/Window.hpp>
#include <SFML/Graphics.hpp>
#include <vector>
using namespace sf;




Texture texture_izq;
Texture texture_der;
Texture texture_izqa;
Texture texture_dera;
Sprite  sprite_izq;
Sprite sprite_der;
Sprite sprite_izqa;
Sprite sprite_dera;



int main() {

    texture_izq.loadFromFile("rcircle.png");
    texture_der.loadFromFile("rcircle.png");
    texture_izqa.loadFromFile("rcircle.png");
    texture_dera.loadFromFile("rcircle.png");

    sprite_izq.setTexture(texture_izq);
    sprite_der.setTexture(texture_der);
    sprite_izqa.setTexture(texture_izqa);
    sprite_dera.setTexture(texture_dera);

    sprite_dera.setPosition(674, 0);
    sprite_izqa.setPosition(0, 0);
    sprite_izq.setPosition(0, 474);
    sprite_der.setPosition(674, 474);

    std::vector<sf::Sprite*> sprites = { &sprite_izq, &sprite_der, &sprite_izqa, &sprite_dera };

    sf::RenderWindow App(sf::VideoMode(800, 600, 32), "Drag");

    bool isDragging = false;
    sf::Sprite* selectedSprite = nullptr;
    sf::Vector2f offset;


    while (App.isOpen()) {

        sf::Event evt;
        while (App.pollEvent(evt)) {

            if (evt.type == sf::Event::Closed) {
                App.close();
            }

            if (evt.type == sf::Event::MouseButtonPressed) {

                sf::Vector2i mousePos = sf::Mouse::getPosition(App);

                for (auto sprite : sprites) {
                    if (sprite->getGlobalBounds().contains(static_cast<float>(mousePos.x), static_cast<float>(mousePos.y))) {
                        isDragging = true;
                        selectedSprite = sprite;
                        offset = selectedSprite->getPosition() - sf::Vector2f(static_cast<float>(mousePos.x), static_cast<float>(mousePos.y));
                        break;

                    }
                }
            }
                

                if (evt.type == sf::Event::MouseButtonReleased && evt.mouseButton.button == sf::Mouse::Left) {
                    isDragging = false;
                    selectedSprite = nullptr;
                }

                if (evt.type == sf::Event::MouseMoved && isDragging && selectedSprite) {
                    sf::Vector2i mousePos = sf::Mouse::getPosition(App);

                    selectedSprite->setPosition(static_cast<float>(mousePos.x) + offset.x, static_cast<float>(mousePos.y) + offset.y);

                }

                
            


            

        }
        App.clear();
        App.draw(sprite_izq);
        App.draw(sprite_der);
        App.draw(sprite_izqa);
        App.draw(sprite_dera);

        App.display();
            
    }
    return 0;
}



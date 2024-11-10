#pragma once
#include "stdafx.h"
using namespace sf;

class Enemigo {

	Texture texture_et;
	Sprite sprite_et;
	bool _estaVivo;
	bool _visible;
	float tiempo_pantalla;
	float fuera_pantalla;
	sf::Clock _reloj;
	Vector2f poscicion_random(Vector2u maxPos) {

		float xSprite = sprite_et.getGlobalBounds().width;
		float ySprite = sprite_et.getGlobalBounds().height;

		float posX = (float)(rand() % (int)(maxPos.x - xSprite));
		float posY = (float)(rand() % (int)(maxPos.y - ySprite));
		
		return Vector2f(posX, posY);

	}

public:

	Enemigo() {

		texture_et.loadFromFile("et.png");
		sprite_et.setTexture(texture_et);
		sprite_et.setScale(0.075f, 0.075f);
		_estaVivo = true;
		_visible = false;
		tiempo_pantalla = 0.5f;
		fuera_pantalla = 0.5f;

	}


	bool EstaVivo() {
		return _estaVivo; 

	}

	bool EnPantalla() {

		return _estaVivo && _visible;

	}

	bool Apuntar(float x, float y) {

		FloatRect bounds = sprite_et.getGlobalBounds();
		return bounds.contains(x, y);
	}

	void Matar() {
		_estaVivo = false;
	}

	void Dibujar(RenderWindow* App) {
		App->draw(sprite_et);
	}

	void Actualizar(RenderWindow* App) {

		if (!_estaVivo)
			return;

		if (!_visible) {
			if (_reloj.getElapsedTime().asSeconds() > fuera_pantalla) {
				_reloj.restart();
				if (rand() % 100 < 25) {
					_visible = true;
					sprite_et.setPosition(poscicion_random(App->getSize()));
					
				}
			
			}
		}
		else {

			if (_reloj.getElapsedTime().asSeconds() > tiempo_pantalla) {
				_visible = false;
				_reloj.restart();


			}

		}

	}

};

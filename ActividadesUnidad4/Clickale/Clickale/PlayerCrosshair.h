#pragma once
#include "stdafx.h"

class PlayerCrosshair {

	Texture texture_cross;
	Sprite sprite_cross;

public:

	PlayerCrosshair() {

		texture_cross.loadFromFile("crosshair.png");
		sprite_cross.setTexture(texture_cross);
		sprite_cross.setScale(0.50f, 0.50f);
		sprite_cross.setOrigin(texture_cross.getSize().x / 2.0f, texture_cross.getSize().y / 2.0f);
	}

	void Dibujar(RenderWindow* App) {

		App->draw(sprite_cross);
	}

	void Posicion(float x, float y) {

		sprite_cross.setPosition(x, y);

	}

	Vector2f ObtenerApuntado() {
		return sprite_cross.getPosition();
	}

};


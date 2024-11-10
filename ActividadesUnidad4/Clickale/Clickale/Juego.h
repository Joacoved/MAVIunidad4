#pragma once
#include <SFML/Graphics.hpp>
#include <SFML/Window.hpp>
#include <SFML/System.hpp>
#include "PlayerCrosshair.h"
#include "Enemigo.h"
using namespace sf;

class Juego {

	RenderWindow* _App;
	PlayerCrosshair* _player;
	Enemigo* _enemigos;
	Text _puntaje;
	Font _fuente;
	int _puntos;
	void actualizar_puntaje() {
		_puntaje.setString(std::to_string(_puntos));
	}

public:

	Juego() {

		_App = new RenderWindow(VideoMode(800, 600, 32), "Clickeale");
		_player = new PlayerCrosshair();
		_enemigos = new Enemigo[5];
		_App->setMouseCursorVisible(false);
		_puntos = 0;
		_fuente.loadFromFile("Tiny5-Regular.ttf");
		_puntaje.setPosition(0.0f, 0.0f);
		_puntaje.setCharacterSize(100.0f);
		_puntaje.setFont(_fuente);
		actualizar_puntaje();
	}

	void Loop() {

		while (_App->isOpen())
		{
			ProcesarEventos();
			Actualizar();
			Dibujar();

		}
	}


	void ProcesarEventos() {
		Event evt;
		while (_App->pollEvent(evt)) {
			switch (evt.type) {
			case Event::Closed:
				_App->close();
				break;
			case Event::MouseButtonPressed:
				if (evt.mouseButton.button == Mouse::Button::Left)
					Disparar();
				break;
			}
		}
	}

	void Actualizar() {

		Vector2i mousePos = Mouse::getPosition(*_App);
		_player->Posicion(mousePos.x, mousePos.y);
		for (size_t i = 0; i < 5; i++) {

			_enemigos[i].Actualizar(_App);

		}

		

	}

	void Disparar() {

		Vector2f playerPos = _player->ObtenerApuntado();

		for (int i = 0; i < 5; i++) {

			if (_enemigos[i].EnPantalla()) {
				if (_enemigos[i].Apuntar(playerPos.x, playerPos.y)) {
					_enemigos[i].Matar();
						_puntos++;
					
				
					
				}

			}
		}

		actualizar_puntaje();

	}

	void Dibujar() {
		_App->clear();
		for (int i = 0; i < 5; i++) {
			if (_enemigos[i].EnPantalla())
				_enemigos[i].Dibujar(_App);
		}
		_App->draw(_puntaje);
		_player->Dibujar(_App);
		_App->display();

	}




};

	

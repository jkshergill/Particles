#include "Engine.h"

#include <iostream>
using namespace std;

Engine::Engine() {
    m_Window.create();
    VideoMode::getDesktopMode();
}

void Engine::run() {
    Clock clock;
    cout << "Starting Particle unit tests..." << endl;
    Particle p(m_Window, 4, { (int)m_Window.getSize().x / 2, (int)m_Window.getSize().y / 2 });
    p.unitTests();
    cout << "Unit tests complete.  Starting engine..." << endl;

    while(m_Window.isOpen()) {
        clock.restart();
        Time time1 = clock.getElapsedTime();
        Time time2 = time1.asSeconds();
        p.input();
        p.update(time2);
        p.draw();
    
    }
}

void Engine::input() {
    Event event;
    
    while (m_Window.pollEvent(event)) {
        
        if (Keyboard::isKeyPressed(Keyboard::Escape)) {   
			m_Window.close();
		}

        if (event.type == Event::Closed) { m_Window.close(); }
            
        if (event.type == Event::MouseButtonPressed) {
            if (event.mouseButton.button == sf::Mouse::Left) {
                //update here
            }
        }
    }
}

void Engine::update(float dtAsSeconds) {

}

voide Engine::draw() {

}

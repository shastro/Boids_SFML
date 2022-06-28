#include <SFML/Graphics.hpp>
#include <iostream>
#include <Actor.hpp>

using namespace std;

int main() {
  sf::RenderWindow window(sf::VideoMode(100, 100), "Boids Test");
  sf::CircleShape shape(100.f);

  shape.setFillColor(sf::Color::Green);

  auto steven = Actor();
  cout << steven.getPosition() << endl;

  while (window.isOpen()) {
    sf::Event event;

    while (window.pollEvent(event)) {
      if (event.type == sf::Event::Closed) {
        window.close();
      }
    }

    window.clear();
    window.draw(shape);
    window.display();
  }
  return 0;
}

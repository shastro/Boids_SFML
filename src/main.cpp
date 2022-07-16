#include <Actor.hpp>
#include <BoidLogic.hpp>
#include <SimConfig.hpp>
#include <SFML/Graphics.hpp>
#include <iostream>
// #include <SFML/Mouse.hpp>

using namespace std;

int main() {
  sf::RenderWindow window(sf::VideoMode(1000, 1000), "Boids Test");

  BoidConfig boid_conf = {
      20 * 3.14159 / 180, // theta_blind
      10,                 // observe_dist
      5,                  // cohesion
      5,                  // separation
      5,                  // allignment
  };

  SimConfig sim_conf =
  {
    0.01, // Delta t
    15, // Num Actors
  };


  auto steven = Actor(&boid_conf, &sim_conf, &window);
  cout << steven.getPosition() << endl;

  while (window.isOpen()) {
    sf::Event event;

    while (window.pollEvent(event)) {
      if (event.type == sf::Event::Closed) {
        window.close();
      }
    }

    double mouse_x = sf::Mouse::getPosition(window).x;
    double mouse_y = sf::Mouse::getPosition(window).y;
    double mouse_angle = compute_absolute_angle(mouse_x - steven.getPosition().x(), mouse_y - steven.getPosition().y());

    double strength = 10;
    cout << "Mouse" <<mouse_angle << endl;
    cout << "MouseX" << mouse_x << "StevenX" << steven.getPosition().x() << endl;
    cout << "MouseY" << mouse_y << "StevenY" << steven.getPosition().y() << endl;
    cout << "Steven" << steven.getTheta() << endl;

    steven.setOmega(strength * (mouse_angle - steven.getTheta()));
    // if ( mouse_angle > steven.getTheta()) {
    //   steven.setOmega(-strength * ( mouse_angle - steven.getTheta()) );
    // } else {
    //   steven.setOmega(-strength * (mouse_angle - steven.getTheta()));
    // }

    // steven.applyTorque(10);
    // steven.setOmega(2);

    // Physics loop
    steven.update();

    window.clear();
    steven.draw();
    window.display();
  }
  return 0;
}

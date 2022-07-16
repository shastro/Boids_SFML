#include <Actor.hpp>
#include <BoidLogic.hpp>
#include <SFML/Graphics/CircleShape.hpp>
#include <SFML/Graphics/RectangleShape.hpp>
#include <SFML/System/Time.hpp>
#include <SFML/System/Vector2.hpp>
#include <cmath>
#include <random>

using Eigen::Matrix;
using Eigen::Rotation2D;
using Eigen::Vector2d;
using namespace std;

double compute_absolute_angle(double x, double y) {
  double angle_x = abs(atan(y / x));

  if (y >= 0 && x >= 0) { // Q1
    angle_x = angle_x;
  } else if (y >= 0 && x <= 0) { // Q2
    angle_x = M_PI - angle_x;
  } else if (y <= 0 && x <= 0) { // Q3
    angle_x += M_PI;
  } else if (y <= 0 && x >= 0) { // Q4
    angle_x = 2 * M_PI - angle_x;
  }
  return angle_x;
}

Actor::Actor(BoidConfig *b_conf, SimConfig *s_conf, sf::RenderWindow *sf_win) {
  m_position = Vector2d(500, 500);
  m_velocity = Vector2d(500, 0);
  m_theta = 0.0;
  m_mass = 1;

  // Rotation2D init_rot = Rotation2D<double>(90 * (3.141519 / 180));
  // Matrix<double, 2, 2> rot_neg_90{{-1, 0}, {0, -1}};
  // m_velocity = (init_rot * m_velocity);

  // SFML
  m_sf_win = sf_win;

  // Boids params
  m_b_conf = b_conf;

  // Simulation Params
  m_s_conf = s_conf;
  m_sim_deltat = m_s_conf->deltat;

  // SFML Params
  m_sf_radius = 20;
}

Vector2d Actor::getPosition() { return m_position; }
Vector2d Actor::getVelocity() { return m_velocity; }

void Actor::updateTheta() {
  double x = m_velocity.x();
  double y = m_velocity.y();

  // Want angle with respect to the x axis
  m_theta = compute_absolute_angle(x, y);
}
double Actor::getTheta() { return m_theta; }

double Actor::getOmega() { return m_omega; }

void Actor::applyForce(double &delta_velocity) {
  // Really just assuming we only want to increase the linear speed across
  // current heading
  m_velocity += m_velocity.normalized() * delta_velocity * m_sim_deltat;
}
void Actor::applyTorque(double delta_omega) {
  m_omega += delta_omega * m_sim_deltat;
}

void Actor::setOmega(double omega) { m_omega = omega; }

void Actor::update() {

  double dtheta = m_omega * m_sim_deltat;


  Rotation2D rotation = Rotation2D<double>(dtheta);
  m_velocity = (rotation * m_velocity);

  // Update Theta
  updateTheta();

  if (m_position.y() > 1000) {
    m_velocity *= -1;
  }

  m_position += m_velocity * m_sim_deltat;
  sf::sleep(sf::milliseconds(30));
}

void setSteerTarget(sf::Vector2f position, double intensity) {
}

void Actor::draw() {

  sf::CircleShape circ;
  circ.setRadius(m_sf_radius);
  circ.setOrigin(m_sf_radius, m_sf_radius);
  circ.setPosition(m_position.x(), m_position.y());
  circ.setFillColor(sf::Color::Red);

  sf::RectangleShape heading;
  heading.setSize(sf::Vector2f(2 * m_sf_radius, m_sf_radius / 10));
  heading.setPosition(m_position.x(), m_position.y());
  heading.setRotation(m_theta * (180.0 / 3.14159));

  m_sf_win->draw(circ);
  m_sf_win->draw(heading);
}

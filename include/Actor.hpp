#include <iostream>
#include <SFML/Graphics.hpp>
#include <Eigen/Dense>

using Eigen::Vector2d;

class Actor {
private:
  // Primary observables

  Vector2d m_position; // Meters TODO: Find vector library
  double m_theta; // Radians
  double m_theta_u; // Uncertainty in theta

  // Simulation parameters
  double m_mass;
  Vector2d m_velocity;
  Vector2d m_acceleration;
  double m_theta_dot;
  double m_omega;

public:

  Actor();

 const Vector2d& getPosition();
 const Vector2d& getVelocity();
 const Vector2d& getTheta();

};

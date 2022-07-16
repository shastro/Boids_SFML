/**
 * @file      Actor.hpp
 * @brief     Header of Actor.cpp
 * @date      Fri Jul  1 18:51:35 2022
 * @author    Skyler Hughes
 * @copyright BSD-3-Clause
 *
 * This module contains the Actor class declaration
 */
#ifndef ACTORHPP
#define ACTORHPP
#include <Eigen/Dense>
#include <SFML/Graphics.hpp>
#include <iostream>
#include <memory>

#include <BoidLogic.hpp>
#include <SimConfig.hpp>
using Eigen::Vector2d;

double compute_absolute_angle(double x, double y);

class Actor {
private:
  // Primary observables
  Vector2d m_position; // Meters TODO: Find vector library
  double m_theta;      // Radians
  double m_theta_u;    // Uncertainty in theta

  // Simulation parameters
  double m_mass;
  Vector2d m_velocity;
  Vector2d m_acceleration;
  double m_omega; // Angular velocity

  // Configuration
  BoidConfig *m_b_conf;
  SimConfig *m_s_conf;
  sf::RenderWindow *m_sf_win;
  double m_sim_deltat;


  // RenderValues
  double m_sf_radius;
  // Utils
  std::vector<std::shared_ptr<Actor>> m_neighbors; // Vector of nearby boids

public:
  Actor(BoidConfig *b_conf, SimConfig *s_conf, sf::RenderWindow *sf_win);

  Vector2d getPosition();
  Vector2d getVelocity();
  double getTheta();
  void updateTheta();
  double getOmega();


  void setSteerTarget(double intensity);

  void setOmega(double omega);
  void applyForce(double &delta_velocity);
  void applyTorque(double delta_omega);
  void update();
  void draw();
};
#endif

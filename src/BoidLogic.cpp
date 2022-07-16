/**
 * @file      BoidLogic.cpp
 * @brief     Source of BoidLogic.hpp
 * @date      Fri Jul  1 19:02:58 2022
 * @author    Skyler Hughes
 * @copyright BSD-3-Clause
 *
 * This module contains implementations for BoidLogic.hpp
 */

#include <Actor.hpp>
#include <BoidLogic.hpp>
#include <cmath>
#include <iostream>

using Eigen::Matrix;
using Eigen::Vector2d;

std::pair<double, double> calculate_alignment(BoidConfig &b_conf,
                                              Actor &primary,
                                              std::vector<Actor> &others) {

  double a_weight = b_conf.alignment;

  // Average over all boids in other in terms of heading and velocity
  Vector2d a_vel = Vector2d(0, 0);

  double num = others.size();

  double omega_correction = a_weight;
  double vel_mag_correction = a_weight;

  for (auto &boid : others) {
    a_vel += boid.getVelocity();
  }
  a_vel /= num;

  // Time to determine the direction to turn.
  // Matrix<double, 2, 2> rot_neg_90{{1, 0}, {0, -1}};

  // #TODO: finish this function

  // if (a_omega > primary.getOmega()) {
  //   omega_correction *= -1;
  // }

  if (a_vel.norm() > primary.getVelocity().norm()) {
    vel_mag_correction *= -1;
  }

  return std::pair<double, double>(vel_mag_correction, omega_correction);
}

Vector2d calculate_cohesion(BoidConfig &b_conf, Actor &primary,
                            std::vector<Actor> const &others) {

  // Compute center of mass of other boids and steer primary towards it
  //
}

Vector2d calculate_separation(BoidConfig &b_conf, Actor &primary,
                              std::vector<Actor> const &others) {}

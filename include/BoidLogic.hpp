/**
 * @file      BoidLogic.hpp
 * @brief     Header of BoidLogic.cpp
 * @date      Fri Jul  1 18:50:41 2022
 * @author    Skyler Hughes
 * @copyright BSD-3-Clause
 *
 * This module is responsible for declarations associated with the boids
 * implementation
 */

#ifndef BOIDLOGICHPP
#define BOIDLOGICHPP
#include <Eigen/Dense>

class Actor;
using Eigen::Vector2d;
/* Contains extra logic or structure related to the boids implementation */

/**
 * @struct BoidConfig
 * Contains configuration weights for the boids simulation
 */
struct BoidConfig {

  double theta_blind;  // Size of blind spot /**< Description */
  double observe_dist; // Observation distance (meters) /**< Description */
  double cohesion;     // Cohesion weight, weight on torque applied for steering
                       // /**< Description */ towards nearby center of mass /**<
                       // Description */
  double separation;   // Separation weight, torque applied proportional to /**<
                       // Description */ distance of closest boids /**<
                       // Description */
  double alignment;    // Alignment weight, tries to match speed and velocity of
                       // /**< Description */
};

/**
 * @brief Calculates alignment force and torque on Actor based on vector of
 * (nearby) actors
 * @param[in] b_conf BoidConfig for separation weight
 * @param[in] primary actor for which forces/torques should be applied on.
 * @param[in] others vector of Actors to compute alignment from
 * @return std::pair<> of vectors representing the force and torque that should
 * be applied to `primary`
 */
std::pair<double, double>
calculate_alignment(BoidConfig &b_conf, Actor &primary,
                    std::vector<Actor> const &others);

/**
 * @brief Calculates cohesion torque on Actor based on vector of
 * (nearby) actors
 * @param[in] b_conf BoidConfig for cohesion weight
 * @param[in] primary actor for which forces/torques should be applied on.
 * @param[in] others vector of Actors to compute alignment from
 * @return Vector2d representing the torque that should
 * be applied to `primary`
 */
Vector2d calculate_cohesion(BoidConfig &b_conf, Actor &primary,
                             std::vector<Actor> const &others);

/**
 * @brief Calculates separation torque on Actor based on vector of
 * (nearby) actors
 * @param[in] b_conf BoidConfig for separation weight
 * @param[in] primary actor for which forces/torques should be applied on.
 * @param[in] others vector of Actors to compute alignment from
 * @return Vector2d representing the torque that should
 * be applied to `primary`
 */
Vector2d calculate_separation(BoidConfig &b_conf, Actor &primary,
                             std::vector<Actor> const &others);

#endif

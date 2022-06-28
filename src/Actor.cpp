#include <Actor.hpp>
#include <SFML/System/Vector2.hpp>

using Eigen::Vector2d;

Actor::Actor() {
  m_position = Vector2d(0.0, 0.0);
  m_theta = 0.0;
}

const Vector2d& Actor::getPosition() {
  return const_cast<Vector2d*>(&m_position);
}

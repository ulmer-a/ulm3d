#include "PoolBall.h"

std::size_t gtime();

PoolBall::PoolBall()
{

}

void PoolBall::update()
{
  // calculate time delta
  auto ms = gtime();
  auto deltaT = ms - m_lastUpdate;
  m_lastUpdate = ms;

  // apply friction losses
  m_velocity *= (m_friction * 0.001);

  // calculate new position
  auto distPerMs = m_velocity * 0.001;
  m_position += distPerMs * deltaT;
}

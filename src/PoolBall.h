#pragma once

#include <glm/glm.hpp>

class PoolBall
{
  public:
    PoolBall();

    void update();

  private:
    glm::vec2 m_friction;       // friction coefficients
    std::size_t m_lastUpdate;   // time of last position update
    glm::vec2 m_velocity;       // current directed velocity
    glm::vec2 m_position;       // current normalized position
};


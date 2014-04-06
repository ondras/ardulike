#ifndef __ARDULIKE_STAIRS_H__
#define __ARDULIKE_STAIRS_H__

#include "entity.h"

class Stairs : public Entity {
  private:
  uint8_t target_level, target_position;

  public:
  Stairs(char _representation, uint8_t _level, uint8_t _position, uint8_t _target_level, uint8_t _target_position);
  uint8_t getTargetLevel(void);
  uint8_t getTargetPosition(void);
};

#endif

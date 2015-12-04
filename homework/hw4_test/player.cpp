#include "player.h"

Player::Player(double weight, double chi) : _weight(weight), _chi(chi) {}

double Player::getWeight() const {
  return _weight;
}

double Player::getChi() const {
  return _chi;
}

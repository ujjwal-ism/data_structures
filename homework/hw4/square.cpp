#include "square.h"

Square::Square(double cannon_powder, double teleporter_energy) :
  _cannon_powder(cannon_powder),
  _teleporter_energy(teleporter_energy) {}

double Square::getCannonPowder() const { return _cannon_powder; }

double Square::getTeleporterEnergy() const { return _teleporter_energy; }

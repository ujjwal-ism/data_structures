#ifndef MONSOON_2016_SQUARE_H
#define MONSOON_2016_SQUARE_H

class Square{
private:
  double _cannon_powder;
  double _teleporter_energy;

public:
  Square(double, double);

  double getCannonPowder() const;
  double getTeleporterEnergy() const;
};

#endif

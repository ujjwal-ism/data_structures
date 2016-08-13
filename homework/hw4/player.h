#ifndef MONSOON_2016_PLAYER_H
#define MONSOON_2016_PLAYER_H

class Player{
  private:
    double _weight;
    double _chi;

  public:
    Player(double, double);

    double getWeight() const;
    double getChi() const;
};

#endif

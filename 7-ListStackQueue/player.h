#ifndef CSE250_FALL2015_PLAYER_H
#define CSE250_FALL2015_PLAYER_H

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

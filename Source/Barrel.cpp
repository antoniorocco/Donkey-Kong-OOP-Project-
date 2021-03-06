#include "../Headers/Barrel.h"
Barrel::Barrel(const int &x, const int &y)
    : Entity(x, y), cont(0), down(false), right(true), left(false) {}
int Barrel::barrelColor() {
  cont++;
  if (cont == 2)
    cont = 0;
  return cont;
}
void Barrel::setRight(const bool &ok) { right = ok; }
void Barrel::setFall(const bool &ok) { fall = ok; }
void Barrel::setLeft(const bool &ok) { left = ok; }
void Barrel::setDown(const bool &ok) { down = ok; }
bool Barrel::getLeft() { return left; }
bool Barrel::getRight() { return right; }
bool Barrel::getDown() { return down; }
bool Barrel::getFall() { return fall; }
void Barrel::Draw() {
  if (down == false && fall == false) {
    if (left == true) {
      setX(getX() - 8);
      if (cont == 0)
        bip = al_load_bitmap("../Sprites/Barrel1.png");
      else if (cont == 1)
        bip = al_load_bitmap("../Sprites/Barrel2.png");
      else if (cont == 2)
        bip = al_load_bitmap("../Sprites/Barrel3.png");
      else
        bip = al_load_bitmap("../Sprites/Barrel4.png");

      al_draw_bitmap(bip, getX(), getY(), 0);
      al_destroy_bitmap(bip);
    } else if (right == true) {
      setX(getX() + 8);
      if (cont == 0)
        bip = al_load_bitmap("../Sprites/Barrel1.png");
      else if (cont == 1)
        bip = al_load_bitmap("../Sprites/Barrel2.png");
      else if (cont == 2)
        bip = al_load_bitmap("../Sprites/Barrel3.png");
      else
        bip = al_load_bitmap("../Sprites/Barrel4.png");
      al_draw_bitmap(bip, getX(), getY(), 0);
      al_destroy_bitmap(bip);
    }
  } else {
    setY(getY() + 8);
    if (cont == 0 || cont == 2)
      bip = al_load_bitmap("../Sprites/Barrel5.png");
    else
      bip = al_load_bitmap("../Sprites/Barrel6.png");
    al_draw_bitmap(bip, getX(), getY(), 0);
    al_destroy_bitmap(bip);
  }
  cont++;
  if (cont == 4)
    cont = 0;
}

Barrel Barrel::operator=(Barrel &b) {
  if (this != &b) {
    this->setX(b.getX());
    this->setY(b.getY());
    this->cont = b.cont;
    this->right = b.right;
    this->fall = b.fall;
    this->left = b.left;
    this->down = b.down;
  }
  return *this;
}
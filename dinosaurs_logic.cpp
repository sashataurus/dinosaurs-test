#include "dinosaurs_logic.h"

bool IsDead(int hp, int enemy_hp) {
    if (hp <= 0) {
        return true;
    }
    if (enemy_hp <= 0) {
        return false;
    }
    return false;
}

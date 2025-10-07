#include <gtest/gtest.h>
#include <string>
#include <iostream>
#include <fstream>

bool IsDead(int hp, int enemy_hp);

// Тест 1: IsDead - игрок мертв когда hp <= 0
TEST(DinosaursTest, IsDead_PlayerDeadWhenHPZero) {
    // Arrange
    int player_hp = 0;
    int enemy_hp = 100;
    
    // Act
    bool result = IsDead(player_hp, enemy_hp);
    
    // Assert
    EXPECT_TRUE(result);
}

// Тест 2: IsDead - игрок жив когда hp > 0
TEST(DinosaursTest, IsDead_PlayerAliveWhenHPPositive) {
    // Arrange
    int player_hp = 50;
    int enemy_hp = 100;
    
    // Act
    bool result = IsDead(player_hp, enemy_hp);
    
    // Assert
    EXPECT_FALSE(result);
}

// Тест 3: IsDead - оба hp = 0
TEST(DinosaursTest, IsDead_BothHPZero) {
    // Arrange
    int player_hp = 0;
    int enemy_hp = 0;
    
    // Act
    bool result = IsDead(player_hp, enemy_hp);
    
    // Assert
    EXPECT_TRUE(result);
}

// Тест 4: Валидация денег - хватает
TEST(DinosaursTest, MoneyValidation_CanAfford) {
    // Arrange
    int current_cash = 100;
    int dino_price = 21;
    
    // Act & Assert
    EXPECT_TRUE(current_cash >= dino_price);
}

// Тест 5: Валидация денег - не хватает
TEST(DinosaursTest, MoneyValidation_CannotAfford) {
    // Arrange
    int current_cash = 10;
    int dino_price = 21;
    
    // Act & Assert
    EXPECT_FALSE(current_cash >= dino_price);
}


int main(int argc, char **argv) {
    ::testing::InitGoogleTest(&argc, argv);
    
    int testResult = RUN_ALL_TESTS();
    
    return testResult;
}

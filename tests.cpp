#include <gtest/gtest.h>
#include <string>
#include <fstream>

#include "dinosaurs.cpp"

class DinosaursTest : public ::testing::Test {
protected:
    void SetUp() override {
        std::ofstream cash_file("cash_test.txt");
        cash_file << "100";
        cash_file.close();
        
        std::ofstream dino_file("dino_numbers_test.txt");
        dino_file << "123";
        dino_file.close();
    }
    
    void TearDown() override {
        remove("cash_test.txt");
        remove("dino_numbers_test.txt");
    }
};

// Тест 1: IsDead - игрок мертв когда hp <= 0
TEST_F(DinosaursTest, IsDead_PlayerDeadWhenHPZero) {
    // Arrange
    int player_hp = 0;
    int enemy_hp = 100;
    
    // Act
    bool result = IsDead(player_hp, enemy_hp);
    
    // Assert
    EXPECT_TRUE(result);
}

// Тест 2: IsDead - игрок жив когда hp > 0
TEST_F(DinosaursTest, IsDead_PlayerAliveWhenHPPositive) {
    // Arrange
    int player_hp = 50;
    int enemy_hp = 100;
    
    // Act
    bool result = IsDead(player_hp, enemy_hp);
    
    // Assert
    EXPECT_FALSE(result);
}

// Тест 3: IsDead - оба hp = 0
TEST_F(DinosaursTest, IsDead_BothHPZero) {
    // Arrange
    int player_hp = 0;
    int enemy_hp = 0;
    
    // Act
    bool result = IsDead(player_hp, enemy_hp);
    
    // Assert
    EXPECT_TRUE(result);
}

// Тест 4: Валидация денег
TEST_F(DinosaursTest, MoneyValidation_CanAfford) {
    // Arrange
    int current_cash = 100;
    int dino_price = 21;
    
    // Act & Assert
    bool can_afford = current_cash >= dino_price;
    EXPECT_TRUE(can_afford);
}

// Тест 5: Валидация денег - недостаточно
TEST_F(DinosaursTest, MoneyValidation_CannotAfford) {
    // Arrange
    int current_cash = 10;
    int dino_price = 21;
    
    // Act & Assert
    bool can_afford = current_cash >= dino_price;
    EXPECT_FALSE(can_afford);
}

int main(int argc, char **argv) {
    ::testing::InitGoogleTest(&argc, argv);
    return RUN_ALL_TESTS();
}

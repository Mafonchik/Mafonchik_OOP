#include <gtest/gtest.h>
#include "header.hpp"

// Тесты для функции validation

TEST(ValidationTest, ValidCase) {
    std::string text = "hello world";
    EXPECT_FALSE(validation(2, 'l', text)); // Вторая буква 'l' существует
}

TEST(ValidationTest, NLessThanOne) {
    std::string text = "hello";
    EXPECT_TRUE(validation(0, 'l', text)); // n = 0
    EXPECT_TRUE(validation(-1, 'l', text)); // n = -1
}

TEST(ValidationTest, NGreaterThanCount) {
    std::string text = "hello";
    EXPECT_TRUE(validation(3, 'l', text)); // Всего 2 буквы 'l', запрашиваем 3-ю
}

TEST(ValidationTest, CharacterNotInText) {
    std::string text = "hello";
    EXPECT_TRUE(validation(1, 'x', text)); // Буквы 'x' нет в тексте
}

TEST(ValidationTest, EmptyString) {
    std::string text = "";
    EXPECT_TRUE(validation(1, 'a', text)); // Пустая строка
}

TEST(ValidationTest, MultipleOccurrences) {
    std::string text = "banana";
    EXPECT_FALSE(validation(3, 'a', text)); // Третья буква 'a' существует
    EXPECT_TRUE(validation(4, 'a', text)); // Четвертой буквы 'a' нет
}

// Тесты для функции replace

TEST(ReplaceTest, ReplaceEverySecondOccurrence) {
    std::string text = "hello world";
    std::string result = replace(text, 2, 'l', 'x');
    EXPECT_EQ(result, "helxo world"); // Каждая вторая 'l' заменяется на 'x'
}

TEST(ReplaceTest, ReplaceEveryOccurrence) {
    std::string text = "hello";
    std::string result = replace(text, 1, 'l', 'x');
    EXPECT_EQ(result, "hexxo"); // Каждая 'l' заменяется на 'x'
}

TEST(ReplaceTest, ReplaceThirdOccurrence) {
    std::string text = "banana";
    std::string result = replace(text, 3, 'a', 'x');
    EXPECT_EQ(result, "bananx"); // Третья 'a' заменяется на 'x'
}

TEST(ReplaceTest, NoReplacementsNeeded) {
    std::string text = "hello";
    std::string result = replace(text, 5, 'l', 'x'); // Пятая 'l' не существует
    // Функция replace не должна вызываться если validation возвращает true,
    // но если вызвана - вернет оригинальную строку
    EXPECT_EQ(result, "hello");
}

TEST(ReplaceTest, ReplaceWithSameCharacter) {
    std::string text = "hello";
    std::string result = replace(text, 1, 'l', 'l');
    EXPECT_EQ(result, "hello"); // Замена на тот же символ
}

TEST(ReplaceTest, CaseSensitivity) {
    std::string text = "Hello";
    std::string result = replace(text, 1, 'H', 'h');
    EXPECT_EQ(result, "hello"); // Замена с учетом регистра
}

TEST(ReplaceTest, SpecialCharacters) {
    std::string text = "a*b*c*d";
    std::string result = replace(text, 2, '*', '-');
    EXPECT_EQ(result, "a*b-c*d"); // Каждый второй '*' заменяется на '-'
}

// Интеграционный тест для main сценария
TEST(IntegrationTest, CompleteWorkflow) {
    std::string text = "programming";
    int n = 2;
    char old_value = 'm';
    char new_value = 'M';

    bool valid = validation(n, old_value, text);
    EXPECT_FALSE(valid); // Вторая буква 'm' существует

    if (!valid) {
        std::string result = replace(text, n, old_value, new_value);
        EXPECT_EQ(result, "programMing"); // Вторая 'm' заменяется на 'M'
    }
}

int main(int argc, char **argv) {
    ::testing::InitGoogleTest(&argc, argv);
    return RUN_ALL_TESTS();
}

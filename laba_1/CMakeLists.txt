cmake_minimum_required(VERSION 3.10)
project(laba_1)

# Установка стандарта C++
set(CMAKE_CXX_STANDARD 11)
set(CMAKE_CXX_STANDARD_REQUIRED ON)

# Включение тестов
enable_testing()

include_directories(include)

# Добавление исполняемого файла для основной программы
add_executable(main_program
    src/main.cpp
    src/task.cpp
)

# Добавление исполняемого файла для тестов
add_executable(run_tests
    src/test_main.cpp
    src/task.cpp
)

# Настройка Google Test
find_package(GTest REQUIRED)
target_link_libraries(run_tests GTest::GTest GTest::Main)

# Добавление тестов
add_test(NAME ValidationReplaceTests COMMAND run_tests)

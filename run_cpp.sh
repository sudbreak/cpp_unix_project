#!/bin/bash

# Скрипт для сборки и запуска C++ программы

echo "[1] Компиляция C++..."
g++ src/main.cpp -o build/cpp_expr

if [ $? -ne 0 ]; then
  echo " Ошибка компиляции!"
  exit 1
fi

echo "[2] Запуск программы:"
./build/cpp_expr

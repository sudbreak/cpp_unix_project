import time

def calculate_expression(x):
    return x**2 - x**2 + x*4 - x*5 + x + x

def main():
    while True:
        iterations = input("Введите количество итераций (или 'q' для выхода): ")
        if iterations == 'q':
            break

        x_input = input("Введите значение x (или 'q' для выхода): ")
        if x_input == 'q':
            break

        try:
            n = int(iterations)
            x = float(x_input)

            start_time = time.time()

            for _ in range(n):
                calculate_expression(x)

            end_time = time.time()
            print(f"Время выполнения: {end_time - start_time} секунд\n")

        except ValueError:
            print("Ошибка: введено не число. Завершение программы.")
            break

if __name__ == "__main__":
    main()

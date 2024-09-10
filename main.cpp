#include <iostream> // Подключение библиотеки ввода-вывода
#include <vector> // Подключение вектора
int main()
{
    setlocale(LC_ALL, "Russian"); // Русский язык в консоли
    srand(time(0)); // Установка рандомного сида
    int n, m; // Объявление количества строк и столбцов матрицы   
    int start = 32, end = 127; // Диапазон
    std::cout << "Введите количество строк: "; // Ввод количества строк
    std::cin >> n;
    std::cout << "Введите количество столбцов: "; // Ввод количества столбцов
    std::cin >> m;
    std::vector<std::vector <char>> matrix ; // Создание вектора векторов типа char
    std::vector <int> massive_Ans; // Создание вектора с ответом типа int

    for (size_t i = 0;i < n; ++i) { // Цикл заполнения матрицы рандомными элементами
        std::vector<char> line; // Создание временного вектора
        for (int j = 0; j < m; ++j) {
            
            int x = rand() % (end - start + 1) + start;
            line.push_back((char)x); // Добавление элемента х во временный вектор               
        }
        matrix.push_back(line); line.clear(); // Добавление вектора в матрицу и очистка временного вектора
    }

    matrix.reserve(matrix.size()); // Резервирование памяти под матрицу

    for (size_t i = 0; i < n; ++i) { // Цикл на соответствие в строке только цифр 0..9
        int count_Temp = 0;
        int str_Temp = -1;
        for (size_t j = 0;j < m; ++j) {
            if ((int)matrix[i][j] >= 48 && (int)matrix[i][j] <= 57) {
                count_Temp += 1;
                str_Temp = j;
            }
        }

        if (count_Temp == m) {
            massive_Ans.push_back(str_Temp);

        }
    }

    massive_Ans.reserve(massive_Ans.size()); // Резервирование памяти под массив с ответом

    std::cout << std::endl;

    if (massive_Ans.size() != 0) { // Если он непустой, выводим номера строк
        std::cout << "Номера строк, заполненных от 0 до 9: " << std::endl;
        for (size_t i = 0;i < massive_Ans.size();++i) {
            if (massive_Ans[i] >= 0)  std::cout << "Строка номер: " << massive_Ans[i] << std::endl; 
        }
        std::cout << std::endl;
    }
    else {
        std::cout << "Таких строк нет" << std::endl;
    }
    for (size_t i = 0;i < n;++i) { // Выводим матрицу
        std::cout << "Номер строки: " << i << " Содержимое: ";
        for (size_t j = 0; j < m; ++j) {
            std::cout << matrix[i][j] << " ";
        }
        std::cout << " " << std::endl;
    }
    
    std::vector<std::vector<char>>().swap(matrix); // Очистка памяти
    std::vector<int>().swap(massive_Ans);

    system("pause");
    return 0;
}

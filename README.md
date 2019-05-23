Задание 1

Необходимо реализовать функции для работы с односвязным списком:

// инициализация пустого списка

void init(list* l);

//удалить все элементы из списка

void clear(list* l); 

// проверка на пустоту списка

int isEmpty(list* l) 

// поиск элемента по значению. вернуть NULL если элемент не найден

node* find(list* l, int value); 

// вставка значения в конец списка, вернуть 0 если успешно

int push_back(list* l, int value); 

// вставка значения в начало списка, вернуть 0 если успешно

int push_front(list* l, int value); 

// вставка значения после указанного узла, вернуть 0 если успешно

int insertAfter(node* n, int value); 

// удалить первый элемент из списка с указанным значением, вернуть 0 если успешно

int remove(list* l, int value); 

// вывести все значения из списка в прямом порядке, через пробел, после окончания вывода перейти на новую строку

void print(list* l); 

Используя реализованные функции реализовать программу которая:
1. считать количество элементов  ∈ N, 0 < ≤ 2147483647;
2. создать пустой список, считать n элементов a , |a | ≤ 2147483647 и занести их в список;
3. вывести содержимое списка используя функцию print;
4. считать k , k , k |k | ≤ 2147483647 и вывести ‘1’ если в списке существует элемент с таким значением. ‘0’ если нет. перейти на новую строку.
5. считать m, |m| ≤ 2147483647 и вставить его в конец списка;
6. вывести содержимое списка используя функцию print;
7. считать t, |t| ≤ 2147483647 и вставить его в начало списка;
8. вывести содержимое списка используя функцию print;
9. считать j, 0 < j ≤ 2147483647 и x, |x| ≤ 2147483647 и вставить
значение x после j-ого элемента списка;
10. вывести содержимое списка используя функцию print;
11. считать z, |z| ≤ 2147483647 и удалить первый элемент хранящий значение z из списка;
12. вывести содержимое списка используя функцию print;
13. очистить список.
пример входных и выходных данных
input      output
5          1 2 3 2 4
1 2 3 2 4  101
2 5 1      1 2 3 2 4 5
5          7 1 2 3 2 4 5
7          7 1 2 0 3 2 4 5
3 0        7 1 0 3 2 4 5
2

Задание 2

Необходимо реализовать функции для работы с двусвязным списком:

// инициализация пустого списка

void init(list* l);

//удалить все элементы из списка

void clear(list* l);

// проверка на пустоту списка

int isEmpty(list* l)

// поиск элемента по значению. вернуть NULL если элемент не найден

node* find(list* l, int value);

// вставка значения в конец списка, вернуть 0 если успешно

int push_back(list* l, int value);

// вставка значения в начало списка, вернуть 0 если успешно

int push_front(list* l, int value);

// вставка значения после указанного узла, вернуть 0 если успешно

int insertAfter(node* n, int value);

// вставка значения перед указанным узлом, вернуть 0 если успешно

int insertBefore(node* n, int value);

// удалить первый элемент из списка с указанным значением, вернуть 0 если успешно

int removeFirst(list* l, int value);

// удалить последний элемент из списка с указанным значением, вернуть 0 если успешно

int removeLast(list* l, int value);

// вывести все значения из списка в прямом порядке, через пробел, после окончания вывода перейти на новую строку

void print(list* l);

// вывести все значения из списка в обратном порядке, через пробел, после окончания вывода перейти на новую строку

void print_invers(list* l);

Используя реализованные функции реализовать программу которая:
1. считать количество элементов  ∈ N, 0 < ≤ 2147483647;
2. создать пустой список, считать n элементов a , |a | ≤ 2147483647 и занести их в список;
3. вывести содержимое списка используя функцию print;
4. считать k , k , k |k | ≤ 2147483647 и вывести ‘1’ если в списке существует элемент с таким значением. ‘0’ если нет. перейти на новую строку.
5. считать m, |m| ≤ 2147483647 и вставить его в конец списка;
6. вывести содержимое списка используя функцию print_invers;
7. считать t, |t| ≤ 2147483647 и вставить его в начало списка;
8. вывести содержимое списка используя функцию print;
9. считать j, 0 < j ≤ 2147483647 и x, |x| ≤ 2147483647 и вставить значение x после j-ого элемента списка;
10. вывести содержимое списка используя функцию print_invers;
11. считать u, 0 < u ≤ 2147483647 и y, |y| ≤ 2147483647 и вставить значение y перед u-ым элементом списка;
12. вывести содержимое списка используя функцию print;
13. считать z, |z| ≤ 2147483647 и удалить первый элемент хранящий значение z из списка;
14. вывести содержимое списка используя функцию print_invers;
15. считать r, |r| ≤ 2147483647 и удалить последний элемент хранящий значение r из списка;
16. вывести содержимое списка используя функцию print;
17. очистить список.
пример входных и выходных данных
input        output
5            1 2 3 2 4
1 2 3 2 4    101
2 5 1        1 4 2 3 2 1
1            7 1 2 3 2 4 1
7            1 4 2 3 0 2 1 7
3 0          7 1 2 0 8 3 2 4 1
5 8          1 4 2 3 8 0 1 7
2            7 1 0 8 3 2 4
1

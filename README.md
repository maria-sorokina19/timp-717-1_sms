Задание 1

Необходимо реализовать структуры данных и функции для работы с бинарным деревом поиска:

/* структура для хранения узла дерева. Необходимо хранить
ссылки на потомков, предка и некоторое значение (целое число) */

struct node;
/* структура для хранения дерева. хранит ссылку на корень
дерева и количество элементов в дереве */
struct tree;

// инициализация пустого дерева

void init(tree* t);

//удалить все элементы из дерева

void clear(tree* t);

/* поиск элемента по значению. вернуть 0 если элемент найд
ен и ссылку на найденнйы элемент в переменную n если n !=
NULL. в случае если элемент не найден вернуть 1
*/

int find(tree* t, int value, node* n);

/* вставка значения в дерево. вернуть 0 если вставка выпол
нена успешна,
1 если элемент уже существует
2 если не удалось выделить память для нового элемента*/

int insert(tree* t, int value);

/* удалить элемент из дерева. вернуть 0 если элемент был у
дален и 1 если нет элемента с указанным значением */

int remove(tree* t, int value);

/* удалить минимальный элемент из поддерева, корнем которо
го является n. вернуть значение удаленного элемента */

int removeMin(node* n);

/* выполнить правое вращение поддерева, корнем которого яв
ляется n. вернуть 0 при успещшно выполнение операции и 1 в
случае если вращение невозможно */

int rotateRight(node *n);

/* выполнить левое вращение поддерева, корнем которого явл
яется n. вернуть 0 при успещшно выполнение операции и 1 в
случае если вращение невозможно */

int rotateLeft(node *n);

// вывести все значения из поддерева корнем которого являе
тся n по уровнем, начиная с корня. каждый уровень выводитс
я на своей строке. элементы в строке разделяются пробелом.
если на указанном месте нет элемента, заменить его значен
ием '_'. Если дерево пусто вывести '-'

void print(node* n);

// вывести все значения дерева t, аналогично функции print

void printTree(tree* t);

Используя реализованные функции реализовать программу которая:
1. создать пустое дерево, считать 4 элементов a , |a | ≤
2147483647 и занести их в дерево;
2. вывести дерево используя функцию printTree;
input output
2 1 3 2 2
1 3
3. считать 3 элементов a , |a | ≤ 2147483647 и занести их в
дерево;
4. вывести дерево используя функцию printTree;
input output
0 4 5 2
1 3
i i
i i
0 _ _ 4
_ _ _ _ _ _ _ 5
5. считать m , |m | ≤ 2147483647 и найти элемент с заданным
значением в дереве. вывести через пробел значение предка
и потомков найденного элемента. если элемент не найден,
вывести "_", если нет значений предка или потомков вывести
’’ вместо таких значений.
input output
3 2 _ 4
6. считать m , |m | ≤ 2147483647 и найти элемент с заданным
значением в дереве. вывести через пробел значение предка
и потомков найденного элемента. если элемент не найден,
вывести ‘-’, если нет значений предка или потомков вывести
‘_’ вместо таких значений.
input output
6 -
7. считать m , |m | ≤ 2147483647 и удалить из дерева элемент с
заданным значением
8. вывести деревео используя printTree
input output
2 3
1 1
2 2
3 3
1 4
0 _ _ 5
9. выполнять левый поворот дерева относительно корня, пока
это возможно.
10. вывести дерево используя команду printTree
input output
5
4 _
3 _ _ _
1 _ _ _ _ _ _ _
0 _ _ _ _ _ _ _ _ _ _ _ _ _ _ _
11. выполнять правый поворот дерева относительно корня, пока
это возможно.
12. вывести дерево используя команду printTree
input output
0
_ 1
_ _ _ 3
_ _ _ _ _ _ _ 4
_ _ _ _ _ _ _ _ _ _ _ _ _ _ _ 5
13. вывести на экран количество элементов в дереве
14. очистить дерево
15. вывести дерево на экран используя printTree
итого входные и выходные данные должны выглядить следующим
образом
input output
2 1 3 2 2
0 4 5 1 3
3 2
6 1 3
2 0 _ _ 4
_ _ _ _ _ _ _ 5
2 _ 4
-
3
1 4
0 _ _ 5
5
4 _
3 _ _ _
1 _ _ _ _ _ _ _
0 _ _ _ _ _ _ _ _ _ _ _ _ _ _ _
0
_ 1
_ _ _ 3
_ _ _ _ _ _ _ 4
_ _ _ _ _ _ _ _ _ _ _ _ _ _ _ 5
5
-

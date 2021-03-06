# Лабораторная работа №9. Поиск кратчайших путей в графе #
## Задание ##
Задан взвешенный ориентированный граф, состоящий из n вершин и m ребер. Вершины пронумерованы целыми числами от 1 до n.
Необходимо найти длины кратчайших путей между всеми парами вершин при помощи алгоритма Джонсона. Длина пути равна сумме весов ребер на этом пути.
Обратите внимание, что в данном варианте веса ребер могут быть отрицательными, поскольку алгоритм умеет с ними работать. Граф не содержит петель и кратных ребер.
## Пример ##
### Входные данные ###
В первой строке заданы 1 ≤ n ≤ 2000, 1 ≤ m ≤ 4000. В следующих m строках записаны ребра. Каждая строка содержит три числа – номера вершин, соединенных ребром,
и вес данного ребра. Вес ребра – целое число <img src="https://render.githubusercontent.com/render/math?math=\pm 10^9"> .

```
5 4
1 2 -1
2 3 2
1 4 -5
3 1 1
```

### Результат работы ###
Если граф содержит цикл отрицательного веса, следует вывести строку "Negative cycle". В противном случае следует вывести матрицу из n строк и n столбцов,
где j-e число в i-й строке равно длине кратчайшего пути из вершины i в вершину j. Если такого пути не существует, на соответствующей позиции
должно стоять слово "inf".
```
0 -1 1 -5 inf
3 0 2 -2 inf
1 0 0 -4 inf
inf inf inf 0 inf
inf inf inf inf 0
```

# DFS, BFS

## Depth-First Search(DFS)

- inorder, preorder, postorder 방식
- 부모노드부터 형제 노드들을 끝까지 탐색
- 한 방향으로 갈 수 있을 때까지 가다가 더 이상 갈 수 없게 되면 가장 가까운 갈림길로 돌아와서, 그 갈림길의 다른 방향으로 다시 탐색을 진행한다
- Stack을 이용하여 구현  → 갈림길로 돌아가기 위해
- 재귀함수(Recursion)을 사용하면 Stack을 이용하는 것보다 빠르다

## Bridth-First Search(BFS)

- 시작 노드으로부터 가까운 노드부터 먼저 방문하고, 멀리 떨어져 있는 노드을 나중에 방문한다
- Queue를 이용해서 구현 → 노드를 차례대로 저장한 후 꺼내기 때문에

## BFS 문제
### [숫자판 점프](https://github.com/sunnyineverywhere/Cpp/blob/main/E-PPER/BOJ2210.cpp)


## 트리 (Tree)
> 계층적인 자료를 표현하기 위한 비선형 자료구조

#### 트리 용어
 <img width="344" alt="Untitled" src="https://user-images.githubusercontent.com/101935265/169186058-f61b231e-253e-47d3-960d-fcac75bcf4a1.png">

1. 노드 : 트리의 기본 요소
	*위 트리의 A, B, C 등을 의미
```C
//예시
typedef struct TreeNodeType
{
	char data;
	struct TreeNodeType* pLeftChild;
	struct TreeNodeType* pRightChild;
} TreeNode;
```
* 루트노드(root) : 트리에서 가장 높은 곳에 있는 노드(A)
	* 트리 {B, E, F}의 루트노드는 (B)이다
* 부모노드(parent), 자식노드(children), 형제노드(sibling)
	* 노드(B)의 부모노드는 노드(A)
	* 노드(A)의 자식노드는 {B, C, D}이다
	* 노드(B)의 형제노드는 {C, D}이다
* 조상노드(ancester node), 후손노드(descendent node)
	* 조상노드 : 어떤노드의 부모노드부터 루트노드까지를 포함하는 노드
	* 후손노드 : 어떤노드의 하위에 연결된 모든 노드
* 단말노드(terminal node 또는 leaf node) : 자식노드가 없는 노드
2. 서브 트리 : 루트노드를 제외한 나머지 노드들의 집합
	* 트리의 {A, B, C, D, E, F, G, H, I}중에 루트노드(A)를 제외한 {B, E, F}/{C, G}/{H, I} 각각이 서브 트리가 된다
3. 간선(edge) : 루트노드와 서브트리를 연결하는 선
4. 차수(degree) : 어떤노드가 가지는 자식노드의 개수
	* 루트노드(A)의 차수 : 3
5. 레벨(level) : 정의에 의해 트리의 각 층 정해진 번호
	* 루트노드(A)의 레벨이 1일때, 자식노드(B)의 레벨은 2가 된다
6. 높이(height) : 트리가 갖는 최대 레벨
	* 위 트리의 최대 레벨은 노드(E)와 형제노드가 갖는 3이므로 높이는 3이다
7. 포리스트(forest) : 트리들의 집합

## 이진트리(Binary Tree)

> 모든 노드가 2개의 서브 트리를 갖는 트리(서브트리는 공집합일 수 있다 => 공집합도 이진트리)
* 모든 노드의 차수가 '2'이하인 트리
* 모든 노드가 2개 이하의 자식노드를 갖는 트리
* 서브 트리간의 순서가 존재하고 왼쪽 서브 트리와 오른쪽 서브 트리가 구분된다
> 순환적인 정의를 갖는다
1. 공집합 또는
2. 루트, 왼쪽 서브 트리, 오른쪽 서브 트리로 구성된 노드들의 유한집합

#### 이진트리의 분류
1. 포화 이진트리(full binary tree)
* 트리의 각 레벨에 노드가 꽉 차있는 이진트리
 <img width="365" alt="Untitled 2 copy" src="https://user-images.githubusercontent.com/101935265/169186250-1a2d0aad-4003-4f24-ac0f-15eea42d3d8a.png">

2. 완전 이진트리(complete binary tree)
* 높이가 h일때, h-1까지는 포화 이진트리이고 마지막 레벨 h에서는 왼쪽부터 오른쪽으로 노드가 순서대로 채워진 트리
 <img width="452" alt="Untitled 2 copy 2" src="https://user-images.githubusercontent.com/101935265/169186211-2974c3bc-a96a-4637-b582-49c841197e4d.png">

3. 기타 이진트리
 <img width="409" alt="Untitled 2" src="https://user-images.githubusercontent.com/101935265/169186149-74ccdea6-e433-4029-b6f6-830aae0ba55b.png">

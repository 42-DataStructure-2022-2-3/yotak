## Heap

### 우선순위 큐
> 데이터들이 우선 순위를 가지고 있고, 우선 순위가 높은 데이터가 먼저 나가도록 구현한 큐
* 컴퓨터의 여러 분야에서 사용된다. 시뮬레이션, 운영 체제 작업 스케줄링 등
* 우선순위 큐의 가장 효율적인 구조는 히프(Heap)이다

### 히프
> 완전 이진 트리의 일종으로 여러 개의 값들 중에서 최대값 혹은 최소값을 가장 빠르게 찾아내도록 만들어진 자료구조
* 우선순위 큐를 위해 만들어진 자료구조라고 할 수 있다
* 값의 중복을 허용
* 효율은 O(log 2n) // 로그의 밑이 2, 진수가 n

[트리 설명](https://github.com/42-DataStructure-2022-2-3/yotak/tree/main/04Tree/BinaryTree#readme)

#### 히프의 종류
1. 최대 히프(Max Heap)
<img width="300" alt="Untitled 5 copy" src="https://user-images.githubusercontent.com/101935265/169931254-db0e44ff-32e0-4bc9-a940-2dc78d984fbb.png">

* 루트노드의 키값이 트리의 최대값
* 부모 노드.key >= 자식 노드.key

2. 최소 히프(Min Heap)
<img width="300" alt="Untitled 5" src="https://user-images.githubusercontent.com/101935265/169931282-eed99b3e-61d9-406a-9838-7251d3e7be01.png">

* 루트노드의 키값이 트리의 최소값
* 부모 노드.key <= 자식 노드.key

#### 히프의 구현
* 완전 이진트리이기 때문에 차례대로 인덱스를 붙여 배열로 표현할 수 있다
<img width="330" alt="Screen Shot 2022-05-24 at 10 49 01 AM" src="https://user-images.githubusercontent.com/101935265/169932275-78efa100-954a-4d10-93e1-ea3a8fc035ab.png">
<img width="350" alt="Screen Shot 2022-05-24 at 10 44 48 AM" src="https://user-images.githubusercontent.com/101935265/169932292-acf0cc9c-e1d3-4f23-9828-7794b8e0a8ed.png">

 > 시작 인덱스가 1인 이유는 구현을 쉽게할 수 있기 때문이다
* 인덱스로 노드 접근하기
  - 왼쪽 자식 인덱스 = (부모 노드 인덱스) * 2
  - 오른쪽 자식 인덱스 = (부모 노드 인덱스) * 2 + 1
  - 부모 노드 인덱스 = (자식 노드 인덱스) / 2

* 추상 자료형(최대 히프)
```
객체 : n개의 노드로 구성된 완전 이진트리로 각 노드의 키값이 자식 노드의 키값보다 크거나 같다
연산 :
    makeHeap(max) ::= max개의 요소를 갖는 배열을 생성한다
    getRootNode(p) ::= p가 가리키는 히프의 루트노드를 반환한다
    insertMaxHeap(p, element) ::= p가 가리키는 히프에 element요소를 추가한다
    deleteMaxHeap(p) ::= p가 가리키는 히프의 루트 노드를 삭제한다
``` 







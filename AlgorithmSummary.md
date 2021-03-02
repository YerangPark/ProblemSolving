# 알고리즘
생성일: Jan 13, 2021 12:40 AM
태그: #공부/algorithm , #공부/C++

[안경잡이개발자 : 네이버 블로그](https://blog.naver.com/ndb796/221226794899)
- - - -
#### <details><summary>🪄 목차</summary>
<p>
	
1. 선택 정렬
2. 버블 정렬
3. 삽입 정렬
4. 퀵 정렬
5. 병합 정렬
6. C++ STL sort(), 큐, 스택
7. 힙 정렬
8. 계수 정렬
9. 심화 정렬 문제 풀이
10. 스택
11. 큐
12. 너비 우선 탐색(BFS)
13. 깊이 우선 탐색(DFS)
14. Union-Find(합집합 찾기)
15. 크루스칼 알고리즘(Kruskal Algorithm)
16. 이진 트리의 구현 및 순회(Traversal)
17. 다이나믹 프로그래밍(Dynamic Programming)
18. 에라토스테네스의 체
19. 플로이드 와샬(Floyd Warshall) 알고리즘
20. 위상 정렬(Topology Sort)
21. 강한 결합 요소
22. 네트워크 플로우
23. 위상 정렬 기초 문제풀이
24. 이분 매칭(Pipartite Matching)
25. KMP(Knuth-Morris-Pratt) 알고리즘
26. 라빈 카프 알고리즘
27. 이분 매칭 기초 문제풀이
28. 강한 결합 요소 기초 문제풀이
29. 그리디(Greedy) 알고리즘
30. 구글 코드 잼 2018에서 살펴보는 기초 그리디 문제
31. 에라토스테네스의 체 기초 문제풀이
32. 분할 정복 기초 문제풀이
33. 이분 탐색(Binary Search)
34. 세그먼트 트리
35. 최소 공통 조상
36. 깃허브로 알고리즘 정답 소스코드 관리하기
37. 인덱스 트리
38. 비트 마스크

</details>
</p>
- - - -
[[알고리즘 한 문장 정리]]
- - - -
## 선택 정렬 O(n^2)
- 배열 0항부터 차례로 순회하면서 우측 항 중 최솟값을 찾아서 탐색 위치(기준 위치)와 변경
* 배열의 자리를 차례대로 탐색하며 우측의 최솟값을 찾아서 탐색 위치와 변경.
```cpp
//review
int main() {
    int arr[4]={5,4,2,3};
    int i,j,len=sizeof(arr)/sizeof(int),min=1000,minIndex;

    for(i=0;i<len-1;i++){
        minIndex=i;
        min=arr[i];
        for(j=i+1;j<len;j++){
            if(min>arr[j]){
                minIndex=j;
                min=arr[j];
            }
        }
        int tmp=arr[minIndex];
        arr[minIndex]=arr[i];
        arr[i]=tmp;
    }
    
    for(i=0;i<len;i++){
        printf("%d ",arr[i]);
    }
    
    return 0;
}
```

```cpp
int i=0,j=0,min=0,index=0,temp=0;
int array[10]={1, 10, 5, 8, 7, 6, 4, 3, 2, 9};
for(i=0;i<10;i++){
    min=9999;
    for(j=i;j<10;j++){
        if(min>array[j]){
            min=array[j];
            index=j;
        }
    }
    temp=array[i];
    array[i]=array[index];
    array[index]=temp;
}
for(i=0;i<10;i++){
    printf("%d ", array[i]);
}
return 0;
```

- - - -
## 버블 정렬 O(n^# 2)

* 2항을 비교하여 크면 우측으로 자리 이동을 반복.
* 최댓값이 차례대로 우측에 쌓이는 형식!
```cpp //review
int main() {
    int arr[4]={5,4,2,3};
    int i,j,len=sizeof(arr)/sizeof(int);

    for(i=0;i<len;i++){
        for(j=0;j+1<len-i;j++){
            if(arr[j]>arr[j+1]){
                int tmp=arr[j];
                arr[j]=arr[j+1];
                arr[j+1]=tmp;
            }
        }
    }
    for(i=0;i<len;i++){
        printf("%d ",arr[i]);
    }
    return 0;
}
```

```cpp
    int i=0,j=0,temp=0;
    int array[10]={1,10,5,8,7,6,4,3,2,9};
    for(i=0;i=10;i++){
        for(j=0;j<9-i;j++){
            if(array[j]>array[j+1]){
                temp=array[j];
                array[j]=array[j+1];
                array[j+1]=temp;
            }
        }
    }
```

- - - -
## 삽입 정렬 O(n^2)

* 데이터가 이미 거의 정렬된 상태이면 어떤 알고리즘보다 빠름.
* 범위를 점차 넓혀가며 왼쪽으로 최솟값을 모는 형태. (1씩 증가하는 `key(i)`의 좌측에 있는 항을 정렬)

```cpp
    int i=0,j=0,temp=0;
    int array[10]={1, 10, 5, 8, 7, 6, 4, 3, 2, 9};
    for(i=0;i<10;i++){
        j=i;
        while(j>=0 && array[j]>array[j+1]){
            temp=array[j];
            array[j]=array[j+1];
            array[j+1]=temp;
            j--;
        }
    }
    for(i=0;i<10;i++){
        printf("%d ",array[i]);
    }
    return 0;
```

- - - -
## 퀵 정렬 O(n*log n)
[알고리즘 퀵 정렬(quick sort)이란 - Heee’s Development Blog](https://gmlwjd9405.github.io/2018/05/10/algorithm-quick-sort.html)
- **분할 정복 알고리즘** 중 하나.
(분할 정복(divide and conquer): 문제를 작은 2개의 문제로 분리하고, 각각을 해결한 다음 결과를 모아서 원래의 문제를 해결하는 방법. 대개 순환 호출을 이용하여 구현)
* 특정한 값(피벗, 보통 첫 번째 원소)을 기준으로 큰 숫자와 작은 숫자를 서로교환한 뒤에 배열을 반으로 나눔.
* C++에서 제공해주는 `<algorithm>` 라이브러리의 `sort()`함수를 이용하면 편함.
(최악의 경우에서도 O(n*logn)을 보장.)

```cpp
int number=10;
int data[10]={5,3,10,8,1,4,9,2,6,7};
    
//퀵정렬은 부분 리스트를 정렬하기에 각 리스트들의 시작 인덱스와 끝 인덱스가 식별되어야 하므로 매개변수로 받음.
void quickSort(int *data, int start, int end){
    int temp=0;
    //원소가 1개인 경우
    if(start>=end){
        return;
    }
    int key=start;  //key는 첫 번째 원소.
    int i=start+1;  //순방향으로 key보다 큰 값 찾기.
    int j=end;      //역방향으로 key보다 작은 값 찾기.
    
    while(i<=j){    //탐색하다가 i와 j가 엇갈릴 때 까지 반복.
        //내림차순으로 변경하고 싶을 때는 아래 와일문의 부등호를 반대로 바꿔주면 됨.
        
        //키 값보다 큰 값을 만날 때까지 오른쪽으로 이동.
        while(data[i]<=data[key]){
            i++;
        }
        //키 값보다 작은 값을 만날 때까지 왼쪽으로 이동.(단 범위 엇나감 방지를 위해 조건 추가)
        while(data[j]>=data[key] && j>start){
            j--;
        }
        
        //엇갈린 상태이면 j와 키 값 교체.
        if(i>j){
            temp=data[j];
            data[j]=data[key];
            data[key]=temp;
        }else{ //엇갈리지 않았으면 찾은 i와 j 교체.
            temp=data[j];
            data[j]=data[i];
            data[i]=temp;
        }
    }
    quickSort(data,start,j-1); //왼쪽 파티션
    quickSort(data, j+1, end); //오른쪽 파티션
}
```

- - - -
## 병합 정렬 O(n*logn)
동빈나 선생님이 잠깐 건너뛴다고 하셨다.

- - - -
### STL 관련 링크
[[C++ STL 개념 정리]]
STL정리는 하단 링크 참고!
* [내역 정리](https://velog.io/@choiiis/C-STL)
* [자주쓰이는 것 정리](https://eehoeskrap.tistory.com/246) 
* [사용법 정리](https://baactree.tistory.com/29)
* [꼼꼼 정리(어디에 뭘 써야할까?)](https://code-algalon.tistory.com/188)
- - - -
## C++ STL sort()
- 헤더: `#include <algorithm>`
- `sort(시작주소, 끝주소);`
- 기본적으로 오름차순 정렬
- 내림차순 정렬하려면 사용자 정의함수(bool compare()) 만들어서  구현
-> 혹은,  세번째 인자에 `greater<>()` 입력해도 됨!(임시 객체)

### 오름차순 정렬 예시

```cpp
int a[10]={9,3,5,4,1,10,8,6,7,2};
sort(a, a+10); //a배열의 0번째 인덱스부터 9번 인덱스까지 정렬
```

### 내림차순 정렬 예시

* 함수 이용 정렬, 왼쪽이 더 큰 수가 오도록 정렬.

```cpp
bool compare(int a, int b){
return a>b;
}
int a[10]={9,3,5,4,1,10,8,6,7,2};
sort(a, a+10, compare);
```

> 실무에서는 클래스 형태를 이용한다.  
> 하지만 코테에서는 클래스를 이용하면 비효율적이라서 `pair` 라이브러리를 사용함.  

## pair
* `pair`는 `iostream`, `vector`, `algorithm` 라이브러리 포함해야 함.
* 벡터 STL은 마치 배열과 같이 작동하는데 원소를 선택적으로 삽입, 삭제할 수 있음! 배열을 보다 사용하기 쉽게 개편한 자료구조라고 할 수 있다. 
```cpp
int main(){
    vector<pair<int, string>> v;
    v. push_back(pair<int, string>(90, "박예랑"));
    v. push_back(pair<int, string>(100, "박예롱"));
    v. push_back(pair<int, string>(99, "박예똥"));
    
    sort(v.begin(), v.end());
    for(int i=0;i<v.size();i++){
        cout<<v[i].second<<' ';
    }
    return 0;
}
```

예제
```cpp
#include <iostream>
#include <algorithm>
#include <vector>
using namespace std;

//성적에 따라 정렬한 뒤 성적이 같으면 나이가 어린 사람이 먼저 출력되게 만들어라.
bool compare(pair<string, pair<int, int>> a,
             pair<string, pair<int, int>> b){
    //왼쪽과 오른쪽의 점수가 같으면
    if(a.second.first == b.second.first){
        //나이가 어린 사람(늦게 태어난 사람)순으로 오름차순 정렬
        return a.second.second>b.second.second;
    } else {
        //점수가 다르면 just 점수 순으로 오름차순 정렬(왼쪽에 큰 것이 오도록)
        return a.second.first > b.second.first;
    }
}

int main() {
    vector<pair<string,pair<int, int>>> v;
    v.push_back(pair<string,pair<int, int>>("박예랑",make_pair(90,19980407)));
    v.push_back(pair<string,pair<int, int>>("나동빈",make_pair(90,19980304)));
    v.push_back(pair<string,pair<int, int>>("이태일",make_pair(87,19660216)));
    v.push_back(pair<string,pair<int, int>>("김상욱",make_pair(80,19771223)));
    v.push_back(pair<string,pair<int, int>>("강종구",make_pair(82,19550712)));
    
    sort(v.begin(), v.end(), compare);
    
    for(int i=0;i<v.size();i++){
        cout<<v[i].first<<' ';
    }
    return 0;
}
```

- - - -
## STL 라이브러리 문법 (큐, 스택)

### 큐

```cpp
#include <queue>
int main(void){
    queue<int> q;
    q.push(1);
    q.push(2);
    q.pop();
    while(!q.empty()){
        cout<<q.front()<<' ';
        q.pop();
    }
    reutrn 0;
}
```

### 스택

```cpp
#include <stack>
int main(void){
    stack<int> s;
    s.push(1);
    s.push(2);
    s.pop();
    while(!s.empty()){
        cout<<s.top()<<' ';
        s.pop();
    }
    return 0;
}
```

- - - -
## 힙 정렬 O(n*logn)

* 힙정렬은 병합정렬과 퀵정렬만큼 빠른 정렬 알고리즘.
* 힙 트리 구조를 이용하기에 힙에 대해 배울 필요가 있음.
![](AlgorithmSummary/%E1%84%89%E1%85%B3%E1%84%8F%E1%85%B3%E1%84%85%E1%85%B5%E1%86%AB%E1%84%89%E1%85%A3%E1%86%BA%202021-02-15%20%E1%84%8B%E1%85%A9%E1%84%92%E1%85%AE%203.10.36.png)
- 힙에는 최대 힙과 최소 힙이 존재함. 
	- **최대 힙**은 부모 노드가 자식 노드보다 큰 힙.

하지만 이러한 힙이 붕괴되는 경우가 있는데, 아래와 같은 경우 초록색 박스 노드는 최대 힙이 구성되어지지 않는다.
![](AlgorithmSummary/%E1%84%89%E1%85%B3%E1%84%8F%E1%85%B3%E1%84%85%E1%85%B5%E1%86%AB%E1%84%89%E1%85%A3%E1%86%BA%202021-02-15%20%E1%84%8B%E1%85%A9%E1%84%92%E1%85%AE%203.17.09.png)
힙 정렬을 수행하기 위해서는 힙 생성 알고리즘(Heapify Algorithm)을 이용한다. 힙 생성 알고리즘은 특정한 ‘하나의 노드’에 대해서 수행하는 것. 
또한 해당 ‘하나의 노드를 제외하고는 최대 힙이 구성되어 있는 상태’라고 가정을 한다는 특징이 있다.
	- **힙 생성 알고리즘**:  ~특정 노드의 두 자식 중에서 더 큰 자식과 자신의 위치를 바꾸는 알고리즘~
	또한 바꾼 뒤에도 여전히 자식이 존재하는 경우 또 자식 중에서 더 큰 자식과 자신의 위치를 바꿔야 한다.
	- 과정 : 5 / (7, 4) -> 7 / (5, 4)

- 히피파이를 상향식/하향식으로 구현할 수 있음.

**히피파이로 정렬은 어떻게 하나요?**
최상위 부모노드(루트 노드)에는 무조건 해당 트리에서 가장 큰 값이 존재하기 때문에, 해당 값을 트리의 마지막 원소와 자리를 바꾼다.
-> 이어서, 마지막 원소를 제외한 배열에서 히피파이를 통해 루트 노드에 최댓값이 오게 되고, 해당 최댓값을 집합의 마지막 원소와 자리 바꾼다. (사실은 마지막-1)
(재귀… 또 재귀…)

`구현`
```cpp
#include <stdio.h>

int number = 9;
int heap[9] = {7, 6, 5, 8, 3, 5, 9, 1, 6};

int main(void) {
    // 힙을 구성
    //점점 영역을 넓혀가며 최대 힙을 구현함. 상향식.
    for(int i = 1; i < number; i++) {
        int c = i;
        do {
            //배열에서 자식노드로 부모노드 찾는 공식
            int root = (c - 1) / 2;
            //자식노드가 부모노드보다 값이 크면 교체
            if(heap[root] < heap[c]) {
                int temp = heap[root];
                heap[root] = heap[c];
                heap[c] = temp;
            }
            c = root;  //위쪽까지 다 검사하기 위해서 현 부모노드를 자식으로 취하는 새 부모노드와 또 검사.
        } while (c != 0);
        //부모노드까지 최대 힙이 될 때까지 반복. 부모노드가 최댓값이 되면 종료.
    }
    
    // 크기를 줄여가며 반복적으로 힙을 구성
    // i값이 감소하면서 배열 끝에서부터 차례대로 큰 값으로 바뀜.
    for (int i = number - 1; i >= 0; i--) {
        //루트 노드(최상위 노드)가 무조건 최대값이므로 마지막으로 밀어냄.(자리 교환)
        int temp = heap[0];
        heap[0] = heap[i];
        heap[i] = temp;
        int root = 0;
        int c = 1;
        //이제 다시 최대힙을 구현하기 위해서 대장정...
        do {
            //자식 찾는 공식~
            c = 2 * root + 1;
            // 자식 중에 더 큰 값을 찾기
            if(c < i - 1 && heap[c] < heap[c + 1]) {
                c++;
            }
            // 루트보다 자식이 크다면 교환
            if(c < i && heap[root] < heap[c]) {
                temp = heap[root];
                heap[root] = heap[c];
                heap[c] = temp;
            }
            root = c;
        } while (c < i);
    }
    
    // 결과 출력
    for(int i = 0; i < number; i++) {
        printf("%d ", heap[i]);
    }
}
```
- 상향식 : [동빈나](https://youtu.be/iyl9bfp_8ag), [Zeddi](https://www.youtube.com/watch?v=aOP81IhPOmw)


- - - -
## 계수 정렬(Counting Sort)
- 데이터가 a~b 사이에 속한다는 특징이 있을 때, ‘범위 조건’이 있는 경우에 한해서 굉장히 빠른 O(n)의 속도를 가지는 알고리즘.
- 방법은? 단순히 크기를 기준으로 세면 됨!

ex) 1, 3, 2, 4, 3, 5 데이터를 정렬해라
	-> 1: 1개 / 2: 1개 / 3: 2개 / 4: 1개 / 5: 1개
결과 : 1, 2, 3, 3, 4, 5
```cpp
#include <iostream>

int main(){
    int count[6]={0,};
    int array[30] = {
        1,3,2,4,3,2,5,3,1,2,
        3,4,4,3,5,1,2,3,5,2,
        3,1,4,3,5,1,2,1,1,1};
        
    for(int i=1;i<=5;i++){
        count[i]=0;
    }
    for(int i=0;i<30;i++){
        count[array[i]]++;
    }
    for(int i=1;i<6;i++){
        printf("%d: %d개\n",i,count[i]);
        if(count[i]!=0){
            for(int j=0;j<count[i];j++){
                printf("%d\n", i);
            }
        }
        
    }
    return 0;
}
```

- - - -
## 심화 정렬 문제 풀이
- - - -
## 스택
```cpp
#include <iostream>
#include <stack>

using namespace std;

int main(void) {
	stack<int> s;
	s.push(7);
	s.push(5);
	s.push(4);
	s.pop();
	s.push(6);
	s.pop();
	while(!s.empty()) {
		cout << s.top() << ‘ ‘;
		s.pop();
	}
	return 0;
}
```
- - - -
## 큐
```cpp
#include <iostream>
#include <queue>

using namespace std;

int main(void) {
	queue<int> q;
	q.push(7);
	q.push(5);
	q.push(4);
	q.pop();
	q.push(6);
	q.pop();
	while(!q.empty()) {
		cout << q.front() << ‘ ‘;
		q.pop();
	}
	return 0;
}
```
- - - -
## 너비 우선 탐색(BFS)
- 너비를 우선으로 하여 탐색을 수행하는 탐색 알고리즘.
- 맹목적인 탐색을 하고자 할때 사용.
- ~최단 경로~를 찾아준다는 점에서 최단 길이를 보장해야 할 때 많이 사용!
- ~큐~를 이용해 구현.
```cpp
void bfs(int start){
    queue<int> q;
    q.push(start);
    c[start]=true;
    while(!q.empty()){
        int x = q.front();
        q.pop();
        printf("%d ", x);
        for(int i=0;i<a[x].size();i++){
            int y=a[x][i];
            if(!c[y]){
                q.push(y);
                c[y]=true;
            }
        }
    }
}
```

- - - -
## 깊이 우선 탐색(DFS)
- 깊은 것을 우선으로 하여 탐색.
- 맹목적으로 각 노드를 전체적으로 탐색할 때 
```cpp
void dfs(int x){
    if(c[x]) return;
    c[x]=true;
    cout<<x<<' ';
    for(int i=0;i<a[x].size();i++){
        int y = a[x][i];
        dfs(y);
    }
}
```

- - - -
## 합집합 찾기(Union-Find)
- 대표적인 그래프 알고리즘 중 하나.
- 서로소 집합(Disjoint-Set) 알고리즘이라고도 불림.
- 여러 개의 노드가 존재할 때, 두 개의 노드를 선택해서 현재 이 두 노드가 서로 같은 그래프에 속하는지를 판별하는 알고리즘.
- (3)-(2)-(1)로 연결되어있을 때, 노드 3과 노드 1이 연결되어 있는지(같은 그래프에 속해있는지) 알아보려면 3의 부모를 재귀적으로 탐색하면서 1이 있는지 찾아보아야 함. (Union-Find)

``` cpp
#include <stdio.h>
//부모노드를 찾는 함수
int getParent(int parent[], int x){
    if(parent[x]==x) return x;
    return parent[x]=getParent(parent,parent[x]);
}
//두 부모 노드를 합치는 함수. (작은 값으로 부모 합침.)
void unionParent(int parent[], int a, int b){
    a=getParent(parent,a);
    b=getParent(parent,b);
    if(a<b) parent[b]=a;
    else parent[a]=b;
}
//같은 부모를 가지는지 확인하는 함수
int findParent(int parent[], int a, int b){
    a=getParent(parent,a);
    b=getParent(parent,b);
    if(a==b) return 1;
    return 0;
}
int main(void){
    int parent[11];
    for(int i=1;i<=10;i++){
        parent[i]=i;
    }
    unionParent(parent,1,2);
    unionParent(parent,2,3);
    unionParent(parent,3,4);
    unionParent(parent,5,6);
    unionParent(parent,6,7);
    unionParent(parent,7,8);
    
    printf("1과 5는 연결되어 있나요? %d\n",findParent(parent,1,5));
    unionParent(parent,1,5);
    printf("1과 5는 연결되어 있나요? %d\n",findParent(parent,1,5));
    
    printf("7과 9는 연결되어 있나요? %d\n",findParent(parent,7,9));
    unionParent(parent,8,9);
    printf("7과 9는 연결되어 있나요? %d\n",findParent(parent,7,9));
}
```

- - - -
## 크루스칼 알고리즘(Kruskal Algorithm)
[안경잡이개발자 : 네이버 블로그](https://blog.naver.com/ndb796/221230994142)
- 가장 적은 비용으로 모든 노드를 연결하기 위해 사용하는 알고리즘.
(최소 비용 신장 트리를 만들기 위한 대표적 알고리즘)

- **용어 정리**
	- 노드=정점=도시 : 그래프에서 동그라미
	- 간선=거리=비용 : 그래프에서 선
- 간선 숫자 = 노드 숫자 -1
-> 주의할 점 : 싸이클이 형성되지 않도록 조심하기!

**<알고리즘>**
1. (비용 낮은 순으로) 정렬된 순서에 맞게 그래프에 포함
2. 포함시키기 전에는 사이클 테이블을 확인
3. 사이클을 형성하는 경우에는 간선을 포함하지 않음.
(사이클은 Union-Find알고리즘을 적용해서 찾기!)

```cpp
#include <vector>
// 부모 노드를 가져옴
int getParent(int set[], int x) {
    if(set[x] == x) return x;
    return set[x] = getParent(set, set[x]);
}
// 부모 노드를 병합
void unionParent(int set[], int a, int b) {
    a = getParent(set, a);
    b = getParent(set, b);
    // 더 숫자가 작은 부모로 병합
    if(a < b) set[b] = a;
    else set[a] = b;
}
// 같은 부모를 가지는지 확인
int find(int set[], int a, int b) {
    a = getParent(set, a);
    b = getParent(set, b);
    if(a == b) return 1;
    else return 0;
}
// 간선 클래스 선언
class Edge {
public:
    int node[2];
    int distance;
    Edge(int a, int b, int distance) {
        this->node[0] = a;
        this->node[1] = b;
        this->distance = distance;
    }
    bool operator <(const Edge &edge) const {
        return this->distance < edge.distance;
    }
};

int main(void) {
    const int n = 7;
    
    vector<Edge> v;
    v.push_back(Edge(1, 7, 12));
    v.push_back(Edge(1, 4, 28));
    v.push_back(Edge(1, 2, 67));
    v.push_back(Edge(1, 5, 17));
    v.push_back(Edge(2, 4, 24));
    v.push_back(Edge(2, 5, 62));
    v.push_back(Edge(3, 5, 20));
    v.push_back(Edge(3, 6, 37));
    v.push_back(Edge(4, 7, 13));
    v.push_back(Edge(5, 6, 45));
    v.push_back(Edge(5, 7, 73));
    
    // 간선의 비용으로 오름차순 정렬
    sort(v.begin(), v.end());
    
    // 각 정점이 포함된 그래프가 어디인지 저장
    int set[n];
    for(int i = 0; i < n; i++) {
        set[i] = i;
    }
    
    // 거리의 합을 0으로 초기화
    int sum = 0;
    for(int i = 0; i < v.size(); i++) {
        // 동일한 부모를 가르키지 않는 경우, 즉 사이클이 발생하지 않을 때만 선택
        if(!find(set, v[i].node[0] - 1, v[i].node[1] - 1)) {
            sum += v[i].distance;
            unionParent(set, v[i].node[0] - 1, v[i].node[1] - 1);
        }
    }
    
    printf("%d\n", sum);
}
```

## 🤔 잠깐, `bool operator < (머시꺵이..`는 뭐였지~? 연산자 오버로딩!!

- 위의 예제와 같은 Edge 클래스가 있다고 치자. (연산자 오버로딩이 없다면)
``` cpp
Edge Edge1=Edge(1,7,12);
Edge Edge2=Edge(1,4,28(;
cout << Edge1 + Edge2 << endl;
```
하면 오류가 발생한다!

-> Edge 클래스에 이러한 연산자 오버로딩 메소드를 추가하면 해결된다!
```cpp
int operator+(Edge &edge){
	return this->distance + edge.distance;
}
```
- 추가해주면 `e1+e2`는 `e1.operator+(e2)`와 같은 의미를 지닌다.
- 자세히 설명하자면, ~e1 객체를 기준으로 메소드 operator+를 호출하고, 매개변수로 e2를 받는다.~

- 단, 주의할 점은 algorithm 헤더에서 오류가 날 때가 있는데, 방지하기 위해서 매개변수들을 모두 `const`로 받으면 된다.
( `const` 를 명시하게 되면 operator 메소드 안에서는 어떤 변수도 바꿀 수 없고, const가 아닌 메소드를 부를 수도 없게 된다.)
[C++ 연산자 오버로딩(Overloading)](https://ssungkang.tistory.com/entry/C-%EC%97%B0%EC%82%B0%EC%9E%90-%EC%98%A4%EB%B2%84%EB%A1%9C%EB%94%A9Overloading)

- - - -
## 이진트리의 구현과 순회(Traversal) 방식
- 이진트리를 구현할 때는 데이터의 낭비(빈 배열로 자리만 차지하는 것)를 줄이기 위해서 포인터로 구현한다.

**세 가지 순회 방법**
1. 전위 순회(Preorder Traversal)
1) 먼저 자기 자신을 처리
2) 왼 자식 방문
3) 오른 자식 방문
2. 중위 순회(Inorder Traversal)
1) 왼 자식 방문
2) 자기 자신 처리
3) 오른 자식 방문
3. 후위 순회(Postorder Traversal) 
1) 왼 자식 방문
2) 오른 자식 방문
3) 자기 자신 처리
-> 컴퓨터에서 수식 처리할 때는 후위순회를 주로 사용함.


```cpp
int number = 15;

typedef struct node *treePointer;
typedef struct node {
    int data;
    treePointer leftChild, rightChild;
} node;
//Preorder traversal
void preorder(treePointer ptr){
    if(ptr){
        cout << ptr->data << ' ';
        preorder(ptr->leftChild);
        preorder(ptr->rightChild);
    }
}
//Inorder traversal
void inorder(treePointer ptr){
    if(ptr){
        inorder(ptr->leftChild);
        cout << ptr->data << ' ';
        inorder(ptr->rightChild);
    }
}
//Postorder traversal
void postorder(treePointer ptr){
    if(ptr){
        postorder(ptr->leftChild);
        postorder(ptr->rightChild);
        cout << ptr->data << ' ';
    }
}
int main(void) {
    node nodes[number+1];
    for(int i=1;i<=number;i++){
        nodes[i].data = i;
        nodes[i].leftChild = NULL;
        nodes[i].rightChild = NULL;
    }
    for(int i=1;i<=number;i++){
        if(i%2==0)
            nodes[i/2].leftChild = &nodes[i];
        else
            nodes[i/2].rightChild = &nodes[i];
    }
    cout << "전위 : ";
    preorder(&nodes[1]);
    cout << '\n';
    
    cout << "중위 : ";
    inorder(&nodes[1]);
    cout << '\n';
    
    cout << "후위 : ";
    postorder(&nodes[1]);
    cout << '\n';
    return 0;
}
```

- - - -
## 다이나믹 프로그래밍(Dynamic Programming)의 원리
- 대회에 진~~~짜 많이 나오는 개념! 피할 수 없는 숙명!
- 문제 종류가 많고, 컴퓨터적인 사고력을 물어보기에 적합함.
- 줄여서  DP, 동적계획법 이라고도 함. 
- **하나의 문제를 ~단 한 번~만 풀도록 하는 알고리즘.**
::but::
- ~분할 정복 기법은 몇몇 요소에서 동일한 문제를 다시 푼다~ 는 단점을 가진다.
(예를 들어, 재귀적으로 구현하면 동일한 데이터를 반복해서 물어봐야함. 피보나치 수열 같은 점화식을 이용하는 문제가 대표적인 예시)
- 다이나믹 프로그래밍은 다음의 가정 하에서 사용할 수 있다.
	1. 번 가정) 큰 문제를 작은 문제로 나눌 수 있다.
	2. 번 가정) 작은 문제에서 구한 정답은 그것을 포함하는 큰 문제에서도 동일하다.★
- 크고 어려운 문제가 있을 때 그것을 먼저 잘게 나누어서 해결한 뒤에 처리하여 나중에 전체의 답을 구하기 위해 메모이제이션(Memoization)이 사용된다.
- - - -
### 피보나치 수열 예시
```c
int dp(int x){
    if(x==1) return 1;
    if(x==2) return 1;
    return dp(x-1) + dp(x-2);
}
int main(void) {
    printf("%d",dp(10));
    return 0;
}
```
👉 하지만, 이런 방식으로 50번째 항을 구한다고 치면 엄~청 오래 걸림.
(n번째를 계산하려면 2^n번 계산을 해야함. 억겁의 시간이 걸린다.)

### 메모이제이션 예시
: 다이나믹 프로그래밍 기법을 이용하여 개선시켰다!
```cpp
int dp(int x){
    if(x==1) return 1;
    if(x==2) return 1;
    if(d[x]!=0) return d[x];
    return d[x] = dp(x-1)+dp(x-2);
}
```
재귀함수적인 사고력을 요구하기 때문에 아주~ 중요한 부분이다.

- - - -
## 다이나믹 프로그래밍 타일링 문제 풀어보기
- 기본적인 문제로 대표적인게 타일링 문제. 점화식을 세워보자.
### 11726 타일 채우기
[11726번](https://www.acmicpc.net/problem/11726)
![](AlgorithmSummary/29771259-C595-41BE-AB2F-C8A441083976.png)
- D[N] : 2xN 사이즈의 직사각형을 1x2, 2x1 사각형으로 채우는 방법의 수
- D[0] = D[1] = 1
- D[N-1] : 마지막 조각을 2x1 사각형으로 채운 방법의 수
- D[N-2] : 마지막 조각을 1x2 사각형 2개로 채운 방법의 수
![](AlgorithmSummary/3FA434DE-A5CF-49CF-AC6B-5AFE533849D5.png)

~그럼, 끝에 3이 남는 경우에는?~
-> 1x2로 2개로 채우고 길이가 1이 남는 경우 => N-1개의 타일을 채우는 방법의 수
-> 2x1로 채우고 길이가 2가 남는 경우 => N-2개의 타일을 채우는 방법의 수
이렇게 2가지 방식으로만 끝난다.
∴ N개의 타일을 채우는 방식은 N-1개의 타일을 채우는 방법의 수와 N-2개의 타일을 채우는 방법의 수의 합이 된다.

### 11727 타일 채우기2
![](AlgorithmSummary/4A947F3F-6493-42CB-8FCA-D247D820FC35.png)
- D[N] : 2xN 사이즈의 직사각형을 1x2, 2x1, 2x2 사각형으로 채우는 방법의 수
- D[0] = D[1] = 1
- D[N-1] : 마지막 조각을 2x1 사각형으로 채운 방법의 수
- D[N-2] : 마지막 조각을 1x2 사각형 2개 또는 2x2 사각형으로 채운 방법의 수
![](AlgorithmSummary/70C154A1-A680-4445-B82B-00CB13E73AE3.png)

### 2133 타일링 높이 3
![](AlgorithmSummary/75CFEB2F-A2D8-4CB7-B326-CA7BE065E769.png)
```cpp
int dp(int x){
    if(x==0) return 1;
    if(x==1) return 0;
    if(x==2) return 3;
    if(d[x]!=0) return d[x];
    int result=3*dp(x-2);
    for(int i=3;i<=x;i++){
        if(i%2==0)
            result+=2*dp(x-i);
    }
    return d[x]=result;
}
```

### 14852 타일 채우기3

![](AlgorithmSummary/5C170DA5-45F0-4A10-886F-6307AF32C1E2.png)

```cpp
int d[1000001],n;
int dp(int x){
    if(x==0) return 1;
    if(x==1) return 2;
    if(x==2) return 7;
    if(d[x]!=0) return d[x];
    int result=3*dp(x-2)+2*dp(x-1);
    for(int i=3;i<=x;i++){
        result+=(2*dp(x-i))%1000000007;
    }
    return d[x]=result%1000000007;
}
```
⚠️시간초과 두둥!!
어떻게 하면 효율적으로 알고리즘을 수정할 수 있을까? -> **2차원 DP**!!

![](AlgorithmSummary/F008D97D-250E-49DA-A1B6-3FB27276B5B7.png)
[2. Dynamic Programming (DP)](https://norman3.github.io/rl/docs/chapter02.html)

- - - -
### 잠깐, 재귀함수에 대해 알아보자!
```java
function recursive (인자) {
	작업 수행
	if (조건충족) {
		return 결과
	} else {
		return recursive (작업된 인자)
	}
}
```
- 근데, 재귀함수로 짜인 코드들은 반복문으로 대체 가능하고, 그렇게 적는게 더 쉬운 경우도 많다.
- 하지만 예를 들어 {1, 2, [2, 4, [4, 3]], 5} 의 합을 구하는 경우에는 3중 반복문을 이용해야하는데… -> 이럴 때 재귀함수를 사용하면 좋다!
- 재귀 종특으로 반복문에 비해 메모리를 많이 잡아먹는다는 단점이 있다. (스택에 계속 쌓여서)
- 🔺BUT🔺 꼬리 재귀 최적화를 이용하면 메모리가 비워지므로 괜찮음!

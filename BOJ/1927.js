const fs = require('fs');
const input = fs.readFileSync('/dev/stdin').toString().trim().split('\n');

const MinHeap = class {
  constructor() {
    this.heap = [];
  }

  swap(i, j) {
    [this.heap[i], this.heap[j]] = [this.heap[j], this.heap[i]];
  }

  insert(value) {
    this.heap.push(value);
    this.heapifyUp();
  }

  // 부모 노드와 비교하여 작으면 부모와 자리 변경(오름차순)
  heapifyUp() {
    let index = this.heap.length - 1;
    while (index > 0) {
      let parentIndex = Math.floor((index - 1)  / 2); // 힙 배열 기반으로 부모 노드 찾깇
      if (this.heap[parentIndex] <= this.heap[index]) break;
      this.swap(index, parentIndex);
      index = parentIndex;
    }
  }

  // 최소값 제거 및 반환
  remove() {
    if (this.heap.length === 0) return 0;
    if (this.heap.length === 1) return this.heap.pop();

    const min = this.heap[0];
    this.heap[0] = this.heap.pop(); // 마지막 요소를 루트로 이동
    this.heapifyDown();
    return min;
  }

  // 자식 노드와 비교해서 크면 자식과 자리 변경
  heapifyDown() {
    let index = 0;
    const length = this.heap.length;

    while (true) {
      let leftChildIdx = 2 * index + 1; // 왼쪽 자식 인덱스
      let rightChildIdx = 2 * index + 2; // 오른쪽 자식 인덱스
      let smallest = index; // 현재 노드를 최소값으로 가정

      if (leftChildIdx < length && this.heap[leftChildIdx] < this.heap[smallest]) {
        smallest = leftChildIdx; // 왼쪽 자식이 더 작으면 교체
      }
      if (rightChildIdx < length && this.heap[rightChildIdx] < this.heap[smallest]) {
        smallest = rightChildIdx; // 오른쪽 자식이 더 작으면 교체
      }
      if (smallest === index) break; // 오른쪽 자식이 더 작으면 교체

      this.swap(index, smallest); // 최소값 위치로 교체
      index = smallest; // 인덱스 갱신
    }
  }
}

let n = Number(input[0]);
input.shift();
const heap = new MinHeap();
const result = [];

input.forEach((elem)=>{
  let num = Number(elem);
  if (num == 0) {
    result.push(heap.remove());
  } else {
    heap.insert(num);
  }
});

console.log(result.join('\n'));

const fs = require("fs");
const input = fs.readFileSync("/dev/stdin").toString().trim().split("\n").map(Number);

class MinHeap {
  constructor() {
    this.heap = [];
  }

  add(x) {
    this.heap.push(x);
    this.heapifyUp();
  }

  remove() {
    if (this.heap.length > 0) {
      return this.heap.shift();
    } else {
      return 0;
    }
  }

  heapifyUp() {
    // 절댓값 낮은거 -> 높은거 순으로 정렬
    // 맨 뒤에 추가됐으니 앞으로 하나씩 이동시키면서 위치 이동시키기
    let idx = this.heap.length - 1;
    while (idx > 0) {
      if (Math.abs(this.heap[idx-1]) > Math.abs(this.heap[idx])) {
        this.swap(idx - 1, idx);
      }
      else if (Math.abs(this.heap[idx - 1]) == Math.abs(this.heap[idx]) &&
               this.heap[idx - 1] > this.heap[idx]) {
        this.swap(idx - 1, idx);
      }
      idx--;
    }
  }

  swap(a, b) {
    const temp = this.heap[a];
    this.heap[a] = this.heap[b];
    this.heap[b] = temp;
  }
}

const N = Number(input[0]);
const T = input.slice(1).map(Number);
const heap = new MinHeap();
T.forEach((x) => {
  if (x != 0) {
    heap.add(x);
  } else {
    // 절댓값이 가장 작은 값 출력, 그 값 배열에서 제거
    console.log(heap.remove());
  }
});

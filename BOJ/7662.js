const { EOF } = require("dns/promises");
const fs = require("fs");
const input = fs.readFileSync("/dev/stdin").toString().trim().split("\n");
let T = +input.shift();

class MinHeap {
  constructor() {
    this.q = [];
  }

  add(n) {
    this.q.push(n);
    this.heapifyUp();
  }

  remove() {
    if (this.q.length === 0) return;
    const lastIdx = this.q.length - 1;
    this.q[0] = this.q[lastIdx];
    this.q.pop();
    this.heapifyDown();
  }

  heapifyUp() {
    let index = this.q.length - 1;
    while (true) {
      let parentIndex = Math.floor(index / 2 - 0.1);
      if (index === 0 || this.q[parentIndex] <= this.q[index]) break;
      this.swap(index, parentIndex);
      index = parentIndex;
    }
  }

  heapifyDown() {
    let index = 0;
    let length = this.q.length;
    while (true) {
      let leftIdx = index * 2 + 1;
      let rightIdx = index * 2 + 2;
      let smallest = index;

      if (leftIdx < length && this.q[leftIdx] < this.q[smallest]) {
        smallest = leftIdx;
      }
      if (rightIdx < length && this.q[rightIdx] < this.q[smallest]) {
        smallest = rightIdx;
      }
      if (smallest === index) break;

      this.swap(index, smallest);
      index = smallest;
    }
  }

  swap(a, b) {
    [this.q[a], this.q[b]] = [this.q[b], this.q[a]];
  }

  peek() {
    return this.q.length ? this.q[0] : null;
  }
}

class MaxHeap {
  constructor() {
    this.q = [];
  }

  add(n) {
    this.q.push(n);
    this.heapifyUp();
  }

  remove() {
    if (this.q.length === 0) return;
    const lastIdx = this.q.length - 1;
    this.q[0] = this.q[lastIdx];
    this.q.pop();
    this.heapifyDown();
  }

  heapifyUp() {
    let index = this.q.length - 1;
    while (index > 0) {
      let parentIndex = Math.floor(index / 2 - 0.1);
      if (this.q[parentIndex] >= this.q[index]) break;
      this.swap(index, parentIndex);
      index = parentIndex;
    }
  }

  heapifyDown() {
    let index = 0;
    let length = this.q.length;
    while (true) {
      let leftIdx = index * 2 + 1;
      let rightIdx = index * 2 + 2;
      let largest = index;

      if (leftIdx < length && this.q[leftIdx] > this.q[largest]) {
        largest = leftIdx;
      }
      if (rightIdx < length && this.q[rightIdx] > this.q[largest]) {
        largest = rightIdx;
      }
      if (largest === index) break;

      this.swap(index, largest);
      index = largest;
    }
  }

  swap(a, b) {
    [this.q[a], this.q[b]] = [this.q[b], this.q[a]];
  }

  peek() {
    return this.q.length ? this.q[0] : null;
  }
}

while (T--) {
  const K = +input.shift();
  let minHeap = new MinHeap();
  let maxHeap = new MaxHeap();
  const visited = new Map();

  for (let i = 0; i < K; i++) {
    const [query, n] = input.shift().split(" ");
    const num = Number(n);
    if (query === "I") {
      maxHeap.add(num);
      minHeap.add(num);
      visited.set(num, (visited.get(num) || 0) + 1);
    }

    if (query === "D") {
      if (num === 1) {
        while (maxHeap.q.length && !visited.get(maxHeap.peek())) {
          maxHeap.remove(); // 알고보니 걔가 minHeap에서 이미 삭제된거면..
        }
        if (maxHeap.q.length) {
          let maxVal = maxHeap.peek();
          visited.set(maxVal, visited.get(maxVal) - 1);
          maxHeap.remove();
        }
      }
      else if (num === -1) { // 최솟값 삭제
        while (minHeap.q.length && !visited.get(minHeap.peek())) {
          minHeap.remove(); // 알고보니 걔가 maxHeap에서 이미 삭제된거면..
        }
        if (minHeap.q.length) {
          let minVal = minHeap.peek();
          visited.set(minVal, visited.get(minVal) - 1);
          minHeap.remove();
        }
      }
    }
  }

  // 유효한 값만 걸러내기
  while (minHeap.q.length && !visited.get(minHeap.peek())) {
    minHeap.remove();
  }
  while (maxHeap.q.length && !visited.get(maxHeap.peek())) {
    maxHeap.remove();
  }

  if (minHeap.q.length && maxHeap.q.length) {
    console.log(`${maxHeap.peek()} ${minHeap.peek()}`);
  } else {
    console.log("EMPTY");
  }
}

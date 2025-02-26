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
    if (this.heap.length === 0) return 0;
    if (this.heap.length === 1) return this.heap.pop();

    const minValue = this.heap[0];
    this.heap[0] = this.heap.pop();
    this.heapifyDown();
    return minValue;
  }

  heapifyUp() {
    let idx = this.heap.length - 1;

    while (idx > 0) {
      const parentIdx = Math.floor((idx - 1) / 2);

      if (this.compare(this.heap[parentIdx], this.heap[idx]) > 0) {
        this.swap(parentIdx, idx);
        idx = parentIdx;
      } else break;
    }
  }

  heapifyDown() {
    let idx = 0;
    const length = this.heap.length;

    while (true) {
      const leftChildIdx = idx * 2 + 1;
      const rightChildIdx = idx * 2 + 2;
      let smallestIdx = idx;

      if (
        leftChildIdx < length &&
        this.compare(this.heap[leftChildIdx], this.heap[smallestIdx]) < 0
      ) {
        smallestIdx = leftChildIdx;
      }

      if (
        rightChildIdx < length &&
        this.compare(this.heap[rightChildIdx], this.heap[smallestIdx]) < 0
      ) {
        smallestIdx = rightChildIdx;
      }

      if (smallestIdx !== idx) {
        this.swap(idx, smallestIdx);
        idx = smallestIdx;
      } else {
        break;
      }
    }
  }

  compare(a, b) {
    const absA = Math.abs(a);
    const absB = Math.abs(b);
    if (absA !== absB) return absA - absB;
    return a - b;
  }

  swap(a, b) {
    [this.heap[a], this.heap[b]] = [this.heap[b], this.heap[a]];
  }
}

const T = input.slice(1);
const heap = new MinHeap();

const result = [];
T.forEach((x) => {
  if (x !== 0) {
    heap.add(x);
  } else {
    result.push(heap.remove());
  }
});

console.log(result.join("\n"));
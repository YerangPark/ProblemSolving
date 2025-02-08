const fs = require('fs');
const input = fs.readFileSync('/dev/stdin').toString().trim().split('\n');
const [N] = input[0].map(Number);

const MaxHeap = class {
  constructor() {
    this.heap = [];
  }

  push(num) {
    this.heap.push(num);
    this.heapifyUp();
  }

  heapifyUp() {
    let index = this.heap.length - 1;
    while (index > 0) {
      const parent = Math.floor((index - 1) / 2);
      if (this.heap[parent] >= this.heap[index]) break;
      [this.heap[parent], this.heap[index]] = [this.heap[index], this.heap[parent]];
      index = parent;
    }
  }

  extractMax() {
    if (this.heap.length === 0) return 0;
    if (this.heap.length === 1) return this.heap.pop();

    const max = this.heap[0];
    this.heap[0] = this.heap.pop();
    this.heapifyDown();
    return max;
  }

  heapifyDown() {
    let index = 0;
    const last = this.heap.length - 1;
    while (index < last) {
      const left = index * 2 + 1;
      const right = index * 2 + 2;
      const largest = index;
      if (left <= last && this.heap[left] > this.heap[largest]) largest = left;
      if (right <= last && this.heap[right] > this.heap[largest]) largest = right;
      if (largest === index) break;
      [this.heap[largest], this.heap[index]] = [this.heap[index], this.heap[largest]];
      index = largest;
    }
  }
}

// 최대 힙
const heap = new MaxHeap();
const output = [];

for (let i = 1; i <= N; i++) {
    const x = parseInt(input[i]);
    if (x > 0) {
        heap.insert(x);
    } else {
        output.push(heap.extractMax());
    }
}

console.log(output.join('\n'));
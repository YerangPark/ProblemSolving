class MinHeap {
    constructor() {
        this.heap = [];
    }
    size() {return this.heap.length;}
    peek() {return this.heap[0];}
    swap(a, b) {[this.heap[a], this.heap[b]] = [this.heap[b], this.heap[a]]}
    leftChild(idx) {return idx*2+1;}
    rightChild(idx) {return idx*2+2;}
    parent(idx) {return Math.floor((idx-1)/2);}
    push(val) {
        this.heap.push(val);
        let i = this.heap.length - 1;
        
        while(i>0) {
            const parent = this.parent(i);
            if (this.heap[parent] <= this.heap[i]) break;
            this.swap(parent, i);
            i = parent;
        }
    }
    pop() {
        if (this.heap.length === 0) return undefined;
        if (this.heap.length === 1) return this.heap.pop();
        
        const min = this.heap[0];
        this.heap[0] = this.heap.pop();
        
        let i = 0;
        while (true) {
            const left = i * 2 + 1;
            const right = i * 2 + 2;
            let smallest = i;
            
            if (left < this.heap.length && this.heap[left] < this.heap[smallest]) {
                smallest = left;
            }
            if (right < this.heap.length && this.heap[right] < this.heap[smallest]) {
                smallest = right;
            }
            if (smallest === i) break;
            
            this.swap(i, smallest);
            i = smallest;
        }
        return min;
    }
}

function solution(scoville, K) {
    var answer = 0;
    const mh = new MinHeap();
    
    scoville.forEach((n)=>mh.push(n));
    while (mh.peek() < K) {
        if (mh.size() < 2) return -1;
        const first = mh.pop();
        const second = mh.pop();
        mh.push(first + second * 2);
        answer++;
    }
    
    
    return answer;
}
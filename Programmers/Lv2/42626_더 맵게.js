class MinHeap {
    constructor() {
        this.heap = [];
    }
    
    add(num) {
        this.heap.push(num);
        
        // 꼬리부터 재정렬
        let idx = this.heap.length - 1;
        while(idx >= 0) {
            const parentIdx = Math.floor((idx - 1) / 2);
            if (this.heap[parentIdx] > this.heap[idx]) {
                [this.heap[idx], this.heap[parentIdx]] = 
                    [this.heap[parentIdx], this.heap[idx]];
                idx = parentIdx;
            }
            else {
                break;
            }
        }
    }
    
    remove() {
        if (this.heap.length === 0) return null;
        
        const smallest = this.heap[0];
        if (this.heap.length > 1) {
            this.heap[0] = this.heap.pop();   
        }
        else {
            this.heap.pop();
        }
        
        // 머리부터 재정렬
        let idx = 0;
        while(this.heap.length > 1) {
            const leftChildIdx = (idx * 2) + 1;
            const rightChildIdx = (idx * 2) + 2;
            let smallestIdx = idx;
            
            if (leftChildIdx < this.heap.length &&
                this.heap[leftChildIdx] < this.heap[smallestIdx]) {
                smallestIdx = leftChildIdx;
            }
            if (rightChildIdx < this.heap.length &&
                     this.heap[rightChildIdx] < this.heap[smallestIdx]) {
                smallestIdx = rightChildIdx;
            }
            
            if (smallestIdx !== idx) {
                [this.heap[idx], this.heap[smallestIdx]] = 
                    [this.heap[smallestIdx], this.heap[idx]];
                idx = smallestIdx;
            } else {
                break;
            }
        }
        return smallest;
    }
    
    getSmallest() {
        return this.heap[0];
    }
    
    getSecondSmallest() {
        return this.heap[1] > this.heap[2] ? this.heap[2] : this.heap[1];
    }
    
    getLength() {
        return this.heap.length;
    }
}

function solution(scoville, K) {
    var answer = -1;
    let cnt = 0;
    
    const minHeap = new MinHeap();
    scoville.forEach((elem)=>minHeap.add(elem));
    
    if (minHeap.getSmallest() >= K) return 0;
    while (minHeap.getLength() >= 2) {
        const first = minHeap.remove();
        const second = minHeap.remove();
        minHeap.add(first + (second * 2));
        cnt++;
        
        if (minHeap.getSmallest() >= K) return cnt;
    }
    
    return answer;
}


// 효율성 틀린 코드
// function solution(scoville, K) {
//     var answer = -1;
//     let time = 0;

//     if (checkListOverK(scoville, K)) {
//         return 0;
//     }
//     while (scoville.length >= 2) {
//         scoville.sort((a, b) => b-a);
        
//         const first = scoville.pop();
//         const second = scoville.pop();
//         scoville.push(first + (second * 2));
        
//         time++;
//         if (checkListOverK(scoville, K)) {
//             answer = time;
//             break;
//         }
//     }
    
//     return answer;
// }
// 
// function checkListOverK(list, K) {
//     return list.every((elem) => elem >= K);
// }
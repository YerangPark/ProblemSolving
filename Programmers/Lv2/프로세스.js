function solution(priorities, location) {
    const queue = [...priorities];
    var answer = 0;
    let head = 0;
    
    while (queue.length > head) {
        const x = queue[head];
        let has = false;
        for (let i=head; i<queue.length; i++) {
            if (queue[i] > x) has = true;
        }

        if (has) {
            queue.push(x);
            if (location === head) location = queue.length - 1;
        }
        else {
            answer++;
            if (location === head) {
                return answer;
            }
        }
        
        head++;
    }
}
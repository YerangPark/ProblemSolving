function solution(priorities, location) {
    var answer = 0;
    const sortedPriorities = [];
    const q = [];
    let order = 1;
    
    priorities.forEach((p, idx) => {
        q.push([p, idx]);
    })
    sortedPriorities.push(...priorities);
    sortedPriorities.sort((a, b)=> b - a);
    
    while (true) {
        const [priority, idx] = q.shift();
        if (sortedPriorities[0] === priority) {
            if (idx === location) {
                return order;
            }
            sortedPriorities.shift();
            order++;
        }
        else {
            q.push([priority, idx]);
        }
    }
    
    return answer;
}
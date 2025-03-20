function solution(progresses, speeds) {
    var answer = [];
    const q = [];

    progresses.forEach((progress, idx) => {
        const releaseLeftDay = Math.ceil((100 - progress) / speeds[idx]);
        q.push(releaseLeftDay);
    });
    
    let accumulatedDays = 0;
    while (q.length) {
        let front = q.shift();
        let cnt = 1;
        
        while (q.length && front >= q[0]) {
            q.shift();
            cnt++;
        }
        
        answer.push(cnt);
    }
    
    return answer;
}
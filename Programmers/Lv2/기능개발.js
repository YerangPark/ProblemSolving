function solution(progresses, speeds) {
    let answer = [];
    let day = Math.ceil((100 - progresses[0]) / speeds[0]);
    let cnt = 1;
    
    for (let i=1; i<progresses.length; i++) {
        const rest = 100 - progresses[i];
        const needDay = Math.ceil(rest / speeds[i]);
        if (needDay <= day) {
            cnt++;
        }
        else {
            answer.push(cnt);
            cnt = 1;
            day = needDay;
        }
    }
    if (cnt > 0) answer.push(cnt);
    
    return answer;
}
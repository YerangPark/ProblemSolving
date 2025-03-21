let visited = Array(200 + 1).fill(false);

function solution(n, computers) {
    let networkCnt = 0;
    
    for (let i=0; i<n; i++) {
        let isAlone = true;
        for (let j=0; j<n; j++) {
            if (i == j) continue;
            if (computers[i][j] === 1) {
                isAlone = false;
                if (!visited[i]) {
                    networkCnt++;
                    visited[i] = true;
                    bfs(i, computers);
                }
            }
        }
        if (isAlone) networkCnt++;
    }
    
    return networkCnt;
}

function bfs(node, computers) {
    const q = [];
    q.push(node);
    
    while(q.length > 0) {
        let now = q.shift();
        for (let i=0; i<computers[now].length; i++) {
            if (now === i || visited[i] || !computers[now][i]) {
                continue;
            }
            visited[i] = true;
            q.push(i);
        }
    }
    
}
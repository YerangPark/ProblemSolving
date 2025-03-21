function solution(maps) {
    const q = [];
    const N = maps.length;
    const M = maps[0].length;
    const visited = Array.from({length: N}, ()=>Array(M).fill(false));
    const axisX = [-1, 1, 0, 0];
    const axisY = [0, 0, -1, 1];
    
    if (maps[N-1][M-2] === 0 && maps[N-2][M-1] === 0) {return -1}
    visited[0][0] = true;
    q.push([0, 0, 1]);
    while (q.length > 0) {
        let [x, y, cnt] = q.shift();
        if (x === N-1 && y === M-1) {
            return cnt;
        }
        for (let i=0; i<4; i++) {
            let [dx, dy] = [x + axisX[i], y + axisY[i]];
            if (dx < 0 || dx >= N || dy < 0 || dy >= M ||
                visited[dx][dy] || maps[dx][dy] === 0) continue;
            visited[dx][dy] = true;
            q.push([dx, dy, cnt+1]);
        }
    }
    
    return -1;
}
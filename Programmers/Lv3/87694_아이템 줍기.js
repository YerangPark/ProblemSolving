function solution(rectangle, characterX, characterY, itemX, itemY) {
    const N = 102;
    const map = Array.from({ length: N }, () => Array(N).fill(0));
    const visited = Array.from({ length: N }, () => Array(N).fill(false));

    // 사각형 테두리 표시 (2배 확장)
    rectangle.forEach(([x1, y1, x2, y2]) => {
        x1 *= 2; y1 *= 2; x2 *= 2; y2 *= 2;

        for (let i = x1; i <= x2; i++) {
            for (let j = y1; j <= y2; j++) {
                // 테두리: 1 / 내부: 2
                if (i === x1 || i === x2 || j === y1 || j === y2) {
                    if (map[i][j] !== 2) map[i][j] = 1;
                } else {
                    map[i][j] = 2;
                }
            }
        }
    });

    const queue = [];
    const dx = [-1, 1, 0, 0];
    const dy = [0, 0, -1, 1];

    characterX *= 2;
    characterY *= 2;
    itemX *= 2;
    itemY *= 2;

    queue.push([characterX, characterY, 0]);
    visited[characterX][characterY] = true;

    while (queue.length) {
        const [x, y, dist] = queue.shift();
        if (x === itemX && y === itemY) return dist / 2;

        for (let i = 0; i < 4; i++) {
            const nx = x + dx[i];
            const ny = y + dy[i];

            if (nx < 0 || ny < 0 || nx >= N || ny >= N) continue;
            if (visited[nx][ny]) continue;
            if (map[nx][ny] !== 1) continue;

            visited[nx][ny] = true;
            queue.push([nx, ny, dist + 1]);
        }
    }

    return 0;
}
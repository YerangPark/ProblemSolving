function solution(sizes) {
    var answer = 0;
    let maxX = 0, maxY = 0;
    sizes.forEach(([x, y])=> {
        const [revX, revY] = [y, x];
        const sizeNormal = Math.max(maxX, x) * Math.max(maxY, y);
        const sizeRev = Math.max(maxX, revX) * Math.max(maxY, revY);
        if (sizeNormal > sizeRev) {
            maxX = Math.max(maxX, revX);
            maxY = Math.max(maxY, revY);
        }
        else {
            maxX = Math.max(maxX, x);
            maxY = Math.max(maxY, y);
        }
    })
    return maxX * maxY;
}
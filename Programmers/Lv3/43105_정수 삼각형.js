function solution(triangle) {
    var answer = 0;
    const dp = Array.from({length:triangle.length}, ()=>Array(triangle.length).fill(0));
    
    // 마지막 줄만 넣어주기
    for (let j=0; j<triangle[triangle.length-1].length; j++) {
        dp[triangle.length-1][j] = triangle[triangle.length-1][j];
    }
    
    for (let i=triangle.length-2; i>=0; i--) {
        for (let j=0; j<triangle[i].length; j++) {
            let leftChild = j, rightChild = j + 1;
            dp[i][j] = triangle[i][j] + 
                Math.max(dp[i+1][leftChild], dp[i+1][rightChild]);
        }
    }
    return dp[0][0];
}

// function solution(triangle) {
//     var answer = 0;
//     return recursive(triangle, 0, 0);
// }

// 재귀방식 -> 답은 나오는데 시간 초과
// function recursive(triangle, x, y) {
//     let leftChild = y,
//         rightChild = y + 1;
//     if (x === triangle.length - 1) {
//         return triangle[x][y];
//     }
//     const maxVal = Math.max(recursive(triangle, x + 1, leftChild), 
//                             recursive(triangle, x + 1, rightChild));
//     return triangle[x][y] + maxVal;
        
// }
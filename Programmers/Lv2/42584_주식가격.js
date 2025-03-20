function solution(prices) {
    const answer = [];
    for (let i = 0; i < prices.length; i++) {
        let stack = 0;
        for (let j = i + 1; j < prices.length; j++) {
            stack++;
            if (prices[i] > prices[j]) {
                break;
            }
        }
        answer.push(stack);
    }
    return answer;
}
    
// function solution(prices) {
//     const answer = [];
//     const q = [];
//     prices.forEach((price, idx)=>{
//         const qLen = q.length;
//         for (let i=0; i<qLen; i++) {
//             const front = q.shift();
//             answer[front.idx] = answer[front.idx] ? answer[front.idx] + 1 : 1;
//             if (price >= front.val) {
//                 q.push(front);
//             }
//         }
//         q.push({val: price, idx: idx});
//     });
//     answer.push(0);

//     // 시간초과 ver
//     while (prices.length) { // 100,000
//         let price = prices.shift();
//         let time = 0;
//         for (let p of prices) { // 100,000
//             time++;
//             if (p < price) break;
//         }
//         answer.push(time);
//     }
//     return answer;
// }
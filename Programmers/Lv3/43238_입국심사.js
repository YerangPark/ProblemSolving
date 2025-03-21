function solution(n, times) {
    const sorted = times.sort((a, b) => a - b);
    let left = 1,
        right = sorted[sorted.length - 1] * n; // 10억. 갖고싶다
    while (left <= right) {
        const mid = Math.floor((left + right)/2);
        const peopleCnt = sorted.reduce((acc, cur)=>acc + Math.floor(mid/cur), 0);
        if (peopleCnt < n) left = mid + 1;
        else right = mid - 1;
    }
    return left;
}
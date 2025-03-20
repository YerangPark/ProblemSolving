function solution(clothes) {
    var answer = 1;
    let map = new Map();
    
    for (let cloth of clothes) {
        map.set(cloth[1], (map.get(cloth[1]) || 0) + 1);
    }
    
    map.forEach((a)=>{
        answer *= a + 1;
    });
    
    return answer - 1;
}
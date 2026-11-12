function solution(clothes) {
    // 추가로 옷을 입거나, 입은 옷 중에 교체를 해야 함.
    // 종류별로 최대 1개
    // 서로 다른 옷 조합의 수
    let mul = 1;
    const map = new Map();
    
    for (const [cloth, kind] of clothes) {
        if (map.has(kind)) {
            map.set(kind, map.get(kind) + 1);
        }
        else map.set(kind, 1);
    }
    
    for (const [kind, cnt] of map) {
        mul *= (cnt+1);
    }

    return mul - 1;
}
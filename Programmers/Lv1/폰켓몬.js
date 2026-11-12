function solution(nums) {
    const take = nums.length / 2;
    const m = new Map();
    
    for (const num of nums) {
        if (m.has(num)) {
            m.set(num, m.get(num)+1);
        }
        else {
            m.set(num, 1);
        }
    }

    if (take >= m.size) {
        return m.size;
    }
    return take;
}
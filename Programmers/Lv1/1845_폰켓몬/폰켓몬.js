function solution(nums) {
    var answer = 0;
    let set = new Set();
    const N = nums.length;
    for (let i=0; i<N; i++) {
        set.add(nums[i]);
    }
    answer = set.size > N/2 ? N/2 : set.size;
    return answer; 
}
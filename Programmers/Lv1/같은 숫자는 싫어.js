function solution(arr) {
    var answer = [];
    for (const num of arr) {
        if ((answer.length >= 1 && answer[answer.length-1] !== num) || answer.length === 0)
            answer.push(num);
    }
    return answer;
}
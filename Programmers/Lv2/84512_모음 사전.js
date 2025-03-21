const moeums = ['A', 'E', 'I', 'O', 'U'];
let cnt = 0;
let found = false;
let answer = 0;

function solution(word) {
    recursive('', word);
    return cnt;
}

function recursive(word, ans) {
    if (word.length >= 5 || found) return;

    moeums.forEach((moeum)=>{
        if (found) return;
        cnt++;
        if (word+moeum === ans) {
            found = true;
            answer = cnt;
            return;
        }
        recursive(word+moeum, ans);
    });
}
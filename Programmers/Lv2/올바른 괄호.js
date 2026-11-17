function solution(s){
    const arr = [...s];
    let open = 0;

    for (const ch of arr) {
        if (ch === '(') open++;
        else if (open >= 1 && ch === ')') open--;
        else if (open < 1 && ch === ')') return false;
    }
    if (open > 0) return false;
    return true;
}
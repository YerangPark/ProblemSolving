function solution(begin, target, words) {
    const W = words.length;
    const L = begin.length;
    const q = [];
    const visited = Array.from({length: W}, ()=>false);
    
    q.push([begin, 0]);
    while (q.length > 0) {
        const [now, cnt] = q.shift();
        // console.log(`now : ${now}`);
        
        if (now === target) {
            return cnt;
        }
        
        words.forEach((word, idx) => {
            // console.log(`    check : ${word}`);
            if (word !== now && !visited[idx]) {
                // 한 단어만 다른지 체크
                let diffCnt = 0;
                for (let i=0; i<L; i++) {
                    if (now.at(i) != word.at(i)) {
                        diffCnt++;
                    }
                }
                if (diffCnt <= 1) {
                    // console.log("    push");
                    visited[idx] = true;
                    q.push([word, cnt + 1]);
                }
                
            }
        })
    }
    
    return 0;
}
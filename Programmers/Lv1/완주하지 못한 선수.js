function solution(participant, completion) {
    const m = new Map();
    
    for (const name of participant) {
        if (m.has(name)) {
            m.set(name, m.get(name)+1);
        }
        else {
            m.set(name, 1);
        }
    }
    
    for (const name of completion) {
        m.set(name, m.get(name)-1);
    }
    
    for (const [name, count] of m) {
        if (count > 0) return name;
    }
}
function solution(participant, completion) {
    const m = new Map();
    
    for (name of participant) {
        if (m.has(name)) {
            m.set(name, m.get(name)+1);
        }
        else {
            m.set(name, 1);
        }
    }
    
    for (name of completion) {
        m.set(name,m.get(name)-1);
    }
    
    for (name of participant) {
        if (m.get(name) == 1) {
            return name;
        }
    }
}
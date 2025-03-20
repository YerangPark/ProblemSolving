function solution(participant, completion) {
    let ansArr = [];
    // 최대 10만명
    let map = new Map();
    participant.forEach((person)=>{
        map.set(person, (map.get(person) || 0) + 1);
    })
    completion.forEach((person) => {
        if (map.get(person) == 1) {
            map.delete(person);
        }
        else {
            map.set(person, map.get(person) - 1);
        }
    })
    return map.keys().next().value;
}
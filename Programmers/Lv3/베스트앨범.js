
function solution(genres, plays) {
    const answer = [];
    const m = new Map();
    const arr = [];
    
    for (let i=0; i<genres.length; i++) {
        arr.push({idx: i, genre: genres[i], play : plays[i]});
        m.set(genres[i], (m.get(genres[i]) || 0) + plays[i]);
    }
    
    arr.sort((a, b)=>
        m.get(b.genre) - m.get(a.genre) ||
        b.play - a.play ||
        a.idx - b.idx
    );
    
    const count = new Map();
    for (const song of arr) {
        const c = count.get(song.genre) || 0;
        if (c < 2) {
            answer.push(song.idx);
            count.set(song.genre, c + 1);
        }
    }
    
    return answer;
}
function solution(genres, plays) {
    var answer = [];
    
    const N = genres.length;
    const genresPlayCnt = new Map();
    const genresAnswerCnt = new Map();
    const genresSong = [];
    
    for (let i=0; i<N; i++) {
        genresPlayCnt.set(genres[i], (genresPlayCnt.get(genres[i]) || 0) + plays[i]);
        genresSong.push([genres[i], plays[i], i]);
    }
    
    genresSong.sort(([genreA, playA], [genreB, playB])=>{
        if (genresPlayCnt.get(genreA) < genresPlayCnt.get(genreB)) {
            return 1;
        }
        else if (genresPlayCnt.get(genreA) > genresPlayCnt.get(genreB)) {
            return -1;
        }
        return playB - playA;
    });

    genresSong.forEach(([genre, play, index])=>{
        let cnt = (genresAnswerCnt.get(genre) || 0) + 1;
        if (cnt > 2) return;
        genresAnswerCnt.set(genre, cnt);
        answer.push(index);
    });
    
    return answer;
}
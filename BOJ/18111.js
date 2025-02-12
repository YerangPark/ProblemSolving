const fs = require('fs');
const input = fs.readFileSync('/dev/stdin').toString().trim().split('\n');
const [N, M, B] = input[0].split(' ').map(Number);

const land = input.slice(1).map((elem)=>elem.split(' '))

let minTime = Number.MAX_SAFE_INTEGER;
let maxHeight = 0;

for (let targetHeight = 0; targetHeight <= 256; targetHeight++) {
  let removeBlocks = 0;
  let addBlocks = 0;

  for (let i=0; i<N; i++) {
    for (let j=0; j<M; j++) {
      const diff = land[i][j] - targetHeight;

      if (diff > 0) removeBlocks += diff;
      else addBlocks -= diff;
    }
  }
  if (addBlocks <= removeBlocks + B) {
    // 가능한 경우
    const time = removeBlocks * 2 + addBlocks;
    if (time < minTime || (time == minTime && targetHeight > maxHeight)) {
      minTime = time;
      maxHeight = targetHeight;
    }
  }
}

console.log(minTime, maxHeight);

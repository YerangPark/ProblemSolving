const fs = require("fs");
const input = fs.readFileSync("/dev/stdin").toString().trim().split("\n");

const N = Number(input[0]);
const M = Number(input[1]);
const S = input[2];
let cnt = 0;
let i = 0;

while (i < M - 1) {
  let count = 0;
  while (i < M - 1 && S[i] === "I" && S[i + 1] === "O") {
    i += 2;
    if (i < M && S[i] === "I") {
      count++;
    }
  }
  if (count >= N) {
    // N회 이상의 반복이 되면
    cnt += count - N + 1; // 한 칸씩 옮겨가면 그 반복이 또 반복되는거니까 (count - N) + 1만큼 횟수가 기록됨.
  }
  i++;
}

console.log(cnt);

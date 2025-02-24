const fs = require("fs");
const input = fs.readFileSync("/dev/stdin").toString().trim().split("\n");

const T = Number(input[0]);
for (let i = 1; i <= T; i++) {
  const [M, N, x, y] = input[i].split(" ").map(Number);
  let xx = 1,
    yy = 1,
    cnt = 1;
  let res = -1;
  while (1) {
    if (x === xx && y === yy) {
      res = cnt;
      break;
    }
    if (xx === M && yy === N) {
      break;
    }

    if (xx < M) xx++;
    else xx = 1;
    if (yy < N) yy++;
    else yy = 1;
    cnt++;
  }
  console.log(res);
}

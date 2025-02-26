const fs = require("fs");
const input = fs
  .readFileSync("./dev/stdin")
  .toString()
  .trim()
  .split("\n")
  .map(Number);
const T = input.splice(1);
const answer = [];

T.forEach((v) => {
  const [M, N, X, Y] = v.split(" ").map(Number);
  const last = lcm(N, M);
  let x = X;
  let y = Y;
  while (true) {
    if (x > last || y > last) {
      answer.push(-1);
      break;
    } else if (x > y) {
      y += N;
    } else if (x < y) {
      x += M;
    } else {
      answer.push(x);
      break;
    }
  }
});

console.log(answer.join("\n"));

function gcd(a, b) {
  if (b == 0) return a;
  return a > b ? gcd(b, a % b) : gcd(a, b % a);
}

function lcm(a, b) {
  return (a * b) / gcd(a, b);
}

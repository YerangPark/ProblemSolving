const fs = require("fs");
const input = fs.readFileSync("/dev/stdin").toString().trim().split("\n");
const N = Number(input[0]);

const fruits = input[1].split(" ").map(Number);
let left = 0,
  right = 0;
let maxLength = 0;
const count = new Map();

while (right < N) {
  console.log(`left : ${left} / right : ${right}`);
  const fruit = fruits[right];
  count.set(fruit, (count.get(fruit) || 0) + 1);
  while (count.size > 2) {
    const leftFruit = fruits[left];
    if (count.get(leftFruit) === 1) {
      count.delete(leftFruit);
    } else {
      count.set(leftFruit, count.get(leftFruit) - 1);
    }
    left++;
  }
  maxLength = Math.max(maxLength, right - left + 1);
  right++;
}
console.log(maxLength);

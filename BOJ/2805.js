const fs = require('fs');
const input = fs.readFileSync('/dev/stdin').toString().trim().split('\n');
let [N, M] = input[0].split(' ').map(Number);
const trees = input[1].split(' ').map(Number);


let left = 0, right = Math.max(...trees);
let result = 0;

while (left <= right) {
  let mid = Math.floor((left + right) / 2);
  let sum = 0;

  for (let tree of trees) {
    if (tree - mid > 0) sum += (tree - mid);
  }

  if (sum >= M) {
    result = mid;
    left = mid + 1;
  }
  else {
    right = mid - 1;
  }
}
console.log(result);
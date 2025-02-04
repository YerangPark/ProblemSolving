const fs = require('fs');
const input = fs.readFileSync('/dev/stdin').toString().trim().split('\n');
const [n, m] = input[0].split(' ').map(Number);

function isNumeric(str) {
  return /^\d+$/.test(str);
}

let illustrated = [];
let dict = new Map();
for (let i = 1; i <= n; i++) {
  illustrated.push(input[i]);
  dict.set(input[i], i);
}

for (let i = n+1; i < n+m+1; i++) {
  if (isNumeric(input[i])) {
    console.log(illustrated[input[i]-1]);
  }
  else {
    console.log(dict.get(input[i]));
  }
}

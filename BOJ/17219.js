const fs = require('fs');
const input = fs.readFileSync('/dev/stdin').toString().trim().split('\n');
const [n, m] = input[0].split(' ').map(Number);

let map = new Map();
for (let i=1; i<=n; i++) {
  const [url, pw] = input[i].split(' ');
  map.set(url, pw);
}

for (let i=n+1; i<n+m+1; i++) {
  console.log(map.get(input[i]));
}
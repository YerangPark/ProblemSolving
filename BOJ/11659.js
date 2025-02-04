const fs = require('fs');
const input = fs.readFileSync('/dev/stdin').toString().trim().split('\n');
const [n, m] = input[0].split(' ').map(Number);

input.shift();
let list = [];
list.push(...input[0].split(' ').map(Number));

input.shift();
input.map((elem)=>{
  let sum = 0;
  const [a, b] = elem.split(' ').map(Number);
  for (let i = a-1; i < b; i++) {
    sum += list[i];
  }
  console.log(sum);
})
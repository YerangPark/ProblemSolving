const fs = require("fs");
const input = fs.readFileSync("/dev/stdin").toString().trim().split("\n");
let T = +input.shift();

// R : 수의 순서 뒤집음
// D : 첫번째 수 버림

while (T--) {
  let order = true; // 1 : 앞에서부터 / 0 : 뒤에서부터
  let isError = false;
  const commandList = input.shift();
  const arrLength = +input.shift();
  const arrStr = input.shift();
  let arr = arrLength === 0 ? [] : arrStr.substring(1, arrStr.length-1).split(",").map(Number);

  for (let i = 0; i < commandList.length; i++) {
    const command = commandList[i];
    if (command === 'R') {
      order = !order;
    }
    else if (command === 'D') {
      if (arr.length === 0) {
        isError = true;
        break;
      }
      if (order) {
        arr.shift();
      }
      else {
        arr.pop();
      }
    }
  }
  if (isError) {
    console.log('error');
    continue;
  }
  if (order) {
    console.log(`[${arr.join(',')}]`);
  }
  else {
    let ans = [];
    for (let i=arr.length-1; i>=0; i--) {
      ans.push(arr[i]);
    }
    console.log(`[${ans.join(',')}]`);
  }
}

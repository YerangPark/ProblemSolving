const fs = require('fs');
const input = fs.readFileSync('/dev/stdin').toString().trim().split('\n');
let list = [];
const allList = Array.from({ length: 20 }, (_, i) => i + 1);

const n = input[0]
input.slice(1).map((value) => {
  const [calcStr, num] = value.split(' ');
  switch(calcStr) {
    case 'add' :
      list.push(num);
      break;
    case 'remove' :
      list.filter(n => n !== num);
      break;
    case 'check' :
      if (list.includes(num)) {
        console.log(1);
      }
      else {
        console.log(0);
      }
      break;
    case 'toggle' :
      if (list.includes(num)) {
        list.filter(n => n !== num);
      }
      else {
        list.push(num);
      }
      break;
    case 'all' :
      list = allList;
      break;
    case 'empty' :
      list = [];
      break;
  }
})
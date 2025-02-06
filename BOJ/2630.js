const fs = require('fs');
const input = fs.readFileSync('/dev/stdin').toString().trim().split('\n');

const N = Number(input[0]);

const paper = input.slice(1).map(line=>line.split(' ').map(Number)); // ⭐️

let white = 0;
let blue = 0;

function checkColor(x, y, size) {
	// 종결 조건 확인
	const firstColor = paper[x][y];
	for (let i=x; i<x+size; i++) {
		for (let j=y; j<y+size; j++) {
			if (firstColor != paper[i][j]) {
				checkColor(x, y, size / 2);
				checkColor(x+size / 2, y, size / 2);
				checkColor(x, y + size / 2, size / 2);
				checkColor(x + size / 2, y + size / 2, size / 2);
				return;
			}
		}
	}
	if (firstColor == 1) blue++;
	else white++;
}

checkColor(0, 0, N);

console.log(white);
console.log(blue);
function solution(numbers) {
    const sorted = numbers.sort((a, b) => {
        const ab = a.toString() + b.toString();
        const ba = b.toString() + a.toString();
        return ba.localeCompare(ab);
    });

    const result = sorted.join('');
    return result[0] === '0' ? '0' : result;
}
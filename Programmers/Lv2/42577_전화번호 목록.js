function solution(phone_book) {
    let phoneSet = new Set();

    for (let phone of phone_book) {
        phoneSet.add(phone);
    }

    for (let phone of phone_book) { // N
        for (let i = 1; i < phone.length; i++) { // 20번
            let prefix = phone.substring(0, i);
            if (phoneSet.has(prefix)) return false;
        }
    }

    return true;
}

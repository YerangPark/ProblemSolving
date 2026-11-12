function solution(phone_book) {
    const set = new Set(phone_book);
    
    for (const phoneNumber of phone_book) {
        for (let i=1; i < phoneNumber.length; i++) {
            if (set.has(phoneNumber.slice(0, i))) return false;
            set.add(phoneNumber);
        }
    }
    return true;
}

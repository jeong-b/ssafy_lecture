const arr = [1, 2, 3, 4, 5];
// some : 하나의 조건만 만족해도 True 반환
const result1 = arr.some(element => element < 0); // false
const result2 = arr.some(element => element > 4); // true

// every : 모든 조건을 만족해야 True 반환
const result3 = arr.every(element => element > 0); // true
const result4 = arr.every(element => element > 3); // false
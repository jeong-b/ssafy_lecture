const arr = [1, 2, 3, 4, 5];
const inventory = [
  {name: "A", quantity: 1},
  {name: "B", quantity: 2},
  {name: "C", quantity: 3},
];

// find : 해당하는 배열의 값을 가져온다
// 만족하는 모든 값이 아닌 만족하는 첫번째 값만 가져온다
const result1 = arr.find(element => element > 3);
console.log(result1);

const result2 = inventory.find(li => li.name === "B");
console.log(result2);

// findIndex : 해당하는 배열의 index를 가져온다
// 만족하는 모든 값이 아닌 만족하는 첫번째 값만 가져온다
const result3 = arr.findIndex(element => element > 3);
console.log(result3);

const result4 = inventory.findIndex(li => li.name === "B");
console.log(result4);
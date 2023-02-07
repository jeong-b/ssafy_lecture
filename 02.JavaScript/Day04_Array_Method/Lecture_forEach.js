// 배열 매소드 구조 - Array.함수(콜백함수)
// forEach는 값을 return하지 않음

/* 배열의 값을 출력하는 3가지 방법 */
const arr1 = [ 1, 2, 3, 4 ];
// #1. for문 활용
for (let i = 0; i < arr1.length; i++) {
  console.log(arr1[i]);
}
// #2. forEach와 화살표 함수 활용 
arr1.forEach((value) => console.log(value));
// #3. 함수 생성 후 forEach 활용
const test = (value) => { console.log(value)};
arr1.forEach(test);

/* 배열에서 홀수의 개수 구하기 */
const arr2 = [ 4, 3, 5, 1, 6, 5 ];
let cnt = 0;

arr2.forEach((value) => {
  if(value%2 === 1 ) cnt++;
})

console.log(cnt);

/* 배열에서 양수와 음수 분리하기 */
const arr3 = [ -5, 3, 4, 2, -7, -2, 7 ];
const pplus = [ ];
const mminus = [ ];
// 아래의 방식으로도 작성 가능
// const pplus = new Array();
// const mminus = new Array();

arr3.forEach((value) => {
  if(value >= 0) pplus.push(value);
  else mminus.push(value);
})

pplus.forEach((value) => console.log(value));
mminus.forEach((value) => console.log(value));
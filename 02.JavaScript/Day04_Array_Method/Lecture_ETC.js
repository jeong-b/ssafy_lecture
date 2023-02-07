// JS에서는 배열간 비교, 객체간 비교가 불가능하다.
const arr1 = [1,2,3];
const arr2 = [1,2,3];

console.log(arr1 === arr2); // false

const sampleObject = {};

if (sampleObject === {}) {
  console.log("데이터 없음")
}
else {
  console.log("데이터 있음")
} // 데이터 있음
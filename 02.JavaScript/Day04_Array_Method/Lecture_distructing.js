// 객체에서의 distructing
const abc = {
  menu: "치킨",
  type: "후라이드"
}

const { type } = abc;
console.log(type);

// 배열에서의 distructing
const arr = [1, 2];

const [one, two] = arr;
console.log(one);

// 함수에서의 distructing
const sampleFunc = () => {
  return [3, 4];
}

const [three, four] = sampleFunc()
console.log(four);
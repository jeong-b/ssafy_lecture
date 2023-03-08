// 함수 표현식

const aa = function () {
  console.log("aa");
};

// 화살표 함수
const bb = () => {
  console.log("bb");
};
// 실행코드가 한줄인 경우 {} 생략가능
const cc = () => console.log("cc");


const sum = (a, b) => {
  return a + b;
};
sum(3, 4);
// 다른코드 없이 return만 하는 함수는 return이 생략된 형태로 가능
const sum2 = (a, b) => a + b;
sum2(3, 4);

const go = (a) => a * a;

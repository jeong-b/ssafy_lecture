const students = [
  {
    name: "김도훈",
    age: 26,
    address: "경남 창원시",
  },
  {
    name: "김기홍",
    age: 27,
    address: "광주광역시",
  },
  {
    name: "김택우",
    age: 30,
    address: "인천광역시",
  },
];

// forEach는 void 이기때문에 return값이 없다
// -> 반복하는 행위에만 집중
students.forEach((student) => {
  console.log(student);
  console.log(student.name);
  console.log(student.age);
  console.log(student.address);
});

// map은 똑같은 크기의 배열을 만들고자 할 때 사용
// for문 대비 장점 : 원향 배열을 손상시키지 않는 방법
const names = students.map((student) => {
  return student.name;
});
console.log(names);

// filter는 조건에 맞는 새로운 배열 생성, 조건은 return에 사용
// 특정 한 요소만 가지고 나오는 것은 불가능
// 원형데이터와 크기는 다름
const under30People = students.filter((student) => {
  return student.age < 30;
});

const under30Names = under30People.map((person) => {
  return person.name;
});

console.log(under30Names);
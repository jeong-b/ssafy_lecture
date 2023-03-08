const datas = [0, 1, 2, 3, 4, 5];

const accResult = datas.reduce((acc, cur) => {
  console.log(acc, cur);
  return acc + cur;
});
// 초기값 미설정 시 배열의 0번 index를 가져온다.
console.log(accResult);

/* map, filter를 대신하는 reduce */
const students = [
  {
    name: "jony",
    age: 30
  },
  {
    name: "sylvie",
    age: 30
  },
  {
    name: "nana",
    age: 1
  },
];

// 기존의 map을 활용하는 방법
/*
const studentsNames = students.map((student) => student.name);
console.log(studentsNames);
*/

// reduce를 사용하는 방법
const studentsNames = students.reduce((acc, cur) => {
   acc.push(cur.name);
  return acc;
}, []);
console.log(studentsNames);

// 기존의 filter를 활용하는 방법
/*
const same30Students = students.filter((student) => {
  return student.age === 30;
});

const same30Names = same30Students.map((student) => {
  return student.name;
});

console.log(same30Names);
*/
const same30Names = students.reduce((acc, cur) => {
  if (cur.age === 30) {
    acc.push(cur.name);
  }
  return acc;
}, []);
console.log(same30Names);
// JanaScript에서의 객체 : Key와 Value로 이루어진 Property의 모음

/*
const studentInfo = {
  name : "서정빈",
  age : 27,
  address : "전라남도 목포시",
  family : [ "나", "아빠", "엄마" ],
  skill : {
    client : [ "a", "b", "c" ],
    sever : [ "d", "e", "f" ],
    db : [ "h", "i", "j" ]
  },
  sayHi : () => console.log("Hi!!!"),
}

// 객체안에 존재하는 함수 : 메서드
studentInfo.sayHi(); // 출력 : Hi!!!
*/

/*
const studentInfo = new Object(); // 출력 : {}
*/

// 프로토타입
StudentInfo = {
  name : String,
  age : Number,
  adress : String,
  family : Array,
  skill : Object,
  sayHi : Function,
};

const student = new StudentInfo();
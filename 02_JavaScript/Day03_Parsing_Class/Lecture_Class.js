// class는 내가 만든 타입
// 해당 타입을 여러개 만들어서 사용하고 싶을 때 사용
 /*
class StudentInfo {
  constructor(name, age) {
    this.name = name;
    this.age = age;
    this.address = "";
  }
  sayMyName() {
    console.log(`my name is ${this.name}`);
  }
  setAddress(address) {
    this.address = address;
  }
  getAddress() {
    return this.address;
  }
  useMethod() {
    this.sayMyName();
  }
}

const student1 = new StudentInfo("jony", 30);
const student2 = new StudentInfo("David", 50);
*/

/*
const student1 = {
  name: "",
  age: -1,
  address: "",
  // 화살표 함수는 this에 접근할 수 없음
  constructor: function (name, age) {
    this.name = name;
    this.age = age;
  },
  sayMyName: function () {
    console.log(`my name is ${this.name}`);
  },
  // 아래와 같이 축약 가능
  // sayMyName() {
    //   console.log(`my name is ${this.name}`);
    // },
    setAddress: (address) => (this.address = address),
    getAddress: () => this.address,
    useMethod: function () {
      this.sayMyName();
    },
  };
  
  student1.constructor("jony", 30);
  student2.constructor("david", 50);
  student1.sayMyName();
  student1.setAddress("경기 군포시 산본동");
  console.log(student1.getAddress());
  student1.useMethod();
*/

/*
class Lawyer {
  constructor(name, age, intro) {
    this.name = name;
    this.age = age;
    this.intro = intro;
  }
  introduce() {
    console.log(this.name);
    console.log(this.age);
    console.log(this.intro);
  }
}

const person1 = new Lawyer("우영우", 27, "기러기 토마토 스위스 역삼역");
const person2 = new Lawyer("최수연", 27, "봄날의 햇살");

person1.introduce();
person2.introduce();
*/

/*
class Hero {
  constructor() {
    this.hp = 100;
  }
  showHP() {
    console.log(this.hp);
  }
  run() {
    this.hp -= 10;
  }
}

// 상속 : 부모의 메서드 접근이 가능하다.
class SuperMan extends Hero {
  fly() {
    console.log("난다!!");
  }
}

const batman = new Hero();
const superman = new SuperMan();

batman.showHP();
batman.run();
batman.run();
batman.showHP();

superman.fly();
superman.showHP();
*/
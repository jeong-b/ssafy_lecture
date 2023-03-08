class Person {
  constructor(name, hp) {
    this.name = name;
    this.hp = hp;
  }
  hello() {
    console.log(this.name);
  }
}

class Avengers extends Person {
  constructor(name, hp, power, skill) {
    super(name, hp);
    this.power = power;
    this.skill = skill;
  }
  information() {    
    console.log(this.hp);
    console.log(this.power);
    console.log(this.skill);
  }
  fly() {
    console.log("비행중");
  }
}

const person1 = new Person("Jeong-b", 28);
const ironMan = new Avengers("ironMan", 500, 1000, "fly");

person1.hello();
ironMan.hello();
ironMan.information();
ironMan.fly();
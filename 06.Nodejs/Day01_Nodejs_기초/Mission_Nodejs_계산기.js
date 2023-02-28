const calc = {
  add: (a, b) => {return a + b},
  substrat: (a, b) => {return a - b},
  mutiply: (a, b) => {return a * b},
  divide: (a, b) => {return a / b},
}

const a = 2, b = 4;
console.log(`주어진 수: ${a} ${b}`);
console.log(`덧셈 결과: ${calc.add(a, b)}`);
console.log(`뺄셈 결과: ${calc.substrat(a, b)}`);
console.log(`곱셈 결과: ${calc.mutiply(a, b)}`);
console.log(`나눗셈 결과: ${calc.divide(a, b)}`); 
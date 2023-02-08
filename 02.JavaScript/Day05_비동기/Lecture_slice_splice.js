const names = ["jony", "sylvie", "nana"]

// slice - 원본배열이 손상되지 않고 새로운 배열이 만들어짐
// slice(a, b) - a부터 b전까지 추출한다
const newNames1 = names.slice(1, 3);
console.log(names);
console.log(newNames1);

// splice - 원본배열이 손상되면서 않고 새로운 배열이 만들어짐
// spice(a, b) - a부터 시작하여 b개를 잘라낸다
const newNames2 = names.splice(0, 1);
console.log(names);
console.log(newNames2);


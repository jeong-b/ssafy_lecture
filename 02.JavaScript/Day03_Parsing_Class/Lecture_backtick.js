// 백틱 `
const myName = "서정빈";

// 문자열 자바스크립트 혼합 가능
const introduce1 = "제이름은" + myName + "입니다!";
const introduce2 = `제이름은 ${myName} 입니다!`

// Enter 허용
const hello1 = "안녕" +
"만나서" +
"반가워";

const hello2 = `
안녕
만나서
반가워`;

// Enter 허용 - 활용
// insertAdjacentHTML 문자열로된 HTML 태크 집어 넣기

const a = `
<div class="aaa">
  안녕
</div>
`
document.querySelector('body').insertAdjacentHTML('beforeend', a);


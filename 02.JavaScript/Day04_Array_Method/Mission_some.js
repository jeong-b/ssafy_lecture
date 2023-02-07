const arrayInput = document.querySelector(".array-input");
const checkValue = document.querySelector(".check-value");
const resultButton = document.querySelector(".result-button");
const resultValue = document.querySelector(".result-value");

resultButton.addEventListener('click', function(evt){
  const arr = arrayInput.value.split(",");
  console.log(arr);
  console.log(checkValue.value);
  const isImported = arr.some(element => element === checkValue.value);
  if(isImported === true) resultValue.textContent = "포함";
  else resultValue.textContent = "미포함";
})
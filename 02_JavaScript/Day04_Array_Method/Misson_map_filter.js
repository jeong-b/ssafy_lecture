const numbers = [1, 2, 3, 4, 5, 6, 7, 8, 9, 10]
const evenNumbers = numbers.filter((number) => {
  return number % 2 === 0;
})
const resultNumbers = evenNumbers.map((evenNumber) => {
  return evenNumber * 10;
})
console.log(resultNumbers);

// 내가 작성한 코드
/*
const orderList = [
  {
    name: "chicken",
    price: 17000,
    event: false,
    count: 50,
  },
  {
    name: "pork",
    price: 8500,
    event: true,
    count: 99,
  },
  {
    name: "mara",
    price: 8000,
    event: false,
    count: 100,
  },
  {
    name: "noodle",
    price: 6500,
    event: false,
    count: 0,
  },
  {
    name: "chinese",
    price: 5500,
    event: true,
    count: 30,
  },
]

const deleteCount0 = orderList.filter((li) => {
  return li.count !== 0;
})

const salePrice = deleteCount0.map((li) => {
  if(li.event === true) li.price *= 0.9;
  return li; 
})

console.log(salePrice);
*/

// 강사님 작성 코드
const orderList = [
  {
    menu: "치킨",
    price: 17000,
    event: false,
    count: 50,
  },
  {
    menu: "돈까스",
    price: 8500,
    event: true,
    count: 99,
  },
  {
    menu: "마라탕",
    price: 8000,
    event: false,
    count: 100,
  },
  {
    menu: "쫄면",
    price: 6500,
    event: false,
    count: 0,
  },
  {
    menu: "짜장면",
    price: 5500,
    event: true,
    count: 30,
  },
];

const newOrderList = orderList
  .filter((order) => order.count !== 0)
  .map((order) => {
    const newOrder = structuredClone(order);
    if (order.event) {
      newOrder.saledPrice = (newOrder.price * 9) / 10;
      return newOrder;
    }
    newOrder.saledPrice = newOrder.price;
    return newOrder;
  });
console.log(orderList); // 원래 배열은 손상되지 않는다.
console.log(newOrderList); // 새로운 메뉴 리스트
const arr = [3, 5, 4, 2];
// 특정 조전을 만족하는 값을 가져온다
const filteredArray = arr.filter(data => data > 3)

const bucketList = [
  {
    id: 1,
    text: "여행 가기",
    doen: false,
  },
  {
    id: 2,
    text: "치킨 먹기",
    doen: true,
  },
  {
    id: 3,
    text: "코딩 하기",
    doen: true,
  },
  {
    id: 4,
    text: "요리 하기",
    doen: false,
  },
]

const filteredBucket = bucketList.filter(data => data.doen === false);
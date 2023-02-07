const arr1 = [1, 2, 3, 4, 5, 6];
const arr2 = ["a", "bcd", "ef", "g"];

// map의 기본 형태
const result1 = arr1.map(data => { return data });

// 제곱의 값을 저장
const result2 = arr1.map(data => data * data);

// 배열의 길이를 저장
const result3 = arr2.map(data => data.length);
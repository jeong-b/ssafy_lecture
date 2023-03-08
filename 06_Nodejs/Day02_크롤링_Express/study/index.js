/* 스크롤링 기본
const puppeteer = require("puppeteer");

const main = async() => {
  // 브라우저 만들기
  const browser = await puppeteer.launch({
    // 기본값이 headless: true
    headless: true
  })

  // 브라우저 페이지 만들기
  const page = await browser.newPage();

  // 페이지에서 주소로 이동하기
  await page.goto("https://www.naver.com");

  // 스크린샷 찍기
  await page.screenshot({path: "screenshot.jpg", fullPage: true});

  // pdf 따기 (headless: true 에서만 작동)
  await page.pdf({path: "test.pdf", format: 'A4'});

  // 브라우저 종료하기
  await browser.close();
}

main();
*/

/* webtoon 이름 가져오기
const puppeteer = require("puppeteer");

const main = async() => {
  // 브라우저 만들기
  const browser = await puppeteer.launch({
    // 기본값이 headless: true
    headless: false
  })
  
  // 브라우저 페이지 만들기
  const page = await browser.newPage();
  
  // 페이지에서 주소로 이동하기
  await page.goto("https://comic.naver.com/webtoon?tab=mon");
  
  // 대기 하는 방법
  // waitForSelector -> 특정 selector가 올때까지 대기 하는 역할
  await page.waitForSelector('#content .item img');
  
  // 크롤링데이터 가져오기
  // node.js는 브라우저가 아닌 환경이기 떄문에 document 사용 불가능
  // eavaluate 안에서 document 사용 가능
  const data = await page.evaluate(() => {
    const webToonList = document.querySelectorAll('#content .item img');
    
    // querySelectorAll은 유사배열
    // -> Array.from으로 베열화를 시킨후에 배열 메서드가 사용 가능
    // 제목을 가져 오기
    const result = Array.from(webToonList).map(li => li.getAttribute('alt'));
    return result;
  })
  console.log(data);  
}

main();
*/
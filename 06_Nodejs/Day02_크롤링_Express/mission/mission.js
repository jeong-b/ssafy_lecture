const puppeteer = require('puppeteer');

const main = async() => {
  // browser
  const browser = await puppeteer.launch({
    headless: false
  }); 

  // page
  const page = await browser.newPage();

  // page goto
  await page.goto("https://news.daum.net/digital#1");

  //
  const data = await page.evaluate(() => {
    const headLineList = document.querySelectorAll('.list_newsmajor a');

    const result = Array.from(headLineList).map(li => li.textContent);
    return result;
  })
  console.log(data);
}

main();